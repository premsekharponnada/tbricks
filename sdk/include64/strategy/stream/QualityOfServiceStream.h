#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QualityOfService stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/QoS.h"
#include "strategy/QualityOfService.h"

#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/QualityOfServiceFilter.h"

// \namespace tbricks
namespace tbricks {

/**
 * QualityOfServiceStream class is an interface to receive snapshots and/or live
 * quality of service updates.
 *
 * QualityOfServiceStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last QualityOfServiceStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private QualityOfServiceStream::IHandler
 * {
 *     ...
 *
 * private:
 *     QualityOfServiceStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE);
 * }
 *
 * void MyStrategy::HandleQualityOfService(
 *          const StreamIdentifier & stream, const QualityOfService & qos)
 * {
 *     // can use such comparison if there are more than one service status
 *     // streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT QualityOfServiceStream : public Stream
{
public:
    class IHandler;

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    QualityOfServiceStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    QualityOfServiceStream(IHandler & handler);

    /**
     * %Set callback interface.
     *
     * Associates current stream object with a callback interface where
     * stream updates will be delivered to.
     *
     * If stream is already opened this method has no effect.
     *
     * @param handler                   Callback interface
     */
    void SetCallback(IHandler & handler);

    /**
     * Open a stream.
     *
     * Opens a stream for a given system instrument identifier, a given
     * venue instrument identifier and a filter, if provided.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     */
    void Open(Type type, const QualityOfServiceFilter & filter = AnyQualityOfServiceFilter());

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * QualityOfServiceStream::IHandler class provides a callback interface to handle
 * best price stream events.
 *
 * @see QualityOfServiceStream
 */
class STRATEGY_EXPORT QualityOfServiceStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * QualityOfService stream update handler.
     *
     * Method is called when a new QualityOfService update becomes available on the
     * stream.
     *
     * @param stream                   Stream where update has appeared
     * @param quality_of_service       Update data
     */
    virtual void HandleQualityOfService(const StreamIdentifier & stream, const QualityOfService & quality_of_service);

    /// @deprecated Deprecated in 2.14.5 use HandleQualityOfService(const StreamIdentifier & stream, const QualityOfService & quality_of_service)
    [[deprecated(DEPRECATE_LINK)]] virtual void HandleQoSUpdate(const StreamIdentifier & stream, const QoS & qos) {}

    /**
     * QualityOfService stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Service identifier of invalidated QoS
     */
    virtual void HandleQualityOfServiceInvalidate(const StreamIdentifier & stream, const ServiceIdentifier & id);

    /// @deprecated Deprecated in 2.14.5 use HandleQualityOfServiceInvalidate(const StreamIdentifier & stream, const ServiceIdentifier & id)
    [[deprecated(DEPRECATE_LINK)]] virtual void HandleQoSInvalidate(const StreamIdentifier & stream, const ServiceIdentifier & id) {}

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

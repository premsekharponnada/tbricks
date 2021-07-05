#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Service stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Service.h"

#include "strategy/stream/Stream.h"

// \namespace tbricks
namespace tbricks {

/**
 * Service::Stream class is an interface to receive snapshots and/or live
 * service updates.
 *
 * Service::Stream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last Service::Stream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private Service::Stream::IHandler
 * {
 *     ...
 *
 * private:
 *     Service::Stream m_stream;
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
 * void MyStrategy::HandleServiceUpdate(const StreamIdentifier & stream_id, const Service & update)
 * {
 *     // can use such comparison if there are more than one service
 *     // streams
 *     if (stream_id == m_stream.GetIdentifier()) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT Service::Stream : public tbricks::Stream
{
public:
    class IHandler;
    class Options;
    struct Filters
    {
        class Filter;
        class FilterCondition;
        class ByTypeFilter;
        class ByVenueFilter;
    };

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    Stream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    Stream(IHandler & handler);

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
     * Opens a stream for with a given filter, if provided.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     */
    /// @deprecated Deprecated in 2.14.3 use void Open(Type type, const Stream::Options & options)
    [[deprecated(DEPRECATE_LINK)]] void Open(Type type, const Filters::Filter & filter);

    /// @deprecated Deprecated in 2.14.3 use void Open(Type type, const Stream::Options & options)
    [[deprecated(DEPRECATE_LINK)]] void Open(Type type);

    /**
     * Open a stream.
     *
     * Opens a stream for settings given in options.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Stream options
     */
    void Open(Type type, const Stream::Options & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * Service::Stream::IHandler class provides a callback interface to handle
 * best price stream events.
 *
 * @see Service::Stream
 */
class STRATEGY_EXPORT Service::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & stream_id){}

        /// @deprecated Deprecated in 2.14.3 use virtual void HandleService(const StreamIdentifier & stream, const
        /// Service & status)
        [[deprecated(DEPRECATE_LINK)]] virtual void HandleServiceStatusUpdate(const StreamIdentifier & stream, const Service & status){};

    /**
     * Best price stream update handler.
     *
     * Method is called when a new best price update becomes available on the
     * stream.
     *
     * @param stream                   Stream where update has appeared
     * @param status                   Update data
     */
    virtual void HandleService(const StreamIdentifier & stream, const Service & status);

    /// @deprecated Deprecated in 2.14.3 use virtual void HandleServiceInvalidate(const StreamIdentifier & stream, const
    /// ServiceIdentifier & id)
    [[deprecated(DEPRECATE_LINK)]] virtual void HandleServiceStatusInvalidate(const StreamIdentifier & stream, const ServiceIdentifier & id){};

    /**
     * Service stream invalidation handler.
     *
     * Called when an item previously seen on the stream stops to match
     * stream filter, to signal that no strategy updates for this strategy
     * instance will be available on the stream from now on, unless the
     * instance changes.
     *
     * @param stream                   Stream where invalidation occured
     * @param id                       Identifier of invalidated service
     */
    virtual void HandleServiceInvalidate(const StreamIdentifier & stream, const ServiceIdentifier & id);

protected:
    virtual ~IHandler();
};
}
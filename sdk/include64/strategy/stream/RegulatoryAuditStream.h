#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Auditable stream.
//****************************************************************************************

#include "strategy/Auditable.h"
#include "strategy/Linkage.h"
#include "strategy/stream_filter/AuditableFilter.h"
#include "strategy/stream/RegulatoryAuditStreamOptions.h"

namespace tbricks {

/**
 * AuditableStream class is an interface to receive snapshots and/or live
 * auditable updates.
 *
 * AuditableStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last AuditableStream object is destroyed.
 *
 * Note that if no callback set then Open will thrown a CallbackNotSetException.
 * If Open is not called then no update will be delivered.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private AuditableStream::IHandler
 * {
 *     ...
 *
 * private:
 *     AuditableStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, m_instrument);
 * }
 *
 * void MyStrategy::HandleAuditable(
 *          const Stream & stream, const Auditable & auditable)
 * {
 *     // can use such comparison if there are more than one auditable streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT RegulatoryAuditStream : public Stream
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
    RegulatoryAuditStream() = default;

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    RegulatoryAuditStream(IHandler & handler);

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
     * Opens a stream for a given filter, if provided.
     *
     * Note that if no callback set then Open will thrown a CallbackNotSetException.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     */
    void Open(Type type, const ServiceIdentifier & service_id, const AuditableFilter & filter = AnyAuditableFilter());

    /**
     * Open a stream.
     *
     * Note that if no callback set then Open will thrown a CallbackNotSetException.
     *
     * @param type                      Stream type
     * @param options                   Stream options
     */
    void Open(Type type, const ServiceIdentifier & service_id, const RegulatoryAuditStreamOptions & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

//----------------------------------------------------------------------------

class STRATEGY_EXPORT RegulatoryAuditStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Auditable stream update handler.
     *
     * Method is called when a new Auditable object becomes available on the
     * stream.
     *
     * @param stream                   Stream where update has appeared
     * @param audit                    Update data
     */
    virtual void HandleAuditable(const StreamIdentifier & stream, const Auditable & audit) = 0;

protected:
    virtual ~IHandler() = default;
};

} // namespace tbricks

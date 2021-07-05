#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Trade stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Trade.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream/TradeStreamOptions.h"
#include "strategy/stream_filter/TradeFilter.h"

// \namespace tbricks
namespace tbricks {

namespace strategy {
class TradeStreamImpl;
}

/**
 * TradeStream class is an interface to receive snapshots and/or live
 * trade updates.
 *
 * TradeStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last TradeStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private TradeStream::IHandler
 * {
 *     ...
 *
 * private:
 *     TradeStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     TradeByAncestorFilter filter(*this);
 *
 *     // receive all historical and live data for all trades originated
 *     // from this strategy and all its descendants
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyStrategy::HandleTrade(
 *          const Stream & stream, const Trade & trade)
 * {
 *     // can use such comparison if there are more than one trade streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT TradeStream : public Stream
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
    TradeStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    TradeStream(IHandler & handler);

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
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * Parameter "snapshot_datetime" allows to get trades as they were at
     * a particular time in past. By default, "snapshot_datetime" is empty what means
     * current trades will be requested.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param snapshot_datetime         Snapshot datetime
     */
    void Open(Type type, const TradeFilter & filter = AnyTradeFilter(), const DateTime & snapshot_datetime = DateTime());

    /**
     * Open a stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * Parameter "snapshot_datetime" allows to get trades as they were at
     * a particular time in past. By default, "snapshot_datetime" is empty what means
     * current trades will be requested.
     *
     * @param type                      Stream type
     * @param options                  Stream options
     */
    void Open(Type type, const TradeStreamOptions & options);

    /**
     * Open a stream directly for trading services with the given venue identifer
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param venue_id                  Venue identifier
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     */
    void OpenDirect(Type type, const VenueIdentifier & venue_id, const TradeFilter & filter = AnyTradeFilter());

    /**
     * Open an audit stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param from                      Initial point of time
     * @param to                        Point of time to which the updates will
     *                                  be collected
     */
    void OpenAudit(Type type, const TradeFilter & filter = AnyTradeFilter(), const DateTime & from = DateTime(), const DateTime & to = DateTime());

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * TradeStream::IHandler class provides a callback interface to handle
 * trade stream events.
 *
 * @see TradeStream
 */
class STRATEGY_EXPORT TradeStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Trade stream update handler.
     *
     * Method is called when a new trade update becomes available on the
     * stream.
     *
     * @param stream                   Stream update was generated for
     * @param trade                    Update data
     */
    virtual void HandleTrade(const StreamIdentifier & stream, const Trade & trade) = 0;

    /**
     * Trade stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     * Fox example, a subscription was made for deleted Trade and all the
     * deleted trades are received. If any such trade is un-deleted, invalidate
     * method would be called to indicate that this trade no longer belongs
     * to subscription request.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Item identifier of invalidated trade
     */
    virtual void HandleTradeInvalidate(const StreamIdentifier & stream, const TradeIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

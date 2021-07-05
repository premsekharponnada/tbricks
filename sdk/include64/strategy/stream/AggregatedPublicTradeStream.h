#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// AggregatedPublicTrade stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/PublicTrade.h"

#include "strategy/type/Venue.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/InstrumentVenueIdentification.h"

#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/PublicTradeFilter.h"

#include "strategy/Instrument.h"

// \namespace tbricks
namespace tbricks {

namespace strategy {
class AggregatedPublicTradeStreamImpl;
}

/**
 * PublicTradeStream class is an interface to receive snapshots and/or live
 * public trade updates.
 *
 * PublicTradeStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last PublicTradeStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private PublicTradeStream::IHandler
 * {
 *     ...
 *
 * private:
 *     PublicTradeStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     // receive all historical and live data for specified instrument
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, m_instrument);
 * }
 *
 * void MyStrategy::HandlePublicTrade(
 *          const Stream & stream, const PublicTrade & trade)
 * {
 *     // can use such comparison if there are more than one public trade streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT AggregatedPublicTradeStream : public Stream
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
    AggregatedPublicTradeStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    AggregatedPublicTradeStream(IHandler & handler);

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
     * Opens a stream for a given instrument venue identifier
     * and a filter, if provided.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param ivid                      Instrument venue identifier
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     */
    void Open(Type type, const std::vector<InstrumentVenueIdentification> & ivids, const PublicTradeFilter & filter = AnyPublicTradeFilter());

    void Open(Type type, const Instrument & instrument, const PublicTradeFilter & filter = AnyPublicTradeFilter());

    virtual void Close();

    virtual bool IsOpen() const;
    virtual bool IsSnapshotDone() const;
    virtual bool IsStale() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    strategy::AggregatedPublicTradeStreamImpl * m_stream;
};

/**
 * PublicTradeStream::IHandler class provides a callback interface to handle
 * public trade stream events.
 *
 * @see PublicTradeStream
 */
class STRATEGY_EXPORT AggregatedPublicTradeStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * PublicTrade stream update handler.
     *
     * Method is called when a new public trade update becomes available on the
     * stream.
     *
     * @param stream                   Stream where an update occurred
     * @param trade                    Update data
     */
    virtual void HandleAggregatedPublicTrade(const StreamIdentifier & stream, const PublicTrade & trade) = 0;
    virtual void
    HandlePublicTrade(const StreamIdentifier & /* stream */, const PublicTrade & /* trade */, const InstrumentVenueIdentification & /* ivid */)
    {}

    /**
     * PublicTradeCancellation stream handler.
     *
     * Method is called when a public trade cancelled
     *
     * @param stream                   Stream where an update occurred
     * @param trade_id                 Cancelled trade identifier
     */
    virtual void HandleAggregatedPublicTradeCancellation(const StreamIdentifier & stream, const PublicTradeIdentifier & trade_id) = 0;
    virtual void HandlePublicTradeCancellation(const StreamIdentifier & /* stream */,
                                               const PublicTradeIdentifier & /* trade_id */,
                                               const InstrumentVenueIdentification & /* ivid */)
    {}

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

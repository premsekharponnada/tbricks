#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// MarketMessage stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/Stream.h"
#include "strategy/MarketMessage.h"

namespace tbricks {

/**
 * MarketMessage::Stream class is an interface to receive snapshots and/or live
 * market message updates.
 *
 * MarketMessage::Stream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last MarketMessage::Stream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private MarketMessage::Stream::IHandler
 * {
 *     ...
 *
 * private:
 *     MarketMessage::Stream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     Filter filter();
 *
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyStrategy::HandleMarketMessage( const Stream & stream, const MarketMessage & message)
 * {
 *     // can use such comparison if there are more than one market message streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT MarketMessage::Stream : public tbricks::Stream
{
public:
    class IHandler;

    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByInstrument;
        class ByUrgency;
        class ByCreatedDateTime;
    };

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
     * Creates a full functional instance associated with a stream callback interface.
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
     * Opens a stream with a given filter, if provided.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param venueId                   desired venue identifier, if not provided,
     *                                  stream will be opened to all 'market message' services
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the associated callback interface
     */
    void Open(Type type, const Filters::Filter & filter, const VenueIdentifier & venueId = VenueIdentifier());

    /**
     * Open a stream for historical data
     *
     * @param type                      Stream type
     * @param venueId                   desired venue identifier, if not provided,
     *                                  stream will be opened to all 'market message' services
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the associated callback interface
     * @param from                      Initial point of time
     * @param to                        Point of time to which the updates will
     *                                  be collected. If empty all live updates will come.
     */
    void OpenHistorical(Type type,
                        const VenueIdentifier & venueId,
                        const Filters::Filter & filter,
                        const DateTime & from = DateTime(),
                        const DateTime & to = DateTime());

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * MarketMessage::Stream::IHandler class provides a callback interface to handle market message stream events.
 *
 * @see MarketMessage::Stream
 */
class STRATEGY_EXPORT MarketMessage::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * MarketMessage stream update handler.
     *
     * Method is called when a new market message becomes available on the stream;
     *
     * @param stream                   Stream update was generated for
     * @param message                  Market message
     */
    virtual void HandleMarketMessage(const StreamIdentifier & stream, const MarketMessage & message) = 0;

protected:
    virtual ~IHandler();
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OrderBook stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/OrderBook.h"
#include "strategy/Strategy.h"
#include "strategy/Filters.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream/OrderBookStreamOptions.h"
#include "strategy/stream_throttle/CommonThrottle.h"

namespace tbricks {

class STRATEGY_EXPORT OrderBook::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    using Options = OrderBookStreamOptions<AnyFilter, BasicThrottle>;

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    /**
     * Open a stream.
     *
     * Opens a stream for a given system instrument identifier, a given
     * Instrument venue identifier and a filter, if provided.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param ivid                      Instrument venue identifier
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param coalescing                Enable coalescing of stream data
     */
    void Open(Type type, const InstrumentVenueIdentification & ivid, const AnyFilter & filter = AnyFilter(), bool coalescing = false);

    /**
     * Open a stream.
     *
     * Opens a stream for a given system instrument identifier, a given
     * Instrument venue identifier and a filter, if provided.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param ivid                      Instrument venue identifier
     * @param options                   Stream advanced options
     */
    void Open(Type type, const InstrumentVenueIdentification & ivid, const Options & options);

    /**
     * Requests stream data snapshot
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @deprecated Deprecated in 2.12.0
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    [[deprecated(DEPRECATE_LINK)]] uint64_t GetSnapshot(FullOrderBook & snapshot) const;

    /**
     * Requests stream data snapshot
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    uint64_t GetSnapshot(OrderBook & snapshot) const;

    /**
     * Open a stream for historical data
     *
     * @param type                      Stream type
     * @param ivid                      Instrument venue identifier
     * @param granularity               Updates granularity
     * @param from                      Initial point of time
     * @param to                        Point of time to which the updates will
     *                                  be collected. If empty all live updates will come.
     */
    void OpenHistorical(Type type,
                        const InstrumentVenueIdentification & ivid,
                        const Duration & granularity,
                        const DateTime & from = DateTime(),
                        const DateTime & to = DateTime());

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

class STRATEGY_EXPORT OrderBook::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleOrderBook(const StreamIdentifier & stream_id, const OrderBook::Update & update) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceMarketData is a
// system virtual MarketData service.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/BestPrice.h"
#include "strategy/InstrumentStatus.h"
#include "strategy/Statistics.h"
#include "strategy/Types.h"
#include "strategy/VWAPPrice.h"

#include "strategy/test/IVirtualService.h"
#include "strategy/test/OrderBook.h"
#include "strategy/test/PublicTrade.h"

namespace tbricks { namespace test {
class MDImpl;

class STRATEGY_EXPORT VirtualServiceMarketData : public IVirtualService
{
public:
    /**
     * Get venue identifier of service.
     *
     * @return           Venue identifier.
     */
    VenueIdentifier GetVenueId() const;

    /**
     * Send best price update to schedule HandleBestPrice() event on an app side.
     *
     * @param viid               Venue instrument identifier.
     *
     * @param update             Best price update.
     */
    void UpdateBestPrice(const VenueInstrumentIdentifier & viid, const BestPrice & update);

    /**
     * Send statistics update to schedule HandleStatistics() event on an app side.
     *
     * @param viid              Venue instrument identifier.
     *
     * @param update            Statistics update.
     */
    void UpdateStatistics(const VenueInstrumentIdentifier & viid, const Statistics & update);

    /**
     * Send order book update to schedule HandleOrderBook() event on an app side.
     * Full order book will be sent.
     *
     * @param viid              Venue instrument identifier.
     *
     * @param update            Order book update.
     */
    void UpdateOrderBook(const VenueInstrumentIdentifier & viid, const test::OrderBook & update);

    /**
     * Send order book update to schedule HandleOrderBook() event on an app side.
     *
     * @param update            Order book update. Recent actions will be flushed.
     */
    void UpdateOrderBook(test::OrderBook & update);

    /**
     * Send instrument status update to schedule HandleInstrumentStatus() event on an app side.
     *
     * @param viid              Venue instrument identifier.
     *
     * @param update            Instrument status update.
     */
    void UpdateInstrumentStatus(const VenueInstrumentIdentifier & viid, const InstrumentStatus & update);

    /**
     * Send VWAP price update to schedule HandleVWAPPrice() event on an app side.
     *
     * @param viid               Venue instrument identifier.
     *
     * @param update             VWAP price update.
     */
    void UpdateVWAPPrice(const VenueInstrumentIdentifier & viid, const VWAPPrice & update);

    /**
     * Send public trade to schedule HandlePublicTrade() event on an app side.
     * Partial public trade will be sent.
     *
     * @param viid              Venue instrument identifier.
     *
     * @param update            Public trade update.
     */
    void UpdatePublicTrade(const VenueInstrumentIdentifier & viid, const PublicTrade & update);

public:
    /**
     * VirtualServiceMarketData constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceMarketData(MDImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceMarketData();

private:
    VirtualServiceMarketData() = delete;
    VirtualServiceMarketData(const VirtualServiceMarketData & md) = delete;
    VirtualServiceMarketData & operator=(const VirtualServiceMarketData &) = delete;
    MDImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks

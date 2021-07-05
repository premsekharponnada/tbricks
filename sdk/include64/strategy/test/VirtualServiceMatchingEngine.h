#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceMatchingEngine is a
// system virtual MatchingEngine service.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/BestPrice.h"
#include "strategy/InstrumentStatus.h"
#include "strategy/Statistics.h"
#include "strategy/Types.h"
#include "strategy/VWAPPrice.h"
#include "strategy/test/OrderOptions.h"
#include "strategy/test/PluginOptions.h"

#include "strategy/test/IVirtualService.h"
#include "strategy/test/OrderBook.h"

namespace tbricks { namespace test {
class MEImpl;

class STRATEGY_EXPORT VirtualServiceMatchingEngine : public IVirtualService
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
     * Wait until an order is created.
     *
     * @return           OrderOptions.
     */
    test::OrderOptions WaitOrderCreateRequest();

    /**
     * Wait until an order is modified.
     *
     * @return           OrderOptions.
     */
    test::OrderOptions WaitOrderModifyRequest();

    /**
     * Wait until an order is deleted.
     *
     * @return           DeleteOptions.
     */
    test::OrderDeleteOptions WaitOrderDeleteRequest();

    /**
     * Send order update to schedule HandleOrderUpdate() event on an app side.
     * Do not use volume delta from update.
     *
     * @param update     Order Update.
     */
    void UpdateOrder(const test::OrderOptions & update);

    /**
     * Send plugin update.
     *
     * @params update    Plugin update
     */
    void UpdatePlugin(const test::PluginOptions & update);

    enum UpdateTypeValue
    {
        OrderCreateRequestType = 1,
        OrderModifyRequestType = 2,
        OrderDeleteRequestType = 3
    };

public:
    /**
     * VirtualServiceMatchingEngine constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceMatchingEngine(MEImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceMatchingEngine();

private:
    VirtualServiceMatchingEngine() = delete;
    VirtualServiceMatchingEngine(const VirtualServiceMatchingEngine &) = delete;
    VirtualServiceMatchingEngine & operator=(const VirtualServiceMatchingEngine &) = delete;
    MEImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks

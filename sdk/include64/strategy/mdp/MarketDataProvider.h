#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// MarketDataProvider
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/Linkage.h"
#include "strategy/mdp/MarketDataItem.h"
#include "strategy/mdp/OrderBookItem.h"

namespace tbricks {

/**
 * Interface for providing Market data from application.
 * Market data providers are available on Integration, Calculation and Matching engines.
 */
class STRATEGY_EXPORT IMarketDataProvider
{
public:
    IMarketDataProvider();
    virtual ~IMarketDataProvider();

public:
    VenueIdentifier GetVenueIdentifier();
    TimeZone GetMarketDataVenueTimeZone() const;

public:
    virtual void HandleSubscribe(MarketDataItem & item) = 0;
    virtual void HandleUnsubscribe(MarketDataItem & item) = 0;

    virtual void HandleOrderBookSubscribe(OrderBookItem & item);
    virtual void HandleOrderBookUnsubscribe(OrderBookItem & /* item */) {}

public:
    /**
     * IsMarketDataSupported is executed by Engine to resolve instrument.
     * Engine asks every app one by one. If app onse answered "true" for particular instrument. All streams for
     * particular instrument will go to particular app.
     *
     * @param     InstrumentVenueIdentification
     * @return    true   if instrument is supported by Application
     *            false  otherwise
     */
    virtual bool IsMarketDataSupported(const tbricks::InstrumentVenueIdentification & ivid) = 0;
};

class STRATEGY_EXPORT MarketDataProvider : public Plugin, public IMarketDataProvider
{
public:
    MarketDataProvider();
    ~MarketDataProvider();

    virtual void HandleIdle() final {}
    virtual void HandleDeleteRequest() final {}
    virtual void HandleRunRequest() final {}
    virtual void HandlePauseRequest() final {}
    virtual void HandleModifyRequest(const StrategyModifier & /* modifier */) final {}
    virtual void HandleValidateRequest(tbricks::ValidationContext & /* context */) final {}
    virtual void HandleScheduledEvent(UserData && /* data */) {}
    virtual std::ostream & Print(std::ostream & strm) const { return strm; }

private:
    MarketDataProvider(const MarketDataProvider &);
    MarketDataProvider & operator=(const MarketDataProvider &);
};
}

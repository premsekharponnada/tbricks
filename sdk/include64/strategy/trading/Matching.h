#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// MatchingApp
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/Linkage.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/mdp/MarketDataProvider.h"
#include "strategy/trading/Trading.h"
#include "strategy/trading/RequestForQuoteProvider.h"

namespace tbricks {

class STRATEGY_EXPORT MatchingApp : public Plugin, public IMarketDataProvider, public Trading, public RequestForQuoteProvider
{
public:
    MatchingApp();
    virtual ~MatchingApp();

    virtual void HandleIdle() {}
    virtual void HandleDeleteRequest() final {}
    virtual void HandleRunRequest() final {}
    virtual void HandlePauseRequest() final {}
    virtual void HandleModifyRequest(const StrategyModifier & /* modifier */) final {}
    virtual void HandleValidateRequest(tbricks::ValidationContext & /* context */) final {}
    virtual void HandleScheduledEvent(UserData && /* data */) {}

    virtual std::ostream & Print(std::ostream & strm) const { return strm; }

    virtual bool IsSupported(const tbricks::InstrumentVenueIdentification & ivid) = 0;

    virtual bool IsMarketDataSupported(const tbricks::InstrumentVenueIdentification & ivid) final { return IsSupported(ivid); }
    virtual bool HandleIsTradingSupported(const tbricks::InstrumentVenueIdentification & ivid) final { return IsSupported(ivid); }

private:
    MatchingApp(const MatchingApp &);
    MatchingApp & operator=(const MatchingApp &);
};
}

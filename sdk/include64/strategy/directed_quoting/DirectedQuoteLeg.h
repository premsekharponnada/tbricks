#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteLeg
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/ExtraData.h"
#include "strategy/MarketDataParameters.h"
#include "strategy_generated/DirectedQuoteLegBase.h"

namespace tbricks {

class STRATEGY_EXPORT DirectedQuoteLeg : public DirectedQuoteLegBase
{
public:
    DirectedQuoteLeg(const InstrumentVenueIdentification & ivid);
    DirectedQuoteLeg(const protocol::DirectedQuoteLeg & leg);

    const InstrumentVenueIdentification & GetInstrumentVenueIdentification() const;

    bool GetExtraData(ExtraData & data) const;

    bool HasMarketDataParameters() const;
    bool GetMarketDataParameters(MarketDataParameters & parameters) const;
    MarketDataParameters GetMarketDataParameters() const;
    void SetMarketDataParameters(const MarketDataParameters & parameters);

    std::ostream & Print(std::ostream & strm) const;

private:
    friend class DirectedQuoteResponse;
    friend class DirectedQuote;
    tbricks::InstrumentVenueIdentification m_ivid;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Capabilities of a market data.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/LiquidityPool.h"

namespace tbricks {

namespace venue {
class VenueInfo;
}

class STRATEGY_EXPORT MarketDataCapabilities : public Printable
{
public:
    MarketDataCapabilities(tbricks::venue::VenueInfo * vi);
    ~MarketDataCapabilities();

    MarketDataCapabilities(const MarketDataCapabilities & mdc);
    MarketDataCapabilities & operator=(const MarketDataCapabilities & mdc);

public:
    void GetLiquidityPools(std::vector<LiquidityPool> & liquidity_pools) const;
    std::ostream & Print(std::ostream & strm) const override;

private:
    tbricks::venue::VenueInfo * m_venue;
};
}

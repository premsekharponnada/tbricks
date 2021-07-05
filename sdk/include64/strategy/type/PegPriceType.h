#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PegPriceType enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT PegPriceType
{
    MID_PRICE_PEG = 2, /**< Order is pegged to mid-price of relevant orderbook. */
    MARKET_PEG = 4 /**< Order is pegged to the same best price (buy order to bid, ask order to ask) of relevant orderbook */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, PegPriceType value);

}

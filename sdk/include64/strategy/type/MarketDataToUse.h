#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Market data to use.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum MarketDataToUse
{
    MARKET_DATA_BEST_PRICE = 0,    /**< Use best price. */
    MARKET_DATA_AVERAGE_PRICE = 1, /**< Average price for volume. */
    MARKET_DATA_WORST_PRICE = 2,   /**< Worst price for volume. */
    MARKET_DATA_LAST_PRICE = 3     /**< The last is taken from the last traded price. */
};

STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, MarketDataToUse market_data_to_use);
}

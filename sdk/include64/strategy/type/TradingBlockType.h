#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingBlockType enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT TradingBlockType
{
    MANUAL = 0, /**< Block created by user request */
    BLACKLISTED = 1, /**< Blacklisted */
    POST_TRADE = 2 /**< Block created after post-trade limit breach */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, TradingBlockType value);

}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuotePegFallbackBehavior enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT QuotePegFallbackBehavior
{
    OUTER = 0, /**< The spread outside of which you would be willing to join the market. */
    INNER = 1 /**< The maximum spread at which you are willing to quote. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, QuotePegFallbackBehavior value);

}

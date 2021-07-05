#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Own Quote Book Type.
//****************************************************************************************

#include "strategy/Linkage.h"

namespace tbricks {

enum class STRATEGY_EXPORT OwnQuoteBookType
{
    ORDER = 0,
    ORDER_AND_QUOTE = 1,
    QUOTE = 2,
    QUOTE_DESIRED = 3
};

STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, OwnQuoteBookType value);
}

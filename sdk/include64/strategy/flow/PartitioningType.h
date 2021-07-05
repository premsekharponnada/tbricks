#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Pre-trade risk checking API.
//
//****************************************************************************************

#include "strategy/Linkage.h"
#include <iosfwd>

namespace tbricks {

enum class STRATEGY_EXPORT PartitioningType
{
    NONE = 1,                /*< One flow app of this type handling both app requests and orders */
    OWNER = 2,               /*< One flow app per owner for orders and one for app requests */
    PORTFOLIO = 3,           /*< One flow app per portfolio for orders and one for app requests */
    CLIENT_LEGAL_ENTITY = 4, /*< One flow app per client legal entity for orders and one for app requests */
    VENUE = 5                /*< One flow app per venue identifier for orders and one for app requests */
};

STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const tbricks::PartitioningType & type);
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Row entity type.
//****************************************************************************************

#include <ostream>

#include "strategy/Linkage.h"

namespace tbricks { namespace visualization {

enum class RowEntityType
{
    Position = 0,
    Instrument = 1,
    Strategy = 2,
    Order = 3,
    Trade = 4,
    InstrumentGroup = 5,
    Cash = 6,
    RequestForQuote = 7,
    InstrumentComponent = 8,
    AuditData = 9,
    Portfolio = 10,
    Service = 11,
    TreeNode = 12,
    User = 13,
    Venue = 14
};

STRATEGY_EXPORT
std::ostream & operator<<(std::ostream & strm, RowEntityType type);

} // namespace visualization
} // namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForQuoteType enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT RequestForQuoteType
{
    NORMAL = 1, /**< Regular request for quote */
    REQUEST_FOR_CROSS = 2, /**< Request for cross */
    INDICATIVE = 3 /**< Request for indicative quoting (aka poll for price request) */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, RequestForQuoteType value);

}

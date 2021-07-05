#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForQuoteResult enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT RequestForQuoteResult
{
    WON = 1, /**<  */
    TRADED_AWAY = 2, /**<  */
    REJECTED = 3, /**<  */
    TIMEOUT = 4, /**<  */
    LOST_UNKNOWN = 5 /**< Negotiation is finished without trade, but the actual reason for loss is unknown. Can be subsequently updated if more information comes in. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, RequestForQuoteResult value);

}

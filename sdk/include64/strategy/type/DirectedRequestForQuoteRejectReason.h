#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedRequestForQuoteRejectReason enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT DirectedRequestForQuoteRejectReason
{
    LIMIT_BREACH = 1, /**< Request cannot be fulfilled due to limit breach. */
    REFUSED = 2, /**< Trader has decided not to answer the request. */
    UNKNOWN = 3, /**< Unknown error. */
    INVALID_COUNTERPARTY = 4, /**< Counterparty is wrong or not handled by liquidity provider. */
    UNKNOWN_INSTRUMENT = 5 /**< Reject due to instrument not being known to liquidity provider. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, DirectedRequestForQuoteRejectReason value);

}

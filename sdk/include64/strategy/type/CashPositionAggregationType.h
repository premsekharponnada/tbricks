#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CashPositionAggregationType enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT CashPositionAggregationType
{
    CASH_POSITIONS_BY_CURRENCY = 1, /**< Aggregation over all keys except currency. */
    CASH_POSITIONS_BY_CURRENCY_AND_TYPE = 2, /**< Aggregation over all keys except currency and type. */
    CASH_POSITIONS = 3, /**< No aggregation is performed. Useful for troubleshooting how a cash position is constructed.
                Cash position description, instrument identifier and strategy identifier are provided only for this aggregation type. */
    CASH_POSITIONS_BY_CURRENCY_AND_INSTRUMENT = 4, /**< Aggregation over all keys except currency and instrument. */
    CASH_POSITIONS_BY_CURRENCY_AND_SETTLEMENT = 5, /**< Aggregation over all keys except currency and settlement. */
    CASH_POSITIONS_BY_CURRENCY_AND_INSTRUMENT_AND_SETTLEMENT = 6 /**< Aggregation over all keys except currency, instrument and settlement. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, CashPositionAggregationType value);

}

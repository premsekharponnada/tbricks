#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CashPositionType enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT CashPositionType
{
    DIVIDEND = 1, /**< Dividend payout from equity instrument. */
    FEE = 2, /**< Fee received or paid. */
    MARGIN = 3, /**< Margin deposit. */
    CASH_DELIVERY = 4, /**< The cash position is due to a cash delivery of e.g. an option. 
                Cash entries of this type will usually have instrument/strategy identifier fields populated. */
    FINANCING = 5, /**< Proceeds from financing position or cash balance. */
    DEPOSIT_OR_WITHDRAWAL = 6, /**< A deposit or withdrawal of money into/from the portfolio. The sign of the volume signifies which. */
    CORRECTION = 7, /**< A manual correction of the portfolios cash position. */
    FX = 8, /**< Exchange cash position. */
    POSITION_ADJUSTMENT = 9, /**< Change in cash balance driven by external system. */
    COUPON = 10, /**< Coupon payout from fixed income instrument. */
    LENDING = 11 /**< Proceeds from lending a security. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, CashPositionType value);

}

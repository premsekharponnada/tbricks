#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Order Book Change Reason.
//****************************************************************************************

#include "strategy/Linkage.h"
#include <iostream>

namespace tbricks {

enum OrderBookChangeReason
{
    CHANGE_REASON_UNDEFINED = 0, /**< Undefined or indeterminable change-reason, like snapshot baseline.*/
    CHANGE_REASON_ADD = 1,       /**< Change due to order add.*/
    CHANGE_REASON_MODIFY = 2,    /**< Change due to order modify.*/
    CHANGE_REASON_DELETE = 3,    /**< Change due to order delete.*/
    CHANGE_REASON_TRADE = 4      /**< Change due to order being traded.*/
};

STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, OrderBookChangeReason reason);
}

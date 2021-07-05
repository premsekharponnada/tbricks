#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// UserSessionStatus enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT UserSessionStatus
{
    LOGGED_IN = 1, /**< User is logged in to the system. */
    LOGGED_OUT = 2 /**< User is logged out from the system. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, UserSessionStatus value);

}

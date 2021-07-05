#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ServiceState enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT ServiceState
{
    ONLINE = 1, /**< Service is on-line with control over it's objects. */
    OFFLINE = 2 /**< Service is off-line, state is unclear or undefined of it's objects. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, ServiceState value);

}

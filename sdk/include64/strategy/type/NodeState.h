#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// NodeState enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT NodeState
{
    UNKNOWN = 1, /**<  */
    ONLINE = 2, /**<  */
    OFFLINE = 3 /**<  */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, NodeState value);

}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ComponentState enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT ComponentState
{
    UNKNOWN = 1, /**< The component state is currently not possible to determine. */
    STARTING = 2, /**< Component is starting up. */
    RUNNING = 3, /**< Component is up and running. */
    STOPPING = 4, /**< Component is being stopped. */
    STOPPED = 5, /**< Component is stopped. */
    OTHER = 6, /**< States of component's processes are in conflict. */
    DEGRADED = 7, /**< One of its processes crashed. */
    MAINTENANCE = 8 /**< Component is in maintenance mode, e.g. upgrading/cleaning/etc. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, ComponentState value);

}

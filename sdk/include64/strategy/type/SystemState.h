#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// SystemState enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT SystemState
{
    UNKNOWN = 1, /**< The system state is currently not possible to determine. */
    STARTING = 2, /**< System is starting up. */
    RUNNING = 3, /**< System is up and running. */
    STOPPING = 4, /**< System is being stopped. */
    STOPPED = 5, /**< System is stopped. */
    OTHER = 6, /**< States of system's components are in conflict. */
    DEGRADED = 7, /**< One of its components crashed. */
    PACKAGE_UPGRADE = 8, /**< System package is being upgraded. */
    DATABASE_UPGRADE = 9, /**< System databases are being upgraded. */
    MAINTENANCE = 10 /**< System is in maintenance mode, e.g. upgrading/cleaning/etc. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, SystemState value);

}

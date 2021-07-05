#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ServiceSelfTestStatus enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT ServiceSelfTestStatus
{
    NOT_RUN = 1, /**< No self-test have been run yet for the service. */
    OK = 2, /**< The previous self-test succeeded. */
    FAILED = 3, /**< The previous self-test for the service failed. */
    IN_PROGRESS = 4 /**< A self-test is currently in progress. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, ServiceSelfTestStatus value);

}

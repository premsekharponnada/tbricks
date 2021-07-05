#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// License type enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <iosfwd>

namespace tbricks {

enum class STRATEGY_EXPORT LicenseType
{
    TRIAL = 0,       /**< License for customer's trial setup */
    DEVELOPMENT = 1, /**< License for customer's development systems */
    PRODUCTION = 2,  /**< License for customer's production systems */
    EMERGENCY = 3,   /**< Unlimited license for customers for emergency cases */
    INTERNAL = 4,    /**< Itiviti's internal unlimited license used for development purposes */
    UNKNOWN = 5      /**< Type is unknown, object was not initialized yet */
};

STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, LicenseType value);
}

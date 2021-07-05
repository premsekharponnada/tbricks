#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// System
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/String.h"
#include "strategy/type/SystemIdentifier.h"

#include "strategy_generated/SystemBase.h"

namespace tbricks {

class STRATEGY_EXPORT System : public SystemBase
{
public:
    class Stream;
    /**
     * Default constructor.
     *
     * Initializes object to default value -- no fields present, all returned
     * values are empty.
     *
     * This is mostly for use in STL containers.
     */
    System() = default;

    System(const SystemIdentifier & identifier);

    /**
     * Get current system.
     */
    static const System GetCurrent();

    using SystemBase::SystemBase;
};

namespace strategy {

/// @deprecated Deprecated in 2.14.3 use tbricks::System
using System[[deprecated(DEPRECATE_LINK)]] = tbricks::System;

} // namespace strategy

} // namespace tbricks

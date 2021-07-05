#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Subsystem
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/System.h"
#include "strategy/type/SubsystemIdentifier.h"
#include "strategy/type/String.h"

#include "strategy_generated/SubsystemBase.h"

namespace tbricks {

class STRATEGY_EXPORT Subsystem : public SubsystemBase
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
    Subsystem() = default;

    Subsystem(const SubsystemIdentifier & identifier);

    /**
     * Get current subsytem.
     */
    static const Subsystem GetCurrent();

    /**
     * Get parent system.
     */
    const System GetSystem() const;

    using SubsystemBase::SubsystemBase;
};

namespace strategy {

/// @deprecated Deprecated in 2.14.3 use tbricks::Subsystem
using Subsystem[[deprecated(DEPRECATE_LINK)]] = tbricks::Subsystem;

} // namespace strategy

} // namespace tbricks

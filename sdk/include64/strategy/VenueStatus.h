#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Venue Status object.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Types.h"
#include "strategy/Value.h"
#include "strategy_generated/VenueStatusBase.h"

namespace tbricks {

class STRATEGY_EXPORT VenueStatus : public VenueStatusBase
{
public:
    VenueStatus() = default;
    using VenueStatusBase::Merge;
    using VenueStatusBase::VenueStatusBase;
};
}

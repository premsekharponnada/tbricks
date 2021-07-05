#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Counterpart information
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/CounterpartInformationBase.h"

namespace tbricks {

class STRATEGY_EXPORT CounterpartInformation : public CounterpartInformationBase
{
public:
    CounterpartInformation() = default;
    CounterpartInformation(const protocol::CounterpartInformation & value) : CounterpartInformationBase(value) {}
};
}

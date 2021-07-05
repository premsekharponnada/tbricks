#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Fake IStratergyHandler
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/test/test_environment/IStrategyResponder.h"

namespace tbricks {

/*
    This call creates instance of TestableEnvironment which is fake IStratergyHandle
    It used as a stub of all tbsystem servises.
*/

void STRATEGY_EXPORT CreateTestableEnvironment(const IStrategyResponder & strategyResponder);
}

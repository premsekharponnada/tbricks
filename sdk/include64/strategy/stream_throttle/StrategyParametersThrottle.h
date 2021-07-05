#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy parameters throttle filters
//****************************************************************************************

#include "strategy/parameter/ParameterDefinition.h"
#include "strategy/stream_throttle/ParametersThrottle.h"

namespace tbricks {

class STRATEGY_EXPORT StrategyParametersThrottle : public ParametersThrottle
{
public:
    StrategyParametersThrottle();
    StrategyParametersThrottle(const StrategyParametersThrottle & throttle);
    StrategyParametersThrottle(const CommonThrottle & throttle);
    StrategyParametersThrottle(const ParameterDefinition & definition, Throttle::ChangeType type, double value);

    StrategyParametersThrottle & operator=(const StrategyParametersThrottle & throttle);
    StrategyParametersThrottle & operator|=(const StrategyParametersThrottle & throttle);
    StrategyParametersThrottle operator||(const StrategyParametersThrottle & throttle) const;
    StrategyParametersThrottle & operator|=(const CommonThrottle & throttle);
    StrategyParametersThrottle operator||(const CommonThrottle & throttle) const;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Common throttle filters
//****************************************************************************************

#include "strategy/type/Duration.h"
#include "strategy/stream_throttle/Throttle.h"

namespace tbricks {

class STRATEGY_EXPORT CommonThrottle : public Throttle
{
public:
    CommonThrottle(const CommonThrottle & throttle);
    CommonThrottle & operator=(const CommonThrottle & throttle);

    CommonThrottle & operator|=(const CommonThrottle & throttle);
    CommonThrottle operator||(const CommonThrottle & throttle) const;

protected:
    CommonThrottle();
};

class STRATEGY_EXPORT MinimumUpdateRateThrottle : public CommonThrottle
{
public:
    MinimumUpdateRateThrottle(const Integer & count);
};

class STRATEGY_EXPORT MaximumUpdateTimeThrottle : public CommonThrottle
{
public:
    MaximumUpdateTimeThrottle(const Duration & interval);
};

class STRATEGY_EXPORT BasicThrottle : public CommonThrottle
{
public:
    BasicThrottle();
    BasicThrottle(const BasicThrottle & throttle);
    BasicThrottle(const CommonThrottle & throttle);

    BasicThrottle & operator=(const BasicThrottle & throttle);
    BasicThrottle & operator|=(const BasicThrottle & throttle);
    BasicThrottle operator||(const BasicThrottle & throttle) const;
    BasicThrottle & operator|=(const CommonThrottle & throttle);
    BasicThrottle operator||(const CommonThrottle & throttle) const;
};
}

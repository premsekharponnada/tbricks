#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameters throttle base class
//****************************************************************************************

#include "strategy/Types.h"
#include "strategy/stream_throttle/CommonThrottle.h"

namespace tbricks {

class STRATEGY_EXPORT ParametersThrottle : public Throttle
{
protected:
    ParametersThrottle();
    ~ParametersThrottle();

    void add_param_condition(int field_id, const Uuid & param_id, Throttle::ChangeType type, double value);

private:
    // prohibited
    ParametersThrottle(const ParametersThrottle &);
    ParametersThrottle & operator=(const ParametersThrottle &);
};
}

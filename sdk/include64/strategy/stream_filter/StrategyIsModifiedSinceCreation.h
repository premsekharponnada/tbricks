#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyIsModifiedSinceCreation matches strategies modified since creation.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

/**
 * StrategyIsModifiedSinceCreation matches all the strategies instance that
 * has been modified since their creation.
 */
class STRATEGY_EXPORT StrategyIsModifiedSinceCreation : public StrategyFilterCondition
{
public:
    StrategyIsModifiedSinceCreation();
    StrategyIsModifiedSinceCreation(const StrategyIsModifiedSinceCreation & filter);

    StrategyIsModifiedSinceCreation & operator=(const StrategyIsModifiedSinceCreation & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};
}

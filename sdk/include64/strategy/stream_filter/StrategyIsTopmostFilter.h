#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyIsTopmostFilter matches the top most strategies.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

/**
 * StrategyIsTopmostFilter matches all the strategies having TopLevel set
 * to true.
 *
 * NOTE: Making strategy a top level one means to break relationship between the
 * child and its parent, a new strategy will have no information of what
 * the parent was and will not appear in the inheritance tree of the parent.
 */
class STRATEGY_EXPORT StrategyIsTopmostFilter : public StrategyFilterCondition
{
public:
    StrategyIsTopmostFilter();
    StrategyIsTopmostFilter(const StrategyIsTopmostFilter & filter);

    StrategyIsTopmostFilter & operator=(const StrategyIsTopmostFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};
}

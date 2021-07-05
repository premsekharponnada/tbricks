#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter used in strategy streams.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/type/Identifier.h"
#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/**
 * Default strategy filter, matches all data.
 */
class STRATEGY_EXPORT StrategyFilter : public Filter
{
public:
    StrategyFilter();
    StrategyFilter(const StrategyFilter & filter);
    ~StrategyFilter();

    StrategyFilter & operator=(const StrategyFilter & filter);

    StrategyFilter & operator|=(const StrategyFilter & filter);
    StrategyFilter & operator&=(const StrategyFilter & filter);

    StrategyFilter operator||(const StrategyFilter & filter);
    StrategyFilter operator&&(const StrategyFilter & filter);

    StrategyFilter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

/**
 * Convenience alias.
 */
typedef StrategyFilter AnyStrategyFilter;

class STRATEGY_EXPORT StrategyFilterCondition : public FilterCondition
{
public:
    StrategyFilter operator||(const StrategyFilterCondition & cond) const;
    StrategyFilter operator&&(const StrategyFilterCondition & cond) const;
    StrategyFilter operator||(const StrategyFilter & cond) const;
    StrategyFilter operator&&(const StrategyFilter & cond) const;
    StrategyFilter operator!() const;
    operator StrategyFilter() const;
};
}

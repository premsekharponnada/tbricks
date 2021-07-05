#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in statistics streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/**
 * Default strategy filter, matches all data.
 */
class STRATEGY_EXPORT StatisticsFilter : public Filter
{
public:
    StatisticsFilter();
    StatisticsFilter(const StatisticsFilter & filter);
    ~StatisticsFilter();

    StatisticsFilter & operator=(const StatisticsFilter & filter);

    StatisticsFilter & operator|=(const StatisticsFilter & filter);
    StatisticsFilter & operator&=(const StatisticsFilter & filter);

    StatisticsFilter operator||(const StatisticsFilter & filter);
    StatisticsFilter operator&&(const StatisticsFilter & filter);

    StatisticsFilter operator!();

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
typedef StatisticsFilter AnyStatisticsFilter;

class STRATEGY_EXPORT StatisticsFilterCondition : public FilterCondition
{
public:
    StatisticsFilter operator||(const StatisticsFilterCondition & cond) const;
    StatisticsFilter operator&&(const StatisticsFilterCondition & cond) const;
    StatisticsFilter operator||(const StatisticsFilter & cond) const;
    StatisticsFilter operator&&(const StatisticsFilter & cond) const;
    StatisticsFilter operator!() const;
    operator StatisticsFilter() const;
};
}

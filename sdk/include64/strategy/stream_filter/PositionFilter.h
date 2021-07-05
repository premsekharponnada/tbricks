#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in position streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/**
 * Default strategy filter, matches all data.
 */
class STRATEGY_EXPORT PositionFilter : public Filter
{
public:
    PositionFilter();
    PositionFilter(const PositionFilter & filter);
    ~PositionFilter();

    PositionFilter & operator=(const PositionFilter & filter);

    PositionFilter & operator|=(const PositionFilter & filter);
    PositionFilter & operator&=(const PositionFilter & filter);

    PositionFilter operator||(const PositionFilter & filter);
    PositionFilter operator&&(const PositionFilter & filter);

    PositionFilter operator!();

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
typedef PositionFilter AnyPositionFilter;

class STRATEGY_EXPORT PositionFilterCondition : public FilterCondition
{
public:
    PositionFilter operator||(const PositionFilterCondition & cond) const;
    PositionFilter operator&&(const PositionFilterCondition & cond) const;
    PositionFilter operator||(const PositionFilter & cond) const;
    PositionFilter operator&&(const PositionFilter & cond) const;
    PositionFilter operator!() const;
    operator PositionFilter() const;
};
}

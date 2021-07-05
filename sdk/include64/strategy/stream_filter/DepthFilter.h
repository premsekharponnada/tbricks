#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in depth streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/**
 * Default strategy filter, matches all data.
 */
class STRATEGY_EXPORT DepthFilter : public Filter
{
public:
    DepthFilter();
    DepthFilter(const DepthFilter & filter);
    ~DepthFilter();

    DepthFilter & operator=(const DepthFilter & filter);

    DepthFilter & operator|=(const DepthFilter & filter);
    DepthFilter & operator&=(const DepthFilter & filter);

    DepthFilter operator||(const DepthFilter & filter);
    DepthFilter operator&&(const DepthFilter & filter);

    DepthFilter operator!();

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
typedef DepthFilter AnyDepthFilter;

class STRATEGY_EXPORT DepthFilterCondition : public FilterCondition
{
public:
    DepthFilter operator||(const DepthFilterCondition & cond) const;
    DepthFilter operator&&(const DepthFilterCondition & cond) const;
    DepthFilter operator||(const DepthFilter & cond) const;
    DepthFilter operator&&(const DepthFilter & cond) const;
    DepthFilter operator!() const;
    operator DepthFilter() const;
};
}

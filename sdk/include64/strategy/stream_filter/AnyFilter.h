#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// AnyFilter
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"

namespace tbricks {

class STRATEGY_EXPORT AnyFilter : public Filter
{
public:
    AnyFilter();
    AnyFilter(const AnyFilter & filter);
    ~AnyFilter();

    AnyFilter & operator=(const AnyFilter & filter);

    AnyFilter & operator|=(const AnyFilter & filter);
    AnyFilter & operator&=(const AnyFilter & filter);

    AnyFilter operator||(const AnyFilter & filter);
    AnyFilter operator&&(const AnyFilter & filter);

    AnyFilter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

class STRATEGY_EXPORT AnyFilterCondition : public FilterCondition
{
public:
    AnyFilter operator||(const AnyFilterCondition & cond) const;
    AnyFilter operator&&(const AnyFilterCondition & cond) const;
    AnyFilter operator||(const AnyFilter & cond) const;
    AnyFilter operator&&(const AnyFilter & cond) const;
    AnyFilter operator!() const;
    operator AnyFilter() const;
};
}

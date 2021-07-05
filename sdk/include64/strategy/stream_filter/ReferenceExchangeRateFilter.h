#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in reference exchange rate streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/**
 * Default strategy filter, matches all data.
 */
class STRATEGY_EXPORT ReferenceExchangeRateFilter : public Filter
{
public:
    ReferenceExchangeRateFilter();
    ReferenceExchangeRateFilter(const ReferenceExchangeRateFilter & filter);
    ~ReferenceExchangeRateFilter();

    ReferenceExchangeRateFilter & operator=(const ReferenceExchangeRateFilter & filter);

    ReferenceExchangeRateFilter & operator|=(const ReferenceExchangeRateFilter & filter);
    ReferenceExchangeRateFilter & operator&=(const ReferenceExchangeRateFilter & filter);

    ReferenceExchangeRateFilter operator||(const ReferenceExchangeRateFilter & filter);
    ReferenceExchangeRateFilter operator&&(const ReferenceExchangeRateFilter & filter);

    ReferenceExchangeRateFilter operator!();

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
typedef ReferenceExchangeRateFilter AnyReferenceExchangeRateFilter;

class STRATEGY_EXPORT ReferenceExchangeRateFilterCondition : public FilterCondition
{
public:
    ReferenceExchangeRateFilter operator||(const ReferenceExchangeRateFilterCondition & cond) const;
    ReferenceExchangeRateFilter operator&&(const ReferenceExchangeRateFilterCondition & cond) const;
    ReferenceExchangeRateFilter operator||(const ReferenceExchangeRateFilter & cond) const;
    ReferenceExchangeRateFilter operator&&(const ReferenceExchangeRateFilter & cond) const;
    ReferenceExchangeRateFilter operator!() const;
    operator ReferenceExchangeRateFilter() const;
};
}

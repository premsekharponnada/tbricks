#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in trade streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/**
 * Default trade filter, matches all data.
 */
class STRATEGY_EXPORT TradeFilter : public Filter
{
public:
    TradeFilter();
    TradeFilter(const TradeFilter & filter);
    ~TradeFilter();

    TradeFilter & operator=(const TradeFilter & filter);

    TradeFilter & operator|=(const TradeFilter & filter);
    TradeFilter & operator&=(const TradeFilter & filter);

    TradeFilter operator||(const TradeFilter & filter);
    TradeFilter operator&&(const TradeFilter & filter);

    TradeFilter operator!();

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
typedef TradeFilter AnyTradeFilter;

class STRATEGY_EXPORT TradeFilterCondition : public FilterCondition
{
public:
    TradeFilter operator||(const TradeFilterCondition & cond) const;
    TradeFilter operator&&(const TradeFilterCondition & cond) const;
    TradeFilter operator||(const TradeFilter & cond) const;
    TradeFilter operator&&(const TradeFilter & cond) const;
    TradeFilter operator!() const;
    operator TradeFilter() const;
};
}

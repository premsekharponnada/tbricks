#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in public trade streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/**
 * Default trade filter, matches all data.
 */
class STRATEGY_EXPORT PublicTradeFilter : public Filter
{
public:
    PublicTradeFilter();
    PublicTradeFilter(const PublicTradeFilter & filter);
    ~PublicTradeFilter();

    PublicTradeFilter & operator=(const PublicTradeFilter & filter);

    PublicTradeFilter & operator|=(const PublicTradeFilter & filter);
    PublicTradeFilter & operator&=(const PublicTradeFilter & filter);

    PublicTradeFilter operator||(const PublicTradeFilter & filter);
    PublicTradeFilter operator&&(const PublicTradeFilter & filter);

    PublicTradeFilter operator!();

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
typedef PublicTradeFilter AnyPublicTradeFilter;

class STRATEGY_EXPORT PublicTradeFilterCondition : public FilterCondition
{
public:
    PublicTradeFilter operator||(const PublicTradeFilterCondition & cond) const;
    PublicTradeFilter operator&&(const PublicTradeFilterCondition & cond) const;
    PublicTradeFilter operator||(const PublicTradeFilter & cond) const;
    PublicTradeFilter operator&&(const PublicTradeFilter & cond) const;
    PublicTradeFilter operator!() const;
    operator PublicTradeFilter() const;
};
}

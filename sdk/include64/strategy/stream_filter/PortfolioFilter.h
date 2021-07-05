#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in portfolio streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/**
 * Default strategy filter, matches all data.
 */
class STRATEGY_EXPORT PortfolioFilter : public Filter
{
public:
    PortfolioFilter();
    PortfolioFilter(const PortfolioFilter & filter);
    ~PortfolioFilter();

    PortfolioFilter & operator=(const PortfolioFilter & filter);

    PortfolioFilter & operator|=(const PortfolioFilter & filter);
    PortfolioFilter & operator&=(const PortfolioFilter & filter);

    PortfolioFilter operator||(const PortfolioFilter & filter);
    PortfolioFilter operator&&(const PortfolioFilter & filter);

    PortfolioFilter operator!();

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
typedef PortfolioFilter AnyPortfolioFilter;

class STRATEGY_EXPORT PortfolioFilterCondition : public FilterCondition
{
public:
    PortfolioFilter operator||(const PortfolioFilterCondition & cond) const;
    PortfolioFilter operator&&(const PortfolioFilterCondition & cond) const;
    PortfolioFilter operator||(const PortfolioFilter & cond) const;
    PortfolioFilter operator&&(const PortfolioFilter & cond) const;
    PortfolioFilter operator!() const;
    operator PortfolioFilter() const;
};
}

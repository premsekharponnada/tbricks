#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByCounterCurrencyFilter, matches trades by counter currency.
//****************************************************************************************

#include "strategy/stream_filter/TradeFilter.h"
#include "strategy/type/Currency.h"

namespace tbricks {

/**
 * TradeByCounterCurrencyFilter matches trades having specified counter cyrrency.
 */
class STRATEGY_EXPORT TradeByCounterCurrencyFilter : public TradeFilterCondition
{
public:
    /// Default constructor.
    TradeByCounterCurrencyFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all trades having counter currency as specified
     * in the input parameter.
     *
     * @param ccy                              Instance of Currency on the basis of which trades will
                                               be filtered.
     */
    TradeByCounterCurrencyFilter(const Currency & ccy);
    TradeByCounterCurrencyFilter(const TradeByCounterCurrencyFilter & filter);
    virtual ~TradeByCounterCurrencyFilter();

    TradeByCounterCurrencyFilter & operator=(const TradeByCounterCurrencyFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;
    virtual std::ostream & Print(std::ostream & strm) const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;

private:
    Currency m_counter_currency;
};
}

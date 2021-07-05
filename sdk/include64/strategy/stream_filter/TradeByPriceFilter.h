#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByPriceFilter matched trades with specified price.
//****************************************************************************************

#include "strategy/stream_filter/TradeFilter.h"
#include "strategy/type/Price.h"

namespace tbricks {

class STRATEGY_EXPORT TradeByPriceFilter : public TradeFilterCondition
{
public:
    /// Default constructor.
    TradeByPriceFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all trades having trade price equal to
     * the price value specified in the input parameter.
     *
     * @param price                    Instance of Price to specify the trade price.
     * @param relation                 Its value is set to Filter::EQ (Equal), hence it will
                                       filter the trades having trade price  = price specified
                                       as the input parameter.
     */
    TradeByPriceFilter(const Price & price, Filter::Relation relation = Filter::EQ);
    TradeByPriceFilter(const TradeByPriceFilter & filter);
    virtual ~TradeByPriceFilter();

    TradeByPriceFilter & operator=(const TradeByPriceFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;
    virtual std::ostream & Print(std::ostream & strm) const;

protected:
    virtual filter::FieldFilter GetValue() const;

private:
    Filter::Relation m_relation = Filter::EQ;
    bool m_is_empty = false;
    double m_value = 0.0;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::ByCurrencyFilter, matches the updates of
// instrument with specified currency.
//****************************************************************************************

#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

/**
 * InstrumentStream::Filters::ByCurrencyFilter concrete instrument instance updates
 * having specific currency.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::ByCurrencyFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all instruments created with specified currency.
     *
     * @param currency                      currency instance.
     */
    ByCurrencyFilter(const Currency & currency);
    ByCurrencyFilter(const ByCurrencyFilter & filter);

    ByCurrencyFilter & operator=(const ByCurrencyFilter & filter);

    /**
     * Get currency method gives the detail about the present currency
     * set for the ByCurrencyFilter.
     *
     * @return                              the currency set in the filter
     */
    const Currency & GetCurrency() const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual void Clear();
    virtual bool Empty() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Currency m_currency;
};
}

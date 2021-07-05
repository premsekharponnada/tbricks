#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ReferenceExchangeRateByCurrencyPairFilter, selects reference prices
// by their currency pair.
//****************************************************************************************

#include "strategy/type/Currency.h"
#include "strategy/stream_filter/ReferenceExchangeRateFilter.h"

namespace tbricks {

/**
 * ReferenceExchangeRateByCurrencyPairFilter matches reference exchange rates of specified currency pair
 */
class STRATEGY_EXPORT ReferenceExchangeRateByCurrencyPairFilter : public ReferenceExchangeRateFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all reference exchange rates of specified currency pair
     * (for example USD/SEK where USD is counter currency and SEK is currency).
     *
     * @param counter_currency             Counter currency
     * @param currency                     Currency
     */
    ReferenceExchangeRateByCurrencyPairFilter(const Currency & counter_currency, const Currency & currency);

    ReferenceExchangeRateByCurrencyPairFilter(const ReferenceExchangeRateByCurrencyPairFilter & filter);

    ReferenceExchangeRateByCurrencyPairFilter & operator=(const ReferenceExchangeRateByCurrencyPairFilter & filter);

    /**
     * %Set counter currency for the filter.
     *
     * @param counter_currency             Instance of Currency
     */
    void SetCounterCurrency(const Currency & counter_currency);

    /**
     * Get counter currency set for the filter.
     *
     * @return                             Currency instance.
     */
    const Currency & GetCounterCurrency() const;

    /**
     * %Set currency for the filter.
     *
     * @param currency                     Instance of Currency
     */
    void SetCurrency(const Currency & currency);

    /**
     * Get currency set for the filter.
     *
     * @return                             Currency instance.
     */
    const Currency & GetCurrency() const;

    /**
     * %Set currency pair for the filter.
     *
     * @param counter_currency             Instance of Currency to set counter currency.
     * @param currency                     Instance of Currency to set currency.
     */
    void SetCurrencyPair(const Currency & counter_currency, const Currency & currency);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Currency m_counter_currency;
    Currency m_currency;
};
}

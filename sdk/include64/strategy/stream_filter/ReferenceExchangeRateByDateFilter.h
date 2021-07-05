#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ReferenceExchangeRateByDateFilter, selects reference exchange rates by their date.
//****************************************************************************************

#include "strategy/type/Date.h"
#include "strategy/stream_filter/ReferenceExchangeRateFilter.h"

namespace tbricks {

/**
 * ReferenceExchangeRateByDateFilter matches reference exchange rates created starting from, until
 * or in a range of a specified date/time(s), inclusive.
 */
class STRATEGY_EXPORT ReferenceExchangeRateByDateFilter : public ReferenceExchangeRateFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all reference exchange rates created in the specified timeframe,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                      Date to start the search from
     * @param until                     Date to end the search with
     */
    ReferenceExchangeRateByDateFilter(const Date & from, const Date & until);

    ReferenceExchangeRateByDateFilter(const ReferenceExchangeRateByDateFilter & filter);

    ReferenceExchangeRateByDateFilter & operator=(const ReferenceExchangeRateByDateFilter & filter);

    /**
     * %Set initial point for the search.
     *
     * Final point value remains unchanged.
     *
     * @param from                      Date to start the search from
     */
    void SetFromDate(const Date & from);

    /**
     * Get current initial search point.
     *
     * @return                          Current settings for the starting point,
     *                                  which could be empty
     */
    const Date & GetFromDate() const;

    /**
     * %Set final position for the search.
     *
     * Initial point value remains unchanged.
     *
     * @param until                     Date to end the search with
     */
    void SetUntilDate(const Date & until);

    /**
     * Get current final search point.
     *
     * @return                          Current settings for the final point,
     *                                  which could be empty
     */
    const Date & GetUntilDate() const;

    /**
     * %Set a search range.
     *
     * @param from                      Date to start the search from
     * @param until                     Date to end the search with
     */
    void SetFromUntilDate(const Date & from, const Date & until);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Date m_from;
    Date m_until;
};
}

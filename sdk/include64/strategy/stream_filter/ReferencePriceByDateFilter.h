#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ReferencePriceByDateTimeFilter, selects reference prices by their date.
//****************************************************************************************

#include "strategy/type/DateTime.h"
#include "strategy/stream_filter/ReferencePriceFilter.h"

namespace tbricks {

/**
 * %Filter for ReferencePrice::Stream to get reference prices in a date range including the boundaries.
 *
 * To match all reference prices from the beginning of storage time until a given date
 * or since a given date until the most recent date, set "from" or "until"
 * date to empty respectively.
 * %Set both dates to empty to get all stored reference prices.
 *
 * @deprecated Deprecated in 2.14.5 use ReferencePriceByDateFilter instead.
 */
class STRATEGY_EXPORT[[deprecated(DEPRECATE_LINK)]] ReferencePriceByDateTimeFilter : public ReferencePriceFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Creates filter object that matches reference prices created in the specified timeframe,
     * including the boundaries.
     *
     * To match all stored reference prices from the beginning of storage time until a given date
     * or since a given date until the most recent date, set "from" or "until"
     * date to empty respectively.
     * %Set both dates to empty to get all stored reference prices.
     *
     * @param from                      The start date/time of the range
     * @param until                     The end date/time of the range
     */
    ReferencePriceByDateTimeFilter(const DateTime & from, const DateTime & until);

    /**
     * %Sets the start date from which reference prices should be provided.
     * Remains the end date of this time range unchanged.
     *
     * Specify the empty start date to receive reference prices from the beginning of storage time.
     *
     * @param from                      The start date/time of the range
     */
    void SetFromDate(const DateTime & from) { m_from = from; }

    /**
     * Returns the current start date from which reference prices should be provided.
     *
     * @return                          Current start date of the range.
     *                                  Could be empty which means that reference prices
     *                                  will be provided from the beginning of storage time.
     */
    const DateTime & GetFromDate() const { return m_from; }

    /**
     * %Sets the end date till which reference prices should be provided.
     * Remains the start date of this time range unchanged.
     *
     * Specify the empty end date to receive reference prices until the most recent date.
     *
     * @param until                     The end date/time of the range
     */
    void SetUntilDate(const DateTime & until) { m_until = until; }

    /**
     * Returns the current end date till which reference prices should be provided.
     *
     * @return                          Current end date.
     *                                  Could be empty which means that reference prices
     *                                  will be provided until the most recent date.
     */
    const DateTime & GetUntilDate() const { return m_until; }

    /**
     * %Sets date interval for which reference prices should be provided.
     * To provide all stored reference prices until a given date or since a given date,
     * set "from" or "until" date to empty respectively.
     *
     * %Set both dates to empty to get all stored reference prices.
     *
     * @param from                      The start date/time of the range
     * @param until                     The end date/time of the range
     */
    void SetFromUntilDate(const DateTime & from, const DateTime & until)
    {
        m_from = from;
        m_until = until;
    }
    /**
     * Clears the dates interval, which makes the filter matching any reference price, regardless of date.
     */
    virtual void Clear()
    {
        m_from = DateTime();
        m_until = DateTime();
    }

    virtual tbricks::filter::FieldFilter GetValue() const;

    /**
     * Checks if filter is empty, which means it matches any reference price.
     */
    virtual bool Empty() const { return m_from.Empty() && m_until.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DateTime m_from;
    DateTime m_until;
};
}

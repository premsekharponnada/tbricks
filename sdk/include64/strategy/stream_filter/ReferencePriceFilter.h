#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in reference price streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/**
 * Default strategy filter, matches all data.
 */
class STRATEGY_EXPORT ReferencePriceFilter : public Filter
{
public:
    ReferencePriceFilter();
    ReferencePriceFilter(const ReferencePriceFilter & filter);
    ~ReferencePriceFilter();

    ReferencePriceFilter & operator=(const ReferencePriceFilter & filter);

    ReferencePriceFilter & operator|=(const ReferencePriceFilter & filter);
    ReferencePriceFilter & operator&=(const ReferencePriceFilter & filter);

    ReferencePriceFilter operator||(const ReferencePriceFilter & filter);
    ReferencePriceFilter operator&&(const ReferencePriceFilter & filter);

    ReferencePriceFilter operator!();

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
using AnyReferencePriceFilter = ReferencePriceFilter;

class STRATEGY_EXPORT ReferencePriceFilterCondition : public FilterCondition
{
public:
    ReferencePriceFilter operator||(const ReferencePriceFilterCondition & cond) const;
    ReferencePriceFilter operator&&(const ReferencePriceFilterCondition & cond) const;
    ReferencePriceFilter operator||(const ReferencePriceFilter & cond) const;
    ReferencePriceFilter operator&&(const ReferencePriceFilter & cond) const;
    ReferencePriceFilter operator!() const;
    operator ReferencePriceFilter() const;
};

/**
 * %Filter for ReferencePrice::Stream to get reference prices in a date range including the boundaries.
 *
 * To match all reference prices from the beginning of storage time until a given date
 * or since a given date until the most recent date, set "from" or "until"
 * date to empty respectively.
 * %Set both dates to empty to get all stored reference prices.
 */
class STRATEGY_EXPORT ReferencePriceByDateFilter : public ReferencePriceFilterCondition
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
    ReferencePriceByDateFilter(const Date & from, const Date & until);

    /**
     * %Sets the start date from which reference prices should be provided.
     * Remains the end date of this time range unchanged.
     *
     * Specify the empty start date to receive reference prices from the beginning of storage time.
     *
     * @param from                      The start date/time of the range
     */
    void SetFromDate(const Date & from) { m_from = from; }

    /**
     * Returns the current start date from which reference prices should be provided.
     *
     * @return                          Current start date of the range.
     *                                  Could be empty which means that reference prices
     *                                  will be provided from the beginning of storage time.
     */
    const Date & GetFromDate() const { return m_from; }

    /**
     * %Sets the end date till which reference prices should be provided.
     * Remains the start date of this time range unchanged.
     *
     * Specify the empty end date to receive reference prices until the most recent date.
     *
     * @param until                     The end date/time of the range
     */
    void SetUntilDate(const Date & until) { m_until = until; }

    /**
     * Returns the current end date till which reference prices should be provided.
     *
     * @return                          Current end date.
     *                                  Could be empty which means that reference prices
     *                                  will be provided until the most recent date.
     */
    const Date & GetUntilDate() const { return m_until; }

    /**
     * Clears the dates interval, which makes the filter matching any reference price, regardless of date.
     */
    virtual void Clear()
    {
        m_from.Clear();
        m_until.Clear();
    }

    /**
     * Checks if filter is empty, which means it matches any reference price.
     */
    virtual bool Empty() const { return m_from.Empty() && m_until.Empty(); }

    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Date m_from;
    Date m_until;
};
}

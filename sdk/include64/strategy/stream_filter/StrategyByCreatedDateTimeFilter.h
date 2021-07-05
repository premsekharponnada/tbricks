#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyByCreatedDateTimeFilter matches strategies by their creation date.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/type/DateTime.h"
#include "strategy/stream_filter/StrategyFilter.h"
#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"

namespace tbricks {

/**
 * StrategyByCreatedDateTimeFilter matches strategies created starting from, until
 * or in a range of a specified date/time(s), inclusive.
 */
class STRATEGY_EXPORT StrategyByCreatedDateTimeFilter : public StrategyFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all strategies created in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    StrategyByCreatedDateTimeFilter(const DateTime & from, const DateTime & until) : m_impl(from, until) {}

    /**
     * %Set initial point for the search.
     *
     * Final point value remains unchanged.
     *
     * @param from                      Date/time to start the search from
     */
    void SetFromDate(const DateTime & from) { m_impl.SetFromDate(from); }

    /**
     * %Set final position for the search.
     *
     * Initial point value remains unchanged.
     *
     * @param until                     Date/time to end the search with
     */
    void SetUntilDate(const DateTime & until) { m_impl.SetUntilDate(until); }

    /**
     * Get current initial search point.
     *
     * @return                          Current settings for the starting point,
     *                                  which can be empty
     */
    const DateTime & GetFromDate() const { return m_impl.GetFromDate(); }

    /**
     * Get current final search point.
     *
     * @return                          Current settings for the final point,
     *                                  which can be empty
     */
    const DateTime & GetUntilDate() const { return m_impl.GetUntilDate(); }

    /**
     * %Set a search range.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    void SetFromUntilDate(const DateTime & from, const DateTime & until)
    {
        m_impl.SetFromDate(from);
        m_impl.SetUntilDate(until);
    }

    virtual void Clear() { m_impl.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_impl.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << "<strategy by host created date time filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeConditionImpl m_impl;
};
}

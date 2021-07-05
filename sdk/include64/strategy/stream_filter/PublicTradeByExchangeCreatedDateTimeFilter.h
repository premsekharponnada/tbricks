#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PublicTradeByExchangeCreatedDateTimeFilter, selects trades by their creation date.
//****************************************************************************************

#include "strategy/type/DateTime.h"
#include "strategy/stream_filter/PublicTradeFilter.h"

namespace tbricks {

/**
 * PublicTradeByExchangeCreatedDateTimeFilter matches trades issued on venue from, until
 * or in a range of a specified date/time(s), inclusive.
 */
class STRATEGY_EXPORT PublicTradeByExchangeCreatedDateTimeFilter : public PublicTradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all trades created in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    PublicTradeByExchangeCreatedDateTimeFilter(const DateTime & from, const DateTime & until);

    PublicTradeByExchangeCreatedDateTimeFilter(const PublicTradeByExchangeCreatedDateTimeFilter & filter);

    PublicTradeByExchangeCreatedDateTimeFilter & operator=(const PublicTradeByExchangeCreatedDateTimeFilter & filter);

    /**
     * %Set initial point for the search.
     *
     * Final point value remains unchanged.
     *
     * @param from                      Date/time to start the search from
     */
    void SetFromDate(const DateTime & from);

    /**
     * Get current initial search point.
     *
     * @return                          Current settings for the starting point,
     *                                  which could be empty
     */
    const DateTime & GetFromDate() const;

    /**
     * %Set final position for the search.
     *
     * Initial point value remains unchanged.
     *
     * @param until                     Date/time to end the search with
     */
    void SetUntilDate(const DateTime & until);

    /**
     * Get current final search point.
     *
     * @return                          Current settings for the final point,
     *                                  which could be empty
     */
    const DateTime & GetUntilDate() const;

    /**
     * %Set a search range.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    void SetFromUntilDate(const DateTime & from, const DateTime & until);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DateTime m_from;
    DateTime m_until;
};
}

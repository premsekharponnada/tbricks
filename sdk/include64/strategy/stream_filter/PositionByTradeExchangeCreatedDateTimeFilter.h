#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PositionByTradeExchangeCreatedDateTimeFilter, matches updates of concrete portfolio
// instance having specified exchange creation trade date.
//****************************************************************************************

#include "strategy/stream_filter/PositionFilter.h"
#include "strategy/type/DateTime.h"

namespace tbricks {

/**
 * PositionByTradeExchangeCreatedDateTimeFilter matches concrete
 * position instance updates, selected by trade created date and time range.
 */
class STRATEGY_EXPORT PositionByTradeExchangeCreatedDateTimeFilter : public PositionFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all positions created in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    PositionByTradeExchangeCreatedDateTimeFilter(const DateTime & datetime_from, const DateTime & datetime_to);

    PositionByTradeExchangeCreatedDateTimeFilter(const PositionByTradeExchangeCreatedDateTimeFilter & filter);

    PositionByTradeExchangeCreatedDateTimeFilter & operator=(const PositionByTradeExchangeCreatedDateTimeFilter & filter);

    /**
     * Positions by today trades
     */
    static PositionByTradeExchangeCreatedDateTimeFilter Today();

    /**
     * Positions by trades with specified date
     */
    static PositionByTradeExchangeCreatedDateTimeFilter Day(const DateTime & date);

    /**
     * Positions by trades with interval [date, *) (date included to interval)
     * All positions having exchange trade creation date equal to and above than
     * specified date time.
     */
    static PositionByTradeExchangeCreatedDateTimeFilter AllAboveDay(const DateTime & datetime);

    /**
     * Positions by trades with interval (*, date] (date included to interval)
     * All positions having exchange trade creation date equal to and below than
     * specified date time.
     */
    static PositionByTradeExchangeCreatedDateTimeFilter AllBeforeDay(const DateTime & datetime);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DateTime m_datetime_from;
    DateTime m_datetime_to;
};
}

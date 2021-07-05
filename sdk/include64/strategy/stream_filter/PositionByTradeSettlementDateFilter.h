#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PositionByTradeSettlementDateFilter, matches updates of concrete portfolio instance
// having specified trade settlement date.
//****************************************************************************************

#include "strategy/stream_filter/PositionFilter.h"
#include "strategy/type/DateTime.h"

namespace tbricks {

/**
 * PositionByTradeSettlementDateFilter matches concrete
 * position instance updates, selected by trade settlement date range.
 */
class STRATEGY_EXPORT PositionByTradeSettlementDateFilter : public PositionFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all positions created in the specified
     * trade settlement time frame, including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param date_from                     Date/time to start the search from
     * @param date_to                       Date/time to end the search with
     */
    PositionByTradeSettlementDateFilter(const DateTime & date_from, const DateTime & date_to);

    PositionByTradeSettlementDateFilter(const PositionByTradeSettlementDateFilter & filter);

    PositionByTradeSettlementDateFilter & operator=(const PositionByTradeSettlementDateFilter & filter);

    /**
     * Positions by today trades
     */
    static PositionByTradeSettlementDateFilter Today();

    /**
     * Positions by trades with specified date
     */
    static PositionByTradeSettlementDateFilter Day(const DateTime & date);

    /**
     * Positions by trades with interval [date, *) (date included to interval)
     * All positions having exchange trade creation date equal to and above than
     * specified date time.
     */
    static PositionByTradeSettlementDateFilter AllAboveDay(const DateTime & date);

    /**
     * Positions by trades with interval (*, date] (date included to interval)
     * All positions having exchange trade creation date equal to and below than
     * specified date time.
     */
    static PositionByTradeSettlementDateFilter AllBeforeDay(const DateTime & date);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DateTime m_date_from;
    DateTime m_date_to;
};
}

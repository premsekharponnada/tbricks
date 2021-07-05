#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingCalendar object.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/CalendarDate.h"
#include "strategy/SafePointer.h"
#include "strategy/type/MIC.h"
#include "strategy/type/Duration.h"

// \namespace tbricks
namespace tbricks {

namespace calendar {
class Calendar;
}

class STRATEGY_EXPORT TradingCalendar : public Printable
{
public:
    /**
     * Default constructor. Creates empty calendar, Saturday and Sunday are weekends.
     *
     */
    TradingCalendar();

    /**
     * Copy constructor, сreates full copy of a calendar.
     *
     * @param calendar              TradingCalendar
     */
    TradingCalendar(const TradingCalendar & calendar);

    /**
     * Constructor by MIC, creates a calendar and resolves it by MIC.
     *
     * @param mic                   MIC
     */
    TradingCalendar(const MIC & mic);

    /**
     * Destructor.
     *
     */
    virtual ~TradingCalendar();

    /**
     * Copy operator, сreates full copy of a calendar.
     *
     * @param calendar              TradingCalendar
     */
    TradingCalendar & operator=(const TradingCalendar & calendar);

    /**
     * Function for loading calendar from a MIC.
     *
     * The function sequentially tries resources for a MIC, for a MIC's
     * country, and uses the default calendar if the previous two checks
     * fail.
     *
     * @param mic                   MIC
     *
     * @return bool                 'true' if resource was successfully loaded,
     *                              'false' otherwise
     */
    bool Resolve(const MIC & mic);

public:
    /**
     * This function returns true if 'date' is a trading day,
     * according to a loaded resource, and 'false' otherwise.
     *
     * @param date                  CalendarDate
     *
     * @return bool
     */
    bool IsTradingDay(const CalendarDate & date) const;

    /**
     * This function returns true if 'date' is a weekend day,
     * according to a loaded resource, and 'false' otherwise.
     *
     * @param date                  CalendarDate
     *
     * @return bool
     */
    bool IsWeekendDay(const CalendarDate & date) const;

    /**
     * This function returns true if 'date' is a holiday day,
     * according to a loaded resource, and 'false' otherwise.
     *
     * @param date                  CalendarDate
     *
     * @return bool
     */
    bool IsHolidayDay(const CalendarDate & date) const;

    /**
     * This function calculates count trading days between
     * 'from' date (inclusive) and 'to' date (not inclusive)
     * according to a loaded resource.
     *
     * For example, between June 25, 2010 and Jule 2, 2010 --- 5 days.
     *
     * @param from                  Begin date
     * @param to                    End date
     *
     * @return int
     */
    int GetNumberOfTradingDays(const CalendarDate & from, const CalendarDate & to) const;

    /**
     * This function calculates trading time between two dates
     * according to a loaded resource.
     *
     * @param from                  Begin date
     * @param to                    End date
     *
     * @return Duration
     */
    Duration GetDurationOfTrading(const CalendarDate & from, const CalendarDate & to) const;

    /**
     * This function calculates default total trading time in one
     * trading day according to a loaded resource.
     *
     * @return Duration
     */
    Duration GetDefaultDurationTradingDay() const;

    /**
     * This function return the sessions was opened in 'date'
     * according to a loaded resource.
     *
     * @param date                  CalendarDate
     *
     * @param sessions              vector of CalendarDate pairs. The
     *                              first value in the pair is
     *                              CalendarDate of opening session.
     *                              The second value in the pair
     *                              is CalendarDate of close session.
     */
    void GetSessionsOfTradingDay(const CalendarDate & date, std::vector<std::pair<CalendarDate, CalendarDate>> & sessions) const;

    /**
     * This function return the sessions was opened in trading day
     * according to a loaded resource.
     *
     * @param sessions              vector of Duration pairs. The
     *                              first value in the pair is duraion
     *                              from the midnight of the trading day
     *                              to opening session. The second value
     *                              in the pair is duration from the
     *                              midnight of the day to closing session.
     */
    void GetDefaultSessionsOfTradingDay(std::vector<std::pair<Duration, Duration>> & sessions) const;

    /**
     * This function calculates count weekend days between
     * 'from' date (inclusive) and 'to' date (not inclusive)
     * according to a loaded resource.
     *
     * For example, between June 25, 2010 and Jule 2, 2010 --- 2 days.
     *
     * @param from                  Begin date
     * @param to                    End date
     *
     * @return int
     */
    int GetNumberOfWeekendDays(const CalendarDate & from, const CalendarDate & to) const;

    /**
     * This function calculates count holiday days between
     * 'from' date (inclusive) and 'to' date (not inclusive)
     * according to a loaded resource.
     *
     * @param from                  Begin date
     * @param to                    End date
     *
     * @return int
     */
    int GetNumberOfHolidayDays(const CalendarDate & from, const CalendarDate & to) const;

    /**
     * This function adds 'numberOfDays' trading days to the CalendarDate.
     *
     * For example, if we add 1 day to Friday we obtain Monday.
     *
     * @param numberOfDays             Number days for adding
     *
     * @return CalendarDate
     */
    CalendarDate AddTradingDays(const CalendarDate & date, int numberOfDays) const;

    /**
     * Calculate next trading day.
     *
     *
     * @param date                  Calendar date
     *
     * @return CalendarDate
     */
    CalendarDate GetNextTradingDay(const CalendarDate & date) const;

private:
    void CheckEmpty() const;

public:
    /**
     * Function returns MIC which calendar resolved.
     *
     * @return const MIC&
     */
    const MIC & GetMIC() const;

    /**
     * Function returns calendar resource name
     *
     * @return String
     */
    String GetName() const;

    /**
     * Function returns true, if resolved and false otherwise.
     *
     * @return bool
     */
    bool Empty() const;

    /**
     * Function unloads calendar resource. After this call
     * calendar will empty.
     *
     */
    void Clear();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    MIC m_mic;
    SafePointer<tbricks::calendar::Calendar> m_calendar;
};

} // \namespace tbricks

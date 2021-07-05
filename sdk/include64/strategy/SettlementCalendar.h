#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// SettlementCalendar object.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/CalendarDate.h"
#include "strategy/SafePointer.h"
#include "strategy/type/MIC.h"
#include "strategy/type/Currency.h"

// \namespace tbricks
namespace tbricks {

namespace calendar {
class Calendar;
}

class STRATEGY_EXPORT SettlementCalendar : public Printable
{
public:
    /**
     * Default constructor. Creates empty calendar,
     * Saturday and Sunday are weekends.
     */
    SettlementCalendar();

    /**
     * Copy constructor, сreates full copy of a calendar.
     *
     * @param calendar              SettlementCalendar
     */
    SettlementCalendar(const SettlementCalendar & calendar);

    /**
     * Constructor by MIC, creates a calendar and resolves it by MIC.
     *
     * @param mic                   MIC
     */
    SettlementCalendar(const MIC & mic);

    /**
     * Constructor by Currency, creates a calendar and resolves it by Currency.
     *
     * @param currency              Currency
     */
    SettlementCalendar(const Currency & currency);

    /**
     * Destructor.
     */
    virtual ~SettlementCalendar();

    /**
     * Copy operator, сreates full copy of a calendar.
     *
     * @param calendar              SettlementCalendar
     */
    SettlementCalendar & operator=(const SettlementCalendar & calendar);

    /**
     * Function for loading calendar from a MIC.
     *
     * The function tries resource for a MIC's country, and
     * uses the default calendar if the previous check
     * fail.
     *
     * @param mic                   MIC
     *
     * @return bool                 'true' if resource was successfully loaded,
     *                              'false' otherwise
     */
    bool Resolve(const MIC & mic);

    /**
     * Function for loading calendar from a Currency.
     *
     * The function tries to find calendar resource associated with currency,
     * and uses the default calendar if can't find associated resource.
     *
     * @param[in]   currency        Currency
     *
     * @return      bool            'true' if resource was successfully loaded,
     *                              'false' otherwise
     */
    bool Resolve(const Currency & currency);

public:
    /**
     * This function returns true if 'date' is a settlement day,
     * according to a loaded resource, and 'false' otherwise.
     *
     * @param date                  CalendarDate
     *
     * @return bool
     */
    bool IsSettlementDay(const CalendarDate & date) const;

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
     * This function calculates count settlement days between
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
    int GetNumberOfSettlementDays(const CalendarDate & from, const CalendarDate & to) const;

    /**
     * This function calculates count settlement days between
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
     * This function calculates count settlement days between
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
     * This function adds 'numberOfDays' settlement days to the CalendarDate.
     *
     * For example, if we add 1 day to Friday we obtain Monday.
     *
     * @param numberOfDays             Number days for adding
     *
     * @return CalendarDate
     */
    CalendarDate AddSettlementDays(const CalendarDate & date, int numberOfDays) const;

    /**
     * Calculate next settlement day.
     *
     *
     * @param date                  Calendar date
     *
     * @return CalendarDate
     */
    CalendarDate GetNextSettlementDay(const CalendarDate & date) const;

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
     * Function returns Currency which calendar resolved.
     *
     * @return const Currency&
     */
    const Currency & GetCurrency() const;

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
    Currency m_currency;
    SafePointer<tbricks::calendar::Calendar> m_calendar;
};

} // \namespace tbricks

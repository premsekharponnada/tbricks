#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DateTime type, represents absolute time stamps.
//****************************************************************************************

#include "strategy/Printable.h"

#include "strategy/Linkage.h"
#include "strategy/type/String.h"

// \namespace tbricks
namespace tbricks {

//---------------------------------------------------------------------------//
// CalendarDate                                                              //
//---------------------------------------------------------------------------//

class STRATEGY_EXPORT CalendarDate : public Printable
{
public:
    class Months;
    class Years;
    class Weeks;

    enum Month
    {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    enum Day
    {
        Monday = 1,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };

public:
    CalendarDate();

    CalendarDate(const CalendarDate & calendar);

    CalendarDate(int year, int month, int day, int hour = 0, int minute = 0, int second = 0, int microsec = 0);

    /** Construct CalendarDate from String.
     *
     * Input string should contain date and optionally time separated from
     * date by any non-digit. For date/time formats see SetDate() and
     * SetTime().
     */
    explicit CalendarDate(const String & string);

    void SetYear(int year);
    int GetYear() const;

    void SetMonth(int month);
    int GetMonth() const;

    void SetDay(int day);
    int GetDay() const;

    void SetHour(int hour);
    int GetHour() const;

    void SetMinute(int minute);
    int GetMinute() const;

    void SetSecond(int second);
    int GetSecond() const;

    void SetMicrosecond(int microsecond);
    int GetMicrosecond() const;

    CalendarDate RoundToDay() const;
    bool IsRoundToDay() const;

    /** Sets date to the value parsed from string.
     *
     * Date must be in the following format: yyyyXmmXdd, where X is optional
     * or any non-digit characters.
     */
    bool SetDate(const String & string) { return SetDate(string, nullptr); }

    /** Sets time to the value parsed from string.
     *
     * Time must be in the following format: hh:mm:ss followed by optional
     * ms (3 digits) or us (6 digits) separated from seconds by any non-digit.
     */
    bool SetTime(const String & string) { return SetTime(string, 0); }

    bool Empty() const
    {
        return (m_year == 0) && (m_month == 0) && (m_day == 0) && (m_hour == 0) && (m_minute == 0) && (m_second == 0) && (m_microsec == 0);
    }
    void Clear();

    size_t GetHash() const;

private:
    bool SetDate(const String & string, size_t * res_offset);
    bool SetTime(const String & string, size_t offset);

public:
    CalendarDate & operator=(const CalendarDate & calendar);

    bool operator==(const CalendarDate & calendar) const;
    bool operator!=(const CalendarDate & calendar) const;

    bool operator<(const CalendarDate & calendar) const;
    bool operator<=(const CalendarDate & calendar) const;
    bool operator>(const CalendarDate & calendar) const;
    bool operator>=(const CalendarDate & calendar) const;

    std::ostream & Print(std::ostream & strm) const override;

    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const Day & day);

public:
    /**
     * This function return day of week , which corresponds this date.
     *
     * @return CalendarDate::Day
     */
    Day GetDayOfWeek() const;

    /**
     * This function adds 'count' days to the CalendarDate.
     *
     * For example, if we add 1, 2, 3 and 7 day to June 25, 2010 (Friday),
     * we obtain respectively 26, 27, 28 June, 2010 and 2 Jule, 2010.
     *
     * @param count                     Number days for adding
     *
     * @return CalendarDate
     */
    CalendarDate & operator+=(int count);

    /**
     * This function adds 'count' days to the CalendarDate.
     *
     * For example, if we add 1, 2, 3 and 7 day to June 25, 2010 (Friday),
     * we obtain respectively 26, 27, 28 June, 2010 and 2 Jule, 2010.
     *
     * @param count                     Number days for adding
     *
     * @return CalendarDate
     */
    CalendarDate operator+(int count) const;

    /**
     * This function adds years to the CalendarDate.
     *
     * Example:
     *   CalendarDate calendarDate(2017, CalendarDate::January, 3);
     *   calendarDate += CalendarDate::Years(2); // 2019 January 3
     *
     * @param  years                    Number years for adding
     *
     * @return CalendarDate&
     */
    CalendarDate & operator+=(const Years & years);

    /**
     * This function adds years to the CalendarDate.
     *
     * @param  years                    Number years for adding
     *
     * @return CalendarDate
     */
    CalendarDate operator+(const Years & years) const;

    /**
     * This function adds months to the CalendarDate.
     *
     * Example:
     *   CalendarDate calendarDate(2017, CalendarDate::January, 3);
     *   calendarDate += CalendarDate::Months(4); // 2017 May 3
     *
     * Note: if new CalendarDate has incorrect number of days in month, these
     *       days are cut.
     *   CalendarDate calendarDate(2016, CalendarDate::January, 31);
     *   calendarDate += CalendarDate::Months(1); // 2017 April 29
     *
     * @param  months                   Number months for adding
     *
     * @return CalendarDate&
     */
    CalendarDate & operator+=(const Months & months);

    /**
     * This function adds months to the CalendarDate.
     *
     * Note: if new CalendarDate has incorrect number of days in month, these
     *       days are cut.
     *
     * @param  months                   Number months for adding
     *
     * @return CalendarDate
     */
    CalendarDate operator+(const Months & moths) const;

    /**
     * This function adds weeks to the CalendarDate.
     *
     * @param  weeks                    Number weeks for adding
     *
     * @return CalendarDate&
     */
    CalendarDate & operator+=(const Weeks & weeks);

    /**
     * This function adds weeks to the CalendarDate.
     *
     * @param  weeks                    Number weeks for adding
     *
     * @return CalendarDate
     */
    CalendarDate operator+(const Weeks & weeks) const;

    /**
     * This static function calculates count days between
     * 'begin' date (inclusive) and 'end' date (not inclusive).
     *
     * For example, between June 25, 2010 and Jule 2, 2010 --- 7 days.
     *
     * @param begin                     Begin date
     * @param end                       End date
     *
     * @return int
     */
    static int GetCountDaysBetween(const CalendarDate & begin, const CalendarDate & end);

    /**
     * This static function calculates the i-th day of j-th the week.
     * For example, if you want calculate 3rd friday of January in 2010 year,
     * you can call:
     * @code
     *     CalendarDate::GetSpecialDay(2010, CalendarDate::January, CalendarDate::Friday, 3);
     * @endcode
     *
     * If requested day doesn't exist, an BadDateException will be thrown.
     *
     * @param year                      Year
     * @param month                     Month
     * @param which_day                 Day
     * @param which_week                Number of week
     *
     * @throw BadDateException
     *
     * @return CalendarDate
     */
    static CalendarDate GetSpecialDay(int year, Month month, Day which_day, int which_week);

private:
    int m_year;
    int m_month;
    int m_day;
    int m_hour;
    int m_minute;
    int m_second;
    int m_microsec;
};

//---------------------------------------------------------------------------//
// CalendarDate::Years                                                       //
//---------------------------------------------------------------------------//

class STRATEGY_EXPORT CalendarDate::Years
{
public:
    explicit Years(int years);

private:
    friend class CalendarDate;
    int m_years;
};

//---------------------------------------------------------------------------//
// CalendarDate::Months                                                      //
//---------------------------------------------------------------------------//

class STRATEGY_EXPORT CalendarDate::Months
{
public:
    explicit Months(int months);

private:
    friend class CalendarDate;
    int m_months;
};

//---------------------------------------------------------------------------//
// CalendarDate::Weeks                                                       //
//---------------------------------------------------------------------------//

class STRATEGY_EXPORT CalendarDate::Weeks
{
public:
    explicit Weeks(int weeks);

private:
    friend class CalendarDate;
    int m_weeks;
};

//---------------------------------------------------------------------------//

inline size_t hash_value(const CalendarDate & value)
{
    return value.GetHash();
}

} // \namespace tbricks

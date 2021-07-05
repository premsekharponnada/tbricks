#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DateTime type, represents absolute time stamps.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/type/String.h"
#include "strategy/type/Integer.h"
#include "strategy/type/Duration.h"
#include "strategy/type/CalendarDate.h"
#include "strategy/type/Date.h"
#include "strategy/type/Time.h"

// \namespace tbricks
namespace tbricks {

namespace types {
class DateTime;
}

class STRATEGY_EXPORT DateTime : public TypeWithError
{
public:
    enum Precision
    {
        EMPTY = 0,             /**< Empty date and time */
        DATE = 1,              /**< Only date part is stored */
        DATE_TIME = 2,         /**< Stored date and time up to seconds */
        DATE_TIME_FRACTION = 3 /**< Date and time up to milliseconds */
    };

    enum Format
    {
        DEFAULT,       /**< %Y-%m-%d %H:%M:%S.FFFF   */
        WITH_TIMEZONE, /**< %Y-%m-%d %H:%M:%S.FFFF  <timezone>*/
        FIX            /**< YYYYMMDD-HH:MM:SS[.ssssss] FIX protocol date format */
    };

public:
    /**
     * Constructor.
     *
     * Creates new DateTime with specified precision and time zone
     *
     * @param precision             Time precision, default EMPTY (by default DateTime has empty state <uninitialized>)
     * @param timezone              Time zone
     */
    DateTime(Precision precision = EMPTY, const TimeZone & timezone = TimeZone::GetLocal());

    DateTime(const DateTime & datetime) = default;
    DateTime(DateTime && datetime) noexcept = default;

    ~DateTime() override = default;

    DateTime & operator=(const DateTime & datetime) = default;
    DateTime & operator=(DateTime && datetime) noexcept = default;
    DateTime & operator=(const types::DateTime & value);

    /**
     * Create DateTime with local time.
     *
     * Returns local date and time with fraction in local timezone
     *
     * @return                      Created DateTime
     *
     * @code
     * // Get local time
     * DateTime dt = DateTime::Now();
     * std::cout << dt << std::endl;
     *
     * // Output:
     * // 2009-05-26 14:25:41.615 CEST
     * @endcode
     */
    static DateTime Now();

    /**
     * Create DateTime with local time.
     *
     * Returns local date and time in specified time zone
     *
     * @param precision             Time precision
     * @param timezone              Time zone
     *
     * @return                      Created DateTime
     *
     * @code
     * // Get local time
     * DateTime dt = DateTime::Now();
     * std::cout << dt << std::endl;
     *
     * // Output:
     * // 2009-05-26 14:25:41.615 CEST
     * @endcode
     */
    static DateTime Now(Precision precision, const TimeZone & timezone = TimeZone::GetLocal());

    /**
     * Create DateTime with midnight time (day/month/year 00:00).
     *
     * Returns DateTime with midnight time
     *
     * @param precision             Time precision
     * @param timezone              Time zone
     *
     * @return                      Created DateTime
     *
     * @code
     * // Create today midnight time with fraction for Japanese timezone
     * DateTime dt = DateTime::Today(DateTime::DATE_TIME_FRACTION, TZ_JST);
     * std::cout << dt << std::endl;
     *
     * // Get 500 seconds from Japanese midnight
     * DateTime dt_500sec = dt + Duration::Seconds(500);
     * std::cout << dt_500sec << std::endl;
     *
     * // Output:
     * // 2009-05-26 00:00:00.000 JST
     * // 2009-05-26 00:08:20.000 JST
     * @endcode
     */
    static DateTime Today(Precision precision = DATE_TIME_FRACTION, const TimeZone & timezone = TimeZone::GetLocal());

    /**
     * Create DateTime with today date and specified time
     * Precision will always DATE_TIME_FRACTION
     * Time zone same as time zone in Time object
     *
     * Returns DateTime
     *
     * @return                      Created DateTime
     *
     * @code
     * // Create today 12:00 time with fraction for local timezone
     * DateTime dt = DateTime::Today(Time(12, 0, 0));
     * std::cout << dt << std::endl;
     * @endcode
     */
    static DateTime Today(const Time & time);

    /**
     * Create DateTime from CalendarDate
     *
     * Returns DateTime with time specified in CalendarDate
     *
     * @param calendar              Date and time fields
     * @param precision             Time precision
     * @param timezone              Time zone
     *
     * @return                      Created DateTime
     *
     * @code
     * //Create time 1/05/2009 12:00:00.0000
     * DateTime dt = DateTime::Create(CalendarDate(2009, 5, 1, 12, 0, 0, 0));
     * std::cout << dt << std::endl;
     *
     * // Output:
     * // 2009-05-01 12:00:00.000 CEST
     * @endcode
     */
    static DateTime Create(const CalendarDate & calendar, Precision precision = DATE_TIME_FRACTION, const TimeZone & timezone = TimeZone::GetLocal());

    /**
     * Create DateTime which starts from date
     *
     * Returns DateTime started from Date of other DateTime
     * For example: if the first parameter is DateTime with day/month/year
     * the result DateTime is day/month/year hour:minute:second:microsec
     * where hour, minute, second and microsec is function parameters
     *
     * @param datetime              DateTime which starts from
     * @param hour                  Hours
     * @param minute                Minutes
     * @param second                Seconds
     * @param microsec              Microseconds
     *
     * @return                      Created DateTime
     *
     * @code
     * //Create today midnight time
     * DateTime dt_today = DateTime::Today();
     * std::cout << "Today midnight: " << dt_today << std::endl;
     *
     * //Create time started from dt_today (dt_today 02:03:04.567)
     * DateTime dt = DateTime::Create(dt_today, 2, 3, 4, 567000);
     * std::cout << "Time from midnight: " << dt_today << std::endl;
     *
     * // Output:
     * // Today midnight: 2009-05-26 00:00:00.000 CEST
     * // Time from midnight: 2009-05-26 02:03:04.567 CEST
     * @endcode
     */
    static DateTime Create(const DateTime & datetime, int hour, int minute, int second, int microsec = 0);

    /**
     * Create DateTime from date of another DateTime and specified time
     *
     * Returns DateTime started from Date of other DateTime
     * For example: if the first parameter is DateTime with day/month/year
     * the result DateTime is day/month/year hour:minute:second:microsec
     * where hour, minute, second and microsec is value from second function parameter
     *
     * @param datetime              DateTime for date part
     * @param time                  Time part of returned DateTime
     *
     * @return                      Created DateTime
     *
     * @code
     * //Create today midnight time
     * DateTime dt_today = DateTime::Today();
     * std::cout << "Today midnight: " << dt_today << std::endl;
     *
     * //Create time started from dt_today (dt_today 02:03:04.567)
     * DateTime dt = DateTime::Create(dt_today, Time(2, 3, 4, 567000));
     * std::cout << "Time from midnight: " << dt_today << std::endl;
     *
     * // Output:
     * // Today midnight: 2009-05-26 00:00:00.000 CEST
     * // Time from midnight: 2009-05-26 02:03:04.567 CEST
     * @endcode
     */
    static DateTime Create(const DateTime & datetime, const Time & time);

    /**
     * Create DateTime from specified date and specified time
     *
     * Returns DateTime
     *
     * @param date                  Date for date part
     * @param time                  Time part of returned DateTime
     *
     * @return                      Created DateTime
     *
     * @code
     * //Create date and time object
     * DateTime dt = DateTime::Create(Date(2012, 2, 28), Time(2, 3, 4, 567000));
     * std::cout << dt << std::endl;
     *
     * // Output:
     * // 2012-02-28 02:03:04.567 CEST
     * @endcode
     */
    static DateTime Create(const Date & date, const Time & time);

    /**
     * Create DateTime from string
     *
     * Returns DateTime created from string.
     * String should be formatted as %Y-%m-%d %H%:%M:%S.FFF
     *
     * @param precision             Time precision
     * @param timezone              Time zone
     *
     * @return                      Created DateTime
     *
     * @code
     * //Create time from string
     * DateTime dt = DateTime::Parse("2009-05-01 15:23:01.432");
     * std::cout << dt << std::endl;
     *
     * // Output:
     * // 2009-05-01 15:23:01.432 UTC
     * @endcode
     */
    static DateTime
    Parse(const String & value, Format format = DEFAULT, Precision precision = DATE_TIME_FRACTION, const TimeZone & timezone = TimeZone::GetUTC());

    /**
     * Create DateTime from POSIX time
     * (useconds from Thursday, January 1, 1970)
     *
     * Returns DateTime created from useconds.
     *
     * @param usec                  Number of microseconds from from Thursday, January 1, 1970 00:00.000000
     * @param precision             Time precision
     * @param timezone              Time zone
     *
     * @return                      Created DateTime
     *
     */
    static DateTime Create(const Integer & usec, Precision precision = DATE_TIME_FRACTION, const TimeZone & timezone = TimeZone::GetUTC());

    /**
     * Convert DateTime to time with another precision and/or time zone
     *
     * Returns DateTime with new precision and time zone.
     * Time will be adjusted to new time zone
     *
     * @param datetime              DateTime which converted from
     * @param precision             Time precision
     * @param timezone              Time zone
     *
     * @return                      New DateTime
     *
     * @code
     * //Create time with fraction
     * DateTime dtf = DateTime::Now();
     * std::cout << "Now: " << dtf << std::endl;
     *
     * //Convert time with fraction to time without fraction
     * DateTime dt = DateTime::Convert(dtf, DateTime::DATE_TIME);
     * std::cout << "DATE_TIME: " << dtf << std::endl;
     *
     * //Convert time with fraction to date
     * DateTime d = DateTime::Convert(dtf, DateTime::DATE);
     * std::cout << "DATE: " << dtf << std::endl;
     *
     * //Change timezone to NY with daylight adjustment
     * DateTime dtf_us = DateTime::Convert(dtf, DateTime::DATE_TIME_FRACTION, TZ_DST_AMERICA_NEW_YORK);
     * std::cout << "Now (NY): " << dtf_us << std::endl;
     *
     * // Output:
     * // Now: 2009-05-26 14:53:40.698 CEST
     * // DATE_TIME: 2009-05-26 14:53:40 CEST
     * // DATE: 2009-05-26 CEST
     * // Now (NY): 2009-05-26 08:53:40.698 EDT
     * @endcode
     */
    static DateTime Convert(const DateTime & datetime, Precision precision = DATE_TIME_FRACTION, const TimeZone & timezone = TimeZone::GetLocal());

    /**
     * Check DateTime for empty state
     *
     * @return                      True if DateTime has EMPTY precision, false otherwise
     */
    bool Empty() const override;
    void Clear() override;

    /**
     * Get DateTime precision
     *
     * @return                      Time precision
     */
    Precision GetPrecision() const;

    /**
     * Get DateTime time zone
     *
     * @return                      Time zone
     */
    TimeZone GetTimeZone() const;

    /**
     * Get date and time fields
     *
     * @param timezone              Timezone which is used for time fields representation
     *
     * @return                      CalendarDate object which encapsulated date and time fields
     */
    CalendarDate GetCalendarDate(const TimeZone & timezone = TimeZone::GetLocal()) const;

    /**
     * Get POSIX value
     *
     * @param timezone              Timezone which is used for time representation
     *
     * @return                      Number of microseconds from from Thursday, January 1, 1970 00:00.000000
     */
    Integer GetTimeValue(const TimeZone & timezone = TimeZone::GetUTC()) const;

    /**
     * Get date part
     *
     * @return                      Date object with date part of the DateTime with the same time zone
     */
    Date GetDate() const;

    /**
     * Get time part
     *
     * @return                      Time object with time part of the DateTime with the same time zone
     */
    Time GetTime() const;

    /**
     * Get type information
     *
     * @return                      DateTime type information
     */
    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_DATE_TIME; }

    /**
     * Get difference between two DateTime
     *
     * @param datetime              DateTime to compute difference from current object
     *
     * @return                      Difference Duration
     */
    Duration Difference(const DateTime & datetime) const;

    /**
     * Get textual representation of DateTime
     *
     * @param format              Text format
     *
     * @return                    Textual representation of local DateTime
     */
    virtual String ToString(Format format) const;

    /**
     * Get textual representation of DateTime in specified time zone
     *
     * @param timezone            Time zone
     * @param format              Text format
     *
     * @return                    Textual representation of local DateTime
     */
    String ToString(TimeZone timezone, Format format = DEFAULT) const;

    String ToString() const override;

    /**
     * Returns minimum possible value
     *
     * @return                    Minimum possible DateTime
     */
    static DateTime MinValue();

    /**
     * Returns maximum possible value
     *
     * @return                    Maximum possible DateTime
     */
    static DateTime MaxValue();

    size_t GetHash() const override;

public:
    DateTime & operator+=(const Duration & duration);
    DateTime operator+(const Duration & duration) const;

    DateTime & operator-=(const Duration & duration);
    DateTime operator-(const Duration & duration) const;

    Duration operator-(const DateTime & datetime) const;

    bool operator==(const DateTime & datetime) const;
    bool operator!=(const DateTime & datetime) const;

    bool operator<(const DateTime & datetime) const;
    bool operator<=(const DateTime & datetime) const;
    bool operator>(const DateTime & datetime) const;
    bool operator>=(const DateTime & datetime) const;

    STRATEGY_EXPORT friend DateTime operator+(const Duration & duration, const DateTime & datetime);

    DateTime(const types::DateTime & datetime);
    tbricks::types::DateTime GetDateTime() const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    uint8_t m_type;
    int64_t m_sec;
    int32_t m_usec;
    uint16_t m_tz_id;
};

} // \namespace tbricks

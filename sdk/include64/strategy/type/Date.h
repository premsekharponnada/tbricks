#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Date type
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/type/String.h"
#include "strategy/type/Integer.h"
#include "strategy/type/Duration.h"
#include "strategy/type/CalendarDate.h"
#include "strategy/type/TimeZone.h"

// \namespace tbricks
namespace tbricks {

namespace FIX {
class Group;
class MessageBuilder;
}
namespace types {
class Date;
}

/**
 * Representation of date class. It contains year, months and days.
 * Now Date contains time zone identifier, but it is deprecated,
 * and in the most of cases will be set as Empty.
 */
class STRATEGY_EXPORT Date : public TypeWithError
{
public:
    /**
     * @deprecated WITH_TIMEZONE item is deprecated. Deprecated in 2.11.1
     */
    enum Format
    {
        DEFAULT,       /**< %Y-%m-%d */
        WITH_TIMEZONE, /**< %Y-%m-%d <timezone>*/
        FIX            /**< YYYYMMDD FIX protocol date format */
    };

    /**
     * Create empty date
     */
    Date();
    Date(const Date & date) = default;
    Date(Date && date) noexcept = default;
    ~Date() override = default;

    Date & operator=(const Date & date) = default;
    Date & operator=(Date && date) noexcept = default;

    /**
     * Create Date object with current date and empty time zone.
     *
     * Example:
     *
     * Current date time is 2017-04-25 00:00.000 UTC or
     *                      2017-04-25 03:00.000 MSK or
     *                      2017-04-24 18:00.000 CST
     *
     * @code
     * Date date = Date::Now(TZ_MSK);
     * std::cout << date << std::endl;
     *
     * // Output
     * // 2017-04-25
     * @endcode
     *
     * @code
     * Date date = Date::Now(TZ_CST);
     * std::cout << date << std::endl;
     *
     * // Output
     * // 2017-04-24
     * @endcode
     *
     * @param          TimeZone
     *
     * @return         Current date
     */
    static Date Now(const TimeZone & timezone = TimeZone::GetLocal());

    /**
     * Create Date
     *
     * Result date is year-month-day where year, month, day specified by calendar.
     * By default time zone is empty.
     *
     * Example:
     * Calendar date is 2017-04-24
     * @code
     * Date empty = Date::Create(cd);
     * Date msk   = Date::Create(cd, TZ_MSK);
     *
     * std::cout << empty << std::endl
     *           << msk   << std::endl;
     *
     * // Output:
     * // 2017-04-25
     * // 2017-04-25 MSK
     * @endcode
     *
     * @return         Specified date
     */
    static Date Create(const CalendarDate & calendar, const TimeZone & timezone = TimeZone::GetEmpty());

    /**
     * Create Date
     *
     * Result date is year-month-day where year, month, day are function parameters.
     * By default time zone is empty.
     *
     * Example:
     * @code
     * Date empty = Date::Create(2017, 4, 25);
     * Date msk   = Date::Create(2017, 4, 25, TZ_MSK);
     *
     * std::cout << empty << std::endl
     *           << msk   << std::endl;
     *
     * // Output:
     * // 2017-04-25
     * // 2017-04-25 MSK
     * @endcode
     *
     * @return         Specified date
     */
    static Date Create(int year, int month, int day, const TimeZone & timezone = TimeZone::GetEmpty());

    /**
     * Parse date from string.
     *
     * @param         value    - String
     * @param         format   - Format of string (DEFAULT/FIX)
     * @param         timezone - Default time zone, will be set
     *                           if time zone cannot be parsed from string
     */
    static Date Parse(const String & value, Format format = DEFAULT, const TimeZone & timezone = TimeZone::GetEmpty());

    /**
     * Check that Date is empty.
     *
     * @return         True if Date is empty, otherwise false
     */
    bool Empty() const override;

    /**
     * Clear Date
     */
    void Clear() override;

    /**
     * Get time zone of date.
     *
     * @return         TimeZone
     *
     * @deprecated Deprecated in 2.11.2
     */
    [[deprecated(DEPRECATE_LINK)]] TimeZone GetTimeZone() const;

    /**
     * %Set time zone.
     *
     * %Time zone identifier is changed,
     * date part of object isn't changed.
     *
     * @param          New TimeZone
     *
     * @deprecated Deprecated in 2.11.2
     */
    [[deprecated(DEPRECATE_LINK)]] void SetTimeZone(const TimeZone & timezone);

    /**
     * Get CalendarDate from Date.
     *
     * @return         CalendarDate
     */
    CalendarDate GetCalendarDate() const;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_DATE; }

    Duration Difference(const Date & date) const;

    String ToString() const override;
    String ToString(bool timezone) const;
    DateTime ToDateTime() const;

    size_t GetHash() const override;

    Duration operator-(const Date & date) const;

    Date & operator+=(const Duration & duration);
    Date operator+(const Duration & duration) const;

    Date & operator-=(const Duration & duration);
    Date operator-(const Duration & duration) const;

    /**
     * Compare two dates.
     *
     * Comparison doesn't take in account time zone
     *
     * @code
     * // Same Dates in difference timezone
     * std::cout << (date_msk == date_cet ? "true  " : "false ")
     *           << date_msk << " == " << date_cet << std::endl;
     *
     * // Different dates in same timezone.
     * std::cout << (date_msk == another_date_msk ? "true  " : "false ")
     *           << date_msk << " == " << another_date_msk << std::endl;
     *
     * // Output:
     * // true  2100-10-14 MSK == 2100-10-14 CEST
     * // false 2100-10-14 MSK == 2100-10-15 MSK
     * @endcode
     */
    bool operator==(const Date & date) const;

    /**
     * Compare two dates.
     *
     * Comparison doesn't take in account time zone
     *
     * See operator==
     */
    bool operator!=(const Date & date) const;

    /**
     * Compare two dates.
     *
     * Comparison doesn't take in account time zone
     *
     * @return True if left operand has value of days, months, years
     * less then right operand, false otherwise.
     */
    bool operator<(const Date & date) const;

    /**
     * Compare two dates.
     *
     * Comparison doesn't take in account time zone
     *
     * @return True if left operand has value of days, months, years
     * less or equel then right operand, false otherwise.
     */
    bool operator<=(const Date & date) const;

    /**
     * Compare two dates.
     *
     * Comparison doesn't take in account time zone
     *
     * @return True if left operand has value of days, months, years
     * more then right operand, false otherwise.
     */
    bool operator>(const Date & date) const;

    /**
     * Compare two dates.
     *
     * Comparison doesn't take in account time zone
     *
     * @return True if left operand has value of days, months, years
     * more or equel then right operand, false otherwise.
     */
    bool operator>=(const Date & date) const;

    STRATEGY_EXPORT friend Date operator+(const Duration & duration, const Date & date);

    std::ostream & Print(std::ostream & strm) const override;

public:
    Date(const types::Date & date);
    tbricks::types::Date GetDate() const;

private:
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;
    friend class DateTime;
    friend class FIX::Group;
    friend class FIX::MessageBuilder;
    friend class ReferenceExchangeRateByDateFilter;
    friend class ReferencePriceByDateFilter;

    uint16_t m_days;
    uint16_t m_tz_id;
};

} // \namespace tbricks

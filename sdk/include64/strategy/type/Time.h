#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Time type, represents day time
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/type/String.h"
#include "strategy/type/Integer.h"
#include "strategy/type/Duration.h"
#include "strategy/type/TimeZone.h"

namespace tbricks {

namespace FIX {
class Group;
class MessageBuilder;
}
namespace types {
class Time;
}

class STRATEGY_EXPORT Time : public TypeWithError
{
public:
    enum Format
    {
        DEFAULT,       /**< %H:%M:%S.FFFF   */
        WITH_TIMEZONE, /**< %H:%M:%S.FFFF  <timezone>*/
        FIX            /**< HH:MM:SS FIX protocol date format */
    };

    Time();
    Time(const Time & time) = default;
    Time(Time && time) noexcept = default;
    ~Time() override = default;

    Time & operator=(const Time & time) = default;
    Time & operator=(Time && time) noexcept = default;

    static Time Now(const TimeZone & timezone = TimeZone::GetLocal());

    static Time Create(int hour, int minute, int second, int microsec = 0, const TimeZone & timezone = TimeZone::GetLocal());

    static Time Parse(const String & value, Format format = DEFAULT, const TimeZone & timezone = TimeZone::GetUTC());

    bool Empty() const override;
    void Clear() override;

    TimeZone GetTimeZone() const;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_TIME; }

    Duration Difference(const Time & time) const;

    void GetTime(int & hour, int & minute, int & second, int & usec) const;
    int GetHour() const;
    int GetMinute() const;
    int GetSecond() const;
    int GetMicrosecond() const;

    String ToString() const override;

    size_t GetHash() const override;

    Time & operator+=(const Duration & duration);
    Time operator+(const Duration & duration) const;

    Time & operator-=(const Duration & duration);
    Time operator-(const Duration & duration) const;

    Duration operator-(const Time & time) const;

    bool operator==(const Time & time) const;
    bool operator!=(const Time & time) const;

    bool operator<(const Time & time) const;
    bool operator<=(const Time & time) const;
    bool operator>(const Time & time) const;
    bool operator>=(const Time & time) const;

    friend STRATEGY_EXPORT Time operator+(const Duration & duration, const Time & time);

    std::ostream & Print(std::ostream & strm) const override;

public:
    Time(const tbricks::types::Time & time);
    tbricks::types::Time GetTime() const;

private:
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

    friend class DateTime;
    friend class FIX::Group;
    friend class FIX::MessageBuilder;

    int64_t m_duration;
    uint16_t m_tz_id;
};
}

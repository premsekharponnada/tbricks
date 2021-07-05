#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Time duration, represents relative time fractions unlike to absolute
// timestamps provided by DateTime class.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/type/Integer.h"
#include "strategy/type/Double.h"

// \namespace tbricks
namespace tbricks {

namespace types {
class Duration;
}

class STRATEGY_EXPORT Duration : public AnyType
{
public:
    Duration();
    Duration(const Double & seconds);
    Duration(const Duration & duration);
    ~Duration() override;

    Duration & operator=(const Duration & duration);

    bool Empty() const override { return m_value == 0; }
    void Clear();
    Double GetDouble() const;
    void SetDouble(const Double & value);

    void SetMicroseconds(uint64_t ms);
    uint64_t GetMicroseconds() const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_DURATION; }

    bool operator>(const Duration & duration) const;
    bool operator>=(const Duration & duration) const;
    bool operator<(const Duration & duration) const;
    bool operator<=(const Duration & duration) const;

    bool operator==(const Duration & duration) const;
    bool operator!=(const Duration & duration) const;

    Duration & operator+=(const Duration & duration);
    Duration & operator-=(const Duration & duration);

    Duration & operator*=(const Double & value);
    Duration & operator*=(const Integer & value);
    Duration & operator*=(double value);
    Duration & operator*=(int value);

    Duration & operator/=(const Double & value);
    Duration & operator/=(const Integer & value);
    Duration & operator/=(double value);
    Duration & operator/=(int value);

    friend STRATEGY_EXPORT Duration operator+(const Duration & first, const Duration & second);
    friend STRATEGY_EXPORT Duration operator-(const Duration & first, const Duration & second);
    friend STRATEGY_EXPORT Duration operator*(const Duration & duration, const Double & value);
    friend STRATEGY_EXPORT Duration operator*(const Duration & duration, const Integer & value);
    friend STRATEGY_EXPORT Duration operator*(const Duration & duration, double value);
    friend STRATEGY_EXPORT Duration operator*(const Duration & duration, int value);
    friend STRATEGY_EXPORT Duration operator/(const Duration & duration, const Double & value);
    friend STRATEGY_EXPORT Duration operator/(const Duration & duration, const Integer & value);
    friend STRATEGY_EXPORT Duration operator/(const Duration & duration, double value);
    friend STRATEGY_EXPORT Duration operator/(const Duration & duration, int value);
    friend STRATEGY_EXPORT Double operator/(const Duration & left, const Duration & right);

    static Duration Microseconds(int64_t usec);
    static Duration Milliseconds(int64_t ms);
    static Duration Seconds(int64_t seconds);
    static Duration Minutes(int64_t minutes);
    static Duration Hours(int64_t hours);
    static Duration Days(int64_t days);
    static Duration Weeks(int64_t weeks);

private:
    friend STRATEGY_EXPORT class Converter;

    void GetDuration(types::Duration & value) const;

    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

    friend class Time;
    friend class DateTime;
    friend class Date;

    double m_value;
};

} // \namespace tbricks

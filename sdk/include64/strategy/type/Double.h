#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Double type.
//****************************************************************************************

#include "strategy/type/TypeWithError.h"

namespace tbricks {

class STRATEGY_EXPORT Double : public TypeWithError
{
public:
    Double() : m_empty(true), m_value(0.0) {}
    Double(double value) : m_empty(false), m_value(value) {}
    Double(const Double & value) = default;
    Double(Double && value) noexcept = default;

    Double & operator=(double value)
    {
        ClearError();
        m_empty = false;
        m_value = value;
        return *this;
    }

    Double & operator=(const Double & value) = default;
    Double & operator=(Double && value) noexcept = default;

    bool Empty() const override { return m_empty; }
    void Clear() override
    {
        ClearError();
        m_empty = true;
        m_value = 0.0;
    }

    double GetDouble() const { return m_value; }

    Double Round(size_t number_of_decimals) const;
    Double Abs() const
    {
        check_empty();
        if (m_value < 0.0)
            return -m_value;
        return *this;
    }

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_DOUBLE; }

    operator double() const
    {
        check_empty();
        return m_value;
    }

    size_t GetHash() const override;

public:
    bool operator==(const Double & value) const { return (m_value == value.m_value) && (m_empty == value.m_empty) && TypeWithError::equal(value); }
    bool operator!=(const Double & value) const { return !operator==(value); }

    bool operator<(const Double & value) const { return (m_value < value.m_value) || (m_empty && !value.m_empty); }
    bool operator>(const Double & value) const { return value < *this; }

    bool operator<=(const Double & value) const { return !(value < *this); }
    bool operator>=(const Double & value) const { return !operator<(value); }

    Double operator+(const Double & value) const
    {
        check_empty();
        value.check_empty();
        return m_value + value.m_value;
    }
    Double operator-(const Double & value) const
    {
        check_empty();
        value.check_empty();
        return m_value - value.m_value;
    }
    Double operator*(const Double & value) const
    {
        check_empty();
        value.check_empty();
        return m_value * value.m_value;
    }
    Double operator/(const Double & value) const
    {
        check_empty();
        value.check_empty();
        return m_value / value.m_value;
    }

    Double & operator+=(const Double & value)
    {
        check_empty();
        value.check_empty();
        m_value += value.m_value;
        return *this;
    }
    Double & operator-=(const Double & value)
    {
        check_empty();
        value.check_empty();
        m_value -= value.m_value;
        return *this;
    }
    Double & operator*=(const Double & value)
    {
        check_empty();
        value.check_empty();
        m_value *= value.m_value;
        return *this;
    }
    Double & operator/=(const Double & value)
    {
        check_empty();
        value.check_empty();
        m_value /= value.m_value;
        return *this;
    }

    /// Set value if Double is empty. Example: Double v; v.Add(17); => v = 17;
    Double & Add(const Double & value)
    {
        value.check_empty();
        m_value += value.m_value;
        m_empty = false;
        return *this;
    }
    /// Do nothing if Double is empty. Example: Double v; v.Multiply(17); => v = <empty>;
    Double & Multiply(const Double & value)
    {
        value.check_empty();
        if (!m_empty) {
            m_value *= value.m_value;
        }
        return *this;
    }

    Double & operator--()
    {
        check_empty();
        --m_value;
        return *this;
    }
    Double operator--(int)
    {
        Double d(*this);
        --*this;
        return d;
    }
    Double & operator++()
    {
        check_empty();
        ++m_value;
        return *this;
    }
    Double operator++(int)
    {
        Double d(*this);
        ++*this;
        return d;
    }

    Double operator-() const
    {
        check_empty();
        return -m_value;
    }

public:
    bool operator==(double value) const { return (m_value == value) && !m_empty; }
    bool operator!=(double value) const { return !operator==(value); }

    bool operator<(double value) const { return (m_value < value) || (m_empty); }
    bool operator>(double value) const { return (m_value > value) && (!m_empty); }

    bool operator<=(double value) const { return (m_value <= value) || (m_empty); }
    bool operator>=(double value) const { return !operator<(value); }

    Double operator+(double value) const
    {
        check_empty();
        return m_value + value;
    }
    Double operator-(double value) const
    {
        check_empty();
        return m_value - value;
    }
    Double operator*(double value) const
    {
        check_empty();
        return m_value * value;
    }
    Double operator/(double value) const
    {
        check_empty();
        return m_value / value;
    }

    Double & operator+=(double value)
    {
        check_empty();
        m_value += value;
        return *this;
    }
    Double & operator-=(double value)
    {
        check_empty();
        m_value -= value;
        return *this;
    }
    Double & operator*=(double value)
    {
        check_empty();
        m_value *= value;
        return *this;
    }
    Double & operator/=(double value)
    {
        check_empty();
        m_value /= value;
        return *this;
    }

    /// Set value if Double is empty. Example: Double v; v.Add(17); => v = 17;
    Double & Add(double value)
    {
        m_value += value;
        m_empty = false;
        return *this;
    }
    /// Do nothing if Double is empty. Example: Double v; v.Multiply(17); => v = <empty>;
    Double & Multiply(double value)
    {
        if (!m_empty) {
            m_value *= value;
        }
        return *this;
    }

public:
    bool operator==(int value) const { return *this == (double)value; }
    bool operator!=(int value) const { return *this != (double)value; }

    bool operator<(int value) const { return operator<((double)value); }
    bool operator>(int value) const { return operator>((double)value); }

    bool operator<=(int value) const { return operator<=((double)value); }
    bool operator>=(int value) const { return operator>=((double)value); }

    Double operator+(int value) const
    {
        check_empty();
        return m_value + value;
    }
    Double operator-(int value) const
    {
        check_empty();
        return m_value - value;
    }
    Double operator*(int value) const
    {
        check_empty();
        return m_value * value;
    }
    Double operator/(int value) const
    {
        check_empty();
        return m_value / value;
    }

    Double & operator+=(int value)
    {
        check_empty();
        m_value += value;
        return *this;
    }
    Double & operator-=(int value)
    {
        check_empty();
        m_value -= value;
        return *this;
    }
    Double & operator*=(int value)
    {
        check_empty();
        m_value *= value;
        return *this;
    }
    Double & operator/=(int value)
    {
        check_empty();
        m_value /= value;
        return *this;
    }

    /// Set value if Double is empty. Example: Double v; v.Add(17); => v = 17;
    Double & Add(int value)
    {
        m_value += value;
        m_empty = false;
        return *this;
    }
    /// Do nothing if Double is empty. Example: Double v; v.Multiply(17); => v = <empty>;
    Double & Multiply(int value)
    {
        if (!m_empty) {
            m_value *= value;
        }
        return *this;
    }

    /** Find min Double.
     *
     * If values vector is empty, return empty Double.
     */
    static Double Min(const std::vector<Double> & values);

    /** Find max Double.
     *
     * If values vector is empty, return empty Double.
     */
    static Double Max(const std::vector<Double> & values);

    static const Double & Min(const Double & d1, const Double & d2);
    static const Double & Max(const Double & d1, const Double & d2);

protected:
    void check_empty() const
    {
        if (m_empty) {
            throw_exception();
        }
    }

    void throw_exception() const;

    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

protected:
    bool m_empty;
    double m_value;
};

inline bool operator==(double v1, const Double & v2)
{
    return v2 == v1;
}
inline bool operator!=(double v1, const Double & v2)
{
    return v2 != v1;
}
inline bool operator<(double v1, const Double & v2)
{
    return v2 > v1;
}
inline bool operator>(double v1, const Double & v2)
{
    return v2 < v1;
}
inline bool operator<=(double v1, const Double & v2)
{
    return v2 >= v1;
}
inline bool operator>=(double v1, const Double & v2)
{
    return v2 <= v1;
}
}

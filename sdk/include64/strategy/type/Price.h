#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Price type.
//****************************************************************************************

#include "strategy/type/Double.h"

#include <optional>

namespace tbricks {

class Side;

class STRATEGY_EXPORT Price : public TypeWithError
{
public:
    Price() : m_empty(true), m_value(0) {}

    Price(double value) : m_empty(false), m_value(value) {}
    Price(std::optional<double> value) : m_empty(!value), m_value(value.value_or(0)) {}

    Price(const Price & value) = default;
    Price(Price && value) noexcept = default;

    ~Price() override = default;

    Price(const Double & value) : TypeWithError(value)
    {
        m_empty = value.Empty();
        if (!m_empty) {
            m_value = value;
        } else {
            m_value = 0.0;
        }
    }

    Price & operator=(double value)
    {
        ClearError();
        m_empty = false;
        m_value = value;
        return *this;
    }

    Price & operator=(const Price & value) = default;
    Price & operator=(Price && value) noexcept = default;

    /**
     * @return     true if Price is empty, false otherwise
     */
    bool Empty() const override { return m_empty; }

    /**
     * Reset object to empty state
     */
    void Clear() override
    {
        ClearError();
        m_empty = true;
        m_value = 0;
    }

    /**
     * Convert Price to double
     * @return      double value if price is not empty
     * @throw       EmptyValueException if ErrorProcessingType is EP_EXCEPTION or undefined
     */
    double GetDouble() const
    {
        if (TB_UNLIKELY(m_empty)) {
            throw_exception();
        }
        return m_value;
    }

    /**
     * Convert Price to optional double
     * @return       double value if price is not empty
     *               empty otherwise
     */
    std::optional<double> GetDoubleValue() const
    {
        if (!Empty()) {
            return m_value;
        }
        return std::nullopt;
    }

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_PRICE; }

    /**
     * Convert Price to double
     * @return      double value if price is not empty
     * @throw       EmptyValueException if ErrorProcessingType is EP_EXCEPTION or undefined
     */
    operator double() const
    {
        if (TB_UNLIKELY(m_empty)) {
            throw_exception();
        }
        return m_value;
    }

public:
    /**
     * Round to the smallest integer that is not less than current value
     *
     * @param number_of_decimals        Precision
     *
     * @return                          Rounded price
     */
    Price RoundUp(size_t number_of_decimals = 0) const;

    /**
     * Round to the largest integer that does not exceed current value
     *
     * @param number_of_decimals        Precision
     *
     * @return                          Rounded price
     */
    Price RoundDown(size_t number_of_decimals = 0) const;

    /**
     * Regardless of side fair rounding is defined as
     *  a. <0.5 -> 0.0 (downwards)
     *  b. ≥0.5 -> 1.0 (upwards)
     *
     * @param number_of_decimals        Precision
     *
     * @return                          Rounded price
     */
    Price RoundFair(size_t number_of_decimals = 0) const;

    /**
     * Market rounding is always done in the venues favor, i.e. Buy down, Sell up
     *
     * @param side                      Side
     * @param number_of_decimals        Precision
     *
     * @return                          Rounded price
     */
    Price RoundMarket(const Side & side, size_t number_of_decimals = 0) const;

    /**
     * Bank rounding is defined as in IEEE 754
     *
     * @param number_of_decimals        Precision
     *
     * @return                          Rounded price
     */
    Price RoundBank(size_t number_of_decimals = 0) const;

public:
    bool operator==(const Price & value) const
    {
        if (!TypeWithError::equal(value)) {
            return false;
        }
        if (m_empty != value.m_empty)
            return false;
        if (m_empty)
            return true;
        return (m_value == value.m_value);
    }

    bool operator!=(const Price & value) const { return !operator==(value); }

    bool operator<(const Price & value) const
    {
        if (!m_empty) {
            if (!value.m_empty) {
                return m_value < value.m_value;
            } else {
                return false;
            }
        } else {
            if (!value.m_empty) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool operator>(const Price & value) const
    {
        if (!m_empty) {
            if (!value.m_empty) {
                return m_value > value.m_value;
            } else {
                return true;
            }
        } else {
            if (!value.m_empty) {
                return false;
            } else {
                return false;
            }
        }
    }

    bool operator<=(const Price & value) const { return !operator>(value); }

    bool operator>=(const Price & value) const { return !operator<(value); }

    Price operator+(const Price & value) const
    {
        if (!m_empty) {
            if (!value.m_empty) {
                return m_value + value.m_value;
            } else {
                return *this;
            }
        } else {
            if (!value.m_empty) {
                return value;
            } else {
                return Price();
            }
        }
    }

    Price operator-(const Price & value) const
    {
        if (!m_empty) {
            if (!value.m_empty) {
                return m_value - value.m_value;
            } else {
                return *this;
            }
        } else {
            if (!value.m_empty) {
                return -value.m_value;
            } else {
                return Price();
            }
        }
    }

    Price operator*(const Price & value) const
    {
        if (!m_empty && !value.m_empty) {
            return m_value * value.m_value;
        }
        return Price();
    }

    Price operator/(const Price & value) const
    {
        if (!m_empty && !value.m_empty) {
            return m_value / value.m_value;
        }
        return Price();
    }

    Price & operator+=(const Price & value)
    {
        if (!m_empty) {
            if (!value.m_empty) {
                m_value += value.m_value;
            }
        } else {
            if (!value.m_empty) {
                ClearError();
                m_empty = false;
                m_value = value.m_value;
            }
        }
        return *this;
    }

    Price & operator-=(const Price & value)
    {
        if (!m_empty) {
            if (!value.m_empty) {
                m_value -= value.m_value;
            }
        } else {
            if (!value.m_empty) {
                ClearError();
                m_empty = false;
                m_value = -value.m_value;
            }
        }
        return *this;
    }

    Price & operator*=(const Price & value)
    {
        if (!m_empty) {
            if (!value.m_empty) {
                m_value *= value.m_value;
            } else {
                m_empty = true;
            }
        }
        return *this;
    }

    Price & operator/=(const Price & value)
    {
        if (!m_empty) {
            if (!value.m_empty) {
                m_value /= value.m_value;
            } else {
                m_empty = true;
            }
        }
        return *this;
    }

    Price & operator--()
    {
        if (!m_empty) {
            m_value--;
        }
        return *this;
    }

    Price operator--(int)
    {
        Price d(*this);
        --*this;
        return d;
    }

    Price & operator++()
    {
        if (!m_empty) {
            m_value++;
        }
        return *this;
    }

    Price operator++(int)
    {
        Price d(*this);
        ++*this;
        return d;
    }

    Price operator-() const
    {
        Price d(*this);
        d.m_value = -d.m_value;
        return d;
    }

public:
    bool operator==(const Double & value) const
    {
        if (!TypeWithError::equal(value)) {
            return false;
        }
        if (m_empty != value.Empty())
            return false;
        if (m_empty)
            return true;
        return (m_value == value.GetDouble());
    }

    bool operator!=(const Double & value) const { return !operator==(value); }

    bool operator<(const Double & value) const
    {
        if (!m_empty) {
            if (!value.Empty()) {
                return m_value < value.GetDouble();
            } else {
                return false;
            }
        } else {
            if (!value.Empty()) {
                return true;
            } else {
                return false;
            }
        }
    }

    bool operator>(const Double & value) const
    {
        if (!m_empty) {
            if (!value.Empty()) {
                return m_value > value.GetDouble();
            } else {
                return true;
            }
        } else {
            if (!value.Empty()) {
                return false;
            } else {
                return false;
            }
        }
    }

    bool operator<=(const Double & value) const { return !operator>(value); }

    bool operator>=(const Double & value) const { return !operator<(value); }

    Price operator+(const Double & value) const
    {
        if (!m_empty) {
            if (!value.Empty()) {
                return m_value + value.GetDouble();
            } else {
                return value.GetDouble();
            }
        } else {
            if (!value.Empty()) {
                return value;
            } else {
                return Price();
            }
        }
    }

    Price operator-(const Double & value) const
    {
        if (!m_empty) {
            if (!value.Empty()) {
                return m_value - value.GetDouble();
            } else {
                return *this;
            }
        } else {
            if (!value.Empty()) {
                return -value.GetDouble();
            } else {
                return Price();
            }
        }
    }

    Price operator*(const Double & value) const
    {
        if (!m_empty && !value.Empty()) {
            return m_value * value.GetDouble();
        }
        return Price();
    }

    Price operator/(const Double & value) const
    {
        if (!m_empty && !value.Empty()) {
            return m_value / value.GetDouble();
        }
        return Price();
    }

    Price & operator+=(const Double & value)
    {
        if (!m_empty) {
            if (!value.Empty()) {
                m_value += value.GetDouble();
            }
        } else {
            if (!value.Empty()) {
                ClearError();
                m_empty = false;
                m_value = value.GetDouble();
            }
        }
        return *this;
    }

    Price & operator-=(const Double & value)
    {
        if (!m_empty) {
            if (!value.Empty()) {
                m_value -= value.GetDouble();
            }
        } else {
            if (!value.Empty()) {
                ClearError();
                m_empty = false;
                m_value = -value.GetDouble();
            }
        }
        return *this;
    }

    Price & operator*=(const Double & value)
    {
        if (!m_empty) {
            if (!value.Empty()) {
                m_value *= value.GetDouble();
            } else {
                m_empty = true;
            }
        }
        return *this;
    }

    Price & operator/=(const Double & value)
    {
        if (!m_empty) {
            if (!value.Empty()) {
                m_value /= value.GetDouble();
            } else {
                m_empty = true;
            }
        }
        return *this;
    }

public:
    bool operator==(double value) const
    {
        if (m_empty) {
            return false;
        }
        return (m_value == value);
    }

    bool operator!=(double value) const { return !operator==(value); }

    bool operator<(double value) const
    {
        if (m_empty) {
            return true;
        }
        return m_value < value;
    }

    bool operator>(double value) const
    {
        if (m_empty) {
            return false;
        }
        return m_value > value;
    }

    bool operator<=(double value) const { return !operator>(value); }

    bool operator>=(double value) const { return !operator<(value); }

    Price operator+(double value) const
    {
        if (!m_empty) {
            return (m_value + value);
        }
        return value;
    }

    Price operator-(double value) const
    {
        if (!m_empty) {
            return (m_value - value);
        }
        return -value;
    }

    Price operator*(double value) const
    {
        if (!m_empty) {
            return (m_value * value);
        }
        return Price();
    }

    Price operator/(double value) const
    {
        if (!m_empty) {
            return (m_value / value);
        }
        return Price();
    }

    Price & operator+=(double value)
    {
        if (!m_empty) {
            m_value += value;
        } else {
            m_empty = false;
            m_value = value;
        }
        return *this;
    }

    Price & operator-=(double value)
    {
        if (!m_empty) {
            m_value -= value;
        } else {
            m_empty = false;
            m_value = -value;
        }
        return *this;
    }

    Price & operator*=(double value)
    {
        if (!m_empty) {
            m_value *= value;
        }
        return *this;
    }

    Price & operator/=(double value)
    {
        if (!m_empty) {
            m_value /= value;
        }
        return *this;
    }

public:
    bool operator==(int value) const { return (*this == (double)value); }

    bool operator!=(int value) const { return (*this != (double)value); }

    bool operator<(int value) const { return (*this < (double)value); }

    bool operator>(int value) const { return (*this > (double)value); }

    bool operator<=(int value) const { return (*this <= (double)value); }

    bool operator>=(int value) const { return (*this >= (double)value); }

    Price operator+(int value) const { return (*this + (double)value); }

    Price operator-(int value) const { return (*this - (double)value); }

    Price operator*(int value) const { return (*this * (double)value); }

    Price operator/(int value) const { return (*this / (double)value); }

    Price & operator+=(int value) { return (*this += (double)value); }

    Price & operator-=(int value) { return (*this -= (double)value); }

    Price & operator*=(int value) { return (*this *= (double)value); }

    Price & operator/=(int value) { return (*this /= (double)value); }

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

    void throw_exception() const;

private:
    bool m_empty;
    double m_value;
};

STRATEGY_EXPORT inline bool operator==(double v1, const Price & v2);
STRATEGY_EXPORT inline bool operator!=(double v1, const Price & v2);
STRATEGY_EXPORT inline bool operator<(double v1, const Price & v2);
STRATEGY_EXPORT inline bool operator>(double v1, const Price & v2);
STRATEGY_EXPORT inline bool operator<=(double v1, const Price & v2);
STRATEGY_EXPORT inline bool operator>=(double v1, const Price & v2);

inline bool operator==(double v1, const Price & v2)
{
    return v2 == v1;
}

inline bool operator!=(double v1, const Price & v2)
{
    return v2 != v1;
}

inline bool operator<(double v1, const Price & v2)
{
    return v2 > v1;
}

inline bool operator>(double v1, const Price & v2)
{
    return v2 < v1;
}

inline bool operator<=(double v1, const Price & v2)
{
    return v2 >= v1;
}

inline bool operator>=(double v1, const Price & v2)
{
    return v2 <= v1;
}
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Volume type.
//****************************************************************************************

#include "strategy/type/Double.h"

#include <optional>

namespace tbricks {

class STRATEGY_EXPORT Volume : public TypeWithError
{
public:
    enum ValueType
    {
        EMPTY = 0,
        TOTAL = 1,
        DELTA = 2
    };

public:
    Volume() : m_type(EMPTY), m_value(0.0) {}
    Volume(std::optional<double> value) : m_type(value ? TOTAL : EMPTY), m_value(value.value_or(0)) {}
    Volume(double value, ValueType type = TOTAL) : m_type(type), m_value(value) {}
    Volume(const Volume & value) = default;
    Volume(Volume && value) noexcept = default;
    Volume(const Double & value) : TypeWithError(value)
    {
        if (value.Empty()) {
            m_type = EMPTY;
            m_value = 0;
        } else {
            m_type = TOTAL;
            m_value = value.GetDouble();
        }
    }

    Volume & operator=(double value)
    {
        ClearError();
        m_type = TOTAL;
        m_value = value;
        return *this;
    }

    Volume & operator=(const Volume & value) = default;
    Volume & operator=(Volume && value) noexcept = default;

    /**
     * @return     true if ValueType is EMPTY, false otherwise
     */
    bool Empty() const override { return (m_type == EMPTY); }

    /**
     * Reset object to empty state
     */
    void Clear() override
    {
        ClearError();
        m_type = EMPTY;
        m_value = 0;
    }

    /**
     * Convert Volume to double
     * @return      double value if type of volume is TOTAL or DELTA
     * @throw       EmptyValueException if ErrorProcessingType is EP_EXCEPTION or undefined
     */
    double GetDouble() const
    {
        if (TB_UNLIKELY(Empty())) {
            throw_exception();
        }
        return m_value;
    }

    /**
     * Convert Volume to optional double
     * @return       not empty value if type of volume is TOTAL or DELTA,
     *               empty optional otherwise
     */
    std::optional<double> GetDoubleValue() const
    {
        if (!Empty()) {
            return m_value;
        }
        return std::nullopt;
    }

    /**
     * %Set value
     * If object is empty, it sets TOTAL type
     * It does not change type if type is DELTA
     * @param value   new value
     */
    void SetDouble(double value)
    {
        if (m_type == EMPTY) {
            ClearError();
            m_type = TOTAL;
        }
        m_value = value;
    }

    Volume Abs() const
    {
        if (!Empty() && m_value < 0) {
            return Volume(-m_value);
        }
        return *this;
    }

    ValueType GetType() const { return m_type; }

    void SetType(ValueType type) { m_type = type; }

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_VOLUME; }

    /**
     * Convert Volume to double
     * @return      double value if type of volume is TOTAL or DELTA
     * @throw       EmptyValueException if ErrorProcessingType is EP_EXCEPTION or undefined
     */
    operator double() const
    {
        if (TB_UNLIKELY(Empty())) {
            throw_exception();
        }
        return m_value;
    }

    /**
     * Convert Volume to tbricks::Double
     * @return       not empty Double if type of volume is TOTAL or DELTA,
     *               empty Double otherwise
     */
    Double ToDouble() const { return (Empty() ? Double() : Double(m_value)); }

    void Merge(const Volume & value)
    {
        switch (m_type) {
        case EMPTY:
            operator=(value);
            break;
        case TOTAL:
            switch (value.m_type) {
            case EMPTY:
                Clear();
                break;
            case TOTAL:
                m_value = value.m_value;
                break;
            case DELTA:
                m_value += value.m_value;
                break;
            }
            break;
        case DELTA:
            switch (value.m_type) {
            case EMPTY:
                Clear();
                break;
            case TOTAL:
                m_value = value.m_value;
                m_type = TOTAL;
                break;
            case DELTA:
                m_value += value.m_value;
                break;
            }
            break;
        }
    }

    static Volume Delta(const Volume & from, const Volume & to);

public:
    bool operator==(const Volume & value) const
    {
        if (!TypeWithError::equal(value)) {
            return false;
        }
        if (m_type == value.m_type) {
            return (m_value == value.m_value);
        }
        return false;
    }

    bool operator!=(const Volume & value) const { return !operator==(value); }

    bool operator<(const Volume & value) const
    {
        if ((m_type == EMPTY) || (value.m_type == EMPTY)) {
            return (m_value < value.m_value);
        }
        return (m_type < value.m_type) || ((m_type == value.m_type) && (m_value < value.m_value));
    }

    bool operator>(const Volume & value) const { return (value < *this); }

    bool operator<=(const Volume & value) const { return !operator>(value); }

    bool operator>=(const Volume & value) const { return !operator<(value); }

    Volume operator+(const Volume & value) const
    {
        Volume v(*this);
        return (v += value);
    }

    Volume operator-(const Volume & value) const
    {
        Volume v(*this);
        return v -= value;
    }

    Volume operator*(const Volume & value) const
    {
        Volume v(*this);
        return v *= value;
    }

    Volume operator/(const Volume & value) const
    {
        Volume v(*this);
        return v /= value;
    }

    Volume & operator+=(const Volume & value)
    {
        if (m_type == value.m_type) {
            m_value += value.m_value;
        } else {
            switch (m_type) {
            case EMPTY:
                operator=(value);
                break;
            case TOTAL:
                switch (value.m_type) {
                case EMPTY:
                    break;
                case TOTAL:
                    break;
                case DELTA:
                    m_value += value.m_value;
                    break;
                }
                break;
            case DELTA:
                switch (value.m_type) {
                case EMPTY:
                    break;
                case TOTAL:
                    m_type = TOTAL;
                    break;
                case DELTA:
                    break;
                }
                break;
            }
        }
        return *this;
    }

    Volume & operator-=(const Volume & value)
    {
        Volume v(-value.m_value, value.m_type);
        return operator+=(v);
    }

    Volume & operator*=(const Volume & value)
    {
        if (m_type == value.m_type) {
            m_value *= value.m_value;
        }
        return *this;
    }

    Volume & operator/=(const Volume & value)
    {
        if (m_type == value.m_type) {
            m_value /= value.m_value;
        }
        return *this;
    }

    Volume & operator--()
    {
        m_value--;
        return *this;
    }

    Volume operator--(int)
    {
        Volume d(*this);
        operator--();
        return d;
    }

    Volume & operator++()
    {
        m_value++;
        return *this;
    }

    Volume operator++(int)
    {
        Volume d(*this);
        operator++();
        return d;
    }

    Volume operator-() const
    {
        Volume d(*this);
        d.m_value = -d.m_value;
        return d;
    }

public:
    bool operator==(const Double & value) const
    {
        Volume v(value);
        return operator==(v);
    }

    bool operator!=(const Double & value) const { return !operator==(value); }

    bool operator<(const Double & value) const
    {
        Volume v(value);
        return operator<(v);
    }

    bool operator>(const Double & value) const
    {
        Volume v(value);
        return operator>(v);
    }

    bool operator<=(const Double & value) const { return !operator>(value); }

    bool operator>=(const Double & value) const { return !operator<(value); }

    Volume operator+(const Double & value) const
    {
        Volume v(value);
        return operator+(v);
    }

    Volume operator-(const Double & value) const
    {
        Volume v(value);
        return operator-(v);
    }

    Volume operator*(const Double & value) const
    {
        Volume v(value);
        return operator*(v);
    }

    Volume operator/(const Double & value) const
    {
        Volume v(value);
        return operator/(v);
    }

    Volume & operator+=(const Double & value)
    {
        Volume v(value);
        return operator+=(v);
    }

    Volume & operator-=(const Double & value)
    {
        Volume v(value);
        return operator-=(v);
    }

    Volume & operator*=(const Double & value)
    {
        Volume v(value);
        return operator*=(v);
    }

    Volume & operator/=(const Double & value)
    {
        Volume v(value);
        return operator/=(v);
    }

public:
    bool operator==(double value) const { return (m_type == TOTAL) && (m_value == value); }

    bool operator!=(double value) const { return !operator==(value); }

    bool operator<(double value) const { return operator<(Volume(value)); }

    bool operator>(double value) const { return operator>(Volume(value)); }

    bool operator<=(double value) const { return operator<=(Volume(value)); }

    bool operator>=(double value) const { return operator>=(Volume(value)); }

    Volume operator+(double value) const { return operator+(Volume(value)); }

    Volume operator-(double value) const { return operator-(Volume(value)); }

    Volume operator*(double value) const { return operator*(Volume(value)); }

    Volume operator/(double value) const { return operator/(Volume(value)); }

    Volume & operator+=(double value) { return operator+=(Volume(value)); }

    Volume & operator-=(double value) { return operator-=(Volume(value)); }

    Volume & operator*=(double value) { return operator*=(Volume(value)); }

    Volume & operator/=(double value) { return operator/=(Volume(value)); }

public:
    bool operator==(int value) const { return operator==((double)value); }

    bool operator!=(int value) const { return operator!=((double)value); }

    bool operator<(int value) const { return operator<((double)value); }

    bool operator>(int value) const { return operator>((double)value); }

    bool operator<=(int value) const { return operator<=((double)value); }

    bool operator>=(int value) const { return operator>=((double)value); }

    Volume operator+(int value) const { return (operator+((double)value)); }

    Volume operator-(int value) const { return (operator-((double)value)); }

    Volume operator*(int value) const { return operator*((double)value); }

    Volume operator/(int value) const { return operator/((double)value); }

    Volume & operator+=(int value) { return operator+=((double)value); }

    Volume & operator-=(int value) { return operator-=((double)value); }

    Volume & operator*=(int value) { return operator*=((double)value); }

    Volume & operator/=(int value) { return operator/=((double)value); }

    /** Find min Volume.
     *
     * If values vector is empty, return empty Volume.
     */
    static Volume Min(const std::vector<Volume> & values);

    /** Find max Volume.
     *
     * If values vector is empty, return empty Volume.
     */
    static Volume Max(const std::vector<Volume> & values);

    static const Volume & Min(const Volume & v1, const Volume & v2);
    static const Volume & Max(const Volume & v1, const Volume & v2);

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

    void throw_exception() const;

private:
    ValueType m_type;
    double m_value;
};

STRATEGY_EXPORT inline bool operator==(double v1, const Volume & v2);
STRATEGY_EXPORT inline bool operator!=(double v1, const Volume & v2);
STRATEGY_EXPORT inline bool operator<(double v1, const Volume & v2);
STRATEGY_EXPORT inline bool operator>(double v1, const Volume & v2);
STRATEGY_EXPORT inline bool operator<=(double v1, const Volume & v2);
STRATEGY_EXPORT inline bool operator>=(double v1, const Volume & v2);

inline bool operator==(double v1, const Volume & v2)
{
    return v2 == v1;
}

inline bool operator!=(double v1, const Volume & v2)
{
    return v2 != v1;
}

inline bool operator<(double v1, const Volume & v2)
{
    return v2 > v1;
}

inline bool operator>(double v1, const Volume & v2)
{
    return v2 < v1;
}

inline bool operator<=(double v1, const Volume & v2)
{
    return v2 >= v1;
}

inline bool operator>=(double v1, const Volume & v2)
{
    return v2 <= v1;
}
}

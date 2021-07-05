#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Integer type.
//****************************************************************************************

#include "strategy/type/TypeWithError.h"

namespace tbricks {

class STRATEGY_EXPORT Integer : public TypeWithError
{
public:
    Integer() : m_empty(true), m_value(0) {}
    Integer(int64_t value) : m_empty(false), m_value(value) {}
    Integer(const Integer & value) = default;
    Integer(Integer && value) noexcept = default;

    Integer & operator=(int64_t value)
    {
        ClearError();
        m_empty = false;
        m_value = value;
        return *this;
    }

    Integer & operator=(const Integer & value) = default;
    Integer & operator=(Integer && value) noexcept = default;

    bool Empty() const override { return m_empty; }

    void Clear() override
    {
        ClearError();
        m_empty = true;
        m_value = 0;
    }

    int64_t GetInt() const { return m_value; }
    int32_t GetInt32() const { return (int32_t)m_value; }
    size_t GetHash() const override { return (size_t)m_empty + (size_t)m_value; }

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_INTEGER; }

    Integer Abs() const
    {
        if (m_value < 0)
            return -m_value;
        return *this;
    }

public:
    bool operator==(const Integer & value) const
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

    bool operator!=(const Integer & value) const { return !operator==(value); }

    bool operator<(const Integer & value) const
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

    bool operator>(const Integer & value) const
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

    bool operator<=(const Integer & value) const { return !operator>(value); }
    bool operator>=(const Integer & value) const { return !operator<(value); }

    Integer operator+(const Integer & value) const
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
                return Integer();
            }
        }
    }

    Integer operator-(const Integer & value) const
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
                return Integer();
            }
        }
    }

    Integer operator*(const Integer & value) const
    {
        if (!m_empty && !value.m_empty) {
            return m_value * value.m_value;
        }
        return Integer();
    }

    Integer operator/(const Integer & value) const
    {
        if (!m_empty && !value.m_empty) {
            return m_value / value.m_value;
        }
        return Integer();
    }

    Integer operator%(const Integer & value) const
    {
        if (!m_empty && !value.m_empty) {
            return m_value % value.m_value;
        }
        return Integer();
    }

    Integer & operator+=(const Integer & value)
    {
        if (!m_empty) {
            if (!value.m_empty) {
                m_value += value.m_value;
            }
        } else {
            if (!value.m_empty) {
                Clear();
                m_empty = false;
                m_value = value.m_value;
            }
        }
        return *this;
    }

    Integer & operator-=(const Integer & value)
    {
        if (!m_empty) {
            if (!value.m_empty) {
                m_value -= value.m_value;
            }
        } else {
            if (!value.m_empty) {
                Clear();
                m_empty = false;
                m_value = -value.m_value;
            }
        }
        return *this;
    }

    Integer & operator*=(const Integer & value)
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

    Integer & operator/=(const Integer & value)
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

    Integer & operator%=(const Integer & value)
    {
        if (!m_empty) {
            if (!value.m_empty) {
                m_value %= value.m_value;
            } else {
                m_empty = true;
            }
        }
        return *this;
    }

    Integer & operator--()
    {
        if (!m_empty) {
            m_value--;
        }
        return *this;
    }

    Integer operator--(int)
    {
        Integer i(*this);
        --*this;
        return i;
    }

    Integer & operator++()
    {
        if (!m_empty) {
            m_value++;
        }
        return *this;
    }

    Integer operator++(int)
    {
        Integer i(*this);
        ++*this;
        return i;
    }

    Integer operator-() const
    {
        Integer i(*this);
        i.m_value = -i.m_value;
        return i;
    }

public:
    bool operator==(int64_t value) const
    {
        if (m_empty) {
            return false;
        }
        return (m_value == value);
    }

    bool operator!=(int64_t value) const { return !operator==(value); }

    bool operator<(int64_t value) const
    {
        if (m_empty) {
            return true;
        }
        return (m_value < value);
    }

    bool operator>(int64_t value) const
    {
        if (m_empty) {
            return false;
        }
        return (m_value > value);
    }

    bool operator<=(int64_t value) const { return !operator>(value); }

    bool operator>=(int64_t value) const { return !operator<(value); }

    Integer operator+(int64_t value) const
    {
        if (!m_empty) {
            return (m_value + value);
        }
        return value;
    }

    Integer operator-(int64_t value) const
    {
        if (!m_empty) {
            return (m_value - value);
        }
        return -value;
    }

    Integer operator*(int64_t value) const
    {
        if (!m_empty) {
            return (m_value * value);
        }
        return Integer();
    }

    Integer operator/(int64_t value) const
    {
        if (!m_empty) {
            return (m_value / value);
        }
        return Integer();
    }

    Integer operator%(int64_t value) const
    {
        if (!m_empty) {
            return (m_value % value);
        }
        return Integer();
    }

    Integer & operator+=(int64_t value)
    {
        if (!m_empty) {
            m_value += value;
        } else {
            Clear();
            m_empty = false;
            m_value = value;
        }
        return *this;
    }

    Integer & operator-=(int64_t value)
    {
        if (!m_empty) {
            m_value -= value;
        } else {
            Clear();
            m_empty = false;
            m_value = -value;
        }
        return *this;
    }

    Integer & operator*=(int64_t value)
    {
        if (!m_empty) {
            m_value *= value;
        }
        return *this;
    }

    Integer & operator/=(int64_t value)
    {
        if (!m_empty) {
            m_value /= value;
        }
        return *this;
    }

    Integer & operator%=(int64_t value)
    {
        if (!m_empty) {
            m_value %= value;
        }
        return *this;
    }

public:
    std::ostream & Print(std::ostream & strm) const override;
    String ToString() const override;

    /** Find min integer.
     *
     * If values vector is empty, return empty Integer.
     */
    static Integer Min(const std::vector<Integer> & values);

    /** Find max integer.
     *
     * If values vector is empty, return empty Integer.
     */
    static Integer Max(const std::vector<Integer> & values);

    static const Integer & Min(const Integer & i1, const Integer & i2);
    static const Integer & Max(const Integer & i1, const Integer & i2);

private:
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    bool m_empty;
    int64_t m_value;
};
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace std {

template <>
struct hash<tbricks::Integer>
{
    size_t operator()(const tbricks::Integer & data) const { return data.GetHash(); }
};
}

#endif // DOXYGEN_SHOULD_SKIP_THIS

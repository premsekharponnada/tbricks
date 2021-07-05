#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Value type.
//****************************************************************************************

#include <iostream>
#include "strategy/Printable.h"
#include "strategy/ComparisonResult.h"

// \namespace tbricks
namespace tbricks {

namespace {
template <typename Type>
std::ostream & operator<<(std::ostream & strm, const std::vector<Type> & v)
{
    if (v.empty()) {
        return strm << "<empty>";
    }
    long & nindent = strm.iword(0);
    std::string indent(nindent + 2, ' ');
    strm << "[" << v.size() << "]";
    nindent += 6;
    for (size_t i = 0; i < v.size(); ++i) {
        strm << '\n' << indent << i << " = " << v[i];
    }
    nindent -= 6;
    return strm;
}
}

template <typename Type>
class STRATEGY_EXPORT Value : public Printable
{
public:
    Value() : m_empty(true), m_value() {}

    Value(const Value & src) : m_empty(src.m_empty), m_value(src.m_value) {}

    Value(const Type & value) : m_empty(false), m_value(value) {}

    ~Value() override {}

    Value & operator=(const Value & src)
    {
        if (this != &src) {
            m_empty = src.m_empty;
            m_value = src.m_value;
        }
        return *this;
    }

    Value & operator=(const Type & value)
    {
        Set(value);
        return *this;
    }

    Value & operator+=(const Type & value)
    {
        if (m_empty) {
            m_empty = false;
            m_value = value;
        } else {
            m_value += value;
        }
        return *this;
    }

    operator const Type &() const { return m_value; }

    const Type * operator->() const { return &Get(); }

    Type * operator->() { return &Get(); }

    const Type & operator*() const { return Get(); }

    Type & operator*() { return Get(); }

public:
    bool operator==(const Type & value) const { return (!m_empty && (m_value == value)); }

    bool operator!=(const Type & value) const { return !operator==(value); }

    bool operator<(const Type & value) const { return (m_empty || (m_value < value)); }

    bool operator>(const Type & value) const { return value < *this; }

    bool operator<=(const Type & value) const { return !(value < *this); }

    bool operator>=(const Type & value) const { return !operator<(value); }

    bool operator==(const Value & src) const { return ((m_empty == src.m_empty && m_value == src.m_value) || (m_empty && src.m_empty)); }

    bool operator!=(const Value & src) const { return !operator==(src); }

    bool operator<(const Value & src) const
    {
        if (m_empty) {
            return !src.m_empty;
        }
        if (src.m_empty)
            return false;

        return (m_value < src.m_value);
    }

    bool operator>(const Value & src) const { return src < *this; }

    bool operator<=(const Value & src) const { return !(src < *this); }

    bool operator>=(const Value & src) const { return !operator<(src); }

    ComparisonResult Compare(const Value & src) const
    {
        if (m_empty) {
            if (src.m_empty) {
                return TB_EQUAL;
            } else {
                return TB_LESS_THAN;
            }
        }
        if (src.m_empty)
            return TB_GREATER_THAN;

        if (m_value < src.m_value) {
            return TB_LESS_THAN;
        }

        if (src.m_value < m_value) {
            return TB_GREATER_THAN;
        }

        return TB_EQUAL;
    }

    void Merge(const Value & value)
    {
        if (!value.m_empty) {
            m_empty = false;
            m_value = value.m_value;
        }
    }

    void SetMax(const Value & value)
    {
        if (!m_empty) {
            if (!value.m_empty) {
                if (m_value < value.m_value) {
                    m_value = value.m_value;
                }
            }
        } else {
            m_empty = value.m_empty;
            m_value = value.m_value;
        }
    }

    void SetMin(const Value & value)
    {
        if (!m_empty) {
            if (!value.m_empty) {
                if (m_value > value.m_value) {
                    m_value = value.m_value;
                }
            }
        } else {
            m_empty = value.m_empty;
            m_value = value.m_value;
        }
    }

    void Set(const Type & value)
    {
        m_empty = false;
        m_value = value;
    }

    const Type & Get() const { return m_value; }

    Type & Get()
    {
        m_empty = false;
        return m_value;
    }

    bool Empty() const { return m_empty; }

    void Clear()
    {
        m_empty = true;
        m_value = Type();
    }

    std::ostream & Print(std::ostream & strm) const override
    {
        if (m_empty) {
            strm << "<empty>";
        } else {
            strm << m_value;
        }
        return strm;
    }

private:
    bool m_empty;
    Type m_value;
};

} // \namespace tbricks

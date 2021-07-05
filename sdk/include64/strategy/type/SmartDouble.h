#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// SmartDouble type.
//****************************************************************************************

#include "strategy/type/Double.h"

namespace tbricks {

class STRATEGY_EXPORT SmartDouble : public Double
{
public:
    enum Type
    {
        Absolute = 1,
        Delta,
        Factor
    };

public:
    SmartDouble() : m_type(Absolute) {}

    SmartDouble(double value, Type type = Absolute) : Double(value), m_type(type) {}

    SmartDouble(const Double & value, Type type = Absolute) : Double(value), m_type(type) {}

    SmartDouble(const SmartDouble & value) : Double(value), m_type(value.m_type) {}

    SmartDouble & operator=(double value)
    {
        m_type = Absolute;
        Double::operator=(value);
        return *this;
    }

    SmartDouble & operator=(const Double & value)
    {
        m_type = Absolute;
        Double::operator=(value);
        return *this;
    }

    SmartDouble & operator=(const SmartDouble & value)
    {
        m_type = value.m_type;
        Double::operator=(value);
        return *this;
    }

    void Clear() override
    {
        m_type = Absolute;
        Double::Clear();
    }

    Type GetType() const { return m_type; }

    void SetType(Type type)
    {
        if (!Empty()) {
            m_type = type;
        }
    }

    template <typename ValueT>
    bool Update(ValueT & value) const
    {
        if (Empty()) {
            return true;
        }
        if (value.Empty()) {
            return false;
        }
        switch (m_type) {
        case Absolute:
            value = m_value;
            break;
        case Delta:
            value += m_value;
            break;
        case Factor:
            value *= m_value;
            break;
        default:
            return false;
        }
        return true;
    }

    bool Update(double & value) const
    {
        if (Empty()) {
            return true;
        }
        switch (m_type) {
        case Absolute:
            value = m_value;
            break;
        case Delta:
            value += m_value;
            break;
        case Factor:
            value *= m_value;
            break;
        default:
            return false;
        }
        return true;
    }

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_SMARTDOUBLE; }

    size_t GetHash() const override;

public:
    bool operator==(const SmartDouble & value) const { return (m_type == value.m_type) && (Double::operator==(value)); }
    bool operator!=(const SmartDouble & value) const { return !operator==(value); }

    bool operator<(const SmartDouble & value) const
    {
        if (m_type != value.m_type) {
            return m_type < value.m_type;
        }
        return Double::operator<(value);
    }
    bool operator>(const SmartDouble & value) const { return value < *this; }
    bool operator<=(const SmartDouble & value) const { return !(value < *this); }
    bool operator>=(const SmartDouble & value) const { return !operator<(value); }

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Type m_type;
};

} // namespace tbricks

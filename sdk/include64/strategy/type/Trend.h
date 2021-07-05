#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Trend type.
//****************************************************************************************

#include "strategy/type/AnyType.h"

// \namespace tbricks
namespace tbricks {

/**
 * This type describes the trend of a changing value, typically prices.
 * Normally used to describe the behavior of the last tick
 * received for market data.
 */

class STRATEGY_EXPORT Trend : public AnyType
{
public:
    enum Value
    {
        NONE = 0,
        ZERO = 1,
        PLUS = 2,
        MINUS = 3,
        ZERO_PLUS = 4,
        ZERO_MINUS = 5,
        UNDEFINED = 6
    };

public:
    Trend() : m_value(NONE) {}
    Trend(Value value) : m_value(value) {}
    Trend(const Trend & value) : m_value(value.m_value) {}

    Trend & operator=(Value value)
    {
        m_value = value;
        return *this;
    }

    Trend & operator=(const Trend & value)
    {
        m_value = value.m_value;
        return *this;
    }

    bool Empty() const override { return (m_value == NONE); }

    void Clear() { m_value = NONE; }

    Value GetTrend() const { return m_value; }

    size_t GetHash() const override { return (size_t)m_value; }

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

public:
    bool operator==(const Trend & value) const { return (m_value == value.m_value); }

    bool operator!=(const Trend & value) const { return !operator==(value); }

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value m_value;
};

} // \namespace tbricks

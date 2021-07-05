#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForTradeIdentifier object
//
//****************************************************************************

#include "strategy/type/Uuid.h"
#include "strategy/type/Identifier.h"

namespace tbricks {

class STRATEGY_EXPORT RequestForTradeIdentifier : public AnyType
{
public:
    RequestForTradeIdentifier() = default;
    RequestForTradeIdentifier(const Uuid & value)
        : m_value(value)
    {}
    RequestForTradeIdentifier(const char * value)
        : m_value(value)
    {}
    RequestForTradeIdentifier(const types::UUID & value)
        : m_value(value)
    {}
    RequestForTradeIdentifier(const Identifier & value)
        : m_value(value.GetUuid())
    {}

    RequestForTradeIdentifier & operator = (const Uuid & value)
    { m_value = value; return *this; }

    RequestForTradeIdentifier & operator = (const types::UUID & value)
    { m_value = value; return *this; }

public:
    bool Empty() const override
    { return m_value.Empty(); }

    void Clear()
    { m_value.Clear(); }

    const Uuid & GetUuid() const
    { return m_value; }

    size_t GetHash() const override
    { return m_value.GetHash(); }

    constexpr static TypeInfo GetTypeInfo()
    { return TypeInfo::SFT_IDENTIFIER; }

public:
    bool operator == (const RequestForTradeIdentifier & value) const
    { return m_value == value.m_value; }
    bool operator != (const RequestForTradeIdentifier & value) const
    { return !operator == (value); }

    bool operator < (const RequestForTradeIdentifier & value) const
    { return m_value < value.m_value; }
    bool operator > (const RequestForTradeIdentifier & value) const
    { return value < *this; }

    bool operator <= (const RequestForTradeIdentifier & value) const
    { return !(value < *this); }
    bool operator >= (const RequestForTradeIdentifier & value) const
    { return !operator < (value); }

private:
    std::ostream & Print(std::ostream & strm) const override
    { return m_value.Print(strm); }

    TypeInfo get_type_info() const override
    { return GetTypeInfo(); }

    size_t get_size() const override
    { return m_value.get_size(); }

    int decode(const void * data, size_t size) override
    { return m_value.decode(data, size); }

    int encode(void * data, size_t size) const override
    { return m_value.encode(data, size); }

private:
    Uuid m_value;
};

}

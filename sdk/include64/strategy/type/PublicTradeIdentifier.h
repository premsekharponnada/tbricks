#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PublicTradeIdentifier, unique trade identity.
//****************************************************************************************

#include "strategy/type/String.h"

namespace tbricks {

class STRATEGY_EXPORT PublicTradeIdentifier : public AnyType
{
public:
    PublicTradeIdentifier() {}
    PublicTradeIdentifier(const PublicTradeIdentifier & value) : m_value(value.m_value) {}
    PublicTradeIdentifier(const String & value) : m_value(value) {}
    PublicTradeIdentifier(const char * value) : m_value(value) {}

    PublicTradeIdentifier & operator=(const PublicTradeIdentifier & value)
    {
        m_value = value.m_value;
        return *this;
    }
    PublicTradeIdentifier & operator=(const String & value)
    {
        m_value = value;
        return *this;
    }

    PublicTradeIdentifier & operator=(const char * value)
    {
        m_value = value;
        return *this;
    }

    bool Empty() const override { return m_value.Empty(); }
    void Clear() { m_value.Clear(); }

    const String & GetString() const { return m_value; }
    const char * GetCString() const { return m_value.GetCString(); }

    size_t GetHash() const override { return m_value.GetHash(); }

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_TRADE; }

public:
    bool operator==(const PublicTradeIdentifier & value) const { return (m_value == value.m_value); }
    bool operator!=(const PublicTradeIdentifier & value) const { return !operator==(value); }

    bool operator<(const PublicTradeIdentifier & value) const { return m_value < value.m_value; }
    bool operator>(const PublicTradeIdentifier & value) const { return value < *this; }

    bool operator<=(const PublicTradeIdentifier & value) const { return !(value < *this); }
    bool operator>=(const PublicTradeIdentifier & value) const { return !(operator<(value)); }

public:
    bool operator==(const String & value) const { return (m_value == value); }
    bool operator!=(const String & value) const { return (m_value != value); }

    bool operator<(const String & value) const { return m_value < value; }
    bool operator>(const String & value) const { return m_value > value; }

    bool operator<=(const String & value) const { return m_value <= value; }
    bool operator>=(const String & value) const { return m_value >= value; }

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    String m_value;
};

inline bool operator==(const String & v1, const PublicTradeIdentifier & v2)
{
    return v2 == v1;
}
inline bool operator!=(const String & v1, const PublicTradeIdentifier & v2)
{
    return v2 != v1;
}
inline bool operator<(const String & v1, const PublicTradeIdentifier & v2)
{
    return v2 > v1;
}
inline bool operator>(const String & v1, const PublicTradeIdentifier & v2)
{
    return v2 < v1;
}
inline bool operator<=(const String & v1, const PublicTradeIdentifier & v2)
{
    return v2 >= v1;
}
inline bool operator>=(const String & v1, const PublicTradeIdentifier & v2)
{
    return v2 <= v1;
}
}

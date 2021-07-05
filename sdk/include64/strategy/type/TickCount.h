#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TickCount, represnts number of ticks a price should be changed by.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/type/Integer.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT TickCount : public AnyType
{
public:
    TickCount();
    TickCount(int64_t value);
    TickCount(const TickCount & value);
    TickCount(const Integer & value);

    TickCount & operator=(int64_t value);
    TickCount & operator=(const TickCount & value);

    bool Empty() const override { return m_empty; }
    void Clear();
    int64_t GetInt() const;
    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_INTEGER; }

public:
    bool operator==(const TickCount & value) const;
    bool operator!=(const TickCount & value) const;

    bool operator<(const TickCount & value) const;
    bool operator>(const TickCount & value) const;

    bool operator<=(const TickCount & value) const;
    bool operator>=(const TickCount & value) const;

    TickCount operator+(const TickCount & value) const;
    TickCount operator-(const TickCount & value) const;
    TickCount operator*(const TickCount & value) const;
    TickCount operator/(const TickCount & value) const;
    TickCount operator%(const TickCount & value) const;

    TickCount & operator+=(const TickCount & value);
    TickCount & operator-=(const TickCount & value);
    TickCount & operator*=(const TickCount & value);
    TickCount & operator/=(const TickCount & value);
    TickCount & operator%=(const TickCount & value);

    TickCount & operator--();
    TickCount operator--(int);
    TickCount & operator++();
    TickCount operator++(int);

    TickCount operator-() const;

public:
    bool operator==(int64_t value) const;
    bool operator!=(int64_t value) const;

    bool operator<(int64_t value) const;
    bool operator>(int64_t value) const;

    bool operator<=(int64_t value) const;
    bool operator>=(int64_t value) const;

    TickCount operator+(int64_t value) const;
    TickCount operator-(int64_t value) const;
    TickCount operator*(int64_t value) const;
    TickCount operator/(int64_t value) const;
    TickCount operator%(int64_t value) const;

    TickCount & operator+=(int64_t value);
    TickCount & operator-=(int64_t value);
    TickCount & operator*=(int64_t value);
    TickCount & operator/=(int64_t value);
    TickCount & operator%=(int64_t value);

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    bool m_empty;
    int64_t m_value;
};

} // \namespace tbricks

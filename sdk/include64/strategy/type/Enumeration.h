#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Enumeration type.
//****************************************************************************************

#include "strategy/type/Integer.h"

namespace tbricks {

class STRATEGY_EXPORT Enumeration : public Integer
{
public:
    Enumeration() : Integer() {}
    Enumeration(int64_t value) : Integer(value) {}
    Enumeration(const Integer & value) : Integer(value) {}
    Enumeration(const Enumeration & value) : Integer(value) {}

    Enumeration & operator=(int64_t value)
    {
        Integer::operator=(value);
        return *this;
    }

    Enumeration & operator=(const Integer & value)
    {
        Integer::operator=(value);
        return *this;
    }

    Enumeration & operator=(const Enumeration & value)
    {
        Integer::operator=(value);
        return *this;
    }

    bool operator==(const Enumeration & value) const { return Integer::operator==(value); }

    bool operator!=(const Enumeration & value) const { return Integer::operator!=(value); }

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

private:
    TypeInfo get_type_info() const override;
};

} // namespace tbricks

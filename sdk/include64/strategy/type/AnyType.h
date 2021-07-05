#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Basic class for all types types.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/StdInt.h"
#include "strategy/type/TypeInfo.h"

// \namespace tbricks
namespace tbricks {

class Binary;
// typename class Binary::iterator;

class STRATEGY_EXPORT AnyType : public Printable
{
public:
    virtual ~AnyType() = default;

public:
    std::ostream & PrintWithType(std::ostream & strm) const;
    virtual size_t GetHash() const = 0;

public:
    virtual TypeInfo get_type_info() const = 0;
    virtual bool Empty() const = 0;

    void Encode(Binary & data) const;
    void Decode(const Binary & buffer, size_t & offset);

    /// Codec
    virtual size_t get_size() const = 0;
    virtual int decode(const void * data, size_t size) = 0;
    virtual int encode(void * data, size_t size) const = 0;
};

inline size_t hash_value(const AnyType & value)
{
    return value.GetHash();
}

inline size_t hash_value(int value)
{
    return (size_t)value;
}

template <typename T>
inline size_t hash_value(T * const & value)
{
    return (size_t)value;
}
}

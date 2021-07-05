#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Algo label type.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

namespace tbricks {

class STRATEGY_EXPORT AlgoType : public AnyType
{
public:
    enum AlgoTypeValue
    {
        ALGORITHM = 1,
        MANUAL = 2,
        UNDEFINED = 3
    };

public:
    AlgoType();
    AlgoType(AlgoTypeValue value);
    AlgoType(const AlgoType & value);

    AlgoType & operator=(AlgoTypeValue value);
    AlgoType & operator=(const AlgoType & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    AlgoTypeValue Get() const;

    bool IsAlgorithm() const { return !Empty() && (Get() == ALGORITHM); }
    bool IsManual() const { return !Empty() && (Get() == MANUAL); }
    bool IsUndefined() const { return !Empty() && (Get() == UNDEFINED); }

    size_t GetHash() const override;
    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator AlgoTypeValue() const { return Get(); }

public:
    bool operator==(AlgoTypeValue value) const;
    bool operator!=(AlgoTypeValue value) const;

    bool operator==(const AlgoType & value) const;
    bool operator!=(const AlgoType & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<AlgoTypeValue> m_value;
};

STRATEGY_EXPORT
bool operator==(AlgoType::AlgoTypeValue v1, const AlgoType & v2);

STRATEGY_EXPORT
bool operator!=(AlgoType::AlgoTypeValue v1, const AlgoType & v2);

} // \namespace tbricks

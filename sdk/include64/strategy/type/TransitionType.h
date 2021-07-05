#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Order transition type.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT TransitionType : public AnyType
{
public:
    enum TypeValue
    {
        MARKET_TO_LIMIT = 1,
        LIMIT_TO_MARKET = 2
    };

public:
    TransitionType();
    TransitionType(TypeValue value);
    TransitionType(const TransitionType & value);

    TransitionType & operator=(TypeValue value);
    TransitionType & operator=(const TransitionType & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    TypeValue Get() const;

    bool IsMarketToLimit() const;
    bool IsLimitToMarket() const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator TypeValue() const { return Get(); }

public:
    bool operator==(TypeValue value) const;
    bool operator!=(TypeValue value) const;

    bool operator==(const TransitionType & value) const;
    bool operator!=(const TransitionType & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<TypeValue> m_value;
};

STRATEGY_EXPORT
bool operator==(TransitionType::TypeValue v1, const TransitionType & v2);

STRATEGY_EXPORT
bool operator!=(TransitionType::TypeValue v1, const TransitionType & v2);

} // \namespace tbricks

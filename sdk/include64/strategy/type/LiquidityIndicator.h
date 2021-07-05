#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Liquidity indicator type.
//****************************************************************************************

#include "strategy/type/AnyType.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT LiquidityIndicator : public AnyType
{
public:
    enum Value
    {
        NONE = 0,
        ADDED = 1,
        REMOVED = 2,
        AUCTION = 3
    };

public:
    LiquidityIndicator();
    LiquidityIndicator(Value value);
    LiquidityIndicator(const LiquidityIndicator & value);

    LiquidityIndicator & operator=(Value value);
    LiquidityIndicator & operator=(const LiquidityIndicator & value);

    bool Empty() const override { return m_value == NONE; }
    void Clear();
    Value GetLiquidityIndicator() const;
    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

public:
    bool operator==(const LiquidityIndicator & value) const;
    bool operator!=(const LiquidityIndicator & value) const;

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

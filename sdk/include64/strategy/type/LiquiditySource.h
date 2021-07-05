#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Liquidity source
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT LiquiditySource : public AnyType
{
public:
    enum SourceValue
    {
        EXCHANGE = 1,
        INTERNAL,
        REMOTE,
    };

public:
    LiquiditySource();
    LiquiditySource(SourceValue value);
    LiquiditySource(const LiquiditySource & value);

    LiquiditySource & operator=(SourceValue value);
    LiquiditySource & operator=(const LiquiditySource & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    SourceValue Get() const;

    bool IsExchange() const;
    bool IsInternal() const;
    bool IsRemote() const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator SourceValue() const { return Get(); }

public:
    bool operator==(SourceValue value) const;
    bool operator!=(SourceValue value) const;

    bool operator==(const LiquiditySource & value) const;
    bool operator!=(const LiquiditySource & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<SourceValue> m_value;
};

STRATEGY_EXPORT
bool operator==(LiquiditySource::SourceValue v1, const LiquiditySource & v2);

STRATEGY_EXPORT
bool operator!=(LiquiditySource::SourceValue v1, const LiquiditySource & v2);

} // \namespace tbricks

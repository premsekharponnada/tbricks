#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Price policy
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

namespace tbricks {

class STRATEGY_EXPORT PricePolicy : public AnyType
{
public:
    enum PolicyValue
    {
        BOOK_OR_CANCEL = 1,
    };

public:
    PricePolicy();
    PricePolicy(PolicyValue value);
    PricePolicy(const PricePolicy & value);

    PricePolicy & operator=(PolicyValue value);
    PricePolicy & operator=(const PricePolicy & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    PolicyValue Get() const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator PolicyValue() const { return Get(); }

public:
    bool operator==(PolicyValue value) const;
    bool operator!=(PolicyValue value) const;

    bool operator==(const PricePolicy & value) const;
    bool operator!=(const PricePolicy & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<PolicyValue> m_value;
};

STRATEGY_EXPORT
bool operator==(PricePolicy::PolicyValue v1, const PricePolicy & v2);

STRATEGY_EXPORT
bool operator!=(PricePolicy::PolicyValue v1, const PricePolicy & v2);

} // namespace tbricks

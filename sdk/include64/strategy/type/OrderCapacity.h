#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Order capacity.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT OrderCapacity : public AnyType
{
public:
    enum CapacityValue
    {
        AGENCY = 0,
        PRINCIPAL,
        RISKLESS_PRINCIPAL,
        LAST_ITEM = RISKLESS_PRINCIPAL
    };

public:
    OrderCapacity();
    OrderCapacity(CapacityValue value);
    OrderCapacity(const OrderCapacity & value);

    OrderCapacity & operator=(CapacityValue value);
    OrderCapacity & operator=(const OrderCapacity & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    CapacityValue Get() const;

    bool IsAgency() const;
    bool IsPrincipal() const;
    bool IsRisklessPrincipal() const;

    size_t GetHash() const override;
    static TypeInfo GetTypeInfo();

    operator CapacityValue() const { return Get(); }

public:
    bool operator==(CapacityValue value) const;
    bool operator!=(CapacityValue value) const;

    bool operator==(const OrderCapacity & value) const;
    bool operator!=(const OrderCapacity & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<CapacityValue> m_value;
};

STRATEGY_EXPORT
bool operator==(OrderCapacity::CapacityValue v1, const OrderCapacity & v2);

STRATEGY_EXPORT
bool operator!=(OrderCapacity::CapacityValue v1, const OrderCapacity & v2);

} // \namespace tbricks

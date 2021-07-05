#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Price structure
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT PriceStructure : public AnyType
{
public:
    /** How a price should be structured for input/output, e.g. penny denomination, fractions or just as-is. */
    enum PriceStructureValue
    {
        PER_UNIT = 1,    /**< Normal pricing per share, contract or unit of measure. Gross trade amount can be calculated
                            by (price X factor X volume). */
        VOLATILITY = 2,  /**< Priced in volatility, resulting trades are normally in per-unit instruments, both options
                            and future. */
        PRICE_OFFSET = 3 /**< Priced in offset from another price e.g. settlement or NAV, resulting trades are normally in per-unit
                            instrument, applicable to futures (trade-at-settlement) and ETFs (at-NAV trades).*/
    };

public:
    PriceStructure();
    PriceStructure(PriceStructureValue value);
    PriceStructure(const PriceStructure & value);

    PriceStructure & operator=(PriceStructureValue value);
    PriceStructure & operator=(const PriceStructure & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    PriceStructureValue Get() const;

    bool IsPerUnit() const;
    bool IsVolatility() const;
    bool IsPriceOffset() const;

    size_t GetHash() const override;
    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator PriceStructureValue() const { return Get(); }

public:
    bool operator==(PriceStructureValue value) const;
    bool operator!=(PriceStructureValue value) const;

    bool operator==(const PriceStructure & value) const;
    bool operator!=(const PriceStructure & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<PriceStructureValue> m_value;
};

STRATEGY_EXPORT
bool operator==(PriceStructure::PriceStructureValue v1, const PriceStructure & v2);

STRATEGY_EXPORT
bool operator!=(PriceStructure::PriceStructureValue v1, const PriceStructure & v2);

} // \namespace tbricks

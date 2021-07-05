#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Qualified role.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

namespace tbricks {

/**
 * Gives the execution policy for a given order.
 * Most common is the short sell policy, indicating a sale of a security not owned by the seller.
 */
class STRATEGY_EXPORT ExecutionPolicy : public AnyType
{
public:
    enum ExecutionPolicyValue
    {
        NONE = 0,              /**< Execution policy is not specified */
        BUY_MINUS = 1,         /**< A round-lot market order to buy minus is an order to buy a stated amount of a stock provided
                                * that its price is:
                                *   - not higher than the last sale if the last sale was a minus or zero minus tick and
                                *   - not higher than the last sale minus the minimum fractional change in
                                *     the stock if the last sale was a plus or zero plus tick.
                                *
                                *   A limit price order to buy minus also states the highest price at which it can be executed.
                                */
        SELL_PLUS = 2,         /**< A round-lot market order to sell plus is an order to sell a stated
                                *   amount of a stock provided that its price is:
                                *   - not lower than the last sale if the last sale was a plus or zero plus tick and
                                *   - not lower than the last sale minus the minimum fractional change in the
                                *     stock if the last sale was a minus or zero minus tick.
                                *
                                *   A limit-price order to sell plus also states the lowest price at which it can be executed.
                                */
        SELL_SHORT = 3,        /**< An order to sell a security that the seller does not own, a sale effected
                                *   by delivering a security borrowed by, or for the account of, the seller.
                                *   Can only be executed on a plus or zero plus tick.
                                */
        SELL_SHORT_EXEMPT = 4, /**< Short sale exempt from short-sale rules. */
        SELL_UNDISCLOSED = 5   /**< It is inpossible determine is it short sale transaction or not.*/

        // if you add new item, please fix ExecutionPolicySet
    };

public:
    ExecutionPolicy();
    ExecutionPolicy(ExecutionPolicyValue value);
    ExecutionPolicy(const ExecutionPolicy & value);

    ExecutionPolicy & operator=(ExecutionPolicyValue value);
    ExecutionPolicy & operator=(const ExecutionPolicy & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    ExecutionPolicyValue Get() const;

    bool IsBuyMinus() const { return !Empty() && (Get() == BUY_MINUS); }
    bool IsSellPlus() const { return !Empty() && (Get() == SELL_PLUS); }
    bool IsSellShort() const { return !Empty() && (Get() == SELL_SHORT); }
    bool IsSellShortExempt() const { return !Empty() && (Get() == SELL_SHORT_EXEMPT); }
    bool IsUndisclosed() const { return !Empty() && (Get() == SELL_UNDISCLOSED); }

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator ExecutionPolicyValue() const { return Get(); }

public:
    bool operator==(ExecutionPolicyValue value) const;
    bool operator!=(ExecutionPolicyValue value) const;

    bool operator==(const ExecutionPolicy & value) const;
    bool operator!=(const ExecutionPolicy & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<ExecutionPolicyValue> m_value;
};

STRATEGY_EXPORT
bool operator==(ExecutionPolicy::ExecutionPolicyValue v1, const ExecutionPolicy & v2);

STRATEGY_EXPORT
bool operator!=(ExecutionPolicy::ExecutionPolicyValue v1, const ExecutionPolicy & v2);
}

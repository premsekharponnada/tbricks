#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Trade type.
//****************************************************************************************

#include "strategy/type/AnyType.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT TradeType : public AnyType
{
public:
    enum Value
    {
        // empty
        NONE = 0,
        // The trade type indicating normal automatic matching, at venue side.
        AUTOMATIC_TRADE = 1,
        // The trade type indicating manual registration.
        REGISTERED_TRADE = 2,
        // The trade type indicating internalised matching of crossing orders,
        // within tbricks system.
        INTERNAL_TRADE = 3,
        // The trade type indicating trades resulting from simulation.
        SIMULATED_TRADE = 4,
        // The trade originates from a venue or exchange but does not have a corresponding order on Tbricks side.
        // This is normally due to reception of drop-copies or other applications trades leaking into Tbricks
        // but it can also be related to reception of trades where orders have not been persisted or orders
        // already being purged on Tbricks side.
        UNSOLICITED_TRADE = 5,
        // The trade was delivered as part of an expiration.
        DELIVERY_TRADE = 6,
        // The trade was delivered as part of an expiration.
        EARLY_EXERCISE_TRADE = 7,
        // The trade was delivered as part of an expiration.
        EXPIRATION_TRADE = 8,
        // The trade was delivered as part of an expiration.
        ASSIGNMENT_TRADE = 9,
        // Expit trade and reported on the exchange.
        EXPIT = 10,
        // Drop copies are trades done in other systems but assimilated by Tbricks drop copy reception service.
        // These trades are not expected to have a corresponding but missing order like the unsoliciteds.
        DROP_COPY = 11,
        // External position adjustment.
        POSITION_ADJUSTMENT = 12,
        // Trade closing the position on expired derivative
        EXPIRATION_CLOSE_TRADE = 13,
        // The trade type indicating position reset
        POSITION_RESET = 14,
        // The correcting trade at an expiration exercise.
        EXERCISE_TRADE = 15,
        // The resulting delivery trade at all exercises.
        EXERCISE_DELIVERY_TRADE = 16,
        // The resulting delivery trade at assignments.
        ASSIGNMENT_DELIVERY_TRADE = 17
    };

public:
    TradeType();
    TradeType(Value value);
    TradeType(const TradeType & value);

    TradeType & operator=(Value value);
    TradeType & operator=(const TradeType & value);

    bool Empty() const override { return m_value == NONE; }
    void Clear();
    Value GetTradeType() const;
    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

public:
    bool operator==(const TradeType & value) const;
    bool operator!=(const TradeType & value) const;

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

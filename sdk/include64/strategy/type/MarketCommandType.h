#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Market command type
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

namespace tbricks {

class STRATEGY_EXPORT MarketCommandType : public AnyType
{
public:
    // clang-format off
    enum Type
    {
        SuspendParticipant = 1,         /*< Sent by a liquidity provider to block trading with participants, still allowing them to see quotes. */
        ResumeParticipant = 2,          /*< Sent by a liquidity provider to resumes trading with participants. */
        HaltParticipant = 3,            /*< Sent by a liquidity provider to blocks trading with participants and preventing them to see quotes. */
        SetParticipationParameters = 4, /*< Set parameters of the minimum guaranteed fill. */
        DelayOpening = 5,               /*< Sent by a specialist to delay opening an instrument. */
        OpenDelayedTrading = 6,         /*< Sent by a specialist to start trading in the instrument which opening was previously delayed. */
        SetLastAuctionPrice = 7,        /*< Set by a specialist to set the last auction price. */
        StartTrading = 8,               /*< Sent by an issuer to start trading in a newly issued instrument. */
        Knockout = 9,                   /*< Sent by an issuer to knock out the instrument due to breach of underlying price barrier. */
        EnterBuybackPhase = 10,         /*< Sent by an issuer to enter the buyback phase for an instrument. */
        SoldOut = 11,                   /*< iSent by issuer when it runs out of inventory to sell. */
        SoftKnockOut = 12,              /*< Sent by an issuer to knock out the instrument due to breach of certain barrier and recalculation event is required. */
        UnderlyingNotQuoted = 13,       /*< Missing market maker in underlying instrument. */
        UnderlyingQuoted = 14           /*< Removes 'Underlying note quoted' indication after market making in underlying instrument provides quotes. */
    };
    // clang-format on

public:
    MarketCommandType() = default;
    MarketCommandType(Type value);
    MarketCommandType(const MarketCommandType & value) = default;

    MarketCommandType & operator=(Type value);
    MarketCommandType & operator=(const MarketCommandType & value) = default;

    bool Empty() const override { return m_value.Empty(); }

    void Clear();
    Type Get() const;

    size_t GetHash() const override;
    static TypeInfo GetTypeInfo();

    operator Type() const { return Get(); }

public:
    bool operator==(Type value) const;
    bool operator!=(Type value) const;

    bool operator==(const MarketCommandType & value) const;
    bool operator!=(const MarketCommandType & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<Type> m_value;
};

STRATEGY_EXPORT
bool operator==(MarketCommandType::Type v1, const MarketCommandType & v2);

STRATEGY_EXPORT
bool operator!=(MarketCommandType::Type v1, const MarketCommandType & v2);

} // namespace tbricks.

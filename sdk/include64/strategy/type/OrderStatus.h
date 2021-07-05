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

class STRATEGY_EXPORT OrderStatus : public AnyType
{
public:
    enum OrderStatusValue
    {
        // Receipt of a new order by the operator of the trading venue.
        NEW_ORDER = 1,
        // An order which becomes executable or, as the case may be, non-executable upon the realisation of a
        // pre-determined condition.
        TRIGGERED = 2,
        // Replaced by the member or participant or client of the trading venue: where a member or participant or client
        // of the trading venue decides upon its own initiative to change any characteristic(s) of the order it has
        // previously entered into the order book.
        REPLACED_BY_MEMBER = 3,
        // Where any characteristic(s) of an order is changed by the trading venue operator’s IT systems. This includes
        // where a peg order’s or a trailing stop order’s current characteristics are changed to reflect how the order
        // is located within the order book.
        REPLACED_BY_MARKET_AUTOMATIC = 4,
        // Where any characteristic(s) of an order is changed by a trading venue operator’s staff. This includes where a
        // member or participant or client of the trading venue has IT issues and needs its orders to be cancelled
        // urgently.
        REPLACED_BY_MARKET_HUMAN_INVENTION = 5,
        // Change of status at the initiative of the Member/Participant/client of the trading venue. This includes
        // activation, deactivation.
        CHANGE_OF_STATUS_AT_THE_INITIATIVE_OF_THE_MEMBER = 6,
        // Change of status due to market operations
        CHANGE_OF_STATUS_DUE_TO_MARKET_OPERATIONS = 7,
        // Cancelled at the initiative of the member or participant or client of the trading venue; where a member or
        // participant or client decides upon its own initiative to cancel the order it has previously entered.
        CANCELLED_AT_THE_INITIATIVE_OF_THE_MEMBER = 8,
        // This includes a protection mechanism provided for investment firms carrying out a market making activity as
        // per Articles 17 and 48 of Directive 2014/65/EU.
        CANCELLED_BY_MARKET_OPERATIONS = 9,
        // An order received but rejected by the operator of the trading venue.
        REJECTED_ORDER = 10,
        // Where the order is removed from the order book upon the end of its validity period.
        EXPIRED_ORDER = 11,
        // Where the order is not fully executed so that there remains a quantity to be executed.
        PARTIALLY_FILLED = 12,
        // Where there is no more quantity to be executed.
        FILLED = 13
    };

public:
    OrderStatus();
    OrderStatus(OrderStatusValue value);
    OrderStatus(const OrderStatus & value);

    OrderStatus & operator=(OrderStatusValue value);
    OrderStatus & operator=(const OrderStatus & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    OrderStatusValue Get() const;

    bool IsNewOrder() const { return IsEqual(NEW_ORDER); }
    bool IsTriggered() const { return IsEqual(TRIGGERED); }
    bool IsReplacedByMember() const { return IsEqual(REPLACED_BY_MEMBER); }
    bool IsReplacedByMarketAutomatic() const { return IsEqual(REPLACED_BY_MARKET_AUTOMATIC); }
    bool IsReplacedByMarketHumanInvention() const { return IsEqual(REPLACED_BY_MARKET_HUMAN_INVENTION); }
    bool IsChangeOfStatusAtTheInitiativeOfTheMember() const { return IsEqual(CHANGE_OF_STATUS_AT_THE_INITIATIVE_OF_THE_MEMBER); }
    bool IsChangeOfStatusDueToMarketOperations() const { return IsEqual(CHANGE_OF_STATUS_DUE_TO_MARKET_OPERATIONS); }
    bool IsCancelledAtTheInitiativeOfTheMember() const { return IsEqual(CANCELLED_AT_THE_INITIATIVE_OF_THE_MEMBER); }
    bool IsCancelledByMarketOperations() const { return IsEqual(CANCELLED_BY_MARKET_OPERATIONS); }
    bool IsRejectedOrder() const { return IsEqual(REJECTED_ORDER); }
    bool IsExpiredOrder() const { return IsEqual(EXPIRED_ORDER); }
    bool IsPartiallyFilled() const { return IsEqual(PARTIALLY_FILLED); }
    bool IsFilled() const { return IsEqual(FILLED); }

    size_t GetHash() const override;
    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator OrderStatusValue() const { return Get(); }

public:
    bool operator==(OrderStatusValue value) const;
    bool operator!=(OrderStatusValue value) const;

    bool operator==(const OrderStatus & value) const;
    bool operator!=(const OrderStatus & value) const;

private:
    bool IsEqual(OrderStatusValue value) const { return !Empty() && (Get() == value); }

    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<OrderStatusValue> m_value;
};

STRATEGY_EXPORT
bool operator==(OrderStatus::OrderStatusValue v1, const OrderStatus & v2);

STRATEGY_EXPORT
bool operator!=(OrderStatus::OrderStatusValue v1, const OrderStatus & v2);

} // \namespace tbricks

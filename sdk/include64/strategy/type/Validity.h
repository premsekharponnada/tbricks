#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy transaction state type.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/Duration.h"

// namespace tbricks
namespace tbricks {

namespace protocol {
class OrderModifyRequest;
class DirectedQuoteRequestRequest;
}

/**
 * Validity type.
 *
 * How long an order or strategy is valid.
 * If not specified the venue default is expected.
 * Keep in mind that the venue default can be a very complex validity scheme
 * even though it is generally equivalent with a simple day order.
 *
 * * immediate
 * The order will never reside in the orderbook, but will be checked
 * for matching and any residual volume will after matching be
 * momentarily cancelled. A strategy is executed once.
 *
 * * infinite
 * The order will be valid until cancelled or until the instrument
 * is no longer valid. An instrument that is no longer valid can be
 * an expired derivative or a stock that is de-listed.
 *
 * * today
 * The order is valid until the current trading day is over.
 * This is almost always supported by the venue itself.
 *
 * * until date
 * The order is valid until and including this date.
 *
 * * until elapsed time
 * The order is valid until specified time has elapsed.
 * This is almost always a synthetic type that needs to be implemented
 * in the target trading service itself. If not implemented or supported,
 * return an error on attempt to enter an order with this validity.
 *
 * * immediate on open
 * The order gets activated and during the opening phase of the instrument.
 * If no price is defined, the order is a market on open order,
 * guaranteeing the opening price or better. If the price is defined,
 * they will execute only if the price limit is met regarding opening price.
 * Few exchanges support limit orders on open.
 *
 * * immediate on close
 * The same order as above but it will get executed on the closing phase
 * of the instrument. Closing phases may be more complicated and include
 * more than one matching cycle, the behavior is highly venue specific.
 * Disregarding the venue semantics, the price will always be better than
 * or equal to closing price or limit price if specified.
 * Few exchanges support limit orders on open.
 *
 * * until datetime
 * The entity is valid up until and including this date and time.
 */

class STRATEGY_EXPORT Validity : public AnyType
{
public:
    using AnyType::Decode;
    using AnyType::Encode;
    enum Type
    {
        VALID_IMMEDIATE = 1,
        VALID_INFINITE = 2,
        VALID_TODAY = 3,
        VALID_UNTIL_DATE = 4,
        VALID_UNTIL_ELAPSED_TIME = 5,
        VALID_IMMEDIATE_ON_OPEN = 6,
        VALID_IMMEDIATE_ON_CLOSE = 7,
        VALID_UNTIL_DATETIME = 8,
        VALID_IMMEDIATE_ON_AUCTION = 9,
        VALID_LAST_AUCTION = 10,
        VALID_LAST_ITEM = VALID_LAST_AUCTION
    };

public:
    Validity() : m_empty(true), m_type(VALID_IMMEDIATE) {}
    Validity(Type value);
    Validity(const Validity & value);

    Validity & operator=(Type value);
    Validity & operator=(const Validity & value);

    void SetValidUntilDate(const DateTime & date);
    const DateTime & GetValidUntilDate() const;

    void SetValidUntilDateTime(const DateTime & datetime);
    const DateTime & GetValidUntilDateTime() const;

    void SetValidFor(const Duration & elapsed);
    const Duration & GetValidFor() const;

    bool Empty() const override { return m_empty; }
    void Clear();

    bool IsValid() const;

    /**
     * %Set type of validity.
     * Date and time will be cleared, if new type doesn't use it.
     *
     * @code
     * Validity v;
     * v.SetValidUntilDateTime(DateTime::Now());
     * v.SetType(VALID_UNTIL_DATE); // date and time aren't cleared
     * v.SetType(VALID_TODAY);      // date and time are cleared
     * @endcode
     */
    void SetType(Type type);
    Type GetType() const;
    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

public:
    bool operator==(Type value) const;
    bool operator!=(Type value) const;

    bool operator==(const Validity & value) const;
    bool operator!=(const Validity & value) const;

public:
    /** @cond PRIVATE */
    template <typename MessageT>
    void Decode(const MessageT & message);
    void Decode(const protocol::OrderModifyRequest & message);
    void Decode(const protocol::DirectedQuoteRequestRequest & message);
    template <typename MessageT>
    void Encode(MessageT & message) const;
    void Encode(protocol::OrderModifyRequest & message) const;
    void Encode(protocol::DirectedQuoteRequestRequest & message) const;
    /** @cond PRIVATE */

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    bool m_empty;
    Type m_type;

    DateTime m_datetime;
    Duration m_elapsed;
};

} // namespace tbricks

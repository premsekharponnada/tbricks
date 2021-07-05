#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CircuitBreaker object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/InstrumentVenueIdentification.h"

#include <memory>

namespace tbricks {

namespace protocol {
class CircuitBreaker;
}
/**
 * CircuitBreaker class
 */
class STRATEGY_EXPORT CircuitBreaker : public Printable
{
public:
    class Options;
    class Modifier;

public:
    class RequestResult;

public:
    class Stream;

public:
    CircuitBreaker();
    CircuitBreaker(const CircuitBreaker & cb);
    CircuitBreaker & operator=(const CircuitBreaker & cb);
    virtual ~CircuitBreaker();

public:
    Identifier GetCircuitBreakerIdentifier() const;

    const InstrumentVenueIdentification & GetInstrumentVenueIdentification() const;

public:
    bool HasQuoteSetIdentifier() const;
    Identifier GetQuoteSetIdentifier() const;

public:
    /**
     * Get existence of allowed move in time period.
     *
     * @return                      true, if parameters is set and
     *                              false, in otherwise
     */
    bool HasAllowedMoveInTimePeriod() const;

    /**
     * Returns allowed move in time period.
     *
     * @return                      Allowed move
     */
    Double GetAllowedMoveInTimePeriod() const;

    /**
     * Get existence of time window for allowed move.
     *
     * @return                      true, if parameters is set and
     *                              false, in otherwise
     */
    bool HasAllowedMoveTimeWindow() const;

    /**
     * Returns duration of time window for allowed move.
     *
     * @return                      Duration of time window
     */
    Duration GetAllowedMoveTimeWindow() const;

    /**
     * Get existence of maximum spread.
     *
     * @return                      true, if parameters is set and
     *                              false, in otherwise
     */
    bool HasMaximumSpreadAllowed() const;
    Double GetMaximumSpreadAllowed() const;

    /**
     * Get existence of volume setting for bid side.
     *
     * @return                      true, if parameters is set and
     *                              false, in otherwise
     */
    bool HasBidVolume() const;

    /**
     * Returns volume setting for bid side.
     *
     * @return                      Volume
     */
    Volume GetBidVolume() const;

    /**
     * Get existence of volume setting for ask side.
     *
     * @return                      true, if parameters is set and
     *                              false, in otherwise
     */
    bool HasAskVolume() const;

    /**
     * Returns volume setting for ask side.
     *
     * @return                      Volume
     */
    Volume GetAskVolume() const;

public:
    /**
     * Returns a true value if circuit breaker is deleted.
     *
     * @return                      true, if circuit breaker is deleted and
     *                              false, in otherwise
     */
    Boolean Deleted() const;

    /**
     * Returns a true value if circuit breaker is triggered.
     *
     * @return                      true, if circuit breaker is treiggered and
     *                              false, in otherwise
     */
    Boolean Triggred() const;

    /**
     * Get existence of transaction state.
     *
     * @return                      true, if transaction state is defined and
     *                              false, in otherwise
     */
    bool HasTransactionState() const;

    /**
     * Returns transaction state of circuit breaker.
     *
     * @return                      Transaction state
     */
    TransactionState GetTransactionState() const;

    /**
     * Returns text with description of circuit breaker status
     *
     * @return                      Status text
     */
    String GetStatusText() const;

private:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    CircuitBreaker(std::shared_ptr<protocol::CircuitBreaker> && msg);

private:
    mutable InstrumentVenueIdentification m_ivid;
    std::shared_ptr<protocol::CircuitBreaker> m_msg;
};

/**
 * CircuitBreaker::Options class
 */
class STRATEGY_EXPORT CircuitBreaker::Options : public Printable
{
public:
    Options();
    Options(const Options & options);
    Options & operator=(const Options & options);
    virtual ~Options();

public:
    /**
     * Specifies instrument venue indentification of circuit breaker instrument.
     *
     * @param                           Instrument venie identification
     */
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);
    const InstrumentVenueIdentification & GetInstrumentVenueIdentification() const;

    /**
     * Specifies the maximum move of the best bid/offer of
     * the circuit breaker instrument in the given time period.
     *
     * @param value                     Maximum move of underlying
     */
    void SetAllowedMoveInTimePeriod(const Double & value);
    const Double & GetAllowedMoveInTimePeriod() const;

    /**
     * Specifies the time period for allowed circuit breaker move.
     *
     * @see SetAllowedMoveInTimePeriod
     *
     * @param pediod                    Time period in seconds
     */
    void SetAllowedMoveTimeWindow(const Duration & period);
    const Duration & GetAllowedMoveTimeWindow() const;

    /**
     * Specifies the largest difference allowed between
     * bid/offer of the circuit breaker instrument.
     *
     * @param                           Maximum spread
     */
    void SetMaximumSpreadAllowed(const Double & value);
    const Double & GetMaximumSpreadAllowed() const;

    /**
     * Specifies the type of market data to use for watching.
     *
     * @param                           Market data to use
     */
    void SetMarketDataToUse(MarketDataToUse market_data_to_use);
    MarketDataToUse GetMarketDataToUse() const;

    /**
     * Bid volume must be set if volume weighted aggregated price is chosen
     *
     * @param                           Volume
     */
    void SetBidVolume(const Volume & volume);
    const Volume & GetBidVolume() const;

    /**
     * Ask volume must be set if volume weighted aggregated price is chosen
     *
     * @param                           Volume
     */
    void SetAskVolume(const Volume & volume);
    const Volume & GetAskVolume() const;

    /**
     * Enables server-side switcher
     *
     * @param enable_server_side_switcher
     */
    void SetEnableServerSideSwitcher(const Boolean & enable_server_side_switcher);
    const Boolean & GetEnableServerSideSwitcher() const;

    /**
     * Sets granularity if server-side switcher is enabled
     *
     * @param price_step_granularity
     */
    void SetPriceStepGranularity(const Double & price_step_granularity);
    /**
     * @return granularity of price cache of server-side switcher
     */
    const Double & GetPriceStepGranularity() const;

    /**
     * Sets type of price granularity
     *
     * @param in_ticks set to ticks if true, to absolute otherwise
     */
    void SetPriceStepGranularityInTicks(const Boolean & in_ticks);
    /**
     * @return true if price step granularity is in ticks
     */
    const Boolean & GetPriceStepGranularityInTicks() const;

private:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    class CircuitBreakerOptionsImpl;
    std::unique_ptr<CircuitBreakerOptionsImpl> m_impl;
};

/**
 * CircuitBreaker::Modifier class
 */

class STRATEGY_EXPORT CircuitBreaker::Modifier : public Printable
{
public:
    Modifier();
    Modifier(const Modifier & modifier);
    Modifier & operator=(const Modifier & modifier);
    virtual ~Modifier();

public:
    /**
     * Specifies the maximum move of the best bid/offer of
     * the circuit breaker instrument in the given time period.
     *
     * @param value                     Maximum move of underlying
     */
    bool HasAllowedMoveInTimePeriod() const;
    void SetAllowedMoveInTimePeriod(const Double & value);
    const Double & GetAllowedMoveInTimePeriod() const;

    /**
     * Specifies the time period for allowed circuit breaker move.
     *
     * @see SetAllowedMoveInTimePeriod
     *
     * @param pediod                    Time period in seconds
     */
    bool HasAllowedMoveTimeWindow() const;
    void SetAllowedMoveTimeWindow(const Duration & period);
    const Duration & GetAllowedMoveTimeWindow() const;

    /**
     * Specifies the largest difference allowed between
     * bid/offer of the circuit breaker instrument.
     *
     * @param                           Maximum spread
     */
    bool HasMaximumSpreadAllowed() const;
    void SetMaximumSpreadAllowed(const Double & value);
    const Double & GetMaximumSpreadAllowed() const;

private:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    class CircuitBreakerModifierImpl;
    std::unique_ptr<CircuitBreakerModifierImpl> m_impl;
};

/**
 * CircuitBreaker::RequestResult class
 */
class STRATEGY_EXPORT CircuitBreaker::RequestResult : public Printable
{
public:
    RequestResult();
    virtual ~RequestResult() {}
    RequestResult(const Identifier & request_identifier, const Identifier & circuit_breaker_identifier);

    const Identifier & GetRequestIdentifier() const;
    const Identifier & GetCircuitBreakerIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    Identifier m_circuit_breaker_identifier;
};

} // namespace tbricks

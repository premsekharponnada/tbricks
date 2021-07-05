#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Venue properties.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/TradingCapabilities.h"
#include "strategy/MarketCommandCapabilities.h"
#include "strategy/MarketDataCapabilities.h"
#include "strategy/DirectedQuoteRequestCapabilities.h"
#include "strategy/VenueInstrumentIdentifierStructure.h"

#include "strategy/type/VenueIdentifier.h"
#include "strategy/SafePointer.h"
#include "strategy/SharedPointer.h"
#include "strategy/Percentiles.h"
#include "strategy/type/MIC.h"
#include "strategy/type/LegalEntityIdentifier.h"

namespace tbricks {

namespace venue {
class VenueInfo;
}

/**
 * Venue provides a full description of a market known in the system, exactly
 * as it is configured with a resource of "application/x-venue+xml" type.
 */
class STRATEGY_EXPORT Venue : public AnyType
{
public:
    /**
     * Default constructor.
     *
     * Creates an unresolved object with an empty identifier and empty fields.
     */
    Venue();
    Venue(const VenueIdentifier & id);
    Venue(const Venue & venue);
    Venue(const types::UUID & id);
    Venue(const char * value);
    ~Venue() override;

    Venue & operator=(const VenueIdentifier & id);
    Venue & operator=(const Venue & venue);
    Venue & operator=(const types::UUID & id);

    enum class OrderPriceType
    {
        Limit = 1,
        VWAP = 2
    };

    enum class OrderBookType
    {
        Limit = 0,
        PriceBanded = 1
    };

    enum class RoundingPolicy
    {
        None = 1,
        Fair = 2,
        Market = 3,
        Bank = 4
    };

    /**
     * Get venue identfier.
     *
     * @return                          Venue identifier
     */
    const VenueIdentifier & GetIdentifier() const;

    /**
     * Get venue name.
     *
     * Returns full venue name, e.g. "Market place".
     *
     * @return                          Venue name if it is available,
     *                                  an empty value otherwise
     */
    String GetName() const;

    /**
     * Get short name.
     *
     * Returns short venue name, e.g. "Internal".
     *
     * @return                          Venue name if it is available,
     *                                  an empty value otherwise
     */
    String GetShortName() const;

    /**
     * Get description.
     *
     * Return venue description, e.g. "tbricks internal market place".
     *
     * @return                          Venue name if it is available,
     *                                  an empty value otherwise
     */
    String GetDescription() const;

    /**
     * Get default liquidity pool.
     *
     * @return                          Default liquidity pool if it is available,
     *                                  an empty value otherwise
     */
    LiquidityPool GetDefaultLiquidityPool() const;

    /**
     * Get trading capabilities.
     *
     * Return a set of features supported by a trading venue.
     *
     * @return                          Trading capabilities set
     */
    TradingCapabilities GetTradingCapabilities() const;

    /**
     * Get market command capabilities.
     *
     * Return a set of features supported by a venue.
     *
     * @return                          Trading capabilities set
     */
    MarketCommandCapabilities GetMarketCommandCapabilities() const;

    /**
     * Get market data capabilities.
     *
     * @return                          Market data capabilities set
     */
    MarketDataCapabilities GetMarketDataCapabilities() const;

    /**
     * Get directed quote request capabilities.
     *
     * @return                          Directed quote request capabilities set
     */
    DirectedQuoteRequestCapabilities GetDirectedQuoteRequestCapabilities() const;

    /**
     * Get order price type.
     *
     * If the market is a Limit Orderbook market orders should either be of
     * "Limit" type which is standard Equity style or "VWAP" which means that
     * the expected average traded price should be the order price. This is
     * relevant when trading through levels.
     *
     * @return                          Order price type
     */
    OrderPriceType GetOrderPriceType() const;

    /**
     * Get order book type.
     *
     * @return                          Order book type
     */
    OrderBookType GetOrderBookType() const;

    /**
     * Check if venue is excluded from market data aggregation.
     *
     * @return                          Exclude from market data aggregation flag
     */
    bool IsExcludedFromMarketDataAggregation() const;

    /**
     * Get price rounding policy
     *
     * - None: there is no rounding (or it not specified)
     * - Fair: regardless of side fair rounding is defined as
     *      a. less than 0.5 -> 0.0 (downwards)
     *      b. greater than or equal to 0.5 -> 1.0 (upwards)
     * - Market: is always done in the venues favor, i.e. bids down, offers up.
     * - Bank: regardless of side Bank rounding is defined as in IEEE 754.
     *
     * @return                          Price rounding policy
     */
    RoundingPolicy GetRoundingPolicy() const;

    /**
     * Get venue instrument identifier structure.
     *
     * Return a set of venue keys with associated FIX tags
     *
     * @return                          Venue instrument identifier structure class
     */
    const VenueInstrumentIdentifierStructure & GetInstrumentIdentifierStructure() const;

    /**
     * Get venue latency statistics.
     *
     * Returns latency for specified MIC for the last 'event_window' events.
     * If 'event_window' parameter is empty, returns statistics for all stored data.
     * \n
     * Latency previously @p from timestamp aren't included.
     *
     *
     * @return                          true if data available, false otherwise
     */

    bool GetOrderToMarketLatency(const MIC & mic, const Integer & event_window, Percentiles & percentiles, const DateTime & from) const;

    /**
     * Get venue latency statistics.
     *
     * Returns latency for specified MIC for the last 'event_window' events.
     * If 'event_window' parameter is empty, returns statistics for all stored data.
     * \n
     *
     * @return                          true if data available, false otherwise
     */

    bool GetOrderToMarketLatency(const MIC & mic, const Integer & event_window, Percentiles & percentiles) const;

    /**
     * Check if venue is resolved.
     *
     * Venue is considered resolved if a venue is configured in the system,
     * that is, appropriate resource is available.
     *
     * @return                          "true" if venue information is
     *                                  resolved, "false" otherwise
     */
    bool IsResolved() const;

    /**
     * Check if venue is Matching Engine.
     *
     * Venue is considered matching if MarketData is provided from Matching Engine component
     *
     * @return                          "true" if venue if from Matching Engine
     *
     */
    bool IsMatchingEngineVenue() const;

    /**
     * Get LEI of venue
     *
     * @return                          LEI of venue. LEI can be empty if this information is not available.
     */
    LegalEntityIdentifier GetReceiverLEI() const;

    /**
     * Check if object is empty.
     *
     * Returns "true" if all object fields are empty, that is, even venue
     * identifier is not set. This happens if object was created with a default
     * constructor (and had never been assigned to with a non-empty one),
     * if it was cleared, or if it was assigned an empty value.
     *
     * @return                          "true" if object is empty, "false"
     *                                  otherwise
     */
    bool Empty() const override { return m_identifier.Empty(); }

    /**
     * Clear object.
     *
     * Invalidate all object's fields. After this call, Empty() method will
     * return "true", IsResolved() method will return "false".
     */
    void Clear();

public:
    bool operator==(const Venue & venue) const;
    bool operator!=(const Venue & venue) const;

    bool operator<(const Venue & venue) const;
    bool operator>(const Venue & venue) const;

    Uuid GetUuid() const;
    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_VENUE; }

protected:
    Venue(tbricks::venue::VenueInfo * information);

private:
    void Resolve();

    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    bool m_resolved;
    VenueIdentifier m_identifier;
    SafePointer<tbricks::venue::VenueInfo> m_venue;
    mutable SharedPointer<VenueInstrumentIdentifierStructure> m_venue_structure;
};
}

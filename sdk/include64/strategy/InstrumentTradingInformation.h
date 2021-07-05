#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentTradingInformation, provides additional instrument information
// required to trade on a given venue.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/TickRule.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/ComparisonResult.h"

// \namespace tbricks
namespace tbricks {

namespace protocol {
class InstrumentTradingInformation;
}

class Side;
class Price;
class Volume;
class Currency;

class STRATEGY_EXPORT InstrumentTradingInformation : public Printable
{
public:
    class Stream;

public:
    /**
     * Constructor.
     *
     * Constructs an empty object.
     */
    InstrumentTradingInformation();

    /**
     * Constructor.
     *
     * Constructs an object and immediately resolves it. If resolution
     * fails, object is left in empty state.
     */
    InstrumentTradingInformation(const InstrumentVenueIdentification & id, const LiquidityPoolIdentifier & pool_id = LiquidityPoolIdentifier());

    virtual ~InstrumentTradingInformation();

    /**
     * Resolve instrument trading information.
     *
     * Sets new instrument venue identifier for the object and synchronously
     * fetches all information available for the instrument from a venue.
     *
     * If called for already resolved object, this method clears its state
     * first, and if the call fails later on the object will be left in an
     * empty state.
     *
     * @param id                        Instrument venue identifier
     * @param pool_id                   Liquidity pool identifier
     *
     * @return                          'true' if the data is available,
     *                                  'false' otherwise
     */
    bool Resolve(const InstrumentVenueIdentification & id, const LiquidityPoolIdentifier & pool_id = LiquidityPoolIdentifier());

    /**
     * Get instrument venue identifier.
     *
     * Returns instrument venue identifier the object is associated with.
     *
     * @return                          Instrument venue identifier
     */
    const InstrumentVenueIdentification & GetInstrumentVenueIdentification() const;

    /**
     * Get liquidity pool identifier.
     *
     * @return                          Liquidity pool identifier
     */
    LiquidityPoolIdentifier GetLiquidityPoolIdentifier() const;

public:
    /**
     * Check object for emptiness.
     *
     * Object is considered empty if its data is not resolved.
     *
     * @return                          "true" if object is empty, "false"
     *                                  otherwise
     */
    bool Empty() const;

    /**
     * Clear object.
     *
     * Object is considered empty after this call.
     */
    void Clear();

public:
    /**
     * Get minimum price.
     *
     * The minimum price allowed for order entry.
     *
     * @return                          Minimum price or an empty value
     *                                  if object is not resolved or
     *                                  minimum price is not defined
     */
    Price GetMinPrice() const;

    /**
     * Get maxinun price.
     *
     * The maximum price allowed for order entry.
     *
     * @return                          Maximum price or an empty value
     *                                  if object is not resolved or
     *                                  maximum price is not defined
     */
    Price GetMaxPrice() const;

    /**
     * Get minimum match price.
     *
     * The minimum match price allowed for order entry.
     *
     * @return                          Minimum match price or an empty value
     *                                  if object is not resolved or
     *                                  minimum match price is not defined
     */
    Price GetMinMatchPrice() const;

    /**
     * Get maximum match price.
     *
     * The maximum match price allowed for order entry.
     *
     * @return                          Maximum match price or an empty value
     *                                  if object is not resolved or
     *                                  maximum match price is not defined
     */
    Price GetMaxMatchPrice() const;

    /**
     * Get minimum allowed price.
     *
     * The minimum price allowed for order entry.
     *
     * @return                          Minimum allowed price or an empty value
     *                                  if object is not resolved or
     *                                  minimum allowed price is not defined
     */
    Price GetMinAllowedPrice() const;

    /**
     * Get maximum allowed price.
     *
     * The maximum price allowed for order entry.
     *
     * @return                          Maximum allowed price or an empty value
     *                                  if object is not resolved or
     *                                  maximum allowed price is not defined
     */
    Price GetMaxAllowedPrice() const;

    /**
     * Get circuit breaker price.
     *
     * @return                          Circuit breaker price or an empty value
     *                                  if object is not resolved or
     *                                  circuit breaker price is not defined
     */
    Price GetCircuitBreakerPrice() const;

    /**
     * Get minimum volume.
     *
     * The minimum volume allowed for order entry.
     *
     * @return                          Minimum volume or an empty value
     *                                  if object is not resolved
     */
    Volume GetMinVolume() const;

    /**
     * Get minimum disclosed volume.
     *
     * The minimum disclosed volume allowed for order entry.
     *
     * @return                          Minimum disclosed volume or an empty value
     *                                  if object is not resolved
     */
    Volume GetMinDisclosedVolume() const;

    /**
     * Get volume increment.
     *
     * The volume allowed to enter for orders is valid in integral multiples of
     * the volume increment.
     *
     * NB this field used name LotSize in previous versions of API
     *
     * @return                          Volume increment or 1.0
     *                                  if object is not resolved
     */
    Volume GetVolumeIncrement() const;

    /**
     * Get lot volume.
     *
     * Volume limit where orders go into board-lot or even-lot orderbook (preferred liquidity pool normally),
     * orders with less volume trade in a separate orderbook (small-orders or odd-lot) under somewhat different rules
     * and/or uncrossing conditions. Executions between order books may occur during certain circumstances depending on
     * business rules.
     *
     * @return                          Lot volume or 1.0
     *                                  if object is not resolved
     */
    Volume GetLotVolume() const;

    /**
     * Is zero volume quote allowed.
     *
     * Is it allowed for quote to have zero volume.
     *
     * @return                          Is zero volume quote allowed or false
     *                                  if object is not resolved
     */
    bool IsZeroVolumeQuoteAllowed() const;

    /**
     * Round volume.
     * For example:
     * VolumeIncrement = 1.0
     * MinVolume = 1.0
     *
     * RoundVolume(-6.80688) = -7
     * RoundVolume(6.80688) = 7
     * RoundVolume(-6.8) = 7
     * RoundVolume(100.5) = 100
     * RoundVolume(-100) = -100
     * RoundVolume(-10) = -10
     * RoundVolume(-1) = -1
     * RoundVolume(100) = 100
     * RoundVolume(10) = 10
     * RoundVolume(1) = 1
     */
    Volume RoundVolume(const Volume & volume) const;

    /**
     * Round disclosedvolume.
     * For example:
     * VolumeIncrement = 1.0
     * MinDisclosedVolume = 10.0
     *
     * RoundDisclosedVolume(3.0) = 10.0
     */
    Volume RoundDisclosedVolume(const Volume & volume) const;

    /**
     * Round volume down.
     * For example:
     * VolumeIncrement = 1.0
     * MinVolume = 1.0
     *
     * RoundVolume(-6.80688) = -6
     * RoundVolume(6.80688) = 6
     * RoundVolume(-6.8) = 6
     * RoundVolume(100.5) = 100
     * RoundVolume(-100) = -100
     * RoundVolume(-10) = -10
     * RoundVolume(-1) = -1
     * RoundVolume(100) = 100
     * RoundVolume(10) = 10
     * RoundVolume(1) = 1
     */
    Volume RoundVolumeDown(const Volume & volume) const;

    Volume RoundVolumeUp(const Volume & volume) const;

    /**
     * Before comparing, both volumes are rounded depending on volume increment ITI's paramenter.
     *
     * example:
     * @code
     * Volume quotingVolume = 200;
     * Volume minVolume = 250;
     * // ITI's volume increment is 100
     * CompareVolumes(quotingVolume, minVolume); // == TB_EQUAL
     * @endcode
     * @return                                            #ComparisonResult
     */
    ComparisonResult CompareVolumes(Volume volume1, Volume volume2) const;

    /**
     * Comparison precision.
     */
    double GetPrecision() const;

    /**
     * Get currency.
     *
     * The currency as specified by the ISO 4217 standard.
     *
     * @return                          Currency or an empty value
     *                                  if object is not resolved
     */
    Currency GetCurrency() const;

    const TickRule & GetTickRule() const;

    /*  This indicates whether prices are to be sorted
     * normally
     * (i.e. buying at a low price is better than buying at a high price),
     * or reversed
     * (i.e. buying at a high price is better than buying at a low price)
     * Empty return value means the information is not resolved
     */

    bool IsPriceReversed() const;

    bool IsPriceBetter(const Side & side, const Price & p1, const Price & p2) const;

    /**
     * Buy orders rounded up and Sell orders rounded down
     *
     * @param side                      Side
     * @param p                         Price
     * @param make_better               If make_better is false, then Buy orders
     *                                  will be rounded down and Sell orders will
     *                                  be rounded up
     *
     * @return                          Rounded price
     */
    Price RoundPrice(const Side & side, const Price & p, bool make_better = true) const;

    /**
     * Rounding to the nearest
     *
     * @param side                      Side
     * @param p                         Price
     *
     * @return                          Rounded price
     */
    Price RoundPriceToNearest(const Side & side, const Price & p) const;

    /**
     * Round price by Venue::RoundingPolicy
     *
     * @param side                      Side
     * @param p                         Price
     * @param number_of_decimals        Precision
     *
     * @return                          Rounded price
     */
    Price RoundPriceByVenueRoundingPolicy(const Side & side, const Price & p, size_t number_of_decimals = 0) const;

    /**
     * Sometimes prices are not properly expressed on a venue, but rather in a convention that is not normalized and
     * that does not fit Tbricks at all. This factor describes how prices are converted by division on the inbound and
     * multiplication on the outbound from Tbricks. The data is normally used by the trading and market data services to
     * properly convert in and outgoing prices.
     *
     * @return                          Price correction factor or 1.0 if not set
     */
    double GetPriceCorrectionFactor() const;

    /**
     * Get minimum book or cancel volume.
     *
     * The minimum volume for orders with book-or-cancel price policy. Example is MinPOQty on Alpha.
     *
     * @return                          Lot volume or 1.0
     *                                  if object is not resolved
     */
    Volume GetMinimumBookOrCancelVolume() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    void resolve(const std::shared_ptr<protocol::InstrumentTradingInformation> & iti);

private:
    InstrumentVenueIdentification m_id;
    TickRule m_tick_rule;
    std::shared_ptr<protocol::InstrumentTradingInformation> m_msg;
};

} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeOptions.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Trade.h"
#include "strategy_generated/TestTradeOptionsBase.h"

namespace tbricks { namespace test {

class STRATEGY_EXPORT TradeOptions : public TestTradeOptionsBase
{
public:
    TradeOptions() = default;
    using TestTradeOptionsBase::TestTradeOptionsBase;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasInstrumentVenueIdentification() const;

    /**
     * %Set instrument venue identifier.
     *
     * @param ivid                      Instrument venue identifier
     */
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    /**
     * Get instrument venue identifier.
     *
     * @return                          Instrument venue identifier
     */
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasVenueInstrumentIdentifier() const;

    /**
     * Get venue instrument identifier.
     *
     * @return                          Venue instrument identifier
     */
    VenueInstrumentIdentifier GetVenueInstrumentIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasVenue() const;

    /**
     * Get venue.
     *
     * @return                          Venue object
     */
    Venue GetVenue() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasMIC() const;

    /**
     * Get market identification code.
     *
     * @return                          Market identification code
     */
    MIC GetMIC() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasGrossTradeAmount() const;

    /**
     * %Set gross trade amount.
     *
     * @param value                     Gross trade amount
     */
    void SetGrossTradeAmount(const Double & value);

    /**
     * Get gross trade amount.
     *
     * The gross trade amount in actual cash for a trade.
     *
     * @return                          Gross trade amount
     */
    Double GetGrossTradeAmount() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasQuoteMode() const;

    /**
     * %Set quote mode.
     *
     * @param value                     New value
     */
    void SetQuoteMode(QuoteMode value);

    /**
     * Get quote mode.
     *
     * @return                          Quote mode value
     */
    QuoteMode GetQuoteMode() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasUniqueTradeIdentifier() const;

    /**
     * %Set UTI.
     *
     * If UTI argument is not valid, an exception is thrown.
     *
     * @param uti                       UTI
     */
    void SetUniqueTradeIdentifier(const UniqueTradeIdentifier & uti);

    /**
     * Get UTI.
     *
     * @return                          UTI
     */
    UniqueTradeIdentifier GetUniqueTradeIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasLiquiditySource() const;

    /**
     * %Set liquidity source.
     *
     * @param value                     liquidity source
     */
    void SetLiquiditySource(const LiquiditySource & value);

    /**
     * Get liquidity source.
     *
     * @return                          liquidity source
     */
    LiquiditySource GetLiquiditySource() const;
};

} // \namespace test

} // \namespace tbricks

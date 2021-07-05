#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Market Model Typology.
//****************************************************************************************

#include <memory>
#include <vector>
#include "strategy/Printable.h"

namespace tbricks { namespace types {
struct MMTFlag;
}}

namespace tbricks {

/**
 *  MMTFlag provides a description of a Market Model Typology value unit.
 */
class STRATEGY_EXPORT MMTFlag
{
public:
    MMTFlag & operator=(const tbricks::types::MMTFlag & other);

    /*
     *  All possible flags as flat structure since they can move around.
     */
    enum Value
    {
        CentralLimitOrderBook = 1,
        QuoteDrivenMarket = 2,
        DarkOrderBook = 3,
        OffBook = 4,
        UndefinedAuction = 5,
        ScheduledOpeningAuction = 6,
        ScheduledClosingAuction = 7,
        ScheduledIntradayAuction = 8,
        UnscheduledAuction = 9,
        ContinuousTrading = 10,
        AtMarketCloseTrading = 11,
        OutOfMainSessionTrading = 12,
        TradeReportingOnExchange = 13,
        TradeReportingOffExchange = 14,
        TradeReportingSystematicInternalizer = 15,
        PlainVanillaTrade = 16,
        DarkTrade = 17,
        TechnicalTrade = 18,
        GiveUpGiveInTrade = 19,
        TradeWithConditions = 20,
        NegotiatedTrade = 21,
        NoNegotiatedTrade = 22,
        CrossingTrade = 23,
        NoCrossingTrade = 24,
        TradeCancellation = 25,
        TradeAmendment = 26,
        NewTrade = 27,
        BenchmarkTrade = 28,
        NoBenchmarkTrade = 29,
        ExCumDividendTrade = 30,
        NoExCumDividendTrade = 31,
        UnspecifiedOrDoesNotApply = 32,
        OffBookNonAutomated = 33,
        OffBookAutomated = 34,
        ImmediatePublication = 35,
        NonImmediatePublication = 36,
        PeriodicAuction = 37,
        TradeThatHasReceivedPriceImprovement = 38,
        PackageTrade = 39,
        ExchangeForPhysicalsTrade = 40,
        NoneApplyAStandardTradeForTheMarketMechanismAndTradingMode = 41,
        NegotiatedTradeInLiquidFinancialInstruments = 42,
        NegotiatedTradeInIlliquidFinancialInstruments = 43,
        NegotiatedTradeSubjectToConditionsOtherThanTheCurrentMarketPrice = 44,
        PreTradeTransparencyWaiverForIlliquidInstrumentOnAnSI = 45,
        PreTradeTransparencyWaiverForAboveStandardMarketSizeOnAnSI = 46,
        ReferencePriceTrade = 47,
        NonPriceFormingTrade = 48,
        TradeNotContributingToThePriceDiscoveryProcess = 49,
        AlgorithmicTrade = 50,
        NoAlgorithmicTrade = 51,
        NonImmediatePublicationDeferralForLargeInScale = 52,
        NonImmediatePublicationDeferralForIlliquidInstrument = 53,
        NonImmediatePublicationDeferralForSizeSpecific = 54,
        LimitedDetailsTrade = 55,
        DailyAggregatedTrade = 56,
        VolumeOmissionTrade = 57,
        FourWeeksAggregationTrade = 58,
        IndefiniteAggregationTrade = 59,
        VolumeOmissionTradeEligibleForSubsequentEnrichmentInAggregatedForm = 60,
        FullDetailsOfEarlierLMTF = 61,
        FullDetailsOfEarlierDATF = 62,
        FullDetailsOfEarlierVOLO = 63,
        FullDetailsOfEarlierFWAF = 64,
        FullDetailsInAggregatedFormOfEarlierVOLW = 65,
        NotApplicableNoRelevantDeferralOrEnrichmentType = 66,
        UniqueTradeReport = 67,
        DuplicativeTradeReport = 68,
        AnyOther_IncludingHybrid = 69,
        SpecialDividendTrade = 70,
        NoSpecialDividendTrade = 71,
        PriceIsCurrentlyNotAvailableButPending = 72,
        RequestForQuotes = 73,
        PreTradeTransparencyWaiversOfILQDAndSIZE = 74,
        NonImmediatePublicationDeferralsOfILQDAndSIZE = 75,
        NonImmediatePublicationDeferralsOfILQDAndLRGS = 76,
    };

    /**
     * Get MMT flag friendly name.
     *
     * Returns full flag name, e.g. "Dark Order Book".
     * You may use this to display MMT flags in app.
     *
     * @return                          Flag name if it is available,
     *                                  an empty value otherwise
     */
    String GetName() const;

    /**
     * Get MMT flag display code.
     *
     * Returns flag display code, e.g. "DB" for "Dark Order Book".
     * You may use this to display MMT flags in app.
     *
     * @return                          Flag display code if it is available,
     *                                  an empty value otherwise
     */
    String GetDisplayCode() const;

    /**
     * Get MMT physical code.
     *
     * Returns flag display code, e.g. '3' for "Dark Order Book".
     * Use this thing to send out to other systems, e.g. FIX.
     *
     * @return                          Flag physical code
     */
    char GetPhysicalCode() const;

    Value GetValue() const;

    bool operator==(const MMTFlag & other) const;
    bool operator!=(const MMTFlag & other) const;

private:
    friend STRATEGY_EXPORT class MMTFlags;
    friend inline bool convert(const std::vector<types::MMTFlag> & from, std::vector<MMTFlag> & to);
    MMTFlag(const tbricks::types::MMTFlag & flag);

    const char * m_name;
    const char * m_display_code;
    char m_physical_code;
    Value value;
};

STRATEGY_EXPORT
bool operator==(const std::vector<MMTFlag> & v1, const std::vector<MMTFlag> & v2);

STRATEGY_EXPORT
bool operator!=(const std::vector<MMTFlag> & v1, const std::vector<MMTFlag> & v2);

} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Market Model Typology version 3.04.
//****************************************************************************************

#include "strategy/type/MMTFlags.h"

namespace tbricks {
namespace types {
class MMTFlags;
}

//****************************************************************************
// MMTFlags_3_04 Class
//****************************************************************************

/**
 * MMTFlags_3_04  Market Model Typology flags version 3.04.
 * See MMTFlags
 */
class STRATEGY_EXPORT MMTFlags_3_04
{
public:
    MMTFlags_3_04();
    MMTFlags_3_04(const MMTFlags_3_04 & other);
    MMTFlags_3_04 & operator=(const MMTFlags_3_04 & other);

    MMTFlags_3_04(MMTFlags_3_04 &&) noexcept;
    MMTFlags_3_04 & operator=(MMTFlags_3_04 &&) noexcept;

    ~MMTFlags_3_04() noexcept;

    operator MMTFlags() const;
    MMTFlags GetFlags() const;

    enum AlgorithmicIndicator : char
    {
        AlgorithmicTrade = 'H',
        NoAlgorithmicTrade = '-',
    };

    enum OrdinaryTradesOrTradesOutsidePriceDiscoveryProcess : char
    {
        PlainVanillaTrade = 'P',
        NonPriceFormingTrade = 'T',
        TradeNotContributingToThePriceDiscoveryProcess = 'J',
        PriceIsCurrentlyNotAvailableButPending = 'N',
    };

    enum TransactionCategory : char
    {
        DarkTrade = 'D',
        TradeThatHasReceivedPriceImprovement = 'R',
        PackageTrade = 'Z',
        ExchangeForPhysicalsTrade = 'Y',
        NoneApplyAStandardTradeForTheMarketMechanismAndTradingMode = '-',
    };

    enum NegotiatedTransactionIndicator : char
    {
        NegotiatedTrade = 'N',
        NegotiatedTradeInLiquidFinancialInstruments = '1',
        NegotiatedTradeInIlliquidFinancialInstruments = '2',
        NegotiatedTradeSubjectToConditionsOtherThanTheCurrentMarketPrice = '3',
        NoNegotiatedTrade = '-',
        PreTradeTransparencyWaiverForIlliquidInstrumentOnAnSI = '4',
        PreTradeTransparencyWaiverForAboveStandardMarketSizeOnAnSI = '5',
        PreTradeTransparencyWaiversOfILQDAndSIZE = '6',
    };

    enum PostTradeDeferralOrEnrichment : char
    {
        LimitedDetailsTrade = '1',
        DailyAggregatedTrade = '2',
        VolumeOmissionTrade = '3',
        FourWeeksAggregationTrade = '4',
        IndefiniteAggregationTrade = '5',
        VolumeOmissionTradeEligibleForSubsequentEnrichmentInAggregatedForm = '6',
        FullDetailsOfEarlierLMTF = '7',
        FullDetailsOfEarlierDATF = '8',
        FullDetailsOfEarlierVOLO = '9',
        FullDetailsOfEarlierFWAF = 'V',
        FullDetailsInAggregatedFormOfEarlierVOLW = 'W',
        NotApplicableNoRelevantDeferralOrEnrichmentType = '-',
    };

    enum BenchmarkIndicator : char
    {
        BenchmarkTrade = 'B',
        ReferencePriceTrade = 'S',
        NoBenchmarkTrade = '-',
    };

    enum PublicationMode : char
    {
        ImmediatePublication = '-',
        NonImmediatePublication = '1',
        NonImmediatePublicationDeferralForLargeInScale = '2',
        NonImmediatePublicationDeferralForIlliquidInstrument = '3',
        NonImmediatePublicationDeferralForSizeSpecific = '4',
        NonImmediatePublicationDeferralsOfILQDAndSIZE = '5',
        NonImmediatePublicationDeferralsOfILQDAndLRGS = '6',
    };

    enum DuplicativeIndicator : char
    {
        UniqueTradeReport = '-',
        DuplicativeTradeReport = '1',
    };

    enum CrossingTradeIndicator : char
    {
        CrossingTrade = 'X',
        NoCrossingTrade = '-',
    };

    enum TradingMode : char
    {
        UndefinedAuction = '1',
        ScheduledOpeningAuction = 'O',
        ScheduledClosingAuction = 'K',
        ScheduledIntradayAuction = 'I',
        UnscheduledAuction = 'U',
        ContinuousTrading = '2',
        AtMarketCloseTrading = '3',
        OutOfMainSessionTrading = '4',
        TradeReportingOnExchange = '5',
        TradeReportingOffExchange = '6',
        TradeReportingSystematicInternalizer = '7',
    };

    enum SpecialDividendIndicator : char
    {
        SpecialDividendTrade = 'E',
        NoSpecialDividendTrade = '-',
    };

    enum ModificationIndicator : char
    {
        TradeCancellation = 'C',
        TradeAmendment = 'A',
        NewTrade = '-',
    };

    enum OffBookAutomatedIndicator : char
    {
        UnspecifiedOrDoesNotApply = '-',
        OffBookNonAutomated = 'M',
        OffBookAutomated = 'Q',
    };

    enum MarketMechanism : char
    {
        CentralLimitOrderBook = '1',
        QuoteDrivenMarket = '2',
        DarkOrderBook = '3',
        OffBook = '4',
        PeriodicAuction = '5',
        RequestForQuotes = '6',
        AnyOther_IncludingHybrid = '7',
    };

    MMTFlags_3_04 & SetAlgorithmicIndicator(AlgorithmicIndicator flag);
    MMTFlags_3_04 & SetOrdinaryTradesOrTradesOutsidePriceDiscoveryProcess(OrdinaryTradesOrTradesOutsidePriceDiscoveryProcess flag);
    MMTFlags_3_04 & SetTransactionCategory(TransactionCategory flag);
    MMTFlags_3_04 & SetNegotiatedTransactionIndicator(NegotiatedTransactionIndicator flag);
    MMTFlags_3_04 & SetPostTradeDeferralOrEnrichment(PostTradeDeferralOrEnrichment flag);
    MMTFlags_3_04 & SetBenchmarkIndicator(BenchmarkIndicator flag);
    MMTFlags_3_04 & SetPublicationMode(PublicationMode flag);
    MMTFlags_3_04 & SetDuplicativeIndicator(DuplicativeIndicator flag);
    MMTFlags_3_04 & SetCrossingTradeIndicator(CrossingTradeIndicator flag);
    MMTFlags_3_04 & SetTradingMode(TradingMode flag);
    MMTFlags_3_04 & SetSpecialDividendIndicator(SpecialDividendIndicator flag);
    MMTFlags_3_04 & SetModificationIndicator(ModificationIndicator flag);
    MMTFlags_3_04 & SetOffBookAutomatedIndicator(OffBookAutomatedIndicator flag);
    MMTFlags_3_04 & SetMarketMechanism(MarketMechanism flag);

private:
    std::unique_ptr<types::MMTFlags> m_impl;
};

} // \namespace tbricks

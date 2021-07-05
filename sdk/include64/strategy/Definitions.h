#pragma once

// Copyright 2020 Itiviti Group All rights reserved.
// Reproduction in whole or in part in any form or medium without express
// written permission of Itiviti Group is strictly prohibited.
//
// This is an automated-generated file. Please do not edit it manually.
// Use Front-end to edit metadata
//

#ifndef USE_FAKE_API
#include "strategy/Types.h"
#include "strategy/Linkage.h"
#include "strategy/pricing/InstrumentCalculatedValueDefinition.h"
#endif //USE_FAKE_API

namespace tbricks {

namespace tree_types {

/// Tree type "Flow routing configuration", description ""
inline tbricks::TreeTypeIdentifier FlowRoutingConfiguration()
{
    // Identifier: "03477750-1572-11e7-9750-4431706ddf95"
    // Name: "Flow routing configuration"
    // Description: ""
    tbricks::TreeTypeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe711721550774703ULL, 0x95df6d7031445097ULL));
    return pd;
}

/// Tree type "App template", description "Tree nodes containing app parameters, extra data and other properties"
inline tbricks::TreeTypeIdentifier AppTemplate()
{
    // Identifier: "0e2f1cf0-f2c4-11e8-9a70-996b89306ec8"
    // Name: "App template"
    // Description: "Tree nodes containing app parameters, extra data and other properties"
    tbricks::TreeTypeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe811c4f2f01c2f0eULL, 0xc86e30896b99709aULL));
    return pd;
}

/// Tree type "Flow apps configuration", description ""
inline tbricks::TreeTypeIdentifier FlowAppsConfiguration()
{
    // Identifier: "0e577dac-1572-11e7-8be0-395ccad5aee0"
    // Name: "Flow apps configuration"
    // Description: ""
    tbricks::TreeTypeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe7117215ac7d570eULL, 0xe0aed5ca5c39e08bULL));
    return pd;
}

/// Tree type "Orc Client", description ""
inline tbricks::TreeTypeIdentifier OrcClient()
{
    // Identifier: "1d404ab8-5c0f-11e7-b149-be84e16cd6ae"
    // Name: "Orc Client"
    // Description: ""
    tbricks::TreeTypeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe7110f5cb84a401dULL, 0xaed66ce184be49b1ULL));
    return pd;
}

/// Tree type "Event type", description "Tree node type for defining a type of an event in the system"
inline tbricks::TreeTypeIdentifier EventType()
{
    // Identifier: "c0f04b04-c252-11e8-8a30-05194b27cb6f"
    // Name: "Event type"
    // Description: "Tree node type for defining a type of an event in the system"
    tbricks::TreeTypeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe81152c2044bf0c0ULL, 0x6fcb274b1905308aULL));
    return pd;
}

/// Tree type "Role", description ""
inline tbricks::TreeTypeIdentifier Role()
{
    // Identifier: "c59bf87a-1569-11e7-b2c0-89ec0344d8b6"
    // Name: "Role"
    // Description: ""
    tbricks::TreeTypeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe71169157af89bc5ULL, 0xb6d84403ec89c0b2ULL));
    return pd;
}

/// Tree type "Client", description ""
inline tbricks::TreeTypeIdentifier Client()
{
    // Identifier: "d3e2751c-1569-11e7-8710-d8c12ed7b49a"
    // Name: "Client"
    // Description: ""
    tbricks::TreeTypeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe71169151c75e2d3ULL, 0x9ab4d72ec1d81087ULL));
    return pd;
}

/// Tree type "Investment decision", description ""
inline tbricks::TreeTypeIdentifier InvestmentDecision()
{
    // Identifier: "e2df0e1e-946b-11e7-b2ae-06b747deb312"
    // Name: "Investment decision"
    // Description: ""
    tbricks::TreeTypeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe7116b941e0edfe2ULL, 0x12b3de47b706aeb2ULL));
    return pd;
}

/// Tree type "Counterpart", description ""
inline tbricks::TreeTypeIdentifier Counterpart()
{
    // Identifier: "f17b4ae8-8905-11e8-945d-0c3e99245e0d"
    // Name: "Counterpart"
    // Description: ""
    tbricks::TreeTypeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe8110589e84a7bf1ULL, 0xd5e24993e0c5d94ULL));
    return pd;
}

}

enum InterestRateCompoundingBasis
{
    ///< Item 0
    InterestRateCompoundingBasisContinuous = 0,
    ///< Item 1
    InterestRateCompoundingBasisAnnual = 1,
    ///< Item 2
    InterestRateCompoundingBasisSemiAnnual = 2,
    ///< Item 3
    InterestRateCompoundingBasisQuarterly = 3,
    ///< Item 4
    InterestRateCompoundingBasisMonthly = 4,
    ///< Item 5
    InterestRateCompoundingBasisSimple = 5
};

inline tbricks::Identifier InterestRateCompoundingBasisEnumerationIdentifier()
{
    // Identifier: "04b99e0e-de16-11e0-92b3-870c3e99245e"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe01116de0e9eb904ULL, 0x5e24993e0c87b392ULL));
    return pd;
}

enum PlugInStateAfterPanicStop
{
    PlugInStateAfterPanicStopSame = 0,
    PlugInStateAfterPanicStopPaused = 1,
    PlugInStateAfterPanicStopRunning = 2,
    PlugInStateAfterPanicStopDeleted = 3
};

inline tbricks::Identifier PlugInStateAfterPanicStopEnumerationIdentifier()
{
    // Identifier: "179d595b-2577-11e0-a68b-870c3e99245e"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe01177255b599d17ULL, 0x5e24993e0c878ba6ULL));
    return pd;
}

enum VolumeIncreaseBehavior
{
    ///< Defer volume increases until the price changes to preserve priority
    VolumeIncreaseBehaviorKeepPriority = 0,
    ///< Increase volumes immediately
    VolumeIncreaseBehaviorKeepVolumes = 1
};

inline tbricks::Identifier VolumeIncreaseBehaviorEnumerationIdentifier()
{
    // Identifier: "1d1d4c90-bbd9-11e3-884d-e9ebb3a6db3c"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe311d9bb904c1d1dULL, 0x3cdba6b3ebe94d88ULL));
    return pd;
}

enum QuoteOperation
{
    ///< Quote set run request.
    QuoteOperationQuoteSetRunRequest = 0,
    ///< Quote set pause request.
    QuoteOperationQuoteSetPauseRequest = 1,
    ///< Quote set delete request.
    QuoteOperationQuoteSetDeleteRequest = 2,
    ///< Quote set modify request.
    QuoteOperationQuoteSetModifyRequest = 3,
    ///< Quote table modify request.
    QuoteOperationQuoteTableModifyRequest = 4,
    ///< Quote table set active request.
    QuoteOperationQuoteTableSetActiveRequest = 5
};

inline tbricks::Identifier QuoteOperationEnumerationIdentifier()
{
    // Identifier: "1e7e05fe-9d4b-11e3-b2ae-06b747deb312"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe3114b9dfe057e1eULL, 0x12b3de47b706aeb2ULL));
    return pd;
}

enum InstrumentParameterScopeType
{
    ///< Use existing scope
    InstrumentParameterScopeTypeUseExistingScope = 0,
    ///< Shared
    InstrumentParameterScopeTypeShared = 1,
    ///< User
    InstrumentParameterScopeTypeUser = 2,
    ///< Shared in current portfolio
    InstrumentParameterScopeTypeSharedInCurrentPortfolio = 3,
    ///< User in shared portfolio
    InstrumentParameterScopeTypeUserInCurrentPortfolio = 4
};

inline tbricks::Identifier InstrumentParameterScopeTypeEnumerationIdentifier()
{
    // Identifier: "204d6f7c-2d8b-11e2-9b1c-47deb3124dc8"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe2118b2d7c6f4d20ULL, 0xc84d12b3de471c9bULL));
    return pd;
}

enum SortingOrder
{
    SortingOrderNormal = 1,
    SortingOrderReversed = 2
};

inline tbricks::Identifier SortingOrderEnumerationIdentifier()
{
    // Identifier: "224cfce7-397f-47be-bc71-002d29e22f2b"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xbe477f39e7fc4c22ULL, 0x2b2fe2292d0071bcULL));
    return pd;
}

enum QuoteMode
{
    ///< Quoting.
    QuoteModeQuoting = 0,
    ///< Quoting multi-level
    QuoteModeQuotingMultiLevel = 1,
    ///< Hidden
    QuoteModeHidden = 2,
    ///< Peg
    QuoteModePeg = 3,
    ///< The quote is a reply to a quote request.
    QuoteModeQuoteResponder = 4
};

inline tbricks::Identifier QuoteModeEnumerationIdentifier()
{
    // Identifier: "2b8d1503-c9b5-11e1-a499-6cd6ae529049"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe111b5c903158d2bULL, 0x499052aed66c99a4ULL));
    return pd;
}

enum OrderTransactionState
{
    ///< The transaction has not yet reached any consistent state but is pending towards the venue or further down service.
    OrderTransactionStatePending = 1,
    ///< Transaction is ok in a state with full integrity.
    OrderTransactionStateOK = 2,
    ///< Transaction has failed but is in a state with full integrity.
    OrderTransactionStateFail = 3
};

inline tbricks::Identifier OrderTransactionStateEnumerationIdentifier()
{
    // Identifier: "2cfd0463-5ec4-4c93-8e6c-bdf50218a03e"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x934cc45e6304fd2cULL, 0x3ea01802f5bd6c8eULL));
    return pd;
}

enum ExpitType
{
    ///< Bilateral interbank trade report.
    ExpitTypeInterbank = 0,
    ///< Unilateral trade report.
    ExpitTypeTradeReport = 1,
    ///< Very large trade report.
    ExpitTypeBlock = 2,
    ///< Trade report when the instigator is both bower and seller.
    ExpitTypeCross = 3,
    ///< Accept a direct request for trade.
    ExpitTypeAccept = 4,
    ///< Guaranteed cross.
    ExpitTypeGuaranteedCross = 5,
    ///< Post-trade publication used to report off-exchange trades to e.g. APA. Both sides should be filled by reporter.
    ExpitTypePublication = 6
};

inline tbricks::Identifier ExpitTypeEnumerationIdentifier()
{
    // Identifier: "38f9af16-cc34-11e2-8bbb-23be84e16cd6"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe21134cc16aff938ULL, 0xd66ce184be23bb8bULL));
    return pd;
}

enum ExpitRegulation
{
    ///< Expit done under no particular regulation.
    ExpitRegulationUndefined = 0,
    ///< Expit is done outside spread or on irregular price.
    ExpitRegulationOffPrice = 1,
    ///< Expit is done under special requirements with price deviating significant or other irregularities.
    ExpitRegulationExchangeGranted = 2,
    ///< Expit is done outside normal trading hours or during odd trading phases.
    ExpitRegulationOffHours = 3,
    ///< Unusually large expit, subject to exchange-specific regulation.
    ExpitRegulationLarge = 4,
    ///< A trade that deviates from the standard settlement and delivery period.
    ExpitRegulationNonStandardSettlement = 5,
    ///< Exercise or expiration of options, forwards or futures contracts that imply an exchange of Instruments or a Trade that relates to a derivatives Trade and that forms an unconditional part of a combination together with a derivative Trade.
    ExpitRegulationDerivativeRelatedTransaction = 6,
    ///< A transaction in more than one Instrument where those Instruments are grouped and traded as a single lot against a specific reference price. The reporting of the portfolio trade should be executed when the final leg of the transaction is completed.
    ExpitRegulationPortfolioTrade = 7
};

inline tbricks::Identifier ExpitRegulationEnumerationIdentifier()
{
    // Identifier: "39daf49e-479f-11e3-897d-e9ebb3a6db3c"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe3119f479ef4da39ULL, 0x3cdba6b3ebe97d89ULL));
    return pd;
}

enum DeliveryType
{
    ///< The instrument yields a cash delivery.
    DeliveryTypeCashDelivery = 0,
    ///< The instruments yields a physical delivery of the underlying instrument.
    DeliveryTypePhysicalDelivery = 1
};

inline tbricks::Identifier DeliveryTypeEnumerationIdentifier()
{
    // Identifier: "43a2adc4-58fb-4802-a7bb-1267cdec6503"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x248fb58c4ada243ULL, 0x365eccd6712bba7ULL));
    return pd;
}

enum CashType
{
    ///< Dividend payout from equity instrument.
    CashTypeDividend = 1,
    ///< Fee received or paid.
    CashTypeFee = 2,
    ///< Margin deposit.
    CashTypeMargin = 3,
    ///< The cash position is due to a cash delivery of e.g. an option.
    CashTypeCashDelivery = 4,
    ///< Proceeds from financing position or cash balance.
    CashTypeFinancing = 5,
    ///< A deposit or withdrawal of money into/from the portfolio. The sign of the volume signifies which.
    CashTypeDepositOrWithdrawal = 6,
    ///< A manual correction of the portfolios cash position.
    CashTypeCorrection = 7,
    ///< Part of a F/X trade.
    CashTypeFX = 8,
    ///< Change in cash balance driven by external system.
    CashTypePositionAdjustment = 9,
    ///< Coupon payout from fixed income instrument.
    CashTypeCoupon = 10,
    ///< Proceeds from lending a security.
    CashTypeLending = 11
};

inline tbricks::Identifier CashTypeEnumerationIdentifier()
{
    // Identifier: "458e89cb-cca2-4598-b98b-4a07ff15114b"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x9845a2cccb898e45ULL, 0x4b1115ff074a8bb9ULL));
    return pd;
}

enum StrategyValidityType
{
    ///< The order will never reside in the orderbook, but will be checked for matching and any residual volume will after matching be momentarily cancelled. A strategy is executed once.
    StrategyValidityTypeImmediate = 1,
    ///< The order will be valid until cancelled or until the instrument is no longer valid. An instrument that is no longer valid can be an expired derivative or a stock that is de-listed.
    StrategyValidityTypeInfinite = 2,
    ///< The order is valid until the current trading day is over. This is almost always supported by the venue itself.
    StrategyValidityTypeToday = 3,
    ///< The order is valid until and including this date.
    StrategyValidityTypeUntilDate = 4,
    ///< The order is valid until specified time has elapsed. This is almost always a synthetic type that needs to be implemented in the target trading service itself. If not implemented or supported, return an error on attempt to enter an order with this validity.
    StrategyValidityTypeUntilElapsedTime = 5,
    ///< The order gets activated and during the opening phase of the instrument. If no price is defined, the order is a market on open order, guaranteeing the opening price or better. If the price is defined, they will execute only if the price limit is met regarding opening price. Few exchanges support limit orders on open.
    StrategyValidityTypeImmediateOnOpen = 6,
    ///< The same order as above but it will get executed on the closing phase of the instrument. Closing phases may be more complicated and include more than one matching cycle, the behaviour is highly venue specific. Disregarding the venue semantics, the price will always be better than or equal to closing price or limit price if specified. Few exchanges support limit orders on open.
    StrategyValidityTypeImmediateOnClose = 7,
    ///< The entity is valid up until and including this date and time.
    StrategyValidityTypeUntilDatetime = 8,
    ///< The entity is valid only during the intraday auction phase of the instrument. If no price is defined, the order is a market on open order for the intraday auction, guaranteeing the actual auction price or better. If the price is defined, they will execute only if the price limit is met regarding actual auction price. Few exchanges support limit on auction.
    StrategyValidityTypeImmediateOnAuction = 9,
    ///< Only valid for the last auction phase, will normally close at the auction-price but limit price is sometimes allowed.
    StrategyValidityTypeLastAuction = 10,
    ///< Allows order to participate in liquidity matching of ongoing (guaranteed)cross / bilaterally reported expit.
    StrategyValidityTypeUntilUncross = 11
};

inline tbricks::Identifier StrategyValidityTypeEnumerationIdentifier()
{
    // Identifier: "482f753e-3ee8-463d-9723-1a427022aa43"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x3d46e83e3e752f48ULL, 0x43aa2270421a2397ULL));
    return pd;
}

enum FractionDisplayConvention
{
    ///< Use only digits (without any special symbols) to represent fractions.
    FractionDisplayConventionDigit = 0,
    ///< Use special symbols like ½ to represent fractions.
    FractionDisplayConventionSymbol = 1
};

inline tbricks::Identifier FractionDisplayConventionEnumerationIdentifier()
{
    // Identifier: "488857ba-655b-11e2-83c8-3e99245e0d1c"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe2115b65ba578848ULL, 0x1c0d5e24993ec883ULL));
    return pd;
}

enum InstrumentTradingPhase
{
    ///< Phase prior to opening with limited interaction and visibility, no matching (same meaning as "Pre trading")
    InstrumentTradingPhasePreOpen = 0,
    ///< Transition phase to commence regular trading, possibly with limited interaction and visibility, matching occurs.
    InstrumentTradingPhaseOpening = 1,
    ///< Transition phase to commence regular trading by using an auction.
    InstrumentTradingPhaseOpeningAuction = 2,
    ///< Phase for normal trading (also called continuous or regular trading).
    InstrumentTradingPhaseTrading = 3,
    ///< Unscheduled temporary interruption of regular trading to conduct an auction, typically a result of exchange circuit breaker or resuming trading after.
    InstrumentTradingPhaseUnscheduledIntradayAuction = 4,
    ///< @deprecated Deprecated in 2.14.3, use InstrumentTradingPhaseUnscheduledIntradayAuction
    InstrumentTradingPhaseIntradayAuction = 4,
    ///< Phase prior to closing with limited interaction and visibility, no matching.
    InstrumentTradingPhasePreClose = 5,
    ///< Transition phase to end regular trading, possibly with limited interaction and visibility, matching occurs.
    InstrumentTradingPhaseClosing = 6,
    ///< Transition phase to end regular trading by using an auction.
    InstrumentTradingPhaseClosingAuction = 7,
    ///< Transition phase to end regular trading, possibly with limited interaction and visibility, matching occurs only on last.
    InstrumentTradingPhaseLastAuction = 8,
    ///< Phase after closing with limited interaction and visibility, no matching.
    InstrumentTradingPhasePostTrading = 9,
    ///< Market closed.
    InstrumentTradingPhaseClosed = 10,
    ///< Market halted, technical reasons normally, no interaction or matching.
    InstrumentTradingPhaseHalted = 11,
    ///< Normal phase suspended due to regulatory reasons, limited interaction and no matching.
    InstrumentTradingPhaseSuspended = 12,
    ///< Accelerated trading, different matching, different trading rules and reduced visibility.
    InstrumentTradingPhaseFast = 13,
    ///< Unknown market phase, only set when there is lack of information or N/A status.
    InstrumentTradingPhaseUnknown = 14,
    ///< Buyback status of issuer managed derivatives, restrictions on orders and quotes may apply.
    InstrumentTradingPhaseBuyBack = 15,
    ///< Continuous auction.
    InstrumentTradingPhaseContinuousAuction = 16,
    ///< Scheduled temporary interruption of regular trading to conduct an auction.
    InstrumentTradingPhaseScheduledIntradayAuction = 17
};

inline tbricks::Identifier InstrumentTradingPhaseEnumerationIdentifier()
{
    // Identifier: "56bc6006-4699-11e1-933b-245e0d1c06b7"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe11199460660bc56ULL, 0xb7061c0d5e243b93ULL));
    return pd;
}

enum StrategySide
{
    StrategySideBuy = 1,
    StrategySideSell = 2,
    StrategySideShortSell = 3
};

inline tbricks::Identifier StrategySideEnumerationIdentifier()
{
    // Identifier: "5bd1b7a3-3e56-4c21-a53b-a2e77a650b76"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x214c563ea3b7d15bULL, 0x760b657ae7a23ba5ULL));
    return pd;
}

enum PositionAggregation
{
    ///< Aggregation over available fields, portfolio identifier, instrument identifier, currency, VIID and settlement date. Most detailed style of aggregation.
    PositionAggregationPositionsByCurrency_44_SettlementAndVenue = 1,
    ///< Aggregation over portfolio identifier and instrument identifier only. Used for total volumes only, gross trade amount have no semantic meaning in this context.
    PositionAggregationPositions = 2,
    ///< Aggregation over portfolio identifier, instrument identifier, currency and settlement date. Used to see your oncoming cashflow in different currencies on instrument level.
    PositionAggregationPositionsByCurrencyAndSettlement = 3,
    ///< Aggregation over portfolio identifier, instrument identifier and currency. Used to see your oncoming cashflow in different currencies on instrument level.
    PositionAggregationPositionsByCurrency = 5,
    ///< Aggregation over instrument and market
    PositionAggregationPositionsByInstrumentAndMarket = 6
};

inline tbricks::Identifier PositionAggregationEnumerationIdentifier()
{
    // Identifier: "5f761e92-1513-4c9d-9d76-ff0c3328eb1e"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x9d4c1315921e765fULL, 0x1eeb28330cff769dULL));
    return pd;
}

enum ServiceClass
{
    ServiceClassX_RayEngine = 0,
    ServiceClassInstrument = 1,
    ServiceClassMarketData = 2,
    ServiceClassMetadata = 3,
    ServiceClassOrderPersistence = 4,
    ServiceClassInstrumentReferenceData = 6,
    ServiceClassStrategyEngine = 7,
    ServiceClassTradePersistence = 9,
    ServiceClassTrading = 10,
    ServiceClassX_RayPersistence = 11,
    ServiceClassMarketPlace = 12,
    ServiceClassIntegration = 14,
    ServiceClassSMS = 15,
    ServiceClassTradingReferenceData = 16,
    ServiceClassTimeSeries = 17,
    ServiceClassReplay = 18,
    ServiceClassCalculationEngine = 19,
    ServiceClassLimitEngine = 20,
    ServiceClassAccessoryEngine = 21,
    ServiceClassQuote = 23,
    ServiceClassRequestForQuote = 24,
    ServiceClassQuoteRequest = 25,
    ServiceClassExpitTrading = 26,
    ServiceClassIntegrationEngine = 27,
    ServiceClassFlowEngine = 28,
    ServiceClassMatchingEngine = 29,
    ServiceClassMarketInformation = 30,
    ServiceClassContribution = 31,
    ServiceClassOMD_RawDataServer = 32,
    ServiceClassDirectedQuoting = 33,
    ServiceClassVisualizationEngine = 34,
    ServiceClassMarketCommand = 35,
    ServiceClassDirectedQuoteRequest = 36,
    ServiceClassDistributionEngine = 37,
    ServiceClassOMD_TickServer = 38,
    ServiceClassOMD_NativeMemoryLoader = 39,
    ServiceClassOMD_NativeDailyLoader = 40,
    ServiceClassOMD_RT_MemoryLoader = 41,
    ServiceClassOMD_RT_DailyLoader = 42,
    ServiceClassOMD_AsciiDailyLoader = 43,
    ServiceClassOMD_OTQ_QueryDailyLoader = 44,
    ServiceClassDropCopy = 45
};

inline tbricks::Identifier ServiceClassEnumerationIdentifier()
{
    // Identifier: "683017e6-cf9b-472f-a766-7d7931327ef9"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x2f479bcfe6173068ULL, 0xf97e3231797d66a7ULL));
    return pd;
}

enum PriceSource
{
    ///< Base price on bid.
    PriceSourceBid = 0,
    ///< Base price on ask.
    PriceSourceAsk = 1,
    ///< Base price on bid+ask / 2.
    PriceSourceMidSpread = 2,
    ///< Base price on last paid.
    PriceSourceLast = 3,
    ///< Base price on close.
    PriceSourceClose = 4,
    ///< Base price on previous close.
    PriceSourcePreviousClose = 5,
    ///< Base price on fair market price.
    PriceSourceFairMarketPrice = 6,
    ///< Base price on a manual reference price parameter.
    PriceSourceManualReferencePrice = 7,
    ///< Base price on the settlement price.
    PriceSourceSettlementPrice = 8,
    ///< Base price on the indicative auction price.
    PriceSourceIndicativeAuctionPrice = 9,
    ///< Base price on the last auction price.
    PriceSourceLastAuctionPrice = 10,
    ///< Base price on (bid * ask_volume + ask * bid_volume) / (bid_volume + ask_volume).
    PriceSourceWeightedMidSpread = 11,
    ///< Base price on the previous settlement price
    PriceSourcePreviousSettlementPrice = 12,
    ///< Base price on the reference price
    PriceSourceReferencePrice = 13,
    ///< Base price on open.
    PriceSourceOpen = 14,
    ///< Base price: bid on bid, ask on ask.
    PriceSourceBidAndAsk = 15
};

inline tbricks::Identifier PriceSourceEnumerationIdentifier()
{
    // Identifier: "77a347ed-f8a8-11e0-9fa6-a6db3c870c3e"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe011a8f8ed47a377ULL, 0x3e0c873cdba6a69fULL));
    return pd;
}

enum QuoteType
{
    ///< Quote.
    QuoteTypeQuote = 0,
    ///< Desired quote.
    QuoteTypeDesiredQuote = 1
};

inline tbricks::Identifier QuoteTypeEnumerationIdentifier()
{
    // Identifier: "79b93ba2-3a82-11e0-8688-a6cb83ae009b"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe011823aa23bb979ULL, 0x9b00ae83cba68886ULL));
    return pd;
}

enum InstrumentGroupType
{
    ///< Any custom group for an instrument. Normally used and defined by the end-user to cover for arbitrary grouping.
    InstrumentGroupTypeCustom = 1,
    ///< A sector like, agriculture, pharmaceuticals etc. Tbricks uses and provides ICB as static built in groups of this type.
    InstrumentGroupTypeSector = 2,
    ///< Any grouping based on currency. Available currencies are provided as static built in groups of this type.
    InstrumentGroupTypeCurrency = 3,
    ///< Any exchange organised group. The exchanges or venues often provide venue specific groupings that are rendered by the instrument originating instrument reference data service as group hierarchies of this type.
    InstrumentGroupTypeExchange = 4,
    ///< An automatic classification of combinations based on their legs and ratios. The correct group is automatically updated by the instrument service and can not be updated manually.
    InstrumentGroupTypeCombination = 5,
    ///< Venue-provided default spread tables matching various market-maker obligations.
    InstrumentGroupTypeSpreadTable = 6,
    ///< Standardized group structure for listed derivatives, originating from the IRD.
    InstrumentGroupTypeDerivative = 7
};

inline tbricks::Identifier InstrumentGroupTypeEnumerationIdentifier()
{
    // Identifier: "7a688174-b0f6-4d8f-af8a-553fb668aa7b"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x8f4df6b07481687aULL, 0x7baa68b63f558aafULL));
    return pd;
}

enum InstrumentMatchingLogic
{
    InstrumentMatchingLogicTimePriority = 1,
    InstrumentMatchingLogicProRata = 2
};

inline tbricks::Identifier InstrumentMatchingLogicEnumerationIdentifier()
{
    // Identifier: "813f49d8-bd94-4f45-b8d6-3a8df779bc3a"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x454f94bdd8493f81ULL, 0x3abc79f78d3ad6b8ULL));
    return pd;
}

enum InstrumentMarketDataStatus
{
    InstrumentMarketDataStatusUnknown = 1,
    ///< The instrument market data from the venue is delayed or unavailable.
    InstrumentMarketDataStatusStale = 2,
    ///< The instrument market data is live and working ok. 
    InstrumentMarketDataStatusOk = 3
};

inline tbricks::Identifier InstrumentMarketDataStatusEnumerationIdentifier()
{
    // Identifier: "8b8a647a-3f9b-4a54-8633-6e3ea5e36e3c"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x544a9b3f7a648a8bULL, 0x3c6ee3a53e6e3386ULL));
    return pd;
}

enum CashAggregation
{
    ///< Aggregation over all keys except currency.
    CashAggregationCashByCurrency = 1,
    ///< Aggregation over all keys except currency and type.
    CashAggregationCashByCurrencyAndType = 2,
    ///< No aggregation is performed. Useful for troubleshooting how a cash position is constructed. Cash position description, instrument identifier and strategy identifier are provided only for this aggregation type.
    CashAggregationCash = 3,
    ///< Aggregation over all keys except currency and instrument.
    CashAggregationCashByCurrencyAndInstrument = 4,
    ///< Aggregation over all keys except currency and settlement.
    CashAggregationCashByCurrencyAndSettlement = 5
};

inline tbricks::Identifier CashAggregationEnumerationIdentifier()
{
    // Identifier: "8c8780e2-5525-4cbc-959d-bcc728484830"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xbc4c2555e280878cULL, 0x30484828c7bc9d95ULL));
    return pd;
}

enum PriceTrends
{
    ///< The trend has not changed and has no defied relation
    PriceTrendsZero = 1,
    ///< The trend is positive
    PriceTrendsPlus = 2,
    ///< The trend is negative
    PriceTrendsMinus = 3,
    ///< The trend is flat, but was positive
    PriceTrendsZeroPlus = 4,
    ///< The trend is flat, but was negative
    PriceTrendsZeroMinus = 5,
    ///< The trend is unknown.
    PriceTrendsUnknown = 6
};

inline tbricks::Identifier PriceTrendsEnumerationIdentifier()
{
    // Identifier: "9e40194a-f61a-4292-bbe8-d50e1fe6e6f4"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x92421af64a19409eULL, 0xf4e6e61f0ed5e8bbULL));
    return pd;
}

enum OrderState
{
    OrderStateWorkingOrder = 2,
    OrderStateCompleted = 3
};

inline tbricks::Identifier OrderStateEnumerationIdentifier()
{
    // Identifier: "9f566e95-04d2-4cb6-8a9b-dcd07ff53699"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xb64cd204956e569fULL, 0x9936f57fd0dc9b8aULL));
    return pd;
}

enum TradeLiquidity
{
    ///< Indicates that trade added liquidity.
    TradeLiquidityAdded = 1,
    ///< Indicates that trade removed liquidity.
    TradeLiquidityRemoved = 2,
    ///< Indicates that trade originates from an order that traded during an auction.
    TradeLiquidityAuction = 3
};

inline tbricks::Identifier TradeLiquidityEnumerationIdentifier()
{
    // Identifier: "9f6c44a8-1171-4537-b12c-e1e52ef7c04d"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x37457111a8446c9fULL, 0x4dc0f72ee5e12cb1ULL));
    return pd;
}

enum SelfTestStatus
{
    ///< No self-test have been run yet for the service.
    SelfTestStatusNotRun = 1,
    ///< The previous self-test succeeded.
    SelfTestStatusOk = 2,
    ///< The previous self-test for the service failed.
    SelfTestStatusFailed = 3,
    ///< A self-test is currently in progress.
    SelfTestStatusInProgress = 4
};

inline tbricks::Identifier SelfTestStatusEnumerationIdentifier()
{
    // Identifier: "a69e4890-3036-4393-bd9d-c9505b8d83d4"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x9343363090489ea6ULL, 0xd4838d5b50c99dbdULL));
    return pd;
}

enum PropertyCategory
{
    PropertyCategoryUnknown = 0,
    PropertyCategoryDateAndTime = 1,
    PropertyCategoryIdentifiersAndReferences = 2,
    PropertyCategoryStatusAndInformation = 3,
    PropertyCategoryMarketData = 4,
    PropertyCategoryPerformanceAndQoS = 5,
    PropertyCategoryPrices_44_Volumes = 6,
    PropertyCategorySettings_LEFT_PARENTHESIS_ObjectSpecific_RIGHT_PARENTHESIS = 7,
    PropertyCategoryNamesAndDescriptions = 8,
    ///< Calculated values such as fair market price, greeks and implied volatilities. 
    PropertyCategoryCalculatedValues = 9,
    ///< Settings influencing the calculated values.
    PropertyCategoryCalculatedValueSettings = 10,
    ///< In-line click trading functionality.
    PropertyCategoryClickTrading = 11
};

inline tbricks::Identifier PropertyCategoryEnumerationIdentifier()
{
    // Identifier: "a6ca9ee8-c313-486e-b379-a964ba96b130"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x6e4813c3e89ecaa6ULL, 0x30b196ba64a979b3ULL));
    return pd;
}

enum StrategyAction
{
    StrategyActionForceDelete = 1
};

inline tbricks::Identifier StrategyActionEnumerationIdentifier()
{
    // Identifier: "a84cfde6-8936-48f9-a08a-744d2c1397cb"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xf9483689e6fd4ca8ULL, 0xcb97132c4d748aa0ULL));
    return pd;
}

enum ExpirationSet
{
    ///< Default expiration set.
    ExpirationSetDefault = 0
};

inline tbricks::Identifier ExpirationSetEnumerationIdentifier()
{
    // Identifier: "b1fc584c-f563-11e3-8d13-5e0d1c06b747"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe31163f54c58fcb1ULL, 0x47b7061c0d5e138dULL));
    return pd;
}

enum Moneyness
{
    ///< The option is deep in-the-money.
    MoneynessDeepInTheMoney = 0,
    ///< The option is in-the-money.
    MoneynessInTheMoney = 1,
    ///< The option is at-the-money.
    MoneynessAtTheMoney = 2,
    ///< The option is out-of-the-money.
    MoneynessOutOfTheMoney = 3,
    ///< The option is deep out-of-the-money.
    MoneynessDeepOutOfTheMoney = 4
};

inline tbricks::Identifier MoneynessEnumerationIdentifier()
{
    // Identifier: "b6d2f8a4-c5fa-43bb-841d-a85d548266ab"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xbb43fac5a4f8d2b6ULL, 0xab6682545da81d84ULL));
    return pd;
}

enum IndicativeAuctionSurplusDirection
{
    ///< Surplus on buy side.
    IndicativeAuctionSurplusDirectionBuy = 1,
    ///< Surplus on sell side.
    IndicativeAuctionSurplusDirectionSell = 2,
    ///< No surplus on either side.
    IndicativeAuctionSurplusDirectionNone = 3,
    ///< The surplus can not be identified, calculated or is otherwise undefined.
    IndicativeAuctionSurplusDirectionUnknown = 4
};

inline tbricks::Identifier IndicativeAuctionSurplusDirectionEnumerationIdentifier()
{
    // Identifier: "bc241488-e5dc-11e1-83c8-870c3e99245e"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe111dce5881424bcULL, 0x5e24993e0c87c883ULL));
    return pd;
}

enum StrategyTransactionOperations
{
    ///< No strategy transaction is currently in progress
    StrategyTransactionOperationsNone = 0,
    ///< The strategy is about to be created
    StrategyTransactionOperationsAdd = 1,
    ///< The strategy will be modified
    StrategyTransactionOperationsModify = 2,
    ///< The strategy is about to be deleted
    StrategyTransactionOperationsDelete = 3,
    ///< The strategy is about to be paused
    StrategyTransactionOperationsPause = 4,
    ///< The strategy is about to be run
    StrategyTransactionOperationsRun = 5
};

inline tbricks::Identifier StrategyTransactionOperationsEnumerationIdentifier()
{
    // Identifier: "c2ed0f33-8165-4daa-8eb3-e8db053ba695"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xaa4d6581330fedc2ULL, 0x95a63b05dbe8b38eULL));
    return pd;
}

enum FractionSeparator
{
    ///< Apostrophe
    FractionSeparator_QUOTE__LEFT_PARENTHESIS_Apostrophe_RIGHT_PARENTHESIS = 0,
    ///< Hyphen
    FractionSeparator_LEFT_PARENTHESIS_Hyphen_RIGHT_PARENTHESIS = 1,
    ///< Dot
    FractionSeparator_46_LEFT_PARENTHESIS_Dot_RIGHT_PARENTHESIS = 2
};

inline tbricks::Identifier FractionSeparatorEnumerationIdentifier()
{
    // Identifier: "d00e9a4c-6a14-11e2-92b3-d6ae529049f1"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe211146a4c9a0ed0ULL, 0xf1499052aed6b392ULL));
    return pd;
}

enum TradingCapacity
{
    TradingCapacityUndefined = 0,
    ///< Instigator of an operation.
    TradingCapacityInitiator = 1,
    ///< Responder to an operation.
    TradingCapacityReactor = 2
};

inline tbricks::Identifier TradingCapacityEnumerationIdentifier()
{
    // Identifier: "d1f82a36-cc33-11e2-8bbb-23be84e16cd6"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe21133cc362af8d1ULL, 0xd66ce184be23bb8bULL));
    return pd;
}

enum InstrumentTradingStatus
{
    ///< The instrument state is currently not possible to determine.
    InstrumentTradingStatusUnknown = 1,
    ///< Instrument is available but not open for trading/matching.
    InstrumentTradingStatusNotAllowed = 2,
    ///< A temporary state that is likely to revert to trading allowed.
    InstrumentTradingStatusTemporarilyNotAllowed = 3,
    ///< Full normal trading/matching.
    InstrumentTradingStatusAllowed = 4
};

inline tbricks::Identifier InstrumentTradingStatusEnumerationIdentifier()
{
    // Identifier: "d1fed92b-272d-45e3-9cdf-4f57cc183e68"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe3452d272bd9fed1ULL, 0x683e18cc574fdf9cULL));
    return pd;
}

enum PostingAction
{
    ///< Undefined action.
    PostingActionUndefined = 0,
    ///< Opening a position.
    PostingActionOpen = 1,
    ///< Closing a position.
    PostingActionClose = 2
};

inline tbricks::Identifier PostingActionEnumerationIdentifier()
{
    // Identifier: "d6f265f2-cdb3-11e2-897d-529049f1f1bb"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe211b3cdf265f2d6ULL, 0xbbf1f14990527d89ULL));
    return pd;
}

enum LogLevel
{
    ///< An unrecoverable critical error has occurred. The service will try to emit additional debug information for the cause before aborting. This is only being done due to a lack for critical system resources or internal inconsistencies in the service that can risk data corruption or erroneous behavior.
    LogLevelCritical = 0,
    ///< An unexpected recoverable error condition has occured that should be reported to the software vendor, this usually requires corrective action by administrative staff.
    LogLevelError = 1,
    ///< A recoverable but potentially expected exceptional condition has occurred that may require corrective action by administrative staff to be resolved. For example, it can be that the system is running low on disk space, or that a latency measurement counter is slower than an acceptable threshold.
    LogLevelWarning = 2,
    ///< An expected system state change has occured. E.g., the service has successfully connected to another service, the service may have connected to an external data source (for trading services), the service has fully recovered it's state during startup.
    LogLevelNotice = 3,
    ///< Periodic events containing status information. Typically non-exceptional health information like memory utilization, cpu utilization, cache statistics, number of instruments, number of bytes sent/received, number of strategies, number of running strategies, number of clients connected, etc, etc.
    LogLevelStatus = 4,
    ///< A moderate amount of debug information is provided with the intention to aid operational administrative and/or engineering staff with troubleshooting. This may have a noticeable performance impact on the service.
    LogLevelDebug = 5,
    ///< This provides extensive debug dumps, up to and including verbose dumps of all messages and data buffers sent/received etc. This will have a severe performance impact on the service if used by a tblog client.
    LogLevelDump = 6,
    ///< This provides extensive dump logs. This will have a severe performance impact on the service if used by a tblog client.
    LogLevelFullDump = 7
};

inline tbricks::Identifier LogLevelEnumerationIdentifier()
{
    // Identifier: "d9f8791b-6069-4ae5-82eb-aeb81a642e21"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe54a69601b79f8d9ULL, 0x212e641ab8aeeb82ULL));
    return pd;
}

enum OrderMode
{
    ///< The order mode indicating normal order.
    OrderModeOrder = 1,
    ///< The order mode indicating quote order used by quoting service.
    OrderModeQuote = 2,
    ///< The order mode indicating quote order used by quoting service in multi-level updates.
    OrderModeQuoteMultiLevel = 3,
    ///< The order mode indicating quote order used by quoting service in hidden quoting mode.
    OrderModeHidden = 4,
    ///< The order mode indicating quote order used by quoting service in peg quoting mode.
    OrderModePeg = 5,
    ///< The order mode indicating quote order is a reply to a quote request.
    OrderModeQuoteResponder = 6
};

inline tbricks::Identifier OrderModeEnumerationIdentifier()
{
    // Identifier: "e5755308-5b76-11e4-9c0d-49f1f1bbe9eb"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe411765b085375e5ULL, 0xebe9bbf1f1490d9cULL));
    return pd;
}

enum AlertSeverity
{
    ///< The alert is of a normal nature.
    AlertSeverityNormal = 0,
    ///< The alert is of a critical nature and requires additional focused attention.
    AlertSeverityCritical = 1
};

inline tbricks::Identifier AlertSeverityEnumerationIdentifier()
{
    // Identifier: "e5ec5f04-8d55-47ae-aaa6-eeed18d93f22"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xae47558d045fece5ULL, 0x223fd918edeea6aaULL));
    return pd;
}

enum PriceDisplayFormat
{
    ///< Decimal representation, e.g. 3.141592.
    PriceDisplayFormatDecimal = 0,
    ///< Fractional representation, e.g. 5.
    PriceDisplayFormatWholes = 1,
    ///< Fractional representation, e.g. 3'5.
    PriceDisplayFormatHalves = 2,
    ///< Fractional representation, e.g. 2'7.
    PriceDisplayFormatQuarters = 4,
    ///< Fractional representation, e.g. 4'6.
    PriceDisplayFormatEights = 8,
    ///< Fractional representation, e.g. 3'09.
    PriceDisplayFormatSixteenths = 16,
    ///< Fractional representation, e.g. 5'29.
    PriceDisplayFormatThirty_8211_Seconds = 32,
    ///< Fractional representation, e.g. 5'18+ or 5'185.
    PriceDisplayFormatThirty_8211_Seconds_LEFT_PARENTHESIS_Half_RIGHT_PARENTHESIS = 33,
    ///< Fractional representation, e.g. 5'187 or 5'18¾.
    PriceDisplayFormatThirty_8211_Seconds_LEFT_PARENTHESIS_Quarter_RIGHT_PARENTHESIS = 34,
    ///< Fractional representation, e.g. 105-29 1/8.
    PriceDisplayFormatThirty_8211_Seconds_LEFT_PARENTHESIS_Eighth_RIGHT_PARENTHESIS = 35,
    ///< Fractional representation, e.g. 5'39.
    PriceDisplayFormatSixtyFourths = 64,
    ///< Fractional representation, e.g. 5'395.
    PriceDisplayFormatSixtyFourths_LEFT_PARENTHESIS_Half_RIGHT_PARENTHESIS = 65,
    ///< Percentage representation, e.g. 34.44 means 0.3444 in decimal representation.
    PriceDisplayFormatPercentage = 100,
    ///< Fractional representation, e.g. 5'102.
    PriceDisplayFormatHundredAndTwentyEighths = 128,
    ///< Fractional representation, e.g. 5'202.
    PriceDisplayFormatTwoHundredAndFiftySixths = 256,
    ///< Fractional representation, e.g. 5'402.
    PriceDisplayFormatFiveHundredAndTwelfths = 512,
    ///< Basis points representation, e.g. 34.44 means 0.003444 in decimal representation.
    PriceDisplayFormatBasisPoints = 10000
};

inline tbricks::Identifier PriceDisplayFormatEnumerationIdentifier()
{
    // Identifier: "ef870d78-6488-11e2-87b7-a6db3c870c3e"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe2118864780d87efULL, 0x3e0c873cdba6b787ULL));
    return pd;
}

namespace enumerations {

enum CME_ILink3Origin
{
    CME_ILink3OriginCustomer = 0,
    CME_ILink3OriginFirm = 1
};

inline tbricks::Identifier CME_ILink3OriginEnumerationIdentifier()
{
    // Identifier: "0366c0e2-6218-11ea-bb45-245e0d1c06b7"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xea111862e2c06603ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}

enum ComboLegPriceAveragingLogic
{
    ///< None
    ComboLegPriceAveragingLogicNone = 0,
    ///< Use number of legs in combo leg price averaging logic
    ComboLegPriceAveragingLogicNumberOfLegs = 1,
    ///< Use sum of ratios in combo leg price averaging logic
    ComboLegPriceAveragingLogicSumOfRatios = 2
};

inline tbricks::Identifier ComboLegPriceAveragingLogicEnumerationIdentifier()
{
    // Identifier: "09e9922e-27f4-11e8-a930-d48f50eaa8f6"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe811f4272e92e909ULL, 0xf6a8ea508fd430a9ULL));
    return pd;
}

enum QualifiedRole
{
    QualifiedRolePerson = 1,
    QualifiedRoleFirm = 2,
    QualifiedRoleAlgorithm = 3
};

inline tbricks::Identifier QualifiedRoleEnumerationIdentifier()
{
    // Identifier: "121c34c0-6d68-11e7-ae50-47deb3124dc8"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe711686dc0341c12ULL, 0xc84d12b3de4750aeULL));
    return pd;
}

enum TradeType
{
    ///< The trade type indicating normal automatic matching, at venue side.
    TradeTypeAutomatic = 1,
    ///< The trade type indicating manual registration.
    TradeTypeRegistered = 2,
    ///< The trade type indicating internalised matching of crossing orders, within tbricks system.
    TradeTypeInternal = 3,
    ///< The trade type indicating trades resulting from simulation.
    TradeTypeSimulated = 4,
    ///< This is normally related to reception of trades where orders have not been persisted or orders already being purged on Tbricks side. Trades that originate from executions done outside Tbricks should be classified as drop copies.
    TradeTypeUnsolicited = 5,
    ///< The trade was delivered as part of an expiration.
    TradeTypeDelivery = 6,
    ///< The trade is due to early exercise.
    TradeTypeEarlyExercise = 7,
    ///< The trade is generated by expiration.
    TradeTypeExpiration = 8,
    ///< The trade is due to an assignment.
    TradeTypeAssignment = 9,
    ///< Expit trade and reported on the exchange.
    TradeTypeExpit = 10,
    ///< Drop copies are trades done in other systems but assimilated by Tbricks drop copy reception service. These trades are not expected to have a corresponding but missing order like the unsoliciteds. 
    TradeTypeDropCopy = 11,
    ///< Position external adjustment
    TradeTypePositionAdjustment = 12,
    ///< The trade was delivered as part of an expiration.
    TradeTypeExpirationClose = 13,
    ///< Position adjustment trade closing an expired position.
    TradeTypePositionReset = 14,
    ///< The correcting trade at an expiration exercise.
    TradeTypeExercise = 15,
    ///< The resulting delivery trade at all exercises.
    TradeTypeExerciseDelivery = 16,
    ///< The resulting delivery trade at assignments.
    TradeTypeAssignmentDelivery = 17
};

inline tbricks::Identifier TradeTypeEnumerationIdentifier()
{
    // Identifier: "18d11e58-a734-4449-801a-a5feaa77c118"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0x494434a7581ed118ULL, 0x18c177aafea51a80ULL));
    return pd;
}

enum OrderbookChangeReason
{
    ///< Undefined or indeterminable change-reason, like snapshot baseline.
    OrderbookChangeReasonUndefined = 0,
    ///< Change due to order add.
    OrderbookChangeReasonAdd = 1,
    ///< Change due to order modify.
    OrderbookChangeReasonModify = 2,
    ///< Change due to order delete.
    OrderbookChangeReasonDelete = 3,
    ///< Change due to order being traded.
    OrderbookChangeReasonTrade = 4
};

inline tbricks::Identifier OrderbookChangeReasonEnumerationIdentifier()
{
    // Identifier: "19ef68e2-740f-11e5-9e24-9049f1f1bbe9"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe5110f74e268ef19ULL, 0xe9bbf1f14990249eULL));
    return pd;
}

enum HistoricalDataLevel
{
    ///< No persisting of market data.
    HistoricalDataLevelOff = 0,
    ///< Persisting of statistics, public trades and additional information like market-phases etc.
    HistoricalDataLevelStatistics = 1,
    ///< BBO in addition to Level 0.
    HistoricalDataLevelBestPricesAndStatistics = 2,
    ///< Depth in addition to Level 1.
    HistoricalDataLevelBestPrices_44_StatisticsAndDepth = 3
};

inline tbricks::Identifier HistoricalDataLevelEnumerationIdentifier()
{
    // Identifier: "1e845e82-1044-11e5-bcdb-d6ae529049f1"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe5114410825e841eULL, 0xf1499052aed6dbbcULL));
    return pd;
}

enum LiquiditySource
{
    ///< Normal liquidity on the exchange from some other counterpart.
    LiquiditySourceExchange = 0,
    ///< Your own liquidity on the exchange, you essentially cross with your own orders and get prioritized.
    LiquiditySourceInternal = 1,
    ///< Liquidity stemming from other exchange than the target (typically linking or faraway routing in the US).
    LiquiditySourceRemote = 2
};

inline tbricks::Identifier LiquiditySourceEnumerationIdentifier()
{
    // Identifier: "24eadedc-eb58-11e5-8d13-5e0d1c06b747"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe51158ebdcdeea24ULL, 0x47b7061c0d5e138dULL));
    return pd;
}

enum OrderCapacity
{
    ///< Acting on a clients behalf.
    OrderCapacityAgency = 0,
    ///< Acting on own account.
    OrderCapacityPrincipal = 1,
    ///< Acting on own account, but backed in a riskless manner.
    OrderCapacityRisklessPrincipal = 2
};

inline tbricks::Identifier OrderCapacityEnumerationIdentifier()
{
    // Identifier: "2941fab2-e1e2-11e5-9e24-9049f1f1bbe9"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe511e2e1b2fa4129ULL, 0xe9bbf1f14990249eULL));
    return pd;
}

enum QuoteRequestType
{
    ///< Quote request.
    QuoteRequestTypeQuoteRequest = 0,
    ///< Intention to cross.
    QuoteRequestTypeIntentionToCross = 1
};

inline tbricks::Identifier QuoteRequestTypeEnumerationIdentifier()
{
    // Identifier: "2aac2ce2-29cb-11e7-a68b-b3a6db3c870c"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe711cb29e22cac2aULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

enum EdgeBasedBid_DIV_AskIntervalIndicator
{
    ///< Not appliсable
    EdgeBasedBid_DIV_AskIntervalIndicatorNull = 0,
    ///< Between fair market price and edge: Below of theo + edge for bid, above theo - edge for ask. 
    EdgeBasedBid_DIV_AskIntervalIndicatorShort = 1,
    ///< Between edge and large edge: Inside of the interval [fair + bid edge, fai + large bid edge] for bid, inside of the interval [fair - large ask edge, fair - ask edge] for ask.
    EdgeBasedBid_DIV_AskIntervalIndicatorMedium = 2,
    ///< Greater then large edge: Above of theo + large edge for bid, below of theo - large edge for ask. 
    EdgeBasedBid_DIV_AskIntervalIndicatorLarge = 3
};

inline tbricks::Identifier EdgeBasedBid_DIV_AskIntervalIndicatorEnumerationIdentifier()
{
    // Identifier: "2ffc5960-686f-11e6-b596-99245e0d1c06"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe6116f686059fc2fULL, 0x61c0d5e249996b5ULL));
    return pd;
}

enum RequestForQuoteType
{
    ///< A regular request for quote.
    RequestForQuoteTypeNormal = 1,
    ///< Request for cross.
    RequestForQuoteTypeRequestForCross = 2,
    ///< Indicative.
    RequestForQuoteTypeIndicative = 3
};

inline tbricks::Identifier RequestForQuoteTypeEnumerationIdentifier()
{
    // Identifier: "36722ef6-2bf6-11e6-aed6-2923be84e16c"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe611f62bf62e7236ULL, 0x6ce184be2329d6aeULL));
    return pd;
}

enum OrderbookType
{
    ///< Regular limit orderbook pepresending individual orders or their aggregation per-price level.
    OrderbookTypeLimit = 0,
    ///< Order book expressed in terms of prices for specific volumes, i.e. price to trade specific volume.
    OrderbookTypePriceBanded = 1
};

inline tbricks::Identifier OrderbookTypeEnumerationIdentifier()
{
    // Identifier: "414eed9c-6bb4-11e7-b2e0-2e388bc4a96d"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe711b46b9ced4e41ULL, 0x6da9c48b382ee0b2ULL));
    return pd;
}

enum ExerciseStyle
{
    ExerciseStyleEuropean = 0,
    ExerciseStyleAmerican = 1
};

inline tbricks::Identifier ExerciseStyleEnumerationIdentifier()
{
    // Identifier: "55ff1984-b88f-11e6-abe9-e16cd6ae5290"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe6118fb88419ff55ULL, 0x9052aed66ce1e9abULL));
    return pd;
}

enum CME_ILink3AveragePxInd
{
    CME_ILink3AveragePxIndNoAveragePricing = 0,
    CME_ILink3AveragePxIndTradeIsPartOfAnAveragePriceGroupIndentifiedByTheAvgPxGroupId_LEFT_PARENTHESIS_Tag1731_RIGHT_PARENTHESIS = 1,
    CME_ILink3AveragePxIndTradeIsPartOfA_NotioinalValueAveragePriceGroup = 3
};

inline tbricks::Identifier CME_ILink3AveragePxIndEnumerationIdentifier()
{
    // Identifier: "571548a6-6229-11ea-bb45-245e0d1c06b7"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xea112962a6481557ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}

enum ExpandState
{
    ExpandStateNone = 0,
    ExpandStateCollapsed = 1,
    ExpandStateExpanded = 2
};

inline tbricks::Identifier ExpandStateEnumerationIdentifier()
{
    // Identifier: "654f1d6e-bd81-11e8-bb43-ebb3a6db3c87"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe81181bd6e1d4f65ULL, 0x873cdba6b3eb43bbULL));
    return pd;
}

enum ExecutionPolicy
{
    ///< Execution policy is not specified.
    ExecutionPolicyNone = 0,
    ///< A round-lot market order to buy minus is an order to buy a stated amount of a stock provided that its price is:  - not higher than the last sale if the last sale was a minus or zero minus tick and  - not higher than the last sale minus the minimum fractional change in the stock if the last sale was a plus or zero plus tick. A limit price order to buy minus also states the highest price at which it can be executed.
    ExecutionPolicyBuyMinus = 1,
    ///< A round-lot market order to sell plus is an order to sell a stated amount of a stock provided that its price is:  - not lower than the last sale if the last sale was a plus or zero plus tick and  - not lower than the last sale minus the minimum fractional change in the stock if the last sale was a minus or zero minus tick. A limit-price order to sell plus also states the lowest price at which it can be executed.
    ExecutionPolicySellPlus = 2,
    ///< An order to sell a security that the seller does not own, a sale effected by delivering a security borrowed by, or for the account of, the seller.  Can only be executed on a plus or zero plus tick.
    ExecutionPolicySellShort = 3,
    ///< Short sale exempt from short-sale rules.
    ExecutionPolicySellShortExempt = 4
};

inline tbricks::Identifier ExecutionPolicyEnumerationIdentifier()
{
    // Identifier: "66276e40-e0e5-11e7-9e24-9049f1f1bbe9"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe711e5e0406e2766ULL, 0xe9bbf1f14990249eULL));
    return pd;
}

enum StrategyState
{
    StrategyStatePaused = 1,
    StrategyStateRunning = 2,
    StrategyStateDeleted = 3
};

inline tbricks::Identifier StrategyStateEnumerationIdentifier()
{
    // Identifier: "69d6ba35-3425-4ad5-85d2-6802850f1a4d"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xd54a253435bad669ULL, 0x4d1a0f850268d285ULL));
    return pd;
}

enum Urgency
{
    ///< Low or background urgency.
    UrgencyLow = 1,
    ///< Standard urgency of messages.
    UrgencyNormal = 2,
    ///< Important priority messages.
    UrgencyHigh = 3
};

inline tbricks::Identifier UrgencyEnumerationIdentifier()
{
    // Identifier: "71ead540-1112-11e6-b149-be84e16cd6ae"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe611121140d5ea71ULL, 0xaed66ce184be49b1ULL));
    return pd;
}

enum StrategyPricePolicy
{
    ///< Order is cancelled if order due to it's price becomes aggressive, only orders entering the orderbook and remain as passive is accepted.
    StrategyPricePolicyBookOrCancel = 1
};

inline tbricks::Identifier StrategyPricePolicyEnumerationIdentifier()
{
    // Identifier: "7b463c38-6b62-11e6-9c0d-49f1f1bbe9eb"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe611626b383c467bULL, 0xebe9bbf1f1490d9cULL));
    return pd;
}

enum ClientNodeType
{
    ClientNodeTypeClient = 0,
    ClientNodeTypeGroup = 1,
    ClientNodeTypeAccount = 2
};

inline tbricks::Identifier ClientNodeTypeEnumerationIdentifier()
{
    // Identifier: "81cbad7a-0808-11e7-9e24-9049f1f1bbe9"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe71108087aadcb81ULL, 0xe9bbf1f14990249eULL));
    return pd;
}

enum DayCountConvention
{
    DayCountConventionActual_DIV_Actual = 0,
    DayCountConventionActual_DIV_365 = 1,
    DayCountConventionActual_DIV_365366 = 2,
    DayCountConventionActual_DIV_360 = 3,
    DayCountConvention_30_DIV_360 = 4,
    DayCountConvention_30E_DIV_360 = 5,
    DayCountConvention_30_DIV_365 = 6,
    DayCountConvention_30E_DIV_365 = 7
};

inline tbricks::Identifier DayCountConventionEnumerationIdentifier()
{
    // Identifier: "848487fa-f047-11e5-b2ae-06b747deb312"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe51147f0fa878484ULL, 0x12b3de47b706aeb2ULL));
    return pd;
}

enum Side
{
    SideBuy = 1,
    SideSell = 2
};

inline tbricks::Identifier SideEnumerationIdentifier()
{
    // Identifier: "88b1de00-6a49-43d2-8aef-c2cfcc35220c"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xd243496a00deb188ULL, 0xc2235cccfc2ef8aULL));
    return pd;
}

enum LimitMode
{
    LimitModeActive = 0,
    LimitModeInactive = 1
};

inline tbricks::Identifier LimitModeEnumerationIdentifier()
{
    // Identifier: "93d5d4fe-72ca-11e8-9b1c-1c06b747deb3"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe811ca72fed4d593ULL, 0xb3de47b7061c1c9bULL));
    return pd;
}

enum OrderStatus
{
    ///< Receipt of a new order by the operator of the trading venue.
    OrderStatusNewOrder = 1,
    ///< An order which becomes executable or, as the case may be, non-executable upon the realisation of a pre-determined condition.
    OrderStatusTriggered = 2,
    ///< Replaced by the member or participant or client of the trading venue: where a member or participant or client of the trading venue decides upon its own initiative to change any characteristic(s) of the order it has previously entered into the order book.
    OrderStatusReplacedByMember = 3,
    ///< Where any characteristic(s) of an order is changed by the trading venue operator’s IT systems. This includes where a peg order’s or a trailing stop order’s current characteristics are changed to reflect how the order is located within the order book.
    OrderStatusReplacedByMarket_LEFT_PARENTHESIS_Automatic_RIGHT_PARENTHESIS = 4,
    ///< Where any characteristic(s) of an order is changed by a trading venue operator’s staff. This includes where a member or participant or client of the trading venue has IT issues and needs its orders to be cancelled urgently.
    OrderStatusReplacedByMarket_LEFT_PARENTHESIS_HumanInvention_RIGHT_PARENTHESIS = 5,
    ///< Change of status at the initiative of the Member/Participant/client of the trading venue. This includes activation, deactivation.
    OrderStatusChangeOfStatusAtTheInitiativeOfTheMember = 6,
    ///< Change of status due to market operations
    OrderStatusChangeOfStatusDueToMarketOperations = 7,
    ///< Cancelled at the initiative of the member or participant or client of the trading venue; where a member or participant or client decides upon its own initiative to cancel the order it has previously entered.
    OrderStatusCancelledAtTheInitiativeOfTheMember = 8,
    ///< This includes a protection mechanism provided for investment firms carrying out a market making activity as per Articles 17 and 48 of Directive 2014/65/EU.
    OrderStatusCancelledByMarketOperations = 9,
    ///< An order received but rejected by the operator of the trading venue.
    OrderStatusRejectedOrder = 10,
    ///< Where the order is removed from the order book upon the end of its validity period.
    OrderStatusExpiredOrder = 11,
    ///< Where the order is not fully executed so that there remains a quantity to be executed.
    OrderStatusPartiallyFilled = 12,
    ///< Where there is no more quantity to be executed.
    OrderStatusFilled = 13
};

inline tbricks::Identifier OrderStatusEnumerationIdentifier()
{
    // Identifier: "9bf6e1ac-8282-11e7-b2c0-7e7dbe024963"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe7118282ace1f69bULL, 0x634902be7d7ec0b2ULL));
    return pd;
}

enum CME_ILink3CustomerTypeIndicator
{
    CME_ILink3CustomerTypeIndicatorMemberTradingOnTheirOwnAccount = 1,
    CME_ILink3CustomerTypeIndicatorClearingFirmTradingForItsProprietaryAccount = 2,
    CME_ILink3CustomerTypeIndicatorMemberTradingForAnotherMember = 3,
    CME_ILink3CustomerTypeIndicatorAllOther = 4
};

inline tbricks::Identifier CME_ILink3CustomerTypeIndicatorEnumerationIdentifier()
{
    // Identifier: "a6945daa-6228-11ea-bb45-245e0d1c06b7"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xea112862aa5d94a6ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}

enum ParticipationPolicy
{
    ///< Allows access to both dark and lit pool even though orders are normally entered on the lit pool market, normally dark pool is tried and residual volume goes into lit pool subsequently, ordres are not ending up passive in both order books.
    ParticipationPolicyDarkLitSweep = 0,
    ///< Follows regulatory requirement to never execute against anything else than passive visible liquidity, meaning it bypasses iceberg-liquidity etc. during execution. Sometimes required when trading through in the depth, depending on the current regulatory status of the instrument.
    ParticipationPolicyBypassUndisclosed = 1,
    ///< Passive liquidity is only posted as indicative and is not immediately tradable, subsequent accept of any aggressive order is required for closing a deal.
    ParticipationPolicyIndicativeOnly = 2
};

inline tbricks::Identifier ParticipationPolicyEnumerationIdentifier()
{
    // Identifier: "adc482a4-527c-11e6-9b1c-1c06b747deb3"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe6117c52a482c4adULL, 0xb3de47b7061c1c9bULL));
    return pd;
}

enum CME_ILink3ClearingTradePriceType
{
    CME_ILink3ClearingTradePriceTypeTradeClearingAtExecutionPrice = 0,
    CME_ILink3ClearingTradePriceTypeTradeClearingAtAlternateClearingPrice = 1
};

inline tbricks::Identifier CME_ILink3ClearingTradePriceTypeEnumerationIdentifier()
{
    // Identifier: "b02efe3e-6231-11ea-bb45-245e0d1c06b7"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xea1131623efe2eb0ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}

enum MarketModelClass
{
    MarketModelClassMarketMechanism = 1,
    MarketModelClassTradingMode = 2,
    MarketModelClassTransactionCategory = 3,
    MarketModelClassNegotiatedTransactionIndicator = 4,
    MarketModelClassCrossingTradeIndicator = 5,
    MarketModelClassModificationIndicator = 6,
    MarketModelClassBenchmarkIndicator = 7,
    MarketModelClassEx_DIV_CumDividendIndicator = 8,
    MarketModelClassOffBookAutomatedIndicator = 9,
    MarketModelClassPublicationMode = 10
};

inline tbricks::Identifier MarketModelClassEnumerationIdentifier()
{
    // Identifier: "b472ad00-eba3-11e5-a770-2d9222c15cbe"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe511a3eb00ad72b4ULL, 0xbe5cc122922d70a7ULL));
    return pd;
}

enum TradingMessageType
{
    TradingMessageTypeOrder = 76,
    TradingMessageTypeBlockOrder = 1008,
    TradingMessageTypeQuoteSet = 1036,
    TradingMessageTypeExpit = 1135,
    TradingMessageTypeDirectedQuote = 1198
};

inline tbricks::Identifier TradingMessageTypeEnumerationIdentifier()
{
    // Identifier: "b48a6154-45ad-11e9-b809-3c870c3e9924"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe911ad4554618ab4ULL, 0x24993e0c873c09b8ULL));
    return pd;
}

enum ServiceStatus
{
    ServiceStatusOffline = 0,
    ServiceStatusOnline = 1,
    ServiceStatusDisabled = 2,
    ServiceStatusOnlineOK = 3,
    ServiceStatusDowntime = 4
};

inline tbricks::Identifier ServiceStatusEnumerationIdentifier()
{
    // Identifier: "ba927833-bd49-45fe-98ba-30c0c19b39a2"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xfe4549bd337892baULL, 0xa2399bc1c030ba98ULL));
    return pd;
}

enum TreeType
{
    TreeTypeRole = 0,
    TreeTypeClient = 1,
    ///< Smart Order Router (SOR) configuration
    TreeTypeSOR_Configuration = 2,
    ///< Market making compliance settings
    TreeTypeMarketMakingComplianceSettings = 3,
    ///< Market making configuration
    TreeTypeMarketMakingConfiguration = 4,
    ///< Defines margin profile for exposing tradable FX orderbook differently to different client grops.
    TreeTypeMarginProfile = 5,
    ///< FX algo configuration
    TreeTypeFX_AlgoConfiguration = 6,
    TreeTypeFlowRoutingConfiguration = 7,
    TreeTypeFlowAppsConfiguration = 8,
    ///< Defines commission profile for exposing tradable FX orderbook differently to different client and session grops.
    TreeTypeCommissionProfile = 9,
    ///< FX client session
    TreeTypeFX_Session = 10,
    ///< Limits not associated with a client
    TreeTypeLimit = 2931
};

inline tbricks::Identifier TreeTypeEnumerationIdentifier()
{
    // Identifier: "bb5061ae-d185-11e5-bccb-3e99245e0d1c"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe51185d1ae6150bbULL, 0x1c0d5e24993ecbbcULL));
    return pd;
}

enum StrategyPersistencePolicy
{
    ///< The strategy instance is only saved together with automatically saved parameters or when the service thinks it reasonable (long timer, shutdown). This provides buffered high-performance mode for strategy instances you want to persist.
    StrategyPersistencePolicyDefault = 1,
    ///< The strategy instance is automatically saved for each change.
    StrategyPersistencePolicyAllUpdates = 2
};

inline tbricks::Identifier StrategyPersistencePolicyEnumerationIdentifier()
{
    // Identifier: "bbb6b0c0-eb58-11e5-8d13-5e0d1c06b747"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe51158ebc0b0b6bbULL, 0x47b7061c0d5e138dULL));
    return pd;
}

enum PriceStructure
{
    ///< Normal pricing per share, contract or unit of measure. Gross trade amount can be calculated by (price X factor X volume).
    PriceStructurePerUnit = 1,
    ///< Priced in volatility, resulting trades are normally in per-unit instruments, both options and future.
    PriceStructureVolatility = 2,
    ///< Priced in offset from another price e.g. settlement or NAV, resulting trades are normally in per-unit instrument, applicable to futures (trade-at-settlement) and ETFs (at-NAV trades).
    PriceStructurePriceOffset = 3
};

inline tbricks::Identifier PriceStructureEnumerationIdentifier()
{
    // Identifier: "bd130362-894e-11e6-9f25-870c3e99245e"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe6114e89620313bdULL, 0x5e24993e0c87259fULL));
    return pd;
}

enum MarketCommandType
{
    ///< Sent by a liquidity provider to block trading with participants, still allowing them to see quotes.
    MarketCommandTypeSuspendParticipant = 1,
    ///< Sent by a liquidity provider to resumes trading with participants.
    MarketCommandTypeResumeParticipant = 2,
    ///< Sent by a liquidity provider to blocks trading with participants and preventing them to see quotes.
    MarketCommandTypeHaltParticipant = 3,
    ///< Set parameters of the minimum guaranteed fill.
    MarketCommandTypeSetParticipationParameters = 4,
    ///< Sent by a specialist to delay opening an instrument.
    MarketCommandTypeDelayOpening = 5,
    ///< Sent by a specialist to start trading in the instrument which opening was previously delayed.
    MarketCommandTypeOpenDelayedTrading = 6,
    ///< Set by a specialist to set the last auction price.
    MarketCommandTypeSetLastAuctionPrice = 7,
    ///< Sent by an issuer to start trading in a newly issued instrument.
    MarketCommandTypeStartTrading = 8,
    ///< Sent by an issuer to knock out the instrument due to breach of underlying price barrier.
    MarketCommandTypeKnockout = 9,
    ///< Sent by an issuer to enter the buyback phase for an instrument.
    MarketCommandTypeEnterBuybackPhase = 10,
    ///< Sent by issuer when it runs out of inventory to sell.
    MarketCommandTypeSoldOut = 11,
    ///< Sent by an issuer to knock out the instrument due to breach of certain barrier and recalculation event is required.
    MarketCommandTypeSoftKnockOut = 12,
    ///< Missing market maker in underlying instrument.
    MarketCommandTypeUnderlyingNotQuoted = 13,
    ///< Removes 'Underlying note quoted' indication after market making in underlying instrument provides quotes.
    MarketCommandTypeUnderlyingQuoted = 14
};

inline tbricks::Identifier MarketCommandTypeEnumerationIdentifier()
{
    // Identifier: "bea22706-162b-11e8-b809-3c870c3e9924"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe8112b160627a2beULL, 0x24993e0c873c09b8ULL));
    return pd;
}

enum HandlingInstruction
{
    ///< Automated execution order, private, no Broker intervention
    HandlingInstructionAutomatedExecution = 1,
    ///< Automated execution order, public, Broker intervention OK
    HandlingInstructionAutomatedInterventionOK = 2,
    ///< Manual, best execution
    HandlingInstructionManual = 3
};

inline tbricks::Identifier HandlingInstructionEnumerationIdentifier()
{
    // Identifier: "d103694c-cad0-11e7-ab50-f23db4b53e2b"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe711d0ca4c6903d1ULL, 0x2b3eb5b43df250abULL));
    return pd;
}

enum AlertType
{
    ///< Market abuse regulation
    AlertTypeMarketAbuseRegulation = 1,
    ///< Market maker compliance
    AlertTypeMarketMakerCompliance = 2,
    ///< Algo monitoring
    AlertTypeAlgoMonitoring = 3,
    ///< Best execution
    AlertTypeBestExecution = 4
};

inline tbricks::Identifier AlertTypeEnumerationIdentifier()
{
    // Identifier: "d230b8f8-2367-11e7-8a00-5547ce6be944"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe7116723f8b830d2ULL, 0x44e96bce4755008aULL));
    return pd;
}

enum PartitioningType
{
    ///< One flow app of this type handling both app requests and orders
    PartitioningTypeNone = 1,
    ///< One flow app per owner for orders and one for app requests
    PartitioningTypeOwner = 2,
    ///< One flow app per portfolio for orders and one for app requests
    PartitioningTypePortfolio = 3,
    ///< One flow app per client legal entity for orders and one for app requests
    PartitioningTypeClientLegalEntity = 4,
    ///< One flow app per venue identifier for orders and one for app requests
    PartitioningTypeVenue = 5
};

inline tbricks::Identifier PartitioningTypeEnumerationIdentifier()
{
    // Identifier: "e3545860-6c9b-11e7-b596-99245e0d1c06"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe7119b6c605854e3ULL, 0x61c0d5e249996b5ULL));
    return pd;
}

enum TransitionType
{
    ///< The order will at execution turn from a market order semantic to a limit order semantic. Any residual volume will take on the limit properties of the order
    TransitionTypeMarketToLimit = 1,
    ///< The order will at expiry turn from a limit order semantic to a market order semantic. After the matching or expiry phase, the order will take on market properties.
    TransitionTypeLimitToMarket = 2
};

inline tbricks::Identifier TransitionTypeEnumerationIdentifier()
{
    // Identifier: "e6510814-9d13-11e5-993e-529049f1f1bb"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe511139d140851e6ULL, 0xbbf1f14990523e99ULL));
    return pd;
}

}

namespace instrument_parameters {

/// Instrument parameter "Snap price origin", type "String"
inline tbricks::Uuid SnapPriceOrigin()
{
    // Identifier: "0876086a-5650-11e1-83c8-e9ebb3a6db3c"
    // Name: "Snap price origin"
    // Description: "Snap price origin"
    // Type: "String"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe11150566a087608ULL, 0x3cdba6b3ebe9c883ULL));
    return pd;
}

/// Instrument parameter "Rate", type "Double"
inline tbricks::Uuid Rate()
{
    // Identifier: "2f0b2401-0b0c-4422-819a-bb9993105f88"
    // Name: "Rate"
    // Description: "Rate"
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0x22440c0b01240b2fULL, 0x885f109399bb9a81ULL));
    return pd;
}

/// Instrument parameter "SVI a", type "Double"
inline tbricks::Uuid SVI_A()
{
    // Identifier: "f3ed9a28-e2f0-4ae3-976b-43f45383e5f1"
    // Name: "SVI a"
    // Description: "Gives the overall level of variance"
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe34af0e2289aedf3ULL, 0xf1e58353f4436b97ULL));
    return pd;
}

/// Instrument parameter "Quote hidden", type "Boolean"
inline tbricks::Uuid QuoteHidden()
{
    // Identifier: "167d9026-bcec-11df-b1f1-bd053309143e"
    // Name: "Quote hidden"
    // Description: "Quote hidden"
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xdf11ecbc26907d16ULL, 0x3e14093305bdf1b1ULL));
    return pd;
}

/// Instrument parameter "Do not expand underlying basket", type "Boolean"
inline tbricks::Uuid DoNotExpandUnderlyingBasket()
{
    // Identifier: "19789776-3d89-11e8-9b1c-1c06b747deb3"
    // Name: "Do not expand underlying basket"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe811893d76977819ULL, 0xb3de47b7061c1c9bULL));
    return pd;
}

/// Instrument parameter "Snap price time", type "DateTime"
inline tbricks::Uuid SnapPriceTime()
{
    // Identifier: "20b96066-5650-11e1-83c8-e9ebb3a6db3c"
    // Name: "Snap price time"
    // Description: "Snap price time"
    // Type: "DateTime"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe11150566660b920ULL, 0x3cdba6b3ebe9c883ULL));
    return pd;
}

/// Instrument parameter "SVI swim reference price", type "Price"
inline tbricks::Uuid SVI_SwimReferencePrice()
{
    // Identifier: "258195a0-7555-11e0-83c8-e16cd6ae5290"
    // Name: "SVI swim reference price"
    // Description: "The SVI swim reference price defines the reference point of the skew when the SVI swim correlation with the at-the-money forward is not equal to one. When the at-money-forward and the swim reference price coincide, the SVI swim correlation does not affect the skew. As the at-money-forward moves away from the SVI swim reference price, the skew will move along according to the SVI swim correlation value using the formula: t = log(X/ F^u / F*^(1-u)), where t is the input parameter to the SVI skew curve, X is the strike, F is the at-the-money-forward, u is the SVI swim correlation and F* is the SVI swim reference price."
    // Type: "Price"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe0115575a0958125ULL, 0x9052aed66ce1c883ULL));
    return pd;
}

/// Instrument parameter "SVI swim correlation", type "Double"
inline tbricks::Uuid SVI_SwimCorrelation()
{
    // Identifier: "29795008-7555-11e0-83c8-e16cd6ae5290"
    // Name: "SVI swim correlation"
    // Description: "The SVI swim correlation defines how much the skew moves with the current at-the-money forward price in terms of percent. A value of 0 means that the skew does not move and is fixed by the SVI swim reference price. This corresponds to a "sticky strike" skew. A value of 100 means that the skew moves and only depends on the at the money forward. This corresponds to a "sticky delta" skew."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011557508507929ULL, 0x9052aed66ce1c883ULL));
    return pd;
}

/// Instrument parameter "SVI b", type "Double"
inline tbricks::Uuid SVI_B()
{
    // Identifier: "a4838351-170b-41ee-914b-b491c0f06336"
    // Name: "SVI b"
    // Description: "Gives the angle between the left and right asymptotes"
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xee410b17518383a4ULL, 0x3663f0c091b44b91ULL));
    return pd;
}

/// Instrument parameter "Snap price", type "Price"
inline tbricks::Uuid SnapPrice()
{
    // Identifier: "3ed8876c-4e66-11e1-83c8-2923be84e16c"
    // Name: "Snap price"
    // Description: "Snap price"
    // Type: "Price"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe111664e6c87d83eULL, 0x6ce184be2329c883ULL));
    return pd;
}

/// Instrument parameter "Quote spread skew", type "Double"
inline tbricks::Uuid QuoteSpreadSkew()
{
    // Identifier: "4896a6cc-610d-11e0-b3de-6cd6ae529049"
    // Name: "Quote spread skew"
    // Description: "A parameter used to adjust the bias of the quote spread, set from -100 to 100. Default value is 0, which means there is no bias or skew of the quote spread. -100 means that the quote spread is initiated from the fair offer price. 100 means that the quote spread is initiated from the fair bid price."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe0110d61cca69648ULL, 0x499052aed66cdeb3ULL));
    return pd;
}

/// Instrument parameter "SVI m", type "Double"
inline tbricks::Uuid SVI_M()
{
    // Identifier: "b7253606-e0b7-4e7f-8d4e-003222a89890"
    // Name: "SVI m"
    // Description: "Translates the graph"
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0x7f4eb7e0063625b7ULL, 0x9098a82232004e8dULL));
    return pd;
}

/// Instrument parameter "Underlying forward price adjustment", type "Double"
inline tbricks::Uuid UnderlyingForwardPriceAdjustment()
{
    // Identifier: "376a8488-f73d-47f4-9087-e70d78a7e686"
    // Name: "Underlying forward price adjustment"
    // Description: "Underlying forward price adjustment"
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xf4473df788846a37ULL, 0x86e6a7780de78790ULL));
    return pd;
}

/// Instrument parameter "SVI sigma", type "Double"
inline tbricks::Uuid SVI_Sigma()
{
    // Identifier: "77174285-59bd-4a39-898e-fcc9be6f8a46"
    // Name: "SVI sigma"
    // Description: "Determines how smooth the vertex is"
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0x394abd5985421777ULL, 0x468a6fbec9fc8e89ULL));
    return pd;
}

/// Instrument parameter "Snap time to use", type "String"
inline tbricks::Uuid SnapTimeToUse()
{
    // Identifier: "660c0310-5652-11e1-83c8-e9ebb3a6db3c"
    // Name: "Snap time to use"
    // Description: "Snap time to use the specific snap set."
    // Type: "String"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe111525610030c66ULL, 0x3cdba6b3ebe9c883ULL));
    return pd;
}

/// Instrument parameter "Portfolio summation group", type "InstrumentGroup"
inline tbricks::Uuid PortfolioSummationGroup()
{
    // Identifier: "6f5cbd4e-e725-11df-9660-71daf0ebb1eb"
    // Name: "Portfolio summation group"
    // Description: ""
    // Type: "InstrumentGroup"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xdf1125e74ebd5c6fULL, 0xebb1ebf0da716096ULL));
    return pd;
}

/// Instrument parameter "Quote spread", type "Double"
inline tbricks::Uuid QuoteSpread()
{
    // Identifier: "6f5fe8cc-bcee-11df-b1f1-bd053309143e"
    // Name: "Quote spread"
    // Description: "Quote spread"
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xdf11eebccce85f6fULL, 0x3e14093305bdf1b1ULL));
    return pd;
}

/// Instrument parameter "ZCYC instrument", type "InstrumentIdentifier"
inline tbricks::Uuid ZCYC_Instrument()
{
    // Identifier: "756d11e8-61b4-11e0-92b3-3c870c3e9924"
    // Name: "ZCYC instrument"
    // Description: ""
    // Type: "InstrumentIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011b461e8116d75ULL, 0x24993e0c873cb392ULL));
    return pd;
}

/// Instrument parameter "ZCYC offset discount", type "Table"
inline tbricks::Uuid ZCYC_OffsetDiscount()
{
    // Identifier: "76ecc051-8355-11e8-b809-3c870c3e9924"
    // Name: "ZCYC offset discount"
    // Description: ""
    // Type: "Table"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe811558351c0ec76ULL, 0x24993e0c873c09b8ULL));
    return pd;
}

/// Instrument parameter "ZCYC venue", type "VenueIdentifier"
inline tbricks::Uuid ZCYC_Venue()
{
    // Identifier: "7907cd8e-61b4-11e0-92b3-3c870c3e9924"
    // Name: "ZCYC venue"
    // Description: ""
    // Type: "VenueIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011b4618ecd0779ULL, 0x24993e0c873cb392ULL));
    return pd;
}

/// Instrument parameter "Quote inside fair bid/ask allowed", type "Boolean"
inline tbricks::Uuid QuoteInsideFairBid_DIV_AskAllowed()
{
    // Identifier: "7fa04bc8-65ef-11e0-9d1f-ebb3a6db3c87"
    // Name: "Quote inside fair bid/ask allowed"
    // Description: "Quote inside fair bid/ask allowed"
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011ef65c84ba07fULL, 0x873cdba6b3eb1f9dULL));
    return pd;
}

/// Instrument parameter "Interest rate day count convention", type "Integer"
inline tbricks::Uuid InterestRateDayCountConvention()
{
    // Identifier: "845966d0-de18-11e0-92b3-870c3e99245e"
    // Name: "Interest rate day count convention"
    // Description: "Interest rate day count convention"
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe01118ded0665984ULL, 0x5e24993e0c87b392ULL));
    return pd;
}

/// Instrument parameter "SVI rho", type "Double"
inline tbricks::Uuid SVI_Rho()
{
    // Identifier: "5ee5700a-8340-4b71-885e-a59a949c804d"
    // Name: "SVI rho"
    // Description: "Determines the orientation of the graph "
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0x714b40830a70e55eULL, 0x4d809c949aa55e88ULL));
    return pd;
}

/// Instrument parameter "Ask offset", type "Integer"
inline tbricks::Uuid AskOffset()
{
    // Identifier: "7f851024-ae50-4501-a93d-03d5e4773c7a"
    // Name: "Ask offset"
    // Description: "Quote offset for MM applicable for the ask side, expressed in ticks.  The tick offset is applied after any absolute offsets."
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0x14550ae2410857fULL, 0x7a3c77e4d5033da9ULL));
    return pd;
}

/// Instrument parameter "Snap weighting", type "Double"
inline tbricks::Uuid SnapWeighting()
{
    // Identifier: "9241d0c0-517a-11e1-8d5e-84e16cd6ae52"
    // Name: "Snap weighting"
    // Description: "Snap weighting"
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe1117a51c0d04192ULL, 0x52aed66ce1845e8dULL));
    return pd;
}

/// Instrument parameter "Interest rate compounding basis", type "Integer"
inline tbricks::Uuid InterestRateCompoundingBasis()
{
    // Identifier: "93c02848-de18-11e0-92b3-870c3e99245e"
    // Name: "Interest rate compounding basis"
    // Description: "Interest rate compounding basis"
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe01118de4828c093ULL, 0x5e24993e0c87b392ULL));
    return pd;
}

/// Instrument parameter "Snap instrument", type "InstrumentIdentifier"
inline tbricks::Uuid SnapInstrument()
{
    // Identifier: "9c414854-4e65-11e1-83c8-2923be84e16c"
    // Name: "Snap instrument"
    // Description: ""
    // Type: "InstrumentIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe111654e5448419cULL, 0x6ce184be2329c883ULL));
    return pd;
}

/// Instrument parameter "Bid offset", type "Integer"
inline tbricks::Uuid BidOffset()
{
    // Identifier: "43300361-1e9c-4adb-b6a0-32b21373e9d7"
    // Name: "Bid offset"
    // Description: "Quote offset for MM applicable for the bid side, expressed in ticks.  The tick offset is applied after any absolute offsets."
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xdb4a9c1e61033043ULL, 0xd7e97313b232a0b6ULL));
    return pd;
}

/// Instrument parameter "Underlying instrument", type "InstrumentIdentifier"
inline tbricks::Uuid UnderlyingInstrument()
{
    // Identifier: "4727abae-6a17-42e0-9bc0-45425e005893"
    // Name: "Underlying instrument"
    // Description: ""
    // Type: "InstrumentIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe042176aaeab2747ULL, 0x9358005e4245c09bULL));
    return pd;
}

/// Instrument parameter "Snap time to snap", type "String"
inline tbricks::Uuid SnapTimeToSnap()
{
    // Identifier: "a2537b84-5650-11e1-83c8-e9ebb3a6db3c"
    // Name: "Snap time to snap"
    // Description: "Snap time to snap"
    // Type: "String"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe1115056847b53a2ULL, 0x3cdba6b3ebe9c883ULL));
    return pd;
}

/// Instrument parameter "Quote dime bid", type "Boolean"
inline tbricks::Uuid QuoteDimeBid()
{
    // Identifier: "a2bd5588-0d16-11e0-87b7-2923be84e16c"
    // Name: "Quote dime bid"
    // Description: "Quote dime bid"
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011160d8855bda2ULL, 0x6ce184be2329b787ULL));
    return pd;
}

/// Instrument parameter "Snap instruments", type "Table"
inline tbricks::Uuid SnapInstruments()
{
    // Identifier: "a6d552ae-4e71-11e1-83c8-2923be84e16c"
    // Name: "Snap instruments"
    // Description: ""
    // Type: "Table"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe111714eae52d5a6ULL, 0x6ce184be2329c883ULL));
    return pd;
}

/// Instrument parameter "Quote dime ask", type "Boolean"
inline tbricks::Uuid QuoteDimeAsk()
{
    // Identifier: "a7763194-0d16-11e0-87b7-2923be84e16c"
    // Name: "Quote dime ask"
    // Description: "Quote dime ask"
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011160d943176a7ULL, 0x6ce184be2329b787ULL));
    return pd;
}

/// Instrument parameter "Bid fallback price", type "Price"
inline tbricks::Uuid BidFallbackPrice()
{
    // Identifier: "a7fe82f6-0a00-11e0-87b7-99245e0d1c06"
    // Name: "Bid fallback price"
    // Description: "If the fallback price is set, it will be used by the pricing app for any calculated instrument values that depends on the bid price, but only if no other valid price is available (i.e. override price, normal bid)."
    // Type: "Price"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011000af682fea7ULL, 0x61c0d5e2499b787ULL));
    return pd;
}

/// Instrument parameter "Underlying forward price offset", type "Double"
inline tbricks::Uuid UnderlyingForwardPriceOffset()
{
    // Identifier: "c9fdeda8-ec45-47cf-b0d9-127452584691"
    // Name: "Underlying forward price offset"
    // Description: "Underlying forward price offset"
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xcf4745eca8edfdc9ULL, 0x914658527412d9b0ULL));
    return pd;
}

/// Instrument parameter "Instrument volatility", type "Double"
inline tbricks::Uuid InstrumentVolatility()
{
    // Identifier: "acb95a4f-df18-4055-825e-3009614deb60"
    // Name: "Instrument volatility"
    // Description: "Instrument volatility"
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0x554018df4f5ab9acULL, 0x60eb4d6109305e82ULL));
    return pd;
}

/// Instrument parameter "ZCYC", type "Table"
inline tbricks::Uuid ZCYC()
{
    // Identifier: "b34fe939-83c0-4d6e-816a-5bd8b5f37784"
    // Name: "ZCYC"
    // Description: ""
    // Type: "Table"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0x6e4dc08339e94fb3ULL, 0x8477f3b5d85b6a81ULL));
    return pd;
}

/// Instrument parameter "Ask override price", type "Price"
inline tbricks::Uuid AskOverridePrice()
{
    // Identifier: "8c2e857b-3146-4eb7-9862-d85466993f01"
    // Name: "Ask override price"
    // Description: "If the override price is set, it will be used by the pricing app for any calculated instrument values that depends on the ask price."
    // Type: "Price"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xb74e46317b852e8cULL, 0x13f996654d86298ULL));
    return pd;
}

/// Instrument parameter "ZCYC discount", type "Table"
inline tbricks::Uuid ZCYC_Discount()
{
    // Identifier: "c152e8b7-8352-11e8-b809-3c870c3e9924"
    // Name: "ZCYC discount"
    // Description: ""
    // Type: "Table"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe8115283b7e852c1ULL, 0x24993e0c873c09b8ULL));
    return pd;
}

/// Instrument parameter "Ask fallback price", type "Price"
inline tbricks::Uuid AskFallbackPrice()
{
    // Identifier: "c369eaa8-0a00-11e0-87b7-99245e0d1c06"
    // Name: "Ask fallback price"
    // Description: "If the fallback price is set, it will be used by the pricing app for any calculated instrument values that depends on the ask price, but only if no other valid price is available (i.e. override price, normal ask)."
    // Type: "Price"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011000aa8ea69c3ULL, 0x61c0d5e2499b787ULL));
    return pd;
}

/// Instrument parameter "Yield curve date", type "Date"
inline tbricks::Uuid YieldCurveDate()
{
    // Identifier: "d5536d12-c5c2-11e6-92b3-bbe9ebb3a6db"
    // Name: "Yield curve date"
    // Description: "Maturity date corresponding to the given point of the yield curve"
    // Type: "Date"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe611c2c5126d53d5ULL, 0xdba6b3ebe9bbb392ULL));
    return pd;
}

/// Instrument parameter "Enable historical data", type "Integer"
inline tbricks::Uuid EnableHistoricalData()
{
    // Identifier: "d798da02-1043-11e5-bcdb-d6ae529049f1"
    // Name: "Enable historical data"
    // Description: "Collect historical data."
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe511431002da98d7ULL, 0xf1499052aed6dbbcULL));
    return pd;
}

/// Instrument parameter "Snap prices", type "Table"
inline tbricks::Uuid SnapPrices()
{
    // Identifier: "e65cfe60-564e-11e1-83c8-e9ebb3a6db3c"
    // Name: "Snap prices"
    // Description: ""
    // Type: "Table"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe1114e5660fe5ce6ULL, 0x3cdba6b3ebe9c883ULL));
    return pd;
}

/// Instrument parameter "Snap set", type "Integer"
inline tbricks::Uuid SnapSet()
{
    // Identifier: "e8c503a4-564f-11e1-83c8-e9ebb3a6db3c"
    // Name: "Snap set"
    // Description: "Snap set"
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe1114f56a403c5e8ULL, 0x3cdba6b3ebe9c883ULL));
    return pd;
}

/// Instrument parameter "Maturity", type "Integer"
inline tbricks::Uuid Maturity()
{
    // Identifier: "1c301c3f-eba5-47a1-ad50-cd7190634e19"
    // Name: "Maturity"
    // Description: "Maturity"
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xa147a5eb3f1c301cULL, 0x194e639071cd50adULL));
    return pd;
}

/// Instrument parameter "Bid override price", type "Price"
inline tbricks::Uuid BidOverridePrice()
{
    // Identifier: "88cf4d04-9f33-4e20-97e5-359cb9c1d66e"
    // Name: "Bid override price"
    // Description: "If the override price is set, it will be used by the pricing app for any calculated instrument values that depends on the bid price."
    // Type: "Price"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0x204e339f044dcf88ULL, 0x6ed6c1b99c35e597ULL));
    return pd;
}

}

namespace instrument_attributes {

/// Instrument attribute "Instrument multiplier", type "Double"
inline tbricks::InstrumentAttributeDefinition InstrumentMultiplier()
{
    // Identifier: "cf282516-9650-11e4-98c0-1ed9c9edf20b"
    // Name: "Instrument multiplier"
    // Description: "The instrument multiplier is used in portfolio calculations for key values like delta and gamma. It is the number of underlying assets which one unit of a derivative contract corresponds to."
    // Type: "Double"
    // FIXML: " /FIXML/SecDef/Instrmt/@Mult"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4115096162528cfULL, 0xbf2edc9d91ec098ULL));
    return pd;
}

/// Instrument attribute "Related option", type "Identifier"
inline tbricks::InstrumentAttributeDefinition RelatedOption()
{
    // Identifier: "3354fce4-b2ad-11e4-81d0-e2171d254d49"
    // Name: "Related option"
    // Description: "Related option."
    // Type: "Identifier"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe411adb2e4fc5433ULL, 0x494d251d17e2d081ULL));
    return pd;
}

/// Instrument attribute "Additional security identifier", type "String"
inline tbricks::InstrumentAttributeDefinition AdditionalSecurityIdentifier()
{
    // Identifier: "e5ea1a92-964c-11e4-ae80-62922e696620"
    // Name: "Additional security identifier"
    // Description: ""
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Instrmt/@ID"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4114c96921aeae5ULL, 0x2066692e926280aeULL));
    return pd;
}

/// Instrument attribute "Coupon payment date", type "DateTime"
inline tbricks::InstrumentAttributeDefinition CouponPaymentDate()
{
    // Identifier: "d7c9a672-9650-11e4-b9a0-e1d54a842b8d"
    // Name: "Coupon payment date"
    // Description: "Coupon payment date"
    // Type: "DateTime"
    // FIXML: " /FIXML/SecDef/Instrmt/@CpnPmt"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe411509672a6c9d7ULL, 0x8d2b844ad5e1a0b9ULL));
    return pd;
}

/// Instrument attribute "CapPrice", type "Price"
inline tbricks::InstrumentAttributeDefinition CapPrice()
{
    // Identifier: "6d5cec56-dc35-11e4-9180-49167c0aa8ab"
    // Name: "CapPrice"
    // Description: "Used to express the ceiling price of a capped call"
    // Type: "Price"
    // FIXML: " /FIXML/SecDef/Instrmt/@CapPx"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41135dc56ec5c6dULL, 0xaba80a7c16498091ULL));
    return pd;
}

/// Instrument attribute "Settlement tenor", type "String"
inline tbricks::InstrumentAttributeDefinition SettlementTenor()
{
    // Identifier: "25c8f98e-1e00-11e7-abe9-e16cd6ae5290"
    // Name: "Settlement tenor"
    // Description: "Indicates order settlement period."
    // Type: "String"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711001e8ef9c825ULL, 0x9052aed66ce1e9abULL));
    return pd;
}

/// Instrument attribute "Additional security identifier source", type "String"
inline tbricks::InstrumentAttributeDefinition AdditionalSecurityIdentifierSource()
{
    // Identifier: "e9624ac4-9650-11e4-a8b0-e21732535de8"
    // Name: "Additional security identifier source"
    // Description: ""
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Instrmt/@Src"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4115096c44a62e9ULL, 0xe85d533217e2b0a8ULL));
    return pd;
}

/// Instrument attribute "Combo leg price averaging logic", type "Integer"
inline tbricks::InstrumentAttributeDefinition ComboLegPriceAveragingLogic()
{
    // Identifier: "3e0d1400-26ef-11e8-9050-ed32bb8df854"
    // Name: "Combo leg price averaging logic"
    // Description: "Method used to average the legs of combinations that require price averaging logic"
    // Type: "Integer"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811ef2600140d3eULL, 0x54f88dbb32ed5090ULL));
    return pd;
}

/// Instrument attribute "Maturity date", type "DateTime"
inline tbricks::InstrumentAttributeDefinition MaturityDate()
{
    // Identifier: "d4f8b28e-964c-11e4-a960-c279a98890e6"
    // Name: "Maturity date"
    // Description: "Maturity date"
    // Type: "DateTime"
    // FIXML: " /FIXML/SecDef/Instrmt/@MatDt"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4114c968eb2f8d4ULL, 0xe69088a979c260a9ULL));
    return pd;
}

/// Instrument attribute "Underlying price level", type "Price"
inline tbricks::InstrumentAttributeDefinition UnderlyingPriceLevel()
{
    // Identifier: "dea7a278-9650-11e4-b6b0-11764e01d6d7"
    // Name: "Underlying price level"
    // Description: "Underlying price level for delta neutrals."
    // Type: "Price"
    // FIXML: " /FIXML/SecDef/Instrmt/@Px"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe411509678a2a7deULL, 0xd7d6014e7611b0b6ULL));
    return pd;
}

/// Instrument attribute "Maturity time", type "String"
inline tbricks::InstrumentAttributeDefinition MaturityTime()
{
    // Identifier: "e3cdfffe-9650-11e4-8e50-4bcd8871fed0"
    // Name: "Maturity time"
    // Description: "Maturity time"
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Instrmt/@MatTm"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4115096feffcde3ULL, 0xd0fe7188cd4b508eULL));
    return pd;
}

/// Instrument attribute "Component ratio divisor", type "Double"
inline tbricks::InstrumentAttributeDefinition ComponentRatioDivisor()
{
    // Identifier: "b3c0db2b-554e-11e5-9052-23be84e16cd6"
    // Name: "Component ratio divisor"
    // Description: "Divides all component ratios. Used to express basket ratios as number of shares per index future."
    // Type: "Double"
    // FIXML: " /FIXML/SecDef/Instrmt/@BasketDivisor"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe5114e552bdbc0b3ULL, 0xd66ce184be235290ULL));
    return pd;
}

/// Instrument attribute "Settlement currency", type "Currency"
inline tbricks::InstrumentAttributeDefinition SettlementCurrency()
{
    // Identifier: "f7ef79f8-ecf5-11e4-9120-c24df61d5b69"
    // Name: "Settlement currency"
    // Description: "Currency code of settlement denomination."
    // Type: "Currency"
    // FIXML: " /FIXML/SecDef/Instrmt/@SettlCcy"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe411f5ecf879eff7ULL, 0x695b1df64dc22091ULL));
    return pd;
}

/// Instrument attribute "Issuer", type "String"
inline tbricks::InstrumentAttributeDefinition Issuer()
{
    // Identifier: "f1876734-9650-11e4-a340-86268c188d1f"
    // Name: "Issuer"
    // Description: "The issuer of the instrument."
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Instrmt/@Issr"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4115096346787f1ULL, 0x1f8d188c268640a3ULL));
    return pd;
}

/// Instrument attribute "Instrument value factor", type "Double"
inline tbricks::InstrumentAttributeDefinition InstrumentValueFactor()
{
    // Identifier: "f70d00f6-9650-11e4-8160-cb06ae13326c"
    // Name: "Instrument value factor"
    // Description: "The instrument value factor is used to calculate the cash value for one lot of an instrument at a given price. It is used in both limit calculations and in gross trade amounts as well as in the market value of a position."
    // Type: "Double"
    // FIXML: " /FIXML/SecDef/Instrmt/@Fctr"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4115096f6000df7ULL, 0x6c3213ae06cb6081ULL));
    return pd;
}

/// Instrument attribute "Country of issue", type "String"
inline tbricks::InstrumentAttributeDefinition CountryOfIssue()
{
    // Identifier: "fc35fb5a-9650-11e4-b060-e81c14d78a14"
    // Name: "Country of issue"
    // Description: "The country of issue for the instrument."
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Instrmt/@IssuCtry"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41150965afb35fcULL, 0x148ad7141ce860b0ULL));
    return pd;
}

/// Instrument attribute "Option pay amount", type "String"
inline tbricks::InstrumentAttributeDefinition OptionPayAmount()
{
    // Identifier: "df6b74fe-964c-11e4-9dd0-cb8b17203652"
    // Name: "Option pay amount"
    // Description: ""
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Instrmt/@OptPayAmt"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4114c96fe746bdfULL, 0x523620178bcbd09dULL));
    return pd;
}

/// Instrument attribute "Instrument CFI", type "String"
inline tbricks::InstrumentAttributeDefinition InstrumentCFI()
{
    // Identifier: "44f39a4e-dc35-11e4-81e0-c3aecff95d35"
    // Name: "Instrument CFI"
    // Description: "Leg's CFI"
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Leg/@CFI"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41135dc4e9af344ULL, 0x355df9cfaec3e081ULL));
    return pd;
}

/// Instrument attribute "Instrument currency", type "Currency"
inline tbricks::InstrumentAttributeDefinition InstrumentCurrency()
{
    // Identifier: "72c8d178-dc35-11e4-baf0-9a53417c96e2"
    // Name: "Instrument currency"
    // Description: "Currency"
    // Type: "Currency"
    // FIXML: " /FIXML/SecDef/@Ccy"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41135dc78d1c872ULL, 0xe2967c41539af0baULL));
    return pd;
}

/// Instrument attribute "Barrier period", type "Duration"
inline tbricks::InstrumentAttributeDefinition BarrierPeriod()
{
    // Identifier: "67a50d5c-dc35-11e4-b2a0-edfbe935993c"
    // Name: "Barrier period"
    // Description: "Predefined time period when rebate is defined."
    // Type: "Duration"
    // FIXML: " /FIXML/SecDef/Instrmt/@BarrierPeriod"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41135dc5c0da567ULL, 0x3c9935e9fbeda0b2ULL));
    return pd;
}

/// Instrument attribute "Security sub-type", type "String"
inline tbricks::InstrumentAttributeDefinition SecuritySubType()
{
    // Identifier: "5f20c586-dc35-11e4-9c00-e650414c1d4d"
    // Name: "Security sub-type"
    // Description: "Sub-type qualification/identification of the SecurityType"
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Instrmt/@SubTyp"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41135dc86c5205fULL, 0x4d1d4c4150e6009cULL));
    return pd;
}

/// Instrument attribute "Leverage", type "Double"
inline tbricks::InstrumentAttributeDefinition Leverage()
{
    // Identifier: "86c0f190-77f5-11e5-aed6-2923be84e16c"
    // Name: "Leverage"
    // Description: "Leverage ratio for ETFs/ETNs expressed in percent."
    // Type: "Double"
    // FIXML: " /FIXML/SecDef/Instrmt/@Leverage"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe511f57790f1c086ULL, 0x6ce184be2329d6aeULL));
    return pd;
}

/// Instrument attribute "Upper strike price", type "Price"
inline tbricks::InstrumentAttributeDefinition UpperStrikePrice()
{
    // Identifier: "89776ca2-6a22-11e9-abe9-e16cd6ae5290"
    // Name: "Upper strike price"
    // Description: "Upper strike for inline warrants"
    // Type: "Price"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe911226aa26c7789ULL, 0x9052aed66ce1e9abULL));
    return pd;
}

/// Instrument attribute "Product", type "String"
inline tbricks::InstrumentAttributeDefinition Product()
{
    // Identifier: "c695a84e-ea81-11e4-b8a0-eec4f2843648"
    // Name: "Product"
    // Description: "Indicates the type of product the security is associated with. "
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Leg/@Prod"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41181ea4ea895c6ULL, 0x483684f2c4eea0b8ULL));
    return pd;
}

/// Instrument attribute "Barrier level", type "Price"
inline tbricks::InstrumentAttributeDefinition BarrierLevel()
{
    // Identifier: "035f8d24-9651-11e4-ace0-fc26190eaa22"
    // Name: "Barrier level"
    // Description: "Barrier level"
    // Type: "Price"
    // FIXML: " /FIXML/SecDef/Instrmt/@BarrierLevel"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4115196248d5f03ULL, 0x22aa0e1926fce0acULL));
    return pd;
}

/// Instrument attribute "Primary market", type "MIC"
inline tbricks::InstrumentAttributeDefinition PrimaryMarket()
{
    // Identifier: "0a9061b8-9651-11e4-b520-895f4ff1355f"
    // Name: "Primary market"
    // Description: "Primary market of listing."
    // Type: "MIC"
    // FIXML: " /FIXML/SecDef/Instrmt/@HomeExchange"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4115196b861900aULL, 0x5f35f14f5f8920b5ULL));
    return pd;
}

/// Instrument attribute "Shares issued", type "Integer"
inline tbricks::InstrumentAttributeDefinition SharesIssued()
{
    // Identifier: "114998a8-9651-11e4-b4b0-eff91f1bb711"
    // Name: "Shares issued"
    // Description: "Shares issued"
    // Type: "Integer"
    // FIXML: " /FIXML/SecDef/Instrmt/@NoSharesIssued"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4115196a8984911ULL, 0x11b71b1ff9efb0b4ULL));
    return pd;
}

/// Instrument attribute "Option attribute", type "String"
inline tbricks::InstrumentAttributeDefinition OptionAttribute()
{
    // Identifier: "ebdd8c5e-964c-11e4-8640-4e62f8c7225d"
    // Name: "Option attribute"
    // Description: "Option attribute"
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Instrmt/@OptAt"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4114c965e8cddebULL, 0x5d22c7f8624e4086ULL));
    return pd;
}

/// Instrument attribute "Votes per share", type "Double"
inline tbricks::InstrumentAttributeDefinition VotesPerShare()
{
    // Identifier: "18007540-9651-11e4-a6e0-4462e2abc0e0"
    // Name: "Votes per share"
    // Description: "Votes per share"
    // Type: "Double"
    // FIXML: " /FIXML/SecDef/Instrmt/@NoVotesPerShare"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe411519640750018ULL, 0xe0c0abe26244e0a6ULL));
    return pd;
}

/// Instrument attribute "Security group", type "String"
inline tbricks::InstrumentAttributeDefinition SecurityGroup()
{
    // Identifier: "51b097e8-6b67-11e5-b470-fff5e32ceadd"
    // Name: "Security group"
    // Description: "Security group"
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Instrmt/@SecGrp"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe511676be897b051ULL, 0xddea2ce3f5ff70b4ULL));
    return pd;
}

/// Instrument attribute "UMTF", type "String"
inline tbricks::InstrumentAttributeDefinition UMTF()
{
    // Identifier: "a8ff4872-68cc-11e8-8800-6fa86d2ae78c"
    // Name: "UMTF"
    // Description: "Uniform Symbology"
    // Type: "String"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811cc687248ffa8ULL, 0x8ce72a6da86f0088ULL));
    return pd;
}

/// Instrument attribute "Combo leg base price source", type "Integer"
inline tbricks::InstrumentAttributeDefinition ComboLegBasePriceSource()
{
    // Identifier: "a9899656-2869-11e8-8d00-c7ec5179d5ee"
    // Name: "Combo leg base price source"
    // Description: "Base price used in combo leg price averaging logic. Usually a settlement price or a close price"
    // Type: "Integer"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe8116928569689a9ULL, 0xeed57951ecc7008dULL));
    return pd;
}

/// Instrument attribute "Instrument side", type "Integer"
inline tbricks::InstrumentAttributeDefinition InstrumentSide()
{
    // Identifier: "509cca5a-dc35-11e4-aba0-c9a1bd4937af"
    // Name: "Instrument side"
    // Description: "Instrument side"
    // Type: "Integer"
    // FIXML: " /FIXML/SecDef/Leg/@Side"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41135dc5aca9c50ULL, 0xaf3749bda1c9a0abULL));
    return pd;
}

/// Instrument attribute "Order book identifier", type "String"
inline tbricks::InstrumentAttributeDefinition OrderBookIdentifier()
{
    // Identifier: "af3cb7e9-b90a-11e5-945d-0c3e99245e0d"
    // Name: "Order book identifier"
    // Description: "Unique instrument identifier in SD environment"
    // Type: "String"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe5110ab9e9b73cafULL, 0xd5e24993e0c5d94ULL));
    return pd;
}

/// Instrument attribute "Secondary instrument id", type "String"
inline tbricks::InstrumentAttributeDefinition SecondaryInstrumentId()
{
    // Identifier: "b247ae8a-6061-11e6-945d-0c3e99245e0d"
    // Name: "Secondary instrument id"
    // Description: "Unique instrument identifier on venue in SD environment"
    // Type: "String"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe61161608aae47b2ULL, 0xd5e24993e0c5d94ULL));
    return pd;
}

/// Instrument attribute "Barrier rebate", type "Double"
inline tbricks::InstrumentAttributeDefinition BarrierRebate()
{
    // Identifier: "1dfdbd18-9651-11e4-a440-5158ae5b2891"
    // Name: "Barrier rebate"
    // Description: "Barrier rebate"
    // Type: "Double"
    // FIXML: " /FIXML/SecDef/Instrmt/@BarrierRebate"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe411519618bdfd1dULL, 0x91285bae585140a4ULL));
    return pd;
}

/// Instrument attribute "Market Segment ID", type "String"
inline tbricks::InstrumentAttributeDefinition MarketSegmentID()
{
    // Identifier: "b72ded3c-7e45-11e5-92b3-bbe9ebb3a6db"
    // Name: "Market Segment ID"
    // Description: "Identifies the market segment"
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Instrmt/@MktSegID"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe511457e3ced2db7ULL, 0xdba6b3ebe9bbb392ULL));
    return pd;
}

/// Instrument attribute "NordicMidEligible", type "Boolean"
inline tbricks::InstrumentAttributeDefinition NordicMidEligible()
{
    // Identifier: "ba1438fa-5b1a-11e6-a6b3-6cd6ae529049"
    // Name: "NordicMidEligible"
    // Description: "Describes if the orderbook is eligible to participate in Nordic@Mid crossing."
    // Type: "Boolean"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe6111a5bfa3814baULL, 0x499052aed66cb3a6ULL));
    return pd;
}

/// Instrument attribute "Instrument barrier crossed", type "Boolean"
inline tbricks::InstrumentAttributeDefinition InstrumentBarrierCrossed()
{
    // Identifier: "7aba96e0-dc36-11e4-8050-6571aefc4677"
    // Name: "Instrument barrier crossed"
    // Description: "Defines if a barrier-option has reached the barrier-level or not."
    // Type: "Boolean"
    // FIXML: " /FIXML/SecDef/Instrmt/@BarrierCrossed"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41136dce096ba7aULL, 0x7746fcae71655080ULL));
    return pd;
}

/// Instrument attribute "Lower strike price", type "Price"
inline tbricks::InstrumentAttributeDefinition LowerStrikePrice()
{
    // Identifier: "c3164046-6a22-11e9-abe9-e16cd6ae5290"
    // Name: "Lower strike price"
    // Description: "Lower strike for inline warrants"
    // Type: "Price"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe911226a464016c3ULL, 0x9052aed66ce1e9abULL));
    return pd;
}

/// Instrument attribute "Strike currency", type "Currency"
inline tbricks::InstrumentAttributeDefinition StrikeCurrency()
{
    // Identifier: "240e8b7e-9651-11e4-8d40-72bc69334495"
    // Name: "Strike currency"
    // Description: "Strike currency"
    // Type: "Currency"
    // FIXML: " /FIXML/SecDef/Instrmt/@StrkCcy"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41151967e8b0e24ULL, 0x95443369bc72408dULL));
    return pd;
}

/// Instrument attribute "Symbol", type "String"
inline tbricks::InstrumentAttributeDefinition Symbol()
{
    // Identifier: "f182eaaa-964c-11e4-afb0-4a3ab27cbd20"
    // Name: "Symbol"
    // Description: "Common, human understandable representation of the security. FIX tag 55."
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Instrmt/@Sym"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4114c96aaea82f1ULL, 0x20bd7cb23a4ab0afULL));
    return pd;
}

/// Instrument attribute "Maturity month/year", type "DateTime"
inline tbricks::InstrumentAttributeDefinition MaturityMonth_DIV_Year()
{
    // Identifier: "f75df7bc-964c-11e4-84c0-4f0716c8e5d2"
    // Name: "Maturity month/year"
    // Description: "Maturiy month/year"
    // Type: "DateTime"
    // FIXML: " /FIXML/SecDef/Instrmt/@MMY"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4114c96bcf75df7ULL, 0xd2e5c816074fc084ULL));
    return pd;
}

/// Instrument attribute "Instrument ratio", type "Double"
inline tbricks::InstrumentAttributeDefinition InstrumentRatio()
{
    // Identifier: "497ab9f8-dc35-11e4-9070-567239bed6e1"
    // Name: "Instrument ratio"
    // Description: "Instrument ratio"
    // Type: "Double"
    // FIXML: " /FIXML/SecDef/Leg/@Ratio"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41135dcf8b97a49ULL, 0xe1d6be3972567090ULL));
    return pd;
}

/// Instrument attribute "Product Complex", type "Integer"
inline tbricks::InstrumentAttributeDefinition ProductComplex()
{
    // Identifier: "cbb78082-0d57-11e6-b596-99245e0d1c06"
    // Name: "Product Complex"
    // Description: "Deutsche Boerse Product Complex"
    // Type: "Integer"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe611570d8280b7cbULL, 0x61c0d5e249996b5ULL));
    return pd;
}

/// Instrument attribute "Base currency", type "Currency"
inline tbricks::InstrumentAttributeDefinition BaseCurrency()
{
    // Identifier: "d3e98a70-09f4-11e0-897d-0d1c06b747de"
    // Name: "Base currency"
    // Description: "Base currency"
    // Type: "Currency"
    // FIXML: " "
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe011f409708ae9d3ULL, 0xde47b7061c0d7d89ULL));
    return pd;
}

/// Instrument attribute "Strike price", type "Price"
inline tbricks::InstrumentAttributeDefinition StrikePrice()
{
    // Identifier: "fd58e000-964c-11e4-9370-50d000970b6e"
    // Name: "Strike price"
    // Description: "Strike price"
    // Type: "Price"
    // FIXML: " /FIXML/SecDef/Instrmt/@StrkPx"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe4114c9600e058fdULL, 0x6e0b9700d0507093ULL));
    return pd;
}

/// Instrument attribute "Coupon rate", type "Double"
inline tbricks::InstrumentAttributeDefinition CouponRate()
{
    // Identifier: "2addd306-9651-11e4-b730-859a3ce79d3f"
    // Name: "Coupon rate"
    // Description: "Coupon rate"
    // Type: "Double"
    // FIXML: " /FIXML/SecDef/Instrmt/@CpnRt"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe411519606d3dd2aULL, 0x3f9de73c9a8530b7ULL));
    return pd;
}

/// Instrument attribute "Issue date", type "DateTime"
inline tbricks::InstrumentAttributeDefinition IssueDate()
{
    // Identifier: "327a256a-9651-11e4-b260-583a430154ff"
    // Name: "Issue date"
    // Description: "The date of issue for the instrument."
    // Type: "DateTime"
    // FIXML: " /FIXML/SecDef/Instrmt/@Issued"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41151966a257a32ULL, 0xff5401433a5860b2ULL));
    return pd;
}

/// Instrument attribute "Security exchange", type "String"
inline tbricks::InstrumentAttributeDefinition SecurityExchange()
{
    // Identifier: "69cf90f2-ea81-11e4-b2d0-30455f4f357e"
    // Name: "Security exchange"
    // Description: "Market used to help identify a security."
    // Type: "String"
    // FIXML: " /FIXML/SecDef/Leg/@Exch"
    tbricks::InstrumentAttributeDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe41181eaf290cf69ULL, 0x7e354f5f4530d0b2ULL));
    return pd;
}

}

namespace strategy_parameters {

/// Strategy parameter "Price", type "Price"
inline tbricks::ParameterDefinition Price()
{
    // Identifier: "6c7f3529-5615-42b4-9456-6efc32167f15"
    // Name: "Price"
    // Description: "The price for the instrument (in a strategy, order or trade)."
    // Type: "Price"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xb442155629357f6cULL, 0x157f1632fc6e5694ULL));
    return pd;
}

/// Strategy parameter "Exchange volume limit for MM", type "Double"
inline tbricks::ParameterDefinition ExchangeVolumeLimitForMM()
{
    // Identifier: "01511204-246f-11e9-9a20-b747deb3124d"
    // Name: "Exchange volume limit for MM"
    // Description: "Actual summation of traded delta including multipliers in the specified underlying group, as specified by the exchange."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9116f2404125101ULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "MIC", type "MIC"
inline tbricks::ParameterDefinition MIC()
{
    // Identifier: "78d1ba99-e183-4531-addb-52c0bb460da5"
    // Name: "MIC"
    // Description: "Shows market information code (MIC) which represents a trading destination or market data feed source used for a venue."
    // Type: "MIC"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0x314583e199bad178ULL, 0xa50d46bbc052dbadULL));
    return pd;
}

/// Strategy parameter "Price improvement not allowed", type "Boolean"
inline tbricks::ParameterDefinition PriceImprovementNotAllowed()
{
    // Identifier: "0c27f20a-6e05-11e7-bbf1-84e16cd6ae52"
    // Name: "Price improvement not allowed"
    // Description: "Indicates whether the price improvement is allowed or not."
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711056e0af2270cULL, 0x52aed66ce184f1bbULL));
    return pd;
}

/// Strategy parameter "Cash value limit", type "Double"
inline tbricks::ParameterDefinition CashValueLimit()
{
    // Identifier: "0e1a37ff-584f-11e9-8a89-0d1c06b747de"
    // Name: "Cash value limit"
    // Description: "Maximum allowed cash value of a single transaction."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9114f58ff371a0eULL, 0xde47b7061c0d898aULL));
    return pd;
}

/// Strategy parameter "Handler", type "TreeNodeIdentifier"
inline tbricks::ParameterDefinition Handler()
{
    // Identifier: "120c7193-3a25-11e6-9e47-f1bbe9ebb3a6"
    // Name: "Handler"
    // Description: "Node in a tree that represent the managing entity of strategy and/or orders."
    // Type: "TreeNodeIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe611253a93710c12ULL, 0xa6b3ebe9bbf1479eULL));
    return pd;
}

/// Strategy parameter "Limit currency", type "Currency"
inline tbricks::ParameterDefinition LimitCurrency()
{
    // Identifier: "131937a5-5dd3-11e8-8c87-ae529049f1f1"
    // Name: "Limit currency"
    // Description: "Defines currency of a limit."
    // Type: "Currency"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d35da5371913ULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Instrument", type "InstrumentIdentifier"
inline tbricks::ParameterDefinition Instrument()
{
    // Identifier: "4862f28d-10ab-46f1-93c5-4c97e2048368"
    // Name: "Instrument"
    // Description: "The internal Tbricks instrument identifier."
    // Type: "InstrumentIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xf146ab108df26248ULL, 0x688304e2974cc593ULL));
    return pd;
}

/// Strategy parameter "Audit snapshot datetime", type "DateTime"
inline tbricks::ParameterDefinition AuditSnapshotDatetime()
{
    // Identifier: "18b592ec-3901-11ea-aedb-245e0d1c06b7"
    // Name: "Audit snapshot datetime"
    // Description: ""
    // Type: "DateTime"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea110139ec92b518ULL, 0xb7061c0d5e24dbaeULL));
    return pd;
}

/// Strategy parameter "Algo label description", type "String"
inline tbricks::ParameterDefinition AlgoLabelDescription()
{
    // Identifier: "1b24782c-9fa1-11e3-993e-49f1f1bbe9eb"
    // Name: "Algo label description"
    // Description: "Algo label description."
    // Type: "String"
    // Persistence: "Buffered"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe311a19f2c78241bULL, 0xebe9bbf1f1493e99ULL));
    return pd;
}

/// Strategy parameter "Hidden exposure volume limit for MM", type "Double"
inline tbricks::ParameterDefinition HiddenExposureVolumeLimitForMM()
{
    // Identifier: "1bdd6b04-246f-11e9-9a20-b747deb3124d"
    // Name: "Hidden exposure volume limit for MM"
    // Description: "Maximum gross volume of hidden orders sent in time window."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9116f24046bdd1bULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Participation policy", type "Integer"
inline tbricks::ParameterDefinition ParticipationPolicy()
{
    // Identifier: "1bf53f2f-530a-11e6-9e47-f1bbe9ebb3a6"
    // Name: "Participation policy"
    // Description: "Participation policy defines what liquidity to access through the order."
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe6110a532f3ff51bULL, 0xa6b3ebe9bbf1479eULL));
    return pd;
}

/// Strategy parameter "Market making limit id", type "Double"
inline tbricks::ParameterDefinition MarketMakingLimitId()
{
    // Identifier: "1c9c4d6c-2613-11e9-9a20-b747deb3124d"
    // Name: "Market making limit id"
    // Description: ""
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91113266c4d9c1cULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Creations per app instance", type "Integer"
inline tbricks::ParameterDefinition CreationsPerAppInstance()
{
    // Identifier: "1d9df656-2470-11e9-9a20-b747deb3124d"
    // Name: "Creations per app instance"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe911702456f69d1dULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Volume limit", type "Double"
inline tbricks::ParameterDefinition VolumeLimit()
{
    // Identifier: "2041a675-584f-11e9-8a89-0d1c06b747de"
    // Name: "Volume limit"
    // Description: "Maximum allowed volume of a single transaction."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9114f5875a64120ULL, 0xde47b7061c0d898aULL));
    return pd;
}

/// Strategy parameter "Left angle", type "Double"
inline tbricks::ParameterDefinition LeftAngle()
{
    // Identifier: "2d184876-3019-11e3-83c8-529049f1f1bb"
    // Name: "Left angle"
    // Description: ""
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe31119307648182dULL, 0xbbf1f1499052c883ULL));
    return pd;
}

/// Strategy parameter "QS aggregated notional value", type "Double"
inline tbricks::ParameterDefinition QS_AggregatedNotionalValue()
{
    // Identifier: "2f7df318-110e-11ea-b2ae-06b747deb312"
    // Name: "QS aggregated notional value"
    // Description: "Maximum allowed aggregated notional value per quote set."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea110e1118f37d2fULL, 0x12b3de47b706aeb2ULL));
    return pd;
}

/// Strategy parameter "Throughput limit id", type "Double"
inline tbricks::ParameterDefinition ThroughputLimitId()
{
    // Identifier: "30bd495e-2613-11e9-9a20-b747deb3124d"
    // Name: "Throughput limit id"
    // Description: ""
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91113265e49bd30ULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Counterpart condition", type "TreeNodeIdentifier"
inline tbricks::ParameterDefinition CounterpartCondition()
{
    // Identifier: "3299d936-f016-11e9-9f25-870c3e99245e"
    // Name: "Counterpart condition"
    // Description: "Filter condition which defines to which counterpart should a limit rule be applied. Empty means that a rule applies to all counterparts."
    // Type: "TreeNodeIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91116f036d99932ULL, 0x5e24993e0c87259fULL));
    return pd;
}

/// Strategy parameter "Soft volume limit", type "Volume"
inline tbricks::ParameterDefinition SoftVolumeLimit()
{
    // Identifier: "343d2307-584f-11e9-8a89-0d1c06b747de"
    // Name: "Soft volume limit"
    // Description: "Maximum allowed volume of a single transaction. This limit can be bypassed if "Bypass soft limits" flag is present in the transaction."
    // Type: "Volume"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9114f5807233d34ULL, 0xde47b7061c0d898aULL));
    return pd;
}

/// Strategy parameter "Side", type "Side"
inline tbricks::ParameterDefinition Side()
{
    // Identifier: "1a010a05-ab5b-4c0a-b423-c722392b37e9"
    // Name: "Side"
    // Description: "Indicates if it is a buy or sell side for the object."
    // Type: "Side"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xa4c5bab050a011aULL, 0xe9372b3922c723b4ULL));
    return pd;
}

/// Strategy parameter "Group condition", type "InstrumentGroup"
inline tbricks::ParameterDefinition GroupCondition()
{
    // Identifier: "3c688706-5dd1-11e8-8c87-ae529049f1f1"
    // Name: "Group condition"
    // Description: "Filter condition which defines to which group should a limit rule be applied. Empty means that a rule applies to all groups."
    // Type: "InstrumentGroup"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d15d0687683cULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Role condition", type "TreeNodeIdentifier"
inline tbricks::ParameterDefinition RoleCondition()
{
    // Identifier: "3d7ff95d-bcf0-11e8-8c87-ae529049f1f1"
    // Name: "Role condition"
    // Description: "Filter condition which defines to which role should a limit rule be applied. Empty means that a rule applies to all roles."
    // Type: "TreeNodeIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811f0bc5df97f3dULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Use primary market data", type "Boolean"
inline tbricks::ParameterDefinition UsePrimaryMarketData()
{
    // Identifier: "4074bfe4-0737-11e9-b596-99245e0d1c06"
    // Name: "Use primary market data"
    // Description: "Use "Primary market" instrument attribute value to handle market data."
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9113707e4bf7440ULL, 0x61c0d5e249996b5ULL));
    return pd;
}

/// Strategy parameter "Modifications per app instance", type "Integer"
inline tbricks::ParameterDefinition ModificationsPerAppInstance()
{
    // Identifier: "44ea2ec8-2470-11e9-9a20-b747deb3124d"
    // Name: "Modifications per app instance"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9117024c82eea44ULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Minimum acceptable volume", type "Volume"
inline tbricks::ParameterDefinition MinimumAcceptableVolume()
{
    // Identifier: "4aa1b2de-e1e1-11e5-9e24-9049f1f1bbe9"
    // Name: "Minimum acceptable volume"
    // Description: "The minimum acceptable volume to be filled for the entered order."
    // Type: "Volume"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe511e1e1deb2a14aULL, 0xe9bbf1f14990249eULL));
    return pd;
}

/// Strategy parameter "Right angle", type "Double"
inline tbricks::ParameterDefinition RightAngle()
{
    // Identifier: "502ea834-3019-11e3-83c8-529049f1f1bb"
    // Name: "Right angle"
    // Description: ""
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe311193034a82e50ULL, 0xbbf1f1499052c883ULL));
    return pd;
}

/// Strategy parameter "Retain on disconnect", type "Boolean"
inline tbricks::ParameterDefinition RetainOnDisconnect()
{
    // Identifier: "2476608b-4fd5-4341-82c9-b8ad10e74637"
    // Name: "Retain on disconnect"
    // Description: "Indicates that the order retains its order on venue when disconnected from it."
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0x4143d54f8b607624ULL, 0x3746e710adb8c982ULL));
    return pd;
}

/// Strategy parameter "Market model class", type "Integer"
inline tbricks::ParameterDefinition MarketModelClass()
{
    // Identifier: "55335cae-ed15-11e5-9052-23be84e16cd6"
    // Name: "Market model class"
    // Description: "Market model class."
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe51115edae5c3355ULL, 0xd66ce184be235290ULL));
    return pd;
}

/// Strategy parameter "Instrument condition", type "InstrumentIdentifier"
inline tbricks::ParameterDefinition InstrumentCondition()
{
    // Identifier: "55db6173-5dd1-11e8-8c87-ae529049f1f1"
    // Name: "Instrument condition"
    // Description: "Filter condition which defines to which instrument should a limit rule be applied. Empty means that a rule applies to all instruments."
    // Type: "InstrumentIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d15d7361db55ULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Time window for MM hidden exposure limit", type "Double"
inline tbricks::ParameterDefinition TimeWindowForMM_HiddenExposureLimit()
{
    // Identifier: "5b4ac73c-246f-11e9-9a20-b747deb3124d"
    // Name: "Time window for MM hidden exposure limit"
    // Description: "Time window for hidden exposure limit (in seconds)."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9116f243cc74a5bULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Allow horizontal move", type "Boolean"
inline tbricks::ParameterDefinition AllowHorizontalMove()
{
    // Identifier: "5c152c36-cdc0-11e2-83c8-3c870c3e9924"
    // Name: "Allow horizontal move"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe211c0cd362c155cULL, 0x24993e0c873cc883ULL));
    return pd;
}

/// Strategy parameter "MIC condition", type "MIC"
inline tbricks::ParameterDefinition MIC_Condition()
{
    // Identifier: "5d52becc-bcf0-11e8-8c87-ae529049f1f1"
    // Name: "MIC condition"
    // Description: "Filter condition which defines to which MIC should a limit rule be applied. Empty means that a rule applies to all MICs."
    // Type: "MIC"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811f0bcccbe525dULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Snapshot limit", type "Integer"
inline tbricks::ParameterDefinition SnapshotLimit()
{
    // Identifier: "5e457a75-2099-11e9-bb43-ebb3a6db3c87"
    // Name: "Snapshot limit"
    // Description: "Defines the maximum amount of updates to deliver in a snapshot"
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9119920757a455eULL, 0x873cdba6b3eb43bbULL));
    return pd;
}

/// Strategy parameter "Trading message type condition", type "Integer"
inline tbricks::ParameterDefinition TradingMessageTypeCondition()
{
    // Identifier: "641d644a-45ae-11e9-b809-3c870c3e9924"
    // Name: "Trading message type condition"
    // Description: "Filter condition which defines to which trading message type should a limit rule be applied. Empty means that a rule applies to all trading message types."
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe911ae454a641d64ULL, 0x24993e0c873c09b8ULL));
    return pd;
}

/// Strategy parameter "Parameter portfolio", type "PortfolioIdentifier"
inline tbricks::ParameterDefinition ParameterPortfolio()
{
    // Identifier: "658cf8b8-0329-11e3-b706-ae529049f1f1"
    // Name: "Parameter portfolio"
    // Description: ""
    // Type: "PortfolioIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe3112903b8f88c65ULL, 0xf1f1499052ae06b7ULL));
    return pd;
}

/// Strategy parameter "Throughput limit time window", type "Integer"
inline tbricks::ParameterDefinition ThroughputLimitTimeWindow()
{
    // Identifier: "65af62fe-2470-11e9-9a20-b747deb3124d"
    // Name: "Throughput limit time window"
    // Description: "Lenght of time backet expressed in milliseconds "
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9117024fe62af65ULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Parameter context ranking", type "Ranking"
inline tbricks::ParameterDefinition ParameterContextRanking()
{
    // Identifier: "68aa0456-b6eb-11e1-9b1c-06b747deb312"
    // Name: "Parameter context ranking"
    // Description: ""
    // Type: "Ranking"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe111ebb65604aa68ULL, 0x12b3de47b7061c9bULL));
    return pd;
}

/// Strategy parameter "Portfolio condition", type "PortfolioIdentifier"
inline tbricks::ParameterDefinition PortfolioCondition()
{
    // Identifier: "7009a339-5dd1-11e8-8c87-ae529049f1f1"
    // Name: "Portfolio condition"
    // Description: "Filter condition which defines to which portfolio should a limit rule be applied. Empty means that a rule applies to all portfolios."
    // Type: "PortfolioIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d15d39a30970ULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Ignore errors in summation rows", type "Boolean"
inline tbricks::ParameterDefinition IgnoreErrorsInSummationRows()
{
    // Identifier: "76e3fc4a-38c8-11e8-993e-529049f1f1bb"
    // Name: "Ignore errors in summation rows"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811c8384afce376ULL, 0xbbf1f14990523e99ULL));
    return pd;
}

/// Strategy parameter "Market making limit timeout", type "Integer"
inline tbricks::ParameterDefinition MarketMakingLimitTimeout()
{
    // Identifier: "7bcae514-246f-11e9-9a20-b747deb3124d"
    // Name: "Market making limit timeout"
    // Description: "Timeout in seconds, after last received trade, until delta protection will be reset to original values. "
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9116f2414e5ca7bULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Editable curve", type "Boolean"
inline tbricks::ParameterDefinition EditableCurve()
{
    // Identifier: "82bea8e4-4d01-11e1-bccb-3c870c3e9924"
    // Name: "Editable curve"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Off"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe111014de4a8be82ULL, 0x24993e0c873ccbbcULL));
    return pd;
}

/// Strategy parameter "Quote mode", type "Integer"
inline tbricks::ParameterDefinition QuoteMode()
{
    // Identifier: "845281e0-998e-11e3-9a20-b747deb3124d"
    // Name: "Quote mode"
    // Description: "Quote mode"
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe3118e99e0815284ULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Stop price", type "Price"
inline tbricks::ParameterDefinition StopPrice()
{
    // Identifier: "84796894-1770-11e2-9e47-3c870c3e9924"
    // Name: "Stop price"
    // Description: ""
    // Type: "Price"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe211701794687984ULL, 0x24993e0c873c479eULL));
    return pd;
}

/// Strategy parameter "Suppress in deleted instruments", type "Boolean"
inline tbricks::ParameterDefinition SuppressInDeletedInstruments()
{
    // Identifier: "a554693a-bb3b-11e7-bfd0-3cbc720d0135"
    // Name: "Suppress in deleted instruments"
    // Description: "Paramater to use in apps and Lua expressions for better handling calculations in deleted instruments"
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe7113bbb3a6954a5ULL, 0x35010d72bc3cd0bfULL));
    return pd;
}

/// Strategy parameter "Reference price date", type "DateTime"
inline tbricks::ParameterDefinition ReferencePriceDate()
{
    // Identifier: "84cb367b-c1ab-11e0-b1f1-be84e16cd6ae"
    // Name: "Reference price date"
    // Description: ""
    // Type: "DateTime"
    // Persistence: "Buffered"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe011abc17b36cb84ULL, 0xaed66ce184bef1b1ULL));
    return pd;
}

/// Strategy parameter "Portfolio", type "PortfolioIdentifier"
inline tbricks::ParameterDefinition Portfolio()
{
    // Identifier: "85922ea3-f818-4c21-92de-0730188c4057"
    // Name: "Portfolio"
    // Description: "The Tbricks internal identifier for the portfolio."
    // Type: "PortfolioIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0x214c18f8a32e9285ULL, 0x57408c183007de92ULL));
    return pd;
}

/// Strategy parameter "CFI condition", type "String"
inline tbricks::ParameterDefinition CFI_Condition()
{
    // Identifier: "8a46add7-5dd1-11e8-8c87-ae529049f1f1"
    // Name: "CFI condition"
    // Description: "Filter condition which defines to which CFI should a limit rule be applied. Empty means that a rule applies to all CFIs."
    // Type: "String"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d15dd7ad468aULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Parameter context", type "ParameterContext"
inline tbricks::ParameterDefinition ParameterContext()
{
    // Identifier: "8dae4a78-b6eb-11e1-9b1c-06b747deb312"
    // Name: "Parameter context"
    // Description: ""
    // Type: "ParameterContext"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe111ebb6784aae8dULL, 0x12b3de47b7061c9bULL));
    return pd;
}

/// Strategy parameter "Include future", type "Boolean"
inline tbricks::ParameterDefinition IncludeFuture()
{
    // Identifier: "938f8830-246f-11e9-9a20-b747deb3124d"
    // Name: "Include future"
    // Description: "Indicates whether futures are included in the market making limits or not."
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9116f2430888f93ULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Net value carveout", type "Double"
inline tbricks::ParameterDefinition NetValueCarveout()
{
    // Identifier: "93e814b6-47f9-11e9-9c0d-49f1f1bbe9eb"
    // Name: "Net value carveout"
    // Description: ""
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe911f947b614e893ULL, 0xebe9bbf1f1490d9cULL));
    return pd;
}

/// Strategy parameter "Currency", type "Currency"
inline tbricks::ParameterDefinition Currency()
{
    // Identifier: "82583bd9-4465-4ac6-83aa-ab76a6b8da9a"
    // Name: "Currency"
    // Description: "The currency symbol according to ISO 4217."
    // Type: "Currency"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xc64a6544d93b5882ULL, 0x9adab8a676abaa83ULL));
    return pd;
}

/// Strategy parameter "Soft limit value", type "Double"
inline tbricks::ParameterDefinition SoftLimitValue()
{
    // Identifier: "97c88015-5dd2-11e8-8c87-ae529049f1f1"
    // Name: "Soft limit value"
    // Description: "Defines a limit that can be bypassed if "Bypass soft limits" flag is present in transaction."
    // Type: "Double"
    // Persistence: "Off"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d25d1580c897ULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Use native quote transactions", type "Boolean"
inline tbricks::ParameterDefinition UseNativeQuoteTransactions()
{
    // Identifier: "9fcc89be-246e-11e9-9a20-b747deb3124d"
    // Name: "Use native quote transactions"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9116e24be89cc9fULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Venue condition", type "VenueIdentifier"
inline tbricks::ParameterDefinition VenueCondition()
{
    // Identifier: "a3341fff-5dd1-11e8-8c87-ae529049f1f1"
    // Name: "Venue condition"
    // Description: "Filter condition which defines to which venue should a limit rule be applied. Empty means that a rule applies to all venues."
    // Type: "VenueIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d15dff1f34a3ULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Static limit id", type "Double"
inline tbricks::ParameterDefinition StaticLimitId()
{
    // Identifier: "a8fcfed0-5617-11e9-8c87-ae529049f1f1"
    // Name: "Static limit id"
    // Description: ""
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9111756d0fefca8ULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Limit mode", type "Integer"
inline tbricks::ParameterDefinition LimitMode()
{
    // Identifier: "aae662c7-72ca-11e8-9b1c-1c06b747deb3"
    // Name: "Limit mode"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811ca72c762e6aaULL, 0xb3de47b7061c1c9bULL));
    return pd;
}

/// Strategy parameter "Hard limit value", type "Double"
inline tbricks::ParameterDefinition HardLimitValue()
{
    // Identifier: "ac91f1c5-5dd2-11e8-8c87-ae529049f1f1"
    // Name: "Hard limit value"
    // Description: "Defines a limit that can not be bypassed."
    // Type: "Double"
    // Persistence: "Off"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d25dc5f191acULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "At market volume limit", type "Double"
inline tbricks::ParameterDefinition AtMarketVolumeLimit()
{
    // Identifier: "ad72d74f-3512-11e9-b2ae-06b747deb312"
    // Name: "At market volume limit"
    // Description: "Maximum allowed volume of a single at market transaction."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91112354fd772adULL, 0x12b3de47b706aeb2ULL));
    return pd;
}

/// Strategy parameter "Quote operation", type "Integer"
inline tbricks::ParameterDefinition QuoteOperation()
{
    // Identifier: "b02a8162-9d4b-11e3-b2ae-06b747deb312"
    // Name: "Quote operation"
    // Description: "Quote operation"
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe3114b9d62812ab0ULL, 0x12b3de47b706aeb2ULL));
    return pd;
}

/// Strategy parameter "Parameter user", type "UserIdentifier"
inline tbricks::ParameterDefinition ParameterUser()
{
    // Identifier: "b2d281b0-0ef1-11e2-b3eb-84e16cd6ae52"
    // Name: "Parameter user"
    // Description: "Parameter user."
    // Type: "UserIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe211f10eb081d2b2ULL, 0x52aed66ce184ebb3ULL));
    return pd;
}

/// Strategy parameter "Thickness index", type "Integer"
inline tbricks::ParameterDefinition ThicknessIndex()
{
    // Identifier: "b417bd46-8d3a-11e1-bb43-d6ae529049f1"
    // Name: "Thickness index"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Off"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe1113a8d46bd17b4ULL, 0xf1499052aed643bbULL));
    return pd;
}

/// Strategy parameter "Owner condition", type "UserIdentifier"
inline tbricks::ParameterDefinition OwnerCondition()
{
    // Identifier: "b6ef9c45-5dd1-11e8-8c87-ae529049f1f1"
    // Name: "Owner condition"
    // Description: "Filter condition which defines to which owner should a limit rule be applied. Empty means that a rule applies to all owners."
    // Type: "UserIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d15d459cefb6ULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Allow vertical move", type "Boolean"
inline tbricks::ParameterDefinition AllowVerticalMove()
{
    // Identifier: "bb3bd888-cdc0-11e2-83c8-3c870c3e9924"
    // Name: "Allow vertical move"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe211c0cd88d83bbbULL, 0x24993e0c873cc883ULL));
    return pd;
}

/// Strategy parameter "Color index", type "Integer"
inline tbricks::ParameterDefinition ColorIndex()
{
    // Identifier: "bdbede40-42b2-11e1-9e24-2923be84e16c"
    // Name: "Color index"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe111b24240debebdULL, 0x6ce184be2329249eULL));
    return pd;
}

/// Strategy parameter "Total volume", type "Volume"
inline tbricks::ParameterDefinition TotalVolume()
{
    // Identifier: "5b00e076-483d-4f03-9238-8238a6603533"
    // Name: "Total volume"
    // Description: "The total volume"
    // Type: "Volume"
    // Persistence: "Buffered"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0x34f3d4876e0005bULL, 0x333560a638823892ULL));
    return pd;
}

/// Strategy parameter "Posting action", type "Integer"
inline tbricks::ParameterDefinition PostingAction()
{
    // Identifier: "c41e0653-9649-11e8-a68b-b3a6db3c870c"
    // Name: "Posting action"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811499653061ec4ULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Strategy parameter "Liquidity pool", type "LiquidityPool"
inline tbricks::ParameterDefinition LiquidityPool()
{
    // Identifier: "c52b0d08-d811-11e6-884d-e9ebb3a6db3c"
    // Name: "Liquidity pool"
    // Description: "Unique identifier if a liquidity pool for a particular VIID."
    // Type: "LiquidityPool"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe61111d8080d2bc5ULL, 0x3cdba6b3ebe94d88ULL));
    return pd;
}

/// Strategy parameter "Request for quote type", type "Integer"
inline tbricks::ParameterDefinition RequestForQuoteType()
{
    // Identifier: "c8970b44-2bf6-11e6-aed6-2923be84e16c"
    // Name: "Request for quote type"
    // Description: "The type of a request for quote."
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe611f62b440b97c8ULL, 0x6ce184be2329d6aeULL));
    return pd;
}

/// Strategy parameter "Gross volume limit for MM", type "Double"
inline tbricks::ParameterDefinition GrossVolumeLimitForMM()
{
    // Identifier: "caa2ece6-246e-11e9-9a20-b747deb3124d"
    // Name: "Gross volume limit for MM"
    // Description: "Maximum allowed gross volume of trades in specified underlying group."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9116e24e6eca2caULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Order capacity", type "Integer"
inline tbricks::ParameterDefinition OrderCapacity()
{
    // Identifier: "cc0d6d94-e1e2-11e5-9e24-9049f1f1bbe9"
    // Name: "Order capacity"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe511e2e1946d0dccULL, 0xe9bbf1f14990249eULL));
    return pd;
}

/// Strategy parameter "Default limit", type "Boolean"
inline tbricks::ParameterDefinition DefaultLimit()
{
    // Identifier: "ced0f12d-3694-11e9-9b1c-1c06b747deb3"
    // Name: "Default limit"
    // Description: "True if the limit rule is default"
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91194362df1d0ceULL, 0xb3de47b7061c1c9bULL));
    return pd;
}

/// Strategy parameter "Allow user edit", type "Boolean"
inline tbricks::ParameterDefinition AllowUserEdit()
{
    // Identifier: "cf59afe6-cdc0-11e2-83c8-3c870c3e9924"
    // Name: "Allow user edit"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe211c0cde6af59cfULL, 0x24993e0c873cc883ULL));
    return pd;
}

/// Strategy parameter "Currency condition", type "Currency"
inline tbricks::ParameterDefinition CurrencyCondition()
{
    // Identifier: "d0c245e1-5dd1-11e8-8c87-ae529049f1f1"
    // Name: "Currency condition"
    // Description: "Filter condition which defines to which currency should a limit rule be applied. Empty means that a rule applies to all currencies."
    // Type: "Currency"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d15de145c2d0ULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Parameter datetime", type "DateTime"
inline tbricks::ParameterDefinition ParameterDatetime()
{
    // Identifier: "d0f587fc-4cdc-11e1-945d-b747deb3124d"
    // Name: "Parameter datetime"
    // Description: ""
    // Type: "DateTime"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe111dc4cfc87f5d0ULL, 0x4d12b3de47b75d94ULL));
    return pd;
}

/// Strategy parameter "Venue", type "VenueIdentifier"
inline tbricks::ParameterDefinition Venue()
{
    // Identifier: "9b21a3fe-87dd-4008-a5a1-cefe070d4d67"
    // Name: "Venue"
    // Description: "Venue identifier"
    // Type: "VenueIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0x840dd87fea3219bULL, 0x674d0d07fecea1a5ULL));
    return pd;
}

/// Strategy parameter "Expand grouping", type "Integer"
inline tbricks::ParameterDefinition ExpandGrouping()
{
    // Identifier: "d592cdec-ae07-11e9-bb45-245e0d1c06b7"
    // Name: "Expand grouping"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91107aeeccd92d5ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}

/// Strategy parameter "App template", type "TreeNodeIdentifier"
inline tbricks::ParameterDefinition AppTemplate()
{
    // Identifier: "e0009a24-f2c4-11e8-9640-ee5357b27bad"
    // Name: "App template"
    // Description: "App template tree node that contains parameters, extra data and other app properties which can be applied to app instance"
    // Type: "TreeNodeIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811c4f2249a00e0ULL, 0xad7bb25753ee4096ULL));
    return pd;
}

/// Strategy parameter "Minimum acceptable fill volume", type "Volume"
inline tbricks::ParameterDefinition MinimumAcceptableFillVolume()
{
    // Identifier: "5cf838c1-6708-4d52-957b-bbee241829ed"
    // Name: "Minimum acceptable fill volume"
    // Description: ""
    // Type: "Volume"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0x524d0867c138f85cULL, 0xed291824eebb7b95ULL));
    return pd;
}

/// Strategy parameter "Use temporary table", type "Boolean"
inline tbricks::ParameterDefinition UseTemporaryTable()
{
    // Identifier: "e0692dd8-e96f-11e6-b149-be84e16cd6ae"
    // Name: "Use temporary table"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe6116fe9d82d69e0ULL, 0xaed66ce184be49b1ULL));
    return pd;
}

/// Strategy parameter "Disclosed volume", type "Volume"
inline tbricks::ParameterDefinition DisclosedVolume()
{
    // Identifier: "bc9e0d54-6779-4675-aa9c-6e769c30529e"
    // Name: "Disclosed volume"
    // Description: "Disclosed volume"
    // Type: "Volume"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0x75467967540d9ebcULL, 0x9e52309c766e9caaULL));
    return pd;
}

/// Strategy parameter "App validation trigger", type "Integer"
inline tbricks::ParameterDefinition AppValidationTrigger()
{
    // Identifier: "e20ff0ce-609c-11e6-8c87-ae529049f1f1"
    // Name: "App validation trigger"
    // Description: "Use for triggering validation from inside of app"
    // Type: "Integer"
    // Persistence: "Off"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe6119c60cef00fe2ULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Valuation datetime", type "DateTime"
inline tbricks::ParameterDefinition ValuationDatetime()
{
    // Identifier: "e46cc659-d956-11e0-993e-ebb3a6db3c87"
    // Name: "Valuation datetime"
    // Description: "Valuation date"
    // Type: "DateTime"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe01156d959c66ce4ULL, 0x873cdba6b3eb3e99ULL));
    return pd;
}

/// Strategy parameter "Allow rotation", type "Boolean"
inline tbricks::ParameterDefinition AllowRotation()
{
    // Identifier: "e5c15038-cdc0-11e2-83c8-3c870c3e9924"
    // Name: "Allow rotation"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe211c0cd3850c1e5ULL, 0x24993e0c873cc883ULL));
    return pd;
}

/// Strategy parameter "Filled volume", type "Volume"
inline tbricks::ParameterDefinition FilledVolume()
{
    // Identifier: "3d13d1cd-214a-4e08-9973-880ccaadc6e4"
    // Name: "Filled volume"
    // Description: "The filled volume"
    // Type: "Volume"
    // Persistence: "Buffered"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0x84e4a21cdd1133dULL, 0xe4c6adca0c887399ULL));
    return pd;
}

/// Strategy parameter "Client condition", type "TreeNodeIdentifier"
inline tbricks::ParameterDefinition ClientCondition()
{
    // Identifier: "e77377d3-5dd1-11e8-8c87-ae529049f1f1"
    // Name: "Client condition"
    // Description: "Filter condition which defines to which client should a limit rule be applied. Empty means that a rule applies to all clients."
    // Type: "TreeNodeIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d15dd37773e7ULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Strategy parameter "Client", type "TreeNodeIdentifier"
inline tbricks::ParameterDefinition Client()
{
    // Identifier: "e85f67fb-3a24-11e6-9e47-f1bbe9ebb3a6"
    // Name: "Client"
    // Description: "Node in a tree that represents the managed entity for a strategy and/or orders."
    // Type: "TreeNodeIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe611243afb675fe8ULL, 0xa6b3ebe9bbf1479eULL));
    return pd;
}

/// Strategy parameter "Active volume", type "Volume"
inline tbricks::ParameterDefinition ActiveVolume()
{
    // Identifier: "4e867cb3-df02-4c22-a336-977a59318fde"
    // Name: "Active volume"
    // Description: "Volume tick down."
    // Type: "Volume"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0x224c02dfb37c864eULL, 0xde8f31597a9736a3ULL));
    return pd;
}

/// Strategy parameter "Net volume limit for MM", type "Double"
inline tbricks::ParameterDefinition NetVolumeLimitForMM()
{
    // Identifier: "f33d059c-246e-11e9-9a20-b747deb3124d"
    // Name: "Net volume limit for MM"
    // Description: "Maximum allowed net volume of trades in specified underlying group."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9116e249c053df3ULL, 0x4d12b3de47b7209aULL));
    return pd;
}

/// Strategy parameter "Selected", type "Boolean"
inline tbricks::ParameterDefinition Selected()
{
    // Identifier: "f476402a-b437-11df-bbf1-f1c9c7ab1686"
    // Name: "Selected"
    // Description: "Selected"
    // Type: "Boolean"
    // Persistence: "Off"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xdf1137b42a4076f4ULL, 0x8616abc7c9f1f1bbULL));
    return pd;
}

/// Strategy parameter "x", type "Double"
inline tbricks::ParameterDefinition X()
{
    // Identifier: "a2d733e8-ae67-11de-b5c5-d9fdf720ba3a"
    // Name: "x"
    // Description: "x"
    // Type: "Double"
    // Persistence: "Off"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xde1167aee833d7a2ULL, 0x3aba20f7fdd9c5b5ULL));
    return pd;
}

/// Strategy parameter "y", type "Double"
inline tbricks::ParameterDefinition Y()
{
    // Identifier: "a31a4b2e-ae67-11de-b8f1-1f176e6cd1a5"
    // Name: "y"
    // Description: "y"
    // Type: "Double"
    // Persistence: "Off"
    // Direction: "Output"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xde1167ae2e4b1aa3ULL, 0xa5d16c6e171ff1b8ULL));
    return pd;
}

/// Strategy parameter "Soft cash value limit", type "Double"
inline tbricks::ParameterDefinition SoftCashValueLimit()
{
    // Identifier: "f95d3803-584e-11e9-8a89-0d1c06b747de"
    // Name: "Soft cash value limit"
    // Description: "Maximum allowed cash value of a single transaction. This limit can be bypassed if "Bypass soft limits" flag is present in the transaction."
    // Type: "Double"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9114e5803385df9ULL, 0xde47b7061c0d898aULL));
    return pd;
}

/// Strategy parameter "App type condition", type "StrategyDefinition"
inline tbricks::ParameterDefinition AppTypeCondition()
{
    // Identifier: "fbafabb6-246f-11e9-9a20-b747deb3124d"
    // Name: "App type condition"
    // Description: "Filter condition which defines to which app type should a limit rule be applied. Empty means that a rule applies to all app types."
    // Type: "StrategyDefinition"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::ParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9116f24b6abaffbULL, 0x4d12b3de47b7209aULL));
    return pd;
}

}

namespace user_preferences {

/// User preference "Fraction display convention", type "Integer"
inline tbricks::Identifier FractionDisplayConvention()
{
    // Identifier: "0be106c2-655b-11e2-83c8-3e99245e0d1c"
    // Name: "Fraction display convention"
    // Description: ""
    // Type: "Integer"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe2115b65c206e10bULL, 0x1c0d5e24993ec883ULL));
    return pd;
}

/// User preference "Large bid edge", type "Double"
inline tbricks::Identifier LargeBidEdge()
{
    // Identifier: "1074c634-6862-11e6-b706-f1f1bbe9ebb3"
    // Name: "Large bid edge"
    // Description: ""
    // Type: "Double"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe611626834c67410ULL, 0xb3ebe9bbf1f106b7ULL));
    return pd;
}

/// User preference "Modified instrument parameter scope", type "Integer"
inline tbricks::Identifier ModifiedInstrumentParameterScope()
{
    // Identifier: "275aef0a-2d8c-11e2-9b1c-47deb3124dc8"
    // Name: "Modified instrument parameter scope"
    // Description: ""
    // Type: "Integer"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe2118c2d0aef5a27ULL, 0xc84d12b3de471c9bULL));
    return pd;
}

/// User preference "Large ask edge", type "Double"
inline tbricks::Identifier LargeAskEdge()
{
    // Identifier: "3330c8bc-6862-11e6-b706-f1f1bbe9ebb3"
    // Name: "Large ask edge"
    // Description: ""
    // Type: "Double"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe6116268bcc83033ULL, 0xb3ebe9bbf1f106b7ULL));
    return pd;
}

/// User preference "Indirect table modification mode", type "Boolean"
inline tbricks::Identifier IndirectTableModificationMode()
{
    // Identifier: "353ca412-24bb-11e2-87b7-f1f1bbe9ebb3"
    // Name: "Indirect table modification mode"
    // Description: ""
    // Type: "Boolean"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe211bb2412a43c35ULL, 0xb3ebe9bbf1f1b787ULL));
    return pd;
}

/// User preference "Default portfolio", type "PortfolioIdentifier"
inline tbricks::Identifier DefaultPortfolio()
{
    // Identifier: "54eea906-65f2-11e0-9d1f-ebb3a6db3c87"
    // Name: "Default portfolio"
    // Description: ""
    // Type: "PortfolioIdentifier"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe011f26506a9ee54ULL, 0x873cdba6b3eb1f9dULL));
    return pd;
}

/// User preference "New instrument parameter scope", type "Integer"
inline tbricks::Identifier NewInstrumentParameterScope()
{
    // Identifier: "5aa32044-2d8c-11e2-9b1c-47deb3124dc8"
    // Name: "New instrument parameter scope"
    // Description: ""
    // Type: "Integer"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe2118c2d4420a35aULL, 0xc84d12b3de471c9bULL));
    return pd;
}

/// User preference "Use primary market", type "Boolean"
inline tbricks::Identifier UsePrimaryMarket()
{
    // Identifier: "61671bda-b38e-11e9-9490-d8f162230fb0"
    // Name: "Use primary market"
    // Description: "Use "Primary market" instrument attribute value to handle market data."
    // Type: "Boolean"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe9118eb3da1b6761ULL, 0xb00f2362f1d89094ULL));
    return pd;
}

/// User preference "Default parameter context ranking", type "Ranking"
inline tbricks::Identifier DefaultParameterContextRanking()
{
    // Identifier: "66756bf1-32e4-11e1-9c0d-db3c870c3e99"
    // Name: "Default parameter context ranking"
    // Description: ""
    // Type: "Ranking"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe111e432f16b7566ULL, 0x993e0c873cdb0d9cULL));
    return pd;
}

/// User preference "Ask edge", type "Double"
inline tbricks::Identifier AskEdge()
{
    // Identifier: "88f0d8ca-687e-11e6-aed6-2923be84e16c"
    // Name: "Ask edge"
    // Description: ""
    // Type: "Double"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe6117e68cad8f088ULL, 0x6ce184be2329d6aeULL));
    return pd;
}

/// User preference "Bid edge", type "Double"
inline tbricks::Identifier BidEdge()
{
    // Identifier: "a200c5f0-687e-11e6-aed6-2923be84e16c"
    // Name: "Bid edge"
    // Description: ""
    // Type: "Double"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe6117e68f0c500a2ULL, 0x6ce184be2329d6aeULL));
    return pd;
}

/// User preference "Fraction separator", type "Integer"
inline tbricks::Identifier FractionSeparator()
{
    // Identifier: "a62842c8-655a-11e2-83c8-3e99245e0d1c"
    // Name: "Fraction separator"
    // Description: ""
    // Type: "Integer"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe2115a65c84228a6ULL, 0x1c0d5e24993ec883ULL));
    return pd;
}

/// User preference "Default basket portfolio", type "PortfolioIdentifier"
inline tbricks::Identifier DefaultBasketPortfolio()
{
    // Identifier: "a6854220-65f2-11e0-9d1f-ebb3a6db3c87"
    // Name: "Default basket portfolio"
    // Description: ""
    // Type: "PortfolioIdentifier"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe011f265204285a6ULL, 0x873cdba6b3eb1f9dULL));
    return pd;
}

/// User preference "Default Excel Add-in read-only mode", type "Boolean"
inline tbricks::Identifier DefaultExcelAddInReadOnlyMode()
{
    // Identifier: "c81154de-5b31-11e7-88c0-21ef2d4d9f97"
    // Name: "Default Excel Add-in read-only mode"
    // Description: "Sets read-only mode for newly inserted lists and single linked cells in Excel Add-in"
    // Type: "Boolean"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe711315bde5411c8ULL, 0x979f4d2def21c088ULL));
    return pd;
}

/// User preference "Default Excel Add-in refresh rate (s)", type "Double"
inline tbricks::Identifier DefaultExcelAddInRefreshRate_LEFT_PARENTHESIS_S_RIGHT_PARENTHESIS()
{
    // Identifier: "e5993b80-5b30-11e7-8860-51cb8c103de0"
    // Name: "Default Excel Add-in refresh rate (s)"
    // Description: "Sets refresh rate in seconds for newly inserted lists and single linked cells in Excel Add-in, minimal supported value is 0.5 seconds"
    // Type: "Double"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe711305b803b99e5ULL, 0xe03d108ccb516088ULL));
    return pd;
}

/// User preference "Default display currency", type "Currency"
inline tbricks::Identifier DefaultDisplayCurrency()
{
    // Identifier: "eb6b5376-a264-11e5-be30-9f4718872c6f"
    // Name: "Default display currency"
    // Description: "Default currency to use in visualizations"
    // Type: "Currency"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe51164a276536bebULL, 0x6f2c8718479f30beULL));
    return pd;
}

}

namespace user_parameters {

/// User parameter "Short code", type "Integer"
inline tbricks::UserParameterDefinition ShortCode()
{
    // Identifier: "271d3cb0-f608-11e7-b809-3c870c3e9924"
    // Name: "Short code"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::UserParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe71108f6b03c1d27ULL, 0x24993e0c873c09b8ULL));
    return pd;
}

}

namespace tree_node_parameters {

/// Tree node parameter "Client node type", type "Integer"
inline tbricks::TreeNodeParameterDefinition ClientNodeType()
{
    // Identifier: "0f0baa96-0809-11e7-9e24-9049f1f1bbe9"
    // Name: "Client node type"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711090896aa0b0fULL, 0xe9bbf1f14990249eULL));
    return pd;
}

/// Tree node parameter "App type", type "StrategyDefinition"
inline tbricks::TreeNodeParameterDefinition AppType()
{
    // Identifier: "19074c54-fd90-11e6-9b1c-1c06b747deb3"
    // Name: "App type"
    // Description: ""
    // Type: "StrategyDefinition"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe61190fd544c0719ULL, 0xb3de47b7061c1c9bULL));
    return pd;
}

/// Tree node parameter "Include orders", type "Boolean"
inline tbricks::TreeNodeParameterDefinition IncludeOrders()
{
    // Identifier: "1a283c34-07df-11e7-b706-f1f1bbe9ebb3"
    // Name: "Include orders"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711df07343c281aULL, 0xb3ebe9bbf1f106b7ULL));
    return pd;
}

/// Tree node parameter "Venue", type "VenueIdentifier"
inline tbricks::TreeNodeParameterDefinition Venue()
{
    // Identifier: "2770b95b-4351-11e6-b2ae-06b747deb312"
    // Name: "Venue"
    // Description: ""
    // Type: "VenueIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe61151435bb97027ULL, 0x12b3de47b706aeb2ULL));
    return pd;
}

/// Tree node parameter "Include expits", type "Boolean"
inline tbricks::TreeNodeParameterDefinition IncludeExpits()
{
    // Identifier: "277a7424-9997-11e8-bccb-3e99245e0d1c"
    // Name: "Include expits"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811979924747a27ULL, 0x1c0d5e24993ecbbcULL));
    return pd;
}

/// Tree node parameter "Include directed quotes", type "Boolean"
inline tbricks::TreeNodeParameterDefinition IncludeDirectedQuotes()
{
    // Identifier: "37b93df2-9997-11e8-bccb-3e99245e0d1c"
    // Name: "Include directed quotes"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe8119799f23db937ULL, 0x1c0d5e24993ecbbcULL));
    return pd;
}

/// Tree node parameter "Short code", type "Integer"
inline tbricks::TreeNodeParameterDefinition ShortCode()
{
    // Identifier: "4a61d990-5c0e-11e7-b149-be84e16cd6ae"
    // Name: "Short code"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe7110e5c90d9614aULL, 0xaed66ce184be49b1ULL));
    return pd;
}

/// Tree node parameter "Flow engine app type", type "StrategyDefinition"
inline tbricks::TreeNodeParameterDefinition FlowEngineAppType()
{
    // Identifier: "4e10350a-f2a5-11e6-9c0d-49f1f1bbe9eb"
    // Name: "Flow engine app type"
    // Description: ""
    // Type: "StrategyDefinition"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe611a5f20a35104eULL, 0xebe9bbf1f1490d9cULL));
    return pd;
}

/// Tree node parameter "Venue counterpart name", type "String"
inline tbricks::TreeNodeParameterDefinition VenueCounterpartName()
{
    // Identifier: "4ebb8196-8906-11e8-945d-0c3e99245e0d"
    // Name: "Venue counterpart name"
    // Description: ""
    // Type: "String"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe81106899681bb4eULL, 0xd5e24993e0c5d94ULL));
    return pd;
}

/// Tree node parameter "Orc client id", type "Table"
inline tbricks::TreeNodeParameterDefinition OrcClientId()
{
    // Identifier: "5567b910-7214-11e7-8a89-0d1c06b747de"
    // Name: "Orc client id"
    // Description: ""
    // Type: "Table"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711147210b96755ULL, 0xde47b7061c0d898aULL));
    return pd;
}

/// Tree node parameter "Flow engine app types", type "Table"
inline tbricks::TreeNodeParameterDefinition FlowEngineAppTypes()
{
    // Identifier: "5fff1bc8-f2a5-11e6-9c0d-49f1f1bbe9eb"
    // Name: "Flow engine app types"
    // Description: ""
    // Type: "Table"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe611a5f2c81bff5fULL, 0xebe9bbf1f1490d9cULL));
    return pd;
}

/// Tree node parameter "Flow source subsystem", type "AnyType"
inline tbricks::TreeNodeParameterDefinition FlowSourceSubsystem()
{
    // Identifier: "7253365e-def7-11e6-9e47-f1bbe9ebb3a6"
    // Name: "Flow source subsystem"
    // Description: ""
    // Type: "AnyType"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe611f7de5e365372ULL, 0xa6b3ebe9bbf1479eULL));
    return pd;
}

/// Tree node parameter "User", type "UserIdentifier"
inline tbricks::TreeNodeParameterDefinition User()
{
    // Identifier: "74e7eaa8-5c11-11e7-b149-be84e16cd6ae"
    // Name: "User"
    // Description: "Internal Tbricks user identifier."
    // Type: "UserIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711115ca8eae774ULL, 0xaed66ce184be49b1ULL));
    return pd;
}

/// Tree node parameter "Flow destination subsystem", type "AnyType"
inline tbricks::TreeNodeParameterDefinition FlowDestinationSubsystem()
{
    // Identifier: "8363e8f9-def7-11e6-9e47-f1bbe9ebb3a6"
    // Name: "Flow destination subsystem"
    // Description: ""
    // Type: "AnyType"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe611f7def9e86383ULL, 0xa6b3ebe9bbf1479eULL));
    return pd;
}

/// Tree node parameter "App types", type "Table"
inline tbricks::TreeNodeParameterDefinition AppTypes()
{
    // Identifier: "969621a2-f75c-11e6-bd5a-db3c870c3e99"
    // Name: "App types"
    // Description: ""
    // Type: "Table"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe6115cf7a2219696ULL, 0x993e0c873cdb5abdULL));
    return pd;
}

/// Tree node parameter "Orc client tag", type "String"
inline tbricks::TreeNodeParameterDefinition OrcClientTag()
{
    // Identifier: "971f96d3-7216-11e7-8a89-0d1c06b747de"
    // Name: "Orc client tag"
    // Description: ""
    // Type: "String"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe7111672d3961f97ULL, 0xde47b7061c0d898aULL));
    return pd;
}

/// Tree node parameter "Partitioning type", type "Integer"
inline tbricks::TreeNodeParameterDefinition PartitioningType()
{
    // Identifier: "b25180f3-6c9c-11e7-b596-99245e0d1c06"
    // Name: "Partitioning type"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe7119c6cf38051b2ULL, 0x61c0d5e249996b5ULL));
    return pd;
}

/// Tree node parameter "Orc client tag value", type "String"
inline tbricks::TreeNodeParameterDefinition OrcClientTagValue()
{
    // Identifier: "b95e1f98-7216-11e7-8a89-0d1c06b747de"
    // Name: "Orc client tag value"
    // Description: ""
    // Type: "String"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe7111672981f5eb9ULL, 0xde47b7061c0d898aULL));
    return pd;
}

/// Tree node parameter "Tree node id", type "TreeNodeIdentifier"
inline tbricks::TreeNodeParameterDefinition TreeNodeId()
{
    // Identifier: "be3ca2f8-6642-11e7-aed6-2923be84e16c"
    // Name: "Tree node id"
    // Description: "Tree node identifier"
    // Type: "TreeNodeIdentifier"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe7114266f8a23cbeULL, 0x6ce184be2329d6aeULL));
    return pd;
}

/// Tree node parameter "Flow engine subsystem", type "AnyType"
inline tbricks::TreeNodeParameterDefinition FlowEngineSubsystem()
{
    // Identifier: "daad7c5b-def7-11e6-9e47-f1bbe9ebb3a6"
    // Name: "Flow engine subsystem"
    // Description: ""
    // Type: "AnyType"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe611f7de5b7caddaULL, 0xa6b3ebe9bbf1479eULL));
    return pd;
}

/// Tree node parameter "Qualified role", type "Integer"
inline tbricks::TreeNodeParameterDefinition QualifiedRole()
{
    // Identifier: "e17a906e-6d67-11e7-ae50-47deb3124dc8"
    // Name: "Qualified role"
    // Description: ""
    // Type: "Integer"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711676d6e907ae1ULL, 0xc84d12b3de4750aeULL));
    return pd;
}

/// Tree node parameter "Flow engine subsystems path", type "Table"
inline tbricks::TreeNodeParameterDefinition FlowEngineSubsystemsPath()
{
    // Identifier: "e5719519-def7-11e6-9e47-f1bbe9ebb3a6"
    // Name: "Flow engine subsystems path"
    // Description: ""
    // Type: "Table"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe611f7de199571e5ULL, 0xa6b3ebe9bbf1479eULL));
    return pd;
}

/// Tree node parameter "Venue counterpart information", type "Table"
inline tbricks::TreeNodeParameterDefinition VenueCounterpartInformation()
{
    // Identifier: "fc9af8dc-8906-11e8-945d-0c3e99245e0d"
    // Name: "Venue counterpart information"
    // Description: ""
    // Type: "Table"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe8110689dcf89afcULL, 0xd5e24993e0c5d94ULL));
    return pd;
}

/// Tree node parameter "Include carveouts", type "Boolean"
inline tbricks::TreeNodeParameterDefinition IncludeCarveouts()
{
    // Identifier: "fde66239-ae6b-11e7-8a89-0d1c06b747de"
    // Name: "Include carveouts"
    // Description: ""
    // Type: "Boolean"
    // Persistence: "Buffered"
    // Direction: "InputOutput"
    tbricks::TreeNodeParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe7116bae3962e6fdULL, 0xde47b7061c0d898aULL));
    return pd;
}

}

namespace market_data_parameters {

/// Market data parameter "HKSE order cancel session", type "Boolean"
// Only cancellation is allowed during this session.
inline tbricks::MarketDataParameterDefinition HKSE_OrderCancelSession()
{
    // Identifier: "180dc09b-174a-11ea-bd5a-db3c870c3e99"
    // Name: "HKSE order cancel session"
    // Description: "Only cancellation is allowed during this session."
    // Type: "Boolean"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea114a179bc00d18ULL, 0x993e0c873cdb5abdULL));
    return pd;
}

/// Market data parameter "HKSE reference price limits order", type "Price"
// The reference price limits order price during auction period.
inline tbricks::MarketDataParameterDefinition HKSE_ReferencePriceLimitsOrder()
{
    // Identifier: "1aec7fe5-334e-11e9-bb45-245e0d1c06b7"
    // Name: "HKSE reference price limits order"
    // Description: "The reference price limits order price during auction period."
    // Type: "Price"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9114e33e57fec1aULL, 0xb7061c0d5e2445bbULL));
    return pd;
}

/// Market data parameter "ASX corporate action codes", type "String"
// ASX corporate action codes
inline tbricks::MarketDataParameterDefinition ASX_CorporateActionCodes()
{
    // Identifier: "261bd53b-125b-11ea-8c87-ae529049f1f1"
    // Name: "ASX corporate action codes"
    // Description: "ASX corporate action codes"
    // Type: "String"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea115b123bd51b26ULL, 0xf1f1499052ae878cULL));
    return pd;
}

/// Market data parameter "SET Par Value", type "Price"
// Par value for Stock Exchange of Thailand.
inline tbricks::MarketDataParameterDefinition SET_ParValue()
{
    // Identifier: "295a1812-c006-11e9-a68b-b3a6db3c870c"
    // Name: "SET Par Value"
    // Description: "Par value for Stock Exchange of Thailand."
    // Type: "Price"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91106c012185a29ULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Market data parameter "SET NonCompliance Flag", type "Boolean"
// Non compliance flag for Stock Exchange of Thailand.
inline tbricks::MarketDataParameterDefinition SET_NonComplianceFlag()
{
    // Identifier: "31d3675a-c006-11e9-a68b-b3a6db3c870c"
    // Name: "SET NonCompliance Flag"
    // Description: "Non compliance flag for Stock Exchange of Thailand."
    // Type: "Boolean"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91106c05a67d331ULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Market data parameter "SET Split Flag", type "Boolean"
// Split flag for Stock Exchange of Thailand.
inline tbricks::MarketDataParameterDefinition SET_SplitFlag()
{
    // Identifier: "3acf13a4-c006-11e9-a68b-b3a6db3c870c"
    // Name: "SET Split Flag"
    // Description: "Split flag for Stock Exchange of Thailand."
    // Type: "Boolean"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91106c0a413cf3aULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Market data parameter "SET Stabilization Flag", type "Boolean"
// Stabilization flag for Stock Exchange of Thailand.
inline tbricks::MarketDataParameterDefinition SET_StabilizationFlag()
{
    // Identifier: "40d9c744-c006-11e9-a68b-b3a6db3c870c"
    // Name: "SET Stabilization Flag"
    // Description: "Stabilization flag for Stock Exchange of Thailand."
    // Type: "Boolean"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91106c044c7d940ULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Market data parameter "SET Short Sell Flag", type "Boolean"
// Short sell flag for Stock Exchange of Thailand.
inline tbricks::MarketDataParameterDefinition SET_ShortSellFlag()
{
    // Identifier: "4b4ed200-c006-11e9-a68b-b3a6db3c870c"
    // Name: "SET Short Sell Flag"
    // Description: "Short sell flag for Stock Exchange of Thailand."
    // Type: "Boolean"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91106c000d24e4bULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Market data parameter "SET NVDR Short Sell Flag", type "Boolean"
// NVDR short sell flag for Stock Exchange of Thailand.
inline tbricks::MarketDataParameterDefinition SET_NVDR_ShortSellFlag()
{
    // Identifier: "537c55ec-c006-11e9-a68b-b3a6db3c870c"
    // Name: "SET NVDR Short Sell Flag"
    // Description: "NVDR short sell flag for Stock Exchange of Thailand."
    // Type: "Boolean"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91106c0ec557c53ULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Market data parameter "SET NVDR Flag", type "String"
// NVDR flag for Stock Exchange of Thailand.
inline tbricks::MarketDataParameterDefinition SET_NVDR_Flag()
{
    // Identifier: "752de84a-c006-11e9-a68b-b3a6db3c870c"
    // Name: "SET NVDR Flag"
    // Description: "NVDR flag for Stock Exchange of Thailand."
    // Type: "String"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91106c04ae82d75ULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Market data parameter "Minimum short sell price (deprecated)", type "Price"
// The price provided by the market to be used as a reference price for validating the uptick rule check. Short-selling order's price should not be lower than the Minimum short sell price.
inline tbricks::MarketDataParameterDefinition MinimumShortSellPrice_LEFT_PARENTHESIS_Deprecated_RIGHT_PARENTHESIS()
{
    // Identifier: "759c6636-564d-11e8-abe9-e16cd6ae5290"
    // Name: "Minimum short sell price (deprecated)"
    // Description: "The price provided by the market to be used as a reference price for validating the uptick rule check. Short-selling order's price should not be lower than the Minimum short sell price."
    // Type: "Price"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe8114d5636669c75ULL, 0x9052aed66ce1e9abULL));
    return pd;
}

/// Market data parameter "SET TTF Flag", type "String"
// TTF flag for Stock Exchange of Thailand.
inline tbricks::MarketDataParameterDefinition SET_TTF_Flag()
{
    // Identifier: "7a57bdf0-c006-11e9-a68b-b3a6db3c870c"
    // Name: "SET TTF Flag"
    // Description: "TTF flag for Stock Exchange of Thailand."
    // Type: "String"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91106c0f0bd577aULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Market data parameter "SET Beneficial Signs", type "String"
// Beneficial signs for Stock Exchange of Thailand.
inline tbricks::MarketDataParameterDefinition SET_BeneficialSigns()
{
    // Identifier: "7fb79e6e-c006-11e9-a68b-b3a6db3c870c"
    // Name: "SET Beneficial Signs"
    // Description: "Beneficial signs for Stock Exchange of Thailand."
    // Type: "String"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91106c06e9eb77fULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Market data parameter "Bloomberg Accured Interest", type "Price"
// Accrued Interest/100 - DS113 - Amount of interest accumulated but not paid between the most recent payment and the settlement date per 100 face value. To see the ticket/coupon accrued, please use Ticket Accrued Amount (DY259, TKT_ACCRUED)
inline tbricks::MarketDataParameterDefinition BloombergAccuredInterest()
{
    // Identifier: "8f4372d8-7dc1-4b5b-ab96-7478055cf4a3"
    // Name: "Bloomberg Accured Interest"
    // Description: "Accrued Interest/100 - DS113 - Amount of interest accumulated but not paid between the most recent payment and the settlement date per 100 face value. To see the ticket/coupon accrued, please use Ticket Accrued Amount (DY259, TKT_ACCRUED)"
    // Type: "Price"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0x5b4bc17dd872438fULL, 0xa3f45c05787496abULL));
    return pd;
}

/// Market data parameter "Exchange Modified Datetime (orderbook)", type "DateTime"
// The venue timestamp when the item was modified.
inline tbricks::MarketDataParameterDefinition ExchangeModifiedDatetime_LEFT_PARENTHESIS_Orderbook_RIGHT_PARENTHESIS()
{
    // Identifier: "9d79470c-57bc-11e9-9b1c-1c06b747deb3"
    // Name: "Exchange Modified Datetime (orderbook)"
    // Description: "The venue timestamp when the item was modified."
    // Type: "DateTime"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe911bc570c47799dULL, 0xb3de47b7061c1c9bULL));
    return pd;
}

/// Market data parameter "HKSE Nominal price", type "Price"
// Nominal Price for Hong Kong Stock Exchange
inline tbricks::MarketDataParameterDefinition HKSE_NominalPrice()
{
    // Identifier: "a3b06eaf-1eea-11e8-9f25-870c3e99245e"
    // Name: "HKSE Nominal price"
    // Description: "Nominal Price for Hong Kong Stock Exchange"
    // Type: "Price"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811ea1eaf6eb0a3ULL, 0x5e24993e0c87259fULL));
    return pd;
}

/// Market data parameter "TFEX VWAP", type "Price"
// WVAP for Stock Exchange of Thailand and Thailand Futures Exchange.
inline tbricks::MarketDataParameterDefinition TFEX_VWAP()
{
    // Identifier: "a7e8fb72-c005-11e9-a68b-b3a6db3c870c"
    // Name: "TFEX VWAP"
    // Description: "WVAP for Stock Exchange of Thailand and Thailand Futures Exchange."
    // Type: "Price"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91105c072fbe8a7ULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Market data parameter "HKSE VWAP price", type "Price"
// Volume-Weighted Average Price.
inline tbricks::MarketDataParameterDefinition HKSE_VWAP_Price()
{
    // Identifier: "a9c8964b-334d-11e9-bb45-245e0d1c06b7"
    // Name: "HKSE VWAP price"
    // Description: "Volume-Weighted Average Price."
    // Type: "Price"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9114d334b96c8a9ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}

/// Market data parameter "SET Notification Type", type "String"
// Notification Type for Stock Exchange of Thailand
inline tbricks::MarketDataParameterDefinition SET_NotificationType()
{
    // Identifier: "be08d6fe-6b34-11ea-884d-e9ebb3a6db3c"
    // Name: "SET Notification Type"
    // Description: "Notification Type for Stock Exchange of Thailand"
    // Type: "String"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11346bfed608beULL, 0x3cdba6b3ebe94d88ULL));
    return pd;
}

/// Market data parameter "SET IPO Price", type "Price"
// IPO price for Stock Exchange of Thailand.
inline tbricks::MarketDataParameterDefinition SET_IPO_Price()
{
    // Identifier: "d31d9186-c005-11e9-a68b-b3a6db3c870c"
    // Name: "SET IPO Price"
    // Description: "IPO price for Stock Exchange of Thailand."
    // Type: "Price"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe91105c086911dd3ULL, 0xc873cdba6b38ba6ULL));
    return pd;
}

/// Market data parameter "HKSE short sell shares traded", type "Volume"
// Number of short-sell shares traded for a security.
inline tbricks::MarketDataParameterDefinition HKSE_ShortSellSharesTraded()
{
    // Identifier: "d7873ca9-334d-11e9-bb45-245e0d1c06b7"
    // Name: "HKSE short sell shares traded"
    // Description: "Number of short-sell shares traded for a security."
    // Type: "Volume"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9114d33a93c87d7ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}

/// Market data parameter "HKSE short sell turnover", type "Volume"
// Current short-sell turnover for a security.
inline tbricks::MarketDataParameterDefinition HKSE_ShortSellTurnover()
{
    // Identifier: "fbd074c7-334d-11e9-bb45-245e0d1c06b7"
    // Name: "HKSE short sell turnover"
    // Description: "Current short-sell turnover for a security."
    // Type: "Volume"
    tbricks::MarketDataParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe9114d33c774d0fbULL, 0xb7061c0d5e2445bbULL));
    return pd;
}

}

namespace calculated_values {

/// Calculated value  "FX adjustment bid", type "Double"
inline tbricks::InstrumentCalculatedValueDefinition FX_AdjustmentBid()
{
    // Identifier: "cc62bd00-02e5-4230-ad99-3f442e2d64af"
    // Name: "FX adjustment bid"
    // Description: "FX adjustment bid"
    // Type: "Double"
    tbricks::InstrumentCalculatedValueDefinition pd(
        std::pair<uint64_t, uint64_t>(0x3042e50200bd62ccULL, 0xaf642d2e443f99adULL));
    return pd;
}

/// Calculated value  "Net position", type "Volume"
inline tbricks::InstrumentCalculatedValueDefinition NetPosition()
{
    // Identifier: "7ab4e63f-f9e5-45a3-824e-21598cf0ff54"
    // Name: "Net position"
    // Description: "Net position (bought - sold)."
    // Type: "Volume"
    tbricks::InstrumentCalculatedValueDefinition pd(
        std::pair<uint64_t, uint64_t>(0xa345e5f93fe6b47aULL, 0x54fff08c59214e82ULL));
    return pd;
}

/// Calculated value  "Moneyness", type "Integer"
inline tbricks::InstrumentCalculatedValueDefinition Moneyness()
{
    // Identifier: "dfad8dad-a3e7-41c1-b42f-8fbe55c1e3cc"
    // Name: "Moneyness"
    // Description: ""
    // Type: "Integer"
    tbricks::InstrumentCalculatedValueDefinition pd(
        std::pair<uint64_t, uint64_t>(0xc141e7a3ad8daddfULL, 0xcce3c155be8f2fb4ULL));
    return pd;
}

/// Calculated value  "FX adjustment ask", type "Double"
inline tbricks::InstrumentCalculatedValueDefinition FX_AdjustmentAsk()
{
    // Identifier: "e1b6d787-5a06-46d2-972a-82b2e27dc852"
    // Name: "FX adjustment ask"
    // Description: "FX adjustment ask"
    // Type: "Double"
    tbricks::InstrumentCalculatedValueDefinition pd(
        std::pair<uint64_t, uint64_t>(0xd246065a87d7b6e1ULL, 0x52c87de2b2822a97ULL));
    return pd;
}

/// Calculated value  "Strike net position", type "Volume"
inline tbricks::InstrumentCalculatedValueDefinition StrikeNetPosition()
{
    // Identifier: "a75a1590-ea77-4779-9880-c2c2d85df048"
    // Name: "Strike net position"
    // Description: "Strike net position"
    // Type: "Volume"
    tbricks::InstrumentCalculatedValueDefinition pd(
        std::pair<uint64_t, uint64_t>(0x794777ea90155aa7ULL, 0x48f05dd8c2c28098ULL));
    return pd;
}

/// Calculated value  "FX adjustment", type "Double"
inline tbricks::InstrumentCalculatedValueDefinition FX_Adjustment()
{
    // Identifier: "39ec5e3c-29db-4cf7-a6fc-42414e40ffa2"
    // Name: "FX adjustment"
    // Description: "FX adjustment"
    // Type: "Double"
    tbricks::InstrumentCalculatedValueDefinition pd(
        std::pair<uint64_t, uint64_t>(0xf74cdb293c5eec39ULL, 0xa2ff404e4142fca6ULL));
    return pd;
}

/// Calculated value  "Present value adjustment factor", type "Double"
inline tbricks::InstrumentCalculatedValueDefinition PresentValueAdjustmentFactor()
{
    // Identifier: "80edca0e-3c32-11e1-bccb-99245e0d1c06"
    // Name: "Present value adjustment factor"
    // Description: "Present value adjustment factor"
    // Type: "Double"
    tbricks::InstrumentCalculatedValueDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe111323c0ecaed80ULL, 0x61c0d5e2499cbbcULL));
    return pd;
}

}

namespace regulatory_parameters {

/// Regulatory parameter "CME iLink3 Order Type", type "String"
// Type of the order: limit, market with protection, market-limit, stop with protection or stop-limit.  Tag 40 - OrdType
inline tbricks::RegulatoryParameterDefinition CME_ILink3OrderType()
{
    // Identifier: "0519e505-63d0-11ea-a68b-b3a6db3c870c"
    // Name: "CME iLink3 Order Type"
    // Description: "Type of the order: limit, market with protection, market-limit, stop with protection or stop-limit.  Tag 40 - OrdType"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11d06305e51905ULL, 0xc873cdba6b38ba6ULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Executing Firm Id", type "String"
// Identifier of the Executing Trading Firm.  PartyRole (1 - Executing Firm)
inline tbricks::RegulatoryParameterDefinition CME_ILink3ExecutingFirmId()
{
    // Identifier: "06a55f96-6233-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Executing Firm Id"
    // Description: "Identifier of the Executing Trading Firm.  PartyRole (1 - Executing Firm)"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea113362965fa506ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "PWT quote", type "Boolean"
// Price without turnover quote for continuous auction model.
inline tbricks::RegulatoryParameterDefinition PWT_Quote()
{
    // Identifier: "6dd9de10-2b86-11e9-8d30-b51e480a0ef1"
    // Name: "PWT quote"
    // Description: "Price without turnover quote for continuous auction model."
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe911862b10ded96dULL, 0xf10e0a481eb5308dULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Avg Px Group Id", type "String"
// Used by submitting firm to group trades being allocated into an average price group. The trades in average price group will be used to calculate an average price for the group.  Tag 1731 - AvgPxGroupID
inline tbricks::RegulatoryParameterDefinition CME_ILink3AvgPxGroupId()
{
    // Identifier: "0d6fa869-6229-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Avg Px Group Id"
    // Description: "Used by submitting firm to group trades being allocated into an average price group. The trades in average price group will be used to calculate an average price for the group.  Tag 1731 - AvgPxGroupID"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11296269a86f0dULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Customer Handling Instr", type "String"
// Codes that apply special information that the Broker / Dealer needs to report, as specified by the customer. Defines source of the order.  Tag 1031 - CustOrderHandlingInst
inline tbricks::RegulatoryParameterDefinition CME_ILink3CustomerHandlingInstr()
{
    // Identifier: "12b1a247-6232-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Customer Handling Instr"
    // Description: "Codes that apply special information that the Broker / Dealer needs to report, as specified by the customer. Defines source of the order.  Tag 1031 - CustOrderHandlingInst"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11326247a2b112ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "Operator id", type "String"
// Identifies operator responsible for this transaction
inline tbricks::RegulatoryParameterDefinition OperatorId()
{
    // Identifier: "18ca3944-1dd9-11e8-8140-f8c2ad95d7bb"
    // Name: "Operator id"
    // Description: "Identifies operator responsible for this transaction"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d91d4439ca18ULL, 0xbbd795adc2f84081ULL));
    return pd;
}
/// Regulatory parameter "Prevent participant match", type "String"
// Self-match prevention setting
inline tbricks::RegulatoryParameterDefinition PreventParticipantMatch()
{
    // Identifier: "229bc6cc-1dd9-11e8-b870-a78440eba012"
    // Name: "Prevent participant match"
    // Description: "Self-match prevention setting"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d91dccc69b22ULL, 0x12a0eb4084a770b8ULL));
    return pd;
}
/// Regulatory parameter "Investment decision", type "Integer"
// Trader or Algorithm responsible for the investment decision (RTS 24, Article 2)
inline tbricks::RegulatoryParameterDefinition InvestmentDecision()
{
    // Identifier: "0e8e9276-6bc4-11e7-9970-643d79f88d82"
    // Name: "Investment decision"
    // Description: "Trader or Algorithm responsible for the investment decision (RTS 24, Article 2)"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711c46b76928e0eULL, 0x828df8793d647099ULL));
    return pd;
}
/// Regulatory parameter "Risk reset", type "String"
// Risk reset setting
inline tbricks::RegulatoryParameterDefinition RiskReset()
{
    // Identifier: "2ddce67e-1dd9-11e8-ba60-354e9ac940b6"
    // Name: "Risk reset"
    // Description: "Risk reset setting"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d91d7ee6dc2dULL, 0xb640c99a4e3560baULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Account Number", type "String"
// Identifier of the Account Number.  PartyRole (24 - Customer Account)
inline tbricks::RegulatoryParameterDefinition CME_ILink3AccountNumber()
{
    // Identifier: "2a4958a8-6233-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Account Number"
    // Description: "Identifier of the Account Number.  PartyRole (24 - Customer Account)"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea113362a858492aULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Country of Origin", type "String"
// Location of the operator.  Tag 9537 - Location
inline tbricks::RegulatoryParameterDefinition CME_ILink3CountryOfOrigin()
{
    // Identifier: "32fc347a-6215-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Country of Origin"
    // Description: "Location of the operator.  Tag 9537 - Location"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea1115627a34fc32ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "CMTA number", type "Integer"
// CMTA number of the firm that will clear the trade
inline tbricks::RegulatoryParameterDefinition CMTA_Number()
{
    // Identifier: "41716aa0-1ddb-11e8-ab50-d2d5d8eff33d"
    // Name: "CMTA number"
    // Description: "CMTA number of the firm that will clear the trade"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811db1da06a7141ULL, 0x3df3efd8d5d250abULL));
    return pd;
}
/// Regulatory parameter "Market making activity", type "Boolean"
// Liquidity provision activity flag according to maintenance of relevant data relating to orders (RTS 24, Article 3)
inline tbricks::RegulatoryParameterDefinition MarketMakingActivity()
{
    // Identifier: "24ba956e-4611-11e7-ac00-f757f678128c"
    // Name: "Market making activity"
    // Description: "Liquidity provision activity flag according to maintenance of relevant data relating to orders (RTS 24, Article 3)"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe71111466e95ba24ULL, 0x8c1278f657f700acULL));
    return pd;
}
/// Regulatory parameter "NYSE Arca Message sequence number", type "Double"
// NYSE Arca message sequence number
inline tbricks::RegulatoryParameterDefinition NYSE_ArcaMessageSequenceNumber()
{
    // Identifier: "4091300a-0f99-11ea-b596-99245e0d1c06"
    // Name: "NYSE Arca Message sequence number"
    // Description: "NYSE Arca message sequence number"
    // Type: "Double"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11990f0a309140ULL, 0x61c0d5e249996b5ULL));
    return pd;
}
/// Regulatory parameter "Direct electronic access", type "Boolean"
// Direct electronic access flag according to maintenance of relevant data relating to orders (RTS 24, Annex, Table 2)
inline tbricks::RegulatoryParameterDefinition DirectElectronicAccess()
{
    // Identifier: "2f58200e-4611-11e7-9950-2314813709a9"
    // Name: "Direct electronic access"
    // Description: "Direct electronic access flag according to maintenance of relevant data relating to orders (RTS 24, Annex, Table 2)"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe71111460e20582fULL, 0xa909378114235099ULL));
    return pd;
}
/// Regulatory parameter "Investment decision maker", type "TreeNodeIdentifier"
// Trader or Algorithm responsible for the investment decision (RTS 24, Article 2)
inline tbricks::RegulatoryParameterDefinition InvestmentDecisionMaker()
{
    // Identifier: "b344eec0-a452-11e7-8c50-5f89499047e8"
    // Name: "Investment decision maker"
    // Description: "Trader or Algorithm responsible for the investment decision (RTS 24, Article 2)"
    // Type: "TreeNodeIdentifier"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe71152a4c0ee44b3ULL, 0xe8479049895f508cULL));
    return pd;
}
/// Regulatory parameter "Cti code", type "String"
// Cti code of transaction
inline tbricks::RegulatoryParameterDefinition CtiCode()
{
    // Identifier: "4e38ed30-1ddb-11e8-a0d0-8554aa9e9e1b"
    // Name: "Cti code"
    // Description: "Cti code of transaction"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811db1d30ed384eULL, 0x1b9e9eaa5485d0a0ULL));
    return pd;
}
/// Regulatory parameter "Client identifier", type "TreeNodeIdentifier"
// 
inline tbricks::RegulatoryParameterDefinition ClientIdentifier()
{
    // Identifier: "4e2c7fde-f084-11e7-b840-deb3124dc843"
    // Name: "Client identifier"
    // Description: ""
    // Type: "TreeNodeIdentifier"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe71184f0de7f2c4eULL, 0x43c84d12b3de40b8ULL));
    return pd;
}
/// Regulatory parameter "Manual order indicator", type "Boolean"
// 
inline tbricks::RegulatoryParameterDefinition ManualOrderIndicator()
{
    // Identifier: "581320fa-1ddb-11e8-bcb0-1572d841152a"
    // Name: "Manual order indicator"
    // Description: ""
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811db1dfa201358ULL, 0x2a1541d87215b0bcULL));
    return pd;
}
/// Regulatory parameter "Self execution prevention", type "Boolean"
// Self-Execution prevention flag according to order keeping (RTS 6, Annex II, Table 3, field 22)
inline tbricks::RegulatoryParameterDefinition SelfExecutionPrevention()
{
    // Identifier: "b6eefcb6-49c4-11e7-8970-9df90a2bf4c1"
    // Name: "Self execution prevention"
    // Description: "Self-Execution prevention flag according to order keeping (RTS 6, Annex II, Table 3, field 22)"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711c449b6fceeb6ULL, 0xc1f42b0af99d7089ULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Take Up Firm", type "String"
// Identifier of the Give Up Firm.  PartyRole (96 - Take up firm)
inline tbricks::RegulatoryParameterDefinition CME_ILink3TakeUpFirm()
{
    // Identifier: "59ee930c-6233-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Take Up Firm"
    // Description: "Identifier of the Give Up Firm.  PartyRole (96 - Take up firm)"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea1133620c93ee59ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Customer Type Indicator", type "Integer"
// Capacity of customer placing the order.  Tag 582 - CustOrderCapacity
inline tbricks::RegulatoryParameterDefinition CME_ILink3CustomerTypeIndicator()
{
    // Identifier: "5a564930-6228-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Customer Type Indicator"
    // Description: "Capacity of customer placing the order.  Tag 582 - CustOrderCapacity"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea1128623049565aULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "Reject reason", type "String"
// 
inline tbricks::RegulatoryParameterDefinition RejectReason()
{
    // Identifier: "630fb89c-1ddb-11e8-ba20-f004d378f908"
    // Name: "Reject reason"
    // Description: ""
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811db1d9cb80f63ULL, 0x8f978d304f020baULL));
    return pd;
}
/// Regulatory parameter "Submission datetime", type "DateTime"
// Date and time of the submission of an order to the trading venue (RTS 6, Annex II, Table 3, field 23)
inline tbricks::RegulatoryParameterDefinition SubmissionDatetime()
{
    // Identifier: "14f39970-49c5-11e7-b320-193acb7a41e3"
    // Name: "Submission datetime"
    // Description: "Date and time of the submission of an order to the trading venue (RTS 6, Annex II, Table 3, field 23)"
    // Type: "DateTime"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711c5497099f314ULL, 0xe3417acb3a1920b3ULL));
    return pd;
}
/// Regulatory parameter "Clearing firm", type "String"
// Firm that will clear the trade
inline tbricks::RegulatoryParameterDefinition ClearingFirm()
{
    // Identifier: "82b8ccc2-1dd8-11e8-91a0-3d9b759270fc"
    // Name: "Clearing firm"
    // Description: "Firm that will clear the trade"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d81dc2ccb882ULL, 0xfc7092759b3da091ULL));
    return pd;
}
/// Regulatory parameter "Receipt datetime", type "DateTime"
// Date and time of any message that is received from the trading venue (RTS 6, Annex II, Table 3, field 24)
inline tbricks::RegulatoryParameterDefinition ReceiptDatetime()
{
    // Identifier: "9f885fda-49c5-11e7-8ee0-d655d945ab28"
    // Name: "Receipt datetime"
    // Description: "Date and time of any message that is received from the trading venue (RTS 6, Annex II, Table 3, field 24)"
    // Type: "DateTime"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711c549da5f889fULL, 0x28ab45d955d6e08eULL));
    return pd;
}
/// Regulatory parameter "CAT Session", type "String"
// Consolidated audit trail identifier representing the name or identifier of the session used when routing to an exchange.
inline tbricks::RegulatoryParameterDefinition CAT_Session()
{
    // Identifier: "32d9a5f6-9526-11ea-8d00-d66ec07deff3"
    // Name: "CAT Session"
    // Description: "Consolidated audit trail identifier representing the name or identifier of the session used when routing to an exchange."
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea112695f6a5d932ULL, 0xf3ef7dc06ed6008dULL));
    return pd;
}
/// Regulatory parameter "CAT Sequence number", type "Double"
// Consolidated audit trail sequence number of the event. Used to sequence events when multiple events have the same timestamp
inline tbricks::RegulatoryParameterDefinition CAT_SequenceNumber()
{
    // Identifier: "1667c5de-9548-11ea-b580-b20fb3c08452"
    // Name: "CAT Sequence number"
    // Description: "Consolidated audit trail sequence number of the event. Used to sequence events when multiple events have the same timestamp"
    // Type: "Double"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea114895dec56716ULL, 0x5284c0b30fb280b5ULL));
    return pd;
}
/// Regulatory parameter "CAT Receiver IMID", type "String"
// Consolidated audit trail receiver Industry Member ID/ Exchange ID.
inline tbricks::RegulatoryParameterDefinition CAT_ReceiverIMID()
{
    // Identifier: "9cd7811c-6a1f-11ea-88a0-a5467f116960"
    // Name: "CAT Receiver IMID"
    // Description: "Consolidated audit trail receiver Industry Member ID/ Exchange ID."
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea111f6a1c81d79cULL, 0x6069117f46a5a088ULL));
    return pd;
}
/// Regulatory parameter "CAT Sender IMID", type "String"
// Consolidated audit trail sender Industry Member ID/ Exchange ID.
inline tbricks::RegulatoryParameterDefinition CAT_SenderIMID()
{
    // Identifier: "838f9c6c-6a1f-11ea-8d00-e651a9060722"
    // Name: "CAT Sender IMID"
    // Description: "Consolidated audit trail sender Industry Member ID/ Exchange ID."
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea111f6a6c9c8f83ULL, 0x220706a951e6008dULL));
    return pd;
}
/// Regulatory parameter "CAT Destination", type "String"
// Consolidated audit trail SRO assigned identifier of the Industry Member or Exchange to which an order was routed.
inline tbricks::RegulatoryParameterDefinition CAT_Destination()
{
    // Identifier: "982e807c-69f0-11ea-beb0-b5e5b65d07d0"
    // Name: "CAT Destination"
    // Description: "Consolidated audit trail SRO assigned identifier of the Industry Member or Exchange to which an order was routed."
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11f0697c802e98ULL, 0xd0075db6e5b5b0beULL));
    return pd;
}
/// Regulatory parameter "CAT Open Close Indicator", type "String"
// Indicates when exchange rules require an order to be marked as open or close upon entry into the exchange. Used for Consolidated audit trail.
inline tbricks::RegulatoryParameterDefinition CAT_OpenCloseIndicator()
{
    // Identifier: "15d0386e-67b1-11ea-b080-b3478fd92649"
    // Name: "CAT Open Close Indicator"
    // Description: "Indicates when exchange rules require an order to be marked as open or close upon entry into the exchange. Used for Consolidated audit trail."
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11b1676e38d015ULL, 0x4926d98f47b380b0ULL));
    return pd;
}
/// Regulatory parameter "CAT Trading Session", type "String"
// Consolidated audit trail trading session(s) during which an order is eligible to trade.
inline tbricks::RegulatoryParameterDefinition CAT_TradingSession()
{
    // Identifier: "6040db50-5efc-11ea-ab10-10040115db51"
    // Name: "CAT Trading Session"
    // Description: "Consolidated audit trail trading session(s) during which an order is eligible to trade."
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11fc5e50db4060ULL, 0x51db1501041010abULL));
    return pd;
}
/// Regulatory parameter "CAT Handling Instruction Not Held", type "Boolean"
// Consolidated audit trail order handling instructions Not Held
inline tbricks::RegulatoryParameterDefinition CAT_HandlingInstructionNotHeld()
{
    // Identifier: "5934ecd0-992f-11ea-a680-f8afc39b8790"
    // Name: "CAT Handling Instruction Not Held"
    // Description: "Consolidated audit trail order handling instructions Not Held"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea112f99d0ec3459ULL, 0x90879bc3aff880a6ULL));
    return pd;
}
/// Regulatory parameter "CAT Handling Instruction All or Non", type "Boolean"
// Consolidated audit trail order handling instructions All or Non
inline tbricks::RegulatoryParameterDefinition CAT_HandlingInstructionAllOrNon()
{
    // Identifier: "9b99d270-992f-11ea-88a0-06c62f427ef0"
    // Name: "CAT Handling Instruction All or Non"
    // Description: "Consolidated audit trail order handling instructions All or Non"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea112f9970d2999bULL, 0xf07e422fc606a088ULL));
    return pd;
}
/// Regulatory parameter "CAT Handling Instruction Slide", type "Boolean"
// Consolidated audit trail order handling instructions Slide - instruction to adjust limit price to prevent locked or crossed market
inline tbricks::RegulatoryParameterDefinition CAT_HandlingInstructionSlide()
{
    // Identifier: "e87ce262-992f-11ea-aae0-1494ae324418"
    // Name: "CAT Handling Instruction Slide"
    // Description: "Consolidated audit trail order handling instructions Slide - instruction to adjust limit price to prevent locked or crossed market"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea112f9962e27ce8ULL, 0x184432ae9414e0aaULL));
    return pd;
}
/// Regulatory parameter "CAT Handling Instruction Stop on Quote", type "Boolean"
// Consolidated audit trail order handling instructions Stop on Quote
inline tbricks::RegulatoryParameterDefinition CAT_HandlingInstructionStopOnQuote()
{
    // Identifier: "0434ccca-9941-11ea-b350-e6dc4699f446"
    // Name: "CAT Handling Instruction Stop on Quote"
    // Description: "Consolidated audit trail order handling instructions Stop on Quote"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea114199cacc3404ULL, 0x46f49946dce650b3ULL));
    return pd;
}
/// Regulatory parameter "CAT Handling Instruction Stop Limit on Quote", type "Boolean"
// Consolidated audit trail oCATrder handling instructions Stop Limit on Quote
inline tbricks::RegulatoryParameterDefinition CAT_HandlingInstructionStopLimitOnQuote()
{
    // Identifier: "8768ba7c-9930-11ea-b230-c9b1bfc4c3db"
    // Name: "CAT Handling Instruction Stop Limit on Quote"
    // Description: "Consolidated audit trail oCATrder handling instructions Stop Limit on Quote"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea1130997cba6887ULL, 0xdbc3c4bfb1c930b2ULL));
    return pd;
}
/// Regulatory parameter "CAT Handling Instruction Fill or Kill", type "Boolean"
// Consolidated audit trail order handling instructions Fill or Kill
inline tbricks::RegulatoryParameterDefinition CAT_HandlingInstructionFillOrKill()
{
    // Identifier: "c053c8cc-9930-11ea-8630-fe7835957e81"
    // Name: "CAT Handling Instruction Fill or Kill"
    // Description: "Consolidated audit trail order handling instructions Fill or Kill"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea113099ccc853c0ULL, 0x817e953578fe3086ULL));
    return pd;
}
/// Regulatory parameter "CAT Handling Instruction Market on Close", type "Boolean"
// Consolidated audit trail order handling instructions Market on Close
inline tbricks::RegulatoryParameterDefinition CAT_HandlingInstructionMarketOnClose()
{
    // Identifier: "03e2186e-9931-11ea-8e40-868e4209b213"
    // Name: "CAT Handling Instruction Market on Close"
    // Description: "Consolidated audit trail order handling instructions Market on Close"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea1131996e18e203ULL, 0x13b209428e86408eULL));
    return pd;
}
/// Regulatory parameter "CAT Handling Instruction Market at Open", type "Boolean"
// Consolidated audit trail order handling instructions Market at Open
inline tbricks::RegulatoryParameterDefinition CAT_HandlingInstructionMarketAtOpen()
{
    // Identifier: "457502e6-9931-11ea-95a0-bf4745c4ba6f"
    // Name: "CAT Handling Instruction Market at Open"
    // Description: "Consolidated audit trail order handling instructions Market at Open"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea113199e6027545ULL, 0x6fbac44547bfa095ULL));
    return pd;
}
/// Regulatory parameter "CAT Handling Instruction Limit on Open", type "Boolean"
// Consolidated audit trail order handling instructions Limit on Open
inline tbricks::RegulatoryParameterDefinition CAT_HandlingInstructionLimitOnOpen()
{
    // Identifier: "7df9c444-9931-11ea-a330-d1e4c23f2f72"
    // Name: "CAT Handling Instruction Limit on Open"
    // Description: "Consolidated audit trail order handling instructions Limit on Open"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11319944c4f97dULL, 0x722f3fc2e4d130a3ULL));
    return pd;
}
/// Regulatory parameter "CAT Handling Instruction Limit on Close", type "Boolean"
// Consolidated audit trail order handling instructions Limit on Close
inline tbricks::RegulatoryParameterDefinition CAT_HandlingInstructionLimitOnClose()
{
    // Identifier: "9b03f546-9931-11ea-8390-81fb361d34d8"
    // Name: "CAT Handling Instruction Limit on Close"
    // Description: "Consolidated audit trail order handling instructions Limit on Close"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11319946f5039bULL, 0xd8341d36fb819083ULL));
    return pd;
}
/// Regulatory parameter "CAT Order Key Date", type "DateTime"
// Consolidated audit trail date and time the orderID was assigned
inline tbricks::RegulatoryParameterDefinition CAT_OrderKeyDate()
{
    // Identifier: "c2538416-99ec-11ea-99f0-17a8e3356808"
    // Name: "CAT Order Key Date"
    // Description: "Consolidated audit trail date and time the orderID was assigned"
    // Type: "DateTime"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11ec99168453c2ULL, 0x86835e3a817f099ULL));
    return pd;
}
/// Regulatory parameter "NYSE Arca Trading session id", type "String"
// NYSE Arca trading session id
inline tbricks::RegulatoryParameterDefinition NYSE_ArcaTradingSessionId()
{
    // Identifier: "74fd70ea-0fa0-11ea-b596-99245e0d1c06"
    // Name: "NYSE Arca Trading session id"
    // Description: "NYSE Arca trading session id"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11a00fea70fd74ULL, 0x61c0d5e249996b5ULL));
    return pd;
}
/// Regulatory parameter "Client identification qualifier", type "Integer"
// 
inline tbricks::RegulatoryParameterDefinition ClientIdentificationQualifier()
{
    // Identifier: "921a85cc-73a9-11e7-91d0-9a24d1ca2ba1"
    // Name: "Client identification qualifier"
    // Description: ""
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711a973cc851a92ULL, 0xa12bcad1249ad091ULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Client Order Id", type "String"
// Customer-generated code uniquely identifying an order, a cancel or cancel replace message.  Tag 11 - ClOrdID
inline tbricks::RegulatoryParameterDefinition CME_ILink3ClientOrderId()
{
    // Identifier: "7ae4a922-6236-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Client Order Id"
    // Description: "Customer-generated code uniquely identifying an order, a cancel or cancel replace message.  Tag 11 - ClOrdID"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11366222a9e47aULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Take up Account", type "String"
// Identifier of the Give Up Account Number.  PartyRole (1000 - Take up account)
inline tbricks::RegulatoryParameterDefinition CME_ILink3TakeUpAccount()
{
    // Identifier: "7fae9e66-6233-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Take up Account"
    // Description: "Identifier of the Give Up Account Number.  PartyRole (1000 - Take up account)"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea113362669eae7fULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "Execution decision qualifier", type "Integer"
// 
inline tbricks::RegulatoryParameterDefinition ExecutionDecisionQualifier()
{
    // Identifier: "9281a676-73a9-11e7-8000-3e8e58b3d9bd"
    // Name: "Execution decision qualifier"
    // Description: ""
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711a97376a68192ULL, 0xbdd9b3588e3e0080ULL));
    return pd;
}
/// Regulatory parameter "NYSE Arca Session id", type "Double"
// NYSE Arca regulatory audit parameter
inline tbricks::RegulatoryParameterDefinition NYSE_ArcaSessionId()
{
    // Identifier: "8a958814-0f98-11ea-b596-99245e0d1c06"
    // Name: "NYSE Arca Session id"
    // Description: "NYSE Arca regulatory audit parameter"
    // Type: "Double"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11980f1488958aULL, 0x61c0d5e249996b5ULL));
    return pd;
}
/// Regulatory parameter "Investment decision qualifier", type "Integer"
// 
inline tbricks::RegulatoryParameterDefinition InvestmentDecisionQualifier()
{
    // Identifier: "92e24c60-73a9-11e7-a820-9843fe63c944"
    // Name: "Investment decision qualifier"
    // Description: ""
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711a973604ce292ULL, 0x44c963fe439820a8ULL));
    return pd;
}
/// Regulatory parameter "NYSE Arca MMID", type "Double"
// NYSE Arca Market Maker ID
inline tbricks::RegulatoryParameterDefinition NYSE_ArcaMMID()
{
    // Identifier: "8bce580c-1545-11ea-b2ae-06b747deb312"
    // Name: "NYSE Arca MMID"
    // Description: "NYSE Arca Market Maker ID"
    // Type: "Double"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea1145150c58ce8bULL, 0x12b3de47b706aeb2ULL));
    return pd;
}
/// Regulatory parameter "NYSE Arca Proactive if locked", type "String"
// NYSE Arca proactive if locked
inline tbricks::RegulatoryParameterDefinition NYSE_ArcaProactiveIfLocked()
{
    // Identifier: "9163739c-0fa0-11ea-b596-99245e0d1c06"
    // Name: "NYSE Arca Proactive if locked"
    // Description: "NYSE Arca proactive if locked"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11a00f9c736391ULL, 0x61c0d5e249996b5ULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Message Type", type "String"
// Identifies the type of the message captured.
inline tbricks::RegulatoryParameterDefinition CME_ILink3MessageType()
{
    // Identifier: "92080bbc-6213-11ea-993e-529049f1f1bb"
    // Name: "CME iLink3 Message Type"
    // Description: "Identifies the type of the message captured."
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea111362bc0b0892ULL, 0xbbf1f14990523e99ULL));
    return pd;
}
/// Regulatory parameter "Trading venue transaction identification code", type "String"
// 
inline tbricks::RegulatoryParameterDefinition TradingVenueTransactionIdentificationCode()
{
    // Identifier: "d042c900-c92f-11e7-80c0-6706b5cda04c"
    // Name: "Trading venue transaction identification code"
    // Description: ""
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe7112fc900c942d0ULL, 0x4ca0cdb50667c080ULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Clearing Trade Price Type", type "Integer"
// Indicates to recipient whether trade is clearing at execution prices LastPx (tag 31) or alternate clearing price (prior day settlement price).  Tag 1598 - ClearingTradePriceType
inline tbricks::RegulatoryParameterDefinition CME_ILink3ClearingTradePriceType()
{
    // Identifier: "9f3cd43e-6231-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Clearing Trade Price Type"
    // Description: "Indicates to recipient whether trade is clearing at execution prices LastPx (tag 31) or alternate clearing price (prior day settlement price).  Tag 1598 - ClearingTradePriceType"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea1131623ed43c9fULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Source of Cancellation", type "Integer"
// CME Globex-generated code identifying the source of a cancel when triggered by CME Group.  Tag 378 - ExecRestatementReason
inline tbricks::RegulatoryParameterDefinition CME_ILink3SourceOfCancellation()
{
    // Identifier: "a0bd6eae-6222-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Source of Cancellation"
    // Description: "CME Globex-generated code identifying the source of a cancel when triggered by CME Group.  Tag 378 - ExecRestatementReason"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea112262ae6ebda0ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "Order status", type "Integer"
// Order status according to order keeping (RTS 6, Annex II, Table 3, field 26)
inline tbricks::RegulatoryParameterDefinition OrderStatus()
{
    // Identifier: "52da46e8-49c6-11e7-a560-2b26373cb09b"
    // Name: "Order status"
    // Description: "Order status according to order keeping (RTS 6, Annex II, Table 3, field 26)"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711c649e846da52ULL, 0x9bb03c37262b60a5ULL));
    return pd;
}
/// Regulatory parameter "NYSE Arca Cancel instead of reprice", type "String"
// 
inline tbricks::RegulatoryParameterDefinition NYSE_ArcaCancelInsteadOfReprice()
{
    // Identifier: "a8c0ef74-0fa0-11ea-b596-99245e0d1c06"
    // Name: "NYSE Arca Cancel instead of reprice"
    // Description: ""
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11a00f74efc0a8ULL, 0x61c0d5e249996b5ULL));
    return pd;
}
/// Regulatory parameter "NYSE Arca LocateReqd", type "Boolean"
// NYSE Arca LocateReq for SSH orders
inline tbricks::RegulatoryParameterDefinition NYSE_ArcaLocateReqd()
{
    // Identifier: "b2abb5db-1547-11ea-b2ae-06b747deb312"
    // Name: "NYSE Arca LocateReqd"
    // Description: "NYSE Arca LocateReq for SSH orders"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea114715dbb5abb2ULL, 0x12b3de47b706aeb2ULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Origin", type "Integer"
// Designates the account type to be used for the order when submitted to clearing Tag 1816 - ClearingAccountType
inline tbricks::RegulatoryParameterDefinition CME_ILink3Origin()
{
    // Identifier: "a5d80666-6217-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Origin"
    // Description: "Designates the account type to be used for the order when submitted to clearing Tag 1816 - ClearingAccountType"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea1117626606d8a5ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Average Px Ind", type "Integer"
// Average pricing indicator.  Tag 819 - AvgPxInd
inline tbricks::RegulatoryParameterDefinition CME_ILink3AveragePxInd()
{
    // Identifier: "b181e8f9-6229-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Average Px Ind"
    // Description: "Average pricing indicator.  Tag 819 - AvgPxInd"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea112962f9e881b1ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Party Details List Request Id", type "Integer"
// Refers to the ID of the related PartyDetailsDefinitionRequest message which will logically be tied to this message.  Tag 1505 - PartyDetailsListRequestID
inline tbricks::RegulatoryParameterDefinition CME_ILink3PartyDetailsListRequestId()
{
    // Identifier: "b3d013c9-6215-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Party Details List Request Id"
    // Description: "Refers to the ID of the related PartyDetailsDefinitionRequest message which will logically be tied to this message.  Tag 1505 - PartyDetailsListRequestID"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea111562c913d0b3ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 IFM Flag", type "Integer"
// Modification flag identifying if in-flight-mitigation functionality is activated or not.
inline tbricks::RegulatoryParameterDefinition CME_ILink3IFM_Flag()
{
    // Identifier: "c0f82722-6213-11ea-993e-529049f1f1bb"
    // Name: "CME iLink3 IFM Flag"
    // Description: "Modification flag identifying if in-flight-mitigation functionality is activated or not."
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea1113622227f8c0ULL, 0xbbf1f14990523e99ULL));
    return pd;
}
/// Regulatory parameter "Executor identifier", type "Identifier"
// 
inline tbricks::RegulatoryParameterDefinition ExecutorIdentifier()
{
    // Identifier: "c911f3f0-f084-11e7-b840-deb3124dc843"
    // Name: "Executor identifier"
    // Description: ""
    // Type: "Identifier"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe71184f0f0f311c9ULL, 0x43c84d12b3de40b8ULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Session Id", type "String"
// Identifier of the iLink Order Entry session.
inline tbricks::RegulatoryParameterDefinition CME_ILink3SessionId()
{
    // Identifier: "cd33a512-6212-11ea-993e-529049f1f1bb"
    // Name: "CME iLink3 Session Id"
    // Description: "Identifier of the iLink Order Entry session."
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11126212a533cdULL, 0xbbf1f14990523e99ULL));
    return pd;
}
/// Regulatory parameter "Clearing account", type "String"
// Supplemental identifier
inline tbricks::RegulatoryParameterDefinition ClearingAccount()
{
    // Identifier: "d9437eac-1dd8-11e8-bac0-bea63d32260d"
    // Name: "Clearing account"
    // Description: "Supplemental identifier"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe811d81dac7e43d9ULL, 0xd26323da6bec0baULL));
    return pd;
}
/// Regulatory parameter "Routing strategy", type "String"
// The applicable routing strategy as per the trading venue spe­cification. This field shall be left blank if not relevant. (RTS 6, Annex II, Table 3, field 29)
inline tbricks::RegulatoryParameterDefinition RoutingStrategy()
{
    // Identifier: "28cf08b8-aaae-11e7-97f0-5762db4ed51c"
    // Name: "Routing strategy"
    // Description: "The applicable routing strategy as per the trading venue spe­cification. This field shall be left blank if not relevant. (RTS 6, Annex II, Table 3, field 29)"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711aeaab808cf28ULL, 0x1cd54edb6257f097ULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 CMTA Give Up CD", type "String"
// Indicates if the order is a give-up or SGX offset.  Tag 9708 - CmtaGiveUpCD
inline tbricks::RegulatoryParameterDefinition CME_ILink3CMTA_GiveUpCD()
{
    // Identifier: "e360c754-6229-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 CMTA Give Up CD"
    // Description: "Indicates if the order is a give-up or SGX offset.  Tag 9708 - CmtaGiveUpCD"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11296254c760e3ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "Client identification code", type "Integer"
// The Client on whose behalf order is submitted to the trading venue (RTS 24, Article 2)
inline tbricks::RegulatoryParameterDefinition ClientIdentificationCode()
{
    // Identifier: "b439001e-6bc2-11e7-ab90-c0251f12b18c"
    // Name: "Client identification code"
    // Description: "The Client on whose behalf order is submitted to the trading venue (RTS 24, Article 2)"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711c26b1e0039b4ULL, 0x8cb1121f25c090abULL));
    return pd;
}
/// Regulatory parameter "NYSE Arca MPID", type "String"
// NYSE Arca Firm Identifier
inline tbricks::RegulatoryParameterDefinition NYSE_ArcaMPID()
{
    // Identifier: "f320cb7b-1545-11ea-b2ae-06b747deb312"
    // Name: "NYSE Arca MPID"
    // Description: "NYSE Arca Firm Identifier"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea1145157bcb20f3ULL, 0x12b3de47b706aeb2ULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Message Direction", type "String"
// Explicit labeling of the direction of the captured message.  "TO CME" : for messages leaving Tier 1 component towards the CME Globex platform  "FROM CME" : for messages received by Tier 1 component from the CME Globex platform
inline tbricks::RegulatoryParameterDefinition CME_ILink3MessageDirection()
{
    // Identifier: "ec014b12-6211-11ea-993e-529049f1f1bb"
    // Name: "CME iLink3 Message Direction"
    // Description: "Explicit labeling of the direction of the captured message.  "TO CME" : for messages leaving Tier 1 component towards the CME Globex platform  "FROM CME" : for messages received by Tier 1 component from the CME Globex platform"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea111162124b01ecULL, 0xbbf1f14990523e99ULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 List Update Action", type "String"
// Indicates if all of the information sent in this message with a unique new PartyDetailsListReqID is a new addition or deletion of existing information associated with an existing PartyDetailsListReqID.  Tag 1324 - ListUpdateAction
inline tbricks::RegulatoryParameterDefinition CME_ILink3ListUpdateAction()
{
    // Identifier: "f178cf86-6223-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 List Update Action"
    // Description: "Indicates if all of the information sent in this message with a unique new PartyDetailsListReqID is a new addition or deletion of existing information associated with an existing PartyDetailsListReqID.  Tag 1324 - ListUpdateAction"
    // Type: "String"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11236286cf78f1ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "CME iLink3 Self-Matching Prevention Id", type "Integer"
// Identifies an order or trade that should not be matched to an opposite order or trade if both buy and sell orders for the same asset contain the same SelfMatchPreventionID(2362) and submitted by the same firm.  Tag 2362 - SelfMatchPreventionID
inline tbricks::RegulatoryParameterDefinition CME_ILink3SelfMatchingPreventionId()
{
    // Identifier: "f3f0876d-6215-11ea-bb45-245e0d1c06b7"
    // Name: "CME iLink3 Self-Matching Prevention Id"
    // Description: "Identifies an order or trade that should not be matched to an opposite order or trade if both buy and sell orders for the same asset contain the same SelfMatchPreventionID(2362) and submitted by the same firm.  Tag 2362 - SelfMatchPreventionID"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea1115626d87f0f3ULL, 0xb7061c0d5e2445bbULL));
    return pd;
}
/// Regulatory parameter "Investor identifier", type "Identifier"
// 
inline tbricks::RegulatoryParameterDefinition InvestorIdentifier()
{
    // Identifier: "f624523f-f084-11e7-b840-deb3124dc843"
    // Name: "Investor identifier"
    // Description: ""
    // Type: "Identifier"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe71184f03f5224f6ULL, 0x43c84d12b3de40b8ULL));
    return pd;
}
/// Regulatory parameter "Execution decision", type "Integer"
// Trader or Algorithm responsible for the execution (RTS 24, Article 2)
inline tbricks::RegulatoryParameterDefinition ExecutionDecision()
{
    // Identifier: "0e7424f4-6bc4-11e7-bb90-98165cb98da6"
    // Name: "Execution decision"
    // Description: "Trader or Algorithm responsible for the execution (RTS 24, Article 2)"
    // Type: "Integer"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe711c46bf424740eULL, 0xa68db95c169890bbULL));
    return pd;
}
/// Regulatory parameter "NYSE Arca Retail Indicator", type "Boolean"
// NYSE Arca Retail or not Retail order
inline tbricks::RegulatoryParameterDefinition NYSE_ArcaRetailIndicator()
{
    // Identifier: "fd61b193-1547-11ea-b2ae-06b747deb312"
    // Name: "NYSE Arca Retail Indicator"
    // Description: "NYSE Arca Retail or not Retail order"
    // Type: "Boolean"
    tbricks::RegulatoryParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xea11471593b161fdULL, 0x12b3de47b706aeb2ULL));
    return pd;
}
}

namespace alert_parameters {

/// Alert parameter "Event type", type "TreeNodeIdentifier"
inline tbricks::AlertParameterDefinition EventType()
{
    // Identifier: "52faf00a-c265-11e8-92b3-bbe9ebb3a6db"
    // Name: "Event type"
    // Description: "Type of event described in the alert."
    // Type: "TreeNodeIdentifier"
    // Direction: "Output"
    tbricks::AlertParameterDefinition pd(
        std::pair<uint64_t, uint64_t>(0xe81165c20af0fa52ULL, 0xdba6b3ebe9bbb392ULL));
    return pd;
}
}

namespace extra_data {

/// Extra data "Bundle ID", type "String"
inline tbricks::String BundleID()
{
    // Identifier: "0c8863ea-72de-11e8-b809-0c3e99245e0d"
    // Name: "Bundle ID"
    // Description: "Bundle ID"
    // Type: "String"
    tbricks::String s("com.itiviti.bundle_id");
    return s;
}

/// Extra data "Reputational score", type "Integer"
inline tbricks::String ReputationalScore()
{
    // Identifier: "48864f4a-4474-11e7-b596-99245e0d1c06"
    // Name: "Reputational score"
    // Description: "Reputational Score for the BI Participant at the time of the Turquoise Plato Block Discovery™ match."
    // Type: "Integer"
    tbricks::String s("com.tbricks.reputational_score");
    return s;
}

/// Extra data "FIXAtdl strategy name", type "String"
inline tbricks::String FIXAtdlStrategyName()
{
    // Identifier: "66efb6ba-5c16-11e7-abe9-e16cd6ae5290"
    // Name: "FIXAtdl strategy name"
    // Description: "Hidden extra data to persist Strategy for FIXAtdl panel."
    // Type: "String"
    tbricks::String s("com.itiviti.FIXAtdl.strategyName");
    return s;
}

/// Extra data "Internal state", type "Integer"
inline tbricks::String InternalState()
{
    // Identifier: "a9e2ea0c-24f6-11e7-9a20-b747deb3124d"
    // Name: "Internal state"
    // Description: "Auxiliary app state index stored in extra data"
    // Type: "Integer"
    tbricks::String s("tb.internal.state");
    return s;
}

/// Extra data "Bundle state", type "String"
inline tbricks::String BundleState()
{
    // Identifier: "af5e60b6-72dd-11e8-b809-0c3e99245e0d"
    // Name: "Bundle state"
    // Description: "Bundle state"
    // Type: "String"
    tbricks::String s("com.itiviti.bundle_state");
    return s;
}

}

namespace roles {

/// Role "Trader", description "A trader operating trading strategies."
inline tbricks::Uuid TraderIdentifier()
{
    // Identifier: "73035a5e-9d74-11e0-81e3-cac4bb3ac176"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011749d5e5a0373ULL, 0x76c13abbc4cae381ULL));
    return pd;
}

/// Role "RiskManager", description "A risk manager operating risk reports."
inline tbricks::Uuid RiskManagerIdentifier()
{
    // Identifier: "732a7e5e-9d74-11e0-8d66-203cbba3c44f"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011749d5e7e2a73ULL, 0x4fc4a3bb3c20668dULL));
    return pd;
}

/// Role "Compliance", description "A compliance manager setting risk limits."
inline tbricks::Uuid ComplianceIdentifier()
{
    // Identifier: "727f5ac4-9d74-11e0-bf8c-ce341c2ab477"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011749dc45a7f72ULL, 0x77b42a1c34ce8cbfULL));
    return pd;
}

/// Role "SystemAdministrator", description "A system manager monitoring the system."
inline tbricks::Uuid SystemAdministratorIdentifier()
{
    // Identifier: "72d8b952-9d74-11e0-97c5-f3b0f023bd26"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011749d52b9d872ULL, 0x26bd23f0b0f3c597ULL));
    return pd;
}

/// Role "Developer", description "A developer configuring system metadata (columns, apps, ...)."
inline tbricks::Uuid DeveloperIdentifier()
{
    // Identifier: "734ca88a-9d74-11e0-9d60-f9c2b36ff247"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011749d8aa84c73ULL, 0x47f26fb3c2f9609dULL));
    return pd;
}

/// Role "BackOffice", description "A back-office staff member with read-only access."
inline tbricks::Uuid BackOfficeIdentifier()
{
    // Identifier: "737c3820-9d74-11e0-8987-9ce71bdd0b52"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011749d20387c73ULL, 0x520bdd1be79c8789ULL));
    return pd;
}

/// Role "RBAC_Manager", description "A person that can assign privileges for other persons."
inline tbricks::Uuid RBAC_ManagerIdentifier()
{
    // Identifier: "73a95f58-9d74-11e0-8849-69b8e3904466"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe011749d585fa973ULL, 0x664490e3b8694988ULL));
    return pd;
}

/// Role "Unrestricted", description "Unrestricted, unfiltered total privileges."
inline tbricks::Uuid UnrestrictedIdentifier()
{
    // Identifier: "54592e2a-4da6-11e1-8775-2112588b6182"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe111a64d2a2e5954ULL, 0x82618b5812217587ULL));
    return pd;
}

/// Role "Desk", description "A trader that is allowed to change parameters, order, apps etc for members of the group."
inline tbricks::Uuid DeskIdentifier()
{
    // Identifier: "54a1e016-4da6-11e1-9595-95d7f43a56ed"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe111a64d16e0a154ULL, 0xed563af4d7959595ULL));
    return pd;
}

/// Role "Support", description "Itiviti support privileges. View mode and emergency stop."
inline tbricks::Uuid SupportIdentifier()
{
    // Identifier: "44663878-6a02-11e6-993e-529049f1f1bb"
    tbricks::Uuid pd(
        std::pair<uint64_t, uint64_t>(0xe611026a78386644ULL, 0xbbf1f14990523e99ULL));
    return pd;
}

}

namespace parameter_contexts {

/// Parameter context "Trading", description "Parameters used by trading desk"
inline tbricks::Identifier Trading()
{
    // Identifier: "132459a4-32d3-11e1-8b7d-898c7bb483ce"
    // Name: "Trading"
    // Description: "Parameters used by trading desk"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe111d332a4592413ULL, 0xce83b47b8c897d8bULL));
    return pd;
}

/// Parameter context "MM quoting", description "Parameters used for MM quoting"
inline tbricks::Identifier MM_Quoting()
{
    // Identifier: "45bda54c-c738-11e1-87b7-be84e16cd6ae"
    // Name: "MM quoting"
    // Description: "Parameters used for MM quoting"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe11138c74ca5bd45ULL, 0xaed66ce184beb787ULL));
    return pd;
}

/// Parameter context "MM hidden", description "Parameter used for MM hidden"
inline tbricks::Identifier MM_Hidden()
{
    // Identifier: "4afea20e-c738-11e1-87b7-be84e16cd6ae"
    // Name: "MM hidden"
    // Description: "Parameter used for MM hidden"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe11138c70ea2fe4aULL, 0xaed66ce184beb787ULL));
    return pd;
}

/// Parameter context "MM quoting multi-level", description "Parameters used for MM multi-level quoting"
inline tbricks::Identifier MM_QuotingMultiLevel()
{
    // Identifier: "64c7c864-c738-11e1-87b7-be84e16cd6ae"
    // Name: "MM quoting multi-level"
    // Description: "Parameters used for MM multi-level quoting"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe11138c764c8c764ULL, 0xaed66ce184beb787ULL));
    return pd;
}

/// Parameter context "MM quote responder", description "Parameters used for MM quote responder"
inline tbricks::Identifier MM_QuoteResponder()
{
    // Identifier: "6d052202-d195-11e2-bb45-3e99245e0d1c"
    // Name: "MM quote responder"
    // Description: "Parameters used for MM quote responder"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe21195d10222056dULL, 0x1c0d5e24993e45bbULL));
    return pd;
}

/// Parameter context "MM shared", description "Parameters used by the MM app for shared state"
inline tbricks::Identifier MM_Shared()
{
    // Identifier: "ed8fe919-caa5-11e1-bcdb-49f1f1bbe9eb"
    // Name: "MM shared"
    // Description: "Parameters used by the MM app for shared state"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe111a5ca19e98fedULL, 0xebe9bbf1f149dbbcULL));
    return pd;
}

/// Parameter context "Global", description "Global parameters, typically used as final fallback in a parameter ranking"
inline tbricks::Identifier Global()
{
    // Identifier: "f4414006-32d2-11e1-8d0a-141222d69e81"
    // Name: "Global"
    // Description: "Global parameters, typically used as final fallback in a parameter ranking"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe111d232064041f4ULL, 0x819ed62212140a8dULL));
    return pd;
}

/// Parameter context "MM peg", description "Parameters used for MM peg"
inline tbricks::Identifier MM_Peg()
{
    // Identifier: "f8d2106a-f27a-11e1-8bbb-3c870c3e9924"
    // Name: "MM peg"
    // Description: "Parameters used for MM peg"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe1117af26a10d2f8ULL, 0x24993e0c873cbb8bULL));
    return pd;
}

/// Parameter context "Risk", description "Parameters used by risk management, typically used for having a different view of pricing"
inline tbricks::Identifier Risk()
{
    // Identifier: "fbebb976-32d2-11e1-8e88-cf8d809fed42"
    // Name: "Risk"
    // Description: "Parameters used by risk management, typically used for having a different view of pricing"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe111d23276b9ebfbULL, 0x42ed9f808dcf888eULL));
    return pd;
}

}

namespace rankings {

/// Ranking "MM quoting multi-level", type "ParameterContext"
// Ranking used for MM quoting multi-level
inline tbricks::Identifier MM_QuotingMultiLevel()
{
    // Identifier: "0c72baec-c739-11e1-87b7-be84e16cd6ae"
    // Name: "MM quoting multi-level"
    // Description: "Ranking used for MM quoting multi-level"
    // Type: "ParameterContext"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe11139c7ecba720cULL, 0xaed66ce184beb787ULL));
    return pd;
}

/// Ranking "MM peg", type "ParameterContext"
// Ranking used for MM peg
inline tbricks::Identifier MM_Peg()
{
    // Identifier: "2232f05a-f27b-11e1-8bbb-3c870c3e9924"
    // Name: "MM peg"
    // Description: "Ranking used for MM peg"
    // Type: "ParameterContext"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe1117bf25af03222ULL, 0x24993e0c873cbb8bULL));
    return pd;
}

/// Ranking "MM quote responder", type "ParameterContext"
// Ranking used for MM quote responder
inline tbricks::Identifier MM_QuoteResponder()
{
    // Identifier: "462f1f22-d198-11e2-bb45-3e99245e0d1c"
    // Name: "MM quote responder"
    // Description: "Ranking used for MM quote responder"
    // Type: "ParameterContext"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe21198d1221f2f46ULL, 0x1c0d5e24993e45bbULL));
    return pd;
}

/// Ranking "Risk", type "ParameterContext"
// Risk ranking
inline tbricks::Identifier Risk()
{
    // Identifier: "586cf076-32d2-11e1-9cc9-eda4fff76405"
    // Name: "Risk"
    // Description: "Risk ranking"
    // Type: "ParameterContext"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe111d23276f06c58ULL, 0x564f7ffa4edc99cULL));
    return pd;
}

/// Ranking "Global", type "ParameterContext"
// Global ranking
inline tbricks::Identifier Global()
{
    // Identifier: "5e325302-32d2-11e1-be6e-e748d6d66bf3"
    // Name: "Global"
    // Description: "Global ranking"
    // Type: "ParameterContext"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe111d2320253325eULL, 0xf36bd6d648e76ebeULL));
    return pd;
}

/// Ranking "MM shared", type "ParameterContext"
// Ranking used for MM shared data lookups
inline tbricks::Identifier MM_Shared()
{
    // Identifier: "8baf2b37-cbf0-11e1-83c8-06b747deb312"
    // Name: "MM shared"
    // Description: "Ranking used for MM shared data lookups"
    // Type: "ParameterContext"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe111f0cb372baf8bULL, 0x12b3de47b706c883ULL));
    return pd;
}

/// Ranking "Trading", type "ParameterContext"
// Trading ranking
inline tbricks::Identifier Trading()
{
    // Identifier: "c4140f68-32d1-11e1-84fa-2edb198d3926"
    // Name: "Trading"
    // Description: "Trading ranking"
    // Type: "ParameterContext"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe111d132680f14c4ULL, 0x26398d19db2efa84ULL));
    return pd;
}

/// Ranking "MM hidden", type "ParameterContext"
// Ranking used for MM hidden
inline tbricks::Identifier MM_Hidden()
{
    // Identifier: "dfde92a8-c738-11e1-87b7-be84e16cd6ae"
    // Name: "MM hidden"
    // Description: "Ranking used for MM hidden"
    // Type: "ParameterContext"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe11138c7a892dedfULL, 0xaed66ce184beb787ULL));
    return pd;
}

/// Ranking "MM quoting", type "ParameterContext"
// Ranking used for MM quoting
inline tbricks::Identifier MM_Quoting()
{
    // Identifier: "fd39d682-c738-11e1-87b7-be84e16cd6ae"
    // Name: "MM quoting"
    // Description: "Ranking used for MM quoting"
    // Type: "ParameterContext"
    tbricks::Identifier pd(
        std::pair<uint64_t, uint64_t>(0xe11138c782d639fdULL, 0xaed66ce184beb787ULL));
    return pd;
}

}

namespace tree_nodes {

/// TreeNode "Trading", description "Root node for Trading events"
inline tbricks::TreeNodeIdentifier TradingIdentifier()
{
    // Identifier: "8746f96c-c260-11e8-8bf0-d082bebeedc7"
    // Name: "Trading"
    // Description: "Root node for Trading events"
    // Tree type: "c0f04b04-c252-11e8-8a30-05194b27cb6f"
    tbricks::TreeNodeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe81160c26cf94687ULL, 0xc7edbebe82d0f08bULL));
    return pd;
}

/// TreeNode "MassCancel", description "Mass cancel operation"
inline tbricks::TreeNodeIdentifier MassCancelIdentifier()
{
    // Identifier: "07b4d43c-c263-11e8-acc0-ff9a618f6f57"
    // Name: "Mass cancel"
    // Description: "Mass cancel operation"
    // Tree type: "c0f04b04-c252-11e8-8a30-05194b27cb6f"
    tbricks::TreeNodeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe81163c23cd4b407ULL, 0x576f8f619affc0acULL));
    return pd;
}

/// TreeNode "TradingBlock", description "Trading block operation"
inline tbricks::TreeNodeIdentifier TradingBlockIdentifier()
{
    // Identifier: "3da9bd6e-c263-11e8-b720-45169982f14c"
    // Name: "Trading block"
    // Description: "Trading block operation"
    // Tree type: "c0f04b04-c252-11e8-8a30-05194b27cb6f"
    tbricks::TreeNodeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe81163c26ebda93dULL, 0x4cf18299164520b7ULL));
    return pd;
}

/// TreeNode "OrderReject", description "Order creation or modification reject"
inline tbricks::TreeNodeIdentifier OrderRejectIdentifier()
{
    // Identifier: "d1cb8576-13f9-11e9-be00-e2a07d781e76"
    // Name: "Order reject"
    // Description: "Order creation or modification reject"
    // Tree type: "c0f04b04-c252-11e8-8a30-05194b27cb6f"
    tbricks::TreeNodeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe911f9137685cbd1ULL, 0x761e787da0e200beULL));
    return pd;
}

/// TreeNode "QuoteSetReject", description "Quote set reject"
inline tbricks::TreeNodeIdentifier QuoteSetRejectIdentifier()
{
    // Identifier: "d4d11d3a-13f9-11e9-aff0-5a0a9689295a"
    // Name: "QuoteSet reject"
    // Description: "Quote set reject"
    // Tree type: "c0f04b04-c252-11e8-8a30-05194b27cb6f"
    tbricks::TreeNodeIdentifier pd(
        std::pair<uint64_t, uint64_t>(0xe911f9133a1dd1d4ULL, 0x5a2989960a5af0afULL));
    return pd;
}

}

}
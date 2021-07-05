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
#include "strategy/type/MMTFlag.h"
#include "strategy/type/String.h"

namespace tbricks {
namespace types {
class MMTFlags;
}

//****************************************************************************
// MMTFlags Class
//****************************************************************************

/**
 * MMTFlags object is the container for Market Model Typology flags of trade or public trade.
 *
 * For detail information see: https://www.fixtrading.org/mmt/
 *
 * Two version of MMTFlags are supported into C++ API.
 * + MMTFlags_2_2
 * + MMTFlags_3_04
 *
 * The flags can be created and filled via MMTFlags_2_2 or MMTFlags_3_04 classes.
 *
 * @code
 *
 * MMTFlags_3_04 flags_3_04;
 *
 * flags_3_04.SetNegotiatedTransactionIndicator(flag);
 *
 * MMTFlags flags = flags_3_04.GetFlags();
 *
 * @endcode
 */
class STRATEGY_EXPORT MMTFlags : public AnyType
{
public:
    /**
     * Default constructor.
     *
     * Creates an object with an empty flag fields.
     */
    MMTFlags();
    MMTFlags(const MMTFlags & other);
    MMTFlags & operator=(const MMTFlags & other);

    MMTFlags(MMTFlags &&) noexcept;
    MMTFlags & operator=(MMTFlags &&) noexcept;

    ~MMTFlags() noexcept override;

    /**
     * Clear object.
     *
     * Reset MMTFlags container.
     * After that the state of the object is not defined,
     * object won't contain any flag.
     */
    void Clear();

    /**
     * Check if object is empty.
     *
     * Returns "true" if object state is not defined.
     * This happens if object was created with a default constructor
     * (and had never been assigned to with a non-empty one),
     * if it was cleared, or if it was assigned an empty value.
     *
     * @return                          "true" if object is empty, "false"
     *                                  otherwise
     */
    bool Empty() const override;

    /**
     * Check if object has flag.
     *
     * @return                          "true" if flag contained, "false"
     *                                  otherwise
     */
    bool HasFlag(const MMTFlag::Value value) const;

    bool operator==(const MMTFlags & other) const;
    bool operator!=(const MMTFlags & other) const;
    bool operator<(const MMTFlags & value) const;
    bool operator>(const MMTFlags & value) const;
    bool operator<=(const MMTFlags & value) const;
    bool operator>=(const MMTFlags & value) const;

public:
    class MMTLevel;

    class MarketMechanismLevel;      //:MMTLevel
    class TradingModeLevel;          //:MMTLevel
    class TransactionTypeLevel;      //:MMTLevel
    class PublicationModeLevel;      //:MMTLevel
    class DuplicativeIndicatorLevel; //:MMTLevel

    /**
     * Get flags presented on Market Mechanism MMT level.
     *
     * @return                          MarketMechanismLevel class
     */
    MarketMechanismLevel GetMarketMechanismLevel() const;

    /**
     * Get flags presented on Trading Mode MMT level.
     *
     * @return                          TradingModeLevel class
     */
    TradingModeLevel GetTradingModeLevel() const;

    /**
     * Get flags presented on Transaction Type MMT level.
     *
     * @return                          TransactionTypeLevel class
     */
    TransactionTypeLevel GetTransactionTypeLevel() const;

    /**
     * Get flags presented on Publication Mode MMT level.
     *
     * @return                          PublicationModeLevel class
     */
    PublicationModeLevel GetPublicationModeLevel() const;

    /**
     * Get flags presented on Publication Mode MMT level.
     *
     * @return                          PublicationModeLevel class
     */
    DuplicativeIndicatorLevel GetDuplicativeIndicator() const;

    /**
     * Get raw MMT string.
     *
     * Return a raw MMT flags string for output to integration
     * apps, e.g. FIX.
     *
     */
    String GetPhysicalCode() const;

    std::ostream & Print(std::ostream & strm) const override;

    const types::MMTFlags & get_value() const;

    MMTFlags(const types::MMTFlags & other);
    MMTFlags & operator=(const types::MMTFlags & other);

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_MMT_FLAGS; }

public:
    size_t GetHash() const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    friend STRATEGY_EXPORT class Converter;

    std::unique_ptr<types::MMTFlags> m_impl;
};

//****************************************************************************
// MMT Levels structure
//****************************************************************************

class STRATEGY_EXPORT MMTFlags::MMTLevel
{
protected:
    MMTLevel();
    MMTLevel(const types::MMTFlags & flags);
    MMTLevel(const MMTLevel & level);
    MMTLevel & operator=(const MMTLevel & other);

    MMTLevel(MMTLevel &&) noexcept;
    MMTLevel & operator=(MMTLevel &&) noexcept;

    std::unique_ptr<types::MMTFlags> m_impl;

    ~MMTLevel() noexcept;
};

//--------------------------------------------------------------------------

class STRATEGY_EXPORT MMTFlags::MarketMechanismLevel : MMTFlags::MMTLevel
{
private:
    friend MMTFlags;
    MarketMechanismLevel(const types::MMTFlags & flags) : MMTLevel(flags) {}

public:
    MarketMechanismLevel();
    MarketMechanismLevel(const MarketMechanismLevel & other);
    MarketMechanismLevel & operator=(const MarketMechanismLevel & other);

    MarketMechanismLevel(MarketMechanismLevel && flags) noexcept;
    MarketMechanismLevel & operator=(MarketMechanismLevel && other) noexcept;

public:
    bool IsCentralLimitOrderBook() const;
    bool IsQuoteDrivenMarket() const;
    bool IsDarkOrderBook() const;
    bool IsOffBook() const;
    bool IsPeriodicAuction() const;
    bool IsRequestForQuotes() const;
    bool IsAnyOther_IncludingHybrid() const;

    bool operator==(const MarketMechanismLevel & other) const;
    bool operator!=(const MarketMechanismLevel & other) const;

public:
    std::vector<MMTFlag> GetFlags() const;
};

//--------------------------------------------------------------------------

class STRATEGY_EXPORT MMTFlags::TradingModeLevel : MMTFlags::MMTLevel
{
private:
    friend MMTFlags;
    TradingModeLevel(const types::MMTFlags & flags) : MMTLevel(flags) {}

public:
    TradingModeLevel();
    TradingModeLevel(const TradingModeLevel & other);
    TradingModeLevel & operator=(const TradingModeLevel & other);

    TradingModeLevel(TradingModeLevel && flags) noexcept;
    TradingModeLevel & operator=(TradingModeLevel && other) noexcept;

public:
    bool IsUndefinedAuction() const;
    bool IsScheduledOpeningAuction() const;
    bool IsScheduledClosingAuction() const;
    bool IsScheduledIntradayAuction() const;
    bool IsUnscheduledAuction() const;
    bool IsContinuousTrading() const;
    bool IsAtMarketCloseTrading() const;
    bool IsOutOfMainSessionTrading() const;
    bool IsTradeReportingOnExchange() const;
    bool IsTradeReportingOffExchange() const;
    bool IsTradeReportingSystematicInternalizer() const;

    bool operator==(const TradingModeLevel & other) const;
    bool operator!=(const TradingModeLevel & other) const;

public:
    std::vector<MMTFlag> GetFlags() const;
};

//--------------------------------------------------------------------------

class STRATEGY_EXPORT MMTFlags::TransactionTypeLevel : MMTFlags::MMTLevel
{
private:
    friend MMTFlags;
    TransactionTypeLevel(const types::MMTFlags & flags) : MMTLevel(flags) {}

public:
    TransactionTypeLevel();
    TransactionTypeLevel(const TransactionTypeLevel & other);
    TransactionTypeLevel & operator=(const TransactionTypeLevel & other);

    TransactionTypeLevel(TransactionTypeLevel && flags) noexcept;
    TransactionTypeLevel & operator=(TransactionTypeLevel && other) noexcept;

public:
    bool IsPlainVanillaTrade() const;
    bool IsDarkTrade() const;
    bool IsTechnicalTrade() const;
    bool IsGiveUpGiveInTrade() const;
    bool IsTradeWithConditions() const;
    bool IsNegotiatedTrade() const;
    bool IsNoNegotiatedTrade() const;
    bool IsCrossingTrade() const;
    bool IsNoCrossingTrade() const;
    bool IsTradeCancellation() const;
    bool IsTradeAmendment() const;
    bool IsNewTrade() const;
    bool IsBenchmarkTrade() const;
    bool IsNoBenchmarkTrade() const;
    bool IsExCumDividendTrade() const;
    bool IsNoExCumDividendTrade() const;
    bool IsOffBookUnspecifiedOrDoesNotApply() const;
    bool IsOffBookNonAutomated() const;
    bool IsOffBookAutomated() const;
    bool IsAlgorithmicTrade() const;
    bool IsExchangeForPhysicalsTrade() const;
    bool IsNegotiatedTradeInIlliquidFinancialInstruments() const;
    bool IsNegotiatedTradeInLiquidFinancialInstruments() const;
    bool IsNegotiatedTradeSubjectToConditionsOtherThanTheCurrentMarketPrice() const;
    bool IsNoAlgorithmicTrade() const;
    bool IsNoneApplyAStandardTradeForTheMarketMechanismAndTradingMode() const;
    bool IsNonPriceFormingTrade() const;
    bool IsNoSpecialDividendTrade() const;
    bool IsPackageTrade() const;
    bool IsPreTradeTransparencyWaiverForAboveStandardMarketSizeOnAnSI() const;
    bool IsPreTradeTransparencyWaiverForIlliquidInstrumentOnAnSI() const;
    bool IsPreTradeTransparencyWaiversOfILQDAndSIZE() const;
    bool IsPriceIsCurrentlyNotAvailableButPending() const;
    bool IsReferencePriceTrade() const;
    bool IsSpecialDividendTrade() const;
    bool IsTradeNotContributingToThePriceDiscoveryProcess() const;
    bool IsTradeThatHasReceivedPriceImprovement() const;
    bool IsUnspecifiedOrDoesNotApply() const;

    bool operator==(const TransactionTypeLevel & other) const;
    bool operator!=(const TransactionTypeLevel & other) const;

public:
    std::vector<MMTFlag> GetFlags() const;
};

//--------------------------------------------------------------------------

class STRATEGY_EXPORT MMTFlags::PublicationModeLevel : MMTFlags::MMTLevel
{
private:
    friend MMTFlags;
    PublicationModeLevel(const types::MMTFlags & flags) : MMTLevel(flags) {}

public:
    PublicationModeLevel();
    PublicationModeLevel(const PublicationModeLevel & other);
    PublicationModeLevel & operator=(const PublicationModeLevel & other);

    PublicationModeLevel(PublicationModeLevel && flags) noexcept;
    PublicationModeLevel & operator=(PublicationModeLevel && other) noexcept;

public:
    bool IsImmediatePublication() const;
    bool IsNonImmediatePublication() const;
    bool IsDailyAggregatedTrade() const;
    bool IsFourWeeksAggregationTrade() const;
    bool IsFullDetailsInAggregatedFormOfEarlierVOLW() const;
    bool IsFullDetailsOfEarlierDATF() const;
    bool IsFullDetailsOfEarlierFWAF() const;
    bool IsFullDetailsOfEarlierLMTF() const;
    bool IsFullDetailsOfEarlierVOLO() const;
    bool IsIndefiniteAggregationTrade() const;
    bool IsLimitedDetailsTrade() const;
    bool IsNonImmediatePublicationDeferralForIlliquidInstrument() const;
    bool IsNonImmediatePublicationDeferralForLargeInScale() const;
    bool IsNonImmediatePublicationDeferralForSizeSpecific() const;
    bool IsNonImmediatePublicationDeferralsOfILQDAndSIZE() const;
    bool IsNonImmediatePublicationDeferralsOfILQDAndLRGS() const;
    bool IsNotApplicableNoRelevantDeferralOrEnrichmentType() const;
    bool IsVolumeOmissionTrade() const;
    bool IsVolumeOmissionTradeEligibleForSubsequentEnrichmentInAggregatedForm() const;

    bool operator==(const PublicationModeLevel & other) const;
    bool operator!=(const PublicationModeLevel & other) const;

public:
    std::vector<MMTFlag> GetFlags() const;
};

//--------------------------------------------------------------------------

class STRATEGY_EXPORT MMTFlags::DuplicativeIndicatorLevel : MMTFlags::MMTLevel
{
private:
    friend MMTFlags;
    DuplicativeIndicatorLevel(const types::MMTFlags & flags) : MMTLevel(flags) {}

public:
    DuplicativeIndicatorLevel();
    DuplicativeIndicatorLevel(const DuplicativeIndicatorLevel & other);
    DuplicativeIndicatorLevel & operator=(const DuplicativeIndicatorLevel & other);

    DuplicativeIndicatorLevel(DuplicativeIndicatorLevel && flags) noexcept;
    DuplicativeIndicatorLevel & operator=(DuplicativeIndicatorLevel && other) noexcept;

public:
    bool IsDuplicativeTradeReport() const;
    bool IsUniqueTradeReport() const;

    bool operator==(const DuplicativeIndicatorLevel & other) const;
    bool operator!=(const DuplicativeIndicatorLevel & other) const;

public:
    std::vector<MMTFlag> GetFlags() const;
};

} // \namespace tbricks

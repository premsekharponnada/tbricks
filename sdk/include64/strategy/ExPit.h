#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExPit.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Strategy.h"
#include "strategy/RequestForTrade.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/ExPitIdentifier.h"
#include "strategy/type/Integer.h"
#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/type/PostingActionType.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/String.h"
#include "strategy/type/TransactionState.h"
#include "strategy/type/TreeNodeIdentifier.h"
#include "strategy/type/UserIdentifier.h"

#include "strategy_generated/ExPitBase.h"
#include "strategy_generated/ExPitUpdateBase.h"
#include "strategy_generated/ExPitOptionsBase.h"
#include "strategy_generated/ExPitPartyBase.h"
#include "strategy_generated/ExPitDealBase.h"
#include "strategy_generated/ExPitDeclineOptionsBase.h"

namespace tbricks {

class ExPitDeal;
class ExPitParty;
class ExPitManager;

namespace test {
class ExPitOptions;
}

namespace pe {
class ExpitCache;
}

/**
 * ExPit
 */
class STRATEGY_EXPORT ExPit : public ExPitBase
{
public:
    class Side;
    class Options;
    class AcceptOptions;
    class DeclineOptions;
    class Update;
    class Stream;

public:
    /**
     * Default constructor, creates an empty object.
     */
    ExPit() = default;

    ExPit(const ExPitIdentifier & expit_id);
    ExPit(const ExPit::Update & update);

private:
    friend class Trading;
    ExPit(const protocol::Expit & expit) : ExPitBase(expit) {}

public:
    enum Type
    {
        EMPTY_TYPE = -1,
        INTERBANK = 0,        /**< Bilateral interbank trade report */
        TRADE_REPORT = 1,     /**< Unilateral trade report */
        BLOCK = 2,            /**< Very large trade report */
        CROSS = 3,            /**< %Trade report when the instigator is both bower and seller */
        ACCEPT = 4,           /**< Accept a direct request for trade */
        GUARANTEED_CROSS = 5, /**< Guaranteed cross */
        PUBLICATION = 6,      /**< Post-trade publication used to report off-exchange trades to e.g. APA. Both sides should
                                 be filled by reporter. */
        DECLINE = 7           /**< Decline request for trade */
    };

    enum TradingCapacity
    {
        EMPTY_TRADING_CAPACITY = -1,
        UNDEFINED = 0, /**< Undefined */
        INITIATOR = 1, /**< Instigator of an operation */
        REACTOR = 2    /**< Responder to an operation */
    };

    enum Regulation
    {
        EMPTY_REGULATION = -1,
        UNDEFINED_REGULATION = 0,           /**< Expit done under no particular regulation */
        OFF_PRICE = 1,                      /**< Expit is done outside spread */
        EXCHANGE_GRANTED = 2,               /**< Expit is done under special requirements with price deviating significant or other irregularities */
        OFF_HOURS = 3,                      /**< Expit is done outside normal trading hours or during odd trading phases. */
        LARGE = 4,                          /**< Unusually large expit, subject to exchange-specific regulation. */
        NON_STANDARD_SETTLEMENT = 5,        /**< Expit deviates from the standard settlement and delivery period. */
        DERIVATIVE_RELATED_TRANSACTION = 6, /**< Exercise or expiration of options, forwards and futures contracts that imply an exchange of
                                             * Instruments or a Trade < that relates to a derivatives Trade and that forms an unconditional part of a
                                             * combination together with < a derivative Trade. */
        PORTFOLIO_TRADE = 7                 /**< A transaction in more then one Instrument where those Instruments are grouped and
                                               traded as a single lot. */
    };

public:
    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "UserIdentifier GetCreator() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetCreator(UserIdentifier & creator) const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "UserIdentifier GetCreator() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetCreator(User & creator) const;
    using ExPitBase::GetCreator;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Boolean GetDeleted() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetDeleted(Boolean & deleted) const;
    using ExPitBase::GetDeleted;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetExchangeClientIdentifier() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetExchangeClientIdentifier(String & exchange_client_identifier) const;
    using ExPitBase::GetExchangeClientIdentifier;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetPackageIdentifier() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetPackageIdentifier(String & package_identifier) const;
    using ExPitBase::GetPackageIdentifier;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "TransactionState GetTransactionState() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetTransactionState(TransactionState & transaction_state) const;
    using ExPitBase::GetTransactionState;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "ExPit::Type GetType() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetType(ExPit::Type & type) const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "DateTime GetHostCreatedDatetime() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetHostCreatedDatetime(DateTime & host_created_datetime) const;
    using ExPitBase::GetHostCreatedDatetime;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "DateTime GetHostModifiedDatetime() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetHostModifiedDatetime(DateTime & host_modified_datetime) const;
    using ExPitBase::GetHostModifiedDatetime;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetMatchingCode() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetMatchingCode(String & matching_code) const;
    using ExPitBase::GetMatchingCode;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "UserIdentifier GetOwner() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetOwner(UserIdentifier & owner) const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "UserIdentifier GetOwner() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetOwner(User & owner) const;
    using ExPitBase::GetOwner;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "StrategyIdentifier GetParentStrategyIdentifier() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetParentStrategyIdentifier(StrategyIdentifier & parent_strategy_identifier) const;
    using ExPitBase::GetParentStrategyIdentifier;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "StrategyIdentifier GetRootStrategyIdentifier() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetRootStrategyIdentifier(StrategyIdentifier & root_strategy_identifier) const;
    using ExPitBase::GetRootStrategyIdentifier;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetStatusText() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetStatusText(String & status_text) const;
    using ExPitBase::GetStatusText;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "ExPit::TradingCapacity GetTradingCapacity() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetTradingCapacity(ExPit::TradingCapacity & trading_capacity) const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "TreeNodeIdentifier GetHandler() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetHandler(TreeNodeIdentifier & handler) const;
    using ExPitBase::GetHandler;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Integer GetAlgoLabel() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetAlgoLabel(Integer & algo_label) const;
    using ExPitBase::GetAlgoLabel;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetExchangeReference() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetExchangeReference(std::string & value) const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetExchangeReference() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetExchangeReference(String & value) const;
    using ExPitBase::GetExchangeReference;

    bool HasPrice() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Price GetPrice() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetPrice(Price & price) const;
    Price GetPrice() const;

    bool HasInstrumentVenueIdentification() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "InstrumentVenueIdentification GetInstrumentVenueIdentification() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetInstrumentVenueIdentification(InstrumentVenueIdentification & ivid) const;
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;

    bool HasVolume() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Volume GetVolume() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetVolume(Volume & volume) const;
    Volume GetVolume() const;

    bool HasFilledVolume() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Volume GetFilledVolume() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetFilledVolume(Volume & volume) const;
    Volume GetFilledVolume() const;

    bool HasAveragePaid() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Double GetAveragePaid() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetAveragePaid(Double & averagePaid) const;
    Double GetAveragePaid() const;

    bool HasRegulation() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "ExPit::Regulation GetRegulation() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetRegulation(ExPit::Regulation & regulation) const;
    ExPit::Regulation GetRegulation() const;

    bool HasMMTFlags() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "MMTFlags GetMMTFlags() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetMMTFlags(MMTFlags & value) const;
    MMTFlags GetMMTFlags() const;

    bool HasAgreementDatetime() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "DateTime GetAgreementDatetime() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetAgreementDatetime(DateTime & value) const;
    DateTime GetAgreementDatetime() const;

    bool HasSettlementDate() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "DateTime GetSettlementDate() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetSettlementDate(DateTime & value) const;
    DateTime GetSettlementDate() const;

    /**
     * @deprecated Deprecated in 2.14.6, will be removed in the next release.
     *             Use "bool HasDeals() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasSides() const;

    /**
     * @deprecated Deprecated in 2.14.6, will be removed in the next release.
     *             Use "std::vector<ExPitDeal> GetDeals() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetSides(std::vector<ExPit::Side> & sides) const;

    /**
     * Get type.
     *
     * @return                      expit type
     */
    ExPit::Type GetType() const;

    /**
     * Check if field is set.
     *
     * @return                      True if field is set, false otherwise.
     */
    bool HasType() const;

    /**
     * Get trading capacity.
     *
     * @return                      tradinc capacity
     */
    ExPit::TradingCapacity GetTradingCapacity() const;

    /**
     * Check if field is set.
     *
     * @return                      True if field is set, false otherwise.
     */
    bool HasTradingCapacity() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeals() const;

    /**
     * Get expit deals.
     *
     * @return                          expit deals
     */
    std::vector<ExPitDeal> GetDeals() const;

    /**
     * Merge ExPit update.
     *
     * @param update                ExPit update
     */
    void Merge(const ExPit::Update & update);
};

/**
 * ExPit::Side
 * @deprecated Deprecated in 2.14.6, will be removed in the next release.
 *             Use ExPitDeal instead
 */
class STRATEGY_EXPORT[[deprecated(DEPRECATE_LINK)]] ExPit::Side : public ExPitPartyBase
{
public:
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"
#endif
    enum PostingAction
    {
        UNDEFINED = 0, /**< Undefined */
        OPEN = 1,      /**< Opening a position */
        CLOSE = 2      /**< Closing a position */
    };
#ifdef __clang__
#pragma clang diagnostic pop
#endif

public:
    Side() = default;
    Side(const protocol::ExpitParty & party) : ExPitPartyBase(party) {}

    PortfolioIdentifier GetPortfolio() const;
    void SetPortfolio(const PortfolioIdentifier & value);

    void SetPostingAction(PostingAction value);
    PostingAction GetPostingAction() const;

    tbricks::Side GetSide() const;
    void SetSide(const tbricks::Side & value);
};

/**
 * ExPit::Update
 */
class STRATEGY_EXPORT ExPit::Update : public ExPitUpdateBase
{
public:
    Update(std::shared_ptr<protocol::Expit> expit) : ExPitUpdateBase(std::move(expit)) {}
    Update(const protocol::Expit & expit) : ExPitUpdateBase(expit) {}

public:
    /**
     * Get type.
     *
     * @return                      expit type
     */
    ExPit::Type GetType() const;

    /**
     * Check if field is set.
     *
     * @return                      True if field is set, false otherwise.
     */
    bool HasType() const;

    /**
     * Get trading capacity.
     *
     * @return                      tradinc capacity
     */
    ExPit::TradingCapacity GetTradingCapacity() const;

    /**
     * Check if field is set.
     *
     * @return                      True if field is set, false otherwise.
     */
    bool HasTradingCapacity() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeals() const;

    /**
     * Get expit deals.
     *
     * @return                          expit deals
     */
    std::vector<ExPitDeal> GetDeals() const;

public:
    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "UserIdentifier GetCreator() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetCreator(UserIdentifier & creator) const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "UserIdentifier GetCreator() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetCreator(User & creator) const;
    using ExPitUpdateBase::GetCreator;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Boolean GetDeleted() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetDeleted(Boolean & deleted) const;
    using ExPitUpdateBase::GetDeleted;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetExchangeClientIdentifier() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetExchangeClientIdentifier(String & exchange_client_identifier) const;
    using ExPitUpdateBase::GetExchangeClientIdentifier;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetPackageIdentifier() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetPackageIdentifier(String & package_identifier) const;
    using ExPitUpdateBase::GetPackageIdentifier;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "TransactionState GetTransactionState() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetTransactionState(TransactionState & transaction_state) const;
    using ExPitUpdateBase::GetTransactionState;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "ExPit::Type GetType() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetType(ExPit::Type & type) const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "DateTime GetHostCreatedDatetime() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetHostCreatedDatetime(DateTime & host_created_datetime) const;
    using ExPitUpdateBase::GetHostCreatedDatetime;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "DateTime GetHostModifiedDatetime() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetHostModifiedDatetime(DateTime & host_modified_datetime) const;
    using ExPitUpdateBase::GetHostModifiedDatetime;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetMatchingCode() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetMatchingCode(String & matching_code) const;
    using ExPitUpdateBase::GetMatchingCode;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "UserIdentifier GetOwner() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetOwner(UserIdentifier & owner) const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "UserIdentifier GetOwner() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetOwner(User & owner) const;
    using ExPitUpdateBase::GetOwner;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "StrategyIdentifier GetParentStrategyIdentifier() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetParentStrategyIdentifier(StrategyIdentifier & parent_strategy_identifier) const;
    using ExPitUpdateBase::GetParentStrategyIdentifier;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "StrategyIdentifier GetRootStrategyIdentifier() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetRootStrategyIdentifier(StrategyIdentifier & root_strategy_identifier) const;
    using ExPitUpdateBase::GetRootStrategyIdentifier;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetStatusText() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetStatusText(String & status_text) const;
    using ExPitUpdateBase::GetStatusText;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "ExPit::TradingCapacity GetTradingCapacity() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetTradingCapacity(ExPit::TradingCapacity & trading_capacity) const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "TreeNodeIdentifier GetHandler() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetHandler(TreeNodeIdentifier & handler) const;
    using ExPitUpdateBase::GetHandler;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Integer GetAlgoLabel() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetAlgoLabel(Integer & algo_label) const;
    using ExPitUpdateBase::GetAlgoLabel;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetExchangeReference() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetExchangeReference(std::string & value) const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "String GetExchangeReference() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetExchangeReference(String & value) const;
    using ExPitUpdateBase::GetExchangeReference;

    bool HasPrice() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Price GetPrice() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetPrice(Price & price) const;
    Price GetPrice() const;

    bool HasInstrumentVenueIdentification() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "InstrumentVenueIdentification GetInstrumentVenueIdentification() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetInstrumentVenueIdentification(InstrumentVenueIdentification & ivid) const;
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;

    bool HasVolume() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Volume GetVolume() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetVolume(Volume & volume) const;
    Volume GetVolume() const;

    bool HasFilledVolume() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Volume GetFilledVolume() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetFilledVolume(Volume & volume) const;
    Volume GetFilledVolume() const;

    bool HasAveragePaid() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "Double GetAveragePaid() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetAveragePaid(Double & averagePaid) const;
    Double GetAveragePaid() const;

    bool HasRegulation() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "ExPit::Regulation GetRegulation() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetRegulation(ExPit::Regulation & regulation) const;
    ExPit::Regulation GetRegulation() const;

    bool HasMMTFlags() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "MMTFlags GetMMTFlags() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetMMTFlags(MMTFlags & value) const;
    MMTFlags GetMMTFlags() const;

    bool HasAgreementDatetime() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "DateTime GetAgreementDatetime() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetAgreementDatetime(DateTime & value) const;
    DateTime GetAgreementDatetime() const;

    bool HasSettlementDate() const;

    /**
     * @deprecated Deprecated in 2.13.0, will be removed in the next release.
     *             Use "DateTime GetSettlementDate() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetSettlementDate(DateTime & value) const;
    DateTime GetSettlementDate() const;

    /**
     * @deprecated Deprecated in 2.14.6, will be removed in the next release.
     *             Use "bool HasDeals() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasSides() const;

    /**
     * @deprecated Deprecated in 2.14.6, will be removed in the next release.
     *             Use "std::vector<ExPitDeal> GetDeals() const" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetSides(std::vector<ExPit::Side> & sides) const;

private:
    Update() = delete;
};

/**
 * ExPitParty
 */
class STRATEGY_EXPORT ExPitParty : public ExPitPartyBase
{
public:
    ExPitParty() = default;
    ExPitParty(const protocol::ExpitParty & party) : ExPitPartyBase(party) {}

    bool HasPortfolio() const;
    PortfolioIdentifier GetPortfolio() const;
    void SetPortfolio(const PortfolioIdentifier & value);

    bool HasPostingAction() const;
    void SetPostingAction(const PostingActionType & value);
    PostingActionType GetPostingAction() const;
};

/**
 * ExPitDeal
 */
class STRATEGY_EXPORT ExPitDeal : public ExPitDealBase
{
public:
    ExPitDeal() = default;
    ExPitDeal(const protocol::ExpitDeal & deal) : ExPitDealBase(deal) {}

public:
    bool HasRegulation() const;
    ExPit::Regulation GetRegulation() const;
    void SetRegulation(ExPit::Regulation value);

    bool HasInstrumentVenueIdentification() const;
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & value);
};

/**
 * ExPit::Options
 */
class STRATEGY_EXPORT ExPit::Options : public ExPitOptionsBase
{
public:
    void SetType(ExPit::Type type);
    ExPit::Type GetType() const;

    void SetTradingCapacity(ExPit::TradingCapacity capacity);
    ExPit::TradingCapacity GetTradingCapacity() const;

    /**
     * @deprecated Deprecated in 2.14.6, will be removed in the next release.
     *             Use "void SetDeals(const std::vector<ExPitDeal> & value)" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] void AddSide(const ExPit::Side & side);

    /**
     * @deprecated Deprecated in 2.14.6, will be removed in the next release.
     *             Use "void SetDeals(const std::vector<ExPitDeal> & value)" instead.
     */
    [[deprecated(DEPRECATE_LINK)]] void SetSides(const std::vector<ExPit::Side> & sides);

    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;

    void SetPrice(const Price & price);

    Price GetPrice() const;

    void SetVolume(const Volume & volume);

    Volume GetVolume() const;

    void SetRegulation(ExPit::Regulation regulation);

    ExPit::Regulation GetRegulation() const;

    DateTime GetAgreementDatetime() const;

    void SetAgreementDatetime(const DateTime & value);

    DateTime GetSettlementDate() const;
    void SetSettlementDate(const DateTime & value);

    void SetMMTFlags(const MMTFlags & value);

    MMTFlags GetMMTFlags() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeals() const;

    /**
     * Get expit deals.
     *
     * @return                          expit deals
     */
    std::vector<ExPitDeal> GetDeals() const;

    /**
     * %Set expit deals.
     * If the value is empty field will delete from options.
     *
     * @param value                     expit deals
     */
    void SetDeals(const std::vector<ExPitDeal> & value);

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend protocol::Expit options_to_request2(const ExPit::Options & options);
    friend STRATEGY_EXPORT class tbricks::ExPitManager;

private:
    ExPitDeal m_deal;
};

/**
 * ExPitAcceptDeal
 */
class STRATEGY_EXPORT ExPitAcceptDeal : public Printable
{
public:
    ExPitAcceptDeal() = default;

public:
    bool HasPortfolio() const;
    PortfolioIdentifier GetPortfolio() const;
    void SetPortfolio(const PortfolioIdentifier & value);

    bool HasOrderCapacity() const;
    OrderCapacity GetOrderCapacity() const;
    void SetOrderCapacity(const OrderCapacity & value);

    bool HasExtraData() const;
    ExtraData GetExtraData() const;
    void SetExtraData(const ExtraData & value);

    bool HasPostingAction() const;
    PostingActionType GetPostingAction() const;
    void SetPostingAction(PostingActionType value);

    bool HasClient() const;
    TreeNodeIdentifier GetClient() const;
    void SetClient(const TreeNodeIdentifier & value);

    bool HasActiveVolume() const;
    Volume GetActiveVolume() const;
    void SetActiveVolume(const Volume & value);

    bool HasInstrumentVenueIdentification() const;
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;

    bool Empty() const;
    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    ExPitAcceptDeal(protocol::ExpitDeal deal);

private:
    friend class pe::ExpitCache;
    friend class ExPitManager;
    friend class ExPit::AcceptOptions;

private:
    ExPitParty m_party;
    ExPitDeal m_deal;
};

/**
 * ExPit::AcceptOptions
 */
class STRATEGY_EXPORT ExPit::AcceptOptions : public Printable
{
public:
    /**
     * Creates one leg options.
     * Instrument and other field will be filled from rft before sending.
     * @deprecated Deprecated in 2.13.0. Use AcceptOptions(const RequestForTrade & rft)
     */
    [[deprecated(DEPRECATE_LINK)]] AcceptOptions();

    /**
     * Creates accept options for specified rft.
     * Deals are filled in ctor.
     * Values in deals may be overridden and will not change before sending.
     */
    AcceptOptions(const RequestForTrade & rft);

    ~AcceptOptions();

public:
    RequestForTradeIdentifier GetRequestForTradeIdentifier() const;

    /**
     * %Set expit identifier if rft was not specified before.
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] void SetExPitIdentifier(const ExPitIdentifier & value);

    /**
     * Get expit identifier
     *
     * @return         expit identifier
     */
    ExPitIdentifier GetExPitIdentifier() const;

    /**
     * %Set portfolio into all accept deals
     */
    void SetPortfolio(const PortfolioIdentifier & portfolio_id);

    /**
     * Get portfolio of the first accept deal
     * @deprecated Deprecated in 2.13.0. Use AcceptDeal::GetPortfolio()
     */
    [[deprecated(DEPRECATE_LINK)]] PortfolioIdentifier GetPortfolio() const;

    /**
     * %Set order capacity into all accept deals
     */
    void SetOrderCapacity(const OrderCapacity & order_capacity);

    /**
     * Get order capacity of the first accept deal
     * @deprecated Deprecated in 2.13.0. Use AcceptDeal::GetOrderCapacity()
     */
    [[deprecated(DEPRECATE_LINK)]] OrderCapacity GetOrderCapacity() const;

    /**
     * %Set extra data into all accept deals
     */
    void SetExtraData(const ExtraData & extra_data);

    /**
     * Get extra data of the first accept deal
     * @deprecated Deprecated in 2.13.0. Use AcceptDeal::GetExtraData()
     */
    [[deprecated(DEPRECATE_LINK)]] ExtraData GetExtraData() const;

    /**
     * %Set posting action into all accept deals
     * @deprecated Deprecated in 2.14.6. Use SetPostingAction(const PostingActionType & posting_action)
     */
    [[deprecated(DEPRECATE_LINK)]] void SetPostingAction(ExPit::Side::PostingAction posting_action);

    /**
     * Get posting action of the first accept deal
     * @deprecated Deprecated in 2.13.0. Use AcceptDeal::GetPostingAction()
     */
    [[deprecated(DEPRECATE_LINK)]] ExPit::Side::PostingAction GetPostingAction() const;

    /**
     * %Set posting action into all accept deals
     */
    void SetPostingAction(const PostingActionType & posting_action);

    /**
     * %Set client into all accept deals
     */
    void SetClient(const TreeNodeIdentifier & client);

    /**
     * Get client of the first accept deal
     * @deprecated Deprecated in 2.13.0. Use AcceptDeal::GetClient()
     */
    [[deprecated(DEPRECATE_LINK)]] TreeNodeIdentifier GetClient() const;

    /**
     * %Set active volume into accept deals
     */
    void SetVolume(const Volume & volume);

    /**
     * Get active volume of the first accept deal
     * @deprecated Deprecated in 2.13.0. Use AcceptDeal::GetVolume()
     */
    [[deprecated(DEPRECATE_LINK)]] Volume GetVolume() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandler() const;

    /**
     * Get handler.
     *
     * @return                          handler
     */
    TreeNodeIdentifier GetHandler() const;

    /**
     * %Set handler.
     *
     * If the passed value is empty, the field in the request
     * will be deleted.
     *
     * @param value                     handler
     */
    void SetHandler(const TreeNodeIdentifier & value);

    /**
     * Get expit deals
     *
     * @return                          expit deals
     */
    std::vector<ExPitAcceptDeal> & GetDeals();

    /**
     * Get exchange client directed quote reference.
     *
     * @return                          exchange client directed quote reference
     */
    String GetExchangeClientReference() const;

    /**
     * Check if field is set.
     *
     * Indicates whether an order should skip the check against soft limits
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBypassSoftLimits() const;

    /**
     * Get bypass soft limits.
     *
     * Indicates whether an order should skip the check against soft limits
     *
     * @return                          bypass soft limits
     */
    Boolean GetBypassSoftLimits() const;

    /**
     * %Set bypass soft limits.
     *
     * Indicates whether an order should skip the check against soft limits
     *
     * @param value                     bypass soft limits
     */
    void SetBypassSoftLimits(const Boolean & value);

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::unique_ptr<protocol::Expit> & get_impl_wr() const;

private:
    friend class ExPitManager;

private:
    std::unique_ptr<protocol::Expit> m_impl;
    std::vector<ExPitAcceptDeal> m_deals;
};

/**
 * ExPit::DeclineOptions
 */
class STRATEGY_EXPORT ExPit::DeclineOptions : public ExPitDeclineOptionsBase
{
public:
    DeclineOptions(const RequestForTrade & rft);
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Order Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Strategy.h"

#include "strategy/type/AnyType.h"
#include "strategy/type/OrderIdentifier.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/TransactionState.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/InstrumentTradingInformation.h"

#include "strategy/type/OrderCapacity.h"
#include "strategy/type/ParticipationPolicy.h"

// \namespace tbricks
namespace tbricks {

namespace protocol {
class Order;
class OrderDeleteRequest;
}

namespace test {

/**
 */
class STRATEGY_EXPORT OrderOptions : public Printable
{
public:
    typedef protocol::Order order_t;

public:
    OrderOptions();
    OrderOptions(order_t * order);
    OrderOptions(const OrderOptions & order);
    virtual ~OrderOptions();

    OrderOptions & operator=(const OrderOptions & order);

public:
    bool HasActiveVolume() const;
    Volume GetActiveVolume() const;
    void SetActiveVolume(const Volume & active_volume);

    bool HasAlgoLabel() const;
    Integer GetAlgoLabel() const;
    void SetAlgoLabel(const Integer & algo_label);

    bool HasAveragePaid() const;
    Double GetAveragePaid() const;
    void SetAveragePaid(const Double & average_paid);

    bool HasAveragePaidVolume() const;
    Volume GetAveragePaidVolume() const;
    void SetAveragePaidVolume(const Volume & average_paid_volume);

    bool HasBypassSoftLimits() const;
    Boolean GetBypassSoftLimits() const;
    void SetBypassSoftLimits(const Boolean & bypass_soft_limits);

    bool HasClient() const;
    TreeNodeIdentifier GetClient() const;
    void SetClient(const TreeNodeIdentifier & client) const;

    bool HasComment() const;
    String GetComment() const;
    void SetComment(const String & comment);

    bool HasCreator() const;
    UserIdentifier GetCreator() const;
    void SetCreator(const UserIdentifier & creator);

    bool HasCurrency() const;
    Currency GetCurrency() const;
    void SetCurrency(const Currency & currency);

    bool HasDeleted() const;
    Boolean GetDeleted() const;
    void SetDeleted(const Boolean & deleted);

    bool HasDealtCurrency() const;
    Currency GetDealtCurrency() const;
    void SetDealtCurrency(const Currency & dealt_currency);

    bool HasDisclosedVolume() const;
    Volume GetDisclosedVolume() const;
    void SetDisclosedVolume(const Volume & disclosed_volume);

    bool HasExchangeClientOrderIdentifier() const;
    String GetExchangeClientOrderIdentifier() const;
    void SetExchangeClientOrderIdentifier(const String & exchange_client_order_reference);

    bool HasExchangeCreatedDatetime() const;
    DateTime GetExchangeCreatedDatetime() const;
    void SetExchangeCreatedDatetime(const DateTime & exchange_created_datetime);

    bool HasExchangeModifiedDatetime() const;
    DateTime GetExchangeModifiedDatetime() const;
    void SetExchangeModifiedDatetime(const DateTime & exchange_modified_datetime);

    bool HasExchangeOrderIdentifier() const;
    String GetExchangeOrderIdentifier() const;
    void SetExchangeOrderIdentifier(const String & exchange_order_reference);

    bool HasExtraData() const;
    ExtraData GetExtraData() const;
    void SetExtraData(const ExtraData & extra_data);

    bool HasFilledVolume() const;
    Volume GetFilledVolume() const;
    void SetFilledVolume(const Volume & filled_volume);

    bool HasFlowRoutingRuleIdentifier() const;
    TreeNodeIdentifier GetFlowRoutingRuleIdentifier() const;
    void SetFlowRoutingRuleIdentifier(const TreeNodeIdentifier & id);

    bool HasHandler() const;
    TreeNodeIdentifier GetHandler() const;
    void SetHandler(const TreeNodeIdentifier & handler);

    bool HasHostCreatedDatetime() const;
    DateTime GetHostCreatedDatetime() const;
    void SetHostCreatedDatetime(const DateTime & host_created_datetime);

    bool HasHostModifiedDatetime() const;
    DateTime GetHostModifiedDatetime() const;
    void SetHostModifiedDatetime(const DateTime & host_modified_datetime);

    bool HasInstrumentVenueIdentification() const;
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    bool HasInternallyFilledVolume() const;
    Volume GetInternallyFilledVolume() const;
    void SetInternallyFilledVolume(const Volume & internally_filled_volume);

    bool HasMinimumAcceptableFillVolume() const;
    Volume GetMinimumAcceptableFillVolume() const;
    void SetMinimumAcceptableFillVolume(const Volume & minimum_acceptable_fill_volume);

    bool HasMinimumAcceptableVolume() const;
    Volume GetMinimumAcceptableVolume() const;
    void SetMinimumAcceptableVolume(const Volume & minimum_acceptable_volume);

    bool HasOperator() const;
    UserIdentifier GetOperator() const;
    void SetOperator(const UserIdentifier & user);

    bool HasOrderCapacity() const;
    OrderCapacity GetOrderCapacity() const;
    void SetOrderCapacity(const OrderCapacity & capacity);

    bool HasOrderIdentifier() const;
    OrderIdentifier GetOrderIdentifier() const;
    void SetOrderIdentifier(const OrderIdentifier & id);

    bool HasOrderTransactionState() const;
    TransactionState GetOrderTransactionState() const;
    void SetOrderTransactionState(const TransactionState & order_transaction_state);

    bool HasOrderValueFactor() const;
    Double GetOrderValueFactor() const;
    void SetOrderValueFactor(const Double & factor);

    bool HasOwner() const;
    UserIdentifier GetOwner() const;
    void SetOwner(const UserIdentifier & owner);

    bool HasParentStrategyIdentifier() const;
    StrategyIdentifier GetParentStrategyIdentifier() const;
    void SetParentStrategyIdentifier(const StrategyIdentifier & parent_strategy_identifier);

    bool HasPartialFillNotAllowed() const;
    Boolean GetPartialFillNotAllowed() const;
    void SetPartialFillNotAllowed(const Boolean & partial_fill_not_allowed);

    bool HasParticipationPolicy() const;
    ParticipationPolicy GetParticipationPolicy() const;
    void SetParticipationPolicy(const ParticipationPolicy & participation_policy);

    bool HasPortfolioIdentifier() const;
    PortfolioIdentifier GetPortfolioIdentifier() const;
    void SetPortfolioIdentifier(const PortfolioIdentifier & portfolio_identifier);

    bool HasPostingAction() const;
    PostingActionType GetPostingAction() const;
    void SetPostingAction(const PostingActionType & posting_action);

    bool HasPrice() const;
    Price GetPrice() const;
    void SetPrice(const Price & price);

    bool HasPricePolicy() const;
    PricePolicy GetPricePolicy() const;
    void SetPricePolicy(const PricePolicy & policy);

    bool HasRequestIdentifier() const;
    Identifier GetRequestIdentifier() const;
    void SetRequestIdentifier(const Identifier & request_identifier);

    bool HasRetainOnDisconnect() const;
    Boolean GetRetainOnDisconnect() const;
    void SetRetainOnDisconnect(const Boolean & retain_on_disconnect);

    bool HasRootStrategyIdentifier() const;
    StrategyIdentifier GetRootStrategyIdentifier() const;
    void SetRootStrategyIdentifier(const StrategyIdentifier & root_strategy_identifier);

    bool HasSide() const;
    Side GetSide() const;
    void SetSide(const Side & side);

    bool HasExecutionPolicy() const;
    ExecutionPolicy GetExecutionPolicy() const;
    void SetExecutionPolicy(const ExecutionPolicy & value);

    bool HasStatusText() const;
    String GetStatusText() const;
    void SetStatusText(const String & status_text);

    bool HasStopPrice() const;
    Price GetStopPrice() const;
    void SetStopPrice(const Price & stop_price);

    bool HasStrategyDefinitionPath() const;
    std::vector<StrategyIdentifier> GetStrategyDefinitionPath() const;
    void SetStrategyDefinitionPath(const std::vector<StrategyIdentifier> & path);

    bool HasStrategyIdentifierPath() const;
    std::vector<StrategyIdentifier> GetStrategyIdentifierPath() const;
    void SetStrategyIdentifierPath(const std::vector<StrategyIdentifier> & path);

    bool HasExtraParameters() const;
    StrategyParameters GetExtraParameters() const;
    void SetExtraParameters(const StrategyParameters & strategy_parameters);

    bool HasTargetPrice() const;
    Price GetTargetPrice() const;
    void SetTargetPrice(const Price & target_price);

    bool HasTotalVolume() const;
    Volume GetTotalVolume() const;
    void SetTotalVolume(const Volume & total_volume);

    bool HasTradingLimitResult() const;
    TradingLimitResult GetTradingLimitResult() const;
    void SetTradingLimitResult(const TradingLimitResult & trading_limit_result);

    bool HasTradingLimitState() const;
    TradingLimitState GetTradingLimitState() const;
    void SetTradingLimitState(const TradingLimitState & trading_limit_state);

    bool HasTradingServiceIdentifier() const;
    ServiceIdentifier GetTradingServiceIdentifier() const;
    void SetTradingServiceIdentifier(const ServiceIdentifier & trading_service);

    bool HasTransitionType() const;
    TransitionType GetTransitionType() const;
    void SetTransitionType(const TransitionType & transition_type);

    bool HasValidity() const;
    Validity GetValidity() const;
    void SetValidity(const Validity & validity);

    bool HasVenueInstrumentIdentifier() const;
    VenueInstrumentIdentifier GetVenueInstrumentIdentifier() const;
    void SetVenueInstrumentIdentifier(const VenueInstrumentIdentifier & viid);

    bool HasVolumeDelta() const;
    Volume GetVolumeDelta() const;
    void SetVolumeDelta(const Volume & volume);

    bool HasPegPriceType() const;
    std::optional<PegPriceType> GetPegPriceType() const;
    void SetPegPriceType(const std::optional<PegPriceType> & value);

    bool HasDirectedQuoteResponseIdentifier() const;
    DirectedQuoteResponseIdentifier GetDirectedQuoteResponseIdentifier() const;
    void SetDirectedQuoteResponseIdentifier(const DirectedQuoteResponseIdentifier & id);

    bool HasDirectedQuoteResponseGeneration() const;
    DirectedQuoteResponseGeneration GetDirectedQuoteResponseGeneration() const;
    void SetDirectedQuoteResponseGeneration(const DirectedQuoteResponseGeneration & id);

    bool HasHandlingInstruction() const;
    HandlingInstruction GetHandlingInstruction() const;
    void SetHandlingInstruction(const HandlingInstruction & hi);

    bool HasCFI() const;
    CFI GetCFI() const;
    void SetCFI(const CFI & value);

    void SetLiquidityPool(const LiquidityPoolIdentifier & pool_id);

    /**
     * Check order options for emptiness.
     *
     * @return                          True if order options is empty, false otherwise.
     */
    bool Empty() const;

    virtual std::ostream & Print(std::ostream & strm) const;

    void Merge(const OrderOptions & options);

public:
    const order_t & get_order() const;
    order_t & get_order();

private:
    order_t * m_order;
    Value<Volume> m_volume_delta;
};

class STRATEGY_EXPORT OrderDeleteOptions : public Printable
{
public:
    typedef protocol::OrderDeleteRequest delete_options_t;

public:
    OrderDeleteOptions();
    OrderDeleteOptions(delete_options_t * options);
    OrderDeleteOptions(const OrderDeleteOptions & options);
    virtual ~OrderDeleteOptions();

    OrderDeleteOptions & operator=(const OrderDeleteOptions & options);

public:
    bool HasAlgoLabel() const;
    Integer GetAlgoLabel() const;
    void SetAlgoLabel(const Integer & algo_label);

    bool HasFlowRoutingRuleIdentifier() const;
    TreeNodeIdentifier GetFlowRoutingRuleIdentifier() const;
    void SetFlowRoutingRuleIdentifier(const TreeNodeIdentifier & id);

    bool HasInstrumentVenueIdentification() const;
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    bool HasOperator() const;
    UserIdentifier GetOperator() const;
    void SetOperator(const UserIdentifier & user);

    bool HasOrderIdentifier() const;
    OrderIdentifier GetOrderIdentifier() const;
    void SetOrderIdentifier(const OrderIdentifier & id);

    bool HasRequestIdentifier() const;
    Identifier GetRequestIdentifier() const;
    void SetRequestIdentifier(const Identifier & request_identifier);

    bool HasTradingServiceIdentifier() const;
    ServiceIdentifier GetTradingServiceIdentifier() const;
    void SetTradingServiceIdentifier(const ServiceIdentifier & trading_service);

    bool HasVenueInstrumentIdentifier() const;
    VenueInstrumentIdentifier GetVenueInstrumentIdentifier() const;
    void SetVenueInstrumentIdentifier(const VenueInstrumentIdentifier & viid);

public:
    bool Empty() const;
    virtual std::ostream & Print(std::ostream & strm) const;
    operator OrderOptions() const;

public:
    const delete_options_t & get_options() const;
    delete_options_t & get_options();

private:
    delete_options_t * m_options;
    Volume m_volume_delta;
};

} // \namespace test

} // \namespace tbricks

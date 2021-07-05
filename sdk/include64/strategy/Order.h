#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Order.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Definitions.h"
#include "strategy/InstrumentTradingInformation.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/Printable.h"
#include "strategy/RegulatoryParameters.h"
#include "strategy/Strategy.h"
#include "strategy/generated/OrderModifyBase.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/BestPriceFilter.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/type/AnyType.h"
#include "strategy/type/HandlingInstruction.h"
#include "strategy/type/OrderCapacity.h"
#include "strategy/type/OrderIdentifier.h"
#include "strategy/type/ParticipationPolicy.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/TransactionState.h"
#include "strategy_generated/OrderTemplateBase.h"

#include <memory>
#include <optional>

namespace tbricks {

namespace protocol {
class Order;
}

/**
 */
class STRATEGY_EXPORT Order : public Printable
{
public:
    /**
     * The type of an order.
     * @deprecated Deprecated in 2.12.0.
     *             Use QuoteMode instead.
     */
    enum Type
    {
        ORDER = 1,            ///< The order type indicating normal order.
        QUOTE = 2,            ///< The order type indicating quote order used by quoting service.
        QUOTE_MULTILEVEL = 3, ///< The order type indicating quote order used by quoting service in multilevel updates.
        HIDDEN = 4,           ///< The order type indicating quote order used by quoting service in hidden quoting mode.
        PEG = 5               ///< The order type indicating quote order used by quoting service in peg quoting mode.
    };

public:
    class Options;
    class Modifier;
    class Update;
    class Stream;
    class Modify;
    class Template;
    class ActivationOptions;

public:
    Order();
    Order(protocol::Order * order);
    Order(const OrderIdentifier & order_id);
    Order(const Order::Update & update);
    Order(const Order & order);
    virtual ~Order();

    Order & operator=(const Order & order);

public:
    OrderIdentifier GetIdentifier() const;

    bool HasExchangeOrderIdentifier() const;
    bool GetExchangeOrderIdentifier(String & exchange_order_reference) const;
    bool GetExchangeOrderIdentifier(const char *& exchange_order_reference) const;

    bool HasExchangeClientOrderIdentifier() const;
    bool GetExchangeClientOrderIdentifier(String & exchange_client_order_reference) const;
    bool GetExchangeClientOrderIdentifier(const char *& exchange_client_order_reference) const;

    bool HasTradingServiceIdentifier() const;
    bool GetTradingServiceIdentifier(ServiceIdentifier & trading_service) const;

    bool HasDeleted() const;
    bool GetDeleted(Boolean & deleted) const;

    bool HasHostCreatedDatetime() const;
    bool GetHostCreatedDatetime(DateTime & host_created_datetime) const;

    bool HasHostModifiedDatetime() const;
    bool GetHostModifiedDatetime(DateTime & host_modified_datetime) const;

    bool HasInstrumentVenueIdentification() const;
    bool GetInstrumentVenueIdentification(InstrumentVenueIdentification & ivid) const;

    bool HasVenueInstrumentIdentifier() const;
    bool GetVenueInstrumentIdentifier(VenueInstrumentIdentifier & viid) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSide() const;

    /**
     * Get SELL or BUY side, use GetExecutionPolicy to get additional information.
     *
     * @param value                     returned value
     * @return                          True if field is set, false otherwise
     */
    bool GetSide(Side & value) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExecutionPolicy() const;

    /**
     * Get execution policy
     *
     * @param value                     return value
     * @return                          True if field is set, false otherwise
     */
    bool GetExecutionPolicy(ExecutionPolicy & value) const;

    bool HasPrice() const;
    bool GetPrice(Price & price) const;
    void SetPrice(const Price & price);

    bool HasActiveVolume() const;
    bool GetActiveVolume(Volume & active_volume) const;
    void SetActiveVolume(const Volume & active_volume);

    bool HasFilledVolume() const;
    bool GetFilledVolume(Volume & filled_volume) const;

    bool HasInternallyFilledVolume() const;
    bool GetInternallyFilledVolume(Volume & internally_filled_volume) const;

    bool HasTotalVolume() const;
    bool GetTotalVolume(Volume & total_volume) const;

    bool HasValueFactor() const;
    bool GetValueFactor(Double & factor) const;

    bool HasAveragePaid() const;
    bool GetAveragePaid(Double & average_paid) const;

    bool HasAveragePaidVolume() const;
    bool GetAveragePaidVolume(Volume & average_paid_volume) const;

    bool HasRetainOnDisconnect() const;
    bool GetRetainOnDisconnect(Boolean & retain_on_disconnect) const;

    bool HasPartialFillNotAllowed() const;
    bool GetPartialFillNotAllowed(Boolean & partial_fill_not_allowed) const;

    bool HasHandlingInstruction() const;
    bool GetHandlingInstruction(HandlingInstruction & instruction) const;

    bool HasPriceImprovementNotAllowed() const;
    bool GetPriceImprovementNotAllowed(Boolean & price_improvement_not_allowed) const;

    bool HasBypassSoftLimits() const;
    bool GetBypassSoftLimits(Boolean & bypass_soft_limits) const;

    bool HasRootStrategyIdentifier() const;
    bool GetRootStrategyIdentifier(StrategyIdentifier & root_strategy_identifier) const;

    bool HasParentStrategyIdentifier() const;
    bool GetParentStrategyIdentifier(StrategyIdentifier & parent_strategy_identifier) const;

    bool HasCreator() const;
    bool GetCreator(UserIdentifier & creator) const;
    bool GetCreator(User & creator) const;

    bool HasOwner() const;
    bool GetOwner(UserIdentifier & owner) const;
    bool GetOwner(User & owner) const;

    bool HasOperator() const;
    bool GetOperator(UserIdentifier & owner) const;
    bool GetOperator(User & user) const;

    bool HasPortfolioIdentifier() const;
    bool GetPortfolioIdentifier(PortfolioIdentifier & portfolio_identifier) const;

    bool HasCurrency() const;
    bool GetCurrency(Currency & currency) const;

    bool HasDealtCurrency() const;
    bool GetDealtCurrency(Currency & currency) const;

    bool HasRequestIdentifier() const;
    bool GetRequestIdentifier(Identifier & request_identifier) const;

    bool HasExtraData() const;
    bool GetExtraData(ExtraData & extra_data) const;

    bool HasTransactionState() const;
    bool GetTransactionState(TransactionState & order_transaction_state) const;

    bool HasStatusText() const;
    bool GetStatusText(String & status_text) const;

    bool HasExtraParameters() const;
    bool GetExtraParameters(StrategyParameters & strategy_parameters) const;

    bool HasTradingLimitResult() const;
    bool GetTradingLimitResult(TradingLimitResult & trading_limit_result) const;

    bool HasTradingLimitState() const;
    bool GetTradingLimitState(TradingLimitState & trading_limit_state) const;

    bool HasValidity() const;
    bool GetValidity(Validity & validity) const;

    bool HasComment() const;
    bool GetComment(String & comment) const;

    bool HasTargetPrice() const;
    bool GetTargetPrice(Price & target_price) const;

    bool HasStopPrice() const;
    bool GetStopPrice(Price & stop_price) const;

    bool HasAlgoLabel() const;
    bool GetAlgoLabel(Integer & algo_label) const;

    bool HasDisclosedVolume() const;
    bool GetDisclosedVolume(Volume & disclosed_volume) const;

    bool HasTransitionType() const;
    bool GetTransitionType(TransitionType & transition_type) const;

    bool HasPostingAction() const;
    bool GetPostingAction(PostingActionType & posting_action) const;

    bool HasMinimumAcceptableFillVolume() const;
    bool GetMinimumAcceptableFillVolume(Volume & minimum_acceptable_fill_volume) const;

    bool HasMinimumAcceptableVolume() const;
    bool GetMinimumAcceptableVolume(Volume & minimum_acceptable_volume) const;

    bool HasCapacity() const;
    bool GetCapacity(OrderCapacity & capacity) const;

    bool HasParticipationPolicy() const;
    bool GetParticipationPolicy(ParticipationPolicy & participation_policy) const;

    bool HasExchangeCreatedDatetime() const;
    bool GetExchangeCreatedDatetime(DateTime & exchange_created_datetime) const;

    bool HasExchangeModifiedDatetime() const;
    bool GetExchangeModifiedDatetime(DateTime & exchange_modified_datetime) const;

    bool HasStrategyParameters() const;
    bool GetStrategyParameters(StrategyParameters & strategyParameters) const;

    bool HasStrategyPath() const;
    void GetStrategyPath(std::vector<StrategyIdentifier> & path) const;

    bool HasStrategyDefinitionPath() const;
    void GetStrategyDefinitionPath(std::vector<StrategyIdentifier> & path) const;

    bool HasPricePolicy() const;
    bool GetPricePolicy(PricePolicy & policy) const;

    bool HasRegulatoryParameters() const;
    bool GetRegulatoryParameters(RegulatoryParameters & parameters) const;

    bool HasLastTradeIdentifier() const;
    bool GetLastTradeIdentifier(TradeIdentifier & trade_identifier) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLiquidityPool() const;

    /**
     * Get liquidity pool identifier.
     *
     * @param                           Returned liquidity pool identifier
     * @return                          True if field is set, false otherwise
     */
    bool GetLiquidityPool(LiquidityPoolIdentifier & identifier) const;

    /**
     * Get Incoming Directed Quote identifier.
     *
     * @return                          "true" if Incoming Directed quote identifier is set, "false" otherwise
     */
    bool GetDirectedQuoteResponseIdentifier(DirectedQuoteResponseIdentifier & identifier) const;

    /**
     * Get Incoming Directed Quote identifier.
     *
     * @return                          "true" if Incoming Directed quote identifier is set, "false" otherwise
     */
    bool GetDirectedQuoteResponseGeneration(DirectedQuoteResponseGeneration & identifier) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandler() const;

    /**
     * Node in a tree that represent the managing entity of strategy and/or orders.
     *
     * @param                           Returned handler
     * @return                          True if handler is set, false otherwise.
     */
    bool GetHandler(TreeNodeIdentifier & handler) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasClient() const;

    /**
     * Node in a tree that represent the managed entity for a strategy and/or orders.
     *
     * @param                           Represent client
     * @return                          True if client is set, false otherwise.
     */
    bool GetClient(TreeNodeIdentifier & client) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExPitIdentifier() const;

    /**
     * Get ExPit identifier
     *
     * @param                           Returned ExPit identifier
     * @return                          True if field is set, false otherwise
     */
    bool GetExPitIdentifier(ExPitIdentifier & id) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasQuoteMode() const;

    /**
     * Get quote mode
     *
     * @param                           Returned quote mode
     * @return                          True if field is set, false otherwise
     */
    bool GetQuoteMode(QuoteMode & value) const;

    /**
     * Check if field is set.
     *
     * @deprecated Deprecated in 2.12.0.
     *             Use HasQuoteMode() instead.
     *
     * @return                          True if field is set, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasType() const;

    /**
     * Get order type
     *
     * @deprecated Deprecated in 2.12.0.
     *             Use GetQuoteMode() instead.
     *
     * @param                           Returned order type
     * @return                          True if field is set, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetType(Type & value) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPegPriceType() const;

    /**
     * Get peg price type
     *
     * @param                           Returned peg price type
     * @return                          True if field is set, false otherwise
     */
    bool GetPegPriceType(std::optional<PegPriceType> & value) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeDepthIdentifier() const;

    /**
     * Get venue-specific identifier of depth entry.
     * On quote-driven venues (typically FX) this identifier must be passed when sending
     * an order to trade that depth entry.
     *
     * @param                           Returned exchange depth identifier
     * @return                          True if field is set, false otherwise
     */
    bool GetExchangeDepthIdentifier(String & value) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUnsolicited() const;

    /**
     * Get unsolicited.
     *
     * @return                          Unsolicited
     */
    bool GetUnsolicited(Boolean & unsolicited) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOrderTemplateIdentifier() const;

    /**
     * Get order template identifier if order was created from template
     *
     * @param                           Returned order template identifier
     * @return                          True if field is set, false otherwise
     */
    bool GetOrderTemplateIdentifier(OrderTemplateIdentifier & value) const;

    /**
     * Check order for emptiness.
     *
     * @return                          True if order is empty, false otherwise.
     */
    bool Empty() const;

    /**
     * Clear all contents from the order object.
     */
    void Clear();

    /**
     * Merge order update.
     *
     * @param update                Order update
     */
    void Merge(const Order::Update & update);

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, Order::Type value);

public:
    const protocol::Order & get_order() const;
    protocol::Order & get_order();

private:
    protocol::Order * m_order;
};

namespace protocol {
class OrderModifyRequest;
class OrderDeleteRequest;
}

class STRATEGY_EXPORT Order::Template : public OrderTemplateBase
{
public:
    using OrderTemplateBase::OrderTemplateBase;

    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & value);
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;
    bool HasInstrumentVenueIdentification() const;

    void SetPortfolioIdentifier(const PortfolioIdentifier & value);
    PortfolioIdentifier GetPortfolioIdentifier() const;
    bool HasPortfolioIdentifier() const;

    void SetValidity(const Validity & value);
    Validity GetValidity() const;
    bool HasValidity() const;
};

class STRATEGY_EXPORT Order::ActivationOptions
{
public:
    ActivationOptions() = default;

public:
    Volume GetVolume() const;
    void SetVolume(const Volume & value);
    bool HasVolume() const;

    Price GetPrice() const;
    void SetPrice(const Price & value);
    bool HasPrice() const;

    Price GetTargetPrice() const;
    void SetTargetPrice(const Price & value);
    bool HasTargetPrice() const;

    ExtraData GetExtraData() const;
    void SetExtraData(ExtraData value);
    bool HasExtraData() const;

private:
    friend class OrderManager;

    std::optional<double> m_volume;
    std::optional<double> m_price;
    std::optional<double> m_target_price;
    void * m_data = nullptr;
    size_t m_data_size = 0;
};

/**
 * Order::Options allows us to create orders by setting various parameters
 * and properties of order. SendCreateRequest method of OrderManger is to create order.
 */
class STRATEGY_EXPORT Order::Options : public Printable
{
public:
    Options();
    Options(const Options & value);
    Options(Options && value);

    ~Options();

    Options & operator=(const Options & value);
    Options & operator=(Options && value);

public:
    /**
     * %Set the instrument venue identification.
     *
     * @param ivid				const InstrumentVenueIdentification
     */
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    /**
     * Get the instrument venue identification.
     *
     * @return					const InstrumentVenueIdentification
     */
    const InstrumentVenueIdentification & GetInstrumentVenueIdentification() const;

    /**
     * %Set side of the order.
     * Possible value of side are SELL and BUY.
     *
     * @param side				Instance of Side
     */
    void SetSide(const Side & side);

    /**
     * Get the side of the order.
     * Possible value of side are SELL and BUY.
     * Use GetExecutionPolicy to get additional information.
     *
     * @return					instance of Side
     */
    const Side & GetSide() const;

    /**
     * %Set execution policy
     *
     * @param value             execution policy
     */
    void SetExecutionPolicy(const ExecutionPolicy & value);

    /**
     * Get execution policy
     *
     * @return                  execution policy
     */
    ExecutionPolicy GetExecutionPolicy() const;

    /**
     * %Set the price to be send in the order.
     *
     * @param price				instance of Price.
     */
    void SetPrice(const Price & price);

    /**
     * Get the price of the order.
     *
     * @return					instance of Price
     */
    Price GetPrice() const;

    /**
     * %Set the volume of the order.
     *
     * @param active_volume                    instance of Volume.
     *                                         Active volume of the order.
     */
    void SetActiveVolume(const Volume & active_volume);

    /**
     * Get the active volume of the order.
     *
     * @return                                 instance of Volume.
     */
    Volume GetActiveVolume() const;

    /**
     * %Set the validity of the order.
     * Time in force of the order.
     * For example: Day, GTD, GTC, etc
     *
     * @param validity                         Validity of the order
     */
    void SetValidity(const Validity & validity);

    /**
     * Get the validity of the order.
     *
     * @return					const Validity instance
     */
    const Validity & GetValidity() const;

    /**
     * %Set retain on disconnect flag of the order.
     *
     * @param retain_on_disconnect		true to set flag to retain on disconnect, false otherwise.
     */
    void SetRetainOnDisconnect(const Boolean & retain_on_disconnect);

    /**
     * Check the status of the retain on disconnect flag.
     *
     * @return                                 true if flag is set to retain on disconnect, false otherwise.
     */
    const Boolean GetRetainOnDisconnect() const;

    /**
     * %Set partial filled not allowed flag of the order.
     *
     * @param partial_fill_not_allowed         set true if partial is not be allowed, false otherwise.
     */
    void SetPartialFillNotAllowed(const Boolean & partial_fill_not_allowed);

    /**
     * Check if partial is allowed or not.
     *
     * @return                                 true if partial filled is NOT allowed, false otherwise.
     */
    Boolean GetPartialFillNotAllowed() const;

    /**
     * %Set the handling instruction type of the order.
     * The way an order is to be processed is specified
     * by the handling instruction value.
     *
     * @param instruction                      const HandlingInstruction instance
     */
    void SetHandlingInstruction(const HandlingInstruction & instruction);

    /**
     * Get the Handling instruction set on the order.
     *
     * @retrun                                 Handling Instruction
     */
    HandlingInstruction GetHandlingInstruction() const;

    /**
     * %Set price improvement not allowed flag of the order.
     *
     * @param price_improvement_not_allowed	true if price improvement not allowed flag
     * 										is not be supported, false otherwise.
     */
    void SetPriceImprovementNotAllowed(const Boolean & price_improvement_not_allowed);

    /**
     * Check if price improvement allowed or not.
     *
     * @return                                 true if price improvement is NOT allowed, false otherwise.
     */
    Boolean GetPriceImprovementNotAllowed() const;

    /**
     * %Set the bypass soft limit flag of the order.
     *
     * @param bypass_soft_limits               true if bypass soft limit is to be allowed, false otherwise.
     */
    void SetBypassSoftLimits(const Boolean & bypass_soft_limits);

    /**
     * Check if bypass soft limit allowed or not.
     *
     * @return                                 true if bypass soft limit is allowed, false otherwise.
     */
    Boolean GetBypassSoftLimits() const;

    /**
     * %Set portpolio of the order.
     *
     * @param portfolio_id			PortfolioIdentifier to the portfolio to be set.
     */
    void SetPortfolioIdentifier(const PortfolioIdentifier & portfolio_id);

    /**
     * Get the portfolio identifier of the order.
     *
     * @return                                 instance of PortfolioIdentifier
     */
    const PortfolioIdentifier & GetPortfolioIdentifier() const;

    /**
     * Get the name of the portfolio sent in the order .
     *
     * @return                                 Portfolio name.
     *                                         const String instance.
     */
    const String & GetPortfolioName() const;

    /**
     * %Set extra data value for the order.
     *
     * Extra data is a key value pair.
     * Extra data is something which you can set for apps,
     * orders and for trades; any extra data set directly
     * for an order will be automatically transfered to all trades resulting from the order.
     *
     * @param key                              Extra data key
     * @param value                            value of the extra data key
     */
    void SetExtraDataValue(const String & key, const AnyType & value);

    /**
     * %Set extra data for the order.
     * Extra data is something which you can set for apps,
     * orders and for trades; any extra data set directly
     * for an order will be automatically transfered to all trades resulting from the order.
     *
     * @param  extra_data                      instance of ExtraData
     */
    void SetExtraData(const ExtraData & extra_data);

    /**
     *  Get the extra data of the order.
     *
     *  @retrun                                const ExtraData instance
     */
    const ExtraData & GetExtraData() const;

    /**
     * Get strategy parameters which should be passed to venue alongside with an order.
     * Used to represent additional parameters for algo orders available on
     * FIX venues or on Tbricks Matching Engine.
     *
     * @return                          %Strategy parameters
     */
    const StrategyParameters & GetStrategyParameters() const;
    /**
     * %Set strategy parameters which should be passed to venue alongside with an order.
     * Used to represent additional parameters for algo orders available on
     * FIX venues or on Tbricks Matching Engine.
     *
     * @param value                     %Strategy parameters
     */
    void SetStrategyParameters(const StrategyParameters & value);

    /**
     * %Set comment for the order.
     *
     * @param comment                          comment for the order
     */
    void SetComment(const String & comment);

    /**
     * Get the comment.
     *
     * @return                                 comment set for the order
     */
    String GetComment() const;

    /**
     * %Set target price of the order.
     * A price target is the projected price level of a financial security.
     * resents a security's price that, if achieved,
     * results in a trader recognizing the best possible outcome for an investment.
     *
     * @param target_price                     Instance of Price.
     */
    void SetTargetPrice(const Price & target_price);

    /**
     * Get the target price set for the order.
     *
     * @return                                 target price
     */
    Price GetTargetPrice() const;

    /**
     * %Set the stop price of the order.
     * A stop price is the price in a stop order that
     * triggers the creation of a market order.
     * In the case of a Sell on Stop order, a market sell order
     * is triggered when the market price reaches or falls below the stop price.
     *
     * @param stop_price                       stop price for stop order
     */
    void SetStopPrice(const Price & stop_price);

    /**
     * Get the stop price of the order.
     *
     * @return                                 stop price of the stop order
     */
    Price GetStopPrice() const;

    /**
     * %Set the dealt currency for the order.
     *
     * If a client trades at the quoted rate,
     * then the dealt currency is the one that specifies the unit of the trade.
     *
     * @param dealt_currency			Dealt currency
     */
    void SetDealtCurrency(const Currency & dealt_currency);

    /**
     * Get the dealt currency of the order.
     *
     * @return                                 Dealt currency
     */
    Currency GetDealtCurrency() const;

    /**
     * %Set disclosed volume for the order.
     * Disclosed quantity is the quantity that is to
     * be shown in market depth. It is less than the total quantity.
     * This feature is useful for those selling and buying in large quantity
     *
     * @param disclosed_volume			disclosed volume
     */
    void SetDisclosedVolume(const Volume & disclosed_volume);

    /**
     * Get the discloed volume of the order.
     *
     * @return					disclosed volume of the order.
     */
    Volume GetDisclosedVolume() const;

    /**
     * %Set the transition type of the order.
     * It can be either 'market to limit' or 'limit to market'.
     *
     * @param transition_type                  const TransitionType instance
     */
    void SetTransitionType(const TransitionType & transition_type);

    /**
     * Get the transition type of the order.
     *
     * @return                                 transition type of the order
     */
    TransitionType GetTransitionType() const;

    /**
     * %Set minimum acceptable fill volume for the order.
     *
     * @param minimum_acceptable_fill_volume	Instance of Volume
     */
    void SetMinimumAcceptableFillVolume(const Volume & minimum_acceptable_fill_volume);

    /**
     * Get the minimum acceptable fill volume of the order.
     *
     * @return                                 const Volume instance
     */
    Volume GetMinimumAcceptableFillVolume() const;

    /**
     * %Set the minimum acceptable volume for the order.
     *
     * @param minimum_acceptable_volume        minimum acceptable volume for the order.
     */
    void SetMinimumAcceptableVolume(const Volume & minimum_acceptable_volume);

    /**
     * Get the minimum acceptable volume of the order.
     *
     * @return                                 const Volume instance
     */
    Volume GetMinimumAcceptableVolume() const;

    /**
     * %Set the order capacity.
     * Possible Values (Generic)
     * Agency
     * Principal
     * Riskless Principal
     *
     * @param capacity				const instance of OrderCapacity
     */
    void SetCapacity(const OrderCapacity & capacity);

    /**
     * Get the order capacity.
     * Possible Values (Generic)
     * Agency
     * Principal
     * Riskless Principal
     *
     * @return                                 const instance of OrderCapacity
     */
    OrderCapacity GetCapacity() const;

    /**
     * %Set the participation policy for the order.
     * Possible value:
     * DARK_LIT_SWEEP,
     * BYPASS_UNDISCLOSED,
     * INDICATIVE_ONLY
     *
     * @param policy                           Order participation policy
     */
    void SetParticipationPolicy(const ParticipationPolicy & policy);

    /**
     * Get the order participation policy.
     *
     * @return                                 const ParticipationPolicy instance
     */
    ParticipationPolicy GetParticipationPolicy() const;

    /**
     * %Set the client for the order.
     *
     * @param client				Instance of TreeNodeIdentifier
     */
    void SetClient(const TreeNodeIdentifier & client);

    /**
     * Get the client node identifier of the order.
     *
     * @return                                 const TreeNodeIdentifier instance
     */
    TreeNodeIdentifier GetClient() const;

    /**
     * %Set the handler for the order.
     * Its a node in a tree that represent the managing
     * entity of strategy and/or orders.
     *
     * @param TreeNodeIdentifier               Instance of TreeNodeIdentifier
     */
    void SetHandler(const TreeNodeIdentifier & handler);

    /**
     * Get the handler of the order.
     * Its a node in a tree that represent the managing
     * entity of strategy and/or orders.
     *
     * @return                                 handler of the order
     */
    TreeNodeIdentifier GetHandler() const;

    /**
     * %Set the price policy, that is  an additional criteria
     * on how the price may be formed, with or without normal limit price.
     *
     * @param policy                           Instance of PricePolicy
     */
    void SetPricePolicy(const PricePolicy & policy);

    /**
     * Get the PricePolicy set on the order.
     *
     * @return                                 price policy
     */
    PricePolicy GetPricePolicy() const;

    /**
     * %Set the extra persistent regulatory audit data on the order.
     *
     * @param parameters                       Instance of RegulatoryParameters
     */
    void SetRegulatoryParameters(const RegulatoryParameters & parameters);

    /**
     * Get the regulatory parameters of the order.
     *
     * @return                                 extra persistent regulatory audit data of the order
     */
    const RegulatoryParameters & GetRegulatoryParameters() const;

    /**
     * %Set liquidity pool identifier.
     * If value is empty, the field will be deleted from Options.
     *
     * @param value                            Instance of LiquidityPoolIdentifier
     */
    void SetLiquidityPool(const LiquidityPoolIdentifier & value);

    /**
     * Set directed quote response identifier.
     * The Directed Quote Response Identifier is a unique identifier of object.
     * If value is empty, the field will be deleted from Options.
     *
     * @param value                            Instance of DirectedQuoteResponseIdentifier
     */
    void SetDirectedQuoteResponse(const DirectedQuoteResponseIdentifier & value);

    /**
     * Set directed quote response identifier
     * If value is empty, the field will be deleted from Options.
     * Directed Quote Response Generation identifies version of Directed Quote Response.
     *
     * @param value                            Instance of DirectedQuoteResponseGeneration
     */
    void SetDirectedQuoteResponseGeneration(const DirectedQuoteResponseGeneration & value);

    /**
     * Get the DirectedQuoteResponseGeneration.
     *
     * @return                                 directed quote response generation
     */
    DirectedQuoteResponseGeneration GetDirectedQuoteResponseGeneration() const;

    /**
     * Get the DirectedQuoteResponseIdentifier.
     * The Directed Quote Response Identifier is a unique identifier of object.
     *
     * @return                                 directed quote response identifier
     */
    DirectedQuoteResponseIdentifier GetDirectedQuoteResponse() const;

    /**
     * Get liquidity pool identifier.
     *
     * @return                          Liquidity pool identifier
     */
    LiquidityPoolIdentifier GetLiquidityPool() const;

    /**
     * %Set posting action.
     *
     * @param value                     posting action
     */
    void SetPostingAction(const PostingActionType & value);

    /**
     * Get posting action.
     *
     * @return                          posting action
     */
    PostingActionType GetPostingAction() const;

    /**
     * %Apply app template to the strategy.
     *
     * @throws EmptyValueException if app_template is empty
     *
     * @throws NotFoundException if there is no tree node with app_template identifier
     *
     * @throws TypeMismatchException if corresponding tree node is of the type other than App template
     *
     * @param app_template               App template identifier
     *                                   StrategyParameters.
     */
    void ApplyTemplate(const TreeNodeIdentifier & app_template);

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPegPriceType() const;

    /**
     * Get peg price type
     *
     * @return                          peg price type
     */
    std::optional<PegPriceType> GetPegPriceType() const;

    /**
     * %Set peg price type
     *
     * If the value is empty field will delete from options.
     *
     * @param                           peg price type
     */
    void SetPegPriceType(const std::optional<PegPriceType> & value);

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeDepthIdentifier() const;

    /**
     * Get venue-specific identifier of depth entry.
     * On quote-driven venues (typically FX) this identifier must be passed when sending
     * an order to trade that depth entry.
     *
     * @return                          exchange depth identifier
     */
    String GetExchangeDepthIdentifier() const;

    /**
     * %Set venue-specific identifier of depth entry.
     * On quote-driven venues (typically FX) this identifier must be passed when sending
     * an order to trade that depth entry.
     *
     * @param                           exchange depth identifier
     */
    void SetExchangeDepthIdentifier(const String & value);

public:
    void Merge(const Modifier & modifier);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    const std::unique_ptr<protocol::Order> & init_pointer();

    inline const std::unique_ptr<protocol::Order> & get_impl()
    {
        if (TB_LIKELY(nullptr != m_impl)) {
            return m_impl;
        }
        return init_pointer();
    }

    inline const std::unique_ptr<protocol::Order> & get_impl() const { return m_impl; }

private:
    InstrumentVenueIdentification m_ivid;
    Side m_side;
    Validity m_validity;
    PortfolioIdentifier m_portfolio_id;
    String m_portfolio_name;
    ExtraData m_extra_data;
    StrategyParameters m_forward_parameters;
    RegulatoryParameters m_regulatory_parameters;

    std::unique_ptr<protocol::Order> m_impl;
};

/**
 * Order::Modifier, helper class for remote order
 * parameter modifications.
 *
 * @see Order::SendModifyRequest
 */
class STRATEGY_EXPORT Order::Modifier : public Printable
{
public:
    /**
     * Contructor.
     */
    Modifier();

    Modifier(const Modifier & value);

    /* Become an owner */
    Modifier(protocol::OrderModifyRequest * value);

    Modifier & operator=(const Modifier & value);

    /**
     * Destructor.
     */
    ~Modifier();

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPrice() const;

    /**
     * Get price.
     *
     * @return                          price
     */
    Price GetPrice() const;

    /**
     * %Set price.
     *
     * @param value                     price
     */
    void SetPrice(const Price & value);

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasActiveVolume() const;

    /**
     * Get active volume.
     *
     * @return                          active volume
     */
    Volume GetActiveVolume() const;

    /**
     * %Set active volume.
     *
     * @param value                     active volume
     */
    void SetActiveVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTotalVolume() const;

    /**
     * Get total volume.
     *
     * @return                          total volume
     */
    Volume GetTotalVolume() const;

    /**
     * %Set total volume.
     *
     * @param value                     total volume
     */
    void SetTotalVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     *
     * @deprecated Deprecated in 2.14.5
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasRetainOnDisconnect() const;

    /**
     * Get retain on disconnect.
     *
     * @return                          retain on disconnect
     *
     * @deprecated Deprecated in 2.14.5
     */
    [[deprecated(DEPRECATE_LINK)]] Boolean GetRetainOnDisconnect() const;

    /**
     * %Set retain on disconnect.
     *
     * @param value                     retain on disconnect
     *
     * @deprecated Deprecated in 2.14.5
     */
    [[deprecated(DEPRECATE_LINK)]] void SetRetainOnDisconnect(const Boolean & value);

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPortfolioIdentifier() const;
    /**
     * Get portfolio identifier.
     *
     * @return                          portfolio identifier
     */
    PortfolioIdentifier GetPortfolioIdentifier() const;
    String GetPortfolioName() const;
    /**
     * %Set portfolio identifier.
     *
     * @param value                     portfolio identifier
     */
    void SetPortfolioIdentifier(const PortfolioIdentifier & value);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExtraData() const;
    /**
     * Get extra data.
     *
     * @return                          extra data
     */
    ExtraData GetExtraData() const;
    /**
     * %Set extra data.
     *
     * @param value                     extra data
     */
    void SetExtraData(const ExtraData & value);
    void SetExtraDataValue(const String & key, const AnyType & value);

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyParameters() const;

    /**
     * Get strategy parameters which should be passed to venue alongside with an order.
     * Used to represent additional parameters for algo orders available on
     * FIX venues or on Tbricks Matching Engine.
     *
     * @return                          %Strategy parameters
     */
    StrategyParameters GetStrategyParameters() const;
    /**
     * %Set strategy parameters which should be passed to venue alongside with an order.
     * Used to represent additional parameters for algo orders available on
     * FIX venues or on Tbricks Matching Engine.
     *
     * @param value                     %Strategy parameters
     */
    void SetStrategyParameters(const StrategyParameters & value);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasValidity() const;
    /**
     * Get validity.
     *
     * @return                          validity
     */
    Validity GetValidity() const;
    /**
     * %Set validity.
     *
     * @param                           validity
     */
    void SetValidity(const Validity & validity);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComment() const;
    /**
     * Get comment.
     *
     * @return                          comment
     */
    String GetComment() const;
    /**
     * %Set comment.
     *
     * @param value                     comment
     */
    void SetComment(const String & value);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStopPrice() const;
    /**
     * Get stop price.
     *
     * @return                          stop price
     */
    Price GetStopPrice() const;
    /**
     * %Set stop price.
     *
     * @param value                     stop price
     */
    void SetStopPrice(const Price & value);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBypassSoftLimits() const;
    /**
     * Get bypass soft limits.
     *
     * @return                          bypass soft limits
     */
    Boolean GetBypassSoftLimits() const;
    /**
     * %Set bypass soft limits.
     *
     * @param value                     bypass soft limits
     */
    void SetBypassSoftLimits(const Boolean & value);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasClient() const;
    /**
     * Get client.
     *
     * @return                          client
     */
    TreeNodeIdentifier GetClient() const;
    /**
     * %Set client.
     *
     * @param value                     client
     */
    void SetClient(const TreeNodeIdentifier & value);
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
     * @param value                     handler
     */
    void SetHandler(const TreeNodeIdentifier & value);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDisclosedVolume() const;
    /**
     * Get disclosed volume.
     *
     * @return                          disclosed volume
     */
    Volume GetDisclosedVolume() const;
    /**
     * %Set disclosed volume.
     *
     * @param value                     disclosed volume
     */
    void SetDisclosedVolume(const Volume & value);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMinimumAcceptableFillVolume() const;
    /**
     * Get minimum acceptable fill volume.
     *
     * @return                          minimum acceptable fill volume
     */
    Volume GetMinimumAcceptableFillVolume() const;
    /**
     * %Set minimum acceptable fill volume.
     *
     * @param value                     minimum acceptable fill volume
     */
    void SetMinimumAcceptableFillVolume(const Volume & value);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLiquidityPool() const;
    /**
     * Get liquidity pool identifier.
     *
     * @return                          liquidity pool identifier
     */
    LiquidityPoolIdentifier GetLiquidityPool() const;
    /**
     * %Set liquidity pool identifier.
     *
     * @param value                     liquidity pool identifier
     */
    void SetLiquidityPool(const LiquidityPoolIdentifier & value);

    /**
     * %Set execution policy
     *
     * @param value             execution policy
     */
    void SetExecutionPolicy(const ExecutionPolicy & value);

    /**
     * Get execution policy
     *
     * @return                  execution policy
     */
    ExecutionPolicy GetExecutionPolicy() const;

    /**
     * %Apply app template to the strategy.
     *
     * @throws EmptyValueException if app_template is empty
     *
     * @throws NotFoundException if there is no tree node with app_template identifier
     *
     * @throws TypeMismatchException if corresponding tree node is of the type other than App template
     *
     * @param app_template               App template identifier
     *                                   StrategyParameters.
     */
    void ApplyTemplate(const TreeNodeIdentifier & app_template);

    /**
     * Check if field is set.
     *
     * @return                          True if field is set (even if set empty field),
     *                                  false if field does not set
     */
    bool HasPegPriceType() const;

    /**
     * Get peg price type
     *
     * @return                          peg price type
     */
    std::optional<PegPriceType> GetPegPriceType() const;

    /**
     * %Set peg price type
     *
     * The field will be set into object even if the field is empty.
     *
     * @param                          peg price type
     */
    void SetPegPriceType(const std::optional<PegPriceType> & value);

public:
    bool Empty() const;

    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

    protocol::OrderModifyRequest & get_impl() const;

private:
    friend class OrderManager;

private:
    std::unique_ptr<protocol::OrderModifyRequest> m_impl;
    ExtraData m_extra_data;
};

/**
 * Order::Update, collection of updated instrument order.
 */
class STRATEGY_EXPORT Order::Update : public Printable
{
public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    const protocol::Order & get_order_update() const;

public:
    Update(const protocol::Order & order);

    Update(const Update & value) = delete;
    Update & operator=(const Update & value) = delete;

    ~Update();

    OrderIdentifier GetIdentifier() const;

    bool HasExchangeOrderIdentifier() const;
    bool GetExchangeOrderIdentifier(String & exchange_order_reference) const;
    bool GetExchangeOrderIdentifier(const char *& exchange_order_reference) const;

    bool HasExchangeClientOrderIdentifier() const;
    bool GetExchangeClientOrderIdentifier(String & exchange_client_order_reference) const;
    bool GetExchangeClientOrderIdentifier(const char *& exchange_client_order_reference) const;

    bool HasTradingServiceIdentifier() const;
    bool GetTradingServiceIdentifier(ServiceIdentifier & trading_service) const;

    bool HasDeleted() const;
    bool GetDeleted(Boolean & deleted) const;

    bool HasHostCreatedDatetime() const;
    bool GetHostCreatedDatetime(DateTime & host_created_datetime) const;

    bool HasHostModifiedDatetime() const;
    bool GetHostModifiedDatetime(DateTime & host_modified_datetime) const;

    bool HasInstrumentVenueIdentification() const;
    bool GetInstrumentVenueIdentification(InstrumentVenueIdentification & ivid) const;

    bool HasVenueInstrumentIdentifier() const;
    bool GetVenueInstrumentIdentifier(VenueInstrumentIdentifier & viid) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSide() const;

    /**
     * Get SELL or BUY side, use GetExecutionPolicy to get additional information.
     *
     * @param value                     returned value
     * @return                          True if field is set, false otherwise
     */
    bool GetSide(Side & value) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExecutionPolicy() const;

    /**
     * Get execution policy
     *
     * @param value                     return value
     * @return                          True if field is set, false otherwise
     */
    bool GetExecutionPolicy(ExecutionPolicy & value) const;

    bool HasPrice() const;
    bool GetPrice(Price & price) const;

    bool HasActiveVolume() const;
    bool GetActiveVolume(Volume & active_volume) const;

    bool HasDisclosedVolume() const;
    bool GetDisclosedVolume(Volume & disvlosed_volume) const;

    bool HasFilledVolume() const;
    bool GetFilledVolume(Volume & filled_volume) const;

    bool HasInternallyFilledVolume() const;
    bool GetInternallyFilledVolume(Volume & internally_filled_volume) const;

    bool HasTotalVolume() const;
    bool GetTotalVolume(Volume & total_volume) const;

    bool HasAveragePaid() const;
    bool GetAveragePaid(Double & average_paid) const;

    bool HasAveragePaidVolume() const;
    bool GetAveragePaidVolume(Volume & average_paid_volume) const;

    bool HasRetainOnDisconnect() const;
    bool GetRetainOnDisconnect(Boolean & retain_on_disconnect) const;

    bool HasPartialFillNotAllowed() const;
    bool GetPartialFillNotAllowed(Boolean & partial_fill_not_allowed) const;

    bool HasHandlingInstruction() const;
    bool GetHandlingInstruction(HandlingInstruction & instruction) const;

    bool HasPriceImprovementNotAllowed() const;
    bool GetPriceImprovementNotAllowed(Boolean & price_improvement_not_allowed) const;

    bool HasBypassSoftLimits() const;
    bool GetBypassSoftLimits(Boolean & bypass_soft_limits) const;

    bool HasRootStrategyIdentifier() const;
    bool GetRootStrategyIdentifier(StrategyIdentifier & root_strategy_identifier) const;

    bool HasParentStrategyIdentifier() const;
    bool GetParentStrategyIdentifier(StrategyIdentifier & parent_strategy_identifier) const;

    bool HasCreator() const;
    bool GetCreator(UserIdentifier & creator) const;
    bool GetCreator(User & creator) const;

    bool HasOwner() const;
    bool GetOwner(UserIdentifier & owner) const;
    bool GetOwner(User & owner) const;

    bool HasOperator() const;
    bool GetOperator(UserIdentifier & owner) const;
    bool GetOperator(User & user) const;

    bool HasPortfolioIdentifier() const;
    bool GetPortfolioIdentifier(PortfolioIdentifier & portfolio_identifier) const;

    bool HasRequestIdentifier() const;
    bool GetRequestIdentifier(Identifier & request_identifier) const;

    bool HasExtraData() const;
    bool GetExtraData(ExtraData & extra_data) const;

    bool HasTransactionState() const;
    bool GetTransactionState(TransactionState & order_transaction_state) const;

    bool HasStatusText() const;
    bool GetStatusText(String & status_text) const;

    bool HasExtraParameters() const;
    bool GetExtraParameters(StrategyParameters & strategy_parameters) const;

    bool HasTradingLimitResult() const;
    bool GetTradingLimitResult(TradingLimitResult & trading_limit_result) const;

    bool HasTradingLimitState() const;
    bool GetTradingLimitState(TradingLimitState & trading_limit_state) const;

    bool HasComment() const;
    bool GetComment(String & comment) const;

    bool HasTargetPrice() const;
    bool GetTargetPrice(Price & target_price) const;

    bool HasStopPrice() const;
    bool GetStopPrice(Price & stop_price) const;

    bool HasAlgoLabel() const;
    bool GetAlgoLabel(Integer & algo_label) const;

    bool HasTransitionType() const;
    bool GetTransitionType(TransitionType & transition_type) const;

    bool HasPostingAction() const;
    bool GetPostingAction(PostingActionType & posting_action) const;

    bool HasMinimumAcceptableFillVolume() const;
    bool GetMinimumAcceptableFillVolume(Volume & minimum_acceptable_fill_volume) const;

    bool HasMinimumAcceptableVolume() const;
    bool GetMinimumAcceptableVolume(Volume & minimum_acceptable_volume) const;

    bool HasCapacity() const;
    bool GetCapacity(OrderCapacity & capacity) const;

    bool HasParticipationPolicy() const;
    bool GetParticipationPolicy(ParticipationPolicy & policy) const;

    bool HasExchangeCreatedDatetime() const;
    bool GetExchangeCreatedDatetime(DateTime & exchange_created_datetime) const;

    bool HasExchangeModifiedDatetime() const;
    bool GetExchangeModifiedDatetime(DateTime & exchange_modified_datetime) const;

    bool HasStrategyPath() const;
    void GetStrategyPath(std::vector<StrategyIdentifier> & path) const;

    bool HasStrategyDefinitionPath() const;
    void GetStrategyDefinitionPath(std::vector<StrategyIdentifier> & path) const;

    bool HasPricePolicy() const;
    bool GetPricePolicy(PricePolicy & policy) const;

    bool HasValidity() const;
    bool GetValidity(Validity & validity) const;

    bool HasRegulatoryParameters() const;
    bool GetRegulatoryParameters(RegulatoryParameters & parameters) const;

    bool HasLastTradeIdentifier() const;
    bool GetLastTradeIdentifier(TradeIdentifier & trade_identifier) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLiquidityPool() const;

    /**
     * Get liquidity pool identifier.
     *
     * @param                           Returned liquidity pool identifier
     * @return                          True if client is set, false otherwise.
     */
    bool GetLiquidityPool(LiquidityPoolIdentifier & identifier) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandler() const;

    /**
     * Node in tree that represent the managing entity of strategy and/or orders.
     *
     * @param                           Returned handler
     * @return                          True if handler is set, false otherwise.
     */
    bool GetHandler(TreeNodeIdentifier & handler) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasClient() const;

    /**
     * Node in a tree that represent the managed entity for a strategy and/or orders.
     *
     * @param                           Returned client
     * @return                          True if client is set, false otherwise.
     */
    bool GetClient(TreeNodeIdentifier & client) const;

    /**
     * Check if field is set.
     *
     * @return                          True if currency is set, false otherwise.
     */
    bool HasCurrency() const;

    /**
     * Get currency.
     *
     * @param                           Returned currency
     * @return                          True if currency is set, false otherwise.
     */
    bool GetCurrency(Currency & currency) const;

    bool HasDealtCurrency() const;
    bool GetDealtCurrency(Currency & currency) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExPitIdentifier() const;

    /**
     * Get ExPit identifier
     *
     * @param                           Returned ExPit identifier
     * @return                          True if field is set, false otherwise
     */
    bool GetExPitIdentifier(ExPitIdentifier & id) const;

    /**
     * Get warmup option.
     *
     * @return                          Warmup option
     */
    bool GetWarmup() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOrderModify() const;

    /**
     * Get modify request
     *
     * @param value                     Returned order modify request
     * @return                          True if field is set, false otherwise
     */
    bool GetOrderModify(Order::Modify & value) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasQuoteMode() const;

    /**
     * Get quote mode
     *
     * @param                           Returned quote mode
     * @return                          True if field is set, false otherwise
     */
    bool GetQuoteMode(QuoteMode & value) const;

    /**
     * Check if field is set.
     *
     * @deprecated Deprecated in 2.12.0.
     *             Use HasQuoteMode() instead.
     *
     * @return                          True if field is set, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasType() const;

    /**
     * Get order type
     *
     * @deprecated Deprecated in 2.12.0.
     *             Use GetMode() instead.
     *
     * @param                           Returned order type
     * @return                          True if field is set, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetType(Type & value) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set (even if set empty field),
     *                                  false if field does not set
     */
    bool HasPegPriceType() const;

    /**
     * Get peg price type
     *
     * @param                           Returned peg price type
     * @return                          True if field is set (even if set empty field),
     *                                  false if field does not set
     */
    bool GetPegPriceType(std::optional<PegPriceType> & value) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set (even if set empty field),
     *                                  false if field does not set
     */
    bool HasCFI() const;

    /**
     * Get peg price type
     *
     * @param[out]                      Returned CFI
     * @return                          True if field is set (even if set empty field),
     *                                  false if field does not set
     */
    bool GetCFI(CFI & cfi) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeDepthIdentifier() const;

    /**
     * Get venue-specific identifier of depth entry.
     * On quote-driven venues (typically FX) this identifier must be passed when sending
     * an order to trade that depth entry.
     *
     * @param                           Returned exchange depth identifier
     * @return                          True if field is set, false otherwise
     */
    bool GetExchangeDepthIdentifier(String & value) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUnsolicited() const;

    /**
     * Get unsolicited.
     *
     * @return                          Unsolicited
     */
    bool GetUnsolicited(Boolean & unsolicited) const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOrderTemplateIdentifier() const;

    /**
     * Get order template identifier if order was created from template
     *
     * @param                           Returned order template identifier
     * @return                          True if field is set, false otherwise
     */
    bool GetOrderTemplateIdentifier(OrderTemplateIdentifier & value) const;

private:
    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, Order::Type value);

private:
    const protocol::Order & m_order_update;
};

/**
 * Order::Modify class can be used in Matching Engine.
 */
class STRATEGY_EXPORT Order::Modify : public OrderModifyBase
{
public:
    Modify();
    Modify(protocol::OrderModifyRequest * value);
    ~Modify();

    using OrderModifyBase::OrderModifyBase;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolumeDelta() const;

    /**
     * Get volume delta
     *
     * @return                          volume (with delta value and total type)
     */
    Volume GetVolumeDelta() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasValidity() const;

    /**
     * Get validity
     *
     * @return                          validity
     */
    Validity GetValidity() const;
};
}

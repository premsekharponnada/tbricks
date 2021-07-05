#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Trade modification API.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/User.h"
#include "strategy/Types.h"
#include "strategy/ExtraData.h"
#include "strategy/TradeParameters.h"
#include "strategy/type/UniqueTradeIdentifier.h"
#include "strategy/RegulatoryParameters.h"

namespace tbricks {

namespace protocol {
class TradeModify;
}

/**
 * TradeModifier defines a set of values that could be applied to a trade
 * instance with TradeModifier::SendModifyRequest call.
 *
 * TradeModifier fields reflect those available for modification in
 * tbricks::Trade object, please refer to its documentation for more
 * information.
 *
 * @see Trade
 * @see TradeModifier::SendModifyRequest
 */
class STRATEGY_EXPORT TradeModifier : public Printable
{
public:
    TradeModifier(const TradeIdentifier & id);
    TradeModifier(const String & trading_service_id);
    TradeModifier(const TradeModifier & modifier);
    TradeModifier & operator=(const TradeModifier & modifier);
    virtual ~TradeModifier();

    bool Empty() const;
    void Clear();

    bool HasCurrency() const;
    void SetCurrency(const Currency & currency);
    void ClearCurrency();
    Currency GetCurrency() const;

    bool HasCounterCurrency() const;
    void SetCounterCurrency(const Currency & currency);
    void ClearCounterCurrency();
    Currency GetCounterCurrency() const;

    bool HasCounterpart() const;
    void SetCounterpart(const String & counterpart);
    String GetCounterpart() const;

    bool HasCounterpartIdentifier() const;
    void SetCounterpartIdentifier(const TreeNodeIdentifier & counterpart);
    TreeNodeIdentifier GetCounterpartIdentifier() const;

    bool HasExtraData() const;
    void SetExtraData(const ExtraData & rparams);
    ExtraData GetExtraData() const;

    bool HasTradeParameters() const;
    void SetTradeParameters(const TradeParameters & data);
    TradeParameters GetTradeParameters() const;

    bool HasOwner() const;
    void SetOwner(const UserIdentifier & owner);
    void SetOwner(const User & owner);
    UserIdentifier GetOwner() const;
    bool GetOwner(User & user) const;

    bool HasPortfolioIdentifier() const;
    void SetPortfolioIdentifier(const PortfolioIdentifier & id);
    PortfolioIdentifier GetPortfolioIdentifier() const;

    bool HasPrice() const;
    void SetPrice(const Price & price);
    Price GetPrice() const;

    bool HasSettlementDate() const;
    void SetSettlementDate(const DateTime & datetime);
    DateTime GetSettlementDate() const;

    bool HasExchangeCreatedDatetime() const;
    void SetExchangeCreatedDatetime(const DateTime & datetime);
    DateTime GetExchangeCreatedDatetime() const;

    bool HasSide() const;
    void SetSide(const Side & side);
    Side GetSide() const;

    bool HasStrategyIdentifier() const;
    void SetStrategyIdentifier(const StrategyIdentifier & id);
    StrategyIdentifier GetStrategyIdentifier() const;

    TradeIdentifier GetTradeIdentifier() const;
    String GetTradingServiceTradeIdentifier() const;

    bool HasVolume() const;
    void SetVolume(const Volume & volume);
    Volume GetVolume() const;

    bool HasGrossTradeAmount() const;
    void SetGrossTradeAmount(const Double & value);
    Double GetGrossTradeAmount() const;

    bool HasFee() const;
    void SetFee(const Double & fee);
    Double GetFee() const;

    bool HasFeeCurrency() const;
    void SetFeeCurrency(const Currency & currency);
    Currency GetFeeCurrency() const;

    bool HasDeleted() const;
    void SetDeleted(const Boolean & is_deleted);
    Boolean GetDeleted() const;

    bool HasComment() const;
    void SetComment(const String & comment);
    String GetComment() const;

    bool HasHandler() const;
    void SetHandler(const TreeNodeIdentifier & handler);
    TreeNodeIdentifier GetHandler() const;

    bool HasClient() const;
    void SetClient(const TreeNodeIdentifier & client);
    TreeNodeIdentifier GetClient() const;

    /**
     * Resolve short codes
     *
     * Client and regulatory parameters fields must be setted before this call
     *
     */
    bool ResolveShortCodes(const UserIdentifier & execution_decision_user, const UserIdentifier & investment_decision_user);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasLiquidityIndicator() const;

    /**
     * %Set liquidity indicator.
     *
     * @param value                     New value
     */
    void SetLiquidityIndicator(const LiquidityIndicator & value);

    /**
     * Get liquidity indicator.
     *
     * @return                          Liquidity indicator value
     */
    LiquidityIndicator GetLiquidityIndicator() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false" otherwise
     */
    bool HasLiquidityPool() const;

    /**
     * %Set liquidity pool identifier.
     *
     * @param value                     New value
     */
    void SetLiquidityPool(const LiquidityPoolIdentifier & value);

    /**
     * Get liquidity pool identifier.
     *
     * @return                          Liquidity pool identifier value
     */
    LiquidityPoolIdentifier GetLiquidityPool() const;

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
     * If UTI argument does not valid, an exception is thrown.
     *
     */
    void SetUniqueTradeIdentifier(const UniqueTradeIdentifier & uti);

    /**
     * Get UTI.
     *
     */
    UniqueTradeIdentifier GetUniqueTradeIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasOrderCapacity() const;

    /**
     * Set order capacity
     *
     * @param                           order capacity
     */
    void SetOrderCapacity(const OrderCapacity & capacity);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasCashFlows() const;

    /**
     * Get cash flows.
     *
     * @return                          vector of cash flow
     */
    std::vector<CashFlow> GetCashFlows() const;

    /**
     * %Set cash flows.
     *
     * @param                           vector of cash flow
     */
    void SetCashFlows(const std::vector<CashFlow> & value) const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasExecutionPolicy() const;

    /**
     * Set execution policy.
     *
     * @param                           Execution policy
     */
    void SetExecutionPolicy(const ExecutionPolicy & value);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasRegulatoryParameters() const;

    /**
     * Set regulatory audit parameters.
     *
     * @param status_text               Regulatory parameters
     */
    void SetRegulatoryParameters(const RegulatoryParameters & params);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasMMTFlags() const;

    /**
     * %Set market model typology.
     *
     * @param id                        Market model typology
     */
    void SetMMTFlags(const MMTFlags & mmt);

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasAccrued() const;

    /**
     * Set accrued interest paid.
     *
     * @param                           accrued
     */
    void SetAccrued(const Double & value);

    /**
     * Get accrued interest paid.
     *
     * @return                          accrued
     */
    Double GetAccrued() const;

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    TradeModifier(const protocol::TradeModify & modifier);

private:
    friend class Trade;

private:
    std::unique_ptr<protocol::TradeModify> m_modifier;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeAttributes
//****************************************************************************************

#include "strategy/Exceptions.h"
#include "strategy/type/LiquidityIndicator.h"
#include "strategy/type/LiquidityPoolIdentifier.h"
#include "strategy/type/MMTFlags.h"
#include "strategy/type/Currency.h"
#include "strategy/type/UniqueTradeIdentifier.h"
#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/type/TradeType.h"
#include "strategy/TradeParameters.h"
#include "strategy/ExtraData.h"
#include "strategy/CashFlow.h"
#include "strategy/Linkage.h"
#include <assert.h>

namespace tbricks {

class STRATEGY_EXPORT TradeAttributes
{
private:
    class Impl;

    Impl * m_impl;

public:
    TradeAttributes();
    TradeAttributes(const TradeAttributes & src);
    TradeAttributes(TradeAttributes && src);
    TradeAttributes & operator=(const TradeAttributes & src);
    TradeAttributes & operator=(TradeAttributes && src);
    ~TradeAttributes();

    /**
     * Clear container.
     * Can be called by the application logic to reset the state of the
     * container to the state as it would be just constructed.
     *
     * <p> After this call container is guaranteed to contain no data,
     * and <code>Empty()</code> method will return <code>true</code> if called,
     * all <code>Has*()</code> methods return <code>false</code>.
     *
     * <p> The internal implementation allocates a block of memory on
     * construction large enough to keep all attributes using placement
     * construction/destruction. The memory block is not freed, but
     * all attributes previously set are destructed, so it would be wrong
     * to assume the cleared object memory usage is close to 0.
     *
     * <p> Method will be called by the <code>destructor</code>.
     */
    void Clear();

    bool HasLiquidityIndicator() const;
    void SetLiquidityIndicator(const LiquidityIndicator &);
    const LiquidityIndicator & GetLiquidityIndicator() const;

    bool HasLiquidityPoolIdentifier() const;
    void SetLiquidityPoolIdentifier(const LiquidityPoolIdentifier &);
    const LiquidityPoolIdentifier & GetLiquidityPoolIdentifier() const;

    bool HasMMTFlags() const;
    void SetMMTFlags(const MMTFlags &);
    const MMTFlags & GetMMTFlags() const;

    bool HasCurrency() const;
    void SetCurrency(const Currency & currency);
    const Currency & GetCurrency() const;

    bool HasCounterCurrency() const;
    void SetCounterCurrency(const Currency &);
    const Currency & GetCounterCurrency() const;

    bool HasBusinessDate() const;
    void SetBusinessDate(const Date &);
    const Date & GetBusinessDate() const;

    bool HasSettlementDate() const;
    void SetSettlementDate(const DateTime &);
    const DateTime & GetSettlementDate() const;

    bool HasGrossTradeAmount() const;
    void SetGrossTradeAmount(const Double &);
    const Double & GetGrossTradeAmount() const;

    bool HasExtraData() const;
    void SetExtraData(const ExtraData &);
    void SetExtraData(ExtraData &&);
    const ExtraData & GetExtraData() const;

    bool HasUniqueTradeIdentifier() const;
    void SetUniqueTradeIdentifier(const UniqueTradeIdentifier & uti);
    const UniqueTradeIdentifier & GetUniqueTradeIdentifier() const;

    bool HasCashFlows() const;
    void SetCashFlows(const std::vector<CashFlow> &);
    const std::vector<CashFlow> & GetCashFlows() const;

    bool HasCounterpart() const;
    void SetCounterpart(const String &);
    const String & GetCounterpart() const;

    bool HasPortfolioIdentifier() const;
    void SetPortfolioIdentifier(const PortfolioIdentifier & id);
    const PortfolioIdentifier & GetPortfolioIdentifier() const;

    bool HasTradeParameters() const;
    void SetTradeParameters(const TradeParameters & parameters);
    void SetTradeParameters(TradeParameters && parameters);
    const TradeParameters & GetTradeParameters() const;
};

} /* namespace tbricks */

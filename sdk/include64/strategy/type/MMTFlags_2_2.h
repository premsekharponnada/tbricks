#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Market Model Typology version 2.2.
//****************************************************************************************

#include "strategy/type/MMTFlags.h"

namespace tbricks {
namespace types {
class MMTFlags;
}

//****************************************************************************
// MMTFlags_2_2 Class
//****************************************************************************

/**
 * MMTFlags_2_2  Market Model Typology flags version 2.2.
 * See MMTFlags
 */
class STRATEGY_EXPORT MMTFlags_2_2
{
public:
    MMTFlags_2_2();
    MMTFlags_2_2(const MMTFlags_2_2 & other);
    MMTFlags_2_2 & operator=(const MMTFlags_2_2 & other) noexcept;

    MMTFlags_2_2(MMTFlags_2_2 && other) noexcept;
    MMTFlags_2_2 & operator=(MMTFlags_2_2 && other) noexcept;

    ~MMTFlags_2_2();

    operator MMTFlags() const;
    MMTFlags GetFlags() const;

    enum MarketMechanism : char
    {
        CentralLimitOrderBook = '1',
        QuoteDrivenMarket = '2',
        DarkOrderBook = '3',
        OffBook = '4',
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
        TradeReportingSystematicInternalizer = '7'
    };

    enum TransactionCategory : char
    {
        PlainVanillaTrade = 'P',
        DarkTrade = 'D',
        TechnicalTrade = 'T',
        GiveUpGiveInTrade = 'G',
        TradeWithConditions = 'F',
    };

    enum NegotiatedTransactionIndicator : char
    {
        NegotiatedTrade = 'N',
        NoNegotiatedTrade = '-'
    };

    enum CrossingTradeIndicator : char
    {
        CrossingTrade = 'X',
        NoCrossingTrade = '-'
    };

    enum ModificationIndicator : char
    {
        TradeCancellation = 'C',
        TradeAmendment = 'A',
        NewTrade = '-'
    };

    enum BenchmarkIndicator : char
    {
        BenchmarkTrade = 'B',
        NoBenchmarkTrade = '-'
    };

    enum ExCumDividendIndicator : char
    {
        ExCumDividendTrade = 'E',
        NoExCumDividendTrade = '-'
    };

    enum OffBookAutomatedIndicator : char
    {
        UnspecifiedOrDoesNotApply = '-',
        OffBookNonAutomated = 'M',
        OffBookAutomated = 'Q'
    };

    enum PublicationMode : char
    {
        ImmediatePublication = '-',
        NonImmediatePublication = '1'
    };

    MMTFlags_2_2 & SetMarketMechanism(MarketMechanism flag);
    MMTFlags_2_2 & SetTradingMode(TradingMode flag);
    MMTFlags_2_2 & SetTransactionCategory(TransactionCategory flag);
    MMTFlags_2_2 & SetNegotiatedTransactionIndicator(NegotiatedTransactionIndicator flag);
    MMTFlags_2_2 & SetCrossingTradeIndicator(CrossingTradeIndicator flag);
    MMTFlags_2_2 & SetModificationIndicator(ModificationIndicator flag);
    MMTFlags_2_2 & SetBenchmarkIndicator(BenchmarkIndicator flag);
    MMTFlags_2_2 & SetExCumDividendIndicator(ExCumDividendIndicator flag);
    MMTFlags_2_2 & SetOffBookAutomatedIndicator(OffBookAutomatedIndicator flag);
    MMTFlags_2_2 & SetPublicationMode(PublicationMode flag);

private:
    std::unique_ptr<types::MMTFlags> m_impl;
};

} // \namespace tbricks

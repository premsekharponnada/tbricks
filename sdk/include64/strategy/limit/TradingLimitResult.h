#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingLimitResult
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/limit/TradingLimitRule.h"

namespace tbricks {

namespace protocol {
class LimitResult;
}

class STRATEGY_EXPORT TradingLimitResult : public Printable
{
public:
    enum LimitBreachType
    {
        LIMIT_BREACH_TYPE_EMPTY = 0,
        LIMIT_BREACH_TYPE_VOLUME = 1,
        LIMIT_BREACH_TYPE_PRICE_MAX = 2,
        LIMIT_BREACH_TYPE_PRICE_MIN = 3,
        LIMIT_BREACH_TYPE_CASH_VALUE = 4,
        LIMIT_BREACH_TYPE_AT_MARKET_VOLUME = 5,
        LIMIT_BREACH_TYPE_SOFT_VOLUME = 6,
        LIMIT_BREACH_TYPE_SOFT_PRICE_MAX = 7,
        LIMIT_BREACH_TYPE_SOFT_PRICE_MIN = 8,
        LIMIT_BREACH_TYPE_SOFT_CASH_VALUE = 9,
        LIMIT_BREACH_TYPE_THROUGHPUT = 10,
        LIMIT_BREACH_TYPE_AGGREGATED_VOLUME = 11,
        LIMIT_BREACH_TYPE_AGGREGATED_CASH = 12,
        LIMIT_BREACH_TYPE_AGGREGATED_NET_CASH = 13,
        LIMIT_BREACH_TYPE_FLOW_ENGINE = 14
    };

public:
    TradingLimitResult();
    TradingLimitResult(const TradingLimitResult & result);
    TradingLimitResult(const protocol::LimitResult & result);
    TradingLimitResult & operator=(const TradingLimitResult & result);
    TradingLimitResult & operator=(const protocol::LimitResult & result);
    virtual ~TradingLimitResult();

    LimitBreachType GetLimitBreachType() const;
    void GetLimitBreachType(LimitBreachType type);

    Price GetPrice() const;
    void SetPrice(const Price & price);

    Volume GetVolume() const;
    void SetVolume(const Volume & volume);

    Double GetCashValue() const;
    void SetCashValue(const Double & cash);

    bool HasStrategyIdentifier() const;
    StrategyIdentifier GetStrategyIdentifier() const;
    void SetStrategyIdentifier(const StrategyIdentifier & strategy_id);

    bool HasTradingLimitRule() const;
    bool GetTradingLimitRule(TradingLimitRule & rule) const;
    void SetTradingLimitRule(const TradingLimitRule & rule);

    bool Empty() const;
    void Clear();

public:
    bool operator==(const TradingLimitResult & value) const;
    bool operator!=(const TradingLimitResult & value) const;

public:
    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const LimitBreachType & breach_type);
    virtual std::ostream & Print(std::ostream & strm) const;

    const tbricks::protocol::LimitResult * get() const;

private:
    tbricks::protocol::LimitResult * m_result;
};
}

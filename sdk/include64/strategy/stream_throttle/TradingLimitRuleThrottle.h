#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BestPrice message throttle filters
//****************************************************************************************

#include "strategy/stream_throttle/CommonThrottle.h"

namespace tbricks {

class STRATEGY_EXPORT TradingLimitRuleThrottle : public Throttle
{
public:
    TradingLimitRuleThrottle();
    TradingLimitRuleThrottle(const TradingLimitRuleThrottle & throttle);
    TradingLimitRuleThrottle(const CommonThrottle & throttle);

    TradingLimitRuleThrottle & operator=(const TradingLimitRuleThrottle & throttle);
    TradingLimitRuleThrottle & operator|=(const TradingLimitRuleThrottle & throttle);
    TradingLimitRuleThrottle operator||(const TradingLimitRuleThrottle & throttle) const;
    TradingLimitRuleThrottle & operator|=(const CommonThrottle & throttle);
    TradingLimitRuleThrottle operator||(const CommonThrottle & throttle) const;
};

inline TradingLimitRuleThrottle operator||(const CommonThrottle & cmn_throttle, const TradingLimitRuleThrottle & tlr_throttle)
{
    return (tlr_throttle || cmn_throttle);
}

class STRATEGY_EXPORT AtMarketVolumeThrottle : public TradingLimitRuleThrottle
{
public:
    AtMarketVolumeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT MaxPriceThrottle : public TradingLimitRuleThrottle
{
public:
    MaxPriceThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT MinPriceThrottle : public TradingLimitRuleThrottle
{
public:
    MinPriceThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT ShortSellVolumeThrottle : public TradingLimitRuleThrottle
{
public:
    ShortSellVolumeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT SoftMaxPriceThrottle : public TradingLimitRuleThrottle
{
public:
    SoftMaxPriceThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT SoftMinPriceThrottle : public TradingLimitRuleThrottle
{
public:
    SoftMinPriceThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT SoftVolumeThrottle : public TradingLimitRuleThrottle
{
public:
    SoftVolumeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT VolumeThrottle : public TradingLimitRuleThrottle
{
public:
    VolumeThrottle(Throttle::ChangeType type, double value);
};
}

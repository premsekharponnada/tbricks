#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Statistics message throttle filters
//****************************************************************************************

#include "strategy/stream_throttle/CommonThrottle.h"

namespace tbricks {

class STRATEGY_EXPORT StatisticsThrottle : public Throttle
{
public:
    StatisticsThrottle();
    virtual ~StatisticsThrottle() {}
    StatisticsThrottle(const StatisticsThrottle & throttle);
    StatisticsThrottle(const CommonThrottle & throttle);

    StatisticsThrottle & operator=(const StatisticsThrottle & throttle);
    StatisticsThrottle & operator|=(const StatisticsThrottle & throttle);
    StatisticsThrottle operator||(const StatisticsThrottle & throttle) const;
    StatisticsThrottle & operator|=(const CommonThrottle & throttle);
    StatisticsThrottle operator||(const CommonThrottle & throttle) const;
};

inline StatisticsThrottle operator||(const CommonThrottle & cmn_throttle, const StatisticsThrottle & st_throttle)
{
    return (st_throttle || cmn_throttle);
}

class STRATEGY_EXPORT ClosingPriceChangeThrottle : public StatisticsThrottle
{
public:
    virtual ~ClosingPriceChangeThrottle() {}
    ClosingPriceChangeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT HighPriceChangeThrottle : public StatisticsThrottle
{
public:
    virtual ~HighPriceChangeThrottle() {}
    HighPriceChangeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT LastPriceChangeThrottle : public StatisticsThrottle
{
public:
    virtual ~LastPriceChangeThrottle() {}
    LastPriceChangeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT LastVolumeChangeThrottle : public StatisticsThrottle
{
public:
    virtual ~LastVolumeChangeThrottle() {}
    LastVolumeChangeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT LowPriceChangeThrottle : public StatisticsThrottle
{
public:
    virtual ~LowPriceChangeThrottle() {}
    LowPriceChangeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT OpeningPriceChangeThrottle : public StatisticsThrottle
{
public:
    virtual ~OpeningPriceChangeThrottle() {}
    OpeningPriceChangeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT TurnoverChangeThrottle : public StatisticsThrottle
{
public:
    virtual ~TurnoverChangeThrottle() {}
    TurnoverChangeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT TurnoverVolumeChangeThrottle : public StatisticsThrottle
{
public:
    virtual ~TurnoverVolumeChangeThrottle() {}
    TurnoverVolumeChangeThrottle(Throttle::ChangeType type, double value);
};
}

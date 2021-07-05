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

class STRATEGY_EXPORT BestPriceThrottle : public Throttle
{
public:
    BestPriceThrottle();
    BestPriceThrottle(const BestPriceThrottle & throttle);
    BestPriceThrottle(const CommonThrottle & throttle);

    BestPriceThrottle & operator=(const BestPriceThrottle & throttle);
    BestPriceThrottle & operator|=(const BestPriceThrottle & throttle);
    BestPriceThrottle operator||(const BestPriceThrottle & throttle) const;
    BestPriceThrottle & operator|=(const CommonThrottle & throttle);
    BestPriceThrottle operator||(const CommonThrottle & throttle) const;
};

inline BestPriceThrottle operator||(const CommonThrottle & cmn_throttle, const BestPriceThrottle & bp_throttle)
{
    return (bp_throttle || cmn_throttle);
}

class STRATEGY_EXPORT AskPriceChangeThrottle : public BestPriceThrottle
{
public:
    AskPriceChangeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT BidPriceChangeThrottle : public BestPriceThrottle
{
public:
    BidPriceChangeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT AskVolumeChangeThrottle : public BestPriceThrottle
{
public:
    AskVolumeChangeThrottle(Throttle::ChangeType type, double value);
};

class STRATEGY_EXPORT BidVolumeChangeThrottle : public BestPriceThrottle
{
public:
    BidVolumeChangeThrottle(Throttle::ChangeType type, double value);
};
}

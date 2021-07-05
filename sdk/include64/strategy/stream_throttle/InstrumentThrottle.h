#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument and instrument group throttle filters
//****************************************************************************************

#include "strategy/stream_throttle/CommonThrottle.h"

namespace tbricks {

class STRATEGY_EXPORT InstrumentThrottle : public Throttle
{
public:
    InstrumentThrottle();
    virtual ~InstrumentThrottle() {}
    InstrumentThrottle(const InstrumentThrottle & throttle);
    InstrumentThrottle(const CommonThrottle & throttle);

    InstrumentThrottle & operator=(const InstrumentThrottle & throttle);
    InstrumentThrottle & operator|=(const InstrumentThrottle & throttle);
    InstrumentThrottle operator||(const InstrumentThrottle & throttle) const;
    InstrumentThrottle & operator|=(const CommonThrottle & throttle);
    InstrumentThrottle operator||(const CommonThrottle & throttle) const;
};

class STRATEGY_EXPORT InstrumentGroupThrottle : public Throttle
{
public:
    InstrumentGroupThrottle();
    virtual ~InstrumentGroupThrottle() {}
    InstrumentGroupThrottle(const InstrumentGroupThrottle & throttle);
    InstrumentGroupThrottle(const CommonThrottle & throttle);

    InstrumentGroupThrottle & operator=(const InstrumentGroupThrottle & throttle);
    InstrumentGroupThrottle & operator|=(const InstrumentGroupThrottle & throttle);
    InstrumentGroupThrottle operator||(const InstrumentGroupThrottle & throttle) const;
    InstrumentGroupThrottle & operator|=(const CommonThrottle & throttle);
    InstrumentGroupThrottle operator||(const CommonThrottle & throttle) const;
};

inline InstrumentThrottle operator||(const CommonThrottle & cmn_throttle, const InstrumentThrottle & st_throttle)
{
    return (st_throttle || cmn_throttle);
}

inline InstrumentGroupThrottle operator||(const CommonThrottle & cmn_throttle, const InstrumentGroupThrottle & st_throttle)
{
    return (st_throttle || cmn_throttle);
}
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument parameters throttle filters
//****************************************************************************************

#include "strategy/instrument/InstrumentParameterDefinition.h"
#include "strategy/stream_throttle/ParametersThrottle.h"

namespace tbricks {

class STRATEGY_EXPORT InstrumentAggregateParametersThrottle : public ParametersThrottle
{
public:
    InstrumentAggregateParametersThrottle();
    InstrumentAggregateParametersThrottle(const InstrumentAggregateParametersThrottle & throttle);
    InstrumentAggregateParametersThrottle(const CommonThrottle & throttle);
    InstrumentAggregateParametersThrottle(const InstrumentParameterDefinition & definition, Throttle::ChangeType type, double value);

    InstrumentAggregateParametersThrottle & operator=(const InstrumentAggregateParametersThrottle & throttle);
    InstrumentAggregateParametersThrottle & operator|=(const InstrumentAggregateParametersThrottle & throttle);
    InstrumentAggregateParametersThrottle operator||(const InstrumentAggregateParametersThrottle & throttle) const;
    InstrumentAggregateParametersThrottle & operator|=(const CommonThrottle & throttle);
    InstrumentAggregateParametersThrottle operator||(const CommonThrottle & throttle) const;
};

class STRATEGY_EXPORT InstrumentGroupAggregateParametersThrottle : public ParametersThrottle
{
public:
    InstrumentGroupAggregateParametersThrottle();
    InstrumentGroupAggregateParametersThrottle(const InstrumentGroupAggregateParametersThrottle & throttle);
    InstrumentGroupAggregateParametersThrottle(const CommonThrottle & throttle);
    InstrumentGroupAggregateParametersThrottle(const InstrumentParameterDefinition & definition, Throttle::ChangeType type, double value);

    InstrumentGroupAggregateParametersThrottle & operator=(const InstrumentGroupAggregateParametersThrottle & throttle);
    InstrumentGroupAggregateParametersThrottle & operator|=(const InstrumentGroupAggregateParametersThrottle & throttle);
    InstrumentGroupAggregateParametersThrottle operator||(const InstrumentGroupAggregateParametersThrottle & throttle) const;
    InstrumentGroupAggregateParametersThrottle & operator|=(const CommonThrottle & throttle);
    InstrumentGroupAggregateParametersThrottle operator||(const CommonThrottle & throttle) const;
};

class STRATEGY_EXPORT InstrumentGroupParametersThrottle : public ParametersThrottle
{
public:
    InstrumentGroupParametersThrottle();
    InstrumentGroupParametersThrottle(const InstrumentGroupParametersThrottle & throttle);
    InstrumentGroupParametersThrottle(const CommonThrottle & throttle);
    InstrumentGroupParametersThrottle(const InstrumentParameterDefinition & definition, Throttle::ChangeType type, double value);

    InstrumentGroupParametersThrottle & operator=(const InstrumentGroupParametersThrottle & throttle);
    InstrumentGroupParametersThrottle & operator|=(const InstrumentGroupParametersThrottle & throttle);
    InstrumentGroupParametersThrottle operator||(const InstrumentGroupParametersThrottle & throttle) const;
    InstrumentGroupParametersThrottle & operator|=(const CommonThrottle & throttle);
    InstrumentGroupParametersThrottle operator||(const CommonThrottle & throttle) const;
};

class STRATEGY_EXPORT InstrumentParametersThrottle : public ParametersThrottle
{
public:
    InstrumentParametersThrottle();
    InstrumentParametersThrottle(const InstrumentParametersThrottle & throttle);
    InstrumentParametersThrottle(const CommonThrottle & throttle);
    InstrumentParametersThrottle(const InstrumentParameterDefinition & definition, Throttle::ChangeType type, double value);

    InstrumentParametersThrottle & operator=(const InstrumentParametersThrottle & throttle);
    InstrumentParametersThrottle & operator|=(const InstrumentParametersThrottle & throttle);
    InstrumentParametersThrottle operator||(const InstrumentParametersThrottle & throttle) const;
    InstrumentParametersThrottle & operator|=(const CommonThrottle & throttle);
    InstrumentParametersThrottle operator||(const CommonThrottle & throttle) const;
};

inline InstrumentAggregateParametersThrottle operator||(const CommonThrottle & cmn_throttle,
                                                        const InstrumentAggregateParametersThrottle & ins_throttle)
{
    return (ins_throttle || cmn_throttle);
}

inline InstrumentGroupAggregateParametersThrottle operator||(const CommonThrottle & cmn_throttle,
                                                             const InstrumentGroupAggregateParametersThrottle & ins_throttle)
{
    return (ins_throttle || cmn_throttle);
}

inline InstrumentGroupParametersThrottle operator||(const CommonThrottle & cmn_throttle, const InstrumentGroupParametersThrottle & ins_throttle)
{
    return (ins_throttle || cmn_throttle);
}

inline InstrumentParametersThrottle operator||(const CommonThrottle & cmn_throttle, const InstrumentParametersThrottle & ins_throttle)
{
    return (ins_throttle || cmn_throttle);
}
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualCalculationEngine is
// system virtual Calculation Engine.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/test/IVirtualService.h"
#include "strategy/limit/TradingLimitRule.h"

namespace tbricks { namespace test {
class LEImpl;

class STRATEGY_EXPORT VirtualLimitEngine : public IVirtualService
{
public:
    void UpdateLimitRule(const TradingLimitRule & rule);

    void InvalidateLimitRule(const TradingLimitRule & rule);

public:
    /**
     * VirtualCalculationEngine constructor,
     * can be called inside TestEngine only.
     */
    VirtualLimitEngine(LEImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualLimitEngine();

private:
    VirtualLimitEngine() = delete;
    VirtualLimitEngine(const VirtualLimitEngine &) = delete;
    VirtualLimitEngine & operator=(const VirtualLimitEngine &) = delete;
    LEImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks

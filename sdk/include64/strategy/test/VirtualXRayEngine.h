#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualXRayEngine is
// system virtual XRay Engine.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/test/IVirtualService.h"
#include "strategy/test/CalculatedPropertiesTableUpdate.h"

namespace tbricks { namespace test {
class XEImpl;

class STRATEGY_EXPORT VirtualXRayEngine : public IVirtualService
{
public:
    /**
     * Send CalculatedProperties to schedule
     * HandleCalculatedProperties() event on an app side.
     * Sending an empty update won't clean a cached calculated values.
     * To remove the values from cache, one need to prepare the update using RemoveValue method.
     *
     * @param update             CalculatedPropertiesTableUpdate update.
     */
    void UpdateCalculatedProperties(const CalculatedPropertiesTableUpdate & update);

public:
    /**
     * VirtualCalculationEngine constructor,
     * can be called inside TestEngine only.
     */
    VirtualXRayEngine(XEImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualXRayEngine();

private:
    VirtualXRayEngine() = delete;
    VirtualXRayEngine(const VirtualXRayEngine &) = delete;
    VirtualXRayEngine & operator=(const VirtualXRayEngine &) = delete;
    XEImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks

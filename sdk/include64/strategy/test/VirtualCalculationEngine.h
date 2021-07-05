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
#include "strategy/test/CalculatedValuesRequest.h"
#include "strategy/test/CalculatedInstrumentValuesTable.h"

namespace tbricks { namespace test {
class CEImpl;

class STRATEGY_EXPORT VirtualCalculationEngine : public IVirtualService
{
public:
    /**
     * Wait until a new calculated instrument values stream is opened.
     *
     * @return           CalculatedValuesRequest.
     */
    test::CalculatedValuesRequest WaitCalculatedValuesRequest();

    /**
     * Wait until a calculated instrument values stream is modified.
     *
     * @return           CalculatedValuesModifyRequest.
     */
    test::CalculatedValuesModifyRequest WaitCalculatedValuesModifyRequest();

    /**
     * Fill in CalculatedValuesUpdate.
     *
     * @param stream_id  Stream Identifier.
     *
     * @param value_id   Calculated Value Identifier.
     *
     * @param value      Value to update.
     */
    void UpdateCalculatedValues(const StreamIdentifier & stream_id, const CalculatedValueIdentifier & value_id, const TypeWithError & value);

    /**
     * Send calculated instrument values update.
     *
     * @param stream_id  Stream Identifier.
     */
    void Send(const StreamIdentifier & stream_id);

    /**
     * Send snapshot done to a stream.
     *
     * @param stream_id  Stream Identifier.
     */
    void SendSnapshotDone(const StreamIdentifier & stream_id);

    /**
     * Send modify snapshot done to a stream.
     *
     * @param stream_id  Stream Identifier.
     *
     * @param request_id Modify request identifier.
     */
    void SendModifySnapshotDone(const StreamIdentifier & stream_id, const Identifier & request_id);

    /**
     * Send CalculatedInstrumentValues to schedule
     * HandleCalculatedInstrumentValues() event on an app side.
     * Sending an empty update won't clean a cached calculated values.
     * To remove the values from cache, one need to prepare the update using RemoveValue method.
     *
     * @param update             CalculatedInstrumentValues update.
     */
    void UpdateCalculatedValues(const CalculatedInstrumentValuesTable & update);

    enum UpdateTypeValue
    {
        CalculatedValuesRequestType = 1,
        CalculatedValuesModifyRequestType = 2
    };

public:
    /**
     * VirtualCalculationEngine constructor,
     * can be called inside TestEngine only.
     */
    VirtualCalculationEngine(CEImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualCalculationEngine();

private:
    VirtualCalculationEngine() = delete;
    VirtualCalculationEngine(const VirtualCalculationEngine &) = delete;
    VirtualCalculationEngine & operator=(const VirtualCalculationEngine &) = delete;
    CEImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks

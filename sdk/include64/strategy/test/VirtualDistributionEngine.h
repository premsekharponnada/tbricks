#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualDistributionEngine is
// system virtual Calculation Engine.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/test/IVirtualService.h"
#include "strategy/test/DistributedValuesRequest.h"
#include "strategy/test/DistributedValuesTable.h"

#include "strategy/distributed_values/DistributedValueIdentification.h"

namespace tbricks::test {
class DEImpl;

class STRATEGY_EXPORT VirtualDistributionEngine : public IVirtualService
{
public:
    /**
     * Waits until distribution stream is open
     * Note! The methon should not be used if distributed values table update is set.
     *
     * @return identifier of the stream and the distributed values request
     */
    test::DistributedValuesRequest WaitDistributedValuesStreamOpenRequest();

    /**
     * Waits until the distribution stream is closed
     * Note! The methon should not be used if distributed values table update is set.
     *
     * @return Identifier of the stream
     */
    StreamIdentifier WaitDistributedValuesStreamCloseRequest();

    /**
     * Updates distributed values cache for the stream identifier passed
     *
     * @param stream_id  Stream identifier
     * @param value_id   Identifier of the distributed value
     * @param value      Value
     */
    void UpdateDistributedValues(const StreamIdentifier & stream_id, const DistributedValueIdentification & value_id, const AnyType & value);

    /**
     * Sends cached distributed values update to the stream
     *
     * @param stream_id Identifier of the stream for which the update should be sent
     */
    void Send(const StreamIdentifier & stream_id);

    /**
     * Sends snapshot done to the stream
     *
     * @param stream_id Identifier of the stream for which the snapshot done should be sent
     */
    void SendSnapshotDone(const StreamIdentifier & stream_id);

    /**
     * Assigns distributed values table to be a reply for all distributed values streams that are coming
     *
     * In that case Wait request methods should not be used
     *
     * @param update Distributed values table update
     */
    void UpdateDistributedValues(const DistributedValuesTable & update);

public:
    VirtualDistributionEngine(DEImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualDistributionEngine();

private:
    VirtualDistributionEngine() = delete;
    VirtualDistributionEngine(const VirtualDistributionEngine &) = delete;
    VirtualDistributionEngine & operator=(const VirtualDistributionEngine &) = delete;
    DEImpl * m_impl;
};

} // \namespace tbricks::test

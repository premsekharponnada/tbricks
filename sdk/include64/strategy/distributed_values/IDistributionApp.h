#pragma once
//****************************************************************************
// Tbricks Strategy Framework.
//
// Copyright (c) 2006-2017 Tbricks AB.
//
// Distribution app interface.
//
//****************************************************************************

#include "strategy/Linkage.h"

#include "strategy/distributed_values/DistributedValuesRequest.h"

namespace tbricks {

class STRATEGY_EXPORT IDistributionApp
{
public:
    IDistributionApp();
    virtual ~IDistributionApp();

public:
    virtual void HandleDistributedValuesRequest(const DistributedValuesRequest & request) = 0;
    void SendDistributedValuesReply(const DistributedValuesReply & reply);

    virtual void HandleDistributedValuesSubscription(const DistributedValuesRequest & request) = 0;

public:
    /**
     * Method updates discributed value in accumulated update to be distributed among subscribers
     */
    void Update(const DistributedValueIdentification & id, const AnyType & value);

    /**
     * Sends accumulated update to subscribers.
     */
    void Send();

    /**
     * Updates distributed values in accumulated snapshot data for the subscriber
     */
    void SnapshotUpdate(const DistributedValuesRequestIdentifier & request_id, const DistributedValueIdentification & id, const AnyType & value);

    /**
     * Sends accumulated snapshot message to subscriber followed by snapshot done indicator.
     */
    void SnapshotDone(const DistributedValuesRequestIdentifier & request_id);

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};
}

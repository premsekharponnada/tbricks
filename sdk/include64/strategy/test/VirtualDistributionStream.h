#pragma once

//****************************************************************************
// Tbricks Strategy Framework.
//
// Copyright (c) 2006-2017 Tbricks AB.
//
// TODO: Description here.
//
//****************************************************************************

#include "strategy/distributed_values/DistributedValues.h"
#include "strategy/test/DistributedValuesTable.h"
#include "strategy/test/DistributedValuesRequest.h"

namespace tbricks::test {

class DSImpl;

class STRATEGY_EXPORT VirtualDistributionStream final
{
public:
    VirtualDistributionStream();
    ~VirtualDistributionStream();

    VirtualDistributionStream(const VirtualDistributionStream &) = delete;
    VirtualDistributionStream & operator=(const VirtualDistributionStream &) = delete;

public:
    /**
     * Sends the request, that is corresponding to the options passed, to the distribution engine
     *
     * @param  options  Distributed values stream options
     */
    void Request(const DistributedValues::Stream::Options & options);

    /**
     * Opens the stream to the distributed engine if there is a de app that is able to handle the request
     *
     * @param  type  Type of the stream, SNAPSHOT or SNAPSHOT_AND_LIVE
     */
    void Open(Stream::Type type);

    /**
     * Closes the stream
     */
    void Close();

    /**
     * Waits until the Distributed values update is received
     *
     * @param  coalesced  if true the updates would be coalesced
     */
    DistributedValues::Update WaitDistributedValues(bool coalesced = false);

    /**
     * Waits until distributed values snapshot is received
     *
     * @return Distributed values update
     */
    DistributedValues::Update WaitDistributedValuesSnapshot();

    /**
     * Waits until distributed values snapshot is received
     */
    void WaitSnapshotEnd();

    /**
     * @return Stream identifier
     */
    StreamIdentifier GetStreamIdentifier() const;

private:
    DSImpl * m_impl;
};

} // \namespace tbricks::test

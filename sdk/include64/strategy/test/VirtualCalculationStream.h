#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Stream is used for calculation plugin initiation from test.
//****************************************************************************************

#include "strategy/pricing/CalculatedValuesRequest.h"
#include "strategy/instrument/CalculatedInstrumentValues.h"
#include "strategy/test/ExtraCalculatedInstrumentValuesOptions.h"

namespace tbricks { namespace test {
class CSImpl;

class STRATEGY_EXPORT VirtualCalculationStream
{
public:
    VirtualCalculationStream();
    ~VirtualCalculationStream();

public:
    /**
     * Open calculation stream to TestEngine.
     * It's initiating creation of calculation plugin.
     *
     * @param type           Stream type
     * @param options        Stream options
     * @param extra_options  Additional parameters for opening calculated values stream, that cannot be specified via
     * regular stream options
     */
    void Open(Stream::Type type,
              const CalculatedInstrumentValues::Stream::Options & options,
              const ExtraCalculatedInstrumentValuesOptions & extra_options = {});

    /**
     * Modify a stream with full update of stream options.
     *
     * @param options        Stream options
     */
    void Modify(const CalculatedInstrumentValues::Stream::Options & options);

    /**
     * Modify a stream with partial update of stream options.
     *
     * @param options        Partial update of stream options
     */
    void Modify(const CalculatedInstrumentValues::Stream::ModifyOptions & options);

    /**
     * Close calculation stream.
     */
    void Close();

    /**
     * Wait until update is sended and get update.
     * Recomended to use after receiving the snapshot.
     *
     * @param coalesced      Return coalesced update if true.
     *
     * @return               Update.
     */
    CalculatedInstrumentValues::Update WaitCalculatedInstrumentValues(bool coalesced = false);

    /**
     * Wait for stream snapshot and get coalesced update.
     * If update already taken with "WaitCalculatedInstrumentValues",
     * return value will be empty.
     *
     * @return               Update.
     */
    CalculatedInstrumentValues::Update WaitCalculatedInstrumentValuesSnapshot();

    /**
     * Wait for stream modify snapshot and get coalesced update.
     * If update already taken with "WaitCalculatedInstrumentValues",
     * return value will be empty.
     *
     * @return               Update.
     */
    CalculatedInstrumentValues::Update WaitCalculatedInstrumentValuesModifySnapshot();

    /**
     * Wait for stream snapshot.
     */
    void WaitSnapshotEnd();

    /**
     * Wait for stream modify snapshot.
     */
    void WaitModifySnapshotEnd();

    /**
     * Get stream identifier.
     */
    StreamIdentifier GetStreamIdentifier() const;

private:
    VirtualCalculationStream(const VirtualCalculationStream &) = delete;
    VirtualCalculationStream & operator=(const VirtualCalculationStream &) = delete;
    CSImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks

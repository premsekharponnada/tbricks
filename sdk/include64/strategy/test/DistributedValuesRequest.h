#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DistributedValuesRequest
//****************************************************************************************

#include "strategy/distributed_values/DistributedValuesRequest.h"
#include "strategy/type/StreamIdentifier.h"

namespace tbricks::test {

class STRATEGY_EXPORT DistributedValuesRequest : public tbricks::DistributedValuesRequest
{
public:
    DistributedValuesRequest() = delete;
    DistributedValuesRequest(const StreamIdentifier & stream_id);
    virtual ~DistributedValuesRequest();

    /**
     * @return Stream identifier
     */
    const StreamIdentifier GetStreamIdentifier() const { return m_stream_id; }

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StreamIdentifier m_stream_id;
};

} // \namespace tbricks::test

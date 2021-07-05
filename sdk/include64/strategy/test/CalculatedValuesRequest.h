#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CalculatedValuesRequest
//****************************************************************************************

#include "strategy/pricing/CalculatedValuesRequest.h"
#include "strategy/type/StreamIdentifier.h"

namespace tbricks { namespace test {

class STRATEGY_EXPORT CalculatedValuesRequest : public tbricks::CalculatedValuesRequest
{
public:
    CalculatedValuesRequest(const Uuid & stream_id);
    virtual ~CalculatedValuesRequest();

    const StreamIdentifier GetStreamId() const { return m_stream_id; }

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Uuid m_stream_id;
    CalculatedValuesRequest() = delete;
};

class STRATEGY_EXPORT CalculatedValuesModifyRequest : public tbricks::CalculatedValuesRequest
{
public:
    CalculatedValuesModifyRequest(const Uuid & stream_id, const Uuid & request_id);
    virtual ~CalculatedValuesModifyRequest();

    const StreamIdentifier GetStreamId() const { return m_stream_id; }
    const Identifier GetRequestId() const { return m_request_id; }

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Uuid m_stream_id;
    Uuid m_request_id;
    CalculatedValuesModifyRequest() = delete;
};

} // \namespace test
} // \namespace tbricks

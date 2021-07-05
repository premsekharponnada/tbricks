#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// LimitsWarmupRequest
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/stream/InstrumentStream.h"
#include "strategy/type/Identifier.h"

namespace tbricks {

class STRATEGY_EXPORT LimitsWarmupRequest : public Printable
{
public:
    using InstrumentFilter = InstrumentStream::Filters::Filter;

    LimitsWarmupRequest(const Identifier & request_id, const InstrumentFilter & filter);
    LimitsWarmupRequest(const LimitsWarmupRequest & request);
    virtual ~LimitsWarmupRequest();

    LimitsWarmupRequest & operator=(const LimitsWarmupRequest & request);

    const Identifier & GetIdentifier() const;
    const InstrumentFilter & GetFilter() const;

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_id;
    InstrumentFilter m_filter;
};
}

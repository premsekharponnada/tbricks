#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteRequestStreamOptions
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/directed_quoting/DirectedQuoteRequest.h"
#include "strategy/stream_filter/DirectedQuoteRequestFilter.h"

namespace tbricks {

class STRATEGY_EXPORT DirectedQuoteRequest::Stream::Options : public Printable
{
public:
    Options() = default;
    Options(const Options & o) = default;
    Options(Options && o) = default;

    Options & operator=(const Options & o) = default;
    Options & operator=(Options && o) = default;

public:
    void SetFilter(const DirectedQuoteRequest::Stream::Filters::Filter & filter) { m_filter = filter; }
    const DirectedQuoteRequest::Stream::Filters::Filter & GetFilter() const { return m_filter; }

    std::ostream & Print(std::ostream & strm) const override;

private:
    DirectedQuoteRequest::Stream::Filters::Filter m_filter;
};
}

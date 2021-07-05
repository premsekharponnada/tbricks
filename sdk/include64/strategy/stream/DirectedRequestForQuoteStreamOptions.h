#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedRequestForQuoteStreamOptions
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/directed_quoting/DirectedRequestForQuote.h"
#include "strategy/stream_filter/DirectedRequestForQuoteFilter.h"

namespace tbricks {

class STRATEGY_EXPORT DirectedRequestForQuote::Stream::Options : public Printable
{
public:
    Options() = default;
    Options(const Options & o) = default;
    Options(Options && o) = default;

    Options & operator=(const Options & o) = default;
    Options & operator=(Options && o) = default;

public:
    void SetFilter(const DirectedRequestForQuote::Stream::Filters::Filter & filter) { m_filter = filter; }
    const DirectedRequestForQuote::Stream::Filters::Filter & GetFilter() const { return m_filter; }

    std::ostream & Print(std::ostream & strm) const override;

private:
    DirectedRequestForQuote::Stream::Filters::Filter m_filter;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedRequestForQuote Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/TestDirectedRequestForQuoteOptionsBase.h"
#include "strategy/type/DirectedQuoteRequestIdentifier.h"

namespace tbricks { namespace test {

/**
 * DirectedRequestForQuoteOptions
 */
class STRATEGY_EXPORT DirectedRequestForQuoteOptions : public TestDirectedRequestForQuoteOptionsBase
{
public:
    DirectedQuoteRequestIdentifier GetQuoteRequestIdentifier() const;

public:
    DirectedRequestForQuoteOptions() = default;
    using TestDirectedRequestForQuoteOptionsBase::Merge;
    using TestDirectedRequestForQuoteOptionsBase::TestDirectedRequestForQuoteOptionsBase;
};

} // namespace test

} // namespace tbricks

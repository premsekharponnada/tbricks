#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteResponse .
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/TestDirectedQuoteResponseBase.h"

namespace tbricks { namespace test {

/**
 * DirectedQuoteResponse
 */
class STRATEGY_EXPORT DirectedQuoteResponse : public TestDirectedQuoteResponseBase
{
public:
    DirectedQuoteResponse() = default;
    using TestDirectedQuoteResponseBase::Merge;
    using TestDirectedQuoteResponseBase::TestDirectedQuoteResponseBase;
};

} // namespace test

} // namespace tbricks

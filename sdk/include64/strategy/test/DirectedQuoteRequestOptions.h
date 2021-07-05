#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteRequest Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/TestDirectedQuoteRequestOptionsBase.h"
#include "strategy_generated/TestDirectedQuoteRequestOperationBase.h"

namespace tbricks { namespace test {

/**
 * DirectedQuoteRequestOptions
 */
class STRATEGY_EXPORT DirectedQuoteRequestOptions : public TestDirectedQuoteRequestOptionsBase
{
public:
    DirectedQuoteRequestOptions() = default;
    using TestDirectedQuoteRequestOptionsBase::Merge;
    using TestDirectedQuoteRequestOptionsBase::TestDirectedQuoteRequestOptionsBase;
};

/**
 * DirectedQuoteRequestOperation
 */
class STRATEGY_EXPORT DirectedQuoteRequestOperation : public TestDirectedQuoteRequestOperationBase
{};

} // namespace test

} // namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForQuote Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/TestRequestForQuoteOptionsBase.h"
#include "strategy_generated/TestRequestForQuoteOperationBase.h"
#include "strategy/InstrumentVenueIdentification.h"

namespace tbricks { namespace test {

/**
 * RequestForQuoteOptions
 */
class STRATEGY_EXPORT RequestForQuoteOptions : public TestRequestForQuoteOptionsBase
{
public:
    RequestForQuoteOptions() = default;
    using TestRequestForQuoteOptionsBase::Merge;
    using TestRequestForQuoteOptionsBase::TestRequestForQuoteOptionsBase;

    bool HasInstrumentVenueIdentification() const;

    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;

    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);
};

/**
 * RequestForQuoteOperation
 */
class STRATEGY_EXPORT RequestForQuoteOperation : public TestRequestForQuoteOperationBase
{};

} // namespace test

} // namespace tbricks

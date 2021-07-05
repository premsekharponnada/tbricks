#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuote Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/TestDirectedQuoteOptionsBase.h"
#include "strategy_generated/TestDirectedQuoteOperationBase.h"
#include "strategy/directed_quoting/DirectedQuoteLeg.h"

namespace tbricks { namespace test {

/**
 * DirectedQuoteOptions
 */
class STRATEGY_EXPORT DirectedQuoteOptions : public TestDirectedQuoteOptionsBase
{
public:
    void SetDirectedQuoteIdentifier(const DirectedQuoteIdentifier &);
    void SetRequestIdentifier(const Identifier &);
    void SetAskPrice(const Price &);
    void SetAskVolume(const Volume &);

    void SetBidPrice(const Price &);
    void SetBidVolume(const Volume &);

    void SetLegs(const std::vector<DirectedQuoteLeg> &);

    void SetLiquidityPool(const LiquidityPoolIdentifier & pool_id);

public:
    DirectedQuoteOptions() = default;
    using TestDirectedQuoteOptionsBase::Merge;
    using TestDirectedQuoteOptionsBase::TestDirectedQuoteOptionsBase;
};

/**
 * DirectedQuoteOperation
 */
class STRATEGY_EXPORT DirectedQuoteOperation : public TestDirectedQuoteOperationBase
{};

} // namespace test

} // namespace tbricks

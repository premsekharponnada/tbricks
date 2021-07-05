#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForTrade Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/RequestForTrade.h"
#include "strategy_generated/TestRequestForTradeOptionsBase.h"
#include "strategy_generated/TestRequestForTradeOperationBase.h"

namespace tbricks {

namespace protocol {
class RequestForTrade;
}

namespace test {

class STRATEGY_EXPORT RequestForTradeOptions : public TestRequestForTradeOptionsBase
{
public:
    RequestForTradeOptions() = default;
    using TestRequestForTradeOptionsBase::Merge;
    using TestRequestForTradeOptionsBase::TestRequestForTradeOptionsBase;
};

/**
 * RequestForTradeOperation
 */
class STRATEGY_EXPORT RequestForTradeOperation : public TestRequestForTradeOperationBase
{};

} // \namespace test

} // \namespace tbricks

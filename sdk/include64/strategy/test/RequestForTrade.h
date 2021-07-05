#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForTrade.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/RequestForTradeBase.h"

namespace tbricks { namespace test {

/**
 * RequestForTrade
 */
class STRATEGY_EXPORT RequestForTrade : public RequestForTradeBase
{
public:
    RequestForTrade() = default;
    using RequestForTradeBase::RequestForTradeBase;
};

} // namespace test

} // namespace tbricks

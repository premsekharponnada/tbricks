#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PublicTrade.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/PublicTrade.h"
#include "strategy_generated/TestPublicTradeBase.h"

namespace tbricks {

namespace protocol {
class PublicTrade;
}

namespace test {

class STRATEGY_EXPORT PublicTrade : public TestPublicTradeBase
{
public:
    PublicTrade() = default;
    using TestPublicTradeBase::Merge;
    using TestPublicTradeBase::TestPublicTradeBase;
};

} // \namespace test

} // \namespace tbricks

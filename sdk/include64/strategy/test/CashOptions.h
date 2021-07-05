#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Cash Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Cash.h"
#include "strategy_generated/TestCashOptionsBase.h"

namespace tbricks {

namespace protocol {
class Cash;
}

namespace test {

class STRATEGY_EXPORT CashOptions : public TestCashOptionsBase
{
public:
    CashOptions() = default;
    using TestCashOptionsBase::Merge;
    using TestCashOptionsBase::TestCashOptionsBase;
};

} // \namespace test

} // \namespace tbricks

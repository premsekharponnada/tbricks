#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExpirationOld Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/ExpirationOld.h"
#include "strategy_generated/TestExpirationOldOptionsBase.h"
#include "strategy_generated/TestExpirationOldOperationBase.h"

namespace tbricks {

namespace protocol {
class Expiration;
}

namespace test {

class STRATEGY_EXPORT ExpirationOldOptions : public TestExpirationOldOptionsBase
{
public:
    ExpirationOldOptions() = default;
    using TestExpirationOldOptionsBase::Merge;
    using TestExpirationOldOptionsBase::TestExpirationOldOptionsBase;
};

/**
 * ExpirationOldOperation
 */
class STRATEGY_EXPORT ExpirationOldOperation : public TestExpirationOldOperationBase
{};

} // \namespace test

} // \namespace tbricks

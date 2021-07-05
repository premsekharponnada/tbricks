#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Expiration Options.
//****************************************************************************************

#include <vector>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Expiration.h"
#include "strategy_generated/TestExpirationOptionsBase.h"
#include "strategy/test/ExpirationDeliveryOperation.h"

namespace tbricks {

namespace protocol {
class Expiration2;
}

namespace test {

class STRATEGY_EXPORT ExpirationOptions : public TestExpirationOptionsBase
{
public:
    ExpirationOptions() = default;
    using TestExpirationOptionsBase::Merge;
    using TestExpirationOptionsBase::TestExpirationOptionsBase;

    /**
     *  Returns copies of the delivery operations held by the ExpirationOptions
     *  object, wrapped in an accessor class intended for test purposes.
     *
     *  @return A vector of wrappers for the delivery operations, holding
     *          copies of the operations.
     */
    std::vector<ExpirationDeliveryOperation> GetExpirationDeliveryOperations() const;
};

} // \namespace test

} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Expiration Delivery Operation.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy_generated/DeliveryOperationBase.h"

namespace tbricks {

namespace protocol {
class ExpirationDeliveryOperation;
}

namespace test {

class STRATEGY_EXPORT ExpirationDeliveryOperation : public DeliveryOperationBase
{
public:
    ExpirationDeliveryOperation() = default;
    using DeliveryOperationBase::DeliveryOperationBase;
};

} // \namespace test

} // \namespace tbricks

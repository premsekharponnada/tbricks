#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// User status.
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/Linkage.h"

#include "strategy/User.h"
#include "strategy_generated/UserStatusBase.h"

#include "strategy/type/String.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/Duration.h"

namespace tbricks {

/**
 * User::Status class, collection of user status.
 */
class STRATEGY_EXPORT User::Status : public UserStatusBase
{
public:
    class Stream;

public:
    Status() = default;
    using UserStatusBase::UserStatusBase;

public:
    User GetUser() const;
    bool Merge(const Status & update);
};
}

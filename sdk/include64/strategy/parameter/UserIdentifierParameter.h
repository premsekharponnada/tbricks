#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of UserIdentifier type.
//****************************************************************************************

#include "strategy/User.h"
#include "strategy/type/UserIdentifier.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT UserIdentifierParameter : public Parameter
{
public:
    using ValueType = UserIdentifier;

public:
    UserIdentifierParameter(const ParameterDefinition & definition);
    UserIdentifierParameter(const UserIdentifierParameter & parameter);

    UserIdentifierParameter & operator=(const UserIdentifier & value);
    UserIdentifierParameter & operator=(const UserIdentifierParameter & parameter);
    UserIdentifierParameter & operator=(const User & user);

    const UserIdentifier & GetUserIdentifier() const;
    operator const UserIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

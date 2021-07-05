#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Identifier type.
//****************************************************************************************

#include "strategy/type/Identifier.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT IdentifierParameter : public Parameter
{
public:
    using ValueType = Identifier;

public:
    IdentifierParameter(const ParameterDefinition & definition);
    IdentifierParameter(const IdentifierParameter & parameter);

    IdentifierParameter & operator=(const Identifier & value);
    IdentifierParameter & operator=(const IdentifierParameter & parameter);

    const Identifier & GetIdentifier() const;
    operator const Identifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

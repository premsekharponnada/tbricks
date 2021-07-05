#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of SubsystemIdentifier type.
//****************************************************************************************

#include "strategy/type/SubsystemIdentifier.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT SubsystemIdentifierParameter : public Parameter
{
public:
    using ValueType = SubsystemIdentifier;

public:
    SubsystemIdentifierParameter(const ParameterDefinition & definition);
    SubsystemIdentifierParameter(const SubsystemIdentifierParameter & parameter);

    SubsystemIdentifierParameter & operator=(const SubsystemIdentifier & value);
    SubsystemIdentifierParameter & operator=(const SubsystemIdentifierParameter & parameter);

    const SubsystemIdentifier & GetSubsystemIdentifier() const;
    operator const SubsystemIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of StrategyIdentifier type.
//****************************************************************************************

#include "strategy/type/StrategyIdentifier.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT StrategyIdentifierParameter : public Parameter
{
public:
    using ValueType = StrategyIdentifier;

public:
    StrategyIdentifierParameter(const ParameterDefinition & definition);
    StrategyIdentifierParameter(const StrategyIdentifierParameter & parameter);

    StrategyIdentifierParameter & operator=(const StrategyIdentifier & value);
    StrategyIdentifierParameter & operator=(const StrategyIdentifierParameter & parameter);

    const StrategyIdentifier & GetStrategyIdentifier() const;
    operator const StrategyIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

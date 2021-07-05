#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of LiquidityPoolIdentifier type.
//****************************************************************************************

#include "strategy/type/LiquidityPool.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT LiquidityPoolParameter : public Parameter
{
public:
    using ValueType = LiquidityPoolIdentifier;

public:
    LiquidityPoolParameter(const ParameterDefinition & definition);
    LiquidityPoolParameter(const LiquidityPoolParameter & parameter);

    LiquidityPoolParameter & operator=(const LiquidityPool & value);
    LiquidityPoolParameter & operator=(const LiquidityPoolIdentifier & value);
    LiquidityPoolParameter & operator=(const LiquidityPoolParameter & parameter);

    const LiquidityPoolIdentifier & GetLiquidityPool() const;
    operator const LiquidityPoolIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

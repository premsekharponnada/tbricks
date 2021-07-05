#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Integer type.
//****************************************************************************************

#include "strategy/type/Integer.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT IntegerParameter : public Parameter
{
public:
    using ValueType = Integer;

public:
    IntegerParameter(const ParameterDefinition & definition);
    IntegerParameter(const IntegerParameter & parameter);

    IntegerParameter & operator=(const Integer & value);
    IntegerParameter & operator=(const IntegerParameter & parameter);

    const Integer & GetInteger() const;
    operator const Integer &() const;

    IntegerParameter & operator+=(const Integer & value);
    IntegerParameter & operator+=(const IntegerParameter & parameter);

    IntegerParameter & operator-=(const Integer & value);
    IntegerParameter & operator-=(const IntegerParameter & parameter);

    bool GetParameter(const StrategyParameters::const_iterator & it);
    bool GetParameter(const StrategyParameters & parameters);

    void SetDefaultIncrement(int increment);
    /// 1.0 by default
    int GetDefaultIncrement() const;

    class Impl;

private:
    Impl * m_impl;
};

} // \namespace tbricks

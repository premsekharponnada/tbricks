#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Double type.
//****************************************************************************************

#include "strategy/type/Double.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT DoubleParameter : public Parameter
{
public:
    using ValueType = Double;

public:
    DoubleParameter(const ParameterDefinition & definition);
    DoubleParameter(const DoubleParameter & a_value);

    DoubleParameter & operator=(const Double & a_value);
    DoubleParameter & operator=(const DoubleParameter & a_value);

    const Double & GetDouble() const;
    operator const Double &() const;

    DoubleParameter & operator+=(const Double & a_value);
    DoubleParameter & operator+=(const DoubleParameter & a_value);

    DoubleParameter & operator-=(const Double & a_value);
    DoubleParameter & operator-=(const DoubleParameter & a_value);

    bool GetParameter(const StrategyParameters::const_iterator & it);
    bool GetParameter(const StrategyParameters & parameters);

    void SetDefaultIncrement(double default_tick);
    /// 0.01 by default
    double GetDefaultIncrement() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

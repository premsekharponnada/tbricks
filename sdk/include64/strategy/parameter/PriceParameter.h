#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Price type.
//****************************************************************************************

#include "strategy/type/Price.h"
#include "strategy/parameter/Parameter.h"

namespace tbricks {

class STRATEGY_EXPORT PriceParameter : public Parameter
{
public:
    using ValueType = Price;

public:
    PriceParameter(const ParameterDefinition & definition);
    PriceParameter(const PriceParameter & parameter);

    PriceParameter & operator=(const Price & price);
    PriceParameter & operator=(const PriceParameter & parameter);

    const Price & GetPrice() const;
    operator const Price &() const;

    PriceParameter & operator+=(const Price & price);
    PriceParameter & operator+=(const PriceParameter & parameter);

    PriceParameter & operator-=(const Price & price);
    PriceParameter & operator-=(const PriceParameter & parameter);

    bool GetParameter(const StrategyParameters & parameters);
    bool GetParameter(const StrategyParameters::const_iterator & it);

    void SetDefaultIncrement(double increment);
    /// 0.01 by default
    double GetDefaultIncrement() const;

    class Impl;

private:
    Impl * m_impl;
};
}

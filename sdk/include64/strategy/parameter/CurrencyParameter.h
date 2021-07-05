#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Currency type.
//****************************************************************************************

#include "strategy/type/Currency.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT CurrencyParameter : public Parameter
{
public:
    using ValueType = Currency;

public:
    CurrencyParameter(const ParameterDefinition & definition);
    CurrencyParameter(const CurrencyParameter & parameter);

    CurrencyParameter & operator=(const Currency & value);
    CurrencyParameter & operator=(const CurrencyParameter & parameter);

    const Currency & GetCurrency() const;
    operator const Currency &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

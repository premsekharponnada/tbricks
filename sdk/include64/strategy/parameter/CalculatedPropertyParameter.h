#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of CalculatedProperty type.
//****************************************************************************************

#include "strategy/calculated_property/CalculatedProperty.h"
#include "strategy/parameter/Parameter.h"

namespace tbricks {

class STRATEGY_EXPORT CalculatedPropertyParameter : public Parameter
{
public:
    using ValueType = CalculatedProperty;

public:
    CalculatedPropertyParameter(const ParameterDefinition & definition);
    CalculatedPropertyParameter(const CalculatedPropertyParameter & parameter);

    CalculatedPropertyParameter & operator=(const CalculatedProperty & value);
    CalculatedPropertyParameter & operator=(const CalculatedPropertyParameter & parameter);

    const CalculatedProperty & GetCalculatedProperty() const;
    operator const CalculatedProperty &() const;

    class Impl;

private:
    Impl * const m_impl;
};
}

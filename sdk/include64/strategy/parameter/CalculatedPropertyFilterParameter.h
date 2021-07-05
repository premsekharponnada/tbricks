#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of CalculatedPropertyFilter type.
//****************************************************************************************

#include "strategy/calculated_property/CalculatedPropertyFilter.h"
#include "strategy/parameter/Parameter.h"

namespace tbricks {

class STRATEGY_EXPORT CalculatedPropertyFilterParameter : public Parameter
{
public:
    using ValueType = CalculatedPropertyFilter;

public:
    CalculatedPropertyFilterParameter(const ParameterDefinition & definition);
    CalculatedPropertyFilterParameter(const CalculatedPropertyFilterParameter & parameter);

    CalculatedPropertyFilterParameter & operator=(const CalculatedPropertyFilter & value);
    CalculatedPropertyFilterParameter & operator=(const CalculatedPropertyFilterParameter & parameter);

    const CalculatedPropertyFilter & GetCalculatedPropertyFilter() const;
    operator const CalculatedPropertyFilter &() const;

    class Impl;

private:
    Impl * const m_impl;
};
}

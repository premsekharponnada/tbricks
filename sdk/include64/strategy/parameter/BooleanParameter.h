#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Boolean type.
//****************************************************************************************

#include "strategy/type/Boolean.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT BooleanParameter : public Parameter
{
public:
    using ValueType = Boolean;

public:
    BooleanParameter(const ParameterDefinition & definition);
    BooleanParameter(const BooleanParameter & parameter);

    BooleanParameter & operator=(const Boolean & value);
    BooleanParameter & operator=(const BooleanParameter & parameter);

    const Boolean & GetBoolean() const;
    operator const Boolean &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

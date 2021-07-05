#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Date type.
//****************************************************************************************

#include "strategy/type/Date.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT DateParameter : public Parameter
{
public:
    using ValueType = Date;

public:
    DateParameter(const ParameterDefinition & definition);
    DateParameter(const DateParameter & parameter);

    DateParameter & operator=(const Date & value);
    DateParameter & operator=(const DateParameter & parameter);

    const Date & GetDate() const;
    operator const Date &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

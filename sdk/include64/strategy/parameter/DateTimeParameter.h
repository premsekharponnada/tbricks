#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of DateTime type.
//****************************************************************************************

#include "strategy/type/DateTime.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT DateTimeParameter : public Parameter
{
public:
    using ValueType = DateTime;

public:
    DateTimeParameter(const ParameterDefinition & definition);
    DateTimeParameter(const DateTimeParameter & parameter);

    DateTimeParameter & operator=(const DateTime & value);
    DateTimeParameter & operator=(const DateTimeParameter & parameter);

    const DateTime & GetDateTime() const;
    operator const DateTime &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved..
//
// Parameter of Time type.
//****************************************************************************************

#include "strategy/type/Time.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT TimeParameter : public Parameter
{
public:
    using ValueType = Time;

public:
    TimeParameter(const ParameterDefinition & definition);
    TimeParameter(const TimeParameter & parameter);

    TimeParameter & operator=(const Time & value);
    TimeParameter & operator=(const TimeParameter & parameter);

    const Time & GetTime() const;
    operator const Time &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

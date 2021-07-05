#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Duration type.
//****************************************************************************************

#include "strategy/type/Duration.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT DurationParameter : public Parameter
{
public:
    using ValueType = Duration;

public:
    DurationParameter(const ParameterDefinition & definition);
    DurationParameter(const DurationParameter & parameter);

    DurationParameter & operator=(const Duration & value);
    DurationParameter & operator=(const DurationParameter & parameter);

    const Duration & GetDuration() const;
    operator const Duration &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of String type.
//****************************************************************************************

#include "strategy/type/String.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT StringParameter : public Parameter
{
public:
    using ValueType = String;

public:
    StringParameter(const ParameterDefinition & definition);
    StringParameter(const StringParameter & parameter);

    StringParameter & operator=(const String & value);
    StringParameter & operator=(const StringParameter & parameter);

    const String & GetString() const;
    operator const String &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

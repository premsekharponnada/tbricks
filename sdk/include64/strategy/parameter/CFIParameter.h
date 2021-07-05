#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of CFI type.
//****************************************************************************************

#include "strategy/type/CFI.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT CFIParameter : public Parameter
{
public:
    using ValueType = CFI;

public:
    CFIParameter(const ParameterDefinition & definition);
    CFIParameter(const CFIParameter & parameter);

    CFIParameter & operator=(const CFI & value);
    CFIParameter & operator=(const CFIParameter & parameter);

    const CFI & GetCFI() const;
    operator const CFI &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of CFI mask type.
//****************************************************************************************

#include "strategy/type/CFIMask.h"
#include "strategy/parameter/Parameter.h"

namespace tbricks {

class STRATEGY_EXPORT CFIMaskParameter : public Parameter
{
public:
    using ValueType = CFIMask;

public:
    CFIMaskParameter(const ParameterDefinition & definition);
    CFIMaskParameter(const CFIMaskParameter & parameter);

    CFIMaskParameter & operator=(const CFIMask & value);
    CFIMaskParameter & operator=(const CFIMaskParameter & parameter);

    const CFIMask & GetCFIMask() const;
    operator const CFIMask &() const;

    class Impl;

private:
    Impl * const m_impl;
};
}

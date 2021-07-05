#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of MIC type.
//****************************************************************************************

#include "strategy/type/MIC.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT MICParameter : public Parameter
{
public:
    using ValueType = MIC;

public:
    MICParameter(const ParameterDefinition & definition);
    MICParameter(const MICParameter & parameter);

    MICParameter & operator=(const MIC & value);
    MICParameter & operator=(const MICParameter & parameter);

    const MIC & GetMIC() const;
    operator const MIC &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

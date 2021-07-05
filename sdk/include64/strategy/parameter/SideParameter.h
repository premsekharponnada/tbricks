#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Side type.
//****************************************************************************************

#include "strategy/type/Side.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT SideParameter : public Parameter
{
public:
    using ValueType = Side;

public:
    SideParameter(const ParameterDefinition & definition);
    SideParameter(const SideParameter & parameter);

    SideParameter & operator=(const Side & value);
    SideParameter & operator=(const SideParameter & parameter);

    const Side & GetSide() const;
    operator const Side &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

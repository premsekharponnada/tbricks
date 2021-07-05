#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Binary type.
//****************************************************************************************

#include "strategy/type/Binary.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT BinaryParameter : public Parameter
{
public:
    using ValueType = Binary;

public:
    BinaryParameter(const ParameterDefinition & definition);
    BinaryParameter(const BinaryParameter & parameter);

    BinaryParameter & operator=(const Binary & value);
    BinaryParameter & operator=(const BinaryParameter & parameter);

    const Binary & GetBinary() const;
    operator const Binary &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

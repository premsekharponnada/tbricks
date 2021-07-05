#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of MMTFlagsParameter type.
//****************************************************************************************

#include "strategy/type/MMTFlags.h"
#include "strategy/parameter/Parameter.h"

namespace tbricks {

class STRATEGY_EXPORT MMTFlagsParameter : public Parameter
{
public:
    using ValueType = MMTFlags;

public:
    MMTFlagsParameter(const ParameterDefinition & definition);
    MMTFlagsParameter(const MMTFlagsParameter & parameter);

    MMTFlagsParameter & operator=(const MMTFlags & value);
    MMTFlagsParameter & operator=(const MMTFlagsParameter & parameter);

    const MMTFlags & GetMMTFlags() const;
    operator const MMTFlags &() const;

    class Impl;

private:
    Impl * const m_impl;
};
}

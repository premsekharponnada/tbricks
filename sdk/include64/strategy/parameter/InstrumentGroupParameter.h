#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of InstrumentGroup type.
//****************************************************************************************

#include "strategy/type/InstrumentGroup.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT InstrumentGroupParameter : public Parameter
{
public:
    using ValueType = InstrumentGroupIdentifier;

public:
    InstrumentGroupParameter(const ParameterDefinition & definition);
    InstrumentGroupParameter(const InstrumentGroupParameter & parameter);

    InstrumentGroupParameter & operator=(const InstrumentGroup & value);
    InstrumentGroupParameter & operator=(const InstrumentGroupIdentifier & value);
    InstrumentGroupParameter & operator=(const InstrumentGroupParameter & p);

    const InstrumentGroup & GetInstrumentGroup() const;
    const InstrumentGroupIdentifier & GetInstrumentGroupIdentifier() const;
    operator const InstrumentGroup &() const;

    class Impl;

private:
    Impl * const m_impl;
    mutable InstrumentGroup m_group;
};

} // \namespace tbricks

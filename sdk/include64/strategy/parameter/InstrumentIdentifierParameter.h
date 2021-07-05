#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of InstrumentIdentifier type.
//****************************************************************************************

#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT InstrumentIdentifierParameter : public Parameter
{
public:
    using ValueType = InstrumentIdentifier;

public:
    InstrumentIdentifierParameter(const ParameterDefinition & definition);
    InstrumentIdentifierParameter(const InstrumentIdentifierParameter & parameter);

    InstrumentIdentifierParameter & operator=(const InstrumentIdentifier & value);
    InstrumentIdentifierParameter & operator=(const InstrumentIdentifierParameter & parameter);

    const InstrumentIdentifier & GetInstrumentIdentifier() const;
    operator const InstrumentIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

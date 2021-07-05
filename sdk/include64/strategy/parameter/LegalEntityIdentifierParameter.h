#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of LegalEntityIdentifier type.
//****************************************************************************************

#include "strategy/type/LegalEntityIdentifier.h"
#include "strategy/parameter/Parameter.h"

namespace tbricks {

class STRATEGY_EXPORT LegalEntityIdentifierParameter : public Parameter
{
public:
    using ValueType = LegalEntityIdentifier;

public:
    LegalEntityIdentifierParameter(const ParameterDefinition & definition);
    LegalEntityIdentifierParameter(const LegalEntityIdentifierParameter & parameter);

    LegalEntityIdentifierParameter & operator=(const LegalEntityIdentifier & value);
    LegalEntityIdentifierParameter & operator=(const LegalEntityIdentifierParameter & parameter);

    const LegalEntityIdentifier & GetLegalEntityIdentifier() const;
    operator const LegalEntityIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of PublicTradeIdentifier type.
//****************************************************************************************

#include "strategy/type/PublicTradeIdentifier.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT PublicTradeIdentifierParameter : public Parameter
{
public:
    using ValueType = PublicTradeIdentifier;

public:
    PublicTradeIdentifierParameter(const ParameterDefinition & definition);
    PublicTradeIdentifierParameter(const PublicTradeIdentifierParameter & parameter);

    PublicTradeIdentifierParameter & operator=(const PublicTradeIdentifier & value);
    PublicTradeIdentifierParameter & operator=(const PublicTradeIdentifierParameter & parameter);

    const PublicTradeIdentifier & GetPublicTradeIdentifier() const;
    operator const PublicTradeIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

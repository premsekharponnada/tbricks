#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of TradeIdentifier type.
//****************************************************************************************

#include "strategy/type/TradeIdentifier.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT TradeIdentifierParameter : public Parameter
{
public:
    using ValueType = TradeIdentifier;

public:
    TradeIdentifierParameter(const ParameterDefinition & definition);
    TradeIdentifierParameter(const TradeIdentifierParameter & parameter);

    TradeIdentifierParameter & operator=(const TradeIdentifier & value);
    TradeIdentifierParameter & operator=(const TradeIdentifierParameter & parameter);

    const TradeIdentifier & GetTradeIdentifier() const;
    operator const TradeIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

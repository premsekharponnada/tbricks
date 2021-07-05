#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of PortfolioIdentifier type.
//****************************************************************************************

#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT PortfolioIdentifierParameter : public Parameter
{
public:
    using ValueType = PortfolioIdentifier;

public:
    PortfolioIdentifierParameter(const ParameterDefinition & definition);
    PortfolioIdentifierParameter(const PortfolioIdentifierParameter & parameter);

    PortfolioIdentifierParameter & operator=(const PortfolioIdentifier & value);
    PortfolioIdentifierParameter & operator=(const PortfolioIdentifierParameter & parameter);

    const PortfolioIdentifier & GetPortfolioIdentifier() const;
    operator const PortfolioIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

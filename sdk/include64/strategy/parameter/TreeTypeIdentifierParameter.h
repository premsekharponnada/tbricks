#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of TreeTypeIdentifier type.
//****************************************************************************************

#include "strategy/type/TreeTypeIdentifier.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT TreeTypeIdentifierParameter : public Parameter
{
public:
    using ValueType = TreeTypeIdentifier;

public:
    TreeTypeIdentifierParameter(const ParameterDefinition & definition);
    TreeTypeIdentifierParameter(const TreeTypeIdentifierParameter & parameter);

    TreeTypeIdentifierParameter & operator=(const TreeTypeIdentifier & value);
    TreeTypeIdentifierParameter & operator=(const TreeTypeIdentifierParameter & parameter);

    const TreeTypeIdentifier & GetTreeTypeIdentifier() const;
    operator const TreeTypeIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

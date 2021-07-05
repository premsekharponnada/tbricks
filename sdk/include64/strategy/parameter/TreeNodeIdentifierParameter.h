#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of TreeNodeIdentifier type.
//****************************************************************************************

#include "strategy/type/TreeNodeIdentifier.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT TreeNodeIdentifierParameter : public Parameter
{
public:
    using ValueType = TreeNodeIdentifier;

public:
    TreeNodeIdentifierParameter(const ParameterDefinition & definition);
    TreeNodeIdentifierParameter(const TreeNodeIdentifierParameter & parameter);

    TreeNodeIdentifierParameter & operator=(const TreeNodeIdentifier & value);
    TreeNodeIdentifierParameter & operator=(const TreeNodeIdentifierParameter & parameter);

    const TreeNodeIdentifier & GetTreeNodeIdentifier() const;
    operator const TreeNodeIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
};

} // \namespace tbricks

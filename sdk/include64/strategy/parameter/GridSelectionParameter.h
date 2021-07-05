#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of GridSelection type.
//****************************************************************************************

#include "strategy/calculated_property/GridSelection.h"
#include "strategy/parameter/Parameter.h"

namespace tbricks {

class STRATEGY_EXPORT GridSelectionParameter : public Parameter
{
public:
    using ValueType = GridSelection;

public:
    GridSelectionParameter(const ParameterDefinition & definition);
    GridSelectionParameter(const GridSelectionParameter & parameter);

    GridSelectionParameter & operator=(const GridSelection & value);
    GridSelectionParameter & operator=(const GridSelectionParameter & parameter);

    const GridSelection & GetGridSelection() const;
    operator const GridSelection &() const;

    class Impl;

private:
    Impl * const m_impl;
};
}

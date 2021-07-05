#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Market data parameter defintion.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/DefinitionBase.h"

namespace tbricks {

class STRATEGY_EXPORT MarketDataParameterDefinition : public DefinitionBase
{
public:
    MarketDataParameterDefinition(const Uuid & id) : DefinitionBase(id) {}

private:
    virtual bool resolve() const override;
};
}

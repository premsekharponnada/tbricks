#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Trade parameter defintion.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/DefinitionBase.h"

namespace tbricks {

class STRATEGY_EXPORT TradeParameterDefinition : public DefinitionBase
{
public:
    TradeParameterDefinition() = default;
    TradeParameterDefinition(const Uuid & id) : DefinitionBase(id) {}

private:
    virtual bool resolve() const override;
};
}

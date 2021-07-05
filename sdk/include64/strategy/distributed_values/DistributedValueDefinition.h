#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
//****************************************************************************************

#include "strategy/DefinitionBase.h"

namespace tbricks {

class STRATEGY_EXPORT DistributedValueDefinition : public DefinitionBase
{
public:
    DistributedValueDefinition() = default;
    DistributedValueDefinition(const Uuid & id) : DefinitionBase(id) {}

private:
    virtual bool resolve() const override;
};
}

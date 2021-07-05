#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument attribute defintion.
//
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/DefinitionBase.h"

namespace tbricks {

class STRATEGY_EXPORT InstrumentAttributeDefinition : public DefinitionBase
{
public:
    InstrumentAttributeDefinition() = default;
    InstrumentAttributeDefinition(const Uuid & id) : DefinitionBase(id) {}

    static void GetAllDefinitions(std::vector<InstrumentAttributeDefinition> & definitions);

private:
    virtual bool resolve() const override;
};
}

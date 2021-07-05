#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument parameter defintion.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/DefinitionBase.h"

namespace tbricks {

class STRATEGY_EXPORT InstrumentParameterDefinition : public DefinitionBase
{
public:
    InstrumentParameterDefinition() = default;
    InstrumentParameterDefinition(const Uuid & id) : DefinitionBase(id) {}

    static void GetAllDefinitions(std::vector<InstrumentParameterDefinition> & definitions);

private:
    virtual bool resolve() const override;
};
}

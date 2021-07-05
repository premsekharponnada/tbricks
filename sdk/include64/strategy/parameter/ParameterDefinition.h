#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter defintion.
//****************************************************************************************

#include <string>

#include "strategy/Linkage.h"
#include "strategy/DefinitionBase.h"

namespace tbricks {

class STRATEGY_EXPORT ParameterDefinition : public DefinitionBase
{
public:
    enum PersistencePolicy
    {
        PERSISTENCE_OFF,      /**< Parameter is not persisted */
        PERSISTENCE_BUFFERED, /**< Automated persistence, asynchronous */
        PERSISTENCE_SYNC      /**< This policy is not used anymore, PERSISTENCE_BUFFERED will be appied instead */
    };

    enum Direction
    {
        INPUT = 1,
        OUTPUT = 2,
        INPUT_OUTPUT = 3
    };

public:
    ParameterDefinition(const Uuid & id) : DefinitionBase(id) {}

    ParameterDefinition(const Uuid & id,
                        const String & display_name,
                        const TypeInfo & type,
                        PersistencePolicy policy,
                        Direction direction = INPUT_OUTPUT) :
        DefinitionBase(id)
    {}

    PersistencePolicy GetPersistencePolicy() const;
    Direction GetDirection() const;

private:
    virtual bool resolve() const override;
};
}

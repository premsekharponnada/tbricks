#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Calculated property defintion.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/DefinitionBase.h"
#include "strategy/PortfolioParameterDefinition.h"
#include "strategy/SafePointer.h"
#include "strategy/TradeParameterDefinition.h"
#include "strategy/TreeNodeParameterDefinition.h"
#include "strategy/instrument/InstrumentAttributeDefinition.h"
#include "strategy/instrument/InstrumentParameterDefinition.h"
#include "strategy/parameter/ParameterDefinition.h"
#include "strategy/pricing/InstrumentCalculatedValueDefinition.h"

namespace tbricks {
class UserParameterDefinition;

class STRATEGY_EXPORT CalculatedPropertyDefinition : public DefinitionBase
{
public:
    enum Type
    {
        TypeUnknown = 0,
        TypeStrategyParameter = 1,
        TypeInstrumentParameter = 2,
        TypeInstrumentCalculatedValue = 3,
        TypePortfolioParameter = 4,
        TypeTradeParameter = 5,
        TypeInstrumentAttribute = 6,
        TypeUserParameter = 7,
        TypeTreeNodeParameter = 8,
        TypeExtraDataProperty = 12
    };

public:
    CalculatedPropertyDefinition() = default;
    CalculatedPropertyDefinition(const Uuid & id) : DefinitionBase(id) {}

public:
    ParameterDefinition GetParameterDefinition() const;
    InstrumentParameterDefinition GetInstrumentParameterDefinition() const;
    InstrumentCalculatedValueDefinition GetInstrumentCalculatedValueDefinition() const;
    PortfolioParameterDefinition GetPortfolioParameterDefinition() const;
    UserParameterDefinition GetUserParameterDefinition() const;
    TradeParameterDefinition GetTradeParameterDefinition() const;
    InstrumentAttributeDefinition GetInstrumentAttributeDefinition() const;
    TreeNodeParameterDefinition GetTreeNodeParameterDefinition() const;
    String GetExtraDataPropertyKey() const;

    Type GetType() const;

    static std::vector<CalculatedPropertyDefinition> GetAllDefinitions();

private:
    virtual bool resolve() const override;
};
}

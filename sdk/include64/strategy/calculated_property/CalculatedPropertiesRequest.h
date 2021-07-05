#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CalculatedPropertiesRequest
//****************************************************************************************

#include "strategy/SparseHash.h"
#include "strategy/Printable.h"
#include "strategy/type/Uuid.h"
#include "strategy/calculated_property/GridSelection.h"
#include "strategy/calculated_property/CalculatedProperty.h"
#include "strategy/calculated_property/CalculatedPropertyFilter.h"

namespace tbricks {

class STRATEGY_EXPORT CalculatedPropertiesRequest : public Printable
{
public:
    typedef SparseHash<Uuid, CalculatedProperty> Properties;

    CalculatedPropertiesRequest();
    CalculatedPropertiesRequest(const CalculatedPropertiesRequest & request);
    virtual ~CalculatedPropertiesRequest();
    CalculatedPropertiesRequest & operator=(const CalculatedPropertiesRequest & request);

    const Properties & GetCalculatedProperties() const;
    Properties & GetCalculatedProperties();

    const GridSelection & GetGridSelection() const;
    GridSelection & GetGridSelection();

    const StrategyParameters & GetParameters() const;
    StrategyParameters & GetParameters();

    const CalculatedPropertyFilter & GetCalculatedPropertyFilter() const;
    CalculatedPropertyFilter & GetCalculatedPropertyFilter();

    bool Empty() const;
    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Properties m_properties;
    GridSelection m_selection;
    StrategyParameters m_parameters;
    CalculatedPropertyFilter m_cp_filter;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CalculatedPropertiesTableUpdate class is used to set calculated properties
// that will be sent in response to a request of calculated properties stream.
//
// One can populate the instance of CalculatedPropertiesTableUpdate with any set of parameters.
// They are used to determine a stream, for which CalculatedProperties should be sent.
//
// Once one has finished setting the calculated properties and its respective parameters
// to match some stream, one should send update to virtual Xray engine.
//
// @see VirtualXRayEngine
//
//****************************************************************************************

#include "strategy/calculated_property/CalculatedPropertiesTable.h"

namespace tbricks {

namespace types {
class CalculatedPropertiesRequest;
class TableValues;
}

namespace test {

class STRATEGY_EXPORT CalculatedPropertiesTableUpdate : public Printable
{
public:
    CalculatedPropertiesTableUpdate();
    ~CalculatedPropertiesTableUpdate();
    CalculatedPropertiesTableUpdate(const CalculatedPropertiesTableUpdate & src);

    CalculatedPropertiesTableUpdate & operator=(const CalculatedPropertiesTableUpdate & src);

public:
    /**
     * Sets calculated property. Definitions of the properties along with strategy parameters
     * are used to distinguish the property from another one with different set of parameters.
     *
     * @param row_id             Row identifier
     * @param definition         Definition of the calculated property
     * @param value              Value of the calculated property
     * @param column_parameters  Strategy parameters set for the calculated property
     */
    void SetCalculatedProperty(const Uuid & row_id,
                               const CalculatedPropertyDefinition & definition,
                               const AnyType & value,
                               const StrategyParameters & column_parameters = StrategyParameters());

    /**
     * Removes calculated property. Definitions of the properties along with strategy parameters
     * are used to distinguish the property from another one with different set of parameters.
     *
     * @param row_id             Row identifier
     * @param definition         Definition of the calculated property
     * @param column_parameters  Strategy parameters set for the calculated property
     */
    void RemoveCalculatedProperty(const Uuid & row_id,
                                  const CalculatedPropertyDefinition & definition,
                                  const StrategyParameters & column_parameters = StrategyParameters());

    /**
     * Removes all calculated properties.
     */
    void RemoveAllValues();

public:
    /**
     * Sets filter. It is used to figure out a stream, for which the update would be sent
     *
     * @param filter             Filter.
     */
    void SetFilter(const Filter & filter);

    /**
     * Sets CalculatedPropertyFilter. It is used to figure out a stream, for which the update would be sent
     *
     * @see CalculatedPropertyFilter
     */
    void SetCalculatedPropertyFilter(const CalculatedPropertyFilter & filter);

    /**
     * Sets GridSelection supposed to be tracked
     *
     * @param selection             grid selection
     */
    void SetGridSelection(const GridSelection & selection);

    /**
     * Sets RowDataType. It is used to match a stream, for which the update would be sent
     * Note: CalculatedPropertiesTable::Stream::Options determines this automatically based on filter type
     *
     * @param selection             grid selection
     */
    void SetRowDataType(const CalculatedPropertiesTable::RowDataType & type);

    /**
     * Sets parameters for all requested calculated properties. It is used to match a stream, for which the update would be sent
     *
     * @param parameters         Strategy parameters.
     */
    void SetParameters(const StrategyParameters & parameters);

    /**
     * Sets parameter context. It is used to match a stream, for which the update would be sent
     *
     * @param identifier         Parameter context identifier.
     */
    void SetParameterContext(const Identifier & identifier);

    /**
     * Sets parameter context ranking. It is used to match a stream, for which the update would be sent
     *
     * @param identifier         Parameter context ranking identifier.
     */
    void SetParameterContextRanking(const Identifier & identifier);

    /**
     * Returns true if there are no calculated values set, otherwise false
     */
    bool Empty() const;

    /**
     * Clears the update
     */
    void Clear();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend class VirtualXRayEngine;
    std::unique_ptr<types::CalculatedPropertiesRequest> m_request;
    std::unique_ptr<types::TableValues> m_values;
    std::unique_ptr<filter::FieldFilter> m_filter;
    Identifier m_context;
    Identifier m_context_ranking;
};

} // \namespace test
} // \namespace tbricks

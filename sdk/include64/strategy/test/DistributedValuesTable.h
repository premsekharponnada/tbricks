#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
//****************************************************************************************

#include "strategy/distributed_values/DistributedValues.h"

namespace tbricks {

namespace types {
class DistributedValuesRequest;
class TableValues;
}

namespace test {

class STRATEGY_EXPORT DistributedValuesTable : public Printable
{
public:
    DistributedValuesTable();
    ~DistributedValuesTable();
    DistributedValuesTable(const DistributedValuesTable & src);
    DistributedValuesTable(DistributedValuesTable && src);

    DistributedValuesTable & operator=(const DistributedValuesTable & src);

public:
    /**
     * Adds distributed value to the accumulated table update
     *
     * @param  definition      Definition of distributed value
     * @param  value           Distributed value
     * @param  row_parameters  Startegy parameters for the row
     *                         or DistributedValuesRequest::Value
     * @param  parameters      Startegy parameters for the column
     *                         or DistributedValuesRequest::Object
     */
    void AddDistributedValue(const DistributedValueDefinition & definition,
                             const AnyType & value,
                             const StrategyParameters & row_parameters = StrategyParameters(),
                             const StrategyParameters & parameters = StrategyParameters());

    /**
     * Checks whether accumulated table update is empty
     *
     * @return  false  if data is not empty, otherwise true
     */
    bool Empty() const;

    /**
     * Clears accumulated table update
     */
    void Clear();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend class VirtualDistributionEngine;
    friend class VirtualDistributionStream;
    std::unique_ptr<types::DistributedValuesRequest> m_request;
    std::unique_ptr<types::TableValues> m_values;
};

} // \namespace test
} // \namespace tbricks

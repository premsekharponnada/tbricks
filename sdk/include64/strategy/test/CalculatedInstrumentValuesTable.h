#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CalculatedInstrumentValuesTable can be used to predefine
// CalculatedInstrumentValues for VirtualCalculationEngine.
//
// CalculatedValues is used to create Table.
// Only required cells can be sent, hence one table can be used for a multiple streams.
// Filter, parameters, parameter context,
// parameter context ranking and override parameters are used to
// identify for which streams this table should be used.
// If one of them is different, there will be two different tables in the cache.
//
// If there is no table with same parameters for stream, default table can be used.
// When a table have all the parameter same of the of a stream
// (stream amy have extra parameter in addition to the similar parameter),
// that table will be used this stream.
// When a stream have all the parameters similar to the table' parameter
// (table may have extra parameter in addition with the similar ones),
// there will be no table for this stream at all.
//
// Example :
//
// Stream 1 : Parameter A B C D
// Stream 2 : Parameter A B
//
// Table 1 : Parameter A B C
//
// For Stream 1, Table 1 can be used by default,
// because parameter D is missed for this table.
//
// For Stream 2, Table 1 can NOT be used because of Table 1 is more concretic
// (has parameter C), hence this table will not be used for Stream 2.
//
//****************************************************************************************

#include "strategy/instrument/CalculatedInstrumentValues.h"
#include "strategy/instrument/InstrumentParameters.h"
#include "strategy/instrument/InstrumentGroupParameters.h"

namespace tbricks {

namespace types {
class TableValues;
}

namespace test {

class STRATEGY_EXPORT CalculatedInstrumentValuesTable : public Printable
{
public:
    CalculatedInstrumentValuesTable();
    ~CalculatedInstrumentValuesTable();
    CalculatedInstrumentValuesTable(const CalculatedInstrumentValuesTable & src);

    CalculatedInstrumentValuesTable & operator=(const CalculatedInstrumentValuesTable & src);

public:
    /**
     * Set calculated value for InstrumentVenueIdentification.
     * If row/column parameters are specified, these values will
     * be sent only for the requested row/column with same parameters.
     *
     * @param ivid               InstrumentVenueIdentification.
     *
     * @param definition         InstrumentCalculatedValueDefinition.
     *
     * @param value              Calculated value.
     *
     * @param row_parameters     Row parameters.
     *
     * @param column_parameters  Column parameters.
     */
    void SetCalculatedValue(const InstrumentVenueIdentification & ivid,
                            const InstrumentCalculatedValueDefinition & definition,
                            const TypeWithError & value,
                            const StrategyParameters & row_parameters = StrategyParameters(),
                            const StrategyParameters & column_parameters = StrategyParameters());

    /**
     * Set calculated value for group.
     * If row/column parameters are specified, these values will
     * be sent only for the requested row/column with same parameters.
     *
     * @param group_id           InstrumentGroupIdentifier.
     *
     * @param definition         InstrumentCalculatedValueDefinition.
     *
     * @param value              Calculated value.
     *
     * @param row_parameters     Row parameters.
     *
     * @param column_parameters  Column parameters.
     */
    void SetCalculatedValue(const InstrumentGroupIdentifier & group_id,
                            const InstrumentCalculatedValueDefinition & definition,
                            const TypeWithError & value,
                            const StrategyParameters & row_parameters = StrategyParameters(),
                            const StrategyParameters & column_parameters = StrategyParameters());

    /**
     * Remove calculated value for InstrumentVenueIdentification.
     *
     * @param ivid               InstrumentVenueIdentification.
     *
     * @param definition         InstrumentCalculatedValueDefinition.
     *
     * @param row_parameters     Row parameters.
     *
     * @param column_parameters  Column parameters.
     */
    void RemoveCalculatedValue(const InstrumentVenueIdentification & ivid,
                               const InstrumentCalculatedValueDefinition & definition,
                               const StrategyParameters & row_parameters = StrategyParameters(),
                               const StrategyParameters & column_parameters = StrategyParameters());

    /**
     * Remove calculated value for group.
     *
     * @param group_id           InstrumentGroupIdentifier.
     *
     * @param definition         InstrumentCalculatedValueDefinition.
     *
     * @param row_parameters     Row parameters.
     *
     * @param column_parameters  Column parameters.
     */
    void RemoveCalculatedValue(const InstrumentGroupIdentifier & group_id,
                               const InstrumentCalculatedValueDefinition & definition,
                               const StrategyParameters & row_parameters = StrategyParameters(),
                               const StrategyParameters & column_parameters = StrategyParameters());

    /**
     * Remove all non-empty values from table.
     */
    void RemoveAllValues();

public:
    /**
     * Set table filter. These table values will be used for
     * streams with same filter.
     *
     * @param filter             Filter.
     */
    void SetFilter(const InstrumentStream::Filters::Filter & filter);

    /**
     * Add instrument override parameters. These table values
     * will be used for streams with same override parameters.
     *
     * @param instrument_id      Instrument Identifier.
     *
     * @param parameters         Override parameters.
     */
    void AddOverrideParameters(const InstrumentIdentifier & instrument_id, const InstrumentParameters & parameters);

    /**
     * Add instrument group override parameters. These table values
     * will be used for streams with same override parameters.
     *
     * @param group_id           Instrument Group Identifier.
     *
     * @param parameters         Override parameters.
     */
    void AddOverrideParameters(const InstrumentGroupIdentifier & group_id, const InstrumentGroupParameters & parameters);

    /**
     * Set parameters. These table values will be used for
     * streams with same parameters.
     *
     * @param parameters         Parameters.
     */
    void SetParameters(const StrategyParameters & parameters);

    /**
     * Set parameter context. These table values will be used for
     * streams with same parameter context.
     *
     * @param identifier         Parameter context identifier.
     */
    void SetParameterContext(const Identifier & identifier);

    /**
     * Set parameter context ranking. These table values will be used for
     * streams with same parameter context ranking.
     *
     * @param identifier         Parameter context ranking identifier.
     */
    void SetParameterContextRanking(const Identifier & identifier);

public:
    /**
     * Check is table values empty.
     */
    bool Empty() const;

    /**
     * Clear table values.
     *
     * Note that the cleared table can't be used to clean up calculated
     * values cache in VirtualCalculationEngine. In this case,
     * the table should be prepared using of RemoveValue method instead.
     */
    void Clear();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend class VirtualCalculationEngine;
    std::unique_ptr<types::CalculatedValuesRequest> m_request;
    std::unique_ptr<types::TableValues> m_values;
    InstrumentStream::Filters::Filter m_filter;
    Identifier m_context;
    Identifier m_context_ranking;
};

} // \namespace test
} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::ByFlatParameterFilter
// matched instruments with specified flat (non-aggregated) parameter
//****************************************************************************************

#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

namespace filter {
class ICondition;
}

class InstrumentParameterDefinition;
class Uuid;

/**
 * InstrumentByFlatParameterFilter matches instruments
 * having specified instrument parameter value.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::ByFlatParameterFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /// Default constructor.
    ByFlatParameterFilter();

    /**
     * Makes a filter to match all instruments with the specified instrument parameter value.
     *
     * @param definition                       Parameter "definitions" allows to select what
                                               specific instrument parameters updates the
                                               caller is interested in.
     * @param value                            value of instrument_parameter
     */
    ByFlatParameterFilter(const InstrumentParameterDefinition & definition, const AnyType & value);

    /**
     * Makes a filter to match all instruments with the specified instrument parameter value.
     *
     * @param definition                       Parameter "definitions" allows to select what
                                               specific instrument parameters updates the
                                               caller is interested in.
     * @param value                            value of instrument_parameter
     */
    ByFlatParameterFilter(const InstrumentParameterDefinition & definition, const AnyType & value, const ContextIdentifier & identifier);

    ~ByFlatParameterFilter();

    ByFlatParameterFilter(const ByFlatParameterFilter & filter);
    ByFlatParameterFilter & operator=(const ByFlatParameterFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;

    /**
     * %Set the parameter context for the filter.
     *
     * @param identifier                       context identifier
     */
    void SetContextIdentifier(const ContextIdentifier & identifier);

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void init(const Uuid & parameter_id, const AnyType & value);

private:
    ::tbricks::filter::ICondition * m_condition;
};
}

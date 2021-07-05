#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentGroupByFlatParameterFilter matches instrument groups
// with specified flat (non-aggregated) instrument parameter.
//****************************************************************************************

#include "strategy/type/Uuid.h"
#include "strategy/type/ContextIdentifier.h"
#include "strategy/instrument/InstrumentParameterDefinition.h"
#include "strategy/stream_filter/InstrumentGroupFilter.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * InstrumentGroupByFlatParameterFilter matches instrument groups
 * having specified instrument parameter value.
 */
class STRATEGY_EXPORT InstrumentGroupByFlatParameterFilter : public InstrumentGroupFilterCondition
{
public:
    /// Default constructor.
    InstrumentGroupByFlatParameterFilter();

    /**
     * Makes a filter to match all instrument groups with the specified instrument parameter value.
     *
     * @param definition                       Parameter "definitions" allows to select what specific
                                               instrument parameters updates the caller is interested in.
     * @param value                            parameter value
     */
    InstrumentGroupByFlatParameterFilter(const InstrumentParameterDefinition & definition, const AnyType & value);

    /**
     * Make a filter to match all instrument groups with the specified
     * instrument parameter value and parameter context.
     *
     * @param definition                       Parameter "definitions" allows to select what specific
                                               instrument parameters updates the caller is interested in.
     * @param  value                           parameter value
     * @param  identifier                      parameter context identifier
     */
    InstrumentGroupByFlatParameterFilter(const InstrumentParameterDefinition & definition,
                                         const AnyType & value,
                                         const ContextIdentifier & identifier);
    InstrumentGroupByFlatParameterFilter(const InstrumentGroupByFlatParameterFilter & filter);
    ~InstrumentGroupByFlatParameterFilter();

    InstrumentGroupByFlatParameterFilter & operator=(const InstrumentGroupByFlatParameterFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;

    /**
     * %Set parameter context for the filter.
     *
     * @param identifier			parameter context identifier
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

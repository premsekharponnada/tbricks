#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::ByParameterFilter, matches the updates of
// instruments with the given parameter.
//****************************************************************************************

#include "strategy/type/Uuid.h"
#include "strategy/instrument/InstrumentAttributes.h"
#include "strategy/instrument/InstrumentAttributeDefinition.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * InstrumentByInstrumentAttributeFilter matches concrete instrument instance updates,
 * related to specified aggregated instrument parameter value.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::ByInstrumentAttributeFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /// Default constructor
    ByInstrumentAttributeFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match instruments having specified default attributes.
     *
     * @param definition                        instrument attribute definition
     * @param value                             instrument attribute's value
     */
    ByInstrumentAttributeFilter(const InstrumentAttributeDefinition & definition, const AnyType & value);

    /**
     * Constructor.
     *
     * Makes a filter to match all instruments having attribute of specified type, index, definition and value.
     *
     * @param type                              instrument attribute's type
     * @param index                             instrument attribute's index value
     * @param definition                        instrument attribute definition
     * @param value                             instrument attribute's value
     */
    ByInstrumentAttributeFilter(InstrumentAttributes::AttributeType type,
                                size_t index,
                                const InstrumentAttributeDefinition & definition,
                                const AnyType & value);

    ByInstrumentAttributeFilter(const ByInstrumentAttributeFilter & filter);
    ~ByInstrumentAttributeFilter();

    ByInstrumentAttributeFilter & operator=(const ByInstrumentAttributeFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void init(InstrumentAttributes::AttributeType type, size_t index, const Uuid & parameter_id, const AnyType & value);

private:
    ::tbricks::filter::ICondition * m_condition;
};
}

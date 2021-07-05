#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::ByInstrumentHasAttributeFilter, matches updates of
// instruments that has the given attribute.
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
class STRATEGY_EXPORT InstrumentStream::Filters::ByInstrumentHasAttributeFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /// Default constructor
    ByInstrumentHasAttributeFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all the instruments having the specified attribute.
     *
     * @param definition                    instrument attribute definition
     */
    ByInstrumentHasAttributeFilter(const InstrumentAttributeDefinition & definition);

    /**
     * Constructor.
     *
     * Makes a filter to match all the instruments having specified attribute type.
     *
     * @param type                          instrument attribute's type
     */
    ByInstrumentHasAttributeFilter(InstrumentAttributes::AttributeType type);

    /**
     * Constructor.
     *
     * Makes a filter using attribute of specified type and index to match
     * the instruments updates.
     *
     * @param type                          instrument attribute's type
     * @param index                         instrument attribute's index value
     */
    ByInstrumentHasAttributeFilter(InstrumentAttributes::AttributeType type, size_t index);

    /**
     * Constructor.
     *
     * Makes a filter using attribute of specified type, index and definition
     * to match the instruments updates.
     *
     * @param type                          instrument attribute's type
     * @oaram index                         instrument attribute's index value
     * @param definition                    instrument attribute definition
     */
    ByInstrumentHasAttributeFilter(InstrumentAttributes::AttributeType type, size_t index, const InstrumentAttributeDefinition & definition);

    ByInstrumentHasAttributeFilter(const ByInstrumentHasAttributeFilter & filter);
    ~ByInstrumentHasAttributeFilter();

    ByInstrumentHasAttributeFilter & operator=(const ByInstrumentHasAttributeFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void init(InstrumentAttributes::AttributeType type, size_t index);
    void init(InstrumentAttributes::AttributeType type, size_t index, const Uuid & parameter_id);

private:
    ::tbricks::filter::ICondition * m_condition;
};
}

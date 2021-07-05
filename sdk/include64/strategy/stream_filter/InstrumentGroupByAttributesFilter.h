#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentGroupByAttributesFilter, matches instrument group updates by specified
// attribute selection.
//****************************************************************************************

#include <vector>

#include "strategy/type/String.h"
#include "strategy/stream_filter/InstrumentGroupFilter.h"
#include "strategy/type/InstrumentGroup.h"

namespace tbricks {

/**
 * InstrumentGroupByAttributesFilter matches concrete instrument group instance updates,
 * selected by instrument group attributes.
 */
class STRATEGY_EXPORT InstrumentGroupByAttributesFilter : public InstrumentGroupFilterCondition
{
public:
    /// Default constructor.
    InstrumentGroupByAttributesFilter();
    InstrumentGroupByAttributesFilter(const InstrumentGroupByAttributesFilter & filter);

    InstrumentGroupByAttributesFilter & operator=(const InstrumentGroupByAttributesFilter & filter);

    /**
     * %Set instrument group name for the filter.
     *
     * @param name                             InstrumentGroup::Type enum type value
     */
    void SetType(const InstrumentGroup::Type & type);

    /**
     * %Set instrument group name for the filter.
     *
     * @param name                             instrument group name
     */
    void SetName(const String & name);

    /**
     * %Set instrument group long name for the filter.
     *
     * @param long_name                        instrument group long name
     */
    void SetLongName(const String & long_name);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    String m_name;
    String m_long_name;
    InstrumentGroup::Type m_type;
};
}

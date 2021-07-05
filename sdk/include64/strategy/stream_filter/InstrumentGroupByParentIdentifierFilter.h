#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentGroupByParentIdentifierFilter.h
// matches updates of concrete instrument group.
//****************************************************************************************

#include "strategy/type/InstrumentGroupIdentifier.h"
#include "strategy/stream_filter/InstrumentGroupFilter.h"

namespace tbricks {

/**
 * InstrumentGroupByParentIdentifierFilter matches concrete instrument group instance updates,
 * selected by parent group identifier.
 */
class STRATEGY_EXPORT InstrumentGroupByParentIdentifierFilter : public InstrumentGroupFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the instrument groups having specified instrument group as a parent group.
     *
     * @param parent_instrument_group_id                            instrument group identifier.
                                                                    Parent instrument group identifier of the
                                                                    instrument groups which are to be filtered.
     */
    InstrumentGroupByParentIdentifierFilter(const InstrumentGroupIdentifier & parent_instrument_group_id);
    InstrumentGroupByParentIdentifierFilter(const InstrumentGroupByParentIdentifierFilter & filter);

    InstrumentGroupByParentIdentifierFilter & operator=(const InstrumentGroupByParentIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentGroupIdentifier m_instrument_group_id;
};
}

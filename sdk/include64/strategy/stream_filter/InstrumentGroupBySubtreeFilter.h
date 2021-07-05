#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentGroupBySubtreeFilter, matches updates of instrument group in
// group subtree.
//****************************************************************************************

#include "strategy/type/InstrumentGroupIdentifier.h"
#include "strategy/stream_filter/InstrumentGroupFilter.h"

namespace tbricks {

/**
 * InstrumentGroupBySubtreeFilter matches concrete instrument group instance updates,
 * selected in group subtree.
 */
class STRATEGY_EXPORT InstrumentGroupBySubtreeFilter : public InstrumentGroupFilterCondition
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
    InstrumentGroupBySubtreeFilter(const InstrumentGroupIdentifier & id);
    InstrumentGroupBySubtreeFilter(const InstrumentGroupBySubtreeFilter & filter);

    InstrumentGroupBySubtreeFilter & operator=(const InstrumentGroupBySubtreeFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentGroupIdentifier m_identifier;
};
}

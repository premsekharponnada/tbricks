#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentGroupDeletedFilter, matches deleted group in snapshot.
//****************************************************************************************

#include "strategy/type/Boolean.h"
#include "strategy/type/InstrumentGroupIdentifier.h"
#include "strategy/stream_filter/InstrumentGroupFilter.h"

namespace tbricks {

/**
 * InstrumentGroupDeletedFilte allows to skip deleted groups.
 */
class STRATEGY_EXPORT InstrumentGroupDeletedFilter : public InstrumentGroupFilterCondition
{
public:
    /// Default constructor.
    InstrumentGroupDeletedFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all instrument group based on the Boolean value specified as true or false.
     * If set to false, the filter will return all the non-deleted instrument group.
     *
     * @param deleted                   Boolean value
     *                                  set true to get deleted instrument group
     *                                  set false to get non deleted instrument group
     */
    InstrumentGroupDeletedFilter(const Boolean & deleted);
    InstrumentGroupDeletedFilter(const InstrumentGroupDeletedFilter & filter);

    InstrumentGroupDeletedFilter & operator=(const InstrumentGroupDeletedFilter & filter);

    /**
     * %Set instrument deleted status for the filter.
     *
     * @param deleted                   Boolean value
     *                                  set true to get deleted instrument group
     *                                  set false to get non deleted instrument group
     */
    void SetDeleted(const Boolean & deleted);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Boolean m_deleted;
};
}

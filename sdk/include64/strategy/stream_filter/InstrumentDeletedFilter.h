#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::DeletedFilter, matches deleted instruments.
//****************************************************************************************

#include "strategy/type/Boolean.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

/**
 * InstrumentDeletedFilter allows to skip deleted instruments.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::DeletedFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /// Default constructor
    DeletedFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all instruments based on the specified
     * Boolean value.
     *
     * @param deleted                                 Boolean value.
                                                      Set true to get deleted instrument.
                                                      Set false to get non deleted instrument.
     */
    DeletedFilter(const Boolean & deleted);
    DeletedFilter(const DeletedFilter & filter);

    DeletedFilter & operator=(const DeletedFilter & filter);

    /**
     * %Set instrument deleted status for the filter.
     *
     * @param deleted                                  Boolean value.
                                                       Set true to get deleted instrument.
                                                       Set false to get non deleted instrument.
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

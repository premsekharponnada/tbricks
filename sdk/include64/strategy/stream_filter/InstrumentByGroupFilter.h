#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentByGroupFilter, matches updates of instruments in
// the given group.
//****************************************************************************************

#include "strategy/type/InstrumentGroup.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

/**
 * InstrumentStream::Filters::ByGroupFilter matches matches concrete instrument instance updates
 * having specific instrument group.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::ByGroupFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all instruments having specified instrument group.
     *
     * @param group                                  instance of instrument group
     *
     */
    ByGroupFilter(const InstrumentGroup & group);

    /**
     * Constructor.
     *
     * Makes a filter to match all instruments having instrument group with specified identifier
     *
     * @param group_id
     *
     */
    ByGroupFilter(const InstrumentGroupIdentifier & group_id);

    ByGroupFilter(const ByGroupFilter & filter);

    ByGroupFilter & operator=(const ByGroupFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentGroupIdentifier m_identifier;
};
}

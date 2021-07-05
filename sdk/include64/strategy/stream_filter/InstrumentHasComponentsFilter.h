#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::HasComponentsFilter
// matches instruments containing components.
//****************************************************************************************

#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

/**
 * InstrumentDeletedFilter matches instruments containing components.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::HasComponentsFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    HasComponentsFilter();
    HasComponentsFilter(const HasComponentsFilter & filter);

    HasComponentsFilter & operator=(const HasComponentsFilter & filter);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual void Clear();
    virtual bool Empty() const;
};
}

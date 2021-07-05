#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::TemporaryFilter, matches temporary instruments.
//****************************************************************************************

#include "strategy/type/Boolean.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

/**
 * InstrumentTemporaryFilter allows to skip temporary instruments.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::TemporaryFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /// Default constructor
    TemporaryFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all instruments having the Boolean value
     * specified as true or false.
     * If set to false, the filter will return all the non-temporary instruments.
     *
     * @param temporary                            Boolean value
     *                                             set true to get temporary instrument.
     *                                             set false to get non temporary instrument.
     */
    TemporaryFilter(const Boolean & temporary);
    TemporaryFilter(const TemporaryFilter & filter);

    TemporaryFilter & operator=(const TemporaryFilter & filter);

    /**
     * %Set instrument temporary status for the filter.
     *
     * @param temporary                            Boolean value
     *                                             set true to get temporary instrument.
     *                                             set false to get non temporary instrument.
     */
    void SetTemporary(const Boolean & temporary);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Boolean m_temporary;
};
}

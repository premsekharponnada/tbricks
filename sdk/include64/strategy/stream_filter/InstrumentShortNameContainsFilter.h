#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::ShortNameContainsFilter, matches instrument
// updates by specified short name.
//****************************************************************************************

#include "strategy/type/String.h"
#include "strategy/Instrument.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

/**
 * InstrumentStream::Filters::ShortNameContainsFilter matches concrete instrument instance updates
 * containing specific instrument short name.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::ShortNameContainsFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /**
     * Makes a filter to match the instrument instance having
     * short name as specified in the input parameter.
     *
     * @param short_name            String instance, short name of the
     *                              instrument to be filtered.
     */
    ShortNameContainsFilter(String short_name, bool case_sensitive = true);

    tbricks::filter::FieldFilter GetValue() const override;

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;
    void Clear() override;
    bool Empty() const override;

private:
    String m_short_name;
    bool m_case_sensitive;
};
}

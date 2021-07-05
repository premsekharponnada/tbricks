#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in system streams.
//****************************************************************************************

#include "strategy/System.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/stream/SystemStream.h"

namespace tbricks {

/**
 * Default system filter, matches all data.
 */
class STRATEGY_EXPORT System::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Filter & filter);
    ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const Filter & filter);
    Filter & operator&=(const Filter & filter);

    Filter operator||(const Filter & filter);
    Filter operator&&(const Filter & filter);

    Filter operator!();

    void Clear() override;
    bool Empty() const override;

public:
    tbricks::filter::FieldFilter GetValue() const override;
    Filter(const tbricks::filter::Filter & filter) : tbricks::Filter(filter) {}

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

class STRATEGY_EXPORT System::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    System::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    System::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    System::Stream::Filters::Filter operator||(const System::Stream::Filters::Filter & cond) const;
    System::Stream::Filters::Filter operator&&(const System::Stream::Filters::Filter & cond) const;
    System::Stream::Filters::Filter operator!() const;
    operator System::Stream::Filters::Filter() const;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in subsystem streams.
//****************************************************************************************

#include "strategy/Subsystem.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/stream/SubsystemStream.h"

namespace tbricks {

/**
 * Default subsystem filter, matches all data.
 */
class STRATEGY_EXPORT Subsystem::Stream::Filters::Filter : public tbricks::Filter
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

class STRATEGY_EXPORT Subsystem::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Filter operator||(const FilterCondition & cond) const;
    Filter operator&&(const FilterCondition & cond) const;
    Filter operator||(const Filter & cond) const;
    Filter operator&&(const Filter & cond) const;
    Filter operator!() const;
    operator Filter() const;
};
}

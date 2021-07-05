#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in component streams.
//****************************************************************************************

#include "strategy/Component.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/stream/ComponentStream.h"

namespace tbricks {

/**
 * Default service status filter, matches all data.
 */
class STRATEGY_EXPORT Component::Stream::Filters::Filter : public tbricks::Filter
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

class STRATEGY_EXPORT Component::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Component::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    Component::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    Component::Stream::Filters::Filter operator||(const Component::Stream::Filters::Filter & cond) const;
    Component::Stream::Filters::Filter operator&&(const Component::Stream::Filters::Filter & cond) const;
    Component::Stream::Filters::Filter operator!() const;
    operator Component::Stream::Filters::Filter() const;
};
}

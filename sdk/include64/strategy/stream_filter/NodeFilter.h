#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in node streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"
#include "strategy/stream/NodeStream.h"

namespace tbricks {

/**
 * Default node filter, matches all data.
 */
class STRATEGY_EXPORT Node::Stream::Filters::Filter : public tbricks::Filter
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

class STRATEGY_EXPORT Node::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Node::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    Node::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    Node::Stream::Filters::Filter operator||(const Node::Stream::Filters::Filter & cond) const;
    Node::Stream::Filters::Filter operator&&(const Node::Stream::Filters::Filter & cond) const;
    Node::Stream::Filters::Filter operator!() const;
    operator Node::Stream::Filters::Filter() const;
};
}

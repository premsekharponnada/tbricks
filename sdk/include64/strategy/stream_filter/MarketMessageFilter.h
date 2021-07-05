#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in market message streams.
//****************************************************************************************

#include "strategy/stream/MarketMessageStream.h"
#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/**
 * Default MarketMessage filter, matches all messages.
 */
class STRATEGY_EXPORT MarketMessage::Stream::Filters::Filter : public tbricks::Filter
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
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

class STRATEGY_EXPORT MarketMessage::Stream::Filters::FilterCondition : public tbricks::FilterCondition
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

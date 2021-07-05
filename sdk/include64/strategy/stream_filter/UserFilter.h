#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// User filter objects.
//****************************************************************************************

#include "strategy/stream/UserStream.h"

namespace tbricks {

class STRATEGY_EXPORT User::Stream::Filters::Filter : public tbricks::Filter
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

class STRATEGY_EXPORT User::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    User::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    User::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    User::Stream::Filters::Filter operator||(const Filter & cond) const;
    User::Stream::Filters::Filter operator&&(const Filter & cond) const;
    User::Stream::Filters::Filter operator!() const;
    operator User::Stream::Filters::Filter() const;
};

using AnyUserFilter = User::Stream::Filters::Filter;

/// By Identifier

class STRATEGY_EXPORT User::Stream::Filters::ByIdentifier : public User::Stream::Filters::FilterCondition
{
public:
    ByIdentifier(const UserIdentifier & id) : m_id(id) {}

    virtual bool Empty() const { return m_id.Empty(); }
    virtual void Clear() { m_id.Clear(); }

    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    UserIdentifier m_id;
};
}

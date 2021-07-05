#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Role stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Role.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/AnyFilter.h"

namespace tbricks {

namespace strategy {
class RoleStreamImpl;
}

class STRATEGY_EXPORT Role::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
    };

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open(Type type, const Filters::Filter & filter);
    void OpenAudit(Type type, const Filters::Filter & filter, const DateTime & from = DateTime(), const DateTime & to = DateTime());

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

class STRATEGY_EXPORT Role::Stream::Filters::Filter : public tbricks::Filter
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

class STRATEGY_EXPORT Role::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Role::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    Role::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    Role::Stream::Filters::Filter operator||(const Filter & cond) const;
    Role::Stream::Filters::Filter operator&&(const Filter & cond) const;
    Role::Stream::Filters::Filter operator!() const;
    operator Role::Stream::Filters::Filter() const;
};

typedef Role::Stream::Filters::Filter AnyRoleFilter;

class STRATEGY_EXPORT Role::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleRole(const StreamIdentifier & stream_id, const Role::Update & update) = 0;

    /**
     * Role stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated Role
     */
    virtual void HandleRoleInvalidate(const StreamIdentifier & stream_id, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

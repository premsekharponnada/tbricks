#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Expiration stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Expiration.h"
#include "strategy/Strategy.h"
#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/Stream.h"

namespace tbricks {

class STRATEGY_EXPORT Expiration::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByIdentifierFilter;
        class ByExpirationDateFilter;
        class ByModifiedDateTimeFilter;
    };

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open(Type type, const Filters::Filter & filter);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

class STRATEGY_EXPORT Expiration::Stream::Filters::Filter : public tbricks::Filter
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

typedef Expiration::Stream::Filters::Filter AnyExpirationFilter;

class STRATEGY_EXPORT Expiration::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleExpiration(const StreamIdentifier & stream_id, const Expiration::Update & update) = 0;
    /**
     * Expiration stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits the filtering criteria.
     *
     * Fox example, a subscription is made for un-deleted Expiration and all the
     * un-deleted Expiration are received. If any such Expiration is deleted,
     * invalidate method will be called to indicate that this Expiration no longer
     * belongs to subscription request.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated Expiration
     */
    virtual void HandleExpirationInvalidate(const StreamIdentifier & stream, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

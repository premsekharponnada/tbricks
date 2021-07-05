#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExPit stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/ExPit.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/AnyFilter.h"

namespace tbricks {

class STRATEGY_EXPORT ExPit::Stream : public tbricks::Stream
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
        class ByParentFilter;
        class ByTypeFilter;
        class ByHostCreatedDateTimeFilter;
        class ByHostModifiedDateTimeFilter;
        class DeletedFilter;
    };

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open(Type type, const Filters::Filter & filter);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

class STRATEGY_EXPORT ExPit::Stream::Filters::Filter : public tbricks::Filter
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

typedef ExPit::Stream::Filters::Filter AnyExPitFilter;

class STRATEGY_EXPORT ExPit::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * ExPit stream update handler.
     *
     * Method is called when a new ex-pit update becomes available on the
     * stream.
     *
     * @param stream                   Stream where an update occurred
     * @param update                   ExPit update object, represents a
     *                                 set of updated ex-pit fields
     */
    virtual void HandleExPit(const StreamIdentifier & stream_id, const ExPit::Update & expit) = 0;

    /**
     * ExPit stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits the filtering criteria.
     *
     * Fox example, a subscription is made for modified ex-pits and all the
     * ex-pit having modified date-time with in the specified range, are received.
     * If any such ex-pit's is modified and does not fit in the modification range,
     * specified in the subscription, invalidate method will be called to indicate
     * that this ex-pit no longer belongs to subscription request.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated ex-pit
     */
    virtual void HandleExPitInvalidate(const StreamIdentifier & stream_id, const ExPitIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

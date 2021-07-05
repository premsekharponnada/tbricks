#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Cash stream.
//****************************************************************************************

#include <set>

#include "strategy/Linkage.h"
#include "strategy/Cash.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/AnyFilter.h"

namespace tbricks {

class STRATEGY_EXPORT Cash::Stream : public tbricks::Stream
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
        class ByPortfolioFilter;
        class ByCashDateTimeFilter;
        class NotDeleted;
        class ByExtraDataFilter;
        class ByModifiedDateTimeFilter;
        class ByStrategyIdentifierFilter;
        class ByRootFilter;
        class ByAncestorFilter;
        class ByClientFilter;
    };

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open(Type type, const Filters::Filter & filter, const DateTime & snapshot_datetime = DateTime());
    void Open(Type type, const Filters::Filter & filter, Cash::AggregationType aggregation_type, bool summate_positions = true);
    void Open(Type type, const Filters::Filter & filter, const std::set<Cash::AggregationKey> & aggregation_keys);

    /**
     * Open an audit stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter
     * @param from                      Initial point of time
     * @param to                        Point of time to which the updates will
     *                                  be collected
     */
    void OpenAudit(Type type, const Filters::Filter & filter, const DateTime & from = DateTime(), const DateTime & to = DateTime());

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

class STRATEGY_EXPORT Cash::Stream::Filters::Filter : public tbricks::Filter
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

typedef Cash::Stream::Filters::Filter AnyCashFilter;

class STRATEGY_EXPORT Cash::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleCash(const StreamIdentifier & stream_id, const Cash::Update & update) = 0;

    /**
     * Cash stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * Fox example, a subscription is made for non-deleted Cash and all the
     * non-deleted cash are received. If any such cash is deleted, invalidate
     * method will be called to indicate that this cash no longer belongs
     * to subscription request.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Item identifier of invalidate cash
     */
    virtual void HandleCashInvalidate(const StreamIdentifier & stream_id, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

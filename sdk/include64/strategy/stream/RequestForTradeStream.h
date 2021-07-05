#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Request for trade stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/RequestForTrade.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/AnyFilter.h"

namespace tbricks {

class STRATEGY_EXPORT RequestForTrade::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByExPitIdentifierFilter;
        class ByAppIdentifierFilter;
        class ByExchangeCreatedDateTimeFilter;
        class ByRequestForQuoteIdentifierFilter;
        class ByHostCreatedDateTimeFilter;
        class DeletedFilter;
    };

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open(Type type, const InstrumentVenueIdentification & ivid, const Filters::Filter & filter);

    void Open(Type type, const Filters::Filter & filter);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

class STRATEGY_EXPORT RequestForTrade::Stream::Filters::Filter : public tbricks::Filter
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

typedef RequestForTrade::Stream::Filters::Filter AnyRequestForTradeFilter;

class STRATEGY_EXPORT RequestForTrade::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleRequestForTrade(const StreamIdentifier & stream_id, const RequestForTrade & rft) = 0;

    /**
     * RequestForTrade stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidate RequestForTrade
     */
    virtual void HandleRequestForTradeInvalidate(const StreamIdentifier & stream_id, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};
}

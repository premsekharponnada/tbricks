#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Request for quote stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/RequestForQuote.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/AnyFilter.h"

namespace tbricks {

class STRATEGY_EXPORT RequestForQuote::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByExchangeCreatedDateTimeFilter;
        class ByHostCreatedDateTimeFilter;
        class DirectedQuoteExpected;
        class ByIdentifierFilter;
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

class STRATEGY_EXPORT RequestForQuote::Stream::Filters::Filter : public tbricks::Filter
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

typedef RequestForQuote::Stream::Filters::Filter AnyRequestForQuoteFilter;

class STRATEGY_EXPORT RequestForQuote::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleRequestForQuote(const StreamIdentifier & stream_id, const RequestForQuote & rfq) = 0;

    /**
     * RequestForQuote stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidate RequestForQuote
     */
    virtual void HandleRequestForQuoteInvalidate(const StreamIdentifier & stream_id, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};
}

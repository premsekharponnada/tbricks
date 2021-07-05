#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteSet stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Strategy.h"
#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/Stream.h"
#include "strategy/quoting/QuoteSet.h"

namespace tbricks {

namespace strategy {
class QuoteSettreamImpl;
}

class STRATEGY_EXPORT QuoteSet::Stream::Filters::Filter : public tbricks::Filter
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

class STRATEGY_EXPORT QuoteSet::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleQuoteSetUpdate(const StreamIdentifier & stream_id, const QuoteSet::Update & update) = 0;

    /**
     * QuoteSet stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * Fox example, a subscription was made for active QuoteSet and all the
     * active QuoteSet were received. If any such QuoteSet becomes non-active,
     * invalidate method would be called to indicate that this QuoteSet no longer
     * belongs to subscription request.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated QuoteSet
     */
    virtual void HandleQuoteSetInvalidate(const StreamIdentifier & stream_id, const Identifier & id) = 0;

    /**
     * QuoteSet event handler
     *
     * This method is called when Quoting notifies quote set owner about events happened in QuoteSet.
     *
     * @param stream                    StreamIdentifier
     * @param event                     Event
     */
    virtual void HandleEvent(const StreamIdentifier & stream, const Event & event) {}

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

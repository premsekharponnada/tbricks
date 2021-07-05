#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Current CurrentQuotes stream (SnapshotAndLive only).
//****************************************************************************************

#include "strategy/quote_information/QuoteIdentifierMapping.h"
#include "strategy/stream_filter/QuoteSetFilters.h"
#include "strategy/quote_information/CurrentQuotes.h"

namespace tbricks {

class STRATEGY_EXPORT CurrentQuotes::Stream : public tbricks::Stream
{
public:
    class IHandler;
    class MergeHandler;

public:
    Stream();
    Stream(IHandler & handler);

    Stream(const Stream & stream);
    Stream & operator=(const Stream & stream);

    virtual ~Stream();

    void SetCallback(IHandler & handler);
    void SetQuotingService(const ServiceIdentifier & id);

    void Open(const QuoteSet::Stream::Filters::ByIdentifierFilter & filter);

    virtual void Close();

    virtual bool IsOpen() const;
    virtual bool IsSnapshotDone() const;
    virtual bool IsStale() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyStreamImpl * m_quote_stream_impl;
    std::shared_ptr<MergeHandler> m_merge_handler;
    ServiceIdentifier m_quoting_service;
};

class STRATEGY_EXPORT CurrentQuotes::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleQuoteIdentifierMapping(const StreamIdentifier & stream, const QuoteIdentifierMapping & quote_info) = 0;
    virtual void HandleCurrentQuotes(const StreamIdentifier & stream, const CurrentQuotes::Update & quotes) = 0;

protected:
    virtual ~IHandler();
};
}

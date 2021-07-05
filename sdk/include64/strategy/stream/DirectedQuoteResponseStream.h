#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteResponse stream.
//****************************************************************************************

#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream/StreamOptions.h"
#include "strategy/stream_throttle/CommonThrottle.h"
#include "strategy/directed_quoting/DirectedQuoteResponse.h"
#include "strategy/type/QuoteRequestIdentifier.h"
#include "strategy/type/DirectedQuoteResponseIdentifier.h"
#include "strategy/type/MIC.h"
#include "strategy/Value.h"
#include "strategy/Types.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * DirectedQuoteResponse::Stream class is an interface to receive snapshots
 * and/or live directed quote response.
 *
 */
class STRATEGY_EXPORT DirectedQuoteResponse::Stream : public tbricks::Stream
{
public:
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByQuoteRequestIdentifier;
        class ByIdentifier;
        class ByInstrument;
        class Deleted;
        class ByCounterpart;
        class ByMIC;
    };

    class IHandler;
    using Options = StreamOptions<Filters::Filter, BasicThrottle>;

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    Stream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    Stream(IHandler & handler);

    /**
     * %Set callback interface.
     *
     * Associates current stream object with a callback interface where
     * stream updates will be delivered to.
     *
     * If stream is already opened this method has no effect.
     *
     * @param handler                   Callback interface
     */
    void SetCallback(IHandler & handler);

    /**
     * Open a stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param definitions               Parameter definitions
     * @param filter                    Stream event filter
     * @param coalescing                Enable coalescing of stream data
     */
    void Open(Type type, const Filters::Filter & filter, bool coalescing = true);

    /**
     * Open a stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Options
     */
    void Open(Type type, const Options & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * DirectedQuoteResponse::Stream::IHandler class is a callback interface to
 * handle instrument parameter stream events.
 *
 * @see DirectedQuoteResponse::Stream
 */
class STRATEGY_EXPORT DirectedQuoteResponse::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * DirectedQuoteResponse update stream handler.
     *
     * Method is called when a new instrument order update becomes
     * available on the stream.
     *
     * @param stream                   Stream identifier
     * @param update                   Update data
     */
    virtual void HandleDirectedQuoteResponseUpdate(const StreamIdentifier & stream, const DirectedQuoteResponse & update) = 0;

    /**
     * DirectedQuoteResponse stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits the filtering criteria.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated quote
     */
    virtual void HandleDirectedQuoteResponseInvalidate(const StreamIdentifier & stream, const DirectedQuoteResponseIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};

class STRATEGY_EXPORT DirectedQuoteResponse::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Filter & filter);
    virtual ~Filter();

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

class STRATEGY_EXPORT DirectedQuoteResponse::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    DirectedQuoteResponse::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    DirectedQuoteResponse::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    DirectedQuoteResponse::Stream::Filters::Filter operator||(const Filter & cond) const;
    DirectedQuoteResponse::Stream::Filters::Filter operator&&(const Filter & cond) const;
    DirectedQuoteResponse::Stream::Filters::Filter operator!() const;
    operator DirectedQuoteResponse::Stream::Filters::Filter() const;
};

class STRATEGY_EXPORT DirectedQuoteResponse::Stream::Filters::ByQuoteRequestIdentifier
    : public DirectedQuoteResponse::Stream::Filters::FilterCondition
{
public:
    ByQuoteRequestIdentifier(const QuoteRequestIdentifier & quote_request_id);
    ByQuoteRequestIdentifier(const ByQuoteRequestIdentifier & filter);
    virtual ~ByQuoteRequestIdentifier();

    ByQuoteRequestIdentifier & operator=(const ByQuoteRequestIdentifier & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    QuoteRequestIdentifier m_quote_request_id;
};

class STRATEGY_EXPORT DirectedQuoteResponse::Stream::Filters::ByIdentifier : public DirectedQuoteResponse::Stream::Filters::FilterCondition
{
public:
    ByIdentifier(const DirectedQuoteResponseIdentifier & id);
    ByIdentifier(const ByIdentifier & filter);
    virtual ~ByIdentifier();

    ByIdentifier & operator=(const ByIdentifier & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DirectedQuoteResponseIdentifier m_idq_id;
};

class STRATEGY_EXPORT DirectedQuoteResponse::Stream::Filters::ByInstrument : public DirectedQuoteResponse::Stream::Filters::FilterCondition
{
public:
    ByInstrument(const InstrumentIdentifier & instrument_id);
    ByInstrument(const ByInstrument & filter);
    virtual ~ByInstrument();

    ByInstrument & operator=(const ByInstrument & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentIdentifier m_instrument_id;
};

class STRATEGY_EXPORT DirectedQuoteResponse::Stream::Filters::ByCounterpart : public DirectedQuoteResponse::Stream::Filters::FilterCondition
{
public:
    ByCounterpart(const String & cp);
    virtual ~ByCounterpart();

    ByCounterpart & operator=(const ByCounterpart & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    String m_counterpart;
};

class STRATEGY_EXPORT DirectedQuoteResponse::Stream::Filters::ByMIC : public DirectedQuoteResponse::Stream::Filters::FilterCondition
{
public:
    ByMIC(const MIC & mic);
    ByMIC(const ByMIC & filter);
    virtual ~ByMIC();

    ByMIC & operator=(const ByMIC & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    MIC m_mic;
};

class STRATEGY_EXPORT DirectedQuoteResponse::Stream::Filters::Deleted : public DirectedQuoteResponse::Stream::Filters::FilterCondition
{
public:
    Deleted();
    Deleted(bool deleted);
    Deleted(const Deleted & filter);
    virtual ~Deleted() = default;
    Deleted & operator=(const Deleted & filter);

    void SetDeleted(bool deleted);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Value<bool> m_deleted;
};
}

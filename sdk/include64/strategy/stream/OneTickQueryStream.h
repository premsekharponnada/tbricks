#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OneTick Query Stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/stream/Stream.h"

#include "strategy/Hash.h"
#include "strategy/Instrument.h"
#include "strategy/type/Variant.h"

#include <memory>

namespace tbricks {

/**
 * OneTickQueryStream class
 */
class STRATEGY_EXPORT OneTickQueryStream : public Stream
{
public:
    class IHandler;

public:
    class Options;
    class Event;

public:
    OneTickQueryStream();
    OneTickQueryStream(IHandler & handler);

public:
    void SetCallback(IHandler & handler);

    void Open(Type type, const Options & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * OneTickQueryStream::IHandler class
 */
class STRATEGY_EXPORT OneTickQueryStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleEvent(const StreamIdentifier & stream, const Event & event) = 0;

    virtual void HandleError(const StreamIdentifier & stream, const String & error) = 0;

protected:
    virtual ~IHandler();
};

/**
 * OneTickQueryStream::Options class
 */
class STRATEGY_EXPORT OneTickQueryStream::Options : public Printable
{
public:
    void SetContext(const String & context) { m_context = context; }

    const String & GetContext() const { return m_context; }

    void SetUser(const String & user) { m_user = user; }

    const String & GetUser() const { return m_user; }

    /**
     * Path to OTQ file
     */
    void SetOTQFile(const String & otq_file) { m_otq_file = otq_file; }

    const String & GetOTQFile() const { return m_otq_file; }

    /**
     * Name of query in the OTQ file
     */
    void SetOTQQuery(const String & otq_query) { m_otq_query = otq_query; }

    const String & GetOTQQuery() const { return m_otq_query; }

    /**
     * query parameters
     */
    void SetQueryParameter(const String & name, const String & value) { m_query_parameters[name] = value; }

    const std::map<String, String> & GetQueryParameter() const { return m_query_parameters; }

public:
    static String GetInstrumentSymbol(const InstrumentIdentifier & instrument, const MIC & mic);

    void AddSymbol(const std::string & symbol) { m_symbols.push_back(symbol); }

    const std::vector<std::string> & GetSymbols() const { return m_symbols; }

    /**
     * Request 'from' - 'to'
     */
    void SetTimeRange(const DateTime & from, const DateTime & to)
    {
        m_from = from;
        m_to = to;
    }

    const DateTime & GetFromDateTime() const { return m_from; }

    const DateTime & GetToDateTime() const { return m_to; }

private:
    std::ostream & Print(std::ostream & strm) const override;

private:
    String m_context;
    String m_user;
    String m_otq_file;
    String m_otq_query;

    std::vector<std::string> m_symbols;
    DateTime m_from;
    DateTime m_to;

    std::map<String, String> m_query_parameters;
};

/**
 * OneTickQueryStream::Event class
 */
class STRATEGY_EXPORT OneTickQueryStream::Event : public Printable
{
public:
    const DateTime & GetDateTime() const { return m_timestamp; }

    const InstrumentIdentifier & GetInstrumentIdentifier() const { return m_instrument_id; }

    const MIC & GetMIC() const { return m_mic; }

    /**
     * Original symbology
     */
    const String & GetSymbol() const { return m_symbol; }

    const Hash<String, Variant> & GetValues() const { return m_values; }

private:
    std::ostream & Print(std::ostream & strm) const override;

    friend STRATEGY_EXPORT class StrategyStreamImpl;

private:
    DateTime m_timestamp;
    InstrumentIdentifier m_instrument_id;
    MIC m_mic;
    String m_symbol;
    Hash<String, Variant> m_values;
};

} // namespace tbricks

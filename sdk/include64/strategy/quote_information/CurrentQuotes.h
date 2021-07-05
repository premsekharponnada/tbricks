#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CurrentQuotes container.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Strategy.h"
#include "strategy/Hash.h"

namespace tbricks {

class STRATEGY_EXPORT QuoteData : public Printable
{
public:
    enum class QuoteStatus
    {
        OK = 0,
        NO_TICK_RULE = 1,
        TRADING_NOT_ALLOWED = 2,
        NOT_ENOUGH_VOLUME = 3,
        TOO_MUCH_VOLUME = 4,
        EXPOSURE_LIMIT_CHECK_FAILED = 5,
        DESIRED_VOLUME_LESS_THAN_MINIMUM = 6,
        DISABLED = 7,
        COALESCING = 8
    };

public:
    QuoteData(const Identifier & id, const Price & bid, const Price & ask, const Volume & bid_volume, const Volume & ask_volume) :
        m_identifier(id),
        m_bid_price(bid),
        m_ask_price(ask),
        m_bid_volume(bid_volume),
        m_ask_volume(ask_volume)
    {}

    QuoteData() {}

    const Identifier & GetQuoteIdentifier() const { return m_identifier; }

    const Price & GetBidPrice() const { return m_bid_price; }

    const Price & GetAskPrice() const { return m_ask_price; }

    const Volume & GetBidVolume() const { return m_bid_volume; }

    const Volume & GetAskVolume() const { return m_ask_volume; }

    const QuoteStatus & GetBidStatus() const { return m_bid_status; }

    const QuoteStatus & GetAskStatus() const { return m_ask_status; }

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

private:
    Identifier m_identifier;
    Price m_bid_price;
    Price m_ask_price;
    Volume m_bid_volume;
    Volume m_ask_volume;
    QuoteStatus m_bid_status = QuoteStatus::OK;
    QuoteStatus m_ask_status = QuoteStatus::OK;
};

class STRATEGY_EXPORT CurrentQuotes : public Printable
{
public:
    typedef Hash<Identifier, QuoteData> CurrentQuotesData;

public:
    class Update;
    class Stream;

public:
    CurrentQuotes(const Identifier & quote_set_id) : m_quote_set_identifier(quote_set_id) {}

    const Identifier & GetQuoteSetIdentifier() const { return m_quote_set_identifier; }

    const CurrentQuotesData & GetCurrentQuotesData() const { return m_quotes_data; }

    void Merge(const Update & update);

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_quote_set_identifier;
    CurrentQuotesData m_quotes_data;
};

class STRATEGY_EXPORT CurrentQuotes::Update : public Printable
{
public:
    typedef Hash<Identifier, QuoteData> CurrentQuotesData;

public:
    Update() {}

    const Identifier & GetQuoteSetIdentifier() const { return m_quote_set_identifier; }

    const CurrentQuotesData & GetCurrentQuotesData() const { return m_quotes_data; }

    bool Empty() const { return m_quotes_data.empty(); }

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

private:
    Identifier m_quote_set_identifier;
    CurrentQuotesData m_quotes_data;
};

namespace strategy {
class QuoteStreamImpl;
class QuoteIdentifierMappingStreamImpl;
}
}

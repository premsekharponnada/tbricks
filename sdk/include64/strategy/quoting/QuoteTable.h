#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteTable object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/Strategy.h"

#include "strategy/SparseHash.h"

#include "strategy/quoting/QuoteIdentification.h"
#include "strategy/quoting/Quote.h"

namespace tbricks {

class STRATEGY_EXPORT QuoteTable : public Printable
{
public:
    class Options;
    class Modifier;

public:
    QuoteTable() {}

    QuoteTable(const QuoteTable::Options & options);

    QuoteTable(const QuoteTable & table) :
        m_primary_identifier(table.m_primary_identifier),
        m_secondary_identifier(table.m_secondary_identifier),
        m_validity(table.m_validity)
    {}

    QuoteTable & operator=(const QuoteTable & table)
    {
        if (this != &table) {
            m_primary_identifier = table.m_primary_identifier;
            m_secondary_identifier = table.m_secondary_identifier;
            m_validity = table.m_validity;
        }
        return *this;
    }

    virtual ~QuoteTable() {}

public:
    const Integer & GetPrimaryIdentifier() const { return m_primary_identifier; }

    const Integer & GetSecondaryIdentifier() const { return m_secondary_identifier; }

    const Validity & GetValidity() const { return m_validity; }

    const Price & GetQuoteUnderlyingBid() const { return m_quote_underlying_bid; }

    const Price & GetQuoteUnderlyingAsk() const { return m_quote_underlying_ask; }

public:
    void Clear()
    {
        m_primary_identifier.Clear();
        m_secondary_identifier.Clear();
    }

    bool Empty() const { return m_primary_identifier.Empty() && m_secondary_identifier.Empty(); }

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class QuoteSet;
    friend STRATEGY_EXPORT class Converter;

private:
    Integer m_primary_identifier;
    Integer m_secondary_identifier;
    Validity m_validity;
    Price m_quote_underlying_bid;
    Price m_quote_underlying_ask;
};

//****************************************************************************
// Options class
//****************************************************************************

class STRATEGY_EXPORT QuoteTable::Options : public Printable
{
public:
    Options() {}

public:
    void SetIdentifier(const Integer & primary_identifier, const Integer & secondary_identifier)
    {
        m_primary_identifier = primary_identifier;
        m_secondary_identifier = secondary_identifier;
    }

    const Integer & GetPrimaryIdentifier() const { return m_primary_identifier; }

    const Integer & GetSecondaryIdentifier() const { return m_secondary_identifier; }

    void SetValidity(const Validity & validity) { m_validity = validity; }
    const Validity & GetValidity() const { return m_validity; }

    void SetQuoteUnderlyingBid(const Price & bid) { m_quote_underlying_bid = bid; }
    const Price & GetQuoteUnderlyingBid() const { return m_quote_underlying_bid; }

    void SetQuoteUnderlyingAsk(const Price & ask) { m_quote_underlying_ask = ask; }
    const Price & GetQuoteUnderlyingAsk() const { return m_quote_underlying_ask; }

public:
    void Clear()
    {
        m_primary_identifier.Clear();
        m_secondary_identifier.Clear();
        m_validity.Clear();
    }

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Integer m_primary_identifier;
    Integer m_secondary_identifier;
    Validity m_validity;
    Price m_quote_underlying_bid;
    Price m_quote_underlying_ask;
};

//****************************************************************************
// Modifier class
//****************************************************************************

class STRATEGY_EXPORT QuoteTable::Modifier : public Printable
{
public:
    Modifier();
    Modifier(const Integer & primary_identifier, const Integer & secondary_identifier);
    Modifier(const Modifier & modifier);
    Modifier & operator=(const Modifier & modifier);
    virtual ~Modifier();

public:
    void SetIdentifier(const Integer & primary_identifier, const Integer & secondary_identifier)
    {
        m_primary_identifier = primary_identifier;
        m_secondary_identifier = secondary_identifier;
    }

    const Integer & GetPrimaryIdentifier() const { return m_primary_identifier; }
    const Integer & GetSecondaryIdentifier() const { return m_secondary_identifier; }

    void ModifyQuote(const QuoteIdentification & id, const Quote & quote);
    void ModifyQuote(const Identifier & id, const Quote & quote);

    void DeleteQuote(const QuoteIdentification & id);
    void DeleteQuote(const Identifier & id);

    bool HasModifications() const;

public:
    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class QuoteTable;
    friend STRATEGY_EXPORT class Converter;
    friend STRATEGY_EXPORT class QuoteSet;

    enum Action
    {
        Modify = 1,
        Delete
    };

    struct Entry
    {
        Entry(const Identifier & pidentifier, const Action & paction, const Quote & pquote);

        bool operator<(const Entry & other) const;

        Identifier identifier;
        QuoteTable::Modifier::Action action;
        Quote quote;
    };

    void sort();

private:
    Integer m_primary_identifier;
    Integer m_secondary_identifier;
    std::vector<Entry> m_entries;
};

} // namespace tbricks

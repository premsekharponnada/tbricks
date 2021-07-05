#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteTableUpdate
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/quoting/QuoteTable.h"
#include "strategy/type/Identifier.h"

namespace tbricks {
class Converter;

namespace protocol {
class QuoteTable;
class QuoteSetActiveTable;
}

namespace test {

class STRATEGY_EXPORT QuoteTableUpdate : public Printable
{
public:
    class Entry;
    typedef protocol::QuoteTable update_t;

    QuoteTableUpdate(const QuoteTableUpdate & update);
    QuoteTableUpdate(update_t * update);
    QuoteTableUpdate & operator=(const QuoteTableUpdate & update);
    virtual ~QuoteTableUpdate();

public:
    bool HasAlgoLabelOperationIdentifier() const;
    std::vector<uint32_t> GetAlgoLabelOperationIdentifier() const;

    bool HasHostCreatedDatetime() const;
    DateTime GetHostCreatedDatetime() const;

    bool HasHostModifiedDatetime() const;
    DateTime GetHostModifiedDatetime() const;

    bool HasOperatingServiceInstanceIdentifier() const;
    Identifier GetOperatingServiceInstanceIdentifier() const;

    bool HasOperatingStrategyIdentifier() const;
    StrategyIdentifier GetOperatingStrategyIdentifier() const;

    bool HasOperator() const;
    UserIdentifier GetOperator() const;

    bool HasQuoteSetIdentifier() const;
    Identifier GetQuoteSetIdentifier() const;

    bool HasQuoteTablePrimaryIdentifier() const;
    Integer GetQuoteTablePrimaryIdentifier() const;

    bool HasQuoteTableSecondaryIdentifier() const;
    Integer GetQuoteTableSecondaryIdentifier() const;

    bool HasQuoteSetUnderlyingAsk() const;
    Price GetQuoteSetUnderlyingAsk() const;

    bool HasQuoteSetUnderlyingBid() const;
    Price GetQuoteSetUnderlyingBid() const;

    bool HasQuotes() const;
    const std::vector<Entry> & GetQuotes() const;

    bool HasRequestIdentifier() const;
    Identifier GetRequestIdentifier() const;

public:
    void Clear();
    bool Empty() const;

public:
    class Entry : public Printable
    {
    public:
        enum Action
        {
            Modify = 1,
            Delete
        };

    public:
        Entry(const Entry & entry) = default;
        Entry(const QuoteIdentification & id, Action action, const Quote & quote);
        ~Entry() override = default;

        Entry & operator=(const Entry & entry) = default;

    public:
        const QuoteIdentification & GetQuoteIdentification() const { return m_quote_id; }
        const Action & GetAction() const { return m_action; }
        const tbricks::Quote & GetQuote() const { return m_quote; }

    public:
        std::ostream & Print(std::ostream & strm) const override;

    private:
        Entry() = delete;
        QuoteIdentification m_quote_id;
        Action m_action;
        tbricks::Quote m_quote;
    };

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    const update_t & get_update() const;
    update_t & get_update();

private:
    friend STRATEGY_EXPORT class tbricks::Converter;

private:
    QuoteTableUpdate() = delete;
    std::vector<Entry> m_entries;
    update_t * m_update;
};

class STRATEGY_EXPORT QuoteTableIdentification : public Printable
{
public:
    typedef protocol::QuoteSetActiveTable table_t;

    QuoteTableIdentification();
    QuoteTableIdentification(const QuoteTableIdentification & table);
    QuoteTableIdentification(table_t * table);
    QuoteTableIdentification & operator=(const QuoteTableIdentification & table);
    virtual ~QuoteTableIdentification();

public:
    bool HasAlgoLabelOperationIdentifier() const;
    std::vector<uint32_t> GetAlgoLabelOperationIdentifier() const;
    void SetAlgoLabelOperationIdentifier(const std::vector<uint32_t> & algo_mapping);

    bool HasOperatingStrategyIdentifier() const;
    StrategyIdentifier GetOperatingStrategyIdentifier() const;
    void SetOperatingStrategyIdentifier(const StrategyIdentifier & id);

    bool HasOperator() const;
    UserIdentifier GetOperator() const;
    void SetOperator(const UserIdentifier & user);

    bool HasQuoteSetIdentifier() const;
    Identifier GetQuoteSetIdentifier() const;
    void SetQuoteSetIdentifier(const Identifier & id);

    bool HasQuoteTablePrimaryIdentifier() const;
    Integer GetQuoteTablePrimaryIdentifier() const;
    void SetQuoteTablePrimaryIdentifier(const Integer & id);

    bool HasQuoteTableSecondaryIdentifier() const;
    Integer GetQuoteTableSecondaryIdentifier() const;
    void SetQuoteTableSecondaryIdentifier(const Integer & id);

    bool HasRequestIdentifier() const;
    Identifier GetRequestIdentifier() const;
    void SetRequestIdentifier(const Identifier & id);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    const table_t & get_table() const;
    table_t & get_table();

private:
    table_t * m_table;
};

} // \namespace test
} // \namespace tbricks

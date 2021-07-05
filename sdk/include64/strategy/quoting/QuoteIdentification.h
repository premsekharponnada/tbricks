#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Quote identifier object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/InstrumentVenueIdentification.h"

#include "strategy/Definitions.h"

namespace tbricks {

class STRATEGY_EXPORT QuoteIdentification : public Printable
{
private:
    friend STRATEGY_EXPORT class QuoteSet;
    friend STRATEGY_EXPORT class QuoteIdentifierMapping;
    friend STRATEGY_EXPORT class Converter;

    QuoteIdentification(const InstrumentVenueIdentification & ivid, const QuoteMode & mode, const Integer & level, const Identifier & id) :
        m_ivid(ivid),
        m_mode(mode),
        m_level(level),
        m_identifier(id)
    {}

public:
    QuoteIdentification() : m_mode(QuoteModeQuoting) {}
    QuoteIdentification(const QuoteIdentification & quote_identifier) :
        m_ivid(quote_identifier.m_ivid),
        m_mode(quote_identifier.m_mode),
        m_level(quote_identifier.m_level),
        m_identifier(quote_identifier.m_identifier)
    {}

    QuoteIdentification & operator=(const QuoteIdentification & quote_identifier)
    {
        m_ivid = quote_identifier.m_ivid;
        m_mode = quote_identifier.m_mode;
        m_level = quote_identifier.m_level;
        m_identifier = quote_identifier.m_identifier;
        return *this;
    }
    virtual ~QuoteIdentification() {}

    bool operator==(const QuoteIdentification & quote_identifier) const { return m_identifier == quote_identifier.m_identifier; }
    bool operator!=(const QuoteIdentification & quote_identifier) const { return m_identifier != quote_identifier.m_identifier; }
    bool operator<(const QuoteIdentification & quote_identifier) const { return m_identifier < quote_identifier.m_identifier; }
    bool operator<=(const QuoteIdentification & quote_identifier) const { return m_identifier <= quote_identifier.m_identifier; }
    bool operator>(const QuoteIdentification & quote_identifier) const { return m_identifier > quote_identifier.m_identifier; }
    bool operator>=(const QuoteIdentification & quote_identifier) const { return m_identifier >= quote_identifier.m_identifier; }

    bool ValidateVenue(const VenueIdentifier & venue_identifier) const { return GetIVID().GetVenueIdentifier() == venue_identifier; }

    static Identifier CreateInstrumentDependentIdentifier(const InstrumentVenueIdentification & ivid,
                                                          const Identifier & quote_set_identifier,
                                                          const QuoteMode & mode,
                                                          const Integer & level);

public:
    const InstrumentVenueIdentification & GetIVID() const { return m_ivid; }

    const QuoteMode & GetQuoteMode() const { return m_mode; }

    const Identifier & GetQuoteIdentifier() const { return m_identifier; }

    const Integer & GetLevel() const { return m_level; }

public:
    void Clear()
    {
        m_ivid.Clear();
        m_mode = QuoteModeQuoting;
        m_level.Clear();
        m_identifier.Clear();
    }
    bool Empty() const { return m_identifier.Empty(); }

    size_t GetHash() const { return m_identifier.GetHash(); }

    friend size_t hash_value(const QuoteIdentification & value) { return value.GetHash(); }

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentVenueIdentification m_ivid;
    QuoteMode m_mode;
    Integer m_level;
    Identifier m_identifier;
};

} // namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Quote identifier object
//****************************************************************************************

#include "strategy/quoting/QuoteIdentification.h"

namespace tbricks {

class STRATEGY_EXPORT QuoteIdentifierMapping : public Printable
{
public:
    QuoteIdentifierMapping() {}

    QuoteIdentifierMapping(const InstrumentVenueIdentification & ivid,
                           const QuoteMode & mode,
                           const Integer & level,
                           const Identifier & quote_id,
                           const Identifier & quote_set_id) :
        m_quote_identification(ivid, mode, level, quote_id),
        m_quote_set_identifier(quote_set_id)
    {}
    virtual ~QuoteIdentifierMapping() {}

    const QuoteIdentification & GetQuoteIdentification() const { return m_quote_identification; }

    const Identifier & GetQuoteSetIdentifier() const { return m_quote_set_identifier; }

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

    QuoteIdentification m_quote_identification;
    Identifier m_quote_set_identifier;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteFill object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/quoting/QuoteIdentification.h"

namespace tbricks {

enum QuoteFillLogic
{
    ATTRIBUTE,
    HEDGE,
    ATTRIBUTE_AND_HEDGE
};

class STRATEGY_EXPORT QuoteFill : public Printable
{
public:
    class Stream;

public:
    QuoteFill() : m_logic(ATTRIBUTE_AND_HEDGE), m_mode(QuoteModeQuoting) {}
    QuoteFill(const QuoteFill & quote_fill) = default;
    QuoteFill & operator=(const QuoteFill & quote_fill) = default;
    virtual ~QuoteFill() = default;

public:
    const Identifier & GetQuoteIdentifier() const { return m_quote_identifier; }
    const InstrumentIdentifier & GetInstrumentIdentifier() const { return m_instrument_identifier; }
    const Identifier & GetQuoteSetIdentifier() const { return m_quote_set_identifier; }
    const Integer & GetPrimaryQuoteTableIdentifier() const { return m_quote_table_primary_identifier; }
    const Integer & GetSecondaryQuoteTableIdentifier() const { return m_quote_table_secondary_identifier; }
    const Side & GetSide() const { return m_side; }
    const Volume & GetVolume() const { return m_volume; }
    const Price & GetEstimatedPrice() const { return m_estimated_price; }
    const Price & GetQuoteUnderlyingBid() const { return m_quote_underlying_bid; }
    const Price & GetQuoteUnderlyingAsk() const { return m_quote_underlying_ask; }
    const QuoteFillLogic & GetLogic() const { return m_logic; }
    QuoteMode GetQuoteMode() const { return m_mode; }
    const Integer & GetQuoteLevel() const { return m_level; }
    const ExPitIdentifier & GetExPitIdentifier() const { return m_expit_identifier; }

public:
    void Clear()
    {
        m_quote_identifier.Clear();
        m_instrument_identifier.Clear();
        m_quote_set_identifier.Clear();
        m_side.Clear();
        m_volume.Clear();
        m_estimated_price.Clear();
        m_quote_underlying_bid.Clear();
        m_quote_underlying_ask.Clear();
        m_logic = ATTRIBUTE_AND_HEDGE;
        m_mode = QuoteModeQuoting;
        m_level.Clear();
        m_expit_identifier.Clear();
    }

    bool Empty() const { return m_quote_identifier.Empty() || m_quote_set_identifier.Empty(); }

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

private:
    Identifier m_quote_identifier;
    InstrumentIdentifier m_instrument_identifier;
    Identifier m_quote_set_identifier;
    Integer m_quote_table_primary_identifier;
    Integer m_quote_table_secondary_identifier;
    Side m_side;
    Volume m_volume;
    Price m_estimated_price;
    Price m_quote_underlying_bid;
    Price m_quote_underlying_ask;
    QuoteFillLogic m_logic;
    QuoteMode m_mode;
    Integer m_level;
    ExPitIdentifier m_expit_identifier;
};

} // namespace tbricks

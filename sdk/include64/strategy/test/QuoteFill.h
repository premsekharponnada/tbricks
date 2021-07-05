#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteFill
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/quoting/QuoteFill.h"

namespace tbricks {

namespace protocol {
class QuoteFill;
}

namespace test {

class STRATEGY_EXPORT QuoteFill : public Printable
{
public:
    typedef protocol::QuoteFill quote_fill_t;

    QuoteFill();
    QuoteFill(const QuoteFill & quote_fill);
    QuoteFill(quote_fill_t * quote_fill);
    QuoteFill & operator=(const QuoteFill & quote_fill);
    virtual ~QuoteFill();

public:
    bool HasQuoteIdentifier() const;
    Identifier GetQuoteIdentifier() const;
    void SetQuoteIdentifier(const Identifier & id);

    bool HasInstrumentIdentifier() const;
    InstrumentIdentifier GetInstrumentIdentifier() const;
    void SetInstrumentIdentifier(const InstrumentIdentifier & id);

    bool HasQuoteSetIdentifier() const;
    Identifier GetQuoteSetIdentifier() const;
    void SetQuoteSetIdentifier(const Identifier & id);

    bool HasPrimaryQuoteTableIdentifier() const;
    Integer GetPrimaryQuoteTableIdentifier() const;
    void SetPrimaryQuoteTableIdentifier(const Integer & id);

    bool HasSecondaryQuoteTableIdentifier() const;
    Integer GetSecondaryQuoteTableIdentifier() const;
    void SetSecondaryQuoteTableIdentifier(const Integer & id);

    bool HasSide() const;
    Side GetSide() const;
    void SetSide(const Side & side);

    bool HasVolume() const;
    Volume GetVolume() const;
    void SetVolume(const Volume & volume);

    bool HasEstimatedPrice() const;
    Price GetEstimatedPrice() const;
    void SetEstimatedPrice(const Price & price);

    bool HasQuoteUnderlyingBid() const;
    Price GetQuoteUnderlyingBid() const;
    void SetQuoteUnderlyingBid(const Price & price);

    bool HasQuoteUnderlyingAsk() const;
    Price GetQuoteUnderlyingAsk() const;
    void SetQuoteUnderlyingAsk(const Price & price);

    bool HasLogic() const;
    QuoteFillLogic GetLogic() const;
    void SetLogic(const QuoteFillLogic & logic);

    bool HasQuoteMode() const;
    QuoteMode GetQuoteMode() const;
    void SetQuoteMode(const QuoteMode & mode);

    bool HasQuoteLevel() const;
    Integer GetQuoteLevel() const;
    void SetQuoteLevel(const Integer & level);

    bool HasExPitIdentifier() const;
    ExPitIdentifier GetExPitIdentifier() const;
    void SetExPitIdentifier(const ExPitIdentifier & id);

public:
    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    const quote_fill_t & get_quote_fill() const;
    quote_fill_t & get_quote_fill();

private:
    quote_fill_t * m_quote_fill;
};

} // \namespace test
} // \namespace tbricks

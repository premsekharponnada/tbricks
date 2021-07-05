#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Auditable
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Order.h"
#include "strategy/Printable.h"
#include "strategy/Trade.h"
#include "strategy/ExPit.h"
#include "strategy/QuoteRequest.h"
#include "strategy/directed_quoting/DirectedQuoteResponse.h"
#include "strategy/quoting/QuoteAudit.h"
#include "strategy/quoting/QuoteSet.h"
#include "strategy/RequestForQuote.h"
#include "strategy/RequestForTrade.h"
#include "strategy/directed_quoting/DirectedQuote.h"
#include "strategy/directed_quoting/DirectedQuoteReject.h"
#include "strategy/directed_quoting/DirectedQuoteRequest.h"
#include "strategy/directed_quoting/DirectedRequestForQuote.h"

namespace tbricks {

namespace protocol {
class IMessage;
}

class STRATEGY_EXPORT Auditable : public Printable
{
public:
    enum Type
    {
        EMPTY = 0,
        QUOTE,
        QUOTESET,
        EXPIT,
        QUOTE_REQUEST,
        DIRECTED_QUOTE_RESPONSE,
        REQUEST_FOR_QUOTE,
        REQUEST_FOR_TRADE,
        DIRECTED_QUOTE,
        DIRECTED_QUOTE_REJECT,
        DIRECTED_QUOTE_REQUEST,
        DIRECTED_REQUEST_FOR_QUOTE
    };

    Auditable() = default;

    Auditable(const Auditable & auditable);
    virtual ~Auditable() = default;

    Auditable & operator=(const Auditable & auditable);

    Type GetType() const;
    QuoteAudit::Update GetQuote() const;
    QuoteSet::Update GetQuoteSet() const;
    ExPit::Update GetExPit() const;
    QuoteRequest GetQuoteRequest() const;
    DirectedQuoteResponse GetDirectedQuoteResponse() const;
    RequestForQuote GetRequestForQuote() const;
    RequestForTrade GetRequestForTrade() const;
    DirectedQuote GetDirectedQuote() const;
    DirectedQuoteReject GetDirectedQuoteReject() const;
    DirectedQuoteRequest GetDirectedQuoteRequest() const;
    DirectedRequestForQuote GetDirectedRequestForQuote() const;

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void CheckType(Auditable::Type type) const;

private:
    friend STRATEGY_EXPORT class Converter;

    std::shared_ptr<protocol::IMessage> m_msg;
};

std::ostream & operator<<(std::ostream & strm, Auditable::Type type);

} // namespace tbricks

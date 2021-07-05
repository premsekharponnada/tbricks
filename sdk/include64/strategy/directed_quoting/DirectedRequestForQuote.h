#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Direct request for quote class
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/DirectedRequestForQuoteBase.h"

namespace tbricks {

class STRATEGY_EXPORT DirectedRequestForQuote : public DirectedRequestForQuoteBase
{
public:
    class Stream;

public:
    DirectedRequestForQuote() = default;
    DirectedRequestForQuote(const protocol::DirectedRequestForQuote & value) : DirectedRequestForQuoteBase(value) {}
    virtual ~DirectedRequestForQuote();

    bool HasDealtCurrency() const;
    Currency GetDealtCurrency() const;
    bool GetDealtCurrency(Currency & dealtCurrency) const;
    void SetDealtCurrency(const Currency & dealtCurrency);

    void Merge(const DirectedRequestForQuote & value);
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Quote.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/quoting/Quote.h"
#include "strategy/test/QuoteData.h"
#include "strategy_generated/TestQuoteBase.h"

namespace tbricks {

namespace protocol {
class Quote;
}

namespace test {

class STRATEGY_EXPORT Quote : public TestQuoteBase
{
public:
    Quote() = default;
    using TestQuoteBase::Merge;
    using TestQuoteBase::TestQuoteBase;

    CurrentQuotesData GetQuotesData() const;
    void SetQuotesData(const CurrentQuotesData & quotesData);
    bool HasQuotesData() const;
};

} // \namespace test

} // \namespace tbricks

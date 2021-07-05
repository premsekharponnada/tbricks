#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteAudit.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy_generated/TestQuoteAuditBase.h"

namespace tbricks::test {

class STRATEGY_EXPORT QuoteAudit : public TestQuoteAuditBase
{
public:
    QuoteAudit() = default;
    using TestQuoteAuditBase::Merge;
    using TestQuoteAuditBase::TestQuoteAuditBase;
};
} // namespace tbricks::test

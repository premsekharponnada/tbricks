#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForQuoteProvider
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/Linkage.h"
#include "strategy/RequestForQuote.h"

namespace tbricks {

class MatchingApp;

class STRATEGY_EXPORT RequestForQuoteProvider
{
private:
    friend class MatchingApp;
    RequestForQuoteProvider();
    virtual ~RequestForQuoteProvider() = default;

public:
    /*
     * Send Request For Quote to tbricks. Must be used only on Matching Engine
     * @param      RequestForQuote. Reference must be passed to set Request identifier.
     *
     * @return         Identifier of RequestForQuote in a system.
     */
    Identifier CreateRequestForQuote(RequestForQuote & quote);

    /**
     * Send Request For Quote to tbricks. Must be used only on Matching Engine
     * @param       RequestForQuote.
     *              Duration    Duration after which RFQ will be closed.
     *
     * @return         Identifier of RequestForQuote in a system.
     */
    Identifier CreateRequestForQuote(RequestForQuote & quote, const Duration & lifeTime);

    /*
     * Delete previously send RequestForQuote
     *
     * @param       Identifier returned by Create method
     */
    void DeleteRequestForQuote(const Identifier & rfqId);
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteResponse
//****************************************************************************************

#include <vector>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/DirectedQuoteResponseBase.h"

namespace tbricks {

class DirectedQuoteLeg;

class STRATEGY_EXPORT DirectedQuoteResponse : public DirectedQuoteResponseBase
{
public:
    class Stream;

public:
    DirectedQuoteResponse() = default;
    DirectedQuoteResponse(const protocol::DirectedQuoteResponse & value) : DirectedQuoteResponseBase(value) {}

public:
    /**
     * @deprecated Deprecated in 2.14.0.
     *             UseSetLegs(...) instead of SetDirectedQuoteLegs(...).
     */
    [[deprecated(DEPRECATE_LINK)]] void SetDirectedQuoteLegs(const std::vector<tbricks::DirectedQuoteLeg> & legs);

    /**
     * @deprecated Deprecated in 2.14.0.
     *             Use GetLegs(...) instead of GetDirectedQuoteLegs(...).
     */
    [[deprecated(DEPRECATE_LINK)]] void GetDirectedQuoteLegs(std::vector<tbricks::DirectedQuoteLeg> & legs) const;

    void SetLegs(const std::vector<tbricks::DirectedQuoteLeg> & legs);

    void GetLegs(std::vector<tbricks::DirectedQuoteLeg> & legs) const;

    void Merge(const DirectedQuoteResponse & update);

private:
    friend class Trading;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByTradingServiceTradeIdentifierFilter, matches trades by trading
// service trade identifier.
//****************************************************************************************

#include "strategy/type/String.h"
#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

/**
 * TradeByTradingServiceTradeIdentifier matches all trades with trading service trade identifier
 * provided as filter argument.
 */
class STRATEGY_EXPORT TradeByTradingServiceTradeIdentifierFilter : public TradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the trades having trading service trade identifier
     * as specified in the input parameter.
     *
     * @param id                            Instance of String
     */
    TradeByTradingServiceTradeIdentifierFilter(const String & id);
    TradeByTradingServiceTradeIdentifierFilter(const TradeByTradingServiceTradeIdentifierFilter & filter);

    TradeByTradingServiceTradeIdentifierFilter & operator=(const TradeByTradingServiceTradeIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    String m_id;
};
}

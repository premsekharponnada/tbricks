#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByParentFilter, matches all trades originated by the strategy.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/StrategyData.h"
#include "strategy/type/Identifier.h"
#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

/**
 * TradeByParentFilter matches all trades generated in response to orders
 * directly created by a given strategy.
 *
 * NOTE: The filter does not match indirect
 * trades, that is, if strategy S1 creates strategy S2 and S2 sends an
 * order that gets traded, the trade for this event will not match the filter. However,
 * if order originates from S1, the trade would match the filter.
 */
class STRATEGY_EXPORT TradeByParentFilter : public TradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the trades generated from
     * parent strategy as specified in the input parameter.
     *
     * @param parent                            Instance of the Strategy to specify the parent
                                                strategy, on basis of which trades will be filtered.
     */
    TradeByParentFilter(const Strategy & parent);

    /**
     * Constructor.
     *
     * Makes a filter to match all the trades having
     * parent StrategyData as specified in the input parameter.
     *
     * @param parent                           Instance of StrategyData to specify the parent
                                               strategy, on basis of which trades will be filtered.
     */
    TradeByParentFilter(const StrategyData & parent);

    /**
     * Constructor.
     *
     * Makes a filter to match all the trades having
     * parent strategy identifier as specified in the input parameter.
     *
     * @param parent                           Instance of the parent strategy identifier to specify the parent
                                               strategy, on basis of which trades will be filtered.
     */
    TradeByParentFilter(const StrategyIdentifier & parent);
    TradeByParentFilter(const TradeByParentFilter & filter);

    TradeByParentFilter & operator=(const TradeByParentFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_parent;
};
}

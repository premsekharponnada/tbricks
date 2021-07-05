#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyByRootFilter, matches all strategies with common root identifier.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/StrategyData.h"
#include "strategy/type/Identifier.h"
#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

/**
 * StrategyByRootFilter matches all strategies in inheritance tree starting
 * from its top, "root" strategy. For instance, if user strategy S1 creates
 * another strategy S2 and the latter in turn creates an order strategy, the
 * order strategy and S2 will have their root identifiers set to S1.
 *
 * NOTE: Currently SE API does not allow to create root strategies, root
 *       strategies are instantiated by outside request, e.g. from the front-end
 *       client.
 *
 * NOTE: Root strategy itself also matches this filter because it has root
 *       identifier set to itself.
 */
class STRATEGY_EXPORT StrategyByRootFilter : public StrategyFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies having
     * root strategy as specified in the input parameter.
     *
     * @param root               Instance of strategy to specify the root strategy.
     */
    StrategyByRootFilter(const Strategy & root);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies having
     * root StrategyData as specified in the input parameter.
     *
     * @param root              Instance of StrategyData to specify the root strategy.
     */
    StrategyByRootFilter(const StrategyData & root);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies having
     * root strategy identifier as specified in the input parameter.
     *
     * @param root              Instance of StrategyIdentifier to specify the
                                root strategy.
     */
    StrategyByRootFilter(const StrategyIdentifier & root);
    StrategyByRootFilter(const StrategyByRootFilter & filter);

    /**
     * %Set the type of the root strategy for the filter.
     *
     * @param type              Type of the parent strategy.
                                In this method, type is specified by providing StrategyIdentifier
                                instance as an input parameter.
     */

    void SetType(const StrategyIdentifier & type);

    /**
     * %Set the type of the root strategy for the filter.
     *
     * @param type              Type of the parent strategy.
                                In this method, type is specified by providing Identifier
                                instance as an input parameter.
     */
    void SetType(const Identifier & type);

    StrategyByRootFilter & operator=(const StrategyByRootFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_type;
    StrategyIdentifier m_root;
};
}

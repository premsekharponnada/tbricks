#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyByAncestorFilter, matches strategy instances with given ancestor.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/StrategyData.h"
#include "strategy/type/Identifier.h"
#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

/**
 * StrategyByAncestorFilter matches strategy instances that have strategy
 * identifier provided as a filter argument in their inheritance tree, for
 * instance, if strategy S1 had created S2, S2 created S3 and S3, in turn,
 * created S4, then a filter with S2 as an argument will match S3 and S4.
 */
class STRATEGY_EXPORT StrategyByAncestorFilter : public StrategyFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the strategy instances
     * having an ancestor node as specified in the input parameter.
     *
     * @param ancestor              Instance of Strategy.
     */
    StrategyByAncestorFilter(const Strategy & ancestor);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategy instances
     * having ancestor node and root node as specified in the input parameters.
     *
     *  @param ancestor_id           Instance of StrategyIdentifier to specify
                                     the ancestor strategy.
     *
     *  @param root_id               Instance of StrategyIdentifier to specify
                                     the root strategy.
     */
    StrategyByAncestorFilter(const StrategyIdentifier & ancestor_id, const StrategyIdentifier & root_id);
    StrategyByAncestorFilter(const StrategyByAncestorFilter & filter);

    /**
     * %Set the type of strategy for the filter.
     *
     * @param type                  Instance of StrategyIdentifier to specify the type of strategy.
                                    In this method, type is specified by providing StrategyIdentifier
                                    instance as an input parameter.
     */
    void SetType(const StrategyIdentifier & type);

    /**
     * %Set the type of strategy for the filter.
     *
     * @param type                  Instance of Identifier to specify the type of strategy.
                                    In this method, type is specified by providing identifier instance
                                    as an input parameter.
     */
    void SetType(const Identifier & type);

    StrategyByAncestorFilter & operator=(const StrategyByAncestorFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_type;
    StrategyIdentifier m_ancestor;
    StrategyIdentifier m_root;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyByStateFilter allows to do filtering based on strategy state.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/StrategyStateSet.h"
#include "strategy/type/StrategyState.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

/**
 * StrategyByStateFilter mix-in, allows to improve stream granularity by
 * filtering out strategies of certain states.
 *
 * Filters of this kind can never be used on their own, rather they
 * must be a part of expression with other strategy filters.
 */
class STRATEGY_EXPORT StrategyByStateFilter : public StrategyFilterCondition
{
public:
    /// Default constructor.
    StrategyByStateFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies having strategy state
     * as specified in the input parameter.
     *
     * @param set                                      Instance of StrategyStateSet. To match all
                                                       the strategies having same state as that of
                                                       specified StrategyStateSet instance.
     */
    StrategyByStateFilter(const StrategyStateSet & set);
    StrategyByStateFilter(const StrategyByStateFilter & filter);
    ~StrategyByStateFilter();

    StrategyByStateFilter & operator=(const StrategyByStateFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyStateSet m_value;
};
}

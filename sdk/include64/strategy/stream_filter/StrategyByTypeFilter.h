#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyByTypeFilter, to match strategies of the specified type.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

/**
 * StrategyByTypeFilter matches strategy instances of the specified type
 * (e.g. Order strategies).
 */
class STRATEGY_EXPORT StrategyByTypeFilter : public StrategyFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies having strategy type
     * as that of the specified StrategyIdentifier instance in the input
     * parameter.
     *
     * @param type                          Instance of StrategyIdentifier to specify
                                            the type of the strategies to be filtered.
     */
    StrategyByTypeFilter(const StrategyIdentifier & type);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies having strategy type
     * as that of the specified Identifier instance in the input
     * parameter.
     *
     * @param type                          Instance of Identifier to specify
                                            the type of the strategies to be filtered.
     */
    StrategyByTypeFilter(const Identifier & type);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies having strategy type
     * as that of the specified Uuid instance in the input parameter.
     *
     * @param type                          Instance of Uuid to specify
                                            the type of the strategies to be filtered.
     */
    StrategyByTypeFilter(const StrategyByTypeFilter & filter);
    StrategyByTypeFilter(const Uuid & type);

    StrategyByTypeFilter & operator=(const StrategyByTypeFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_type;
};
}

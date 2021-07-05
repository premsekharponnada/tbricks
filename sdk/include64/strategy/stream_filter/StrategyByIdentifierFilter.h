#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyByIdentifierFilter, matches updates of concrete strategy instance.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/StrategyData.h"
#include "strategy/type/Identifier.h"
#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

/**
 * StrategyByIdentifierFilter matches concrete strategy instance updates,
 * selected by strategy identifier.
 */
class STRATEGY_EXPORT StrategyByIdentifierFilter : public StrategyFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the strategy instance as specified
     * in the input parameter.
     *
     * @param instance              Instance of the strategy to be matched.
     */
    StrategyByIdentifierFilter(const Strategy & instance);

    /**
     * Constructor.
     *
     * Makes a filter to match the strategy instance as specified
     * by the StrategyData instance in the input parameter.
     *
     * @param instance             Instance of StrategyData to be matched.
     */
    StrategyByIdentifierFilter(const StrategyData & instance);

    /**
     * Makes a filter to match the strategy instance having
     * specified strategy identifier as an input parameter.
     *
     * @param instance             Instance of the StrategyIdentifier to be
     *                             matched.
     */
    StrategyByIdentifierFilter(const StrategyIdentifier & instance);
    StrategyByIdentifierFilter(const StrategyByIdentifierFilter & filter);

    StrategyByIdentifierFilter & operator=(const StrategyByIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_instance;
};
}

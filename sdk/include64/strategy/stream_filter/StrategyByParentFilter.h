#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyByParentFilter, to match direct children of the strategy.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/StrategyData.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/DateTime.h"
#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

/**
 * StrategyByParentFilter matches strategy instances which parent identifier
 * (and, optionally, strategy type) matches the one set in
 * the filter.
 *
 * The filter therefore matches all direct children of the specified strategy
 * (if SetWithParent() is set to "true", the filter also matches the parent
 * strategy itself).
 *
 */
class STRATEGY_EXPORT StrategyByParentFilter : public StrategyFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies instance having
     * parent strategy as specified in the input parameter.
     *
     * @param parent                            Instance of the Strategy to specify the parent
                                                strategy and to filter all its child strategies
                                                (and parent strategy itself, if SetWithParent()
                                                is set to "true").
     */
    StrategyByParentFilter(const Strategy & parent);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies instance having
     * parent StrategyData as specified in the input parameter.
     *
     * @param parent                           Instance of StrategyData to specify the parent
                                               strategy and to filter all its child strategies
                                               (and parent strategy itself, if SetWithParent()
                                               is set to "true").
     */
    StrategyByParentFilter(const StrategyData & parent);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies instance having
     * parent strategy identifier as specified in the input parameter.
     *
     * @param parent                           Instance of the parent strategy identifier to
                                               filter all its child strategies
                                               (and parent strategy itself, if SetWithParent()
                                               is set to "true").
     */
    StrategyByParentFilter(const StrategyIdentifier & parent);
    StrategyByParentFilter(const StrategyByParentFilter & filter);

    /**
     * %Set the type of the strategy for the filter.
     *
     * @param type                             Type of the strategy.
                                               In this method, type is specified by providing StrategyIdentifier
                                               instance as an input parameter.
     */
    void SetType(const StrategyIdentifier & type);

    /**
     * %Set the type of the strategy for the filter.
     *
     * @param type                             Type of the strategy.
                                               In this method, type is specified by providing Identifier
                                               instance as an input parameter.
     */
    void SetType(const Identifier & type);

    /**
     * %Set the parent strategy presence in the filter output.
     *
     *  @param with_parent                     Its a Boolean value which decides
                                               if the parent strategy is to be filtered or not.
                                               By default, parent strategy will be present in the
                                               filter.
     */
    void SetWithParent(const Boolean & with_parent = true);

    /**
     * %Set filtering condition for the filter on the basis of strategy creation time.
     * Allows to match all the strategies having its creation date greater than or equal
     * to the date time specified in the input parameter.
     *
     * All the strategies created between the date time specified till today will
     * all be filtered.
     *
     * @param datetime                         Instance of DateTime.
                                               Starting search point.
     */
    void SetCreationTime(const DateTime & datetime);

    StrategyByParentFilter & operator=(const StrategyByParentFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_parent;
    StrategyIdentifier m_type;
    bool m_with_parent;
    DateTime m_creation_time;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyByOwnerFilter  matches the strategy instances
// having specified owner.
//****************************************************************************************

#include "strategy/type/UserIdentifier.h"
#include "strategy/User.h"
#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

/**
 * StrategyByOwnerFilter matches strategies having specified owner.
 */
class STRATEGY_EXPORT StrategyByOwnerFilter : public StrategyFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies having
     * owner's user identifier as specified in the input parameter.
     *
     * @param owner                         Instance of an UserIdentifier.
     */
    StrategyByOwnerFilter(const UserIdentifier & owner);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategies having
     * owner as specified in the input parameter.
     *
     * @param owner                         Instance of an User.
     */
    StrategyByOwnerFilter(const User & owner);
    StrategyByOwnerFilter(const StrategyByOwnerFilter & filter);

    StrategyByOwnerFilter & operator=(const StrategyByOwnerFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    UserIdentifier m_owner;
};
}

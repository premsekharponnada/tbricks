#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByOwnerFilter
//****************************************************************************************

#include "strategy/type/UserIdentifier.h"
#include "strategy/User.h"
#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

/**
 * TradeByOwnerFilter matches trades having specified owner.
 */
class STRATEGY_EXPORT TradeByOwnerFilter : public TradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the trades having
     * owner's user identifier as specified in the input parameter.
     *
     * @param owner                         Instance of an UserIdentifier.
     */
    TradeByOwnerFilter(const UserIdentifier & owner);

    /**
     * Constructor.
     *
     * Makes a filter to match all the trades having
     * owner as specified in the input parameter.
     *
     * @param owner                         Instance of an User.
     */
    TradeByOwnerFilter(const User & owner);

    TradeByOwnerFilter(const TradeByOwnerFilter & filter) = default;
    TradeByOwnerFilter & operator=(const TradeByOwnerFilter & filter) = default;

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    UserIdentifier m_owner;
};
}

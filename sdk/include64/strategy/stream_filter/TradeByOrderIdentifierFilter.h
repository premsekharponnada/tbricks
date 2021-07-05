#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByOrderIdentifierFilter, matches trade by order identifier.
//****************************************************************************************

#include "strategy/type/OrderIdentifier.h"
#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

/**
 * TradeByOrderIdentifierFilter matches to trade for specified order identifier.
 */
class STRATEGY_EXPORT TradeByOrderIdentifierFilter : public TradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all trades having order identifier as
     * specified in the input parameter.
     *
     * @param identifier                                    Instance of OrderIdentifier.
     */
    TradeByOrderIdentifierFilter(const OrderIdentifier & identifier);
    TradeByOrderIdentifierFilter(const TradeByOrderIdentifierFilter & filter);

    TradeByOrderIdentifierFilter & operator=(const TradeByOrderIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    OrderIdentifier m_identifier;
};
}

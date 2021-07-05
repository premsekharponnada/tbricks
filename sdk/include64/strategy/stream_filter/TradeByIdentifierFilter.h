#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByIdentifierFilter, matches trades by trade identifier.
//****************************************************************************************

#include "strategy/type/TradeIdentifier.h"
#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

/**
 * TradeByIdentifierFilter matches all trades with trade identifier provided
 * as filter argument.
 */
class STRATEGY_EXPORT TradeByIdentifierFilter : public TradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the trade having
     * trade identifier as specified in the input parameter.
     *
     * @param identifier                            Instance of the trade identifier to be filtered.
     */
    TradeByIdentifierFilter(const TradeIdentifier & identifier);
    TradeByIdentifierFilter(const TradeByIdentifierFilter & filter);

    TradeByIdentifierFilter & operator=(const TradeByIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    TradeIdentifier m_identifier;
};
}

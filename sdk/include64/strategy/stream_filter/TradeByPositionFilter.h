#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByPositionFilter matched trades which aggregated in specified position
//****************************************************************************************

#include "strategy/Position.h"
#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

/**
 * TradeByPositionFilter matched trades which aggregated in specified position.
 *
 * NOTE: Currently this filter works only if a single position specified, please
 * don't use it with multiple positions specified!
 */
class STRATEGY_EXPORT TradeByPositionFilter : public TradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all trades having position
     * as specified by the input parameters.
     *
     * @param position                              Instance of Position.
     */
    TradeByPositionFilter(const Position & position);
    TradeByPositionFilter(const TradeByPositionFilter & filter);

    TradeByPositionFilter & operator=(const TradeByPositionFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_position_identifier;
};
}

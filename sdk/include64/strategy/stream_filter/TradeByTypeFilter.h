#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByTypeFilter, matches trades by trade type.
//****************************************************************************************

#include "strategy/type/TradeType.h"
#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

/**
 * TradeByTypeFilter matches all trades with trade type provided
 * as filter argument.
 */
class STRATEGY_EXPORT TradeByTypeFilter : public TradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all trades having trade type as
     * specified in the input parameter.
     *
     * @param type                          Instance of TradeType. Value enumeration of
                                            TradeType class provide all possible trade type values.
     */
    TradeByTypeFilter(const TradeType & type);
    TradeByTypeFilter(const TradeByTypeFilter & filter);

    TradeByTypeFilter & operator=(const TradeByTypeFilter & filter);

    /**
     * Get the type of the trade.
     *
     * @return                              Instance of TradeType
     */
    const TradeType & GetType() const;

    /**
     * %Set trade type of the filter.
     *
     * @param type                          Instance of TradeType. Value enumeration of
                                            TradeType class provide all possible trade type values.
     */
    void SetType(const TradeType & type);

    virtual void Clear();
    virtual bool Empty() const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    TradeType m_type;
};
}

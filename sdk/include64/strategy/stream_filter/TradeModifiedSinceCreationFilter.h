#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeModifiedSinceCreationFilter selects modified trades
//****************************************************************************************

#include "strategy/type/Boolean.h"
#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

/**
 * TradeModifiedSinceCreationFilter matches trades by its modification status
 */
class STRATEGY_EXPORT TradeModifiedSinceCreationFilter : public TradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match any modified or not modified trades
     *
     * @param modified                  Select modified trades or not
     */
    TradeModifiedSinceCreationFilter(const Boolean & modified);

    TradeModifiedSinceCreationFilter(const TradeModifiedSinceCreationFilter & filter);

    TradeModifiedSinceCreationFilter & operator=(const TradeModifiedSinceCreationFilter & filter);

    /**
     * %Set modified filter flag
     *
     * @param modified                  Select modified trades or not
     */
    void SetModified(const Boolean & modified);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Boolean m_modified;
};
}

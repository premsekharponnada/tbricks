#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeDeletedFilter, matches deleted trade in snapshot.
//****************************************************************************************

#include "strategy/type/Boolean.h"
#include "strategy/type/TradeIdentifier.h"
#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

/**
 * TradeDeletedFilter allows to skip deleted trades.
 */
class STRATEGY_EXPORT TradeDeletedFilter : public TradeFilterCondition
{
public:
    /// Default constructor.
    TradeDeletedFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all trades based on the specified
     * Boolean value.
     *
     * @param deleted                                 Boolean value.
                                                      Set true to get deleted trades.
                                                      Set false to get non deleted trades.
     */
    TradeDeletedFilter(const Boolean & deleted);
    TradeDeletedFilter(const TradeDeletedFilter & filter);

    TradeDeletedFilter & operator=(const TradeDeletedFilter & filter);

    /**
     * %Set trade deleted status for the filter.
     *
     * @param deleted                                  Boolean value.
                                                       Set true to get deleted trades.
                                                       Set false to get non deleted trades.
     */
    void SetDeleted(const Boolean & deleted);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Boolean m_deleted;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PublicTradeByAggressorFilter, matches public trades by side.
//****************************************************************************************

#include "strategy/stream_filter/PublicTradeFilter.h"

#include "strategy/type/Side.h"

namespace tbricks {

/**
 * PublicTradeByAggressorFilter matches all trades with side provided
 * as filter argument.
 */
class STRATEGY_EXPORT PublicTradeByAggressorFilter : public PublicTradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the public trades having
     * side as specified in the input parameter.
     *
     * @param side                  Instance of Side.
     */
    PublicTradeByAggressorFilter(const Side & side);
    PublicTradeByAggressorFilter(const PublicTradeByAggressorFilter & filter);

    PublicTradeByAggressorFilter & operator=(const PublicTradeByAggressorFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Side m_side;
};
}

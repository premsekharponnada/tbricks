#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PortfolioByNameFilter, matches updates of concrete portfolio instance
// having specified name.
//****************************************************************************************

#include "strategy/Portfolio.h"
#include "strategy/stream_filter/PortfolioFilter.h"

namespace tbricks {

/**
 * PortfolioByNameFilter matches concrete portfolio instance updates,
 * selected by portfolio name.
 */
class STRATEGY_EXPORT PortfolioByNameFilter : public PortfolioFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the portfolio having specified name.
     *
     * @param instance                       portfolio name
     */
    PortfolioByNameFilter(const String & instance);
    PortfolioByNameFilter(const PortfolioByNameFilter & filter);

    PortfolioByNameFilter & operator=(const PortfolioByNameFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    String m_instance;
};
}

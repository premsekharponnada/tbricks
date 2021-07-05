#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PortfolioByIdentifierFilter, matches updates of concrete portfolio instance
// having specified identifier.
//****************************************************************************************

#include "strategy/Portfolio.h"
#include "strategy/stream_filter/PortfolioFilter.h"

namespace tbricks {

/**
 * PortfolioByIdentifierFilter matches concrete portfolio instance updates,
 * selected by portfolio identifier.
 */
class STRATEGY_EXPORT PortfolioByIdentifierFilter : public PortfolioFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter that matches the portfolio having portfolio identifier
     * as specified by the portfolio instance.
     *
     * @param instance                  portfolio instance
     */
    PortfolioByIdentifierFilter(const Portfolio & instance);

    /**
     * Constructor.
     *
     * Makes a filter that matches the portfolio having specified identifier.
     *
     * @param instance                  portfolio identifier
     */
    PortfolioByIdentifierFilter(const PortfolioIdentifier & instance);
    PortfolioByIdentifierFilter(const PortfolioByIdentifierFilter & filter);

    PortfolioByIdentifierFilter & operator=(const PortfolioByIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    PortfolioIdentifier m_instance;
};
}

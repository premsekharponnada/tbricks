#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PositionByPortfolioFilter.
//****************************************************************************************

#include "strategy/stream_filter/PositionFilter.h"
#include "strategy/Portfolio.h"

namespace tbricks {

/**
 * PositionByPortfolioFilter matches concrete position instance updates,
 * selected by portfolio identifier.
 */
class STRATEGY_EXPORT PositionByPortfolioFilter : public PositionFilterCondition
{
public:
    /// Default Constructor.
    PositionByPortfolioFilter();

    /**
     * Makes the filter to match all the positions with the specified portfolio.
     *
     * @param portfolio			portfolio instance
     */
    PositionByPortfolioFilter(const Portfolio & portfolio);

    /**
     * Makes the filter to match all the positions with the specified
     * portfolio identifier.
     *
     * @param portfolio_id			portfolio identifier.
     */
    PositionByPortfolioFilter(const PortfolioIdentifier & portfolio_id);
    PositionByPortfolioFilter(const PositionByPortfolioFilter & filter);

    PositionByPortfolioFilter & operator=(const PositionByPortfolioFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    PortfolioIdentifier m_identifier;
};
}

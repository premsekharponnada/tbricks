#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PortfolioDeletedFilter, matches deleted portfolios in snapshot.
//****************************************************************************************

#include "strategy/type/Boolean.h"
#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/stream_filter/PortfolioFilter.h"

namespace tbricks {

/**
 * PortfolioDeletedFilter allows to skip deleted portfolios.
 */
class STRATEGY_EXPORT PortfolioDeletedFilter : public PortfolioFilterCondition
{
public:
    /// Default constructor.
    PortfolioDeletedFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all portfolios based on the
     * specified Boolean value.
     *
     * @param deleted                                  Boolean value.
                                                       Set true to get deleted portfolio.
                                                       Set false to get non deleted portfolio.
     */
    PortfolioDeletedFilter(const Boolean & deleted);
    PortfolioDeletedFilter(const PortfolioDeletedFilter & filter);

    PortfolioDeletedFilter & operator=(const PortfolioDeletedFilter & filter);

    /**
     * %Set instrument deleted status for the filter.
     *
     * @param deleted                                  Boolean value.
                                                       Set true to get deleted portfolio.
                                                       Set false to get non deleted portfolio.
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

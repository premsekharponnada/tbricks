#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PortfolioNameContainsFilter, matches portfolio
// updates by specified name.
//****************************************************************************************

#include "strategy/type/String.h"
#include "strategy/stream/PortfolioStream.h"

namespace tbricks {

/**
 * PortfolioNameContainsFilter matches concrete portfolio instance updates
 * containing specific portfolio name.
 */
class STRATEGY_EXPORT PortfolioNameContainsFilter : public PortfolioFilterCondition
{
public:
    /**
     * Makes a filter to match the portfolio instance having
     * name as specified in the input parameter.
     *
     * @param name            String instance, name of the
     *                              portfolio to be filtered.
     */
    PortfolioNameContainsFilter(String name, bool case_sensitive = true);

    tbricks::filter::FieldFilter GetValue() const override;

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;
    void Clear() override;
    bool Empty() const override;

private:
    String m_name;
    bool m_case_sensitive;
};
}

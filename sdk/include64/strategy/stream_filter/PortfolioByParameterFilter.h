#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PortfolioByParameterFilter, matches updates of concrete portfolio instance
// having specified parameter.
//****************************************************************************************

#include "strategy/type/Uuid.h"
#include "strategy/stream_filter/PortfolioFilter.h"
#include "strategy/PortfolioParameters.h"

namespace tbricks {

/**
 * PortfolioByParameterFilter matches portfolio instances updates
 * having specified parameter.
 */

namespace filter {
class ICondition;
}

class STRATEGY_EXPORT PortfolioByParameterFilter : public PortfolioFilterCondition
{
public:
    /// Default constructor.
    PortfolioByParameterFilter();
    PortfolioByParameterFilter(const PortfolioByParameterFilter & filter);

    /**
     * Constructor.
     *
     * Makes a filter to match the portfolios with the specified parameter
     * and parameter value.
     *
     * @param parameter_id              parameter identifier
     * @param value                     parameter value
     * @param relation                  Should be Filter::EQ
     */
    PortfolioByParameterFilter(const PortfolioParameterDefinition & definition, const AnyType & value, Filter::Relation relation = Filter::EQ);

    /**
     * Constructor.
     *
     * Makes a filter to match portfolios having specified parameter
     * and parameter value.
     * Here, portfolio parameter is given in UUID form.
     *
     * @param parameter_id              parameter identifier
     * @param value                     parameter value
     * @param relation                  Should be Filter::EQ
     */
    PortfolioByParameterFilter(const Uuid & parameter_id, const AnyType & value, Filter::Relation relation = Filter::EQ);
    ~PortfolioByParameterFilter();

    PortfolioByParameterFilter & operator=(const PortfolioByParameterFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void init(const Uuid & parameter_id, const AnyType & value, Filter::Relation relation);

private:
    filter::ICondition * m_condition;
};
}

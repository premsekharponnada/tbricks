#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyByParameterFilter matches updates of
// strategies having the specified parameter.
//****************************************************************************************

#include "strategy/type/Uuid.h"
#include "strategy/parameter/Parameter.h"
#include "strategy/stream_filter/StrategyFilter.h"

namespace tbricks {

/**
 * StrategyByParameterFilter matches strategy instances with the specified
 * parameter
 *
 */

namespace filter {
class ICondition;
}

class STRATEGY_EXPORT StrategyByParameterFilter : public StrategyFilterCondition
{
public:
    /// Default constructor.
    StrategyByParameterFilter();
    StrategyByParameterFilter(const StrategyByParameterFilter & filter);

    /**
     * Constructor.
     *
     *  Makes a filter to match all the strategy instances having
     *  parameter as specified in the input parameter.
     *
     *  @param parameter                       Instance of Parameter.
     *                                         Parameter on the basis of which strategies are
     *                                         to be filtered.
     */
    StrategyByParameterFilter(const Parameter & parameter);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategy instances having
     * parameter definition and AnyTypye value as specified in the input parameters.
     *
     * @param definition                       Parameter "definitions" allows to select what
                                               specific strategy parameters updates the
                                               caller is interested in.
     * @param value                            Strategy parameter's value
    *
    * @param relation                         Filter::Relation enumeration type value.
     */
    StrategyByParameterFilter(const ParameterDefinition & definition, const AnyType & value, Filter::Relation relation = Filter::Relation::EQ);

    /**
     * Constructor.
     *
     * Makes a filter to match all the strategy instances having
     * parameter and its value as specified in the input parameters.
     *
     * @param parameter_id                     Uuid of the strategy parameter to select the
                                               specific strategy parameters updates, the
                                               caller is interested in.
     * @param value                            Value of the strategy parameter.
    *
    * @param relation                         Filter::Relation enumeration type value.
     */
    StrategyByParameterFilter(const Uuid & parameter_id, const AnyType & value, Filter::Relation relation = Filter::Relation::EQ);
    ~StrategyByParameterFilter();

    StrategyByParameterFilter & operator=(const StrategyByParameterFilter & filter);

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

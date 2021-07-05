#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TTradeByParameterFilter matches trades having the
// specified parameter.
//****************************************************************************************

#include "strategy/type/Uuid.h"
#include "strategy/stream_filter/TradeFilter.h"
#include "strategy/TradeParameterDefinition.h"
#include "strategy/type/RankingIdentifier.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * TradeByParameterFilter matches trades having specified parameter.
 */
class STRATEGY_EXPORT TradeByParameterFilter : public TradeFilterCondition
{
public:
    /// Default constructor.
    TradeByParameterFilter();

    /**
     * Makes a filter to match trades having ranking identifier, trade parameter,
     * trade parameter value as specified in the input parameters.
     *
     * @param identifier                       Instance of RankingIdentifier.
     * @param definition                       Parameter "definitions" allows to select what
                                               specific trade parameters updates the
                                               caller is interested in.
     * @param value                            Strategy parameter's value
     * @param relation                         Filter::Relation enumeration type value.
     */
    TradeByParameterFilter(const RankingIdentifier & identifier,
                           const TradeParameterDefinition & definition,
                           const AnyType & value,
                           Filter::Relation relation = Filter::EQ);
    TradeByParameterFilter(const TradeByParameterFilter & filter);
    ~TradeByParameterFilter();

    TradeByParameterFilter & operator=(const TradeByParameterFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void init(const Uuid & parameter_id, const Uuid & ranking_id, const AnyType & value, Filter::Relation relation);

private:
    ::tbricks::filter::ICondition * m_condition;
};
}

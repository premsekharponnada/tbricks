#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::ByParameterFilter, matches updates of
// instruments with the given parameter.
//****************************************************************************************

#include "strategy/type/Uuid.h"
#include "strategy/instrument/InstrumentParameterDefinition.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * InstrumentByParameterFilter matches concrete instrument instance updates,
 * related to specified aggregated instrument parameter value.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::ByParameterFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /// Default constructor.
    ByParameterFilter();

    /**
     * Makes a filter to match all instruments with the specified aggregated instrument parameter value.
     *
     * @param definition                       Parameter "definitions" allows to select what
                                               specific instrument parameters updates the
                                               caller is interested in.
     * @param value                            instrument parameter's value
     */
    ByParameterFilter(const InstrumentParameterDefinition & definition, const AnyType & value);

    /**
     * Make a filter to match all instruments with the specified aggregated instrument
     * parameter value and parameter context.
     *
     * @param definition                       Parameter "definitions" allows to select what
                                               specific instrument parameters updates the
                                               caller is interested in.
     * @param value                            parameter's value
     * @param identifier                       parameter ranking identifier
     */
    ByParameterFilter(const InstrumentParameterDefinition & definition, const AnyType & value, const ContextIdentifier & identifier);

    /**
     * Make a filter to match all instrument with the specified aggregated instrument
     * parameter value and parameter context ranking.
     *
     * @param definition                       Parameter "definitions" allows to select what
                                               specific instrument parameters updates the
                                               caller is interested in.
     * @param value                            parameter's value
     * @param identifier                       parameter ranking identifier
     */
    ByParameterFilter(const InstrumentParameterDefinition & definition, const AnyType & value, const RankingIdentifier & identifier);
    ByParameterFilter(const ByParameterFilter & filter);
    ~ByParameterFilter();

    ByParameterFilter & operator=(const ByParameterFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;

    /**
     * %Set the parameter context for the filter.
     *
     * @param identifier			parameter context identifier
     */
    void SetContextIdentifier(const ContextIdentifier & identifier);

    /**
     * %Set the context ranking for the filter.
     *
     * @param identifier			ranking identifier
     */
    void SetRankingIdentifier(const RankingIdentifier & identifier);

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void init(const Uuid & parameter_id, const AnyType & value);

private:
    ::tbricks::filter::ICondition * m_condition;
};
}

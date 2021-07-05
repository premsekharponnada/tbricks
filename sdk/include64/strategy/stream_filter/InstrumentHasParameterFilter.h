#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::HasParameterFilter, matches updates of
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
 * InstrumentHasParameterFilter matches concrete instrument instance updates if parameter is set.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::HasParameterFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /// Default constructor
    HasParameterFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all instrument that has specified parameter set.
     *
     * @param definition                       Parameter "definitions" allows to select what specific instrument
                                               parameters updates the caller is interested in.
     */
    HasParameterFilter(const InstrumentParameterDefinition & definition);

    /**
     * Constructor.
     *
     * Makes a filter to match all instrument that has specified parameter definition and context set.
     *
     * @param definition                       Parameter "definitions" allows to select what specific instrument
                                               parameters updates the caller is interested in.
     * @param identifier                       parameter context identifier
     */
    HasParameterFilter(const InstrumentParameterDefinition & definition, const ContextIdentifier & identifier);

    /**
     * Constructor.
     *
     * Makes a filter to match all instrument that has specified parameter definition and ranking set.
     *
     * @param definition                       Parameter "definitions" allows to select what specific instrument
                                               parameters updates the caller is interested in.
     * @param identifier                       ranking identifier
     */
    HasParameterFilter(const InstrumentParameterDefinition & definition, const RankingIdentifier & identifier);
    HasParameterFilter(const HasParameterFilter & filter);
    ~HasParameterFilter();

    HasParameterFilter & operator=(const HasParameterFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;

    /**
     * %Set parameter context for the filter.
     *
     * @param identifier			parameter context identifier
     */
    void SetContextIdentifier(const ContextIdentifier & identifier);

    /**
     * %Set context ranking for the filter.
     *
     * @param identifier			 ranking identifier
     */
    void SetRankingIdentifier(const RankingIdentifier & identifier);

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void init(const Uuid & parameter_id);

private:
    ::tbricks::filter::ICondition * m_condition;
};
}

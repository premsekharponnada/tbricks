#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentGroupHasParameterFilter, matches instrument groups with specified
// parameter set or aggregated.
//****************************************************************************************

#include "strategy/stream_filter/InstrumentGroupFilter.h"
#include "strategy/instrument/InstrumentParameterDefinition.h"
#include "strategy/type/ContextIdentifier.h"
#include "strategy/type/RankingIdentifier.h"
#include <memory>

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * InstrumentGroupHasParameterFilter matches concrete instrument group instance updates if parameter is set.
 */
class STRATEGY_EXPORT InstrumentGroupHasParameterFilter : public InstrumentGroupFilterCondition
{
public:
    /// Default constructor.
    InstrumentGroupHasParameterFilter();
    /**
     * Constructor.
     *
     * Makes a filter to match all instrument groups that has specified parameter set.
     *
     * @param definition                       Parameter "definitions" allows to select what specific instrument
                                               group parameters updates the caller is interested in.
     */
    InstrumentGroupHasParameterFilter(const InstrumentParameterDefinition & definition);

    /**
     * Constructor.
     *
     * Makes a filter to match all instrument group that has specified parameter definition and context set.
     *
     * @param definition                       Parameter "definitions" allows to select what specific instrument
                                               group parameters updates the caller is interested in.
     * @param identifier                       parameter context identifier.
     */
    InstrumentGroupHasParameterFilter(const InstrumentParameterDefinition & definition, const ContextIdentifier & identifier);

    /**
     * Constructor.
     *
     * Makes a filter to match all instrument group that has specified parameter definition and ranking set.
     *
     * @param definition                       Parameter "definitions" allows to select what specific instrument
                                               group parameters updates the caller is interested in.
     * @param identifier                       ranking identifier
     */
    InstrumentGroupHasParameterFilter(const InstrumentParameterDefinition & definition, const RankingIdentifier & identifier);
    InstrumentGroupHasParameterFilter(const InstrumentGroupHasParameterFilter & filter);
    InstrumentGroupHasParameterFilter & operator=(const InstrumentGroupHasParameterFilter & filter);
    ~InstrumentGroupHasParameterFilter();

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

    virtual void Clear() override;
    virtual tbricks::filter::FieldFilter GetValue() const override;
    virtual bool Empty() const override;

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    void init(const Uuid & parameter_id);

private:
    std::unique_ptr<::tbricks::filter::ICondition> m_condition;
};
}

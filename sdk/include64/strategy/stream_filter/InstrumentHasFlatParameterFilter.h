#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::HasFlatParameterFilter
// matches instruments with specified flat (non-aggregated) parameter set.
//****************************************************************************************

#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

namespace filter {
class ICondition;
}

class InstrumentParameterDefinition;
class Uuid;

/**
 * InstrumentHasFlatParameterFilter matches instruments with specified flat parameter set.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::HasFlatParameterFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /// Default constructor
    HasFlatParameterFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all instrument groups that has specified flat parameter set.
     *
      * @param definition                       Parameter "definitions" allows to select what specific instrument
                                                parameters updates the caller is interested in.
     */

    HasFlatParameterFilter(const InstrumentParameterDefinition & definition);

    /**
     * Constructor.
     *
     * Makes a filter to match all instrument group that has specified flat parameter definition and context set.
     *
     * @param definition                       Parameter "definitions" allows to select what specific instrument
                                               parameters updates the caller is interested in.
     * @param identifier                       parameter context identifier
     */
    HasFlatParameterFilter(const InstrumentParameterDefinition & definition, const ContextIdentifier & identifier);
    HasFlatParameterFilter(const HasFlatParameterFilter & filter);
    ~HasFlatParameterFilter();

    HasFlatParameterFilter & operator=(const HasFlatParameterFilter & filter);

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
    ::tbricks::filter::ICondition * m_condition;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByVolumeFilter to match trade with specified volume.
//****************************************************************************************

#include "strategy/stream_filter/TradeFilter.h"
#include "strategy/type/Volume.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * TradeByVolumeFilter matches concrete trade selected by traded volume.
 */
class STRATEGY_EXPORT TradeByVolumeFilter : public TradeFilterCondition
{
public:
    /// Default constructor.
    TradeByVolumeFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all the trades having traded volume
     * as specified in the input parameter.
     *
     * @param volume                   Instance of Volume to specify traded volume.
     *
     * @param relation                 Its value is set to Filter::EQ (Equal), hence it will
                                       filter the trades having trade volume  = volume specified
                                       as the input parameter.
     */
    TradeByVolumeFilter(const Volume & volume, Filter::Relation relation = Filter::EQ);
    TradeByVolumeFilter(const TradeByVolumeFilter & filter);
    virtual ~TradeByVolumeFilter();

    TradeByVolumeFilter & operator=(const TradeByVolumeFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;
    virtual std::ostream & Print(std::ostream & strm) const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;

private:
    Filter::Relation m_relation = Filter::EQ;
    bool m_is_empty = false;
    double m_value = 0;
};
}

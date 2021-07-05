#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByVenueFilter to match trade with specified venue.
//****************************************************************************************

#include "strategy/stream_filter/TradeFilter.h"
#include "strategy/type/Venue.h"

namespace tbricks {

/**
 * TradeByVenueFilter matches concrete trade selected by venue identifier.
 */
class STRATEGY_EXPORT TradeByVenueFilter : public TradeFilterCondition
{
public:
    /// Default constructor.
    TradeByVenueFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all trades with the specified venue.
     *
     * @param venue                 Instance of Venue
     */
    TradeByVenueFilter(const Venue & venue);

    /**
     * Constructor.
     *
     * Makes a filter to match all trades with the specified venue.
     *
     * @param venue_id              Instance of VenueIdentifier.
     */
    TradeByVenueFilter(const VenueIdentifier & id);

    TradeByVenueFilter(const TradeByVenueFilter & filter);

    virtual ~TradeByVenueFilter();

    TradeByVenueFilter & operator=(const TradeByVenueFilter & filter);

    virtual void Clear();
    virtual bool Empty() const;
    virtual std::ostream & Print(std::ostream & strm) const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;

private:
    VenueIdentifier m_venue_id;
};
}

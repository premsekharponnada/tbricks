#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::ByVenueFilter, matches updates of instruments
// tradeable on a given venue/mic combination.
//****************************************************************************************

#include "strategy/type/VenueIdentifier.h"
#include "strategy/type/MIC.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

/**
 * InstrumentStream::Filters::ByVenueFilter matches concrete instrument
 * instance updates, selected by venue/MIC.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::ByVenueFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all instruments with the specified venue.
     *
     * @param venue_id                 venue identifier
     */
    ByVenueFilter(const VenueIdentifier & venue_id);

    /**
     * Constructor.
     *
     * Make a filter to match all instruments with the specified venue and MIC code.
     *
     * @param venue_id                  venue identifier
     * @param mic                       MIC code
     */
    ByVenueFilter(const VenueIdentifier & venue_id, const MIC & mic);
    ByVenueFilter(const ByVenueFilter & filter);

    ByVenueFilter & operator=(const ByVenueFilter & filter);

    /**
     * %Set MIC code for the filter.
     *
     * @param mic                       MIC code
     */
    void SetMIC(const MIC & mic);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    VenueIdentifier m_venue_id;
    MIC m_mic;
};
}

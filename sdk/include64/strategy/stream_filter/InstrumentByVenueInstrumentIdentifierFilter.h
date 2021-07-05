#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::ByVenueInstrumentIdentifierFilter, matches updates of
// instrument with venue instrument identifier.
//****************************************************************************************

#include "strategy/type/VenueInstrumentIdentifier.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

/**
 *  This filter doesn't work for instrument stream. Please do not use for stream opening.
 *
 *  The filter can be used only for resolving instruments via Instrument::Resolve().
 */
class STRATEGY_EXPORT InstrumentStream::Filters::ByVenueInstrumentIdentifierFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the instruments having specified
     * venue instrument identifier.
     *
     * @param viid                     VenueInstrumentIdentifier instance.
                                       VIID id triplet of VenueIdentifier,
                                       MIC and set of pairs <key, value> defines set of VIID fields
     */
    ByVenueInstrumentIdentifierFilter(const VenueInstrumentIdentifier & viid);
    ByVenueInstrumentIdentifierFilter(const ByVenueInstrumentIdentifierFilter & filter);

    ByVenueInstrumentIdentifierFilter & operator=(const ByVenueInstrumentIdentifierFilter & filter);

    /**
     * Get venue instrument identifier.
     *
     * @return                         Current viid
     */
    const VenueInstrumentIdentifier & GetVenueInstrumentIdentifier() const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual void Clear();
    virtual bool Empty() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    VenueInstrumentIdentifier m_viid;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentVenueIdentification type.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/type/Venue.h"
#include "strategy/type/MIC.h"
#include "strategy/VenueAndMIC.h"

// \namespace tbricks
namespace tbricks {

namespace types {
class VIID;
class UUID;
}

class STRATEGY_EXPORT InstrumentVenueIdentification : public Printable
{
public:
    /** These constructors are simply a way to create
     *  an InstrumentVenueIdentification instance with the given properties;
     *  there is no check to see if there actually exists such an instance
     *  for the given instrument which can be used for
     *  trading, marketdata, and so on
     */
    InstrumentVenueIdentification() {}
    explicit InstrumentVenueIdentification(const InstrumentIdentifier & instrument_id) : m_instrument_id(instrument_id) {}
    InstrumentVenueIdentification(const InstrumentIdentifier & instrument_id, const Venue & venue) :
        m_instrument_id(instrument_id),
        m_venue_id(venue.GetIdentifier())
    {}
    InstrumentVenueIdentification(const InstrumentIdentifier & instrument_id, const Venue & venue, const MIC & mic) :
        m_instrument_id(instrument_id),
        m_venue_id(venue.GetIdentifier()),
        m_mic(mic)
    {}
    InstrumentVenueIdentification(const InstrumentIdentifier & instrument_id, const VenueAndMIC & venue_mic) :
        m_instrument_id(instrument_id),
        m_venue_id(venue_mic.GetVenue().GetIdentifier()),
        m_mic(venue_mic.GetMIC())
    {}
    InstrumentVenueIdentification(const InstrumentVenueIdentification & ivid) :
        m_instrument_id(ivid.m_instrument_id),
        m_venue_id(ivid.m_venue_id),
        m_mic(ivid.m_mic)
    {}

    InstrumentVenueIdentification(const InstrumentIdentifier & instrument_id, const Venue & venue, const MIC & mic, bool use_trading_venues);

    ~InstrumentVenueIdentification() {}

    InstrumentVenueIdentification & operator=(const InstrumentVenueIdentification & ivid);

    bool operator<(const InstrumentVenueIdentification & ivid) const;
    bool operator==(const InstrumentVenueIdentification & ivid) const;
    bool operator!=(const InstrumentVenueIdentification & ivid) const;

    void Set(const InstrumentIdentifier & instrument_id, const Venue & venue_id, const MIC & mic = MIC());

    void Set(const InstrumentIdentifier & instrument_id, const VenueIdentifier & venue_id, const MIC & mic = MIC());

    void SetInstrumentIdentifier(const InstrumentIdentifier & instrument_id);
    void SetVenueIdentifier(const VenueIdentifier & venue_id);
    void SetMIC(const MIC & mic);

    const InstrumentIdentifier & GetInstrumentIdentifier() const { return m_instrument_id; }
    const VenueIdentifier & GetVenueIdentifier() const { return m_venue_id; }
    const MIC & GetMIC() const { return m_mic; }

    Venue GetVenue() const;
    VenueAndMIC GetVenueAndMIC() const;

    bool Empty() const;
    void Clear();

    size_t GetHash() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;
    std::ostream & Print(std::ostream & strm, bool print_mic) const;

    void set_ivid(const tbricks::types::UUID & instrument_id, const tbricks::types::VIID & viid);
    bool get_viid(tbricks::types::VIID & viid) const;
    static bool get_viid(const InstrumentIdentifier & instrument_id, const VenueIdentifier & venue_id, const MIC & mic, tbricks::types::VIID & viid);

private:
    InstrumentIdentifier m_instrument_id;
    VenueIdentifier m_venue_id;
    MIC m_mic;
};

inline size_t hash_value(const InstrumentVenueIdentification & value)
{
    return value.GetHash();
}

inline size_t get_hash_value(const InstrumentVenueIdentification & value)
{
    return hash_value(value);
}

} // \namespace tbricks

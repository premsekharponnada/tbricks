#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Venue and MIC type.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Venue.h"
#include "strategy/type/MIC.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT VenueAndMIC : public Printable
{
public:
    VenueAndMIC();
    VenueAndMIC(const Venue & venue);
    VenueAndMIC(const Venue & venue, const MIC & mic);
    VenueAndMIC(const VenueAndMIC & vm);
    ~VenueAndMIC();

    VenueAndMIC & operator=(const VenueAndMIC & vm);

    bool operator<(const VenueAndMIC & vm) const;
    bool operator==(const VenueAndMIC & vm) const;
    bool operator!=(const VenueAndMIC & vm) const;

    void Set(const Venue & venue, const MIC & mic);

    void SetVenue(const Venue & venue);
    const Venue & GetVenue() const;

    void SetMIC(const MIC & mic);
    const MIC & GetMIC() const;

    bool Empty() const;
    void Clear();

    size_t GetHash() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Venue m_venue;
    MIC m_mic;
};

inline size_t hash_value(const VenueAndMIC & value)
{
    return value.GetHash();
}

} // \namespace tbricks

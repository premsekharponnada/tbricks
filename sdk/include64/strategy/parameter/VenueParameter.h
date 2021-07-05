#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Venue type.
//****************************************************************************************

#include "strategy/type/Venue.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT VenueParameter : public Parameter
{
public:
    using ValueType = Venue;

public:
    VenueParameter(const ParameterDefinition & definition);
    VenueParameter(const VenueParameter & parameter);

    VenueParameter & operator=(const Venue & value);
    VenueParameter & operator=(const VenueParameter & parameter);

    const Venue & GetVenue() const;
    const VenueIdentifier & GetVenueIdentifier() const;

    operator const VenueIdentifier &() const;

    class Impl;

private:
    Impl * const m_impl;
    mutable Venue m_venue;
};

} // \namespace tbricks

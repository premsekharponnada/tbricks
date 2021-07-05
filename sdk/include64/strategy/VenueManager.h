#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VenueManager : Access to the venue infromation.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/Venue.h"
#include "strategy/type/MIC.h"

namespace tbricks {

namespace venue {
class VenueInfo;
}

/**
 * VenueManager allows to access the currently available venue information
 * as well as to track its changes.
 */
class STRATEGY_EXPORT VenueManager
{
public:
    /**
     * Get all available venues.
     *
     * On return, venue vector provided as a method parameter is filled in
     * with available venue data, or is cleared if no data is available.
     *
     * @param venues                    Venue vector
     */
    static void GetAllVenues(std::vector<Venue> & venues);

    /**
     * Get all venues which are used by any instrument.
     *
     * On return, venue vector provided as a method parameter is filled in
     * with available venue data, or is cleared if no data is available.
     *
     * @param venues                    Venue vector
     */
    static void GetAllUsedVenues(std::vector<Venue> & venues);

    /**
     * Get all available MICs.
     *
     * On return, MIC vector provided as a method parameter is filled in
     * with available MIC data, or is cleared if no data is available.
     *
     * @param venues                    MIC vector
     */
    static void GetAllMICs(std::vector<MIC> & mics);

    /**
     * Get all MICs which are used by any instrument.
     *
     * On return, MIC vector provided as a method parameter is filled in
     * with available MIC data, or is cleared if no data is available.
     *
     * @param venues                    MIC vector
     */
    static void GetAllUsedMICs(std::vector<MIC> & mics);
};
}

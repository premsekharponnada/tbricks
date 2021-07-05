#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Capabilities of a trading venue.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/MarketCommandType.h"

namespace tbricks {

namespace venue {
class VenueInfo;
}

/**
 * MarketCommandCapabilities allows to discover capabilities
 * of a market command service for a venue.
 */
class STRATEGY_EXPORT MarketCommandCapabilities : public Printable
{
public:
    /**
     * Copy constructor
     *
     * @param o                  MarketCommandCapabilities
     */
    MarketCommandCapabilities(const MarketCommandCapabilities & o);

    /**
     * Destructor
     */
    ~MarketCommandCapabilities() override;

    /**
     * Copy assignment operator
     *
     * @param o                  MarketCommandCapabilities
     */
    MarketCommandCapabilities & operator=(const MarketCommandCapabilities & o);

public:
    /**
     * Get supported market command types.
     *
     * @param[out] command_types    vector of market command types supported by a venue
     */
    void GetSupportedMarketCommandTypes(std::vector<MarketCommandType> & command_types) const;

public:
    /**
     * Put string representation of MarketCommandCapabilities to ostream.
     *
     * @return                      ostream
     */
    std::ostream & Print(std::ostream & strm) const override;

private:
    friend class Venue;
    MarketCommandCapabilities(tbricks::venue::VenueInfo * vi);

private:
    tbricks::venue::VenueInfo * m_venue;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Venue Ranking.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/rankings/RankingBase.h"
#include "strategy/type/VenueIdentifier.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT VenueRanking : public RankingBase
{
public:
    /// Construct empty VenueRanking.
    VenueRanking() = default;

    /**
     * Construct VenueRanking and call @ref Resolve with the specifier ranking
     * identifier. If the ranking identifier cannot be resolved, the created
     * VenueRanking will be empty.
     *
     * @param identifier    Venue ranking identifier
     */
    VenueRanking(const Identifier & identifier);

    /// Copy-constructor
    VenueRanking(const VenueRanking & ranking);

    /// Copy-assignment operator
    VenueRanking & operator=(const VenueRanking & ranking);

    /// Class destructor
    virtual ~VenueRanking() = default;

public:
    /**
     * Init VenueRanking from the specified ranking identifier.
     * @return false if cannot resolve the ranking
     */
    virtual bool Resolve(const Identifier & identifier);

    /**
     * Get venues order.
     * @return  ordered vector of venues
     */
    const std::vector<VenueIdentifier> & GetVenueOrder() const;

    /**
     * Get position of the specified venue in the ranking.
     *
     * @param[in] venueId   Identifier of the venue
     * @param[out] index    Index of the specified venue in the ranking
     * @return true if the venue was found in the ranking, false otherwise
     */
    bool GetItemOrder(const VenueIdentifier & venueId, size_t & index) const;

    /// Clear vector of venues and call @ref RankingBase::Clear.
    void Clear();

    /// @return @ref RankingBase::Empty
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::vector<VenueIdentifier> m_venue_order;
};

} // \namespace tbricks

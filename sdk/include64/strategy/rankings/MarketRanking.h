#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Market Ranking.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/MIC.h"

#include "strategy/rankings/RankingBase.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT MarketRanking : public RankingBase
{
public:
    /// Construct empty MarketRanking.
    MarketRanking() = default;

    /**
     * Construct MarketRanking and call @ref Resolve with the specifier ranking
     * identifier. If the ranking identifier cannot be resolved, the created
     * MarketRanking will be empty.
     *
     * @param identifier    Market ranking identifier
     */
    MarketRanking(const Identifier & identifier);

    /// Copy-constructor
    MarketRanking(const MarketRanking & ranking);

    /// Copy-assignment operator
    MarketRanking & operator=(const MarketRanking & ranking);

    /// Class destructor
    virtual ~MarketRanking() = default;

public:
    /**
     * Init MarketRanking from the specified ranking identifier.
     * @return false if cannot resolve the ranking
     */
    virtual bool Resolve(const Identifier & identifier);

    /**
     * Get markets order.
     * @return  ordered vector of markets
     */
    const std::vector<MIC> & GetMarketOrder() const;

    /**
     * Get position of the specified market in the ranking.
     *
     * @param[in] mic       Market
     * @param[out] index    Index of the specified market in the ranking
     * @return true if the market was found in the ranking, false otherwise
     */
    bool GetItemOrder(const MIC & mic, size_t & index) const;

    /// Clear vector of markets and call @ref RankingBase::Clear.
    void Clear();

    /// @return @ref RankingBase::Empty
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::vector<MIC> m_market_order;
};

} // \namespace tbricks

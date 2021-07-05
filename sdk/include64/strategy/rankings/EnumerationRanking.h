#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Enumeration Ranking.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/rankings/RankingBase.h"

namespace tbricks {

class STRATEGY_EXPORT EnumerationRanking : public RankingBase
{
public:
    EnumerationRanking();
    EnumerationRanking(const Identifier & enumeration_identifier);
    EnumerationRanking(const Identifier & enumeration_identifier, const Identifier & ranking_identifier);
    EnumerationRanking(const EnumerationRanking & ranking);
    EnumerationRanking & operator=(const EnumerationRanking & ranking);
    virtual ~EnumerationRanking();

public:
    virtual bool Resolve(const Identifier & identifier);

public:
    const Identifier & GetEnumerationIdentifier() const;
    const std::vector<Integer> & GetRankingOrder() const;

public:
    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_enumeration_identifier;
    std::vector<Integer> m_ranking_order;
};
}

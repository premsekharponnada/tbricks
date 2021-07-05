#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Price Source Ranking.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/rankings/RankingBase.h"

namespace tbricks {

class STRATEGY_EXPORT ParameterContextRanking : public RankingBase
{
public:
    ParameterContextRanking();
    ParameterContextRanking(const Identifier & identifier);
    ParameterContextRanking(const ParameterContextRanking & ranking);
    ParameterContextRanking & operator=(const ParameterContextRanking & ranking);
    virtual ~ParameterContextRanking();

public:
    virtual bool Resolve(const Identifier & identifier);

public:
    const std::vector<Identifier> & GetParameterContextOrder() const;

    bool GetItemOrder(const Identifier & identifier, size_t & index) const;

public:
    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::vector<Identifier> m_parameter_context_order;
};
}

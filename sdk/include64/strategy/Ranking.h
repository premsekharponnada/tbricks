#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Ranking.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Identifier.h"
#include "strategy/type/String.h"

namespace tbricks {

class STRATEGY_EXPORT Ranking : public Printable
{
public:
    Ranking();
    Ranking(const Identifier & identifier);
    Ranking(const Ranking & ranking);

    Ranking & operator=(const Ranking & ranking);
    virtual ~Ranking();

public:
    const Identifier & GetIdentifier() const;
    const String & GetName() const;
    bool Deleted() const;

public:
    bool Resolve(const Identifier & identifier);

public:
    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_identifier;
    String m_name;
    bool m_deleted;
};
}

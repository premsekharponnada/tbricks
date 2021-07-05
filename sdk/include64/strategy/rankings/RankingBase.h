#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Ranking API.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"

namespace tbricks {

class STRATEGY_EXPORT RankingBase : public Printable
{
public:
    enum RankingType
    {
        RankingTypeMarket = 0,
        RankingTypeVenue = 1,
        RankingTypeService = 2,
        RankingTypeParameterContext = 3,
        RankingTypeEnumeration = 4,
        RankingTypeEmpty = 5
    };

public:
    RankingBase();
    RankingBase(const RankingBase & ranking);
    RankingBase & operator=(const RankingBase & ranking);
    virtual ~RankingBase();

public:
    virtual bool Resolve(const Identifier & identifier) = 0;

public:
    const Identifier & GetIdentifier() const;

    const String & GetName() const;
    const String & GetDescription() const;

    RankingType GetType() const;
    const Identifier & GetTypeIdentifier() const;

    const Boolean & Deleted() const;

public:
    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const = 0;

protected:
    friend STRATEGY_EXPORT class Converter;

    Identifier m_identifier;

    Boolean m_deleted;

    String m_name;
    String m_description;

    RankingType m_type;
    Identifier m_type_identifier;
};

} // namespace tbricks

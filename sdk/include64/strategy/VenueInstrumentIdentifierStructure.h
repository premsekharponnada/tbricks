#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Venue instrument identifier structure description
//****************************************************************************************

#include "type/Integer.h"
#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/SparseHash.h"

namespace tbricks {

namespace venue {
class VenueInfo;
}

class STRATEGY_EXPORT VenueInstrumentIdentifierStructure : public Printable
{
    friend class Venue;

public:
    class STRATEGY_EXPORT Key
    {
    public:
        Key();
        Key(const Integer & tag);

        const Integer & GetTag() const;

    private:
        Integer m_tag;
    };

    VenueInstrumentIdentifierStructure();
    VenueInstrumentIdentifierStructure(const VenueInstrumentIdentifierStructure & viids);
    ~VenueInstrumentIdentifierStructure() override;

    VenueInstrumentIdentifierStructure & operator=(const VenueInstrumentIdentifierStructure & viids);

    const SparseHash<String, Key> & GetKeys() const;

    bool Empty() const;

    std::ostream & Print(std::ostream & strm) const override;

private:
    SparseHash<String, Key> m_map_keys;

    void Init(const tbricks::venue::VenueInfo * vi);
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CombinationType type.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/InstrumentGroup.h"
#include "strategy/type/InstrumentGroupIdentifier.h"
#include "strategy/type/String.h"

// \namespace tbricks
namespace tbricks {

namespace combination {
class Combination;
}

class STRATEGY_EXPORT CombinationType : public Printable
{
public:
    class Leg;

public:
    CombinationType();
    CombinationType(const InstrumentGroupIdentifier & group_id);
    CombinationType(const CombinationType & combination);
    ~CombinationType() override;

    CombinationType & operator=(const CombinationType & combination);

public:
    bool Resolve(const InstrumentGroupIdentifier & group_id);

public:
    const String & GetName() const;
    const String & GetShortName() const;
    const InstrumentGroupIdentifier & GetInstrumentGroupIdentifier() const;

    const std::vector<Leg> & GetLegs() const;

public:
    void Clear();
    bool Empty() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    void Decode(const combination::Combination & combo);

private:
    String m_name;
    String m_short_name;
    InstrumentGroupIdentifier m_ins_group_id;

    std::vector<Leg> m_legs;
};

class STRATEGY_EXPORT CombinationType::Leg : public Printable
{
public:
    enum Type
    {
        Futures,
        Option,
        Call,
        Put,
        Underlying
    };

public:
    Leg();
    Leg(const Leg & leg);
    ~Leg() override;

public:
    const Type & GetType() const;
    const Integer & GetExpirationOffset() const;
    const Integer & GetStrikeOffset() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Leg(const Type & type, const Integer & expiration_offset, const Integer & strike_offset);

private:
    friend class CombinationType;

    Type m_type = Futures;
    Integer m_expiration_offset;
    Integer m_strike_offset;
};

} // \namespace tbricks

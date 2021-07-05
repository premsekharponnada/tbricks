#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Participation policy enumerator type
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include "strategy/Value.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT ParticipationPolicy : public AnyType
{
public:
    enum PolicyValue
    {
        DARK_LIT_SWEEP = 0,
        BYPASS_UNDISCLOSED,
        INDICATIVE_ONLY
    };

    ParticipationPolicy();
    ParticipationPolicy(PolicyValue value);
    ParticipationPolicy(const ParticipationPolicy & value);

    ParticipationPolicy & operator=(PolicyValue value);
    ParticipationPolicy & operator=(const ParticipationPolicy & value);

    bool Empty() const override { return m_value.Empty(); }
    void Clear();
    PolicyValue Get() const;

    bool IsDarkLitSweep() const;
    bool IsByPassUndisclosed() const;
    bool IsIndicativeOnly() const;

    size_t GetHash() const override;
    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator PolicyValue() const { return Get(); }

public:
    bool operator==(PolicyValue value) const;
    bool operator!=(PolicyValue value) const;

    bool operator==(const ParticipationPolicy & value) const;
    bool operator!=(const ParticipationPolicy & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    Value<PolicyValue> m_value;
};

STRATEGY_EXPORT
bool operator==(ParticipationPolicy::PolicyValue v1, const ParticipationPolicy & v2);

STRATEGY_EXPORT
bool operator!=(ParticipationPolicy::PolicyValue v1, const ParticipationPolicy & v2);

} // \namespace tbricks

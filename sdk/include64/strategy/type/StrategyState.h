#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy state type.
//****************************************************************************************

#include "strategy/type/AnyType.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT StrategyState : public AnyType
{
public:
    enum StateValue
    {
        NONE = 0,
        PAUSED = 1,
        RUNNING = 2,
        DELETED = 3
    };

public:
    StrategyState();
    StrategyState(StateValue value);
    StrategyState(const StrategyState & value);

    StrategyState & operator=(StateValue value);
    StrategyState & operator=(const StrategyState & value);

    bool Empty() const override { return m_value == NONE; }
    void Clear();
    StateValue Get() const;

    bool IsPaused() const;
    bool IsRunning() const;
    bool IsDeleted() const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator StateValue() const { return Get(); }

public:
    bool operator==(StateValue value) const;
    bool operator!=(StateValue value) const;

    bool operator==(const StrategyState & value) const;
    bool operator!=(const StrategyState & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    StateValue m_value;
};

STRATEGY_EXPORT
bool operator==(StrategyState::StateValue v1, const StrategyState & v2);

STRATEGY_EXPORT
bool operator!=(StrategyState::StateValue v1, const StrategyState & v2);

} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy transaction state type.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/String.h"

// \namespace tbricks
namespace tbricks {

/**
 * Trading limit state.
 *
 */
class STRATEGY_EXPORT TradingLimitState : public Printable
{
public:
    enum StateValue
    {
        NO_RULES = 0,
        OK = 1,
        SOFT_BREACH = 2,
        HARD_BREACH = 3
    };

public:
    TradingLimitState();
    TradingLimitState(StateValue value);
    TradingLimitState(const TradingLimitState & value);

    TradingLimitState & operator=(StateValue value);
    TradingLimitState & operator=(const TradingLimitState & value);

    bool Empty() const;
    void Clear();
    StateValue Get() const;

    bool IsOk() const;
    bool IsNoRules() const;
    bool IsSoftBreach() const;
    bool IsHardBreach() const;

    operator StateValue() const { return Get(); }

public:
    bool operator==(StateValue value) const;
    bool operator!=(StateValue value) const;

    bool operator==(const TradingLimitState & value) const;
    bool operator!=(const TradingLimitState & value) const;

private:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    bool m_empty;
    StateValue m_value;
};

STRATEGY_EXPORT
bool operator==(TradingLimitState::StateValue v1, const TradingLimitState & v2);

STRATEGY_EXPORT
bool operator!=(TradingLimitState::StateValue v1, const TradingLimitState & v2);

} // \namespace tbricks

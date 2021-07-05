#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Set of strategy types.
//****************************************************************************************

#include <vector>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/StdInt.h"
#include "strategy/type/StrategyState.h"

// \namespace tbricks
namespace tbricks {

namespace types {
class Any;
}

/**
 * StrategyStateSet, aggregation of possible strategy states, for use in
 * filters and such.
 */
class STRATEGY_EXPORT StrategyStateSet : public Printable
{
public:
    typedef uint16_t Value;
    class const_iterator;

public:
    StrategyStateSet();
    StrategyStateSet(StrategyState::StateValue v);
    StrategyStateSet(const StrategyStateSet & set);

    bool operator==(const StrategyStateSet & set) const;
    bool operator!=(const StrategyStateSet & set) const;

    StrategyStateSet & operator=(StrategyState::StateValue v);
    StrategyStateSet & operator=(const StrategyStateSet & set);

    StrategyStateSet operator|(StrategyState::StateValue v);
    StrategyStateSet & operator|=(StrategyState::StateValue v);
    StrategyStateSet & operator|=(const StrategyStateSet & set);

    StrategyStateSet operator&(StrategyState::StateValue v);
    StrategyStateSet & operator&=(StrategyState::StateValue v);
    StrategyStateSet & operator&=(const StrategyStateSet & set);

    StrategyStateSet operator~();

    bool Has(StrategyState::StateValue v) const;
    bool Has(const StrategyState & state) const;

    Value Get() const;
    bool Empty() const;
    void Clear();
    void Fill();

public:
    void Encode(std::vector<tbricks::types::Any> & values) const;

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    const_iterator begin() const;
    const_iterator end() const;

private:
    Value m_set;
};

class STRATEGY_EXPORT StrategyStateSet::const_iterator
{
public:
    const_iterator();
    const_iterator(const const_iterator & it);
    ~const_iterator();

    const_iterator & operator=(const const_iterator & it);

    bool operator==(const const_iterator & it) const;
    bool operator!=(const const_iterator & it) const;

    const_iterator & operator++();
    const_iterator operator++(int);

    StrategyState Get() const;
    StrategyState operator*() const;

private:
    friend StrategyStateSet;

private:
    StrategyStateSet m_set;
    int m_value;
};

} // \namespace tbricks

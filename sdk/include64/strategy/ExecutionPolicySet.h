#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Set of supported execution policies.
//****************************************************************************************

#include <vector>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/StdInt.h"
#include "strategy/type/ExecutionPolicy.h"

namespace tbricks {

/**
 * ExecutionPolicySet a convenience aggregation of possible
 * execution policy values.
 */
class STRATEGY_EXPORT ExecutionPolicySet
{
public:
    class const_iterator;

public:
    ExecutionPolicySet() : m_value(EMPTY) {}

    /**
     * Creates a set with specified execution policy.
     *
     * @param value   execution policy
     */
    ExecutionPolicySet(ExecutionPolicy::ExecutionPolicyValue value) : m_value((uint16_t)((uint16_t)1 << (uint16_t)value)) {}

    bool operator==(const ExecutionPolicySet & set) const { return m_value == set.m_value; }

    bool operator!=(const ExecutionPolicySet & set) const { return !operator==(set); }

    ExecutionPolicySet & operator=(ExecutionPolicy::ExecutionPolicyValue value)
    {
        m_value = (uint16_t)((uint16_t)1 << (uint16_t)value);
        return *this;
    }

    /**
     * Creates a new set. The new set will consist all values from this set and
     * passed value.
     *
     * @param value   execution policy
     * @return        new set
     */
    ExecutionPolicySet operator|(ExecutionPolicy::ExecutionPolicyValue value) const
    {
        ExecutionPolicySet set(*this);
        set |= value;
        return set;
    }

    /**
     * Adds passed execution policy to this set.
     *
     * @param value   added execution policy
     * @return        this set
     */
    ExecutionPolicySet & operator|=(ExecutionPolicy::ExecutionPolicyValue value)
    {
        m_value |= (uint16_t)((uint16_t)1 << (uint16_t)value);
        return *this;
    }

    /**
     * Creates a new set. The new set will consist of only passed value
     * if the this set includes it otherwise, the new set will be empty.
     *
     * @param value   execution policy
     * @return        new policy set
     */
    ExecutionPolicySet operator&(ExecutionPolicy::ExecutionPolicyValue value) const
    {
        ExecutionPolicySet set(*this);
        set &= value;
        return set;
    }

    /**
     * Changes this set. The set will consist of only passed value
     * if the set includes it otherwise, the set will be empty.
     *
     * @param value   execution policy
     * @return        this set
     */
    ExecutionPolicySet & operator&=(ExecutionPolicy::ExecutionPolicyValue value)
    {
        m_value &= (uint16_t)((uint16_t)1 << (uint16_t)value);
        return *this;
    }

    /**
     * Creates new set. The new set will contain only values
     * that are not in this set.
     *
     * @return       new set
     */
    ExecutionPolicySet operator~()
    {
        ExecutionPolicySet set;
        set.m_value = (~m_value) & ALL;
        return set;
    }

    /**
     * @return       True if the set contain passed value otherwise, False
     */
    bool Has(ExecutionPolicy::ExecutionPolicyValue value) const { return (0 != (m_value & ((uint16_t)1 << (uint16_t)value))); }

    uint16_t Get() const { return m_value; }

    bool Empty() const { return m_value == EMPTY; }

    void Clear() { m_value = EMPTY; }

    const_iterator begin() const;

    const_iterator end() const;

public:
    static const uint16_t EMPTY = 0;
    static const uint16_t ALL = 0x3e;
    static const uint16_t FIRST = ExecutionPolicy::BUY_MINUS;
    static const uint16_t LAST = ExecutionPolicy::SELL_UNDISCLOSED;

private:
    uint16_t m_value;
};

class STRATEGY_EXPORT ExecutionPolicySet::const_iterator
{
public:
    bool operator==(const const_iterator & it) const { return (m_set == it.m_set) && (m_value == it.m_value); }

    bool operator!=(const const_iterator & it) const { return !operator==(it); }

    const_iterator & operator++();

    const_iterator operator++(int);

    ExecutionPolicy Get() const { return static_cast<ExecutionPolicy::ExecutionPolicyValue>(m_value); }

    ExecutionPolicy operator*() const { return Get(); }

private:
    friend class ExecutionPolicySet;

private:
    ExecutionPolicySet m_set;
    int m_value;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Set of order capacities.
//****************************************************************************************

#include <vector>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/StdInt.h"
#include "strategy/type/OrderCapacity.h"

// \namespace tbricks
namespace tbricks {

namespace types {
class Any;
}

class ValidationItem;

/**
 * OrderCapacitySet, aggregation of possible order capacities
 */
class STRATEGY_EXPORT OrderCapacitySet : public Printable
{
public:
    typedef uint8_t Value;
    class const_iterator;

    /// @deprecated Deprecated in 2.11.2, will be removed in 2.12.0
    [[deprecated(DEPRECATE_LINK)]] typedef const_iterator ConstIterator;

public:
    OrderCapacitySet();
    OrderCapacitySet(OrderCapacity::CapacityValue type);
    OrderCapacitySet(const OrderCapacitySet & set);

    bool operator==(const OrderCapacitySet & set) const;
    bool operator!=(const OrderCapacitySet & set) const;

    OrderCapacitySet & operator=(OrderCapacity::CapacityValue type);
    OrderCapacitySet & operator=(const OrderCapacitySet & set);

    OrderCapacitySet operator|(OrderCapacity::CapacityValue type);
    OrderCapacitySet & operator|=(OrderCapacity::CapacityValue type);
    OrderCapacitySet & operator|=(const OrderCapacitySet & set);

    OrderCapacitySet operator&(OrderCapacity::CapacityValue type);
    OrderCapacitySet & operator&=(OrderCapacity::CapacityValue type);
    OrderCapacitySet & operator&=(const OrderCapacitySet & set);
    OrderCapacitySet operator~();

    bool Has(OrderCapacity::CapacityValue type) const;

    bool Has(const OrderCapacity & state) const;

    Value Get() const;

    bool Empty() const;
    void Clear();
    void Fill();

public:
    void Encode(std::vector<tbricks::types::Any> & values) const;

    std::ostream & Print(std::ostream & strm) const override;

public:
    const_iterator begin() const;
    const_iterator end() const;

private:
    Value m_set;
};

class STRATEGY_EXPORT OrderCapacitySet::const_iterator
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

    OrderCapacity Get() const;
    OrderCapacity operator*() const;

private:
    friend OrderCapacitySet;

private:
    OrderCapacitySet m_set;
    int m_value;
};

} // \namespace tbricks

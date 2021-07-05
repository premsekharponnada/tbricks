#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Set of supported validity types.
//****************************************************************************************

#include <vector>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/StdInt.h"
#include "strategy/type/Validity.h"

// \namespace tbricks
namespace tbricks {

namespace types {
class Any;
}

/**
 * ValidityTypeSet, a convenience aggregation of possible validity types.
 * Normally used in places where a few types can be used and/or returned
 * simultaneously -- for instance, when an object returns supported
 * types.
 */
class STRATEGY_EXPORT ValidityTypeSet : public Printable
{
public:
    typedef uint16_t Value;
    class const_iterator;

public:
    ValidityTypeSet();
    ValidityTypeSet(Validity::Type type);
    ValidityTypeSet(const ValidityTypeSet & set);

    bool operator==(const ValidityTypeSet & set) const;
    bool operator!=(const ValidityTypeSet & set) const;

    ValidityTypeSet & operator=(Validity::Type type);
    ValidityTypeSet & operator=(const ValidityTypeSet & set);

    ValidityTypeSet operator|(Validity::Type type);
    ValidityTypeSet & operator|=(Validity::Type type);

    ValidityTypeSet operator&(Validity::Type type);
    ValidityTypeSet & operator&=(Validity::Type type);

    ValidityTypeSet operator~();

    bool Has(Validity::Type type) const;
    bool Has(const Validity & validity) const;

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

class STRATEGY_EXPORT ValidityTypeSet::const_iterator
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

    Validity Get() const;
    Validity operator*() const;

private:
    friend ValidityTypeSet;

private:
    ValidityTypeSet m_set;
    int m_value;
};

} // \namespace tbricks

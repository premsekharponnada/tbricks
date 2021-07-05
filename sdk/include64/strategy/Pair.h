#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Pair template type.
//****************************************************************************************

#include <iostream>
#include "strategy/Printable.h"

// \namespace tbricks
namespace tbricks {

template <typename FirstT, typename SecondT>
class STRATEGY_EXPORT Pair : public Printable
{
public:
    Pair() {}
    virtual ~Pair() {}
    Pair(const FirstT & f, const SecondT & s) : first(f), second(s) {}

    bool operator<(const Pair & p) const { return (first < p.first) || ((first == p.first) && (second < p.second)); }
    bool operator==(const Pair & p) const { return (first == p.first) && (second == p.second); }
    bool operator!=(const Pair & p) const { return !operator==(p); }

    bool Empty() const { return first.Empty() && second.Empty(); }
    void Clear()
    {
        first.Clear();
        second.Clear();
    }

    size_t GetHash() const
    {
        size_t hash = 0;
        hash += first.GetHash();
        spread(hash);
        hash += second.GetHash();
        spread(hash);
        return hash;
    }

private:
    static void spread(size_t & hash) { hash -= (hash << 13) | (hash >> 19); }

public:
    virtual std::ostream & Print(std::ostream & strm) const { return strm << '{' << first << ',' << second << '}'; }

public:
    FirstT first;
    SecondT second;
};

template <typename FirstT, typename SecondT>
inline size_t hash_value(const Pair<FirstT, SecondT> & value)
{
    return value.GetHash();
}

} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Printable abstract class
//****************************************************************************************

#include "strategy/Linkage.h"
#include <iosfwd>

namespace tbricks {

class String;
class STRATEGY_EXPORT Printable
{
public:
    Printable() = default;
    Printable(const Printable &) = default;
    virtual ~Printable() = default;

    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const Printable & printable);

    virtual std::ostream & Print(std::ostream & strm) const = 0;

    virtual String ToString() const;
};

} // namespace tbricks {

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Field filter.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Field.h"

#include <set>

namespace tbricks {

class Stream;

class STRATEGY_EXPORT FieldFilter : public Printable
{
public:
    FieldFilter();
    FieldFilter(const Field & field);
    FieldFilter(const FieldFilter & filter);

    FieldFilter & operator=(const FieldFilter & filter);

    FieldFilter operator||(const Field & field) const;
    FieldFilter operator||(const FieldFilter & filter) const;

    FieldFilter & operator|=(const Field & field);
    FieldFilter & operator|=(const FieldFilter & filter);

    bool operator==(const FieldFilter & filter) const;
    bool operator!=(const FieldFilter & filter) const;

    bool Empty() const;
    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

    STRATEGY_EXPORT friend std::ostream & operator<<(std::ostream & strm, const FieldFilter & filter);

    friend class Stream;

private:
    std::set<Field> m_fields;
};
}

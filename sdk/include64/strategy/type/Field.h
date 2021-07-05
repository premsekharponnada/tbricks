#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Field type.
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/type/String.h"

// \namespace tbricks
namespace tbricks {

class FieldFilter;

class STRATEGY_EXPORT Field : public Printable
{
public:
    Field();

protected:
    Field(int field_key);

public:
    Field(const Field & field);

    Field & operator=(const Field & field);

    FieldFilter operator||(const Field & field) const;

    bool operator==(const Field & field) const;
    bool operator!=(const Field & field) const;

    bool operator<(const Field & field) const;
    bool operator>(const Field & field) const;

    bool Empty() const;
    void Clear();

    std::ostream & Print(std::ostream & strm) const override;
    const char * GetName() const;

    STRATEGY_EXPORT friend std::ostream & operator<<(std::ostream & strm, const Field & field);

    friend class Stream;

private:
    int m_key;
};

} // \namespace tbricks

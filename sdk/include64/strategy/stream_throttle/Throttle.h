#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Throttle options base class.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/String.h"
#include "strategy/type/Duration.h"

namespace tbricks {

namespace filter {
class FieldFilter;
class ICondition;
}

class STRATEGY_EXPORT Throttle : public Printable
{
public:
    enum ChangeType
    {
        RELATIVE_CHANGE,
        ABSOLUTE_CHANGE,

        /// DEPRECATED: use RELATIVE_CHANGE instead of PERCENT_CHANGE
        PERCENT_CHANGE
    };

    void Clear();
    bool Empty() const;

    const tbricks::filter::FieldFilter & GetValue() const;
    void SetValue(const tbricks::filter::FieldFilter & ff);

protected:
    Throttle();
    ~Throttle();

    void add_condition(const tbricks::filter::ICondition & cond);
    void add_filter(const Throttle & throttle);
    void set_filter(const Throttle & throttle);

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    // prohibited
    Throttle(const Throttle &);
    Throttle & operator=(const Throttle &);

private:
    tbricks::filter::FieldFilter * m_filter;
};
}

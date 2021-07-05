#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DateTime Conditions
//
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/DateTime.h"
#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/** This conditions should be used only for DateTimeFraction type. */

class STRATEGY_EXPORT DateTimeConditionImpl
{
public:
    DateTimeConditionImpl(const DateTime & from, const DateTime & until);

    void Clear()
    {
        m_from.Clear();
        m_until.Clear();
    }

    bool Empty() const { return (m_from.Empty() && m_until.Empty()); }

    void SetFromDate(const DateTime & from) { m_from = from; }

    const DateTime & GetFromDate() const { return m_from; }

    void SetUntilDate(const DateTime & until) { m_until = until; }

    const DateTime & GetUntilDate() const { return m_until; }

    tbricks::filter::FieldFilter GetValue(int key) const;
    std::ostream & Print(std::ostream & strm) const;

private:
    DateTime m_from;
    DateTime m_until;
};

class STRATEGY_EXPORT DateTimeWithRelationConditionImpl
{
public:
    DateTimeWithRelationConditionImpl(const tbricks::Filter::Relation & relation, const DateTime & datetime);

    void Clear() { m_datetime.Clear(); }

    bool Empty() const { return m_datetime.Empty(); }

    tbricks::filter::FieldFilter GetValue(int key) const;
    std::ostream & Print(std::ostream & strm) const;

private:
    tbricks::Filter::Relation m_relation;
    DateTime m_datetime;
};
}

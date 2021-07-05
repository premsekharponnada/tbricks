#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// LogEntry filters
//****************************************************************************************

#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/LogEntryStream.h"
#include "strategy/type/LogEntryLevel.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"

namespace tbricks {

class STRATEGY_EXPORT LogEntry::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Filter & filter);
    virtual ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const Filter & filter);
    Filter & operator&=(const Filter & filter);

    Filter operator||(const Filter & filter);
    Filter operator&&(const Filter & filter);

    Filter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

class STRATEGY_EXPORT LogEntry::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    LogEntry::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    LogEntry::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    LogEntry::Stream::Filters::Filter operator||(const Filter & cond) const;
    LogEntry::Stream::Filters::Filter operator&&(const Filter & cond) const;
    LogEntry::Stream::Filters::Filter operator!() const;
    operator LogEntry::Stream::Filters::Filter() const;
};

class STRATEGY_EXPORT LogEntry::Stream::Filters::ByLevel : public LogEntry::Stream::Filters::FilterCondition
{
public:
    ByLevel(const Filter::Relation & relation, LogEntryLevel level);
    ByLevel(const ByLevel & filter) = default;
    virtual ~ByLevel() = default;

    ByLevel & operator=(const ByLevel & filter) = default;

    void Clear() override { m_level.reset(); }
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override { return !m_level.has_value(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    Filter::Relation m_relation;
    std::optional<LogEntryLevel> m_level;
};

class STRATEGY_EXPORT LogEntry::Stream::Filters::ByStrategyIdentifier : public LogEntry::Stream::Filters::FilterCondition
{
public:
    ByStrategyIdentifier(const StrategyIdentifier & id);
    ByStrategyIdentifier(const ByStrategyIdentifier & filter) = default;
    virtual ~ByStrategyIdentifier() = default;

    ByStrategyIdentifier & operator=(const ByStrategyIdentifier & filter) = default;

    void Clear() override { m_id.Clear(); }
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override { return m_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    StrategyIdentifier m_id;
};

class STRATEGY_EXPORT LogEntry::Stream::Filters::ByCreatedDateTime : public LogEntry::Stream::Filters::FilterCondition
{
public:
    ByCreatedDateTime(const DateTime & from, const DateTime & until);
    ByCreatedDateTime(const ByCreatedDateTime & filter) = default;
    virtual ~ByCreatedDateTime() = default;

    ByCreatedDateTime & operator=(const ByCreatedDateTime & filter) = default;

    void SetFromDate(const DateTime & from) { m_impl.SetFromDate(from); }

    void SetUntilDate(const DateTime & until) { m_impl.SetUntilDate(until); }

    const DateTime & GetFromDate() const { return m_impl.GetFromDate(); }

    const DateTime & GetUntilDate() const { return m_impl.GetUntilDate(); }

    void SetFromUntilDate(const DateTime & from, const DateTime & until)
    {
        m_impl.SetFromDate(from);
        m_impl.SetUntilDate(until);
    }

    void Clear() override { m_impl.Clear(); }
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override { return m_impl.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    DateTimeConditionImpl m_impl;
};
}

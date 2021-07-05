#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BlockOrderFilter objects.
//****************************************************************************************

#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/stream/BlockOrderStream.h"
#include "strategy/Strategy.h"

namespace tbricks {

/**
 * Base instrument order filter class.
 */
class STRATEGY_EXPORT BlockOrder::Stream::Filters::Filter : public tbricks::Filter
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

class STRATEGY_EXPORT BlockOrder::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    BlockOrder::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    BlockOrder::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    BlockOrder::Stream::Filters::Filter operator||(const Filter & cond) const;
    BlockOrder::Stream::Filters::Filter operator&&(const Filter & cond) const;
    BlockOrder::Stream::Filters::Filter operator!() const;
    operator BlockOrder::Stream::Filters::Filter() const;
};

/// Active orders

class STRATEGY_EXPORT BlockOrder::Stream::Filters::Active : public BlockOrder::Stream::Filters::FilterCondition
{
public:
    Active() = default;
    Active(const Active & filter) = default;
    virtual ~Active() = default;

    Active & operator=(const Active & filter) = default;

    virtual void Clear() {}
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return false; }

protected:
    virtual std::ostream & Print(std::ostream & strm) const { return strm << "active"; }
};

/// ByHostModifiedDateTime
class STRATEGY_EXPORT BlockOrder::Stream::Filters::ByHostModifiedDateTime : public BlockOrder::Stream::Filters::FilterCondition
{
public:
    ByHostModifiedDateTime(const tbricks::Filter::Relation & relation, const DateTime & datetime) : m_impl(relation, datetime) {}

    virtual bool Empty() const { return m_impl.Empty(); }

    virtual void Clear() { m_impl.Clear(); }

    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << "<block order by host modified datetime filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeWithRelationConditionImpl m_impl;
};

/// ByHostCreatedDateTime
class STRATEGY_EXPORT BlockOrder::Stream::Filters::ByHostCreatedDateTime : public BlockOrder::Stream::Filters::FilterCondition
{
public:
    ByHostCreatedDateTime(const tbricks::Filter::Relation & relation, const DateTime & datetime) : m_impl(relation, datetime) {}

    virtual bool Empty() const { return m_impl.Empty(); }

    virtual void Clear() { m_impl.Clear(); }

    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << "<block order by host created datetime filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeWithRelationConditionImpl m_impl;
};

/// ByParentStrategy
class STRATEGY_EXPORT BlockOrder::Stream::Filters::ByParentStrategy : public BlockOrder::Stream::Filters::FilterCondition
{
public:
    ByParentStrategy(const Strategy & strategy);
    ByParentStrategy(const StrategyIdentifier & strategy_id);
    ByParentStrategy(const ByParentStrategy & filter) = default;
    virtual ~ByParentStrategy() = default;

    ByParentStrategy & operator=(const ByParentStrategy & filter) = default;

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_strategy_id;
};
}

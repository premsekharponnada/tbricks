#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuote filters
//****************************************************************************************

#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/DirectedQuoteStream.h"
#include "strategy/Value.h"
#include "strategy/type/DirectedQuoteIdentifier.h"
#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"

namespace tbricks {

class STRATEGY_EXPORT DirectedQuote::Stream::Filters::Filter : public tbricks::Filter
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

class STRATEGY_EXPORT DirectedQuote::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    DirectedQuote::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    DirectedQuote::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    DirectedQuote::Stream::Filters::Filter operator||(const Filter & cond) const;
    DirectedQuote::Stream::Filters::Filter operator&&(const Filter & cond) const;
    DirectedQuote::Stream::Filters::Filter operator!() const;
    operator DirectedQuote::Stream::Filters::Filter() const;
};

class STRATEGY_EXPORT DirectedQuote::Stream::Filters::ByIdentifier : public DirectedQuote::Stream::Filters::FilterCondition
{
public:
    ByIdentifier(const DirectedQuoteIdentifier & id);
    ByIdentifier(const ByIdentifier & filter) = default;
    virtual ~ByIdentifier() = default;

    ByIdentifier & operator=(const ByIdentifier & filter) = default;

    void Clear() override { m_id.Clear(); }
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override { return m_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    DirectedQuoteIdentifier m_id;
};

class STRATEGY_EXPORT DirectedQuote::Stream::Filters::Deleted : public DirectedQuote::Stream::Filters::FilterCondition
{
public:
    Deleted(bool deleted) : m_deleted(deleted) {}
    Deleted(const Deleted & filter) = default;
    virtual ~Deleted() = default;

    Deleted & operator=(const Deleted & filter) = default;

    void SetDeleted(bool deleted) { m_deleted = deleted; }

    void Clear() override { m_deleted.Clear(); }
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override { return m_deleted.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    Value<bool> m_deleted;
};

/**
 * DirectedQuote::Stream::Filters::ByHostCreatedDateTime matches concrete
 * directed quote instance updates, selected by ExPit created date and time range.
 */
class STRATEGY_EXPORT DirectedQuote::Stream::Filters::ByHostCreatedDateTime : public DirectedQuote::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all ExPit created in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                  Date/time to start the search from
     * @param until                 Date/time to end the search with
     */
    ByHostCreatedDateTime(const DateTime & from, const DateTime & until) : m_impl(from, until) {}

    virtual void Clear() { m_impl.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_impl.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DateTimeConditionImpl m_impl;
};

/**
 * DirectedQuote::Stream::Filters::ByHostModifiedDateTime matches concrete
 * directed quote instance updates, selected by ex-pit modified date and time range.
 */
class STRATEGY_EXPORT DirectedQuote::Stream::Filters::ByHostModifiedDateTime : public DirectedQuote::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all ExPit modified in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                  Date/time to start the search from
     * @param until                 Date/time to end the search with
     */
    ByHostModifiedDateTime(const DateTime & from, const DateTime & until) : m_impl(from, until) {}

    virtual void Clear() { m_impl.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_impl.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DateTimeConditionImpl m_impl;
};
}

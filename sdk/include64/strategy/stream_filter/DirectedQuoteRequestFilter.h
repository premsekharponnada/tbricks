#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteRequest filters
//****************************************************************************************

#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/DirectedQuoteRequestStream.h"
#include "strategy/Value.h"
#include "strategy/type/DirectedQuoteRequestIdentifier.h"
#include "strategy/type/VenueIdentifier.h"
#include "strategy/type/VenueInstrumentIdentifier.h"
#include "strategy/type/StrategyIdentifier.h"

namespace tbricks {

class STRATEGY_EXPORT DirectedQuoteRequest::Stream::Filters::Filter : public tbricks::Filter
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

class STRATEGY_EXPORT DirectedQuoteRequest::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    DirectedQuoteRequest::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    DirectedQuoteRequest::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    DirectedQuoteRequest::Stream::Filters::Filter operator||(const Filter & cond) const;
    DirectedQuoteRequest::Stream::Filters::Filter operator&&(const Filter & cond) const;
    DirectedQuoteRequest::Stream::Filters::Filter operator!() const;
    operator DirectedQuoteRequest::Stream::Filters::Filter() const;
};

class STRATEGY_EXPORT DirectedQuoteRequest::Stream::Filters::ByIdentifier : public DirectedQuoteRequest::Stream::Filters::FilterCondition
{
public:
    ByIdentifier(const DirectedQuoteRequestIdentifier & id);
    ByIdentifier(const ByIdentifier & filter) = default;
    virtual ~ByIdentifier() = default;

    ByIdentifier & operator=(const ByIdentifier & filter) = default;

    void Clear() override { m_id.Clear(); }
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override { return m_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    DirectedQuoteRequestIdentifier m_id;
};

class STRATEGY_EXPORT DirectedQuoteRequest::Stream::Filters::Deleted : public DirectedQuoteRequest::Stream::Filters::FilterCondition
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

class STRATEGY_EXPORT DirectedQuoteRequest::Stream::Filters::ByVenueInstrumentIdentifier
    : public DirectedQuoteRequest::Stream::Filters::FilterCondition
{
public:
    ByVenueInstrumentIdentifier(const VenueInstrumentIdentifier & value) : m_value(value) {}
    ByVenueInstrumentIdentifier(const ByVenueInstrumentIdentifier & value) = default;
    virtual ~ByVenueInstrumentIdentifier() = default;

    ByVenueInstrumentIdentifier & operator=(const ByVenueInstrumentIdentifier & value) = default;

    void Clear() override { m_value.Clear(); }
    bool Empty() const override { return m_value.Empty(); }
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    VenueInstrumentIdentifier m_value;
};

class STRATEGY_EXPORT DirectedQuoteRequest::Stream::Filters::ByVenue : public DirectedQuoteRequest::Stream::Filters::FilterCondition
{
public:
    ByVenue(const VenueIdentifier & value) : m_value(value) {}
    ByVenue(const ByVenue & value) = default;
    virtual ~ByVenue() = default;

    ByVenue & operator=(const ByVenue & value) = default;

    void Clear() override { m_value.Clear(); }
    bool Empty() const override { return m_value.Empty(); }
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    VenueIdentifier m_value;
};

class STRATEGY_EXPORT DirectedQuoteRequest::Stream::Filters::ByParentStrategy : public DirectedQuoteRequest::Stream::Filters::FilterCondition
{
public:
    ByParentStrategy(const StrategyIdentifier & strategy_id);
    ByParentStrategy(const ByParentStrategy & filter);
    virtual ~ByParentStrategy();

    ByParentStrategy & operator=(const ByParentStrategy & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_strategy_id;
};
}

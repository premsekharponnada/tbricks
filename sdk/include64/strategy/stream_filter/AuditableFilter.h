#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in regulatory audit streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"
#include "strategy/type/InstrumentIdentifier.h"

namespace tbricks {

/**
 * Default regulatory audit filter, matches all data.
 */
class STRATEGY_EXPORT AuditableFilter : public Filter
{
public:
    AuditableFilter();
    AuditableFilter(const AuditableFilter & filter);
    ~AuditableFilter();

    AuditableFilter & operator=(const AuditableFilter & filter);

    AuditableFilter & operator|=(const AuditableFilter & filter);
    AuditableFilter & operator&=(const AuditableFilter & filter);

    AuditableFilter operator||(const AuditableFilter & filter);
    AuditableFilter operator&&(const AuditableFilter & filter);

    AuditableFilter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

/**
 * Convenience alias.
 */
typedef AuditableFilter AnyAuditableFilter;

class STRATEGY_EXPORT AuditableFilterCondition : public FilterCondition
{
public:
    AuditableFilter operator||(const AuditableFilterCondition & cond) const;
    AuditableFilter operator&&(const AuditableFilterCondition & cond) const;
    AuditableFilter operator||(const AuditableFilter & cond) const;
    AuditableFilter operator&&(const AuditableFilter & cond) const;
    AuditableFilter operator!() const;
    operator AuditableFilter() const;
};

class STRATEGY_EXPORT AuditableByInstrumentFilter : public AuditableFilterCondition
{
public:
    AuditableByInstrumentFilter(const InstrumentIdentifier & instrument_id);

    virtual void Clear() { m_instrument_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_instrument_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentIdentifier m_instrument_id;
};
}

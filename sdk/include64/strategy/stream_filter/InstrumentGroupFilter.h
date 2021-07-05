#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in instrument group streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"
#include "strategy/type/InstrumentGroupIdentifier.h"

namespace tbricks {

/**
 * Default instrument group filter, matches all data.
 */
class STRATEGY_EXPORT InstrumentGroupFilter : public Filter
{
public:
    InstrumentGroupFilter();
    InstrumentGroupFilter(const InstrumentGroupFilter & filter);
    ~InstrumentGroupFilter();

    InstrumentGroupFilter & operator=(const InstrumentGroupFilter & filter);

    InstrumentGroupFilter & operator|=(const InstrumentGroupFilter & filter);
    InstrumentGroupFilter & operator&=(const InstrumentGroupFilter & filter);

    InstrumentGroupFilter operator||(const InstrumentGroupFilter & filter);
    InstrumentGroupFilter operator&&(const InstrumentGroupFilter & filter);

    InstrumentGroupFilter operator!();

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
typedef InstrumentGroupFilter AnyInstrumentGroupFilter;

class STRATEGY_EXPORT InstrumentGroupFilterCondition : public FilterCondition
{
public:
    InstrumentGroupFilter operator||(const InstrumentGroupFilterCondition & cond) const;
    InstrumentGroupFilter operator&&(const InstrumentGroupFilterCondition & cond) const;
    InstrumentGroupFilter operator||(const InstrumentGroupFilter & cond) const;
    InstrumentGroupFilter operator&&(const InstrumentGroupFilter & cond) const;
    InstrumentGroupFilter operator!() const;
    operator InstrumentGroupFilter() const;
};

/**
 * InstrumentGroupByIdentifierFilter matches concrete instrument group instance updates
 */
class STRATEGY_EXPORT InstrumentGroupByIdentifierFilter : public InstrumentGroupFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the instrument group by identifier
     *
     * @param instrumentGroupId                            instrument group identifier.
     */
    InstrumentGroupByIdentifierFilter(const InstrumentGroupIdentifier & instrumentGroupId);
    InstrumentGroupByIdentifierFilter(const InstrumentGroupByIdentifierFilter & filter);

    InstrumentGroupByIdentifierFilter & operator=(const InstrumentGroupByIdentifierFilter & filter);

    void Clear() override;
    tbricks::filter::FieldFilter GetValue() const override;
    bool Empty() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    InstrumentGroupIdentifier m_instrumentGroupId;
};
}

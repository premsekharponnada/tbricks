#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in audit data streams.
//****************************************************************************************

#include "strategy/Instrument.h"
#include "strategy/stream/AuditDataStream.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"

#include <ostream>
#include <set>
#include <vector>

namespace tbricks {

/**
 * Default AuditData filter, matches all audit messages.
 */
class STRATEGY_EXPORT AuditData::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Filter & filter);
    ~Filter();

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

class STRATEGY_EXPORT AuditData::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Filter operator||(const FilterCondition & cond) const;
    Filter operator&&(const FilterCondition & cond) const;
    Filter operator||(const Filter & cond) const;
    Filter operator&&(const Filter & cond) const;
    Filter operator!() const;
    operator Filter() const;
};

/**
 * AuditData::Stream::Filters::ByCreatedDateTime mix-in, allows to improve stream granularity by
 * filtering out audit messages with specified creation time range.
 */
class STRATEGY_EXPORT AuditData::Stream::Filters::ByCreatedDateTime : public AuditData::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all audit messages created in the specified time frame,
     * including the boundaries.
     * Setting one of the parameters empty creates an interval filter with one end open.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    ByCreatedDateTime(const DateTime & from, const DateTime & until) : m_impl(from, until) {}

    /**
     * %Set initial point for the search.
     *
     * Final point value remains unchanged.
     *
     * @param from                      Date/time to start the search from
     */
    void SetFromDate(const DateTime & from) { m_impl.SetFromDate(from); }

    /**
     * Get current initial search point.
     *
     * @return                          Current settings for the starting point,
     *                                  which could be empty
     */
    const DateTime & GetFromDate() const { return m_impl.GetFromDate(); }

    /**
     * %Set final position for the search.
     *
     * Initial point value remains unchanged.
     *
     * @param until                     Date/time to end the search with
     */
    void SetUntilDate(const DateTime & until) { m_impl.SetUntilDate(until); }

    /**
     * Get current final search point.
     *
     * @return                          Current settings for the final point,
     *                                  which could be empty
     */
    const DateTime & GetUntilDate() const { return m_impl.GetUntilDate(); }

    /**
     * %Set a search range.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    void SetFromUntilDate(const DateTime & from, const DateTime & until)
    {
        m_impl.SetFromDate(from);
        m_impl.SetUntilDate(until);
    }

    virtual void Clear() { m_impl.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_impl.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << "<audit data by host created date time filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeConditionImpl m_impl;
};

/**
 * AuditData::Stream::Filters::ByInstrument matches audit messages selected by instrument identifier.
 */
class STRATEGY_EXPORT AuditData::Stream::Filters::ByInstrument : public AuditData::Stream::Filters::FilterCondition
{
public:
    /// Default constructor.
    ByInstrument();

    /**
     * Constructor.
     *
     * Makes a filter to match all the audit messages having
     * instrument as specified in the input parameter.
     *
     * @param instrument                Instance of Instrument
     */
    ByInstrument(const Instrument & instrument);

    /**
     * Constructor.
     *
     * Makes a filter to match all the audit messages having
     * instrument identifier as specified in the input parameter.
     *
     * @param instrument_id             Instance of InstrumentIdentifier
     */
    ByInstrument(const InstrumentIdentifier & instrument_id);

    /**
     * Constructor.
     *
     * Makes a filter to match all the audit messages having
     * instrument as one of the instrument specified in the
     * instrument vector parameter.
     *
     * @param vec_instrument_ids        Vector of instrument identifier.
     */
    ByInstrument(const std::vector<InstrumentIdentifier> & vec_instrument_ids);
    ByInstrument(const ByInstrument & filter);

    ByInstrument & operator=(const ByInstrument & filter);

    /**
     * Add instrument identifier to the filter.
     *
     * @param instrument_id             Instance of InstrumentIdentifier
     */
    void AddInstrument(const InstrumentIdentifier & instrument_id);

    /**
     * Remove instrument identifier from the filter.
     *
     * @return                          Instance of InstrumentIdentifier
     */
    void RemoveInstrument(const InstrumentIdentifier & instrument_id);

    /**
     * Add instrument to the filter.
     *
     * @param instrument_id             Instance of Instrument
     */
    void AddInstrument(const Instrument & instrument);

    /**
     * Remove instrument from the filter.
     *
     * @return                          Instance of Instrument
     */
    void RemoveInstrument(const Instrument & instrument);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::set<InstrumentIdentifier> m_set_instrument_ids;
};

/**
 * AuditData::Stream::Filters::ByStrategyIdentifier matches audit messages selected by strategy identifier.
 */
class STRATEGY_EXPORT AuditData::Stream::Filters::ByStrategyIdentifier : public AuditData::Stream::Filters::FilterCondition
{
public:
    /// Default constructor.
    ByStrategyIdentifier();

    /**
     * Constructor.
     *
     * Makes a filter to match all audit messages having
     * strategy as specified in the input parameter.
     *
     * @param strategy               Instance of Strategy
     */
    ByStrategyIdentifier(const Strategy & strategy);

    /**
     * Constructor.
     *
     * Makes a filter to match all the audit messages
     * having strategy identifier as specified in the input parameter.
     *
     * @param strategy_id            Instance of StrategyIdentifier
     */
    ByStrategyIdentifier(const StrategyIdentifier & strategy_id);

    /**
     * Constructor.
     *
     * Makes a filter to match all the audit messages
     * strategy as one of the strategy specified in the strategy vector parameter.
     *
     * @param vec_strategy_ids       Vector of strategy identifier.
     */
    ByStrategyIdentifier(const std::vector<StrategyIdentifier> & vec_strategy_ids);
    ByStrategyIdentifier(const ByStrategyIdentifier & filter);

    ByStrategyIdentifier & operator=(const ByStrategyIdentifier & filter);

    /**
     * Add strategy identifier to the filter.
     *
     * @param strategy_id            Instance of StrategyIdentifier
     */
    void AddStrategy(const StrategyIdentifier & strategy_id);

    /**
     * Remove strategy identifier from the filter.
     *
     * @return                       Instance of StrategyIdentifier
     */
    void RemoveStrategy(const StrategyIdentifier & strategy_id);

    /**
     * Add strategy to the filter.
     *
     * @param strategy               Instance of Strategy
     */
    void AddStrategy(const Strategy & strategy);

    /**
     * Remove strategy from the filter.
     *
     * @return                       Instance of Strategy
     */
    void RemoveStrategy(const Strategy & strategy);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::set<StrategyIdentifier> m_set_strategy_ids;
};
}

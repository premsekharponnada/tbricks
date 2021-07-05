#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ReferencePriceByInstrumentFilter, matches updates of concrete reference price instance
// having specified instrument.
//****************************************************************************************

#include "strategy/stream_filter/ReferencePriceFilter.h"
#include "strategy/Instrument.h"

namespace tbricks {

/**
 * PositionByInstrumentFilter matches concrete position instance updates,
 * selected by instrument identifier.
 */
class STRATEGY_EXPORT ReferencePriceByInstrumentFilter : public ReferencePriceFilterCondition
{
public:
    /// Default constructor.
    ReferencePriceByInstrumentFilter();

    /**
     * Constructor.
     *
     * Makes a filter to match all the reference price instance updates having
     * instrument as specified in the input parameter.
     *
     * @param instrument                 Instance of Instrument.
     */
    ReferencePriceByInstrumentFilter(const Instrument & instrument);

    /**
     * Constructor.
     *
     * Makes a filter to match all the reference price instance updates having
     * instrument identifier as specified in the input parameter.
     *
     * @param instrument_id              Instance of InstrumentIdentifier
     */
    ReferencePriceByInstrumentFilter(const InstrumentIdentifier & instrument_id);

    /**
     * Constructor.
     *
     * Makes a filter to match all the reference price instance updates
     * having instrument as one of the specified input instrument identifier vector.
     *
     * @param vec_instrument_ids         vector of instrument identifier
     */
    ReferencePriceByInstrumentFilter(const std::vector<InstrumentIdentifier> & vec_instrument_ids);
    ReferencePriceByInstrumentFilter(const ReferencePriceByInstrumentFilter & filter);

    ReferencePriceByInstrumentFilter & operator=(const ReferencePriceByInstrumentFilter & filter);

    /**
     * Add instrument identifier to the filter.
     *
     * @param  instrument_id             Instance of InstrumentIdentifier
     */
    void AddInstrument(const InstrumentIdentifier & instrument_id);

    /**
     * Remove instrument identifier from the filter.
     *
     * @param instrument_id              Instance of InstrumentIdentifier
     */
    void RemoveInstrument(const InstrumentIdentifier & instrument_id);

    /**
     * Add instrument to the filter.
     *
     * @param  instrument_id             Instance of Instrument
     */
    void AddInstrument(const Instrument & instrument);

    /**
     * Remove instrument from the filter.
     *
     * @param instrument_id              Instance of Instrument
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
}

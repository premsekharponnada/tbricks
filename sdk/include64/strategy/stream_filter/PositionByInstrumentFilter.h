#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PositionByInstrumentFilter, matches updates of concrete portfolio instance.
//****************************************************************************************

#include "strategy/stream_filter/PositionFilter.h"
#include "strategy/Instrument.h"

namespace tbricks {

/**
 * PositionByInstrumentFilter matches concrete position instance updates,
 * selected by instrument identifier.
 */
class STRATEGY_EXPORT PositionByInstrumentFilter : public PositionFilterCondition
{
public:
    /// Default constructor.
    PositionByInstrumentFilter();

    /**
     * Makes a filter to match all the positions with the specified instrument.
     *
     * @param instrument			instrument instance
     */
    PositionByInstrumentFilter(const Instrument & instrument);

    /**
     * Makes a filter to match all the positions with the specified
     * instrument identifier.
     *
     * @param instrument_id			instrument identifier
     */
    PositionByInstrumentFilter(const InstrumentIdentifier & instrument_id);

    /**
     * Makes a filter to match all the positions with the specified
     * vector of instrument identifiers.
     *
     * @param vec_instrument_ids		vector of instrument identifiers
     */
    PositionByInstrumentFilter(const std::vector<InstrumentIdentifier> & vec_instrument_ids);
    PositionByInstrumentFilter(const PositionByInstrumentFilter & filter);

    PositionByInstrumentFilter & operator=(const PositionByInstrumentFilter & filter);

    /**
     * Add instrument identifier to the filter.
     *
     * @param  instrument_id        	   	Identifier of the instrument to be added
     */
    void AddInstrument(const InstrumentIdentifier & instrument_id);

    /**
     * Remove instrument identifier from the filter.
     *
     * @param instrument_id			Identifier of the instrument to be removed
     */
    void RemoveInstrument(const InstrumentIdentifier & instrument_id);

    /**
     * Add instrument to the filter
     *
     * @param instrument			Instrument to be added
     */
    void AddInstrument(const Instrument & instrument);

    /**
     * Remove instrument from the filter
     *
     * @param instrument			Instrument to be removed
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

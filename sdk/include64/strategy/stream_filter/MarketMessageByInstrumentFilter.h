#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// MarketMessage::Stream::Filters::ByInstrument, matches messages for specified instrument
//****************************************************************************************

#include "strategy/stream_filter/MarketMessageFilter.h"
#include "strategy/Instrument.h"
#include "strategy/stream/MarketMessageStream.h"

namespace tbricks {

/**
 * MarketMessage::Stream::Filters::ByInstrument matches market messages selected by instrument identifier.
 */
class STRATEGY_EXPORT MarketMessage::Stream::Filters::ByInstrument : public MarketMessage::Stream::Filters::FilterCondition
{
public:
    /// Default constructor.
    ByInstrument();

    /**
     * Constructor.
     *
     * Makes a filter to match all the market messages for
     * the instrument specified in the input parameter.
     *
     * @param instrument		Instance of Instrument
     */
    ByInstrument(const Instrument & instrument);

    /**
     * Constructor.
     *
     * Makes a filter to match all the market messages for the
     * instrument identifier specified in the input parameter.
     *
     * @param instrument_id		Instance of InstrumentIdentifier
     */
    ByInstrument(const InstrumentIdentifier & instrument_id);
    ByInstrument(const ByInstrument & filter);

    ByInstrument & operator=(const ByInstrument & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentIdentifier m_identifier;
};
}

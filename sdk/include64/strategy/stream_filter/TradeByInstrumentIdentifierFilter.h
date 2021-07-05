#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeByInstrumentIdentifierFilter, matches trades by instrument identifier.
//****************************************************************************************

#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/Instrument.h"
#include "strategy/InstrumentVenueIdentification.h"

#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

/**
 * TradeByInstrumentIdentifierFilter matches all trades with instrument identifier provided
 * as filter argument.
 */
class STRATEGY_EXPORT TradeByInstrumentIdentifierFilter : public TradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all trades having instrument identifier
     * as specified in the input parameter.
     *
     * @param identifier                            Instance of InstrumentIdentifier on the basis of
                                                    which trades will be filtered.
     */
    TradeByInstrumentIdentifierFilter(const InstrumentIdentifier & identifier);

    /**
     * Constructor.
     *
     * Makes a filter to match all trades executed on the instrument as
     * specified in the input parameter.
     *
     * @param instrument                            Instance of Instrument on the basis of which
                                                    trades will be filtered.
     */
    TradeByInstrumentIdentifierFilter(const Instrument & instrument);

    /**
     * Constructor.
     *
     * Makes a filter to match all trades having instrument venue identifier as
     * specified in the input parameter.
     *
     * @param ivid                                  Instance of InstrumentVenueIdentification to the
                                                    basis of which trades will be filtered.
     */
    TradeByInstrumentIdentifierFilter(const InstrumentVenueIdentification & ivid);
    TradeByInstrumentIdentifierFilter(const TradeByInstrumentIdentifierFilter & filter);

    TradeByInstrumentIdentifierFilter & operator=(const TradeByInstrumentIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentIdentifier m_identifier;
};
}

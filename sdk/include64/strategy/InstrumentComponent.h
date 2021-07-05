#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentComponent type.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/Double.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy_generated/InstrumentComponentBase.h"

namespace tbricks {

/**
 * InstrumentComponent represents an instrument in a composite instrument.
 *
 * @see Instrument
 */
class STRATEGY_EXPORT InstrumentComponent : public InstrumentComponentBase
{
public:
    /**
     * Default constructor.
     *
     * Initializes object to default value -- no fields present, all returned
     * values are empty.
     *
     * This is mostly for use in STL containers.
     */
    InstrumentComponent() = default;

    /**
     * Constructor.
     *
     * Initializes object with specified instrument identifier and
     * instrument component ratio.
     *
     * This is mostly for use in STL containers.
     *
     * @param instrument_id             Instrument identifier
     * @param ratio                     Instrument ratio
     */
    InstrumentComponent(const InstrumentIdentifier & instrument_id, const Double & ratio)
    {
        SetInstrumentIdentifier(instrument_id);
        SetRatio(ratio);
    }

    using InstrumentComponentBase::InstrumentComponentBase;
};
}

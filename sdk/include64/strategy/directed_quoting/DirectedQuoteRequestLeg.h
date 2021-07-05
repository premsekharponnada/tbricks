#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteRequestLeg
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy_generated/DirectedQuoteRequestLegBase.h"

#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/type/VenueInstrumentIdentifier.h"

namespace tbricks {

/**
 * Represents leg-specific information in directed quote request.
 */
class STRATEGY_EXPORT DirectedQuoteRequestLeg : public DirectedQuoteRequestLegBase
{
public:
    DirectedQuoteRequestLeg() = default;
    DirectedQuoteRequestLeg(const DirectedQuoteRequestLeg & leg) = default;
    DirectedQuoteRequestLeg(DirectedQuoteRequestLeg && leg) noexcept = default;

    ~DirectedQuoteRequestLeg() override = default;

    DirectedQuoteRequestLeg & operator=(const DirectedQuoteRequestLeg & leg) = default;
    DirectedQuoteRequestLeg & operator=(DirectedQuoteRequestLeg && leg) noexcept = default;

    DirectedQuoteRequestLeg(const protocol::DirectedQuoteRequestLeg & leg);

    /**
     * %Set instrument venue identification.
     *
     * The field does not make sense for DirectedQuoteRequest::Modifier.
     *
     * @param value                     instrument venue identification
     */
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    /**
     * Get venue instrument identifier.
     *
     * The field does not make sense for DirectedQuoteRequest::Modifier.
     *
     * @return                          venue identifier
     */
    VenueInstrumentIdentifier GetVenueInstrumentIdentifier() const;

    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Capabilities of a directed quote request venue.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/ValidityTypeSet.h"
#include "strategy/OrderCapacitySet.h"
#include "strategy/ExecutionPolicySet.h"
#include "strategy/type/TransitionType.h"
#include "strategy/type/PricePolicy.h"
#include "strategy/type/LiquidityPool.h"

#include "strategy/parameter/ParameterDefinition.h"

namespace tbricks {

namespace venue {
class VenueInfo;
}

/**
 * DirectedQuoteRequestCapabilities allows to discover peculiarities of a directed quote request venue
 */
class STRATEGY_EXPORT DirectedQuoteRequestCapabilities : public Printable
{
public:
    DirectedQuoteRequestCapabilities(const DirectedQuoteRequestCapabilities & tc);
    DirectedQuoteRequestCapabilities(tbricks::venue::VenueInfo * vi);
    ~DirectedQuoteRequestCapabilities() override;

    DirectedQuoteRequestCapabilities & operator=(const DirectedQuoteRequestCapabilities & tc);

    /**
     * Check if venue supports directed quote request modify requests.
     *
     * @return                          "true" if feature si supported,
     *                                  "false" otherwise
     */
    bool CanModify() const;

    /**
     * Check if parameter is supported.
     *
     * If "empty" is "false": returns "true" if a venue allows to create an dqr with the
     * parameter set.
     *
     * If "empty" is "true": returns "true" if a venue allows to create an dqr without the
     * parameter set.
     *
     * @param definition                Parameter definition
     * @param empty                     Parameter is empty
     * @return                          "true" if parameter supported,
     *                                  "false" otherwise
     */
    bool SupportsParameter(const ParameterDefinition & definition, bool empty = false) const;

    /**
     * Check if parameter can be modified.
     *
     * Returns "true" if a venue allows to modify the parameter in an existing
     * dqr.
     *
     * @param definition                Parameter definition
     * @return                          "true" if parameter can be modified,
     *                                  "false" otherwise
     */
    bool CanModifyParameter(const ParameterDefinition & definition) const;

    std::ostream & Print(std::ostream & strm) const override;

private:
    tbricks::venue::VenueInfo * m_venue;
};
}

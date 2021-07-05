#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Capabilities of a trading venue.
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

class ParticipationPolicy;

/**
 * TradingCapabilities allows to discover peculiarities of a trading venue,
 * for instance, what validity types are supported, what order fields could
 * be specified in order modify requests, and so on.
 */
class STRATEGY_EXPORT TradingCapabilities : public Printable
{
public:
    enum ModifyType
    {
        MODIFY_ABSOLUTE,
        MODIFY_RELATIVE
    };

public:
    TradingCapabilities(const TradingCapabilities & tc);
    TradingCapabilities(tbricks::venue::VenueInfo * vi);
    ~TradingCapabilities() override;

    TradingCapabilities & operator=(const TradingCapabilities & tc);

    /**
     * Check if venue supports order modify requests.
     *
     * @return                          "true" if feature si supported,
     *                                  "false" otherwise
     */
    bool CanModify() const;

    /**
     * Check if venue supports block orders.
     *
     * @return                          "true" if feature supported,
     *                                  "false" otherwise
     */
    bool IsBlockOrdersSupported() const;

    /**
     * Get liquidity pools for traiding.
     */
    void GetLiquidityPools(std::vector<LiquidityPool> & liquidity_pools) const;

    /**
     * Check if parameter is supported.
     *
     * If "empty" is "false": returns "true" if a venue allows to create an order with the
     * parameter set.
     *
     * If "empty" is "true": returns "true" if a venue allows to create an order without the
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
     * order.
     *
     * @param definition                Parameter definition
     * @return                          "true" if parameter can be modified,
     *                                  "false" otherwise
     */
    bool CanModifyParameter(const ParameterDefinition & definition, ModifyType type = MODIFY_ABSOLUTE) const;

    /**
     * Check if parameter can be modified.
     *
     * Returns "true" if a venue allows to modify the parameter in an existing
     * order.
     *
     * @param definition                Parameter definition
     * @return                          "true" if parameter can be modified,
     *                                  "false" otherwise
     */
    bool CanModifyParameter(const ParameterDefinition & definition, bool empty) const;

    /**
     * Check if parameter can be increased.
     *
     * Returns "true" if a venue allows to increase the parameter in an existing
     * order.
     *
     * @param definition                Parameter definition
     * @return                          "true" if parameter can be increased,
     *                                  "false" otherwise
     */
    bool CanIncreaseParameter(const ParameterDefinition & definition, ModifyType type = MODIFY_ABSOLUTE);

    /**
     * Check if parameter can be decreased.
     *
     * Returns "true" if a venue allows to decrease the parameter in an existing
     * order.
     *
     * @param definition                Parameter definition
     * @return                          "true" if parameter can be decreased,
     *                                  "false" otherwise
     */
    bool CanDecreaseParameter(const ParameterDefinition & definition, ModifyType type = MODIFY_ABSOLUTE);

    /**
     * Get supported validity types.
     *
     * @return A set of validity types supported by a venue.
     */
    const ValidityTypeSet & GetSupportedValidityTypes() const;

    /**
     * Get supported order capacities.
     *
     * @return A set of order capacities supported by a venue.
     */
    const OrderCapacitySet & GetSupportedOrderCapacities() const;

    /**
     * Get supported execution poliies.
     *
     * @return A set of execution policies supported by a venue.
     */
    const ExecutionPolicySet & GetSupportedExecutionPolicies() const;

    /**
     * Get modifiable validity types.
     *
     * @return a set of validity types supported by a venue in
     * order modify requests.
     */
    const ValidityTypeSet & GetModifiableValidityTypes() const;

    /**
     * Get two sided rfq response quote required flag
     *
     * @return                          true if two sided quote required
     *                                  false in otherwise
     */
    bool TwoSidedRFQResponseRequired() const;

    /**
     * Get supported transition types.
     *
     * Returns a vector of transition types supported by a venue.
     *
     */
    void GetSupportedTransitionTypes(std::vector<TransitionType> & set) const;

    /**
     * Get supported participation policies.
     *
     * Returns a vector of participation policies supported by a venue.
     *
     */
    void GetSupportedParticipationPolicies(std::vector<ParticipationPolicy> & set) const;

    /**
     * Get supported price policies.
     *
     * Returns a vector of price policies supported by a venue.
     *
     */
    void GetSupportedPricePolicies(std::vector<PricePolicy> & set) const;

    std::ostream & Print(std::ostream & strm) const override;

private:
    void decode_validity();
    void decode_capacity();
    void decode_policies();

private:
    ValidityTypeSet m_supported_validity_types;
    ValidityTypeSet m_modifiable_validity_types;
    OrderCapacitySet m_supported_capacities;
    ExecutionPolicySet m_execution_policies;

    tbricks::venue::VenueInfo * m_venue;
};
}

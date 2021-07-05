#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Component
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy_generated/QualityOfServiceBase.h"

namespace tbricks {

/**
 * QualityOfService object informs about runtime state of a service, including information
 * about CPU usage, order processing latency, service healthiness and more.
 *
 * Only identifier field is guaranteed to always be present in the message.
 * Set of fields provided in the message are service specific (for instance,
 * all order related fields will only be defined by those services that work
 * with orders directly, for all other services the fields will not be filled
 * in).
 */
class STRATEGY_EXPORT QualityOfService : public QualityOfServiceBase
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
    QualityOfService() = default;

    /**
     * Merge data from extern source.
     *
     * Object fields are updated from the argument, old values (if any) are
     * replaced.
     *
     * Method only fails when both source and target objects have service
     * identifier set, and identifiers are not equal. If this is the case,
     * the method throws an exception.
     *
     * @param src                      Data source
     * @return                         "true" if merge succeeded, "false"
     *                                 otherwise
     */
    using QualityOfServiceBase::Merge;

    using QualityOfServiceBase::QualityOfServiceBase;
};
}

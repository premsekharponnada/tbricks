#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy scheduling policy, to be specified in strategy instantiation
// call.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"

namespace tbricks {

/**
 * Scheduling policy allows to distribute a child strategy on a given strategy
 * engine instance or execute it in a given subsystem. The default is to run
 * child strategy on the same strategy engine where its parent runs.
 *
 * @see StrategyOptions
 */
class STRATEGY_EXPORT SchedulingPolicy : public Printable
{
public:
    enum Type
    {
        NONE,
        SUBSYSTEM,
        STRATEGY_ENGINE
    };

private:
    SchedulingPolicy(Type type, const Identifier & id);

public:
    /**
     * Copy constructor.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param src                       Object to copy from
     */
    SchedulingPolicy(const SchedulingPolicy & src);

    /**
     * Assignment operator.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param src                       Object to copy from
     * @return                          Updated object
     */
    SchedulingPolicy & operator=(const SchedulingPolicy & src);
    ~SchedulingPolicy();

    /**
     * Comparison operator.
     *
     * Returns "true" if both type and the identifier of the parameter
     * are the same as in the current object.
     *
     * @param src                       Object to compare with
     * @return                          "true" if objects are equal,
     *                                  "false" otherwise
     */
    bool operator==(const SchedulingPolicy & src) const;
    bool operator!=(const SchedulingPolicy & src) const;

    /**
     * Get scheduling type.
     *
     * @return                          Scheduling type
     */
    Type GetType() const;

    /**
     * Get scheduling entity identifier.
     *
     * For scheduling of STRATEGY_ENGINE type returns service identifier
     * of the target engine instance; for SUBSYSTEM, it is a subsystem
     * identifier.
     *
     * @return                          Scheduling entity identifier
     */
    const Identifier & GetIdentifier() const;

    /**
     * Schedule strategy on a local engine.
     */
    static SchedulingPolicy LocalEngine();

    /**
     * Schedule strategy on a specific engine.
     *
     * @param id                        Strategy engine identifier
     */
    static SchedulingPolicy SpecificEngine(const Identifier & id);

    /**
     * Schedule strategy in a local subsystem.
     */
    static SchedulingPolicy LocalSubsystem();

    /**
     * Schedule strategy in a specific subsystem.
     *
     * @param id                        Strategy engine identifier
     */
    static SchedulingPolicy SpecificSubsystem(const Identifier & id);

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Type m_type;
    Identifier m_identifier;
};
}

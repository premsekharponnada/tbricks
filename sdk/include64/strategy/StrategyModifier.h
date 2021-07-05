#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy modifiable attributes and parameters container, for use in
// strategy modify request and in the appropriate strategy callback.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/StrategyAttributes.h"
#include "strategy/parameter/StrategyParameters.h"
#include "strategy/AuditPolicy.h"

namespace tbricks {

/**
 * StrategyModifier carries modified attribute and parameter values from
 * a request originator to a target strategy.
 */
class STRATEGY_EXPORT StrategyModifier : public Printable
{
public:
    StrategyModifier();
    StrategyModifier(const StrategyModifier & parameters);
    StrategyModifier(StrategyModifier && parameters);
    StrategyModifier(const StrategyAttributes & attributes);
    StrategyModifier(const StrategyParameters & parameters);
    ~StrategyModifier();

    StrategyModifier & operator=(const StrategyModifier & modifier);
    StrategyModifier & operator=(StrategyModifier && modifier);

    StrategyModifier(const protocol::StrategyModifyRequest & value);
    StrategyModifier(const protocol::StrategyAddRequest & value);

public:
    /**
     * Get strategy attributes.
     *
     * Method will return an empty object if attributes had never been
     * modified.
     *
     * @return                          Strategy attributes container
     */
    const StrategyAttributes & GetAttributes() const;

    /**
     * Get strategy attributes.
     *
     * Method will return an empty object if attributes had never been
     * modified.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return                          Strategy attributes container
     */
    [[deprecated(DEPRECATE_LINK)]] StrategyAttributes & GetAttributes();

    /**
     * %Set strategy attributes.
     *
     * @param attributes                Strategy attributes
     */
    void SetAttributes(const StrategyAttributes & attributes);

    /**
     * Get strategy parameters.
     *
     * Method will return an empty object if parameters had never been
     * modified.
     *
     * @return                          Strategy parameters container
     */
    const StrategyParameters & GetParameters() const;

    /**
     * Get strategy parameters.
     *
     * Method will return an empty object if parameters had never been
     * modified.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return                          Strategy parameters container
     */
    [[deprecated(DEPRECATE_LINK)]] StrategyParameters & GetParameters();

    /**
     * %Set strategy parameters.
     *
     * @param parameters                Strategy parameters
     */
    void SetParameters(const StrategyParameters & parameters);

    /**
     * %Set strategy state.
     *
     * @ param                          Strategy state
     */
    void SetState(const StrategyState & state);

    /**
     * Get strategy state.
     *
     * Method will return an empty object if state had never been
     * modified.
     *
     * @return                          Strategy state
     */
    const StrategyState & GetState() const;

    /**
     * Get strategy state.
     *
     * Method will return an empty object if state had never been
     * modified.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return                          Strategy state
     */
    [[deprecated(DEPRECATE_LINK)]] StrategyState & GetState();

    /**
     * %Set audit policy.
     *
     * Method allows to set audit policy for a strategy
     *
     * @see AuditPolicy
     *
     * @param sp                        Persistence policy
     */
    void SetAuditPolicy(const AuditPolicy & sp);

    /**
     * Get audit policy.
     *
     * @return                          Persistence policy
     */
    const AuditPolicy & GetAuditPolicy() const;

    /**
     * Merge strategy modifiers
     */
    void Merge(const StrategyModifier & modifier);

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no records in the
     *                                  container, false otherwise.
     */
    bool Empty() const;

    /**
     * Clear container data.
     *
     * After this call container is guaranteed to contain no data, and Empty()
     * method will return True if called.
     */
    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

    void SetAlgoLabelParameters(const StrategyParameters & /* parameters */) {}

private:
    StrategyAttributes m_attributes;
    StrategyParameters m_parameters;
    AuditPolicy m_audit_policy;
    StrategyState m_state;
};
}

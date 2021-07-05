#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy instantiation options, for use in Strategy::SendCreateRequest()
// API call.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/SchedulingPolicy.h"
#include "strategy/AuditPolicy.h"
#include "strategy/StrategyAttributes.h"

#include "strategy/type/Integer.h"

namespace tbricks {

/**
 * StrategyOptions class defines a set of options a child strategy can be
 * created with.
 *
 *  @see Strategy::SendCreateRequest()
 */
class STRATEGY_EXPORT StrategyOptions : public Printable
{
public:
    /**
     * Constructor.
     *
     * Allows to create a strategy of the specified type.
     * By default, strategy state will be Paused.
     *
     * @param type                      Instance of StrategyIdentifier.
     *                                  Child strategy type identifier
     */
    StrategyOptions(const StrategyIdentifier & type);

    /**
     * Constructor.
     *
     * Allows to create a strategy of the specified type.
     * By default, strategy state will be Running, priority is 0.
     *
     * @param type                      Instance of Identifier.
     *                                  Child strategy type identifier
     */
    StrategyOptions(const Identifier & type);

    /**
     * Constructor.
     *
     * Allows to create a strategy of the specified type.
     * By default, strategy state will be Running, priority is 0.
     *
     * @param type                      Instance of Uuid.
     *                                  Child strategy type identifier
     */
    StrategyOptions(const Uuid & type);
    ~StrategyOptions();

public:
    /**
     * Create child strategy in paused state.
     */
    void SetStatePaused();

    /**
     * Create child strategy in running state (is the default).
     */
    void SetStateRunning();

    /**
     * Get current state value.
     *
     * @return                          Strategy state
     */
    StrategyState GetState() const;

    /**
     * Get strategy type identifier.
     *
     * @return                          Strategy type identifier
     */
    const StrategyIdentifier & GetType() const;

    /**
     * %Set visible strategy attribute.
     *
     * Visible attribute controls whether strategy will visible as a child strategy in a front-end.
     * By default, strategies are created as visible.
     *
     * @param is_visible                Visible flag value
     */
    void SetVisible(bool is_visible);

    /**
     * Get visible strategy attribute.
     *
     * @return                          Visible flag value
     */
    bool GetVisible() const;

    /**
     * %Set strategy relationship attribute.
     *
     * Making strategy a top level one means to break relationship between the
     * child and its parent, a new strategy will have no information of what
     * the parent was and will not appear in the inheritance tree of the parent.
     *
     * @param is_top_level              New flag value
     */
    void SetTopLevel(bool is_top_level);

    /**
     * Get strategy relationship attribute.
     *
     * @return                          Relationship flag value
     */
    bool GetTopLevel() const;

    /**
     * %Set scheduling policy.
     *
     * Method allows to distribute a child strategy onto a different
     * strategy engine instance or to run it in a given subsystem.
     * By default, the child is instantiated on the same strategy engine.
     *
     * @see SchedulingPolicy
     *
     * @param sp                        Scheduling policy
     */
    void SetSchedulingPolicy(const SchedulingPolicy & sp);

    /**
     * Get scheduling policy.
     *
     * If SetSchedulingPolicy() had never been called, default policy
     * value is returned.
     *
     * @return                          Scheduling policy
     */
    const SchedulingPolicy & GetSchedulingPolicy() const;

    /**
     * %Set audit policy.
     *
     * Method allows to set audit persistence policy for a strategy
     *
     * @see AuditPolicy
     *
     * @param sp                        Persistence policy
     */
    void SetAuditPolicy(const AuditPolicy & sp);

    /**
     * Get audit persistence policy.
     *
     * @return                          Audit persistence policy
     */
    const AuditPolicy & GetAuditPolicy() const;

    /**
     * %Set strategy attributes.
     *
     * Method allows to override default strategy attribute settings.
     *
     * @param attributes                Strategy attributes container
     */
    void SetAttributes(const StrategyAttributes & attributes);

    /**
     * Get strategy attributes for writing.
     *
     * Method provides read-write access to strategy attributes and
     * makes it possible to modify only certain attributes instead
     * of overriding all of them as SetAttributes() does.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return                          Strategy attributes container
     */
    [[deprecated(DEPRECATE_LINK)]] StrategyAttributes & GetAttributes();

    /**
     * Get strategy attributes for reading.
     *
     * Method provides read-only access to strategy attributes.
     *
     * @return                          Strategy attributes container
     */
    const StrategyAttributes & GetAttributes() const;

    /**
     * %Set strategy comment.
     *
     * Method allows to set strategy comment.
     *
     * @param comment                   Strategy comment
     */
    void SetComment(const String & comment);

    /**
     * Get strategy comment.
     *
     * Method provides read-write access to strategy comment.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return                          Strategy comment
     */
    [[deprecated(DEPRECATE_LINK)]] String & GetComment();

    /**
     * Get strategy comment.
     *
     * Method provides read-only access to strategy comment.
     *
     * @return                          Strategy comment
     */
    const String & GetComment() const;

    /**
     * Get creator identifier.
     *
     * Can be used for matching apps only.
     *
     * @return                          Creator identifier
     */
    const UserIdentifier & GetCreator() const;

    /**
     * %Set creator identifier.
     *
     * Can be used for matching apps only.
     * Throw exception if app isn't matching.
     *
     * @param                           Creator identifier
     */
    void SetCreator(const UserIdentifier & identifier);

    /**
     * %Set warmup option.
     *
     * Method allows to set warmup option to create child app in warmup mode
     *
     * @param warmup                    Warmup option
     */
    void SetWarmup(bool warmup);

    /**
     * Get warmup option.
     *
     * Method provides read-only access to warmup option.
     *
     * @return                          Warmup option
     */
    bool GetWarmup() const;

    virtual std::ostream & Print(std::ostream & strm) const;

    /**
     * %Set the algo label parameters of the strategy.
     *
     * @param parameters				Set the Algo parameters in
     *                                  StrategyParameters.
     */
    void SetAlgoLabelParameters(const StrategyParameters & /* parameters */) {}

private:
    StrategyState m_state;
    StrategyIdentifier m_type;

    bool m_visible;
    bool m_top_level;
    bool m_warmup;

    SchedulingPolicy m_scpolicy;
    AuditPolicy m_audit_policy;
    StrategyAttributes m_attributes;
    String m_comment;

    UserIdentifier m_creator;
};
}

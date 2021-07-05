#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// UserBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/UserUpdateBase.h"


#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class DateTime;
class RoleIdentifier;
class String;
class UserAuthenticationType;
class UserIdentifier;
class UserParameters;


namespace protocol { class User; }

class STRATEGY_EXPORT UserBase : public Printable
{
protected:
    UserBase();
    UserBase(const UserBase & value);
    UserBase(UserBase && value) noexcept;
    UserBase & operator=(const UserBase & value);
    UserBase & operator=(UserBase && value) noexcept;
    virtual ~UserBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get user identifier.
     *
     *
     * @return                          user identifier
     */
    UserIdentifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasShortName() const;

    /**
     * Get user name.
     *
     *
     * @return                          user name
     */
    String GetShortName() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasName() const;

    /**
     * Get user long name.
     *
     *
     * @return                          user long name
     */
    String GetName() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeleted() const;

    /**
     * Get deleted.
     *
     *
     * @return                          deleted
     */
    Boolean GetDeleted() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParameters() const;

    /**
     * Get user parameters.
     *
     *
     * @return                          user parameters
     */
    UserParameters GetParameters() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostCreatedDatetime() const;

    /**
     * Get host created datetime.
     *
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDatetime() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostModifiedDatetime() const;

    /**
     * Get host modified datetime.
     *
     *
     * @return                          host modified datetime
     */
    DateTime GetHostModifiedDatetime() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRoleIdentifiers() const;

    /**
     * Get role identifiers.
     *
     *
     * @return                          role identifiers
     */
    std::vector<RoleIdentifier> GetRoleIdentifiers() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAllowMultipleLogins() const;

    /**
     * Get allow multiple logins.
     *
     *
     * @return                          allow multiple logins
     */
    Boolean GetAllowMultipleLogins() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAllowSingleSignOn() const;

    /**
     * Get allow single sign on.
     *
     *
     * @return                          allow single sign on
     */
    Boolean GetAllowSingleSignOn() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasWindowsDomain() const;

    /**
     * Get windows domain.
     *
     *
     * @return                          windows domain
     */
    String GetWindowsDomain() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasWindowsDomainUserName() const;

    /**
     * Get windows domain user name.
     *
     *
     * @return                          windows domain user name
     */
    String GetWindowsDomainUserName() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUserAuthenticationType() const;

    /**
     * Get user authentication type.
     *
     *
     * @return                          user authentication type
     */
    UserAuthenticationType GetUserAuthenticationType() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasEnforcePasswordChange() const;

    /**
     * Get enforce password change.
     *
     *
     * @return                          enforce password change
     */
    Boolean GetEnforcePasswordChange() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const UserUpdateBase & update);

/** @cond PRIVATE */
public:
    UserBase(const protocol::User & value);
    UserBase(std::shared_ptr<protocol::User> && value);

    std::shared_ptr<protocol::User> & get_impl_wr() const;
    const std::shared_ptr<protocol::User> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::User> m_impl;
};

}

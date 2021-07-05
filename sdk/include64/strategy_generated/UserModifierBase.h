#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// UserModifierBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class RoleIdentifier;
class String;
class UserAuthenticationType;
class UserParameters;


namespace protocol { class UserRequest; }

class STRATEGY_EXPORT UserModifierBase : public Printable
{
protected:
    UserModifierBase();
    UserModifierBase(const UserModifierBase & value);
    UserModifierBase(UserModifierBase && value) noexcept;
    UserModifierBase & operator=(const UserModifierBase & value);
    UserModifierBase & operator=(UserModifierBase && value) noexcept;
    virtual ~UserModifierBase();

public:
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
     * %Set user name.
     *
     *    
     *  
     * @param value                     user name
     */
    void SetShortName(const String & value);

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
     * %Set user long name.
     *
     *    
     *  
     * @param value                     user long name
     */
    void SetName(const String & value);

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
     * %Set deleted.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     deleted
     */
    void SetDeleted(const Boolean & value);

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
     * %Set user parameters.
     *
     *    
     *  
     * @param value                     user parameters
     */
    void SetParameters(const UserParameters & value);

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
     * %Set role identifiers.
     * The field will be set into object even if the field is empty.
     *
     *
     * @param value                     role identifiers
     */
    void SetRoleIdentifiers(const std::vector<RoleIdentifier> & value);

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
     * %Set allow multiple logins.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     allow multiple logins
     */
    void SetAllowMultipleLogins(const Boolean & value);

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
     * %Set allow single sign on.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     allow single sign on
     */
    void SetAllowSingleSignOn(const Boolean & value);

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
     * %Set windows domain.
     *
     *    
     *  
     * @param value                     windows domain
     */
    void SetWindowsDomain(const String & value);

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
     * %Set windows domain user name.
     *
     *    
     *  
     * @param value                     windows domain user name
     */
    void SetWindowsDomainUserName(const String & value);

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
     * %Set user authentication type.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     user authentication type
     */
    void SetUserAuthenticationType(const UserAuthenticationType & value);

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

    /**
     * %Set enforce password change.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     enforce password change
     */
    void SetEnforcePasswordChange(const Boolean & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    UserModifierBase(const protocol::UserRequest & value);
    UserModifierBase(std::unique_ptr<protocol::UserRequest> && value);

    std::unique_ptr<protocol::UserRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::UserRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::UserRequest> m_impl;
};

}

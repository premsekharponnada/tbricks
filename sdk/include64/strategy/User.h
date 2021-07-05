#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// User
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/UserParameterDefinition.h"
#include "strategy/UserParameters.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/RoleIdentifier.h"
#include "strategy/type/String.h"
#include "strategy/type/UserAuthenticationType.h"
#include "strategy/type/UserIdentifier.h"
#include "strategy_generated/UserBase.h"
#include "strategy_generated/UserModifierBase.h"
#include "strategy_generated/UserOptionsBase.h"
#include "strategy_generated/UserUpdateBase.h"

#include <vector>

namespace tbricks {

class IRequestReplyHandler;

/**
 * User class describes a user registered in the system.
 */
class STRATEGY_EXPORT User : public UserBase
{
public:
    class Preferences;
    class Status;
    class Stream;
    class Update;
    class Options;
    class Modifier;
    class RequestResult;

public:
    /**
     * Constructor.
     *
     * Constructs empty User object.
     */
    User() = default;

    User(const User::Update & update);

    /**
     * Constructor.
     *
     * Creates new User instance with specified user
     * identifier and immediately tries to resolve it.
     *
     * @see Resolve
     *
     * @throws                          NullReferenceException if user does not exist
     *
     * @param id                        User identifier
     */
    User(const UserIdentifier & id);

    /**
     * Constructor.
     *
     * Creates new User instance with specified user
     * identifier and immediately tries to resolve it.
     *
     * @see Resolve
     *
     * @throws                          NullReferenceException if user does not exist
     *
     * @param short_name                User short name
     */
    User(const String & short_name);

public:
    /**
     * Resolve user.
     *
     * Synchronously fetches full description of the user
     * identified by the parameter.
     *
     * @param id                        User identifier
     *
     * @return                          'true' if instrument is available,
     *                                  'false' otherwise
     */
    bool Resolve(const UserIdentifier & id);

    /**
     * Resolve user.
     *
     * Synchronously fetches full description of the user
     * identified by the parameter.
     *
     * @param short_name                User short name
     *
     * @return                          'true' if instrument is available,
     *                                  'false' otherwise
     */
    bool Resolve(const String & short_name);

public:
    /**
     * Get role identifiers.
     *
     * @return                          A set of role identifiers, associated with the user.
     */
    void GetRoleIdentifiers(std::vector<RoleIdentifier> & role_identifiers) const;

    /**
     * Get deleted.
     *
     * @return                          'true' if user was marked as deleted
     */
    bool Deleted() const;

public:
    /**
     * Get all user
     *
     * Synchronously fetches all users registered in the system.
     *
     * @param[out] allUsers              vector of users
     */
    static void GetAllUsers(std::vector<User> & allUsers);

    /**
     * Send user password change request.
     *
     * Method sends a request to change user password.
     *
     * Password change request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param id                        User identifier
     * @param password                  New password
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          User::RequestResult object
     */
    static RequestResult SendPasswordChangeRequest(const UserIdentifier & user_identifier, const String & password, IRequestReplyHandler & handler);

    static RequestResult SendRequest(const Modifier & modifier, IRequestReplyHandler & handler);

    /**
     * Send user create request.
     *
     * Method sends a request to create user.
     *
     * User create request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param options                   Creation options
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          User::RequestResult object
     */
    static RequestResult SendCreateRequest(const Options & options, IRequestReplyHandler & handler);

    /**
     * Send user modify request.
     *
     * Method sends a request to modify user.
     *
     * User modify  request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param options                   Modify options
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          User::RequestResult object
     */
    static RequestResult SendModifyRequest(const Modifier & modifier, IRequestReplyHandler & handler);

    /**
     * Send user delete request.
     *
     * Method sends a request to delete user.
     *
     * User delete  request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param id                        User identifier
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          User::RequestResult object
     */
    static RequestResult SendDeleteRequest(const UserIdentifier & id, IRequestReplyHandler & handler);

public:
    void Merge(const Update & update);

    size_t GetHash() const;

public:
    User(std::shared_ptr<protocol::User> value);
};

class STRATEGY_EXPORT User::Update : public UserUpdateBase
{
public:
    Update() = default;
    Update(const Update & update);
    Update(Update && update) = default;
    Update & operator=(const Update & update);
    Update & operator=(Update && update) = default;
    ~Update() override = default;

public:
    Boolean Deleted() const { return GetDeleted(); }

    std::vector<RoleIdentifier> * GetRoleIdentifiers() const;

public:
    Update(std::shared_ptr<protocol::User> update);

private:
    mutable std::unique_ptr<std::vector<RoleIdentifier>> m_role_identifiers;
};

class STRATEGY_EXPORT User::Options : public UserOptionsBase
{
private:
    friend User;
};

class STRATEGY_EXPORT User::Modifier : public UserModifierBase
{
public:
    Modifier(const UserIdentifier & identifier);

public:
    void SetParameter(const UserParameterDefinition & def, const AnyType & value);
    bool GetParameter(const UserParameterDefinition & def, AnyType & value) const;
    bool GetParameter(const Uuid & identifier, AnyType & value) const;

public:
    /// @deprecated Deprecated in 2.13.0, will be removed in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void UnsetShortName();
    /// @deprecated Deprecated in 2.13.0, will be removed in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void UnsetName();
    /// @deprecated Deprecated in 2.13.0, will be removed in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void UnsetDeleted();
    /// @deprecated Deprecated in 2.13.0, will be removed in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void UnsetParameters();
    /// @deprecated Deprecated in 2.13.0, will be removed in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void UnsetRoleIdentifiers();
    /// @deprecated Deprecated in 2.13.0, will be removed in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void UnsetAllowMultipleLogins();
    /// @deprecated Deprecated in 2.13.0, will be removed in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void UnsetAllowSingleSignOn();
    /// @deprecated Deprecated in 2.13.0, will be removed in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void UnsetWindowsDomain();
    /// @deprecated Deprecated in 2.13.0, will be removed in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void UnsetWindowsDomainUserName();
    /// @deprecated Deprecated in 2.13.0, will be removed in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void UnsetUserAuthenticationType();
    /// @deprecated Deprecated in 2.13.0, will be removed in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void UnsetEnforcePasswordChange();

private:
    friend User;
    UserIdentifier m_user_identifier;
};

class STRATEGY_EXPORT User::RequestResult : public Printable
{
public:
    RequestResult() = default;
    RequestResult(const Identifier & request_id, const UserIdentifier & user_id);

    const Identifier & GetRequestIdentifier() const { return m_request_identifier; }
    const UserIdentifier & GetUserIdentifier() const { return m_user_identifier; }

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Identifier m_request_identifier;
    UserIdentifier m_user_identifier;
};

inline size_t hash_value(const User & value)
{
    return value.GetHash();
}
}

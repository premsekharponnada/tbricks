#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// UserStatusBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Duration;
class Identifier;
class String;
class UserIdentifier;
enum class UserSessionStatus;


namespace protocol { class UserStatus; }

class STRATEGY_EXPORT UserStatusBase : public Printable
{
protected:
    UserStatusBase();
    UserStatusBase(const UserStatusBase & value);
    UserStatusBase(UserStatusBase && value) noexcept;
    UserStatusBase & operator=(const UserStatusBase & value);
    UserStatusBase & operator=(UserStatusBase && value) noexcept;
    virtual ~UserStatusBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUserIdentifier() const;

    /**
     * Get user identifier.
     *
     *
     * @return                          user identifier
     */
    UserIdentifier GetUserIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSessionIdentifier() const;

    /**
     * Get session identifier.
     *
     *
     * @return                          session identifier
     */
    Identifier GetSessionIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSessionIdentifierName() const;

    /**
     * Get session identifier display name.
     *
     *
     * @return                          session identifier display name
     */
    String GetSessionIdentifierName() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostName() const;

    /**
     * Get host name.
     *
     *
     * @return                          host name
     */
    String GetHostName() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIPAddress() const;

    /**
     * Get ip address.
     *
     *
     * @return                          ip address
     */
    String GetIPAddress() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTimeSinceLastActivity() const;

    /**
     * Get time since last activity.
     *
     *
     * @return                          time since last activity
     */
    Duration GetTimeSinceLastActivity() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSessionStatus() const;

    /**
     * Get user session status.
     *
     *
     * @return                          user session status
     */
    std::optional<UserSessionStatus> GetSessionStatus() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const UserStatusBase & update);

/** @cond PRIVATE */
public:
    UserStatusBase(const protocol::UserStatus & value);
    UserStatusBase(std::shared_ptr<protocol::UserStatus> && value);

    std::shared_ptr<protocol::UserStatus> & get_impl_wr() const;
    const std::shared_ptr<protocol::UserStatus> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::UserStatus> m_impl;
};

}

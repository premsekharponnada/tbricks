#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// User Row Entity public interface.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class User;

namespace visualization {

/**
 * RowEntity implementation containing User object.
 *
 */
class STRATEGY_EXPORT UserRowEntity final : public RowEntity
{
public:
    UserRowEntity();
    ~UserRowEntity() = default;

    UserRowEntity(const UserRowEntity & other) = default;
    UserRowEntity(UserRowEntity && other) noexcept = default;
    UserRowEntity & operator=(const UserRowEntity & other) = default;
    UserRowEntity & operator=(UserRowEntity && other) noexcept = default;

    /**
     * Get user object stored in row entity.
     *
     * @return user
     */
    const User & GetUser() const;

    /**
     * Set user object and update view models containing row entity.
     *
     * @param user        user
     */
    void SetUser(const User & user);
};

} // namespace visualization
} // namespace tbricks

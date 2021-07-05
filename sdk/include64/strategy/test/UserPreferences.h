#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// UserPreferences wrapper.
// Only for test usage.
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/Strategy.h"

namespace tbricks {

namespace protocol {
class UserPreferences;
}

namespace test {
class STRATEGY_EXPORT UserPreferences : public Printable
{
public:
    UserPreferences();
    UserPreferences(const UserPreferences & user_preferences);
    ~UserPreferences();

    UserPreferences & operator=(const UserPreferences & user_preferences);

public:
    void SetUser(const UserIdentifier & user);

    bool HasParameter(const Identifier & definition) const;
    bool GetParameter(const Identifier & definition, AnyType & value) const;
    void SetParameter(const Identifier & definition, const AnyType & value);

    void Clear();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    static void UpdateUserPreferences(const UserPreferences & user_preferences);

private:
    protocol::UserPreferences * m_impl;
};

} // \namespace test

} // \namespace tbricks

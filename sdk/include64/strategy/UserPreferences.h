#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// User preferences.
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/Linkage.h"

#include "strategy/User.h"

#include "strategy/Types.h"

#include <memory>

namespace tbricks {

class ParametersImpl;

/**
 * User::Preferences class, collection of user preferences.
 */
class STRATEGY_EXPORT User::Preferences : public Printable
{
public:
    class Stream;
    class Update;

public:
    Preferences();
    Preferences(const Preferences & preferences);
    Preferences & operator=(const Preferences & preferences);
    virtual ~Preferences();

public:
    const UserIdentifier & GetUserIdentifier() const;
    User GetUser() const;

    bool GetParameter(const Identifier & definition, AnyType & value) const;
    bool HasParameter(const Identifier & definition) const;

    bool Merge(const Update & update);

public:
    void Clear();
    bool Empty() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

public:
    class STRATEGY_EXPORT const_iterator : public Printable
    {
    public:
        const_iterator();
        const_iterator(const const_iterator & it);
        ~const_iterator();
        const_iterator & operator=(const const_iterator & it);

        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        const_iterator & operator*();

        void Clear();
        bool Empty() const;

    public:
        Uuid GetIdentifier() const;
        Identifier GetDefinition() const;

        bool Get(AnyType & value) const;
        bool Get(Variant & value) const;

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class User::Preferences;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

private:
    UserIdentifier m_user_identifier;
    std::unique_ptr<types::Parameters> m_impl;
};

namespace protocol {
class UserPreferences;
}

/**
 * User::Preferences::Update class, collection of updated user preferences.
 */
class STRATEGY_EXPORT User::Preferences::Update : public Printable
{
public:
    Update();
    Update(const Update & update);
    Update & operator=(const Update & update);
    virtual ~Update();

public:
    const UserIdentifier & GetUserIdentifier() const;
    User GetUser() const;

    bool GetParameter(const Identifier & definition, AnyType & value) const;
    bool IsUpdated(const Identifier & definition) const;

    std::ostream & Print(std::ostream & strm) const override;

public:
    class STRATEGY_EXPORT const_iterator : public Printable
    {
    public:
        const_iterator();
        const_iterator(const const_iterator & it);
        ~const_iterator();
        const_iterator & operator=(const const_iterator & it);

        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        const_iterator & operator*();

        void Clear();
        bool Empty() const;

    public:
        Uuid GetIdentifier() const;
        Identifier GetDefinition() const;

        bool Get(AnyType & value) const;
        bool Get(Variant & value) const;

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class User::Preferences::Update;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

public:
    Update(std::shared_ptr<protocol::UserPreferences> && msg);
    const protocol::UserPreferences * GetImpl() const;

private:
    UserIdentifier m_user_identifier;
    std::shared_ptr<protocol::UserPreferences> m_msg;
};
}

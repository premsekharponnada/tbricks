#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Role
//****************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Boolean.h"
#include "strategy/type/RoleIdentifier.h"

#include <vector>

namespace tbricks {

namespace protocol {
class TreeNode;
}
class TreeNode;

class STRATEGY_EXPORT Role : public Printable
{
public:
    class Preferences;
    class Stream;
    class Update;

public:
    Role();
    Role(const Role & role);
    Role(const Role::Update & update);
    Role(const RoleIdentifier & id);
    Role(const String & name);

    Role & operator=(const Role & user);

    virtual ~Role();

    bool Resolve(const RoleIdentifier & id);
    bool Resolve(const String & name);

    RoleIdentifier GetIdentifier() const;
    RoleIdentifier GetParentIdentifier() const;
    Role GetParent() const;
    String GetName() const;
    String GetDescription() const;
    Boolean Deleted() const;
    DateTime GetHostModifiedDatetime() const;

    static void GetAllRoles(std::vector<Role> & allRoles);

    void Merge(const Update & update);

private:
    void init(const protocol::TreeNode & msg);

public:
    bool Empty() const;
    void Clear();

    size_t GetHash() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

    RoleIdentifier m_identifier;
    RoleIdentifier m_parent_identifier;
    String m_name;
    String m_description;
    Boolean m_deleted;
    DateTime m_modified;
};

inline size_t hash_value(const Role & value)
{
    return value.GetHash();
}

class STRATEGY_EXPORT Role::Update : public Printable
{
public:
    Update();
    Update(const Update & update);
    Update & operator=(const Update & user);
    virtual ~Update();

    RoleIdentifier GetIdentifier() const;
    RoleIdentifier GetParentIdentifier() const;
    String GetName() const;
    String GetDescription() const;
    Boolean Deleted() const;
    DateTime GetHostModifiedDatetime() const;

    bool Empty() const;

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    Update(const TreeNode & msg);

private:
    RoleIdentifier m_identifier;
    RoleIdentifier m_parent_identifier;
    String m_name;
    String m_description;
    Boolean m_deleted;
    DateTime m_modified;
};
}

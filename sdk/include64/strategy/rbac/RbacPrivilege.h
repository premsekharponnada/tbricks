#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RbacPrivilege
//****************************************************************************************

#include "strategy/type/Identifier.h"
#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/VenueAndMIC.h"
#include "strategy/rbac/RbacOperation.h"
#include "strategy/type/RoleIdentifier.h"

namespace tbricks {

namespace protocol {
class Privilege;
}

class STRATEGY_EXPORT RbacPrivilege : public Printable
{
public:
    class Stream;

public:
    RbacPrivilege();
    RbacPrivilege(const RbacPrivilege & privilege);
    virtual ~RbacPrivilege();

    RbacPrivilege & operator=(const RbacPrivilege & privilege);

    bool Empty() const;

    Identifier GetIdentifier() const;

    RbacOperation GetOperation() const;
    RoleIdentifier GetRoleIdentifier() const;

    bool Deleted() const;
    DateTime GetHostModifiedDatetime() const;

    size_t GetHash() const;

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    bool CanModifyParameter(const DefinitionBase & definition) const;

    void GetVenuesAndMICs(std::vector<VenueAndMIC> & vvmics) const;

public:
    RbacPrivilege(std::shared_ptr<protocol::Privilege> && msg);

private:
    std::shared_ptr<protocol::Privilege> m_msg;
};

inline size_t hash_value(const RbacPrivilege & value)
{
    return value.GetHash();
}
}

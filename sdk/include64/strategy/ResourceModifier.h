#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Resource::Modifier class.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Resource.h"

#include "strategy_generated/ResourceModifierBase.h"

namespace tbricks {

namespace protocol {
class ResourceUpdateRequest;
}

class STRATEGY_EXPORT Resource::Modifier : public ResourceModifierBase
{
public:
    Modifier(String short_name);
    Modifier(const Modifier & value);
    Modifier(Modifier && value) noexcept;
    Modifier & operator=(const Modifier & value);
    Modifier & operator=(Modifier && value) noexcept;
    virtual ~Modifier();

public:
    /**
     * Get resource short name.
     *
     * Returns name used to identify the resource.
     *
     *
     * @return                          resource short name
     */
    String GetShortName() const;

public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

public:
    std::unique_ptr<protocol::ResourceUpdateRequest> & get_impl() const;

private:
    std::unique_ptr<protocol::ResourceUpdateRequest> m_impl;
};
}

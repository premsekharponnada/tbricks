#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Resource::Options class.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/Resource.h"

#include "strategy_generated/ResourceOptionsBase.h"

namespace tbricks {

namespace protocol {
class ResourceCreateRequest;
}

class STRATEGY_EXPORT Resource::Options : public ResourceOptionsBase
{
public:
    Options() = default;
    Options(const Options & value);
    Options(Options && value) noexcept;
    Options & operator=(const Options & value);
    Options & operator=(Options && value) noexcept;
    virtual ~Options();

    /** @cond PRIVATE */
public:
    Options(const protocol::ResourceCreateRequest & value);
    Options(std::unique_ptr<protocol::ResourceCreateRequest> && value);
    /** @endcond */
};
}

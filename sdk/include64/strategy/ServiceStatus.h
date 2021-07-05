#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Service status updates, to inform subscribers about changes in a service
// state.
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/Linkage.h"

#include "strategy/Types.h"
#include "strategy/Service.h"

namespace tbricks {

namespace protocol {
class Service;
}

/// @deprecated Deprecated in 2.14.3 use tbricks::Service
using ServiceStatus[[deprecated(DEPRECATE_LINK)]] = Service;
}

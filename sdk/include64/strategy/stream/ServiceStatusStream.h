#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ServiceStatus stream.
//****************************************************************************************

#include "strategy/ServiceStatus.h"
#include "strategy/stream/ServiceStream.h"
#include "strategy/stream_filter/ServiceStatusFilter.h"

// namespace tbricks
namespace tbricks {

/// @deprecated Deprecated in 2.14.3 use Service::Stream
using ServiceStatusStream[[deprecated(DEPRECATE_LINK)]] = Service::Stream;
}

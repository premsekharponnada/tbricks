#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QoSByIdentifierFilter, filters updates for a particular service.
//****************************************************************************************

#include "strategy/QoS.h"
#include "strategy/stream_filter/QualityOfServiceFilter.h"

namespace tbricks {

/// @deprecated Deprecated in 2.14.5 use QualityOfServiceByIdentifierFilter
using QoSByIdentifierFilter[[deprecated(DEPRECATE_LINK)]] = QualityOfServiceByIdentifierFilter;
}

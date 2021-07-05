#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in service status streams.
//****************************************************************************************

#include "strategy/stream_filter/QualityOfServiceFilter.h"

namespace tbricks {

/// @deprecated Deprecated in 2.14.5 use QualityOfServiceFilter
using QoSFilter[[deprecated(DEPRECATE_LINK)]] = QualityOfServiceFilter;

/// @deprecated Deprecated in 2.14.5 use AnyQualityOfServiceFilter
using AnyQoSFilter[[deprecated(DEPRECATE_LINK)]] = AnyQualityOfServiceFilter;

/// @deprecated Deprecated in 2.14.5 use QualityOfServiceFilterCondition
using QoSFilterCondition[[deprecated(DEPRECATE_LINK)]] = QualityOfServiceFilterCondition;
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in service status streams.
//****************************************************************************************

#include "strategy/ServiceStatus.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/stream_filter/ServiceFilter.h"

namespace tbricks {

/**
 * Default service status filter, matches all data.
 */
using ServiceStatusFilter[[deprecated(DEPRECATE_LINK)]] = Service::Stream::Filters::Filter;

/**
 * Convenience alias.
 */
using AnyServiceStatusFilter[[deprecated(DEPRECATE_LINK)]] = AnyServiceFilter;

using ServiceStatusFilterCondition[[deprecated(DEPRECATE_LINK)]] = Service::Stream::Filters::FilterCondition;

/**
 * Service status filter by type.
 */
using ServiceStatusByTypeFilter[[deprecated(DEPRECATE_LINK)]] = Service::Stream::Filters::ByTypeFilter;

/**
 * Service status filter by venue.
 */
using ServiceStatusByVenueFilter[[deprecated(DEPRECATE_LINK)]] = Service::Stream::Filters::ByVenueFilter;
}

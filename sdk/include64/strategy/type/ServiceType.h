#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Service Type.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT ServiceType
{
    GRID_BACKEND = 0,
    INSTRUMENT = 1,
    MARKET_DATA = 2,
    METADATA = 3,
    ORDER_PERSISTENCE = 4,
    XRAY_FRONTEND = 5,
    INSTRUMENT_REFERENCE_DATA = 6,
    STRATEGY_ENGINE = 7,
    TRADE_PERSISTENCE = 9,
    TRADING = 10,
    XRAY_PERSISTENCE = 11,
    MARKET_PLACE = 12,
    INTEGRATION = 14,
    SMS = 15,
    TRADING_REFERENCE_DATA = 16,
    TIME_SERIES = 17,
    REPLAY = 18,
    PRICING_ENGINE = 19,
    LIMIT_ENGINE = 20,
    ACCESSORY_ENGINE = 21,
    QUOTING = 23,
    REQUEST_FOR_QUOTE = 24,
    QUOTE_REQUEST = 25,
    EXPIT_TRADING = 26,
    INTEGRATION_ENGINE = 27,
    FLOW_ENGINE = 28,
    MATCHING_ENGINE = 29,
    MARKET_INFORMATION = 30,
    CONTRIBUTION = 31,
    OMD_RAW_DATA_SERVER = 32,
    DIRECTED_QUOTING = 33,
    VISUALIZATION_ENGINE = 34,
    MARKET_COMMAND = 35,
    DIRECTED_QUOTE_REQUEST = 36,
    DISTRIBUTION_ENGINE = 37,
    OMD_TICK_SERVER = 38,
    OMD_NATIVE_MEMORY_LOADER = 39,
    OMD_NATIVE_DAILY_LOADER = 40,
    OMD_RT_MEMORY_LOADER = 41,
    OMD_RT_DAILY_LOADER = 42,
    OMD_ASCII_DAILY_LOADER = 43,
    OMD_OTQ_QUERY_DAILY_LOADER = 44,
    DROP_COPY = 45,
    UNKNOWN = 46
};

STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const ServiceType & value);
}

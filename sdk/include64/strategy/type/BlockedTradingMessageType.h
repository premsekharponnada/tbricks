#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BlockedTradingMessageType enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT BlockedTradingMessageType
{
    ORDER = 76, /**< Order */
    BLOCK_ORDER = 1008, /**< Block order */
    QUOTE_SET = 1036, /**< Quote set */
    EXPIT = 1135, /**< Ex-pit */
    DIRECTED_QUOTE = 1198 /**< Directed quote */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, BlockedTradingMessageType value);

}

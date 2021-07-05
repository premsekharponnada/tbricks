#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OwnQuoteBookSource enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT OwnQuoteBookSource
{
    QUOTING = 0, /**< The quote is continuously being sent into the market using native transactions. */
    QUOTING_MULTILEVEL = 1, /**< The quote is continuously being sent into the market using orders. */
    HIDDEN = 2, /**< The quote watches for opportunities and uses immediate orders to try to capture them. */
    PEG = 3, /**< The quote offsets the market by a specified number of ticks, bound upwards by a specific threshold. */
    QUOTE_RESPONDER = 4 /**< The quote is a reply to a quote request. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, OwnQuoteBookSource value);

}

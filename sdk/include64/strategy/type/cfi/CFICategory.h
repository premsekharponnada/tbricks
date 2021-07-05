#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Classification of Financial Instruments.
//****************************************************************************************

namespace tbricks {

enum class CFICategory
{
    EQUITY = 'E',
    COLLECTIVE_INVESTMENT_VEHICLES = 'C',
    DEBT = 'D',
    RIGHTS = 'R',
    OPTIONS = 'O',
    FUTURES = 'F',
    SWAPS = 'S',
    NON_OR_COMPLEX_LISTED_OPTIONS = 'H',
    SPOT = 'I',
    FORWARDS = 'J',
    STRATEGIES = 'K',
    FINANCING = 'L',
    REFERENCE_INSTRUMENTS = 'T',
    OTHERS = 'M'
};
}

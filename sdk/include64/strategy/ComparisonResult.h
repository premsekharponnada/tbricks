#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ComparisonResult
//****************************************************************************************

#include <ostream>

namespace tbricks {

enum ComparisonResult
{
    TB_EQUAL = 0,
    TB_LESS_THAN = -1,
    TB_GREATER_THAN = 1,
    TB_UNDEFINED = -2
};

inline std::ostream & operator<<(std::ostream & strm, const ComparisonResult & result)
{
    switch (result) {
    case TB_EQUAL:
        strm << " == ";
        break;
    case TB_LESS_THAN:
        strm << " < ";
        break;
    case TB_GREATER_THAN:
        strm << " > ";
        break;
    case TB_UNDEFINED:
        strm << "<undefined>";
        break;
    default:
        strm << "<invalid>:" << (int)result;
        break;
    }
    return strm;
}
}

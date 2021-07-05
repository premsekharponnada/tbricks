#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// FilterOperation
//****************************************************************************************

namespace tbricks {

/**
 * FilterOperation enum represents operation by which child filter nodes are connected
 */
enum class FilterOperation
{
    EMPTY = 0, /**< Filter is default-constructed, contains neither condition nor child nodes. */
    AND,       /**< Child filter nodes are connected by conjunction. */
    OR,        /**< Child filter nodes are connected by disjunction. */
    MATCH      /**< Filter contains condition. */
};
}

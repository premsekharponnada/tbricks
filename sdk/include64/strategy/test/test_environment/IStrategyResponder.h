#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// IStrategyResponder
//****************************************************************************************

#include "strategy/Types.h"

namespace tbricks {

class IStrategyResponder
{
public:
    virtual unsigned int
    dataHighLevelTypeForUUID(const tbricks::Uuid & uuid, tbricks::String & name, std::vector<std::pair<int, String>> & enumerationItems) const = 0;
};
} // namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ErrorProcessing
//****************************************************************************************

#include "strategy/Linkage.h"

namespace tbricks {

class STRATEGY_EXPORT ErrorProcessing
{
public:
    enum ErrorProcessingType
    {
        EP_UNDEFINED = 0,
        EP_EXCEPTION = 1,
        EP_WARNING = 2,
        EP_FULLDUMP = 3
    };

public:
    static ErrorProcessingType GetErrorProcessingType();

    static void SetErrorProcessingType(ErrorProcessingType type);

private:
    ErrorProcessing();
};

} // namespace tbricks

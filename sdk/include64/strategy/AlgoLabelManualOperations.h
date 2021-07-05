#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// AlgoLabelManualOperations
//****************************************************************************************

#include "strategy/Linkage.h"

namespace tbricks {

class STRATEGY_EXPORT AlgoLabelManualOperations
{
public:
    AlgoLabelManualOperations();
    ~AlgoLabelManualOperations();
    AlgoLabelManualOperations(const AlgoLabelManualOperations &) = delete;
    AlgoLabelManualOperations & operator=(const AlgoLabelManualOperations &) = delete;

private:
    bool m_previous_value;
};
}

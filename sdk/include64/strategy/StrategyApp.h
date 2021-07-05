#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyApp
//****************************************************************************************

#include "strategy/VisualizationApp.h"

namespace tbricks {

/**
 * StrategyApp class is a base class for all user-defined strategies. Its
 * interface provides for strategy data access and manipulations, and all
 * strategy data changes are automatically become available for interested
 * strategy stream listeners. Provides new visualization interface.
 *
 * Descendants of the class may choose to handle events sent to the
 * strategy from the outside by overriding appropriate callbacks
 * that come from IStrategyEventHandler. Strategy API guarantees
 * sequential execution of strategy events, i.e. no callbacks will
 * ever be launched in parallel. Any modifications to the strategy
 * instance are not propagated to the outside until the callback
 * is finished, that is, if a callback changes e.g. strategy state a few times,
 * only the last state will become visible to other strategies when the
 * callback methods exits.
 */
class STRATEGY_EXPORT StrategyApp : public VisualizationApp
{};
}

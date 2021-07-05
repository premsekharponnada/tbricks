#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QoS stream.
//****************************************************************************************

#include "strategy/stream/QualityOfServiceStream.h"

// \namespace tbricks
namespace tbricks {

/// @deprecated Deprecated in 2.14.5 use QualityOfServiceStream
using QoSStream[[deprecated(DEPRECATE_LINK)]] = QualityOfServiceStream;

} // \namespace tbricks

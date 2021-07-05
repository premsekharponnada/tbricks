#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Additional data, available as a strategy property.
//****************************************************************************************

#include "strategy/StringDictionary.h"

namespace tbricks {

/**
 * ExtraData class provides a convenience container to keep user-defined data in
 * a vector of key-value pairs. It is possible to pass it down to the new
 * strategy with StrategyOptions object.
 *
 * If passed to the Order Strategy, extra data becomes a part of order business
 * object which could be analyzed by Trading service, which allows to enhance
 * default order processing by e.g. adding some FIX fields etc. (Subject to
 * Trading service configuration; please see system documentation for more
 * details).
 *
 * @see StrategyOptions
 */
class STRATEGY_EXPORT ExtraData : public StringDictionary
{
public:
    ExtraData() = default;

    ExtraData(const tbricks::types::Dictionary & src);
    ExtraData(tbricks::types::Dictionary && src) noexcept;
    ExtraData & operator=(const tbricks::types::Dictionary & src);
    ExtraData & operator=(tbricks::types::Dictionary && src) noexcept;

private:
    friend class StrategyAttributes;
    ExtraData(tbricks::types::DictionaryRef && value) noexcept;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Order Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/Validity.h"
#include "strategy/type/Boolean.h"
#include "strategy_generated/TestBlockOrderOptionsBase.h"

// \namespace tbricks
namespace tbricks::protocol {
class BlockOrder;
}

namespace tbricks::test {

class STRATEGY_EXPORT BlockOrderOptions : public TestBlockOrderOptionsBase
{
public:
    BlockOrderOptions() = default;
    using TestBlockOrderOptionsBase::TestBlockOrderOptionsBase;

public:
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRetainOnDisconnect() const;

    /**
     * Get retain on disconnect.
     *
     * @return                          retain on disconnect
     */
    Boolean GetRetainOnDisconnect() const;

    /**
     * %Set retain on disconnect.
     *
     * @param value                     retain on disconnect
     */
    void SetRetainOnDisconnect(const Boolean & value);

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasValidity() const;

    /**
     * Get validity.
     *
     * @return                          validity
     */
    Validity GetValidity() const;

    /**
     * %Set validity.
     *
     * @param value                     validity
     */
    void SetValidity(const Validity & value);
};

} // \namespace tbricks::test

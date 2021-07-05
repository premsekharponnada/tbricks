#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PublicTrade
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Boolean.h"
#include "strategy/type/Price.h"
#include "strategy/type/Side.h"
#include "strategy/type/String.h"
#include "strategy/type/Volume.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/MIC.h"
#include "strategy/type/MMTFlags.h"
#include "strategy/ExtraData.h"
#include "strategy/MarketDataParameters.h"
#include "strategy/type/PublicTradeIdentifier.h"
#include "strategy_generated/PublicTradeBase.h"

namespace tbricks {

class STRATEGY_EXPORT PublicTrade : public PublicTradeBase
{
public:
    using PublicTradeBase::PublicTradeBase;

    /**
     * Get Unique public trade identifier.
     *
     * @return                          Unique public trade identifier.
     *
     * @deprecated Deprecated in 2.14.4, please use GetIdentifier() method instead
     */
    [[deprecated(DEPRECATE_LINK)]] String GetPublicTradeIdentifier() const;
};
}

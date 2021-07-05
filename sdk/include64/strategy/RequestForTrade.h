#pragma once

//****************************************************************************
// Tbricks Strategy Framework.
//
// Copyright (c) 2017 Itiviti Group.
//
// RequestForTrade object
//
//****************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/ExtraData.h"
#include "strategy/MarketDataParameters.h"
#include "strategy/RequestForTradeLeg.h"
#include "strategy/type/BlockOrderIdentifier.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/ExPitIdentifier.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/OrderIdentifier.h"
#include "strategy/type/Price.h"
#include "strategy/type/Side.h"
#include "strategy/type/String.h"
#include "strategy/type/TreeNodeIdentifier.h"
#include "strategy/type/Volume.h"

#include "strategy_generated/RequestForTradeBase.h"

namespace tbricks {

class STRATEGY_EXPORT RequestForTrade : public RequestForTradeBase
{
public:
    class Stream;

public:
    RequestForTrade() = default;

    RequestForTrade(std::shared_ptr<protocol::RequestForTrade> && value) : RequestForTradeBase(std::move(value)) {}

public:
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] InstrumentVenueIdentification GetInstrumentVenueIdentification() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] Side GetSide() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] Volume GetVolume() const;
    /// @deprecated Deprecated in 2.13.0, will be removed in the next release.
    [[deprecated(DEPRECATE_LINK)]] Price GetPrice() const;
};
}

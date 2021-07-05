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
#include "strategy/type/Price.h"
#include "strategy/type/Side.h"
#include "strategy/type/Volume.h"
#include "strategy_generated/RequestForTradeLegBase.h"

namespace tbricks {

class STRATEGY_EXPORT RequestForTradeLeg : public RequestForTradeLegBase
{
public:
    RequestForTradeLeg() = default;
    RequestForTradeLeg(const protocol::RequestForTradeLeg & value) : RequestForTradeLegBase(value) {}

public:
    bool HasInstrumentVenueIdentification() const;
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & value);
};
}

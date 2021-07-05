#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OwnPriceLevelQuoteBook stream options.
//****************************************************************************************

#include "strategy/User.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/stream/OwnPriceLevelQuoteBookStream.h"
#include "strategy/stream_throttle/CommonThrottle.h"
#include "strategy/type/LiquidityPoolIdentifier.h"
#include "strategy/type/OwnQuoteBookSource.h"
#include "strategy/type/OwnQuoteBookType.h"

namespace tbricks {

/**
 * OwnPriceLevelQuoteBook::Stream::Options class
 */
class STRATEGY_EXPORT OwnPriceLevelQuoteBook::Stream::Options : public Printable
{
public:
    Options();

public:
    void SetThrottle(const BasicThrottle & throttle) { m_throttle = throttle; }
    BasicThrottle GetThrottle() const { return m_throttle; }

    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid) { m_ivid = ivid; }
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const { return m_ivid; }

    void SetType(OwnQuoteBookType type) { m_type = type; }
    OwnQuoteBookType GetType() const { return m_type; }

    void SetSource(OwnQuoteBookSource source) { m_source = source; }
    OwnQuoteBookSource GetSource() const { return m_source; }

    void SetUser(const User & user) { m_user = user; }
    User GetUser() const { return m_user; }

    void SetLiquidityPool(const LiquidityPoolIdentifier & lp) { m_liquidity_pool = lp; }
    LiquidityPoolIdentifier GetLiquidityPool() const { return m_liquidity_pool; }

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    BasicThrottle m_throttle;
    InstrumentVenueIdentification m_ivid;
    OwnQuoteBookType m_type;
    OwnQuoteBookSource m_source;
    User m_user;
    LiquidityPoolIdentifier m_liquidity_pool;
};
}

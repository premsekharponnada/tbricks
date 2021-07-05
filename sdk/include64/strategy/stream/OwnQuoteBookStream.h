#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OwnQuoteBook stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/OwnQuoteBook.h"
#include "strategy/Strategy.h"
#include "strategy/Filters.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_throttle/CommonThrottle.h"

namespace tbricks {

class STRATEGY_EXPORT OwnQuoteBook::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Options;

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open(Type type, const Options & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * OwnQuoteBook::Stream::IHandler
 */
class STRATEGY_EXPORT OwnQuoteBook::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleQuoteInformation(const StreamIdentifier & stream_id, const OwnQuoteBook::Update & update) = 0;

protected:
    virtual ~IHandler();
};

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif

/**
 * OwnQuoteBook::Stream::Options
 */
class STRATEGY_EXPORT OwnQuoteBook::Stream::Options : public Printable
{
public:
    Options();
    virtual ~Options();

public:
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);
    const InstrumentVenueIdentification & GetInstrumentVenueIdentification() const;

    /**
     * %Set own quote book source.
     *
     * @param          New source
     *
     * @deprecated Deprecated in 2.14.0, use SetSource instead
     */
    [[deprecated(DEPRECATE_LINK)]] void SetOwnQuoteBookSource(OwnQuoteBookSource source);

    /**
     * %Get own quote book source.
     *
     * @return          source
     *
     * @deprecated Deprecated in 2.14.0, use GetSource instead
     */
    [[deprecated(DEPRECATE_LINK)]] OwnQuoteBookSource GetOwnQuoteBookSource() const;

    /**
     * %Set own quote book type.
     *
     * @param          New type
     *
     * @deprecated Deprecated in 2.14.0, use SetType instead
     */
    [[deprecated(DEPRECATE_LINK)]] void SetOwnQuoteBookType(OwnQuoteBookType type);

    /**
     * %Get own quote book type.
     *
     * @return          type
     *
     * @deprecated Deprecated in 2.14.0, use GetType instead
     */
    [[deprecated(DEPRECATE_LINK)]] OwnQuoteBookType GetOwnQuoteBookType() const;

    void SetSource(tbricks::OwnQuoteBookSource source);
    tbricks::OwnQuoteBookSource GetSource() const;

    void SetType(tbricks::OwnQuoteBookType type);
    tbricks::OwnQuoteBookType GetType() const;

    void SetUser(const User & user);
    const User & GetUser() const;

    void SetThrottle(const BasicThrottle & throttle);
    const BasicThrottle & GetThrottle() const;

    void SetLiquidityPool(const LiquidityPoolIdentifier & lp);
    const LiquidityPoolIdentifier & GetLiquidityPool() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentVenueIdentification m_ivid;
    tbricks::OwnQuoteBookSource m_source;
    tbricks::OwnQuoteBookType m_type;
    User m_user;
    LiquidityPoolIdentifier m_liquidity_pool;

    BasicThrottle m_throttle;
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif

} // \namespace tbricks

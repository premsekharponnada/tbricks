#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForQuote object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/MarketDataParameters.h"

namespace tbricks {

namespace protocol {
class RequestForQuote;
}

namespace visualization {
class RequestForQuoteRowEntityImpl;
}

class RequestForQuoteProvider;

class STRATEGY_EXPORT RequestForQuote : public Printable
{
public:
    enum Type
    {
        NONE = 0,
        NORMAL = 1,            /**< Regular request for quote */
        REQUEST_FOR_CROSS = 2, /**< Request for cross */
        INDICATIVE = 3         /**< Request for indicative quoting */
    };

public:
    class Stream;

public:
    RequestForQuote();
    RequestForQuote(const RequestForQuote & rfq);
    RequestForQuote(RequestForQuote && rfq) noexcept;
    RequestForQuote & operator=(const RequestForQuote & rfq);
    RequestForQuote & operator=(RequestForQuote && rfq) noexcept;

    virtual ~RequestForQuote();

    /**
     * Get request for quote identifier.
     *
     * @return                          Identifier
     */
    Identifier GetIdentifier() const;

    /**
     * Get instrument venue identification.
     *
     * @return                          InstrumentVenueIdentification
     */
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;

    /**
     * Get counterpart.
     *
     * @return                          Counterpart
     */
    String GetCounterpart() const;

    /**
     * Get exchange request for quote reference
     *
     * The exchanges reference for the request for quote expressed as human readable text.
     * This is data originating from the exchange or venue itself, normally it is the
     * exchanges internal tag for the request for quote generated by the exchange.
     *
     * @return                          Counterpart
     */
    String GetExchangeRequestForQuoteReference() const;

    /**
     * Get host created date time.
     *
     * @return                          Host created date time
     */
    DateTime GetHostCreatedDatetime() const;

    /*
     * Get exchange created date time.
     *
     * @return                          Exchange created date time
     */
    DateTime GetExchangeCreatedDatetime() const;

    /**
     * Get side.
     *
     * @return                          Side
     */
    Side GetSide() const;

    /**
     * Get volume.
     *
     * @return                          Volume
     */
    Volume GetVolume() const;

    /**
     * Get type.
     *
     * @return                          Type
     */
    Type GetType() const;

    /**
     * Get directed quote expected.
     *
     * @return                          Directed quote expected
     */
    Boolean GetDirectedQuoteExpected() const;

    /**
     * Get market data parameters.
     *
     * @return                          Market data parameters
     */
    MarketDataParameters GetMarketDataParameters() const;

    /**
     * Get client.
     *
     * @return                          Client
     */
    TreeNodeIdentifier GetClient() const;

    /**
     * Get liquidity pool
     *
     * @return                          Liquidity pool identifier
     */
    LiquidityPoolIdentifier GetLiquidityPool() const;

    /**
     * Get valid until date time
     *
     * @return                          Valid until date time
     */
    DateTime GetValidUntilDatetime() const;

    bool Empty() const;

public:
    void SetIdentifier(const Identifier & id);
    void SetVolume(const Volume & volume);
    void SetSide(const Side & side);
    void SetDirectedQuoteExpected(bool expected);
    void SetCounterpart(const String & counterpart);
    void SetClient(const TreeNodeIdentifier & client);
    void SetLiquidityPool(const LiquidityPoolIdentifier & liquidity_pool);
    void SetValidUntilDatetime(const DateTime & value);
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);
    void SetType(Type type);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    RequestForQuote(std::shared_ptr<protocol::RequestForQuote> && msg) noexcept;

private:
    friend RequestForQuoteProvider;

    friend STRATEGY_EXPORT class visualization::RequestForQuoteRowEntityImpl;
    const protocol::RequestForQuote * get_rfq() const { return m_impl.get(); }

    friend class DirectedQuoteReject;

    std::shared_ptr<protocol::RequestForQuote> m_impl;
};

std::ostream & operator<<(std::ostream & strm, const RequestForQuote::Type & type);
}

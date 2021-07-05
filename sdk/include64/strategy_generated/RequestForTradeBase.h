#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForTradeBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class BlockOrderIdentifier;
class Boolean;
class DateTime;
class DirectedQuoteGeneration;
class DirectedQuoteIdentifier;
class ExPitIdentifier;
class ExtraData;
class Identifier;
class MarketDataParameters;
class OrderIdentifier;
class RequestForTradeIdentifier;
class RequestForTradeLeg;
class String;
class TreeNodeIdentifier;


namespace protocol { class RequestForTrade; }

class STRATEGY_EXPORT RequestForTradeBase : public Printable
{
protected:
    RequestForTradeBase();
    RequestForTradeBase(const RequestForTradeBase & value);
    RequestForTradeBase(RequestForTradeBase && value) noexcept;
    RequestForTradeBase & operator=(const RequestForTradeBase & value);
    RequestForTradeBase & operator=(RequestForTradeBase && value) noexcept;
    virtual ~RequestForTradeBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpart() const;

    /**
     * Get counterpart.
     *
     *
     * @return                          counterpart
     */
    String GetCounterpart() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpartIdentifier() const;

    /**
     * Get counterpart identifier.
     *
     *
     * @return                          counterpart identifier
     */
    TreeNodeIdentifier GetCounterpartIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeCreatedDatetime() const;

    /**
     * Get exchange created datetime.
     *
     *
     * @return                          exchange created datetime
     */
    DateTime GetExchangeCreatedDatetime() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExPitIdentifier() const;

    /**
     * Get expit identifier.
     *
     *
     * @return                          expit identifier
     */
    ExPitIdentifier GetExPitIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExtraData() const;

    /**
     * Get extra data.
     *
     *
     * @return                          extra data
     */
    ExtraData GetExtraData() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostCreatedDatetime() const;

    /**
     * Get host created datetime.
     *
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDatetime() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostModifiedDatetime() const;

    /**
     * Get host modified datetime.
     *
     *
     * @return                          host modified datetime
     */
    DateTime GetHostModifiedDatetime() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get stream item identifier.
     *
     *
     * @return                          stream item identifier
     */
    Identifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMessage() const;

    /**
     * Get message text.
     *
     *
     * @return                          message text
     */
    String GetMessage() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOrderIdentifier() const;

    /**
     * Get order identifier.
     *
     *
     * @return                          order identifier
     */
    OrderIdentifier GetOrderIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMarketDataParameters() const;

    /**
     * Get market data parameters.
     *
     *
     * @return                          market data parameters
     */
    MarketDataParameters GetMarketDataParameters() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSettlementDate() const;

    /**
     * Get settlement date.
     *
     *
     * @return                          settlement date
     */
    DateTime GetSettlementDate() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBlockOrderIdentifier() const;

    /**
     * Get block order identifier.
     *
     *
     * @return                          block order identifier
     */
    BlockOrderIdentifier GetBlockOrderIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestForQuoteIdentifier() const;

    /**
     * Get quote request identifier.
     *
     *
     * @return                          quote request identifier
     */
    Identifier GetRequestForQuoteIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteIdentifier() const;

    /**
     * Get directed quote identifier.
     *
     *
     * @return                          directed quote identifier
     */
    DirectedQuoteIdentifier GetDirectedQuoteIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteGeneration() const;

    /**
     * Get directed quote generation.
     *
     *
     * @return                          directed quote generation
     */
    DirectedQuoteGeneration GetDirectedQuoteGeneration() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLegs() const;

    /**
     * Get request for trade legs.
     *
     *
     * @return                          request for trade legs
     */
    std::vector<RequestForTradeLeg> GetLegs() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRespondByDatetime() const;

    /**
     * Get respond by datetime.
     *
     *
     * @return                          respond by datetime
     */
    DateTime GetRespondByDatetime() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestForTradeIdentifier() const;

    /**
     * Get request for trade identifier.
     *
     *
     * @return                          request for trade identifier
     */
    RequestForTradeIdentifier GetRequestForTradeIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeleted() const;

    /**
     * Get deleted.
     *
     *
     * @return                          deleted
     */
    Boolean GetDeleted() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    RequestForTradeBase(const protocol::RequestForTrade & value);
    RequestForTradeBase(std::shared_ptr<protocol::RequestForTrade> && value);

    std::shared_ptr<protocol::RequestForTrade> & get_impl_wr() const;
    const std::shared_ptr<protocol::RequestForTrade> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::RequestForTrade> m_impl;
};

}

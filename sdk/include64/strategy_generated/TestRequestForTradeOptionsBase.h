#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestRequestForTradeOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class BlockOrderIdentifier;
class DateTime;
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

class STRATEGY_EXPORT TestRequestForTradeOptionsBase : public Printable
{
protected:
    TestRequestForTradeOptionsBase();
    TestRequestForTradeOptionsBase(const TestRequestForTradeOptionsBase & value);
    TestRequestForTradeOptionsBase(TestRequestForTradeOptionsBase && value) noexcept;
    TestRequestForTradeOptionsBase & operator=(const TestRequestForTradeOptionsBase & value);
    TestRequestForTradeOptionsBase & operator=(TestRequestForTradeOptionsBase && value) noexcept;
    virtual ~TestRequestForTradeOptionsBase();

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
     * %Set counterpart.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     counterpart
     */
    void SetCounterpart(const String & value);

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
     * %Set counterpart identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     counterpart identifier
     */
    void SetCounterpartIdentifier(const TreeNodeIdentifier & value);

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
     * %Set exchange created datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange created datetime
     */
    void SetExchangeCreatedDatetime(const DateTime & value);

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
     * %Set expit identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expit identifier
     */
    void SetExPitIdentifier(const ExPitIdentifier & value);

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
     * %Set extra data.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     extra data
     */
    void SetExtraData(const ExtraData & value);

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
     * %Set host created datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host created datetime
     */
    void SetHostCreatedDatetime(const DateTime & value);

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
     * %Set host modified datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host modified datetime
     */
    void SetHostModifiedDatetime(const DateTime & value);

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
     * %Set stream item identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     stream item identifier
     */
    void SetIdentifier(const Identifier & value);

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
     * %Set message text.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     message text
     */
    void SetMessage(const String & value);

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
     * %Set order identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     order identifier
     */
    void SetOrderIdentifier(const OrderIdentifier & value);

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
     * %Set market data parameters.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     market data parameters
     */
    void SetMarketDataParameters(const MarketDataParameters & value);

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
     * %Set settlement date.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     settlement date
     */
    void SetSettlementDate(const DateTime & value);

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
     * %Set block order identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     block order identifier
     */
    void SetBlockOrderIdentifier(const BlockOrderIdentifier & value);

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
     * %Set quote request identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote request identifier
     */
    void SetRequestForQuoteIdentifier(const Identifier & value);

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
     * %Set request for trade legs.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     request for trade legs
     */
    void SetLegs(const std::vector<RequestForTradeLeg> & value);

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
     * %Set respond by datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     respond by datetime
     */
    void SetRespondByDatetime(const DateTime & value);

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
     * %Set request for trade identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     request for trade identifier
     */
    void SetRequestForTradeIdentifier(const RequestForTradeIdentifier & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const TestRequestForTradeOptionsBase & update);

/** @cond PRIVATE */
public:
    TestRequestForTradeOptionsBase(const protocol::RequestForTrade & value);
    TestRequestForTradeOptionsBase(std::shared_ptr<protocol::RequestForTrade> && value);

    std::shared_ptr<protocol::RequestForTrade> & get_impl_wr() const;
    const std::shared_ptr<protocol::RequestForTrade> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::RequestForTrade> m_impl;
};

}

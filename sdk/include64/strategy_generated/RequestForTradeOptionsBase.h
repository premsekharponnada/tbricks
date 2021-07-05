#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForTradeOptionsBase object
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
class DirectedQuoteGeneration;
class DirectedQuoteIdentifier;
class Identifier;
class OrderIdentifier;
class RequestForTradeIdentifier;
class RequestForTradeLeg;
class String;
class TreeNodeIdentifier;


namespace protocol { class RequestForTrade; }

class STRATEGY_EXPORT RequestForTradeOptionsBase : public Printable
{
protected:
    RequestForTradeOptionsBase();
    RequestForTradeOptionsBase(const RequestForTradeOptionsBase & value);
    RequestForTradeOptionsBase(RequestForTradeOptionsBase && value) noexcept;
    RequestForTradeOptionsBase & operator=(const RequestForTradeOptionsBase & value);
    RequestForTradeOptionsBase & operator=(RequestForTradeOptionsBase && value) noexcept;
    virtual ~RequestForTradeOptionsBase();

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
    bool HasDirectedQuoteIdentifier() const;

    /**
     * Get directed quote identifier.
     *
     *
     * @return                          directed quote identifier
     */
    DirectedQuoteIdentifier GetDirectedQuoteIdentifier() const;

    /**
     * %Set directed quote identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote identifier
     */
    void SetDirectedQuoteIdentifier(const DirectedQuoteIdentifier & value);

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
     * %Set directed quote generation.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote generation
     */
    void SetDirectedQuoteGeneration(const DirectedQuoteGeneration & value);

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


/** @cond PRIVATE */
public:
    RequestForTradeOptionsBase(const protocol::RequestForTrade & value);
    RequestForTradeOptionsBase(std::unique_ptr<protocol::RequestForTrade> && value);

    std::unique_ptr<protocol::RequestForTrade> & get_impl_wr() const;
    const std::unique_ptr<protocol::RequestForTrade> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::RequestForTrade> m_impl;
};

}

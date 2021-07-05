#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BlockOrderOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class BlockOrderLeg;
class Boolean;
class Currency;
class DirectedQuoteResponseGeneration;
class DirectedQuoteResponseIdentifier;
class Double;
class ExtraData;
class OrderCapacity;
class Price;
class PricePolicy;
class RegulatoryParameters;
class TreeNodeIdentifier;
class UserIdentifier;


namespace protocol { class BlockOrder; }

class STRATEGY_EXPORT BlockOrderOptionsBase : public Printable
{
protected:
    BlockOrderOptionsBase();
    BlockOrderOptionsBase(const BlockOrderOptionsBase & value);
    BlockOrderOptionsBase(BlockOrderOptionsBase && value) noexcept;
    BlockOrderOptionsBase & operator=(const BlockOrderOptionsBase & value);
    BlockOrderOptionsBase & operator=(BlockOrderOptionsBase && value) noexcept;
    virtual ~BlockOrderOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLegs() const;

    /**
     * Get block order legs.
     *
     *
     * @return                          block order legs
     */
    std::vector<BlockOrderLeg> GetLegs() const;

    /**
     * %Set block order legs.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     block order legs
     */
    void SetLegs(const std::vector<BlockOrderLeg> & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBypassSoftLimits() const;

    /**
     * Get bypass soft limits.
     *
     *
     * @return                          bypass soft limits
     */
    Boolean GetBypassSoftLimits() const;

    /**
     * %Set bypass soft limits.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     bypass soft limits
     */
    void SetBypassSoftLimits(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandler() const;

    /**
     * Get handler.
     *
     *
     * @return                          handler
     */
    TreeNodeIdentifier GetHandler() const;

    /**
     * %Set handler.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     handler
     */
    void SetHandler(const TreeNodeIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCapacity() const;

    /**
     * Get order capacity.
     *
     *
     * @return                          order capacity
     */
    OrderCapacity GetCapacity() const;

    /**
     * %Set order capacity.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     order capacity
     */
    void SetCapacity(const OrderCapacity & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOwner() const;

    /**
     * Get owner.
     *
     *
     * @return                          owner
     */
    UserIdentifier GetOwner() const;

    /**
     * %Set owner.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     owner
     */
    void SetOwner(const UserIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPrice() const;

    /**
     * Get price.
     *
     *
     * @return                          price
     */
    Price GetPrice() const;

    /**
     * %Set price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     price
     */
    void SetPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPricePolicy() const;

    /**
     * Get price policy.
     *
     *
     * @return                          price policy
     */
    PricePolicy GetPricePolicy() const;

    /**
     * %Set price policy.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     price policy
     */
    void SetPricePolicy(const PricePolicy & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRegulatoryParameters() const;

    /**
     * Get regulatory parameters.
     *
     *
     * @return                          regulatory parameters
     */
    RegulatoryParameters GetRegulatoryParameters() const;

    /**
     * %Set regulatory parameters.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     regulatory parameters
     */
    void SetRegulatoryParameters(const RegulatoryParameters & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRetainOnDisconnect() const;

    /**
     * Get retain on disconnect.
     *
     *
     * @return                          retain on disconnect
     */
    Boolean GetRetainOnDisconnect() const;

    /**
     * %Set retain on disconnect.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     retain on disconnect
     */
    void SetRetainOnDisconnect(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTargetPrice() const;

    /**
     * Get target price.
     *
     *
     * @return                          target price
     */
    Double GetTargetPrice() const;

    /**
     * %Set target price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     target price
     */
    void SetTargetPrice(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDealtCurrency() const;

    /**
     * Get dealt currency.
     *
     *
     * @return                          dealt currency
     */
    Currency GetDealtCurrency() const;

    /**
     * %Set dealt currency.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     dealt currency
     */
    void SetDealtCurrency(const Currency & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteResponseIdentifier() const;

    /**
     * Get directed quote response identifier.
     *
     *
     * @return                          directed quote response identifier
     */
    DirectedQuoteResponseIdentifier GetDirectedQuoteResponseIdentifier() const;

    /**
     * %Set directed quote response identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote response identifier
     */
    void SetDirectedQuoteResponseIdentifier(const DirectedQuoteResponseIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasGeneration() const;

    /**
     * Get directed quote response generation.
     *
     *
     * @return                          directed quote response generation
     */
    DirectedQuoteResponseGeneration GetGeneration() const;

    /**
     * %Set directed quote response generation.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote response generation
     */
    void SetGeneration(const DirectedQuoteResponseGeneration & value);

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    BlockOrderOptionsBase(const protocol::BlockOrder & value);
    BlockOrderOptionsBase(std::unique_ptr<protocol::BlockOrder> && value);

    std::unique_ptr<protocol::BlockOrder> & get_impl_wr() const;
    const std::unique_ptr<protocol::BlockOrder> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::BlockOrder> m_impl;
};

}

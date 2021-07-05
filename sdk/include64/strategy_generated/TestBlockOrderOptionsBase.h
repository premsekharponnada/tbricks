#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestBlockOrderOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class BlockOrderIdentifier;
class BlockOrderLeg;
class Boolean;
class DirectedQuoteResponseGeneration;
class DirectedQuoteResponseIdentifier;
class Identifier;
class Integer;
class OrderCapacity;
class Price;
class PricePolicy;
class RegulatoryParameters;
class ServiceIdentifier;
class TreeNodeIdentifier;
class UserIdentifier;


namespace protocol { class BlockOrder; }

class STRATEGY_EXPORT TestBlockOrderOptionsBase : public Printable
{
protected:
    TestBlockOrderOptionsBase();
    TestBlockOrderOptionsBase(const TestBlockOrderOptionsBase & value);
    TestBlockOrderOptionsBase(TestBlockOrderOptionsBase && value) noexcept;
    TestBlockOrderOptionsBase & operator=(const TestBlockOrderOptionsBase & value);
    TestBlockOrderOptionsBase & operator=(TestBlockOrderOptionsBase && value) noexcept;
    virtual ~TestBlockOrderOptionsBase();

public:
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
    bool HasRequestIdentifier() const;

    /**
     * Get request identifier.
     *
     *
     * @return                          request identifier
     */
    Identifier GetRequestIdentifier() const;

    /**
     * %Set request identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     request identifier
     */
    void SetRequestIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasFlowRoutingRuleIdentifier() const;

    /**
     * Get flow routing rule identifier.
     *
     *
     * @return                          flow routing rule identifier
     */
    TreeNodeIdentifier GetFlowRoutingRuleIdentifier() const;

    /**
     * %Set flow routing rule identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     flow routing rule identifier
     */
    void SetFlowRoutingRuleIdentifier(const TreeNodeIdentifier & value);

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
    bool HasAlgoLabel() const;

    /**
     * Get algo label.
     *
     *
     * @return                          algo label
     */
    Integer GetAlgoLabel() const;

    /**
     * %Set algo label.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     algo label
     */
    void SetAlgoLabel(const Integer & value);

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
    bool HasCreator() const;

    /**
     * Get creator.
     *
     *
     * @return                          creator
     */
    UserIdentifier GetCreator() const;

    /**
     * %Set creator.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     creator
     */
    void SetCreator(const UserIdentifier & value);

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

    /**
     * %Set deleted.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     deleted
     */
    void SetDeleted(const Boolean & value);

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
    bool HasOrderCapacity() const;

    /**
     * Get order capacity.
     *
     *
     * @return                          order capacity
     */
    OrderCapacity GetOrderCapacity() const;

    /**
     * %Set order capacity.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     order capacity
     */
    void SetOrderCapacity(const OrderCapacity & value);

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
    bool HasTradingServiceIdentifier() const;

    /**
     * Get trading service instance identifier.
     *
     *
     * @return                          trading service instance identifier
     */
    ServiceIdentifier GetTradingServiceIdentifier() const;

    /**
     * %Set trading service instance identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     trading service instance identifier
     */
    void SetTradingServiceIdentifier(const ServiceIdentifier & value);

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    TestBlockOrderOptionsBase(const protocol::BlockOrder & value);
    TestBlockOrderOptionsBase(std::shared_ptr<protocol::BlockOrder> && value);

    std::shared_ptr<protocol::BlockOrder> & get_impl_wr() const;
    const std::shared_ptr<protocol::BlockOrder> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::BlockOrder> m_impl;
};

}

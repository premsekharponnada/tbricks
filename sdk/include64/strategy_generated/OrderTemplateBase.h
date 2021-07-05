#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OrderTemplateBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class Currency;
class DirectedQuoteResponseGeneration;
class DirectedQuoteResponseIdentifier;
class ExecutionPolicy;
class ExtraData;
class HandlingInstruction;
class LiquidityPoolIdentifier;
class OrderCapacity;
class ParticipationPolicy;
class PostingActionType;
class PricePolicy;
class RegulatoryParameters;
class Side;
class StrategyParameters;
class String;
class TransitionType;
class TreeNodeIdentifier;
class Volume;
enum class PegPriceType;


namespace protocol { class Order; }

class STRATEGY_EXPORT OrderTemplateBase : public Printable
{
protected:
    OrderTemplateBase();
    OrderTemplateBase(const OrderTemplateBase & value);
    OrderTemplateBase(OrderTemplateBase && value) noexcept;
    OrderTemplateBase & operator=(const OrderTemplateBase & value);
    OrderTemplateBase & operator=(OrderTemplateBase && value) noexcept;
    virtual ~OrderTemplateBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSide() const;

    /**
     * Get side.
     *
     *
     * @return                          side
     */
    Side GetSide() const;

    /**
     * %Set side.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     side
     */
    void SetSide(const Side & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExecutionPolicy() const;

    /**
     * Get execution policy.
     *
     *
     * @return                          execution policy
     */
    ExecutionPolicy GetExecutionPolicy() const;

    /**
     * %Set execution policy.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     execution policy
     */
    void SetExecutionPolicy(const ExecutionPolicy & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPartialFillNotAllowed() const;

    /**
     * Get partial fill not allowed.
     *
     *
     * @return                          partial fill not allowed
     */
    Boolean GetPartialFillNotAllowed() const;

    /**
     * %Set partial fill not allowed.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     partial fill not allowed
     */
    void SetPartialFillNotAllowed(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandlingInstruction() const;

    /**
     * Get handling instruction.
     *
     *
     * @return                          handling instruction
     */
    HandlingInstruction GetHandlingInstruction() const;

    /**
     * %Set handling instruction.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     handling instruction
     */
    void SetHandlingInstruction(const HandlingInstruction & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPriceImprovementNotAllowed() const;

    /**
     * Get price improvement not allowed.
     *
     *
     * @return                          price improvement not allowed
     */
    Boolean GetPriceImprovementNotAllowed() const;

    /**
     * %Set price improvement not allowed.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     price improvement not allowed
     */
    void SetPriceImprovementNotAllowed(const Boolean & value);

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
    bool HasStrategyParameters() const;

    /**
     * Get strategy parameters.
     *
     *
     * @return                          strategy parameters
     */
    StrategyParameters GetStrategyParameters() const;

    /**
     * %Set strategy parameters.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     strategy parameters
     */
    void SetStrategyParameters(const StrategyParameters & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComment() const;

    /**
     * Get comment.
     *
     *
     * @return                          comment
     */
    String GetComment() const;

    /**
     * %Set comment.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     comment
     */
    void SetComment(const String & value);

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
    bool HasDisclosedVolume() const;

    /**
     * Get disclosed volume.
     *
     *
     * @return                          disclosed volume
     */
    Volume GetDisclosedVolume() const;

    /**
     * %Set disclosed volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     disclosed volume
     */
    void SetDisclosedVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTransitionType() const;

    /**
     * Get transition type.
     *
     *
     * @return                          transition type
     */
    TransitionType GetTransitionType() const;

    /**
     * %Set transition type.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     transition type
     */
    void SetTransitionType(const TransitionType & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMinimumAcceptableFillVolume() const;

    /**
     * Get minimum acceptable fill volume.
     *
     *
     * @return                          minimum acceptable fill volume
     */
    Volume GetMinimumAcceptableFillVolume() const;

    /**
     * %Set minimum acceptable fill volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     minimum acceptable fill volume
     */
    void SetMinimumAcceptableFillVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMinimumAcceptableVolume() const;

    /**
     * Get minimum acceptable volume.
     *
     *
     * @return                          minimum acceptable volume
     */
    Volume GetMinimumAcceptableVolume() const;

    /**
     * %Set minimum acceptable volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     minimum acceptable volume
     */
    void SetMinimumAcceptableVolume(const Volume & value);

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
    bool HasParticipationPolicy() const;

    /**
     * Get participation policy.
     *
     *
     * @return                          participation policy
     */
    ParticipationPolicy GetParticipationPolicy() const;

    /**
     * %Set participation policy.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     participation policy
     */
    void SetParticipationPolicy(const ParticipationPolicy & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasClient() const;

    /**
     * Get client.
     *
     *
     * @return                          client
     */
    TreeNodeIdentifier GetClient() const;

    /**
     * %Set client.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     client
     */
    void SetClient(const TreeNodeIdentifier & value);

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
    bool HasLiquidityPool() const;

    /**
     * Get liquidity pool identifier.
     *
     *
     * @return                          liquidity pool identifier
     */
    LiquidityPoolIdentifier GetLiquidityPool() const;

    /**
     * %Set liquidity pool identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     liquidity pool identifier
     */
    void SetLiquidityPool(const LiquidityPoolIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteResponse() const;

    /**
     * Get directed quote response identifier.
     *
     *
     * @return                          directed quote response identifier
     */
    DirectedQuoteResponseIdentifier GetDirectedQuoteResponse() const;

    /**
     * %Set directed quote response identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote response identifier
     */
    void SetDirectedQuoteResponse(const DirectedQuoteResponseIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteResponseGeneration() const;

    /**
     * Get directed quote response generation.
     *
     *
     * @return                          directed quote response generation
     */
    DirectedQuoteResponseGeneration GetDirectedQuoteResponseGeneration() const;

    /**
     * %Set directed quote response generation.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote response generation
     */
    void SetDirectedQuoteResponseGeneration(const DirectedQuoteResponseGeneration & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPostingAction() const;

    /**
     * Get posting action.
     *
     *
     * @return                          posting action
     */
    PostingActionType GetPostingAction() const;

    /**
     * %Set posting action.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     posting action
     */
    void SetPostingAction(const PostingActionType & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPegPriceType() const;

    /**
     * Get peg price type.
     *
     *
     * @return                          peg price type
     */
    std::optional<PegPriceType> GetPegPriceType() const;

    /**
     * %Set peg price type.
     *
     *
     * @param value                     peg price type
     */
    void SetPegPriceType(std::optional<PegPriceType> value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeDepthIdentifier() const;

    /**
     * Get venue depth identifier.
     *
     *
     * @return                          venue depth identifier
     */
    String GetExchangeDepthIdentifier() const;

    /**
     * %Set venue depth identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     venue depth identifier
     */
    void SetExchangeDepthIdentifier(const String & value);

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    OrderTemplateBase(const protocol::Order & value);
    OrderTemplateBase(std::shared_ptr<protocol::Order> && value);

    std::shared_ptr<protocol::Order> & get_impl_wr() const;
    const std::shared_ptr<protocol::Order> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Order> m_impl;
};

}

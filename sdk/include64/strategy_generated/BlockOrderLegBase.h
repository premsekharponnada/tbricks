#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BlockOrderLegBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class BlockOrderLegIdentifier;
class Boolean;
class Double;
class InstrumentIdentifier;
class LiquidityPoolIdentifier;
class ParticipationPolicy;
class PortfolioIdentifier;
class Price;
class PricePolicy;
class String;
class TransitionType;
class TreeNodeIdentifier;
class Volume;


namespace protocol { class BlockOrderLeg; }

class STRATEGY_EXPORT BlockOrderLegBase : public Printable
{
protected:
    BlockOrderLegBase();
    BlockOrderLegBase(const BlockOrderLegBase & value);
    BlockOrderLegBase(BlockOrderLegBase && value) noexcept;
    BlockOrderLegBase & operator=(const BlockOrderLegBase & value);
    BlockOrderLegBase & operator=(BlockOrderLegBase && value) noexcept;
    virtual ~BlockOrderLegBase();

public:
    /**
     * Get block order leg identifier.
     *
     *
     * @return                          block order leg identifier
     */
    BlockOrderLegIdentifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasActiveVolume() const;

    /**
     * Get active volume.
     *
     *
     * @return                          active volume
     */
    Volume GetActiveVolume() const;

    /**
     * %Set active volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     active volume
     */
    void SetActiveVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAveragePaid() const;

    /**
     * Get average paid.
     *
     *
     * @return                          average paid
     */
    Double GetAveragePaid() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAveragePaidVolume() const;

    /**
     * Get average paid volume.
     *
     *
     * @return                          average paid volume
     */
    Volume GetAveragePaidVolume() const;

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
    bool HasFilledVolume() const;

    /**
     * Get filled volume.
     *
     *
     * @return                          filled volume
     */
    Volume GetFilledVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInstrumentIdentifier() const;

    /**
     * Get instrument identifier.
     *
     *
     * @return                          instrument identifier
     */
    InstrumentIdentifier GetInstrumentIdentifier() const;

    /**
     * %Set instrument identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     instrument identifier
     */
    void SetInstrumentIdentifier(const InstrumentIdentifier & value);

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
    bool HasStopPrice() const;

    /**
     * Get stop price.
     *
     *
     * @return                          stop price
     */
    Price GetStopPrice() const;

    /**
     * %Set stop price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     stop price
     */
    void SetStopPrice(const Price & value);

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
    Price GetTargetPrice() const;

    /**
     * %Set target price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     target price
     */
    void SetTargetPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTotalVolume() const;

    /**
     * Get total volume.
     *
     *
     * @return                          total volume
     */
    Volume GetTotalVolume() const;

    /**
     * %Set total volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     total volume
     */
    void SetTotalVolume(const Volume & value);

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
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPortfolioIdentifier() const;

    /**
     * Get portfolio identifier.
     *
     *
     * @return                          portfolio identifier
     */
    PortfolioIdentifier GetPortfolioIdentifier() const;

    /**
     * %Set portfolio identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     portfolio identifier
     */
    void SetPortfolioIdentifier(const PortfolioIdentifier & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    BlockOrderLegBase(const protocol::BlockOrderLeg & value);
    BlockOrderLegBase(std::shared_ptr<protocol::BlockOrderLeg> && value);

    std::shared_ptr<protocol::BlockOrderLeg> & get_impl_wr() const;
    const std::shared_ptr<protocol::BlockOrderLeg> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::BlockOrderLeg> m_impl;
};

}

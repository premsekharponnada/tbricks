#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteRequestOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class CounterpartInformation;
class Currency;
class DirectedQuoteRequestLeg;
class ExtraData;
class HandlingInstruction;
class Identifier;
class LiquidityPoolIdentifier;
class Price;
class RegulatoryParameters;
class Side;
class StrategyParameters;
class String;
class TreeNodeIdentifier;
class Volume;
enum class DirectedRequestForQuoteRejectReason;


namespace protocol { class DirectedQuoteRequestRequest; }

class STRATEGY_EXPORT DirectedQuoteRequestOptionsBase : public Printable
{
protected:
    DirectedQuoteRequestOptionsBase();
    DirectedQuoteRequestOptionsBase(const DirectedQuoteRequestOptionsBase & value);
    DirectedQuoteRequestOptionsBase(DirectedQuoteRequestOptionsBase && value) noexcept;
    DirectedQuoteRequestOptionsBase & operator=(const DirectedQuoteRequestOptionsBase & value);
    DirectedQuoteRequestOptionsBase & operator=(DirectedQuoteRequestOptionsBase && value) noexcept;
    virtual ~DirectedQuoteRequestOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolume() const;

    /**
     * Get volume.
     *
     *
     * @return                          volume
     */
    Volume GetVolume() const;

    /**
     * %Set volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     volume
     */
    void SetVolume(const Volume & value);

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
    bool HasIsFirm() const;

    /**
     * Get is firm.
     *
     *
     * @return                          is firm
     */
    Boolean GetIsFirm() const;

    /**
     * %Set is firm.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     is firm
     */
    void SetIsFirm(const Boolean & value);

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
    bool HasRequestedBidPrice() const;

    /**
     * Get requested bid price.
     *
     *
     * @return                          requested bid price
     */
    Price GetRequestedBidPrice() const;

    /**
     * %Set requested bid price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     requested bid price
     */
    void SetRequestedBidPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestedAskPrice() const;

    /**
     * Get requested ask price.
     *
     *
     * @return                          requested ask price
     */
    Price GetRequestedAskPrice() const;

    /**
     * %Set requested ask price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     requested ask price
     */
    void SetRequestedAskPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLegs() const;

    /**
     * Get directed quote request legs.
     *
     *
     * @return                          directed quote request legs
     */
    std::vector<DirectedQuoteRequestLeg> GetLegs() const;

    /**
     * %Set directed quote request legs.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     directed quote request legs
     */
    void SetLegs(const std::vector<DirectedQuoteRequestLeg> & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpartiesInformation() const;

    /**
     * Get counterparties information.
     *
     *
     * @return                          counterparties information
     */
    std::vector<CounterpartInformation> GetCounterpartiesInformation() const;

    /**
     * %Set counterparties information.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     counterparties information
     */
    void SetCounterpartiesInformation(const std::vector<CounterpartInformation> & value);

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
    bool HasRejectReason() const;

    /**
     * Get directed request for quote reject reason.
     *
     *
     * @return                          directed request for quote reject reason
     */
    std::optional<DirectedRequestForQuoteRejectReason> GetRejectReason() const;

    /**
     * %Set directed request for quote reject reason.
     *
     *
     * @param value                     directed request for quote reject reason
     */
    void SetRejectReason(std::optional<DirectedRequestForQuoteRejectReason> value);

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
    bool HasNegotiateDelta() const;

    /**
     * Get negotiate delta.
     *
     *
     * @return                          negotiate delta
     */
    Boolean GetNegotiateDelta() const;

    /**
     * %Set negotiate delta.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     negotiate delta
     */
    void SetNegotiateDelta(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasNegotiateUnderlyingPriceLevel() const;

    /**
     * Get negotiate underlying price level.
     *
     *
     * @return                          negotiate underlying price level
     */
    Boolean GetNegotiateUnderlyingPriceLevel() const;

    /**
     * %Set negotiate underlying price level.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     negotiate underlying price level
     */
    void SetNegotiateUnderlyingPriceLevel(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequoteAllowed() const;

    /**
     * Get requote allowed.
     *
     *
     * @return                          requote allowed
     */
    Boolean GetRequoteAllowed() const;

    /**
     * %Set requote allowed.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     requote allowed
     */
    void SetRequoteAllowed(const Boolean & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    DirectedQuoteRequestOptionsBase(const protocol::DirectedQuoteRequestRequest & value);
    DirectedQuoteRequestOptionsBase(std::unique_ptr<protocol::DirectedQuoteRequestRequest> && value);

    std::unique_ptr<protocol::DirectedQuoteRequestRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::DirectedQuoteRequestRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::DirectedQuoteRequestRequest> m_impl;
};

}

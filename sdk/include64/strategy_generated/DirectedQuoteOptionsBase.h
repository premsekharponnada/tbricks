#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class ExtraData;
class OrderCapacity;
class PortfolioIdentifier;
class Price;
class RegulatoryParameters;
class String;
class TreeNodeIdentifier;
class Volume;


namespace protocol { class DirectedQuote; }

class STRATEGY_EXPORT DirectedQuoteOptionsBase : public Printable
{
protected:
    DirectedQuoteOptionsBase();
    DirectedQuoteOptionsBase(const DirectedQuoteOptionsBase & value);
    DirectedQuoteOptionsBase(DirectedQuoteOptionsBase && value) noexcept;
    DirectedQuoteOptionsBase & operator=(const DirectedQuoteOptionsBase & value);
    DirectedQuoteOptionsBase & operator=(DirectedQuoteOptionsBase && value) noexcept;
    virtual ~DirectedQuoteOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidPrice() const;

    /**
     * Get bid price.
     *
     *
     * @return                          bid price
     */
    Price GetBidPrice() const;

    /**
     * %Set bid price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     bid price
     */
    void SetBidPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskPrice() const;

    /**
     * Get ask price.
     *
     *
     * @return                          ask price
     */
    Price GetAskPrice() const;

    /**
     * %Set ask price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ask price
     */
    void SetAskPrice(const Price & value);

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
    bool HasBidActiveVolume() const;

    /**
     * Get bid active volume.
     *
     *
     * @return                          bid active volume
     */
    Volume GetBidActiveVolume() const;

    /**
     * %Set bid active volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     bid active volume
     */
    void SetBidActiveVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidFilledVolume() const;

    /**
     * Get bid filled volume.
     *
     *
     * @return                          bid filled volume
     */
    Volume GetBidFilledVolume() const;

    /**
     * %Set bid filled volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     bid filled volume
     */
    void SetBidFilledVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidTotalVolume() const;

    /**
     * Get bid volume.
     *
     *
     * @return                          bid volume
     */
    Volume GetBidTotalVolume() const;

    /**
     * %Set bid volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     bid volume
     */
    void SetBidTotalVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskActiveVolume() const;

    /**
     * Get ask active volume.
     *
     *
     * @return                          ask active volume
     */
    Volume GetAskActiveVolume() const;

    /**
     * %Set ask active volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ask active volume
     */
    void SetAskActiveVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskFilledVolume() const;

    /**
     * Get ask filled volume.
     *
     *
     * @return                          ask filled volume
     */
    Volume GetAskFilledVolume() const;

    /**
     * %Set ask filled volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ask filled volume
     */
    void SetAskFilledVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskTotalVolume() const;

    /**
     * Get ask volume.
     *
     *
     * @return                          ask volume
     */
    Volume GetAskTotalVolume() const;

    /**
     * %Set ask volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ask volume
     */
    void SetAskTotalVolume(const Volume & value);

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    DirectedQuoteOptionsBase(const protocol::DirectedQuote & value);
    DirectedQuoteOptionsBase(std::unique_ptr<protocol::DirectedQuote> && value);

    std::unique_ptr<protocol::DirectedQuote> & get_impl_wr() const;
    const std::unique_ptr<protocol::DirectedQuote> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::DirectedQuote> m_impl;
};

}

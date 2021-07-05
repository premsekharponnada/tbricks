#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteModifierBase object
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
class Price;
class RegulatoryParameters;
class Volume;


namespace protocol { class DirectedQuoteModifyRequest; }

class STRATEGY_EXPORT DirectedQuoteModifierBase : public Printable
{
protected:
    DirectedQuoteModifierBase();
    DirectedQuoteModifierBase(const DirectedQuoteModifierBase & value);
    DirectedQuoteModifierBase(DirectedQuoteModifierBase && value) noexcept;
    DirectedQuoteModifierBase & operator=(const DirectedQuoteModifierBase & value);
    DirectedQuoteModifierBase & operator=(DirectedQuoteModifierBase && value) noexcept;
    virtual ~DirectedQuoteModifierBase();

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
     * @throw Exception if passed value is empty
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
     * @throw Exception if passed value is empty
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
     * @throw Exception if passed value is empty
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
     * @throw Exception if passed value is empty
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
     * @throw Exception if passed value is empty
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
     * @throw Exception if passed value is empty
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
     * @throw Exception if passed value is empty
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
    DirectedQuoteModifierBase(const protocol::DirectedQuoteModifyRequest & value);
    DirectedQuoteModifierBase(std::unique_ptr<protocol::DirectedQuoteModifyRequest> && value);

    std::unique_ptr<protocol::DirectedQuoteModifyRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::DirectedQuoteModifyRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::DirectedQuoteModifyRequest> m_impl;
};

}

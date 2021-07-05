#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExPitDealBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class DateTime;
class Double;
class ExPitDealIdentifier;
class ExPitParty;
class MMTFlags;
class Price;
class Volume;


namespace protocol { class ExpitDeal; }

class STRATEGY_EXPORT ExPitDealBase : public Printable
{
protected:
    ExPitDealBase();
    ExPitDealBase(const ExPitDealBase & value);
    ExPitDealBase(ExPitDealBase && value) noexcept;
    ExPitDealBase & operator=(const ExPitDealBase & value);
    ExPitDealBase & operator=(ExPitDealBase && value) noexcept;
    virtual ~ExPitDealBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get expit deal identifier.
     *
     *
     * @return                          expit deal identifier
     */
    ExPitDealIdentifier GetIdentifier() const;

    /**
     * %Set expit deal identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expit deal identifier
     */
    void SetIdentifier(const ExPitDealIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAgreementDatetime() const;

    /**
     * Get agreement datetime.
     *
     *
     * @return                          agreement datetime
     */
    DateTime GetAgreementDatetime() const;

    /**
     * %Set agreement datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     agreement datetime
     */
    void SetAgreementDatetime(const DateTime & value);

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
    bool HasMMTFlags() const;

    /**
     * Get market model typology.
     *
     *
     * @return                          market model typology
     */
    MMTFlags GetMMTFlags() const;

    /**
     * %Set market model typology.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     market model typology
     */
    void SetMMTFlags(const MMTFlags & value);

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
    bool HasBuyer() const;

    /**
     * Get expit buyer.
     *
     *
     * @return                          expit buyer
     */
    ExPitParty GetBuyer() const;

    /**
     * %Set expit buyer.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expit buyer
     */
    void SetBuyer(const ExPitParty & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSeller() const;

    /**
     * Get expit seller.
     *
     *
     * @return                          expit seller
     */
    ExPitParty GetSeller() const;

    /**
     * %Set expit seller.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expit seller
     */
    void SetSeller(const ExPitParty & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    ExPitDealBase(const protocol::ExpitDeal & value);
    ExPitDealBase(std::shared_ptr<protocol::ExpitDeal> && value);

    std::shared_ptr<protocol::ExpitDeal> & get_impl_wr() const;
    const std::shared_ptr<protocol::ExpitDeal> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::ExpitDeal> m_impl;
};

}

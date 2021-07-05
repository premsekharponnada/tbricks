#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DeliveryOperationBase object
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
class DateTime;
class Double;
class Identifier;
class InstrumentIdentifier;
class MIC;
class PortfolioIdentifier;
class Price;
class VenueIdentifier;
class Volume;


namespace protocol { class ExpirationDeliveryOperation; }

class STRATEGY_EXPORT DeliveryOperationBase : public Printable
{
protected:
    DeliveryOperationBase();
    DeliveryOperationBase(const DeliveryOperationBase & value);
    DeliveryOperationBase(DeliveryOperationBase && value) noexcept;
    DeliveryOperationBase & operator=(const DeliveryOperationBase & value);
    DeliveryOperationBase & operator=(DeliveryOperationBase && value) noexcept;
    virtual ~DeliveryOperationBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExpirationDeliveryIdentifier() const;

    /**
     * Get expiration delivery identifier.
     *
     *
     * @return                          expiration delivery identifier
     */
    Identifier GetExpirationDeliveryIdentifier() const;

    /**
     * %Set expiration delivery identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expiration delivery identifier
     */
    void SetExpirationDeliveryIdentifier(const Identifier & value);

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
    bool HasExpirationPrice() const;

    /**
     * Get expiration price.
     *
     *
     * @return                          expiration price
     */
    Price GetExpirationPrice() const;

    /**
     * %Set expiration price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expiration price
     */
    void SetExpirationPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCurrency() const;

    /**
     * Get currency.
     *
     *
     * @return                          currency
     */
    Currency GetCurrency() const;

    /**
     * %Set currency.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     currency
     */
    void SetCurrency(const Currency & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradeByTradeDelivery() const;

    /**
     * Get trade by trade delivery.
     *
     *
     * @return                          trade by trade delivery
     */
    Boolean GetTradeByTradeDelivery() const;

    /**
     * %Set trade by trade delivery.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     trade by trade delivery
     */
    void SetTradeByTradeDelivery(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasResidualCashApplicable() const;

    /**
     * Get residual cash applicable.
     *
     *
     * @return                          residual cash applicable
     */
    Boolean GetResidualCashApplicable() const;

    /**
     * %Set residual cash applicable.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     residual cash applicable
     */
    void SetResidualCashApplicable(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExpirationVolume() const;

    /**
     * Get expiration volume.
     *
     *
     * @return                          expiration volume
     */
    Volume GetExpirationVolume() const;

    /**
     * %Set expiration volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expiration volume
     */
    void SetExpirationVolume(const Volume & value);

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
    bool HasOrderValueFactor() const;

    /**
     * Get order value factor.
     *
     *
     * @return                          order value factor
     */
    Double GetOrderValueFactor() const;

    /**
     * %Set order value factor.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     order value factor
     */
    void SetOrderValueFactor(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMultiplier() const;

    /**
     * Get multiplier.
     *
     *
     * @return                          multiplier
     */
    Double GetMultiplier() const;

    /**
     * %Set multiplier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     multiplier
     */
    void SetMultiplier(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUnderlyingInstrumentIdentifier() const;

    /**
     * Get underlying instrument identifier.
     *
     *
     * @return                          underlying instrument identifier
     */
    InstrumentIdentifier GetUnderlyingInstrumentIdentifier() const;

    /**
     * %Set underlying instrument identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     underlying instrument identifier
     */
    void SetUnderlyingInstrumentIdentifier(const InstrumentIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUnderlyingPrice() const;

    /**
     * Get underlying price.
     *
     *
     * @return                          underlying price
     */
    Price GetUnderlyingPrice() const;

    /**
     * %Set underlying price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     underlying price
     */
    void SetUnderlyingPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUnderlyingVolume() const;

    /**
     * Get underlying volume.
     *
     *
     * @return                          underlying volume
     */
    Volume GetUnderlyingVolume() const;

    /**
     * %Set underlying volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     underlying volume
     */
    void SetUnderlyingVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUnderlyingOrderValueFactor() const;

    /**
     * Get underlying order value factor.
     *
     *
     * @return                          underlying order value factor
     */
    Double GetUnderlyingOrderValueFactor() const;

    /**
     * %Set underlying order value factor.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     underlying order value factor
     */
    void SetUnderlyingOrderValueFactor(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUnderlyingMultiplier() const;

    /**
     * Get underlying multiplier.
     *
     *
     * @return                          underlying multiplier
     */
    Double GetUnderlyingMultiplier() const;

    /**
     * %Set underlying multiplier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     underlying multiplier
     */
    void SetUnderlyingMultiplier(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCashValue() const;

    /**
     * Get cash value.
     *
     *
     * @return                          cash value
     */
    Double GetCashValue() const;

    /**
     * %Set cash value.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     cash value
     */
    void SetCashValue(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasResidualCashValue() const;

    /**
     * Get residual cash value.
     *
     *
     * @return                          residual cash value
     */
    Double GetResidualCashValue() const;

    /**
     * %Set residual cash value.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     residual cash value
     */
    void SetResidualCashValue(const Double & value);

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
    bool HasVenueIdentifier() const;

    /**
     * Get venue identifier.
     *
     *
     * @return                          venue identifier
     */
    VenueIdentifier GetVenueIdentifier() const;

    /**
     * %Set venue identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     venue identifier
     */
    void SetVenueIdentifier(const VenueIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMIC() const;

    /**
     * Get mic.
     *
     *
     * @return                          mic
     */
    MIC GetMIC() const;

    /**
     * %Set mic.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     mic
     */
    void SetMIC(const MIC & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUseVenueAndMicForDeliveryInstrument() const;

    /**
     * Get use venue and mic for delivery instrument.
     *
     *
     * @return                          use venue and mic for delivery instrument
     */
    Boolean GetUseVenueAndMicForDeliveryInstrument() const;

    /**
     * %Set use venue and mic for delivery instrument.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     use venue and mic for delivery instrument
     */
    void SetUseVenueAndMicForDeliveryInstrument(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasEarlyExercise() const;

    /**
     * Get early exercise.
     *
     *
     * @return                          early exercise
     */
    Boolean GetEarlyExercise() const;

    /**
     * %Set early exercise.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     early exercise
     */
    void SetEarlyExercise(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUnderlyingMIC() const;

    /**
     * Get underlying mic.
     *
     *
     * @return                          underlying mic
     */
    MIC GetUnderlyingMIC() const;

    /**
     * %Set underlying mic.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     underlying mic
     */
    void SetUnderlyingMIC(const MIC & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUnderlyingVenueIdentifier() const;

    /**
     * Get underlying venue identifier.
     *
     *
     * @return                          underlying venue identifier
     */
    VenueIdentifier GetUnderlyingVenueIdentifier() const;

    /**
     * %Set underlying venue identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     underlying venue identifier
     */
    void SetUnderlyingVenueIdentifier(const VenueIdentifier & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    DeliveryOperationBase(const protocol::ExpirationDeliveryOperation & value);
    DeliveryOperationBase(std::shared_ptr<protocol::ExpirationDeliveryOperation> && value);

    std::shared_ptr<protocol::ExpirationDeliveryOperation> & get_impl_wr() const;
    const std::shared_ptr<protocol::ExpirationDeliveryOperation> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::ExpirationDeliveryOperation> m_impl;
};

}

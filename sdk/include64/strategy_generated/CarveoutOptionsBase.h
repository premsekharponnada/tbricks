#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CarveoutOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Currency;
class Double;
class InstrumentGroupIdentifier;
class MIC;
class PortfolioIdentifier;
class TreeNodeIdentifier;
class VenueIdentifier;
class Volume;


namespace protocol { class Carveout; }

class STRATEGY_EXPORT CarveoutOptionsBase : public Printable
{
protected:
    CarveoutOptionsBase();
    CarveoutOptionsBase(const CarveoutOptionsBase & value);
    CarveoutOptionsBase(CarveoutOptionsBase && value) noexcept;
    CarveoutOptionsBase & operator=(const CarveoutOptionsBase & value);
    CarveoutOptionsBase & operator=(CarveoutOptionsBase && value) noexcept;
    virtual ~CarveoutOptionsBase();

public:
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
    bool HasInstrumentGroupIdentifier() const;

    /**
     * Get instrument group identifier.
     *
     *
     * @return                          instrument group identifier
     */
    InstrumentGroupIdentifier GetInstrumentGroupIdentifier() const;

    /**
     * %Set instrument group identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     instrument group identifier
     */
    void SetInstrumentGroupIdentifier(const InstrumentGroupIdentifier & value);

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
    bool HasBidTotalValue() const;

    /**
     * Get bid value.
     *
     *
     * @return                          bid value
     */
    Double GetBidTotalValue() const;

    /**
     * %Set bid value.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     bid value
     */
    void SetBidTotalValue(const Double & value);

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
    bool HasAskTotalValue() const;

    /**
     * Get ask value.
     *
     *
     * @return                          ask value
     */
    Double GetAskTotalValue() const;

    /**
     * %Set ask value.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ask value
     */
    void SetAskTotalValue(const Double & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    CarveoutOptionsBase(const protocol::Carveout & value);
    CarveoutOptionsBase(std::unique_ptr<protocol::Carveout> && value);

    std::unique_ptr<protocol::Carveout> & get_impl_wr() const;
    const std::unique_ptr<protocol::Carveout> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::Carveout> m_impl;
};

}

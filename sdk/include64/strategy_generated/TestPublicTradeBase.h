#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestPublicTradeBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class DateTime;
class ExtraData;
class MIC;
class MMTFlags;
class MarketDataParameters;
class Price;
class Side;
class String;
class Volume;


namespace protocol { class PublicTrade; }

class STRATEGY_EXPORT TestPublicTradeBase : public Printable
{
protected:
    TestPublicTradeBase();
    TestPublicTradeBase(const TestPublicTradeBase & value);
    TestPublicTradeBase(TestPublicTradeBase && value) noexcept;
    TestPublicTradeBase & operator=(const TestPublicTradeBase & value);
    TestPublicTradeBase & operator=(TestPublicTradeBase && value) noexcept;
    virtual ~TestPublicTradeBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get public trade identifier.
     *
     *
     * @return                          public trade identifier
     */
    String GetIdentifier() const;

    /**
     * %Set public trade identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     public trade identifier
     */
    void SetIdentifier(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAggressor() const;

    /**
     * Get aggressor.
     *
     *
     * @return                          aggressor
     */
    Side GetAggressor() const;

    /**
     * %Set aggressor.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     aggressor
     */
    void SetAggressor(const Side & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBuyer() const;

    /**
     * Get buyer.
     *
     *
     * @return                          buyer
     */
    String GetBuyer() const;

    /**
     * %Set buyer.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     buyer
     */
    void SetBuyer(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSeller() const;

    /**
     * Get seller.
     *
     *
     * @return                          seller
     */
    String GetSeller() const;

    /**
     * %Set seller.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     seller
     */
    void SetSeller(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStatusText() const;

    /**
     * Get status text.
     *
     *
     * @return                          status text
     */
    String GetStatusText() const;

    /**
     * %Set status text.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     status text
     */
    void SetStatusText(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVenueTradeConditions() const;

    /**
     * Get venue trade conditions.
     *
     *
     * @return                          venue trade conditions
     */
    ExtraData GetVenueTradeConditions() const;

    /**
     * %Set venue trade conditions.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     venue trade conditions
     */
    void SetVenueTradeConditions(const ExtraData & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangePublicTradeIdentifier() const;

    /**
     * Get exchange trade identifier.
     *
     *
     * @return                          exchange trade identifier
     */
    String GetExchangePublicTradeIdentifier() const;

    /**
     * %Set exchange trade identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange trade identifier
     */
    void SetExchangePublicTradeIdentifier(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeOrderIdentifier() const;

    /**
     * Get exchange order reference.
     *
     *
     * @return                          exchange order reference
     */
    String GetExchangeOrderIdentifier() const;

    /**
     * %Set exchange order reference.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange order reference
     */
    void SetExchangeOrderIdentifier(const String & value);

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
    bool HasOffMarket() const;

    /**
     * Get off market.
     *
     *
     * @return                          off market
     */
    Boolean GetOffMarket() const;

    /**
     * %Set off market.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     off market
     */
    void SetOffMarket(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostCreatedDatetime() const;

    /**
     * Get host created datetime.
     *
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDatetime() const;

    /**
     * %Set host created datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host created datetime
     */
    void SetHostCreatedDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeCreatedDatetime() const;

    /**
     * Get exchange created datetime.
     *
     *
     * @return                          exchange created datetime
     */
    DateTime GetExchangeCreatedDatetime() const;

    /**
     * %Set exchange created datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange created datetime
     */
    void SetExchangeCreatedDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMarketModelTypology() const;

    /**
     * Get market model typology.
     *
     *
     * @return                          market model typology
     */
    MMTFlags GetMarketModelTypology() const;

    /**
     * %Set market model typology.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     market model typology
     */
    void SetMarketModelTypology(const MMTFlags & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParameters() const;

    /**
     * Get market data parameters.
     *
     *
     * @return                          market data parameters
     */
    MarketDataParameters GetParameters() const;

    /**
     * %Set market data parameters.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     market data parameters
     */
    void SetParameters(const MarketDataParameters & value);

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const TestPublicTradeBase & update);

/** @cond PRIVATE */
public:
    TestPublicTradeBase(const protocol::PublicTrade & value);
    TestPublicTradeBase(std::shared_ptr<protocol::PublicTrade> && value);

    std::shared_ptr<protocol::PublicTrade> & get_impl_wr() const;
    const std::shared_ptr<protocol::PublicTrade> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::PublicTrade> m_impl;
};

}

#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BestPriceBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class DateTime;
class Integer;
class MarketDataParameters;
class Price;
class Trend;
class Volume;


namespace protocol { class BestPrice; }

class STRATEGY_EXPORT BestPriceBase : public Printable
{
protected:
    BestPriceBase();
    BestPriceBase(const BestPriceBase & value);
    BestPriceBase(BestPriceBase && value) noexcept;
    BestPriceBase & operator=(const BestPriceBase & value);
    BestPriceBase & operator=(BestPriceBase && value) noexcept;
    virtual ~BestPriceBase();

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
    bool HasBidVolume() const;

    /**
     * Get bid volume.
     *
     *
     * @return                          bid volume
     */
    Volume GetBidVolume() const;

    /**
     * %Set bid volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     bid volume
     */
    void SetBidVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskVolume() const;

    /**
     * Get ask volume.
     *
     *
     * @return                          ask volume
     */
    Volume GetAskVolume() const;

    /**
     * %Set ask volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ask volume
     */
    void SetAskVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidOrderCount() const;

    /**
     * Get bid order count.
     *
     *
     * @return                          bid order count
     */
    Integer GetBidOrderCount() const;

    /**
     * %Set bid order count.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     bid order count
     */
    void SetBidOrderCount(const Integer & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskOrderCount() const;

    /**
     * Get ask order count.
     *
     *
     * @return                          ask order count
     */
    Integer GetAskOrderCount() const;

    /**
     * %Set ask order count.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ask order count
     */
    void SetAskOrderCount(const Integer & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidPriceImplied() const;

    /**
     * Get bid price implied.
     *
     *
     * @return                          bid price implied
     */
    Price GetBidPriceImplied() const;

    /**
     * %Set bid price implied.
     *
     *    
     *  
     * @param value                     bid price implied
     */
    void SetBidPriceImplied(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskPriceImplied() const;

    /**
     * Get ask price implied.
     *
     *
     * @return                          ask price implied
     */
    Price GetAskPriceImplied() const;

    /**
     * %Set ask price implied.
     *
     *    
     *  
     * @param value                     ask price implied
     */
    void SetAskPriceImplied(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidVolumeImplied() const;

    /**
     * Get bid volume implied.
     *
     *
     * @return                          bid volume implied
     */
    Volume GetBidVolumeImplied() const;

    /**
     * %Set bid volume implied.
     *
     *    
     *  
     * @param value                     bid volume implied
     */
    void SetBidVolumeImplied(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskVolumeImplied() const;

    /**
     * Get ask volume implied.
     *
     *
     * @return                          ask volume implied
     */
    Volume GetAskVolumeImplied() const;

    /**
     * %Set ask volume implied.
     *
     *    
     *  
     * @param value                     ask volume implied
     */
    void SetAskVolumeImplied(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidTrend() const;

    /**
     * Get bid trend.
     *
     *
     * @return                          bid trend
     */
    Trend GetBidTrend() const;

    /**
     * %Set bid trend.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     bid trend
     */
    void SetBidTrend(const Trend & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskTrend() const;

    /**
     * Get ask trend.
     *
     *
     * @return                          ask trend
     */
    Trend GetAskTrend() const;

    /**
     * %Set ask trend.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ask trend
     */
    void SetAskTrend(const Trend & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostModifiedDateTime() const;

    /**
     * Get host modified datetime.
     *
     *
     * @return                          host modified datetime
     */
    DateTime GetHostModifiedDateTime() const;

    /**
     * %Set host modified datetime.
     *
     *    
     *  
     * @param value                     host modified datetime
     */
    void SetHostModifiedDateTime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMarketDataParameters() const;

    /**
     * Get market data parameters.
     *
     *
     * @return                          market data parameters
     */
    MarketDataParameters GetMarketDataParameters() const;

    /**
     * %Set market data parameters.
     *
     *    
     *  
     * @param value                     market data parameters
     */
    void SetMarketDataParameters(const MarketDataParameters & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeModifiedDatetime() const;

    /**
     * Get exchange modified datetime.
     *
     *
     * @return                          exchange modified datetime
     */
    DateTime GetExchangeModifiedDatetime() const;

    /**
     * %Set exchange modified datetime.
     *
     *    
     *  
     * @param value                     exchange modified datetime
     */
    void SetExchangeModifiedDatetime(const DateTime & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const BestPriceBase & update);

/** @cond PRIVATE */
public:
    BestPriceBase(const protocol::BestPrice & value);
    BestPriceBase(std::shared_ptr<protocol::BestPrice> && value);

    std::shared_ptr<protocol::BestPrice> & get_impl_wr() const;
    const std::shared_ptr<protocol::BestPrice> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::BestPrice> m_impl;
};

}

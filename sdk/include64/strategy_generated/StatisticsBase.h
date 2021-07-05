#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StatisticsBase object
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
class Double;
class Integer;
class MarketDataParameters;
class Price;
class Trend;
class Volume;


namespace protocol { class Statistics; }

class STRATEGY_EXPORT StatisticsBase : public Printable
{
protected:
    StatisticsBase();
    StatisticsBase(const StatisticsBase & value);
    StatisticsBase(StatisticsBase && value) noexcept;
    StatisticsBase & operator=(const StatisticsBase & value);
    StatisticsBase & operator=(StatisticsBase && value) noexcept;
    virtual ~StatisticsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasClosingPrice() const;

    /**
     * Get closing price.
     *
     *
     * @return                          closing price
     */
    Price GetClosingPrice() const;

    /**
     * %Set closing price.
     *
     *    
     *  
     * @param value                     closing price
     */
    void SetClosingPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPreviousClosingPrice() const;

    /**
     * Get previous closing price.
     *
     *
     * @return                          previous closing price
     */
    Price GetPreviousClosingPrice() const;

    /**
     * %Set previous closing price.
     *
     *    
     *  
     * @param value                     previous closing price
     */
    void SetPreviousClosingPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDailySettlementPrice() const;

    /**
     * Get daily settlement price.
     *
     *
     * @return                          daily settlement price
     */
    Price GetDailySettlementPrice() const;

    /**
     * %Set daily settlement price.
     *
     *    
     *  
     * @param value                     daily settlement price
     */
    void SetDailySettlementPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPreviousSettlementPrice() const;

    /**
     * Get previous settlement price.
     *
     *
     * @return                          previous settlement price
     */
    Price GetPreviousSettlementPrice() const;

    /**
     * %Set previous settlement price.
     *
     *    
     *  
     * @param value                     previous settlement price
     */
    void SetPreviousSettlementPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHighPrice() const;

    /**
     * Get high price.
     *
     *
     * @return                          high price
     */
    Price GetHighPrice() const;

    /**
     * %Set high price.
     *
     *    
     *  
     * @param value                     high price
     */
    void SetHighPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastPrice() const;

    /**
     * Get last price.
     *
     *
     * @return                          last price
     */
    Price GetLastPrice() const;

    /**
     * %Set last price.
     *
     *    
     *  
     * @param value                     last price
     */
    void SetLastPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastVolume() const;

    /**
     * Get last volume.
     *
     *
     * @return                          last volume
     */
    Volume GetLastVolume() const;

    /**
     * %Set last volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     last volume
     */
    void SetLastVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastTrend() const;

    /**
     * Get last trend.
     *
     *
     * @return                          last trend
     */
    Trend GetLastTrend() const;

    /**
     * %Set last trend.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     last trend
     */
    void SetLastTrend(const Trend & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLowPrice() const;

    /**
     * Get low price.
     *
     *
     * @return                          low price
     */
    Price GetLowPrice() const;

    /**
     * %Set low price.
     *
     *    
     *  
     * @param value                     low price
     */
    void SetLowPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOpenInterest() const;

    /**
     * Get open interest.
     *
     *
     * @return                          open interest
     */
    Integer GetOpenInterest() const;

    /**
     * %Set open interest.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     open interest
     */
    void SetOpenInterest(const Integer & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOpeningPrice() const;

    /**
     * Get opening price.
     *
     *
     * @return                          opening price
     */
    Price GetOpeningPrice() const;

    /**
     * %Set opening price.
     *
     *    
     *  
     * @param value                     opening price
     */
    void SetOpeningPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTurnover() const;

    /**
     * Get turnover.
     *
     *
     * @return                          turnover
     */
    Double GetTurnover() const;

    /**
     * %Set turnover.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     turnover
     */
    void SetTurnover(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTurnoverVolume() const;

    /**
     * Get turnover volume.
     *
     *
     * @return                          turnover volume
     */
    Volume GetTurnoverVolume() const;

    /**
     * %Set turnover volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     turnover volume
     */
    void SetTurnoverVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     * The indicative auction price is the current price that an auction
     * would be uncrossed at if it was done at this point in time. It
     * will continuously update during the auction process. This price
     * is for some markets called the indicative uncrossing price
     * (e.g. LSE/SETS). Returns Indicative auction price or empty
     * object if the price is not available.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIndicativeAuctionPrice() const;

    /**
     * Get indicative auction price.
     *
     * The indicative auction price is the current price that an auction
     * would be uncrossed at if it was done at this point in time. It
     * will continuously update during the auction process. This price
     * is for some markets called the indicative uncrossing price
     * (e.g. LSE/SETS). Returns Indicative auction price or empty
     * object if the price is not available.
     *
     *
     * @return                          indicative auction price
     */
    Price GetIndicativeAuctionPrice() const;

    /**
     * %Set indicative auction price.
     *
     * The indicative auction price is the current price that an auction
     * would be uncrossed at if it was done at this point in time. It
     * will continuously update during the auction process. This price
     * is for some markets called the indicative uncrossing price
     * (e.g. LSE/SETS). Returns Indicative auction price or empty
     * object if the price is not available.
     *
     *    
     *  
     * @param value                     indicative auction price
     */
    void SetIndicativeAuctionPrice(const Price & value);

    /**
     * Check if field is set.
     *
     * The indicative auction volume is the volume that the current price
     * that an auction would generate of it were to uncross at that
     * point in time. It will continuously update during the auction
     * process, normally at a fixed time interval. Indicative auction
     * volume or empty object if the price is not available.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIndicativeAuctionVolume() const;

    /**
     * Get indicative auction volume.
     *
     * The indicative auction volume is the volume that the current price
     * that an auction would generate of it were to uncross at that
     * point in time. It will continuously update during the auction
     * process, normally at a fixed time interval. Indicative auction
     * volume or empty object if the price is not available.
     *
     *
     * @return                          indicative auction volume
     */
    Volume GetIndicativeAuctionVolume() const;

    /**
     * %Set indicative auction volume.
     *
     * The indicative auction volume is the volume that the current price
     * that an auction would generate of it were to uncross at that
     * point in time. It will continuously update during the auction
     * process, normally at a fixed time interval. Indicative auction
     * volume or empty object if the price is not available.
     *
     *    
     *  
     * @param value                     indicative auction volume
     */
    void SetIndicativeAuctionVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     * The indicative auction surplus volume is the volume that would
     * remain after an auction at the current price were to uncross at
     * that point in time. It will continuously update during the
     * auction process, normally at a fixed time interval. Indicative
     * auction surplus volume or empty object if the price is not
     * available.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIndicativeAuctionSurplusVolume() const;

    /**
     * Get indicative auction surplus volume.
     *
     * The indicative auction surplus volume is the volume that would
     * remain after an auction at the current price were to uncross at
     * that point in time. It will continuously update during the
     * auction process, normally at a fixed time interval. Indicative
     * auction surplus volume or empty object if the price is not
     * available.
     *
     *
     * @return                          indicative auction surplus volume
     */
    Volume GetIndicativeAuctionSurplusVolume() const;

    /**
     * %Set indicative auction surplus volume.
     *
     * The indicative auction surplus volume is the volume that would
     * remain after an auction at the current price were to uncross at
     * that point in time. It will continuously update during the
     * auction process, normally at a fixed time interval. Indicative
     * auction surplus volume or empty object if the price is not
     * available.
     *
     *    
     *  
     * @param value                     indicative auction surplus volume
     */
    void SetIndicativeAuctionSurplusVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastAuctionPrice() const;

    /**
     * Get last auction price.
     *
     *
     * @return                          last auction price
     */
    Price GetLastAuctionPrice() const;

    /**
     * %Set last auction price.
     *
     *    
     *  
     * @param value                     last auction price
     */
    void SetLastAuctionPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastAuctionVolume() const;

    /**
     * Get last auction volume.
     *
     *
     * @return                          last auction volume
     */
    Volume GetLastAuctionVolume() const;

    /**
     * %Set last auction volume.
     *
     *    
     *  
     * @param value                     last auction volume
     */
    void SetLastAuctionVolume(const Volume & value);

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
     * Indicates that some or all statistics fields might be incorrect due
     * to inability of market data service to recover them from venue.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUnreliable() const;

    /**
     * Get unreliable.
     *
     * Indicates that some or all statistics fields might be incorrect due
     * to inability of market data service to recover them from venue.
     *
     *
     * @return                          unreliable
     */
    Boolean GetUnreliable() const;

    /**
     * %Set unreliable.
     *
     * Indicates that some or all statistics fields might be incorrect due
     * to inability of market data service to recover them from venue.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     unreliable
     */
    void SetUnreliable(const Boolean & value);

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
    void Merge(const StatisticsBase & update);

/** @cond PRIVATE */
public:
    StatisticsBase(const protocol::Statistics & value);
    StatisticsBase(std::shared_ptr<protocol::Statistics> && value);

    std::shared_ptr<protocol::Statistics> & get_impl_wr() const;
    const std::shared_ptr<protocol::Statistics> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Statistics> m_impl;
};

}

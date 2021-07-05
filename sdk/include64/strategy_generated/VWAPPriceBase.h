#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VWAPPriceBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class DateTime;
class Price;
class Volume;


namespace protocol { class Vwap; }

class STRATEGY_EXPORT VWAPPriceBase : public Printable
{
protected:
    VWAPPriceBase();
    VWAPPriceBase(const VWAPPriceBase & value);
    VWAPPriceBase(VWAPPriceBase && value) noexcept;
    VWAPPriceBase & operator=(const VWAPPriceBase & value);
    VWAPPriceBase & operator=(VWAPPriceBase && value) noexcept;
    virtual ~VWAPPriceBase();

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
    bool HasWorstBidPrice() const;

    /**
     * Get worst bid price for vwap.
     *
     *
     * @return                          worst bid price for vwap
     */
    Price GetWorstBidPrice() const;

    /**
     * %Set worst bid price for vwap.
     *
     *    
     *  
     * @param value                     worst bid price for vwap
     */
    void SetWorstBidPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasWorstAskPrice() const;

    /**
     * Get worst ask price for vwap.
     *
     *
     * @return                          worst ask price for vwap
     */
    Price GetWorstAskPrice() const;

    /**
     * %Set worst ask price for vwap.
     *
     *    
     *  
     * @param value                     worst ask price for vwap
     */
    void SetWorstAskPrice(const Price & value);

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
    void Merge(const VWAPPriceBase & update);

/** @cond PRIVATE */
public:
    VWAPPriceBase(const protocol::Vwap & value);
    VWAPPriceBase(std::shared_ptr<protocol::Vwap> && value);

    std::shared_ptr<protocol::Vwap> & get_impl_wr() const;
    const std::shared_ptr<protocol::Vwap> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Vwap> m_impl;
};

}

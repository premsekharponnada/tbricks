#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteLegBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Currency;
class DirectedQuoteLegIdentifier;
class Double;
class ExtraData;
class Price;


namespace protocol { class DirectedQuoteLeg; }

class STRATEGY_EXPORT DirectedQuoteLegBase : public Printable
{
protected:
    DirectedQuoteLegBase();
    DirectedQuoteLegBase(const DirectedQuoteLegBase & value);
    DirectedQuoteLegBase(DirectedQuoteLegBase && value) noexcept;
    DirectedQuoteLegBase & operator=(const DirectedQuoteLegBase & value);
    DirectedQuoteLegBase & operator=(DirectedQuoteLegBase && value) noexcept;
    virtual ~DirectedQuoteLegBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get directed quote leg identifier.
     *
     *
     * @return                          directed quote leg identifier
     */
    DirectedQuoteLegIdentifier GetIdentifier() const;

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
    bool HasRatio() const;

    /**
     * Get ratio.
     *
     *
     * @return                          ratio
     */
    Double GetRatio() const;

    /**
     * %Set ratio.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ratio
     */
    void SetRatio(const Double & value);

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
    bool HasPriceCorrectionFactor() const;

    /**
     * Get price correction factor.
     *
     *
     * @return                          price correction factor
     */
    Double GetPriceCorrectionFactor() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    DirectedQuoteLegBase(const protocol::DirectedQuoteLeg & value);
    DirectedQuoteLegBase(std::shared_ptr<protocol::DirectedQuoteLeg> && value);

    std::shared_ptr<protocol::DirectedQuoteLeg> & get_impl_wr() const;
    const std::shared_ptr<protocol::DirectedQuoteLeg> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::DirectedQuoteLeg> m_impl;
};

}

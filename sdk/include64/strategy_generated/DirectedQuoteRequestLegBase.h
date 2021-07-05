#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteRequestLegBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Double;


namespace protocol { class DirectedQuoteRequestLeg; }

class STRATEGY_EXPORT DirectedQuoteRequestLegBase : public Printable
{
protected:
    DirectedQuoteRequestLegBase();
    DirectedQuoteRequestLegBase(const DirectedQuoteRequestLegBase & value);
    DirectedQuoteRequestLegBase(DirectedQuoteRequestLegBase && value) noexcept;
    DirectedQuoteRequestLegBase & operator=(const DirectedQuoteRequestLegBase & value);
    DirectedQuoteRequestLegBase & operator=(DirectedQuoteRequestLegBase && value) noexcept;
    virtual ~DirectedQuoteRequestLegBase();

public:
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
    bool HasUnderlyingPriceLevel() const;

    /**
     * Get underlying price level.
     *
     *
     * @return                          underlying price level
     */
    Double GetUnderlyingPriceLevel() const;

    /**
     * %Set underlying price level.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     underlying price level
     */
    void SetUnderlyingPriceLevel(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasNotionalAmount() const;

    /**
     * Get notional amount.
     *
     *
     * @return                          notional amount
     */
    Double GetNotionalAmount() const;

    /**
     * %Set notional amount.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     notional amount
     */
    void SetNotionalAmount(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTickSize() const;

    /**
     * Get tick size.
     *
     *
     * @return                          tick size
     */
    Double GetTickSize() const;

    /**
     * %Set tick size.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     tick size
     */
    void SetTickSize(const Double & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    DirectedQuoteRequestLegBase(const protocol::DirectedQuoteRequestLeg & value);
    DirectedQuoteRequestLegBase(std::shared_ptr<protocol::DirectedQuoteRequestLeg> && value);

    std::shared_ptr<protocol::DirectedQuoteRequestLeg> & get_impl_wr() const;
    const std::shared_ptr<protocol::DirectedQuoteRequestLeg> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::DirectedQuoteRequestLeg> m_impl;
};

}

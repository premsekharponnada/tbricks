#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteSetMassCancelConditionBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class MIC;
class PortfolioIdentifier;
class StrategyIdentifier;
class TreeNodeIdentifier;
class UserIdentifier;
class VenueIdentifier;


namespace protocol { class TradingBlockCondition; }

class STRATEGY_EXPORT QuoteSetMassCancelConditionBase : public Printable
{
protected:
    QuoteSetMassCancelConditionBase();
    QuoteSetMassCancelConditionBase(const QuoteSetMassCancelConditionBase & value);
    QuoteSetMassCancelConditionBase(QuoteSetMassCancelConditionBase && value) noexcept;
    QuoteSetMassCancelConditionBase & operator=(const QuoteSetMassCancelConditionBase & value);
    QuoteSetMassCancelConditionBase & operator=(QuoteSetMassCancelConditionBase && value) noexcept;
    virtual ~QuoteSetMassCancelConditionBase();

public:
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
    bool HasOwner() const;

    /**
     * Get owner.
     *
     *
     * @return                          owner
     */
    UserIdentifier GetOwner() const;

    /**
     * %Set owner.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     owner
     */
    void SetOwner(const UserIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCreator() const;

    /**
     * Get creator.
     *
     *
     * @return                          creator
     */
    UserIdentifier GetCreator() const;

    /**
     * %Set creator.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     creator
     */
    void SetCreator(const UserIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRole() const;

    /**
     * Get role identifier.
     *
     *
     * @return                          role identifier
     */
    TreeNodeIdentifier GetRole() const;

    /**
     * %Set role identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     role identifier
     */
    void SetRole(const TreeNodeIdentifier & value);

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
    bool HasStrategyIdentifier() const;

    /**
     * Get strategy identifier.
     *
     *
     * @return                          strategy identifier
     */
    StrategyIdentifier GetStrategyIdentifier() const;

    /**
     * %Set strategy identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     strategy identifier
     */
    void SetStrategyIdentifier(const StrategyIdentifier & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    QuoteSetMassCancelConditionBase(const protocol::TradingBlockCondition & value);
    QuoteSetMassCancelConditionBase(std::shared_ptr<protocol::TradingBlockCondition> && value);

    std::shared_ptr<protocol::TradingBlockCondition> & get_impl_wr() const;
    const std::shared_ptr<protocol::TradingBlockCondition> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::TradingBlockCondition> m_impl;
};

}

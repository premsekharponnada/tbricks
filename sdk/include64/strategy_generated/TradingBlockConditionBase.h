#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingBlockConditionBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class CFIMask;
class Currency;
class InstrumentGroupIdentifier;
class InstrumentIdentifier;
class Integer;
class MIC;
class PortfolioIdentifier;
class RoleIdentifier;
class Side;
class StrategyIdentifier;
class TreeNodeIdentifier;
class UserIdentifier;
class VenueIdentifier;


namespace protocol { class TradingBlockCondition; }

class STRATEGY_EXPORT TradingBlockConditionBase : public Printable
{
protected:
    TradingBlockConditionBase();
    TradingBlockConditionBase(const TradingBlockConditionBase & value);
    TradingBlockConditionBase(TradingBlockConditionBase && value) noexcept;
    TradingBlockConditionBase & operator=(const TradingBlockConditionBase & value);
    TradingBlockConditionBase & operator=(TradingBlockConditionBase && value) noexcept;
    virtual ~TradingBlockConditionBase();

public:
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
    bool HasHandler() const;

    /**
     * Get handler.
     *
     *
     * @return                          handler
     */
    TreeNodeIdentifier GetHandler() const;

    /**
     * %Set handler.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     handler
     */
    void SetHandler(const TreeNodeIdentifier & value);

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
    bool HasRole() const;

    /**
     * Get role identifier.
     *
     *
     * @return                          role identifier
     */
    RoleIdentifier GetRole() const;

    /**
     * %Set role identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     role identifier
     */
    void SetRole(const RoleIdentifier & value);

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
    bool HasSide() const;

    /**
     * Get side.
     *
     *
     * @return                          side
     */
    Side GetSide() const;

    /**
     * %Set side.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     side
     */
    void SetSide(const Side & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCFIMask() const;

    /**
     * Get cfi mask.
     *
     *
     * @return                          cfi mask
     */
    CFIMask GetCFIMask() const;

    /**
     * %Set cfi mask.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     cfi mask
     */
    void SetCFIMask(const CFIMask & value);

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
    bool HasStrategyDefinitionIdentifier() const;

    /**
     * Get strategy definition identifier.
     *
     *
     * @return                          strategy definition identifier
     */
    StrategyIdentifier GetStrategyDefinitionIdentifier() const;

    /**
     * %Set strategy definition identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     strategy definition identifier
     */
    void SetStrategyDefinitionIdentifier(const StrategyIdentifier & value);

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

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAlgoLabel() const;

    /**
     * Get algo label.
     *
     *
     * @return                          algo label
     */
    Integer GetAlgoLabel() const;

    /**
     * %Set algo label.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     algo label
     */
    void SetAlgoLabel(const Integer & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpartIdentifier() const;

    /**
     * Get counterpart identifier.
     *
     *
     * @return                          counterpart identifier
     */
    TreeNodeIdentifier GetCounterpartIdentifier() const;

    /**
     * %Set counterpart identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     counterpart identifier
     */
    void SetCounterpartIdentifier(const TreeNodeIdentifier & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    TradingBlockConditionBase(const protocol::TradingBlockCondition & value);
    TradingBlockConditionBase(std::shared_ptr<protocol::TradingBlockCondition> && value);

    std::shared_ptr<protocol::TradingBlockCondition> & get_impl_wr() const;
    const std::shared_ptr<protocol::TradingBlockCondition> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::TradingBlockCondition> m_impl;
};

}

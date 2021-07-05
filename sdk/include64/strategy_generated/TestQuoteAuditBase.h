#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestQuoteAuditBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class DateTime;
class Identifier;
class InstrumentIdentifier;
class LiquidityPoolIdentifier;
class Price;
class Side;
class TransactionState;
class Volume;


namespace protocol { class QuoteAudit; }

class STRATEGY_EXPORT TestQuoteAuditBase : public Printable
{
protected:
    TestQuoteAuditBase();
    TestQuoteAuditBase(const TestQuoteAuditBase & value);
    TestQuoteAuditBase(TestQuoteAuditBase && value) noexcept;
    TestQuoteAuditBase & operator=(const TestQuoteAuditBase & value);
    TestQuoteAuditBase & operator=(TestQuoteAuditBase && value) noexcept;
    virtual ~TestQuoteAuditBase();

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
    bool HasQuoteSetIdentifier() const;

    /**
     * Get quote set identifier.
     *
     *
     * @return                          quote set identifier
     */
    Identifier GetQuoteSetIdentifier() const;

    /**
     * %Set quote set identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote set identifier
     */
    void SetQuoteSetIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasQuoteIdentifier() const;

    /**
     * Get quote identifier.
     *
     *
     * @return                          quote identifier
     */
    Identifier GetQuoteIdentifier() const;

    /**
     * %Set quote identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote identifier
     */
    void SetQuoteIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTransactionState() const;

    /**
     * Get quote transaction state.
     *
     *
     * @return                          quote transaction state
     */
    TransactionState GetTransactionState() const;

    /**
     * %Set quote transaction state.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote transaction state
     */
    void SetTransactionState(const TransactionState & value);

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
    bool HasFilledVolume() const;

    /**
     * Get filled volume.
     *
     *
     * @return                          filled volume
     */
    Volume GetFilledVolume() const;

    /**
     * %Set filled volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     filled volume
     */
    void SetFilledVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLiquidityPoolIdentifier() const;

    /**
     * Get liquidity pool identifier.
     *
     *
     * @return                          liquidity pool identifier
     */
    LiquidityPoolIdentifier GetLiquidityPoolIdentifier() const;

    /**
     * %Set liquidity pool identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     liquidity pool identifier
     */
    void SetLiquidityPoolIdentifier(const LiquidityPoolIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostModifiedDatetime() const;

    /**
     * Get host modified datetime.
     *
     *
     * @return                          host modified datetime
     */
    DateTime GetHostModifiedDatetime() const;

    /**
     * %Set host modified datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host modified datetime
     */
    void SetHostModifiedDatetime(const DateTime & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const TestQuoteAuditBase & update);

/** @cond PRIVATE */
public:
    TestQuoteAuditBase(const protocol::QuoteAudit & value);
    TestQuoteAuditBase(std::shared_ptr<protocol::QuoteAudit> && value);

    std::shared_ptr<protocol::QuoteAudit> & get_impl_wr() const;
    const std::shared_ptr<protocol::QuoteAudit> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::QuoteAudit> m_impl;
};

}

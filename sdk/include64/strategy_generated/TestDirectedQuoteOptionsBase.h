#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestDirectedQuoteOptionsBase object
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
class DirectedQuoteIdentifier;
class ExtraData;
class Identifier;
class OrderCapacity;
class PortfolioIdentifier;
class Price;
class QuoteRequestIdentifier;
class RegulatoryParameters;
class StrategyIdentifier;
class String;
class TransactionState;
class TreeNodeIdentifier;
class UserIdentifier;
class Volume;


namespace protocol { class DirectedQuote; }

class STRATEGY_EXPORT TestDirectedQuoteOptionsBase : public Printable
{
protected:
    TestDirectedQuoteOptionsBase();
    TestDirectedQuoteOptionsBase(const TestDirectedQuoteOptionsBase & value);
    TestDirectedQuoteOptionsBase(TestDirectedQuoteOptionsBase && value) noexcept;
    TestDirectedQuoteOptionsBase & operator=(const TestDirectedQuoteOptionsBase & value);
    TestDirectedQuoteOptionsBase & operator=(TestDirectedQuoteOptionsBase && value) noexcept;
    virtual ~TestDirectedQuoteOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteIdentifier() const;

    /**
     * Get directed quote identifier.
     *
     *
     * @return                          directed quote identifier
     */
    DirectedQuoteIdentifier GetDirectedQuoteIdentifier() const;

    /**
     * %Set directed quote identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote identifier
     */
    void SetDirectedQuoteIdentifier(const DirectedQuoteIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestIdentifier() const;

    /**
     * Get request identifier.
     *
     *
     * @return                          request identifier
     */
    Identifier GetRequestIdentifier() const;

    /**
     * %Set request identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     request identifier
     */
    void SetRequestIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasQuoteRequestIdentifier() const;

    /**
     * Get quote request identifier.
     *
     *
     * @return                          quote request identifier
     */
    QuoteRequestIdentifier GetQuoteRequestIdentifier() const;

    /**
     * %Set quote request identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote request identifier
     */
    void SetQuoteRequestIdentifier(const QuoteRequestIdentifier & value);

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
    bool HasTransactionState() const;

    /**
     * Get directed quote transaction state.
     *
     *
     * @return                          directed quote transaction state
     */
    TransactionState GetTransactionState() const;

    /**
     * %Set directed quote transaction state.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote transaction state
     */
    void SetTransactionState(const TransactionState & value);

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
    bool HasRegulatoryParameters() const;

    /**
     * Get regulatory parameters.
     *
     *
     * @return                          regulatory parameters
     */
    RegulatoryParameters GetRegulatoryParameters() const;

    /**
     * %Set regulatory parameters.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     regulatory parameters
     */
    void SetRegulatoryParameters(const RegulatoryParameters & value);

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
    bool HasValidUntilDatetime() const;

    /**
     * Get valid until datetime.
     *
     *
     * @return                          valid until datetime
     */
    DateTime GetValidUntilDatetime() const;

    /**
     * %Set valid until datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     valid until datetime
     */
    void SetValidUntilDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidActiveVolume() const;

    /**
     * Get bid active volume.
     *
     *
     * @return                          bid active volume
     */
    Volume GetBidActiveVolume() const;

    /**
     * %Set bid active volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     bid active volume
     */
    void SetBidActiveVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidFilledVolume() const;

    /**
     * Get bid filled volume.
     *
     *
     * @return                          bid filled volume
     */
    Volume GetBidFilledVolume() const;

    /**
     * %Set bid filled volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     bid filled volume
     */
    void SetBidFilledVolume(const Volume & value);

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
    bool HasAskActiveVolume() const;

    /**
     * Get ask active volume.
     *
     *
     * @return                          ask active volume
     */
    Volume GetAskActiveVolume() const;

    /**
     * %Set ask active volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ask active volume
     */
    void SetAskActiveVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskFilledVolume() const;

    /**
     * Get ask filled volume.
     *
     *
     * @return                          ask filled volume
     */
    Volume GetAskFilledVolume() const;

    /**
     * %Set ask filled volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ask filled volume
     */
    void SetAskFilledVolume(const Volume & value);

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
    bool HasCapacity() const;

    /**
     * Get order capacity.
     *
     *
     * @return                          order capacity
     */
    OrderCapacity GetCapacity() const;

    /**
     * %Set order capacity.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     order capacity
     */
    void SetCapacity(const OrderCapacity & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeNegotiationReference() const;

    /**
     * Get exchange negotiation reference.
     *
     *
     * @return                          exchange negotiation reference
     */
    String GetExchangeNegotiationReference() const;

    /**
     * %Set exchange negotiation reference.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange negotiation reference
     */
    void SetExchangeNegotiationReference(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComment() const;

    /**
     * Get comment.
     *
     *
     * @return                          comment
     */
    String GetComment() const;

    /**
     * %Set comment.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     comment
     */
    void SetComment(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpart() const;

    /**
     * Get counterpart.
     *
     *
     * @return                          counterpart
     */
    String GetCounterpart() const;

    /**
     * %Set counterpart.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     counterpart
     */
    void SetCounterpart(const String & value);

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
    bool HasParentStrategyIdentifier() const;

    /**
     * Get parent strategy identifier.
     *
     *
     * @return                          parent strategy identifier
     */
    StrategyIdentifier GetParentStrategyIdentifier() const;

    /**
     * %Set parent strategy identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     parent strategy identifier
     */
    void SetParentStrategyIdentifier(const StrategyIdentifier & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const TestDirectedQuoteOptionsBase & update);

/** @cond PRIVATE */
public:
    TestDirectedQuoteOptionsBase(const protocol::DirectedQuote & value);
    TestDirectedQuoteOptionsBase(std::shared_ptr<protocol::DirectedQuote> && value);

    std::shared_ptr<protocol::DirectedQuote> & get_impl_wr() const;
    const std::shared_ptr<protocol::DirectedQuote> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::DirectedQuote> m_impl;
};

}

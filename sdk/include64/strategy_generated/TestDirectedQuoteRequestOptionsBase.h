#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestDirectedQuoteRequestOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class CounterpartInformation;
class Currency;
class DateTime;
class DirectedQuoteRequestIdentifier;
class DirectedQuoteRequestLeg;
class ExtraData;
class HandlingInstruction;
class Identifier;
class LiquidityPoolIdentifier;
class Price;
class RegulatoryParameters;
class Side;
class StrategyParameters;
class String;
class TransactionState;
class TreeNodeIdentifier;
class UserIdentifier;
class Volume;
enum class DirectedRequestForQuoteRejectReason;


namespace protocol { class DirectedQuoteRequestRequest; }

class STRATEGY_EXPORT TestDirectedQuoteRequestOptionsBase : public Printable
{
protected:
    TestDirectedQuoteRequestOptionsBase();
    TestDirectedQuoteRequestOptionsBase(const TestDirectedQuoteRequestOptionsBase & value);
    TestDirectedQuoteRequestOptionsBase(TestDirectedQuoteRequestOptionsBase && value) noexcept;
    TestDirectedQuoteRequestOptionsBase & operator=(const TestDirectedQuoteRequestOptionsBase & value);
    TestDirectedQuoteRequestOptionsBase & operator=(TestDirectedQuoteRequestOptionsBase && value) noexcept;
    virtual ~TestDirectedQuoteRequestOptionsBase();

public:
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
    bool HasIsFirm() const;

    /**
     * Get is firm.
     *
     *
     * @return                          is firm
     */
    Boolean GetIsFirm() const;

    /**
     * %Set is firm.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     is firm
     */
    void SetIsFirm(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLiquidityPool() const;

    /**
     * Get liquidity pool identifier.
     *
     *
     * @return                          liquidity pool identifier
     */
    LiquidityPoolIdentifier GetLiquidityPool() const;

    /**
     * %Set liquidity pool identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     liquidity pool identifier
     */
    void SetLiquidityPool(const LiquidityPoolIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestedBidPrice() const;

    /**
     * Get requested bid price.
     *
     *
     * @return                          requested bid price
     */
    Price GetRequestedBidPrice() const;

    /**
     * %Set requested bid price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     requested bid price
     */
    void SetRequestedBidPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestedAskPrice() const;

    /**
     * Get requested ask price.
     *
     *
     * @return                          requested ask price
     */
    Price GetRequestedAskPrice() const;

    /**
     * %Set requested ask price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     requested ask price
     */
    void SetRequestedAskPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get quote request identifier.
     *
     *
     * @return                          quote request identifier
     */
    DirectedQuoteRequestIdentifier GetIdentifier() const;

    /**
     * %Set quote request identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote request identifier
     */
    void SetIdentifier(const DirectedQuoteRequestIdentifier & value);

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
    bool HasLegs() const;

    /**
     * Get directed quote request legs.
     *
     *
     * @return                          directed quote request legs
     */
    std::vector<DirectedQuoteRequestLeg> GetLegs() const;

    /**
     * %Set directed quote request legs.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     directed quote request legs
     */
    void SetLegs(const std::vector<DirectedQuoteRequestLeg> & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpartiesInformation() const;

    /**
     * Get counterparties information.
     *
     *
     * @return                          counterparties information
     */
    std::vector<CounterpartInformation> GetCounterpartiesInformation() const;

    /**
     * %Set counterparties information.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     counterparties information
     */
    void SetCounterpartiesInformation(const std::vector<CounterpartInformation> & value);

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
    bool HasTransactionState() const;

    /**
     * Get directed quote request transaction state.
     *
     *
     * @return                          directed quote request transaction state
     */
    TransactionState GetTransactionState() const;

    /**
     * %Set directed quote request transaction state.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote request transaction state
     */
    void SetTransactionState(const TransactionState & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRespondByDatetime() const;

    /**
     * Get valid until datetime.
     *
     *
     * @return                          valid until datetime
     */
    DateTime GetRespondByDatetime() const;

    /**
     * %Set valid until datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     valid until datetime
     */
    void SetRespondByDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRejectReason() const;

    /**
     * Get directed request for quote reject reason.
     *
     *
     * @return                          directed request for quote reject reason
     */
    std::optional<DirectedRequestForQuoteRejectReason> GetRejectReason() const;

    /**
     * %Set directed request for quote reject reason.
     *
     *
     * @param value                     directed request for quote reject reason
     */
    void SetRejectReason(std::optional<DirectedRequestForQuoteRejectReason> value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDealtCurrency() const;

    /**
     * Get dealt currency.
     *
     *
     * @return                          dealt currency
     */
    Currency GetDealtCurrency() const;

    /**
     * %Set dealt currency.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     dealt currency
     */
    void SetDealtCurrency(const Currency & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyParameters() const;

    /**
     * Get strategy parameters.
     *
     *
     * @return                          strategy parameters
     */
    StrategyParameters GetStrategyParameters() const;

    /**
     * %Set strategy parameters.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     strategy parameters
     */
    void SetStrategyParameters(const StrategyParameters & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandlingInstruction() const;

    /**
     * Get handling instruction.
     *
     *
     * @return                          handling instruction
     */
    HandlingInstruction GetHandlingInstruction() const;

    /**
     * %Set handling instruction.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     handling instruction
     */
    void SetHandlingInstruction(const HandlingInstruction & value);

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
    bool HasValidUntilDateTime() const;

    /**
     * Get valid until datetime.
     *
     *
     * @return                          valid until datetime
     */
    DateTime GetValidUntilDateTime() const;

    /**
     * %Set valid until datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     valid until datetime
     */
    void SetValidUntilDateTime(const DateTime & value);

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
    bool HasNegotiateDelta() const;

    /**
     * Get negotiate delta.
     *
     *
     * @return                          negotiate delta
     */
    Boolean GetNegotiateDelta() const;

    /**
     * %Set negotiate delta.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     negotiate delta
     */
    void SetNegotiateDelta(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasNegotiateUnderlyingPriceLevel() const;

    /**
     * Get negotiate underlying price level.
     *
     *
     * @return                          negotiate underlying price level
     */
    Boolean GetNegotiateUnderlyingPriceLevel() const;

    /**
     * %Set negotiate underlying price level.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     negotiate underlying price level
     */
    void SetNegotiateUnderlyingPriceLevel(const Boolean & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const TestDirectedQuoteRequestOptionsBase & update);

/** @cond PRIVATE */
public:
    TestDirectedQuoteRequestOptionsBase(const protocol::DirectedQuoteRequestRequest & value);
    TestDirectedQuoteRequestOptionsBase(std::shared_ptr<protocol::DirectedQuoteRequestRequest> && value);

    std::shared_ptr<protocol::DirectedQuoteRequestRequest> & get_impl_wr() const;
    const std::shared_ptr<protocol::DirectedQuoteRequestRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::DirectedQuoteRequestRequest> m_impl;
};

}

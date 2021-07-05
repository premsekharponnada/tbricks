#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedRequestForQuoteBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class Currency;
class DateTime;
class DirectedQuoteRequestLeg;
class Duration;
class ExtraData;
class HandlingInstruction;
class Identifier;
class Integer;
class LiquidityPoolIdentifier;
class Price;
class Side;
class String;
class TreeNodeIdentifier;
class Volume;
enum class RequestForQuoteResult;


namespace protocol { class DirectedRequestForQuote; }

class STRATEGY_EXPORT DirectedRequestForQuoteBase : public Printable
{
protected:
    DirectedRequestForQuoteBase();
    DirectedRequestForQuoteBase(const DirectedRequestForQuoteBase & value);
    DirectedRequestForQuoteBase(DirectedRequestForQuoteBase && value) noexcept;
    DirectedRequestForQuoteBase & operator=(const DirectedRequestForQuoteBase & value);
    DirectedRequestForQuoteBase & operator=(DirectedRequestForQuoteBase && value) noexcept;
    virtual ~DirectedRequestForQuoteBase();

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
    bool HasDeleted() const;

    /**
     * Get deleted.
     *
     *
     * @return                          deleted
     */
    Boolean GetDeleted() const;

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
    bool HasIdentifier() const;

    /**
     * Get quote request identifier.
     *
     *
     * @return                          quote request identifier
     */
    Identifier GetIdentifier() const;

    /**
     * %Set quote request identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote request identifier
     */
    void SetIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpart() const;

    /**
     * Get counterpart identifier.
     *
     *
     * @return                          counterpart identifier
     */
    TreeNodeIdentifier GetCounterpart() const;

    /**
     * %Set counterpart identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     counterpart identifier
     */
    void SetCounterpart(const TreeNodeIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpartName() const;

    /**
     * Get counterpart.
     *
     *
     * @return                          counterpart
     */
    String GetCounterpartName() const;

    /**
     * %Set counterpart.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     counterpart
     */
    void SetCounterpartName(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasNumberOfRespondents() const;

    /**
     * Get number of respondents.
     *
     *
     * @return                          number of respondents
     */
    Integer GetNumberOfRespondents() const;

    /**
     * %Set number of respondents.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     number of respondents
     */
    void SetNumberOfRespondents(const Integer & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasNumberOfQuotedRespondents() const;

    /**
     * Get number of quoted respondents.
     *
     *
     * @return                          number of quoted respondents
     */
    Integer GetNumberOfQuotedRespondents() const;

    /**
     * %Set number of quoted respondents.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     number of quoted respondents
     */
    void SetNumberOfQuotedRespondents(const Integer & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRespondByDatetime() const;

    /**
     * Get respond by datetime.
     *
     *
     * @return                          respond by datetime
     */
    DateTime GetRespondByDatetime() const;

    /**
     * %Set respond by datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     respond by datetime
     */
    void SetRespondByDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestedValidity() const;

    /**
     * Get requested validity.
     *
     *
     * @return                          requested validity
     */
    Duration GetRequestedValidity() const;

    /**
     * %Set requested validity.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     requested validity
     */
    void SetRequestedValidity(const Duration & value);

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
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSettlementDate() const;

    /**
     * Get settlement date.
     *
     *
     * @return                          settlement date
     */
    DateTime GetSettlementDate() const;

    /**
     * %Set settlement date.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     settlement date
     */
    void SetSettlementDate(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSettlementCurrency() const;

    /**
     * Get settlement currency.
     *
     *
     * @return                          settlement currency
     */
    Currency GetSettlementCurrency() const;

    /**
     * %Set settlement currency.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     settlement currency
     */
    void SetSettlementCurrency(const Currency & value);

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
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestForQuoteResult() const;

    /**
     * Get request for quote result.
     *
     *
     * @return                          request for quote result
     */
    std::optional<RequestForQuoteResult> GetRequestForQuoteResult() const;

    /**
     * %Set request for quote result.
     *
     *
     * @param value                     request for quote result
     */
    void SetRequestForQuoteResult(std::optional<RequestForQuoteResult> value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIsGrossPrice() const;

    /**
     * Get is gross price.
     *
     *
     * @return                          is gross price
     */
    Boolean GetIsGrossPrice() const;

    /**
     * %Set is gross price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     is gross price
     */
    void SetIsGrossPrice(const Boolean & value);

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
    bool HasRequoteAllowed() const;

    /**
     * Get requote allowed.
     *
     *
     * @return                          requote allowed
     */
    Boolean GetRequoteAllowed() const;

    /**
     * %Set requote allowed.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     requote allowed
     */
    void SetRequoteAllowed(const Boolean & value);

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
    void Merge(const DirectedRequestForQuoteBase & update);

/** @cond PRIVATE */
public:
    DirectedRequestForQuoteBase(const protocol::DirectedRequestForQuote & value);
    DirectedRequestForQuoteBase(std::shared_ptr<protocol::DirectedRequestForQuote> && value);

    std::shared_ptr<protocol::DirectedRequestForQuote> & get_impl_wr() const;
    const std::shared_ptr<protocol::DirectedRequestForQuote> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::DirectedRequestForQuote> m_impl;
};

}

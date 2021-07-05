#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteResponseBase object
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
class DirectedQuoteResponseGeneration;
class DirectedQuoteResponseIdentifier;
class ExtraData;
class MarketDataParameters;
class Price;
class QuoteRequestIdentifier;
class String;
class TreeNodeIdentifier;
class Volume;


namespace protocol { class DirectedQuoteResponse; }

class STRATEGY_EXPORT DirectedQuoteResponseBase : public Printable
{
protected:
    DirectedQuoteResponseBase();
    DirectedQuoteResponseBase(const DirectedQuoteResponseBase & value);
    DirectedQuoteResponseBase(DirectedQuoteResponseBase && value) noexcept;
    DirectedQuoteResponseBase & operator=(const DirectedQuoteResponseBase & value);
    DirectedQuoteResponseBase & operator=(DirectedQuoteResponseBase && value) noexcept;
    virtual ~DirectedQuoteResponseBase();

public:
    /**
     * Get directed quote response identifier.
     *
     *
     * @return                          directed quote response identifier
     */
    DirectedQuoteResponseIdentifier GetIdentifier() const;

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
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasGeneration() const;

    /**
     * Get directed quote response generation.
     *
     *
     * @return                          directed quote response generation
     */
    DirectedQuoteResponseGeneration GetGeneration() const;

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
    bool HasHostCreatedDatetime() const;

    /**
     * Get host created datetime.
     *
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDatetime() const;

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
     * Delete field from request if field is empty 
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
    bool HasCurrency() const;

    /**
     * Get currency.
     *
     *
     * @return                          currency
     */
    Currency GetCurrency() const;

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
    bool HasStatusText() const;

    /**
     * Get status text.
     *
     *
     * @return                          status text
     */
    String GetStatusText() const;

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const DirectedQuoteResponseBase & update);

/** @cond PRIVATE */
public:
    DirectedQuoteResponseBase(const protocol::DirectedQuoteResponse & value);
    DirectedQuoteResponseBase(std::shared_ptr<protocol::DirectedQuoteResponse> && value);

    std::shared_ptr<protocol::DirectedQuoteResponse> & get_impl_wr() const;
    const std::shared_ptr<protocol::DirectedQuoteResponse> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::DirectedQuoteResponse> m_impl;
};

}

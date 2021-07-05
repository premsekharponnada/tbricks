#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteBase object
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
class DirectedQuoteGeneration;
class DirectedQuoteIdentifier;
class ExtraData;
class Identifier;
class OrderCapacity;
class PortfolioIdentifier;
class Price;
class QuoteRequestIdentifier;
class RegulatoryParameters;
class String;
class TransactionState;
class TreeNodeIdentifier;
class UserIdentifier;
class Volume;


namespace protocol { class DirectedQuote; }

class STRATEGY_EXPORT DirectedQuoteBase : public Printable
{
protected:
    DirectedQuoteBase();
    DirectedQuoteBase(const DirectedQuoteBase & value);
    DirectedQuoteBase(DirectedQuoteBase && value) noexcept;
    DirectedQuoteBase & operator=(const DirectedQuoteBase & value);
    DirectedQuoteBase & operator=(DirectedQuoteBase && value) noexcept;
    virtual ~DirectedQuoteBase();

public:
    /**
     * Get directed quote identifier.
     *
     *
     * @return                          directed quote identifier
     */
    DirectedQuoteIdentifier GetDirectedQuoteIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteGeneration() const;

    /**
     * Get directed quote generation.
     *
     *
     * @return                          directed quote generation
     */
    DirectedQuoteGeneration GetDirectedQuoteGeneration() const;

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
    bool HasBidPrice() const;

    /**
     * Get bid price.
     *
     *
     * @return                          bid price
     */
    Price GetBidPrice() const;

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
    bool HasOwner() const;

    /**
     * Get owner.
     *
     *
     * @return                          owner
     */
    UserIdentifier GetOwner() const;

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
    bool HasBidActiveVolume() const;

    /**
     * Get bid active volume.
     *
     *
     * @return                          bid active volume
     */
    Volume GetBidActiveVolume() const;

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
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeDirectedQuoteReference() const;

    /**
     * Get exchange directed quote reference.
     *
     *
     * @return                          exchange directed quote reference
     */
    String GetExchangeDirectedQuoteReference() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeClientReference() const;

    /**
     * Get exchange client directed quote reference.
     *
     *
     * @return                          exchange client directed quote reference
     */
    String GetExchangeClientReference() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBypassSoftLimits() const;

    /**
     * Get bypass soft limits.
     *
     *
     * @return                          bypass soft limits
     */
    Boolean GetBypassSoftLimits() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    DirectedQuoteBase(const protocol::DirectedQuote & value);
    DirectedQuoteBase(std::shared_ptr<protocol::DirectedQuote> && value);

    std::shared_ptr<protocol::DirectedQuote> & get_impl_wr() const;
    const std::shared_ptr<protocol::DirectedQuote> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::DirectedQuote> m_impl;
};

}

#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteRequestBase object
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

class STRATEGY_EXPORT DirectedQuoteRequestBase : public Printable
{
protected:
    DirectedQuoteRequestBase();
    DirectedQuoteRequestBase(const DirectedQuoteRequestBase & value);
    DirectedQuoteRequestBase(DirectedQuoteRequestBase && value) noexcept;
    DirectedQuoteRequestBase & operator=(const DirectedQuoteRequestBase & value);
    DirectedQuoteRequestBase & operator=(DirectedQuoteRequestBase && value) noexcept;
    virtual ~DirectedQuoteRequestBase();

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
    bool HasTransactionState() const;

    /**
     * Get directed quote request transaction state.
     *
     *
     * @return                          directed quote request transaction state
     */
    TransactionState GetTransactionState() const;

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
    bool HasCreator() const;

    /**
     * Get creator.
     *
     *
     * @return                          creator
     */
    UserIdentifier GetCreator() const;

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
    bool HasMinimumAcceptableVolume() const;

    /**
     * Get minimum acceptable volume.
     *
     *
     * @return                          minimum acceptable volume
     */
    Volume GetMinimumAcceptableVolume() const;

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const DirectedQuoteRequestBase & update);

/** @cond PRIVATE */
public:
    DirectedQuoteRequestBase(const protocol::DirectedQuoteRequestRequest & value);
    DirectedQuoteRequestBase(std::shared_ptr<protocol::DirectedQuoteRequestRequest> && value);

    std::shared_ptr<protocol::DirectedQuoteRequestRequest> & get_impl_wr() const;
    const std::shared_ptr<protocol::DirectedQuoteRequestRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::DirectedQuoteRequestRequest> m_impl;
};

}

#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BlockOrderUpdateBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class BlockOrderIdentifier;
class BlockOrderLeg;
class Boolean;
class Currency;
class DateTime;
class DirectedQuoteResponseGeneration;
class DirectedQuoteResponseIdentifier;
class Double;
class ExtraData;
class Identifier;
class Integer;
class OrderCapacity;
class Price;
class PricePolicy;
class RegulatoryParameters;
class StrategyIdentifier;
class String;
class TransactionState;
class TreeNodeIdentifier;
class UserIdentifier;


namespace protocol { class BlockOrder; }

class STRATEGY_EXPORT BlockOrderUpdateBase : public Printable
{
protected:
    BlockOrderUpdateBase();
    BlockOrderUpdateBase(const BlockOrderUpdateBase & value);
    BlockOrderUpdateBase(BlockOrderUpdateBase && value) noexcept;
    BlockOrderUpdateBase & operator=(const BlockOrderUpdateBase & value);
    BlockOrderUpdateBase & operator=(BlockOrderUpdateBase && value) noexcept;
    virtual ~BlockOrderUpdateBase();

public:
    /**
     * Get block order identifier.
     *
     *
     * @return                          block order identifier
     */
    BlockOrderIdentifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLegs() const;

    /**
     * Get block order legs.
     *
     *
     * @return                          block order legs
     */
    std::vector<BlockOrderLeg> GetLegs() const;

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
    bool HasExchangeOrderReference() const;

    /**
     * Get exchange order reference.
     *
     *
     * @return                          exchange order reference
     */
    String GetExchangeOrderReference() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeClientOrderReference() const;

    /**
     * Get exchange client order reference.
     *
     *
     * @return                          exchange client order reference
     */
    String GetExchangeClientOrderReference() const;

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
    bool HasExchangeCreatedDatetime() const;

    /**
     * Get exchange created datetime.
     *
     *
     * @return                          exchange created datetime
     */
    DateTime GetExchangeCreatedDatetime() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeModifiedDatetime() const;

    /**
     * Get exchange modified datetime.
     *
     *
     * @return                          exchange modified datetime
     */
    DateTime GetExchangeModifiedDatetime() const;

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
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOperator() const;

    /**
     * Get operator.
     *
     *
     * @return                          operator
     */
    UserIdentifier GetOperator() const;

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
    bool HasTransactionState() const;

    /**
     * Get order transaction state.
     *
     *
     * @return                          order transaction state
     */
    TransactionState GetTransactionState() const;

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
    bool HasPrice() const;

    /**
     * Get price.
     *
     *
     * @return                          price
     */
    Price GetPrice() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPricePolicy() const;

    /**
     * Get price policy.
     *
     *
     * @return                          price policy
     */
    PricePolicy GetPricePolicy() const;

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
    bool HasRetainOnDisconnect() const;

    /**
     * Get retain on disconnect.
     *
     *
     * @return                          retain on disconnect
     */
    Boolean GetRetainOnDisconnect() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRootStrategyIdentifier() const;

    /**
     * Get root strategy identifier.
     *
     *
     * @return                          root strategy identifier
     */
    StrategyIdentifier GetRootStrategyIdentifier() const;

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
    bool HasStrategyIdentifierPath() const;

    /**
     * Get strategy identifier path.
     *
     *
     * @return                          strategy identifier path
     */
    std::vector<StrategyIdentifier> GetStrategyIdentifierPath() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyDefinitionPath() const;

    /**
     * Get strategy definition identifier path.
     *
     *
     * @return                          strategy definition identifier path
     */
    std::vector<StrategyIdentifier> GetStrategyDefinitionPath() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyEngineServiceInstanceIdentifier() const;

    /**
     * Get strategy engine service instance identifier.
     *
     *
     * @return                          strategy engine service instance identifier
     */
    Identifier GetStrategyEngineServiceInstanceIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTargetPrice() const;

    /**
     * Get target price.
     *
     *
     * @return                          target price
     */
    Double GetTargetPrice() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradingServiceInstanceIdentifier() const;

    /**
     * Get trading service instance identifier.
     *
     *
     * @return                          trading service instance identifier
     */
    Identifier GetTradingServiceInstanceIdentifier() const;

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
    bool HasDirectedQuoteResponseIdentifier() const;

    /**
     * Get directed quote response identifier.
     *
     *
     * @return                          directed quote response identifier
     */
    DirectedQuoteResponseIdentifier GetDirectedQuoteResponseIdentifier() const;

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
    bool HasUnsolicited() const;

    /**
     * Get unsolicited.
     *
     *
     * @return                          unsolicited
     */
    Boolean GetUnsolicited() const;

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    BlockOrderUpdateBase(const protocol::BlockOrder & value);
    BlockOrderUpdateBase(std::shared_ptr<protocol::BlockOrder> && value);

    std::shared_ptr<protocol::BlockOrder> & get_impl_wr() const;
    const std::shared_ptr<protocol::BlockOrder> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::BlockOrder> m_impl;
};

}

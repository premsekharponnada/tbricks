#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OrderModifyBase object
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/LiquidityPoolIdentifier.h"
#include "strategy/parameter/StrategyParameters.h"
#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/String.h"
#include "strategy/type/Price.h"
#include "strategy/type/TreeNodeIdentifier.h"
#include "strategy/type/Volume.h"
#include "strategy/ExtraData.h"

namespace tbricks {

namespace protocol {
class OrderModifyRequest;
}

class STRATEGY_EXPORT OrderModifyBase : public Printable
{
protected:
    OrderModifyBase();
    OrderModifyBase(const OrderModifyBase & value);
    OrderModifyBase(OrderModifyBase && value) noexcept;
    OrderModifyBase & operator=(const OrderModifyBase & value);
    OrderModifyBase & operator=(OrderModifyBase && value) noexcept;
    virtual ~OrderModifyBase();

public:
    /**
     * Get order identifier
     *
     * @return                         order identifier
     */
    OrderIdentifier GetOrderIdentifier() const;

    /**
     * Get request identifier
     *
     * @return                         request identifier
     */
    Identifier GetRequestIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPrice() const;

    /**
     * Get price.
     *
     * @return                          price
     */
    Price GetPrice() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasActiveVolume() const;

    /**
     * Get active volume.
     *
     * @return                          active volume
     */
    Volume GetActiveVolume() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTotalVolume() const;

    /**
     * Get total volume.
     *
     * @return                          total volume
     */
    Volume GetTotalVolume() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     *
     * @deprecated Deprecated in 2.14.5
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasRetainOnDisconnect() const;

    /**
     * Get retain on disconnect.
     *
     * @return                          retain on disconnect
     *
     * @deprecated Deprecated in 2.14.5
     */
    [[deprecated(DEPRECATE_LINK)]] Boolean GetRetainOnDisconnect() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPortfolioIdentifier() const;

    /**
     * Get portfolio identifier.
     *
     * @return                          portfolio identifier
     */
    PortfolioIdentifier GetPortfolioIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExtraData() const;

    /**
     * Get extra data.
     *
     * @return                          extra data
     */
    ExtraData GetExtraData() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyParameters() const;

    /**
     * Get strategy parameters.
     *
     * @return                          strategy parameters
     */
    StrategyParameters GetStrategyParameters() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComment() const;

    /**
     * Get comment.
     *
     * @return                          comment
     */
    String GetComment() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStopPrice() const;

    /**
     * Get stop price.
     *
     * @return                          stop price
     */
    Price GetStopPrice() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBypassSoftLimits() const;

    /**
     * Get bypass soft limits.
     *
     * @return                          bypass soft limits
     */
    Boolean GetBypassSoftLimits() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasClient() const;

    /**
     * Get client.
     *
     * @return                          client
     */
    TreeNodeIdentifier GetClient() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandler() const;

    /**
     * Get handler.
     *
     * @return                          handler
     */
    TreeNodeIdentifier GetHandler() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDisclosedVolume() const;

    /**
     * Get disclosed volume.
     *
     * @return                          disclosed volume
     */
    Volume GetDisclosedVolume() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMinimumAcceptableFillVolume() const;

    /**
     * Get minimum acceptable fill volume.
     *
     * @return                          minimum acceptable fill volume
     */
    Volume GetMinimumAcceptableFillVolume() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLiquidityPool() const;

    /**
     * Get liquidity pool identifier.
     *
     * @return                          liquidity pool identifier
     */
    LiquidityPoolIdentifier GetLiquidityPool() const;

public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

public:
    OrderModifyBase(const protocol::OrderModifyRequest & value);
    const protocol::OrderModifyRequest & get_impl() const;

protected:
    std::unique_ptr<protocol::OrderModifyRequest> m_impl;
};
}

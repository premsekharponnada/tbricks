#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Block Order.
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/BlockOrderLeg.h"
#include "strategy/RegulatoryParameters.h"
#include "strategy/limit/TradingLimitState.h"
#include "strategy/limit/TradingLimitResult.h"
#include "strategy/type/BlockOrderIdentifier.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/Double.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/Integer.h"
#include "strategy/type/OrderCapacity.h"
#include "strategy/type/Price.h"
#include "strategy/type/PricePolicy.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/String.h"
#include "strategy/type/TransactionState.h"
#include "strategy/type/TreeNodeIdentifier.h"
#include "strategy/type/Validity.h"
#include "strategy/type/UserIdentifier.h"

#include "strategy_generated/BlockOrderBase.h"
#include "strategy_generated/BlockOrderOptionsBase.h"
#include "strategy_generated/BlockOrderUpdateBase.h"

namespace tbricks {

/**
 * Representing a multi-level order priced either per-leg or as a whole.
 * All volumes will be normalized per-leg
 */
class STRATEGY_EXPORT BlockOrder : public BlockOrderBase
{
private:
    typedef BlockOrderBase super;

public:
    class Options;
    class Update;
    class Stream;

public:
    /// Default constructor
    BlockOrder();

    /// Copy constructor
    BlockOrder(const BlockOrder & block_order);
    BlockOrder(BlockOrder && block_order) noexcept;
    BlockOrder(protocol::BlockOrder * order);

    /// Destructor
    virtual ~BlockOrder() override;

    BlockOrder & operator=(const BlockOrder & block_order);
    BlockOrder & operator=(BlockOrder && block_order) noexcept;

public:
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
    bool HasValidity() const;

    /**
     * Get validity.
     *
     * @return                          validity
     */
    Validity GetValidity() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradingLimitResult() const;

    /**
     * Get trading limit result.
     *
     * @return                          trading limit result
     */
    TradingLimitResult GetTradingLimitResult() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradingLimitState() const;

    /**
     * Get trading limit state.
     *
     * @return                          trading limit state
     */
    TradingLimitState GetTradingLimitState() const;

    void Merge(const BlockOrder::Update & update);
};

class STRATEGY_EXPORT BlockOrder::Update : public BlockOrderUpdateBase
{
public:
    /// Default constructor
    Update();

    /// Copy constructor
    Update(const Update & block_order);
    Update(Update && block_order) noexcept;

    /// Destructor
    ~Update() override;

    Update & operator=(const Update & block_order);
    Update & operator=(Update && block_order) noexcept;

    Update(const protocol::BlockOrder & block_order);

public:
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
    bool HasValidity() const;

    /**
     * Get validity.
     *
     * @return                          validity
     */
    Validity GetValidity() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradingLimitResult() const;

    /**
     * Get trading limit result.
     *
     * @return                          trading limit result
     */
    TradingLimitResult GetTradingLimitResult() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradingLimitState() const;

    /**
     * Get trading limit state.
     *
     * @return                          trading limit state
     */
    TradingLimitState GetTradingLimitState() const;
};

/**
 * Block Order A signficant order placed for sale or purchase of a
 * large number of securities. Also known as a "Block Trade".
 *
 * BlockOrder::Options allows to create a block order.
 *
 * @warning SetLegs call changes Identifiers in Legs. If you need
 *          identifier of legs they should be taken after Set.
 */
class STRATEGY_EXPORT BlockOrder::Options : public BlockOrderOptionsBase
{
public:
    Options();
    Options(const Options & options);
    Options(Options && options) noexcept;

    ~Options();

    Options & operator=(const Options & options);
    Options & operator=(Options && options) noexcept;

public:
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasValidity() const;

    /**
     * Get validity.
     *
     * @return                          validity
     */
    Validity GetValidity() const;

    /**
     * %Set validity.
     *
     * @param value                     validity
     */
    void SetValidity(const Validity & value);

    /**
     * Set directed quote response identifier
     *
     * @param value                     directed quote response identifier
     */
    void SetDirectedQuoteResponse(const DirectedQuoteResponseIdentifier & value);

    /**
     * Set directed quote response generation
     *
     * @param value                     directed quote response generation
     */
    void SetDirectedQuoteResponseGeneration(const DirectedQuoteResponseGeneration & value);
};
}

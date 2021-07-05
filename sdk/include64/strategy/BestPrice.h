#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Best Price updates.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/MarketDataParameters.h"
#include "strategy/Value.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/OrderBookChangeReason.h"
#include "strategy/type/Price.h"
#include "strategy/type/Trend.h"
#include "strategy/type/Volume.h"
#include "strategy_generated/BestPriceBase.h"

namespace tbricks {

/**
 * BestPrice object represents best price update, with either ask price/volume,
 * bid price/volume or both set.
 *
 * Has() method family allows to check if corresponding fields are included
 * in the update at all.
 *
 * Price/Volume HasValue() method should be used together with appropriate
 * Update() method to separate the case when price disappears from the market
 * from the case when particular price was not included at all:
 *
 * @code
 * if (best_price.HasAskPrice()) {
 *      // ask price is included, check its value
 *      if (!best_price.GetAskPrice().Empty()) {
 *          // ask price is non-empty value
 *      } else {
 *          // ask price is empty, it has disappered from the market
 *      }
 * } else {
 *      // ask price is not included
 * }
 * if (m_currentOS == strategy.GetIdentifier()) {
 *     UpdateChildStrategyState(strategy);
 * }
 * @endcode
 *
 */
class STRATEGY_EXPORT BestPrice : public BestPriceBase
{
public:
    /**
     * Default constructor.
     *
     * Initializes object to default value -- no fields present, all returned
     * values are empty.
     *
     * This is mostly for use in STL containers.
     */
    BestPrice() = default;
    using BestPriceBase::BestPriceBase;
    using BestPriceBase::Merge;

    /**
     *  @brief  Test equivalence of two best prices.
     *  @param lhs  First best price.
     *  @param rhs  Second best price.
     *  @return  True if @a lhs.compare(@a rhs) == 0.  False otherwise.
     */
    bool operator==(const BestPrice & best_price) const;

    /**
     *  @brief  Test difference of two best prices.
     *  @param lhs  First best price.
     *  @param rhs  Second best price.
     *  @return  True if @a lhs.compare(@a rhs) == 0.  False otherwise.
     */
    bool operator!=(const BestPrice & best_price) const { return !operator==(best_price); }

    /**
     * Check if ask change reason is included into the update.
     *
     * @return                          "true" if ask change reason is part
     *                                  of the update, "false" otherwise
     */
    bool HasAskChangeReason() const;

    /**
     * Get reason for ask change.
     *
     * @return                          Reason for ask change
     */
    OrderBookChangeReason GetAskChangeReason() const;

    /**
     *  Check if bid change reason is included into the update.
     *
     * @return                          "true" if bid change reason is part
     *                                  of the update, "false" otherwise
     */
    bool HasBidChangeReason() const;

    /**
     * Get reason for bid change.
     *
     * @return                          Reason for ask change
     */
    OrderBookChangeReason GetBidChangeReason() const;

    bool Empty() const;
};
}

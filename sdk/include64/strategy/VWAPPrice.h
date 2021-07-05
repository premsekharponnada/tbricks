#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VWAP Price updates.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Price.h"
#include "strategy/type/Volume.h"
#include "strategy/type/Trend.h"
#include "strategy/Value.h"
#include "strategy_generated/VWAPPriceBase.h"

namespace tbricks {

/**
 * VWAPPrice object represents VWAP price update, with either ask price/volume,
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
 * if (VWAP_price.HasAskPrice()) {
 *      // ask price is included, check its value
 *      if (!VWAP_price.GetAskPrice().Empty()) {
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
class STRATEGY_EXPORT VWAPPrice : public VWAPPriceBase
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
    VWAPPrice() = default;

    using VWAPPriceBase::Merge;
    using VWAPPriceBase::VWAPPriceBase;

    /**
     *  @brief  Test equivalence of two best prices.
     *  @param lhs  First VWAP price.
     *  @param rhs  Second VWAP price.
     *  @return  True if @a lhs.compare(@a rhs) == 0.  False otherwise.
     */
    bool operator==(const VWAPPrice & VWAP_price) const;

    /**
     *  @brief  Test difference of two best prices.
     *  @param lhs  First VWAP price.
     *  @param rhs  Second VWAP price.
     *  @return  True if @a lhs.compare(@a rhs) == 0.  False otherwise.
     */
    bool operator!=(const VWAPPrice & VWAP_price) const { return !operator==(VWAP_price); }

    bool Empty() const;
};
}

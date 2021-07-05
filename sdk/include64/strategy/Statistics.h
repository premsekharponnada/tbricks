#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Statistics
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Value.h"
#include "strategy/MarketDataParameters.h"

#include "strategy_generated/StatisticsBase.h"

namespace tbricks {

class STRATEGY_EXPORT Statistics : public StatisticsBase
{
public:
    enum SurplusDirection
    {
        BuySurplusDirection = 1,    ///< Surplus on buy side.
        SellSurplusDirection = 2,   ///< Surplus on sell side.
        NoneSurplusDirection = 3,   ///< No surplus on either side.
        UnknownSurplusDirection = 4 ///< The surplus can not be identified, calculated or is otherwise undefined.
    };

public:
    Statistics() = default;
    using StatisticsBase::Merge;
    using StatisticsBase::StatisticsBase;

    /**
     *  @brief  Test equivalence of two statistics objects.
     *  @param lhs  First statistics.
     *  @param rhs  Second statistics.
     *  @return  True if @a lhs.compare(@a rhs) == 0.  False otherwise.
     */
    bool operator==(const Statistics & statistics) const;

    /**
     *  @brief  Test difference of two statistics objects.
     *  @param lhs  First statistics.
     *  @param rhs  Second statistics.
     *  @return  True if @a lhs.compare(@a rhs) == 0.  False otherwise.
     */
    bool operator!=(const Statistics & statistics) const;

    void SetLastPriceAndVolume(const Price & price, const Volume & volume);

    /**
     * Check if field is set
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasIndicativeAuctionSurplusDirection() const;

    /**
     * Return indicative auction surplus direction.
     * Direction can be sell, buy, none or unknown.
     *
     * @return                           Indirative auction surplus direction or
     *                                   empty object if the direction is not avaliable.
     */
    SurplusDirection GetIndicativeAuctionSurplusDirection() const;

    /**
     * %Set indicative auction surplus direction.
     *
     * @param value                      Value of indicative auction surplus direction.
     */
    void SetIndicativeAuctionSurplusDirection(const SurplusDirection & value);

    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const Statistics::SurplusDirection & direction);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMinimumShortSellPrice() const;

    /**
     * Get minimum short sell price.
     *
     *
     * @return                          minimum short sell price
     */
    Price GetMinimumShortSellPrice() const;

    /**
     * %Set minimum short sell price.
     *
     *
     * If the passed value is empty, the field in the request
     * will be deleted.
     *
     * @param value                     minimum short sell price
     */
    void SetMinimumShortSellPrice(const Price & value);
};
}

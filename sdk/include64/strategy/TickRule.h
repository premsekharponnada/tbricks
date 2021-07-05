#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TickRule type.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/ComparisonResult.h"

#include <memory>

// \namespace tbricks
namespace tbricks {

class Price;
class Volume;
class TickCount;

class STRATEGY_EXPORT TickRule : public Printable
{
public:
    TickRule();
    TickRule(const TickRule & rule);
    ~TickRule() override;

    TickRule & operator=(const TickRule & rule);

public:
    /**
     * Check emptiness.
     *
     * @return                          "true" if the object is not
     *                                  resolved, "false" otherwise
     */
    bool Empty() const;
    void Clear();

public:
    /**
     * Get Tick Rule identifier.
     *
     * @return                          Tick Rule identifier
     */
    String GetIdentifier() const;

    /**
     * Round up price according to the tick rules.
     *
     * Rounds the argument upwards to the nearest (greater) valid price. If
     * provided value is already a valid price, it is returned as the operation
     * result.
     *
     * If the object is not resolved (is empty), returned value is
     * the same as the argument.
     *
     * Note: Empty argument results in undefined behavior.
     *
     * @param price                     Value to round up
     * @return                          Operation result
     */
    Price RoundUp(const Price & price) const;

    /**
     * Round down price according to the tick rules.
     *
     * Rounds the argument downwards to the nearest (lower) valid price. If
     * provided value is already a valid price, it is returned as the operation
     * result.
     *
     * If the object is not resolved (is empty), returned value is
     * the same as the argument.
     *
     * Note: Empty argument results in undefined behavior.
     *
     * @param price                     Value to round down
     * @return                          Operation result
     */
    Price RoundDown(const Price & price) const;

    /**
     * Round down price according to the tick rules.
     *
     * Rounds the argument downwards to the nearest (lower) half-tick price.
     * If provided value is already a valid price, it is returned as the operation
     * result.
     *
     * If the object is not resolved (is empty), returned value is
     * the same as the argument.
     *
     * Note: Empty argument results in undefined behavior.
     *
     * @param price                     Value to round down
     * @return                          Operation result
     */
    Price RoundDownToHalftick(const Price & price) const;

    /**
     * Round price to the nearest valid price.
     *
     * Rounds the argument to the nearest valid price, either greater or lower
     * depending on the distance to the nearest valid value.  If provided value
     * is already a valid price, it is returned as the operation result.
     *
     * If the object is not resolved (is empty), returned value is
     * the same as the argument.
     *
     * Note: Empty argument results in undefined behavior.
     *
     * @param price                     Value to round
     * @return                          Operation result
     */
    Price Round(const Price & price) const;

    /**
     * Check price validity.
     *
     * Returns "true" if the argument's value is aligned to the tick rules.
     * Empty argument is always considered invalid.
     *
     * If the object is not resolved (is empty), result is undefined.
     *
     * @param price                     Value to check
     * @return                          Operation result
     */
    bool Valid(const Price & price) const;

    /**
     * Increase price by one tick.
     *
     * If price is valid (that is, aligned according to the tick rules) then
     * the argument is increased by one step; otherwise, the value is rounded
     * up to the next valid value.
     *
     * If the object is not resolved (is empty), returned value is
     * the same as the argument.
     *
     * Note: Empty argument results in undefined behavior.
     *
     * @see RoundUp
     *
     * @param price                     Value to round up
     * @return                          Operation result
     */
    Price Up(const Price & price) const;

    /**
     * Decrease price by one tick.
     *
     * If price is valid (that is, aligned according to the tick rules) then
     * the argument is decreased by one step; otherwise, the value is rounded
     * down to the next valid value.
     *
     * If the object is not resolved (is empty), returned value is
     * the same as the argument.
     *
     * Note: Empty argument results in undefined behavior.
     *
     * @see RoundDown
     *
     * @param price                     Value to round down
     * @return                          Operation result
     */
    Price Down(const Price & price) const;

    /**
     * Change price by specified number of ticks.
     *
     * Depending on "ticks" sign, the call is equivalent to Up() or Down()
     * methods applied "ticks" times.
     *
     * If object is not resolved (empty), method has no effect.
     *
     * Note: Empty argument results in undefined behavior.
     *
     * @param price                     Value to round up
     * @param ticks                     Number of ticks
     * @return                          Operation result
     */
    Price Tick(const Price & price, const TickCount & ticks) const;

    /**
     * Get upper tick rule limit.
     *
     * Returns the nearest greater price for which the tick value will be
     * different than for "price".
     *
     * If such price does not exist (price is beyond of tick rule table),
     * the method returns "false".
     *
     * If object is not resolved (empty), method has no effect.
     *
     * Note: Empty "price" argument results in undefined behavior.
     *
     * @param price                     Price value for limit calcualtion
     * @param limit                     Limit value
     * @return                          "true" if limit is found, "false"
     *                                  if it doesn't exist
     */
    bool UpLimit(const Price & price, Price & limit) const;

    /**
     * Get lower tick rule limit.
     *
     * Returns the nearest lower price for which the tick value will be
     * still the same as for "price".
     *
     * If such price does not exist (price is beyond of tick rule table),
     * the method returns "false".
     *
     * If object is not resolved (empty), method has no effect.
     *
     * Note: Empty "price" argument results in undefined behavior.
     *
     * @param price                     Price value for limit calcualtion
     * @param limit                     Limit value
     * @return                          "true" if limit is found, "false"
     *                                  if it doesn't exist
     */
    bool DownLimit(const Price & price, Price & limit) const;

    /**
     * Get tick value.
     *
     * Returns value of a tick for "price" value increment.
     *
     * If object is not resolved (empty), method has no effect.
     *
     * Note: Empty "price" argument results in undefined behavior.
     *
     * @param price                     Price value
     * @return                          Tick value
     */
    Price UpTick(const Price & price) const;

    /**
     * Get tick value.
     *
     * Returns value of a tick for "price" value decrement.
     *
     * If object is not resolved (empty), method has no effect.
     *
     * Note: Empty "price" argument results in undefined behavior.
     *
     * @param price                     Price value
     * @return                          Tick value
     */
    Price DownTick(const Price & price) const;

    /**
     * Compare prices.
     *
     * Method performs price comparison based on price precision provided
     * by the market.
     *
     * @param price1                    Price value
     * @param price2                    Price value
     * @return                          TB_LESS_THAN    if price1 < price2
     *                                  TB_EQUAL        if price1 == price2  or both prices are empty
     *                                  TB_GREATER_THAN if price1 > price2
     *                                  TB_UNDEFINED    if only one of prices is empty
     */
    ComparisonResult ComparePrices(Price price1, Price price2) const;

    /**
     * Get precision.
     *
     * Returns value precision used for price comparison.
     *
     * @see ComparePrices
     *
     * @return                          Precision value
     */
    double GetPrecision() const;

    /**
     * Get number of ticks between prices.
     *
     * Returns complete tick count between rounded prices.
     * Return positive count if second value bigger than first,
     * negative - otherwise.
     *
     * @param price1                    First price value
     * @param price2                    Second price value
     *
     * @return                          Tick count
     */
    TickCount GetTickCount(const Price & price1, const Price & price2) const;

    /**
     * Get default tick value.
     *
     * If object is not resolved (empty), method returns empty price.
     *
     * @return                          Tick value
     */
    Price GetDefaultTick() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

    class Impl;

private:
    friend Impl;
    std::shared_ptr<Impl> m_impl;
};

} // \namespace tbricks

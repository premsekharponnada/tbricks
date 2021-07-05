#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy validation API.
//****************************************************************************************

#include <set>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Parameters.h"

// \namespace tbricks
namespace tbricks {

namespace strategy {
class ValidationItemImpl;
}

/**
 * ValidationItem object provides complete description on operations request
 * originator is allowed to perform on strategy parameter the item is
 * associated with.
 */
class STRATEGY_EXPORT ValidationItem : public Printable
{
public:
    /**
     * Create a new empty editable item associated with a strategy parameter.
     *
     * @param definition                Strategy parameter definition
     */
    ValidationItem(const ParameterDefinition & definition);
    ValidationItem(const ValidationItem & vi);
    virtual ~ValidationItem();

    ValidationItem & operator=(const ValidationItem & vi);

    /**
     * Get parameter definition.
     *
     * @return                          Parameter definition
     */
    const ParameterDefinition & GetParameterDefinition() const;

    /**
     * %Set item value.
     *
     * The call completely replaces old value of the item, no matter was it
     * a single value or a list of values, and clears the list of valid
     * values.
     *
     * If the value is empty, the call has no effect.
     *
     * @param value                     Strategy API type value
     */
    void SetValue(const AnyType & value);

    /**
     * Get item value.
     *
     * Retrieves current validation item value, which could be empty.
     * Method returns "false" if provided value type is not correct. The
     * following code takes advantage of this feature:
     *
     * @code
     * Price price;
     * if (price_item.GetValue(price)) {
     *     m_price = price;
     * }
     * int count = price_item.GetIncrementCount();
     * if (count != 0) {
     *     m_price = GetTickRule().Tick(m_price, count);
     * }
     * @endcode
     *
     * @param value                     Method result
     */
    bool GetValue(AnyType & value) const;

    int GetIncrementCount() const;

    template <typename ParameterT>
    void ApplyDefaultIncrement(const ParameterT & parameter)
    {
        int count = GetIncrementCount();
        if (count != 0) {
            typename ParameterT::ValueType value;
            if (GetValue(value) && !value.Empty()) {
                value += parameter.GetDefaultIncrement() * count;
                SetValue(value);
            }
        }
    }

    /**
     * Add a new value to the list of valid item values.
     *
     * The call allows to specify a list of values applicable to the validation
     * item.
     *
     * Adding a value of a type different from the type of other values,
     * including the one set by ValidationItem::SetValue() method, yields
     * undefined behavior.
     *
     * If value is empty, the call has no effect.
     *
     * @param value                     Item value
     */
    void AddValidValue(const AnyType & value);

    /**
     * %Set item value and list of valid values.
     *
     * The call allows to set the value of validation item
     * and list of values applicable to the validation item
     * at the same time to the same value.
     *
     * @param value                     Item value
     */
    void SetValidValue(const AnyType & value);

    /**
     * Check if value of item is valid.
     *
     * Check if value of validation item is in list of values applicable to the item.
     *
     * @result                          'true' if the value is in list of valid values,
     *                                  'false' otherwise
     */
    bool IsValueValid();

    /**
     * Clear the value of validation item.
     */
    void ClearValue();

    /**
     * Clear list of valid values.
     */
    void ClearValidValues();

    /**
     * Clear item.
     *
     * Removes all values previously set or added to the item.
     *
     * This method is particularly useful when a strategy can suggest no value
     * for the parameter and the user input was not correct either.
     */
    void Clear();

    /**
     * Check for emptiness.
     *
     * ValidationItem considered to be empty if it has no suggested value(s)
     * set.
     *
     * @return                          'true' after Clear() method or if
     *                                   an item has no any values, 'false'
     *                                   otherwise
     */
    bool Empty() const;

    /**
     * %Set parameter direction.
     *
     * @param direction                 Parameter direction
     */
    void SetDirection(ParameterDefinition::Direction direction);

    /**
     * Add valid values.
     *
     * Convenience method to apply containers of %Strategy Framework data types at
     * once, comes handy when the item being resolved is likely to have more
     * than one value, for instance, if strategy can trade on more than one
     * venue:
     *
     * @code
     *  ValidationItem & venue_item = context.GetItem(m_venue.GetDefinition());
     *
     *  std::vector<Venue> venue_ids;
     *  instrument.GetTradingVenues(venue_ids);
     *  if (venue_ids.size() > 0)
     *  {
     *     venue_item.AddValidValues(venue_ids);
     *  }
     *  else
     *  {
     *      venue_item.SetDirection(ParameterDefinition::OUTPUT);
     *      venue_item.SetValue(Venue());
     *  }
     * @endcode
     *
     * @param values                 container of %Strategy Framework data types
     *                               (passed container must have begin() and end() methods)
     */
    template <typename TYPE>
    void AddValidValues(const TYPE & values)
    {
        for (const auto & it : values) {
            AddValidValue(it);
        }
    }

    /**
     * Add valid values.
     *
     * Convenience method to apply vectors of LiquidityPool objects at once.
     *
     * example:
     *
     * @code
     * const tbricks::TradingCapabilities& c = v.GetTradingCapabilities();
     * std::vector<LiquidityPool> liquidityPools;
     * c.GetLiquidityPools( liquidityPools);
     *
     * ValidationItem& poolsItem = context.GetItem( m_liquidityPool);
     * poolsItem.AddValidValues( liquidityPools);
     * @endcode
     *
     * By the fact AddValidValues adds LiquidityPoolIdentifiers (not LiquidityPools).
     *
     * @param values                 vector of LiquidityPool objects
     */
    void AddValidValues(const std::vector<LiquidityPool> & values);

    /**
     * %Set list of valid values.
     *
     * Change list of valid values,
     * clear value of validation item if it's not valid.
     *
     * @param values                    Vector of valid values
     */
    template <typename TYPE>
    void SetValidValues(const std::vector<TYPE> & values)
    {
        // remove duplicates
        std::set<TYPE> unique(values.begin(), values.end());
        ClearValidValues();

        // add all values
        for (const auto & it : values) {
            AddUniqueValidValue(it);
        }

        // valid values should contain the value
        if (!IsValueValid()) {
            ClearValue();
        }
    }

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    ValidationItem(const strategy::ValidationItemImpl & impl);
    strategy::ValidationItemImpl & get_value() const;

private:
    void AddUniqueValidValue(const AnyType & value);

protected:
    strategy::ValidationItemImpl * m_impl;
};

} // \namespace tbricks

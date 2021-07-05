#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy validation API, Validity part.
//****************************************************************************************

#include <set>

#include "strategy/Types.h"
#include "strategy/Parameters.h"
#include "strategy/ValidityTypeSet.h"

// \namespace tbricks
namespace tbricks {

namespace strategy {
class ValidityValidationItemImpl;
}

/**
 * ValidityValidationItem object controls strategy validity settings.
 */
class STRATEGY_EXPORT ValidityValidationItem : public Printable
{
public:
    ValidityValidationItem();
    ValidityValidationItem(const ValidityValidationItem & vvi);
    ~ValidityValidationItem();

    ValidityValidationItem & operator=(const ValidityValidationItem & vvi);

    /**
     * %Set validity.
     *
     * The call completely replaces old value of the item, no matter was it
     * a single value or a list of values, and clears the list of valid
     * values.
     *
     * If the value is empty, the call has no effect.
     *
     * @param validity                  Validity
     */
    void SetValidity(const Validity & validity);

    /**
     * Get validity.
     *
     * Return validity value suggested by a user, which could be empty if
     * there was no value set.
     *
     * @return                          Suggested validity
     */
    Validity & GetValidity();

    /**
     * %Set available validity types.
     *
     * If value is empty, the call has no effect.
     *
     * @param set                       Set of available validity types
     */
    void SetAllowedValidityTypes(const ValidityTypeSet & set);

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
     * ValidityValidationItem considered to be empty if it has no suggested
     * value(s) set.
     *
     * @return                          'true' after Clear() method or if
     *                                   an item has no any values, 'false'
     *                                   otherwise
     */
    bool Empty() const;

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    ValidityValidationItem(const strategy::ValidityValidationItemImpl & impl);
    strategy::ValidityValidationItemImpl & get_value() const;

protected:
    strategy::ValidityValidationItemImpl * m_impl;
};

} // \namespace tbricks

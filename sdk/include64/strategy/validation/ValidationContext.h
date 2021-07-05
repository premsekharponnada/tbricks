#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy validation API.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Parameters.h"
#include "strategy/validation/ValidationItem.h"
#include "strategy/validation/ValidityValidationItem.h"

// \namespace tbricks
namespace tbricks {

namespace strategy {
class ValidationContextImpl;
}

/**
 * ValidationContext is the primary validation entry point. When
 * Strategy::HandleValidateRequest() is called, ValidationContext object
 * contains parameter values provided by the user, i.e. the data that must be
 * validated by the strategy. Validation code shall check if the values are
 * correct and if they are not they should be modified, or removed. Strategy
 * can also suggest values for some parameters even if they are not present in
 * the incoming request -- for instance, if incoming requests has an instrument
 * set, the validation code could suggest a (list of) venue(s) where this
 * instrument can be traded, and so on.
 *
 * @see Strategy::HandleValidateRequest()
 *
 * ValidationContext is a container. Be careful with references on ValidationItems.
 * @code
 * ValidationItem & item = context.GetItem(m_item_def);
 * context.RemoveItem(other_item);
 * if (item.Empty()) { <- crash
 * @endcode
 * If you want to add or remove items, find elements in context before work with them.
 * @code
 * context.RemoveItem(other_item);
 * ValidationItem & item = context.GetItem(m_item_def);
 * if (item.Empty()) {
 * @endcode
 */
class STRATEGY_EXPORT ValidationContext : public Printable
{
public:
    ValidationContext();
    ValidationContext(const std::shared_ptr<strategy::ValidationContextImpl> & impl);
    ~ValidationContext();

public:
    /**
     * Check item presence.
     *
     * Method looks up an item by parameter definition deduced from the
     * argument.
     *
     * @param parameter                 Strategy parameter
     *
     * @return                          'true' if item exists, 'false' otherwise
     */
    bool HasItem(const Parameter & parameter) const;

    /**
     * Check item presence.
     *
     * Method looks up an item by parameter definition.
     *
     * @param definition                Strategy parameter definition
     *
     * @return                          'true' if item exists, 'false' otherwise
     */
    bool HasItem(const ParameterDefinition & definition) const;

    /**
     * Check if context is empty.
     *
     * Method check if context has any item.
     *
     * @return                          'true' if no items exist, 'false' otherwise
     */
    bool Empty() const;

    /**
     * Lookup ValidationContext for an item associated with the parameter,
     * return a reference to an existing object if there is one or create a new
     * one otherwise.
     *
     * All modifications to the reference become immediately effective to
     * the ValidationContext object, i.e. it is not necessary to call
     * AddItem() method to apply the changes. However, if result is copied,
     * changes made to the copy will not affect ValidationContext until
     * AddItem() is called.
     *
     * Since the method returns a reference into ValidationContext internals,
     * calling RemoveItem() for the item and accessing the reference afterwards
     * yields undefined behavior.
     *
     * The call does not modify item value if the item exists, and does not
     * assign a value if item is not available. In the latter case, empty
     * item is returned. However, even if an item was not available, this
     * call adds it into ValidationContext and the item will be returned in
     * the reply even if the value is not assigned to it (in the latter case,
     * an empty value will be returned back to the client).
     *
     * @param parameter                 Strategy parameter
     *
     * @return                          Reference to an editable item stored in
     *                                  ValidationContext
     */
    ValidationItem & GetItem(const Parameter & parameter) const;

    /**
     * Lookup ValidationContext for an item associated with the parameter
     * definition, return a reference to an existing object if there is one or
     * create a new one otherwise.
     *
     * All modifications to the reference become immediately effective to
     * the ValidationContext object, i.e. it is not necessary to call
     * AddItem() method to apply the changes. However, if result is copied,
     * changes made to the copy will not affect ValidationContext until
     * AddItem() is called.
     *
     * Since the method returns a reference into ValidationContext internals,
     * calling RemoveItem() for the item and accessing the reference afterwards
     * yields undefined behavior.
     *
     * The call does not modify item value if the item exists, and does not
     * assign a value if item is not available. In the latter case, empty
     * item is returned. However, even if an item was not available, this
     * call adds it into ValidationContext and the item will be returned in
     * the reply even if the value is not assigned to it (in the latter case,
     * an empty value will be returned back to the client).
     *
     * @param definition                Strategy parameter definition
     *
     * @return                          Reference to an editable item stored in
     *                                  ValidationContext
     */
    ValidationItem & GetItem(const ParameterDefinition & definition) const;

    /**
     * Get validity item.
     *
     * Method returns a reference to an existing item if there is a value
     * in the validation request, or otherwise creates a new one.
     *
     * The call does not modify item value if the item exists, and if it does
     * not, an empty item is returned. However, even if an item was not
     * available, this call adds it into ValidationContext and the item will be
     * returned in the reply even if the value is not assigned to it (in the
     * latter case, an empty value will be returned back to the client).
     *
     * @return                          Reference to an editable item stored in
     *                                  ValidationContext
     */
    ValidityValidationItem & GetValidityItem() const;

    /**
     * Get operator
     *
     * @return                          User
     */
    User GetOperator() const;

    /**
     * Remove item.
     *
     * Permanently remove item from the context.
     *
     * After this operation, it is illegal to use references to the item
     * retrieved by GetItem() method with the same parameter or parameter
     * definition.
     *
     * If parameter has no corresponding item in the context, the call
     * has no effect.
     *
     * @param parameter                 Strategy parameter
     */
    void RemoveItem(const Parameter & parameter);

    /**
     * Remove item.
     *
     * Permanently remove item from the context.
     *
     * After this operation, it is illegal to use references to the item
     * retrieved by GetItem() method with the same parameter or parameter
     * definition.
     *
     * If parameter has no corresponding item in the context, the call
     * has no effect.
     *
     * @param definition                Strategy parameter definition
     */
    void RemoveItem(const ParameterDefinition & definition);

    /**
     * Remove item.
     *
     * Permanently remove item from the context.
     *
     * After this operation, it is illegal to use references to the item
     * being removed previously returned by GetItem() or AddItem().
     *
     * If item is not in the context, the call has no effect.
     *
     * @param item                      Item to remove
     */
    void RemoveItem(const ValidationItem & item);

    /**
     * Send ValidationContext back to the request originator.
     *
     * The method must be executed exactly once per validation request, when
     * ValidationContext object is completely filled with information on all
     * available strategy parameters and their default/suggested/applicable
     * values, if any.
     *
     * @throw exception if is called twice.
     */
    void SendReply() const;

    /**
     * %Apply app template to the strategy.
     *
     * @throws EmptyValueException if app_template is empty
     *
     * @throws NotFoundException if there is no tree node with app_template identifier
     *
     * @throws TypeMismatchException if corresponding tree node is of the type other than App template
     *
     * @param app_template               App template identifier
     *                                   StrategyParameters.
     */
    void ApplyTemplate(const TreeNodeIdentifier & app_template);

    virtual std::ostream & Print(std::ostream & strm) const;

    strategy::ValidationContextImpl * get_impl() const;

private:
    std::shared_ptr<strategy::ValidationContextImpl> m_impl;
    mutable bool m_is_sent = false;
};

} // \namespace tbricks

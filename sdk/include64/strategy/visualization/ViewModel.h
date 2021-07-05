#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// App view model public interface.
//****************************************************************************************

#include <stdint.h>
#include <vector>
#include <memory>

#include "strategy/visualization/ICellValue.h"

#include "strategy/Value.h"
#include "strategy/type/UserIdentifier.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/Variant.h"

namespace tbricks {

class Uuid;
class RowEntityIdentifier;

namespace visualization {

class STRATEGY_EXPORT AppViewModelImpl;

class STRATEGY_EXPORT ViewModel
{
public:
    virtual operator const std::shared_ptr<AppViewModelImpl>() const { return get_model(); }

    /**
     * Get ViewModel identifier
     *
     * @return ViewModel Uuid
     */
    Uuid GetViewModelIdentifier() const;

    /**
     * Get ViewModel owner
     *
     * @return owner user identifier
     */
    UserIdentifier GetOwner() const;

    /**
     * Apply unconfirmed state to data model.
     *
     * @throws InapplicableUnconfirmedValuesException if not all changes can be applied
     *
     * @return number of modified rows
     *
     */
    uint32_t ApplyModifications();

    /**
     * Clears unconfirmed state for view.
     *
     * @return true if container was not empty before cleaning, false otherwise
     */
    bool RejectUnconfirmedModifications();

    /**
     * Get current view model properties
     *
     * @return vector of properties
     */
    const std::vector<CalculatedProperty> & GetCalculatedProperties() const;

    /**
     * Set unconfirmed value for cell in current model
     *
     * @param [in] row_id        Row identifier
     * @param [in] property      CalculatedProperty
     * @param [in] value         Cell value
     *
     * @returns old value if it exists
     */
    Value<Variant> SetUnconfirmedValue(const RowEntityIdentifier & row_id, const CalculatedProperty & property, const Variant & value);

    /**
     * Reset unconfirmed value for cell in current model
     *
     * @param [in] row_id        Row identifier
     * @param [in] property      CalculatedProperty
     *
     * @returns old value if it exists
     */
    Value<Variant> RemoveUnconfirmedValue(const RowEntityIdentifier & row_id, const CalculatedProperty & property);

    /**
     * Set valid values for cell in current model
     *
     * @param [in] row_id        Row identifier
     * @param [in] property      CalculatedProperty
     * @param [in] values        Vector of valid values
     *
     * @returns old value if it exists
     */
    void SetValidValues(const RowEntityIdentifier & row_id, const CalculatedProperty & property, const std::vector<Variant> & values);

    /**
     * Clears valid values for cell in current model
     *
     * @param [in] row_id        Row identifier
     * @param [in] property      CalculatedProperty
     *
     */
    void ClearValidValues(const RowEntityIdentifier & row_id, const CalculatedProperty & property);

    /**
     * Set direction for cell in current model
     *
     * @param [in] row_id        Row identifier
     * @param [in] property      CalculatedProperty
     * @param [in] direction     Cell value direction
     *
     */
    void SetDirection(const RowEntityIdentifier & row_id, const CalculatedProperty & property, CellValueDirection direction);

    /**
     * Tries to get unconfirmed value from current model
     *
     * @param [in] row_id        Row identifier
     * @param [in] property      CalculatedProperty
     *
     * @returns value if it exists
     */
    Value<Variant> TryGetUnconfirmedValue(const RowEntityIdentifier & row_id, const CalculatedProperty & property) const;

    /**
     * Get source strategy identifier.
     *
     * @return Strategy identifier
     *
     */
    std::optional<StrategyIdentifier> GetSourceStrategyIdentifier() const;

    /**
     * Get source view model identifier.
     *
     * @returns source view model identifier
     */
    std::optional<Uuid> GetSourceViewModelIdentifier() const;

    /**
     * Returns identifier of app that created view model via RemoteAppView or RemoteGridView class.
     * Return value is empty if view model was created otherwise.
     *
     * @returns originating app identifier
     */
    std::optional<StrategyIdentifier> GetOriginatingAppIdentifier() const;

    /**
     * Returns definition identifier of app that created view model via RemoteAppView or RemoteGridView class.
     * Return value is empty if view model was created otherwise.
     *
     * @returns originating app definition identifier
     */
    std::optional<StrategyIdentifier> GetOriginatingAppDefinitionIdentifier() const;

    virtual ~ViewModel() = default;

protected:
    ViewModel() = default;

    ViewModel(const ViewModel & other) = default;

    ViewModel(ViewModel && other) noexcept = default;

    ViewModel & operator=(const ViewModel & other) = default;

    ViewModel & operator=(ViewModel && other) noexcept = default;

    virtual std::shared_ptr<AppViewModelImpl> get_model() const = 0;
};

} // namespace visualization
} // namespae tbricks

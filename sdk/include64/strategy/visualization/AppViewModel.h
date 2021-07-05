#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// App view model public interface.
//****************************************************************************************

#include "strategy/visualization/ViewModel.h"
#include "strategy/Value.h"
#include "strategy/type/Variant.h"
#include "strategy/Linkage.h"

namespace tbricks {
class Variant;
class CalculatedPropertyDefinition;
class Uuid;

namespace visualization {
class ViewModelUpdate;

class AppViewModelImpl;
class AppLayoutViewModel;

namespace models {

class STRATEGY_EXPORT AppViewModel : public ViewModel
{
public:
    AppViewModel(const std::shared_ptr<visualization::AppLayoutViewModel> & app_view_model);

    AppViewModel(const AppViewModel & other) = default;
    AppViewModel(AppViewModel && other) noexcept = default;
    AppViewModel & operator=(const AppViewModel & other) = default;
    AppViewModel & operator=(AppViewModel && other) noexcept = default;

    friend bool operator==(const AppViewModel & lhs, const AppViewModel & rhs) { return lhs.m_app_view_model == rhs.m_app_view_model; }

    /**
     * Get row identifier for IAppViewModel single-row view
     *
     * @note usually row identifier coincides with the app identifier
     */
    const Uuid & GetRowIdentifier() const;

    /**
     * Mege view model update to unconfirmed values
     *
     * @note existing unconfirmed values will be overriden
     *
     */
    void MergeUpdate(const ViewModelUpdate & update);

    /**
     * Set valid values for cell in current model
     *
     * @param [in] property      CalculatedProperty
     * @param [in] values        Vector of valid values
     *
     * @returns old value if it exists
     */
    void SetValidValues(const CalculatedProperty & property, const std::vector<Variant> & values);

    /**
     * Clears valid values for cell in current model
     *
     * @param [in] property      CalculatedProperty
     *
     */
    void ClearValidValues(const CalculatedProperty & property);

    /**
     * Set unconfirmed value for cell in current model
     *
     * @param [in] property      CalculatedProperty
     * @param [in] value         Cell value
     *
     * @returns old value if it exists
     */
    Value<Variant> SetUnconfirmedValue(const CalculatedProperty & property, const Variant & value);

    /**
     * Reset unconfirmed value for cell in current model
     *
     * @param [in] property      CalculatedProperty
     *
     * @returns old value if it exists
     */
    Value<Variant> RemoveUnconfirmedValue(const CalculatedProperty & property);

    /**
     * Tries to get unconfirmed value from current model
     *
     * @param [in] property      CalculatedProperty
     *
     * @returns value if it exists
     */
    Value<Variant> TryGetUnconfirmedValue(const CalculatedProperty & property) const;

    /**
     * Set direction for cell in current model
     *
     * @param [in] property      CalculatedProperty
     * @param [in] direction     Cell value direction
     *
     */
    void SetDirection(const CalculatedProperty & property, CellValueDirection direction);

    /**
     * Get a property value if it exists
     *
     */
    Value<Variant> GetValue(const CalculatedProperty & property) const;

    /**
     * Set stream limit for the app
     *
     * @param [in]  limit Maximum amount of streams that app can open.
     *                    Stream limitations will be discarded if this parameter is passed as empty Integer.
     *
     * @throws TypeInitializationException if provided integer is less than zero
     */
    void SetStreamLimit(const Integer & limit);

    operator const std::shared_ptr<tbricks::visualization::AppLayoutViewModel>() const;

private:
    std::shared_ptr<AppViewModelImpl> get_model() const override;

    std::shared_ptr<AppLayoutViewModel> m_app_view_model;
};

} // namespace models
} // namespace visualization
} // namespace tbricks

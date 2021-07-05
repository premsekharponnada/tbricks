#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Header row public interface.
//****************************************************************************************

#include <memory>

#include "strategy/visualization/ViewModel.h"

namespace tbricks { namespace visualization {

namespace models {
class GridViewModel;
}

class GridViewModel;

class STRATEGY_EXPORT HeaderRow
{
public:
    /**
     * Set valid values for column
     *
     * @param [in] property      CalculatedProperty
     * @param [in] values        Vector of valid values
     *
     * @returns old value if it exists
     */
    void SetValidValues(const CalculatedProperty & property, const std::vector<Variant> & values);

    /**
     * Clears valid values for column
     *
     * @param [in] property      CalculatedProperty
     *
     */
    void ClearValidValues(const CalculatedProperty & property);

    /**
     * Set direction for column
     *
     * @param [in] property      CalculatedProperty
     * @param [in] direction     Cell value direction
     *
     */
    void SetDirection(const CalculatedProperty & property, CellValueDirection direction);

    /**
     * Reset direction for column
     *
     * @param [in] property      CalculatedProperty
     * @param [in] direction     Cell value direction
     *
     */
    void ResetDirection(const CalculatedProperty & property);

    /**
     * Set default value for column
     *
     * @param [in] property      CalculatedProperty
     * @param [in] value         Cell value
     *
     */
    void SetDefaultValue(const CalculatedProperty & property, const Variant & value);

    /**
     * Reset default value for column
     *
     * @param [in] property      CalculatedProperty
     *
     */
    void ResetDefaultValue(const CalculatedProperty & property);

private:
    friend models::GridViewModel;

    HeaderRow(visualization::GridViewModel & model) : m_model(model) {}

    HeaderRow(const HeaderRow & other) = default;
    HeaderRow(HeaderRow && other) noexcept = default;

    visualization::GridViewModel & m_model;
};

} // namespace visualization
} // namespace tbricks

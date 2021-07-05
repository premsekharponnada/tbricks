#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Grid view model public interface.
//****************************************************************************************

#include "strategy/visualization/ViewModel.h"
#include "strategy/visualization/HeaderRow.h"

namespace tbricks {

class GridParameterDefinition;
class Variant;
class ColumnIdentifier;
class RowEntityIdentifier;

namespace visualization {

class ViewModelUpdate;

class GridViewModel;
class AppViewModelImpl;

namespace models {

class STRATEGY_EXPORT GridViewModel : public ViewModel
{
public:
    GridViewModel(const std::shared_ptr<visualization::GridViewModel> & model);

    GridViewModel(const GridViewModel & other) = default;
    GridViewModel(GridViewModel && other) noexcept = default;
    GridViewModel & operator=(const GridViewModel & other) = default;
    GridViewModel & operator=(GridViewModel && other) noexcept = default;

    friend bool operator==(const GridViewModel & lhs, const GridViewModel & rhs) { return lhs.m_grid_view_model == rhs.m_grid_view_model; }

    /**
     * Get identifier of grid view parameter
     */
    const GridParameterDefinition & GetGridParameterDefinition() const;

    /**
     * Mege view model update to unconfirmed values
     *
     * @note existing unconfirmed values will be overriden
     *
     */
    void MergeUpdate(const ViewModelUpdate & update);

    /**
     * Get all identifiers of all rows identifiers that contain unconfirmed values
     */
    std::vector<Uuid> GetUnconfirmedRowsIdentifiers() const;

    /**
     * Get a property value if it exists
     *
     * @returns Variant value or empty Value if there is no row or its value
     */
    Value<Variant> GetValue(const RowEntityIdentifier & row_id, const CalculatedProperty & property) const;

    /**
     * Get header row, these values will be applied to all columns of the model
     */
    HeaderRow GetHeaderRow();

    /**
     * Sorted vector of selected rows identifiers
     */
    std::vector<RowEntityIdentifier> GetSelectedRows();

    /**
     * Clear selection
     */
    void ClearSelection();

private:
    /**
     * Clear and set selection for columns
     */
    void SetSelectedColumns(const std::vector<ColumnIdentifier> & aliases);

    /**
     * Add column to celection
     */
    void SelectColumn(const ColumnIdentifier alias);

    /**
     * Sorted vector of selected columns aliases
     */
    std::vector<ColumnIdentifier> GetSelectedColumns();

    /**
     * Set range based selection
     */
    void SetSelectedRows(const std::vector<RowEntityIdentifier> & row_ids);

    /**
     * Add row to selection
     */
    void SelectRow(const RowEntityIdentifier & row_id);

    /**
     * Select all cells in grid
     */
    void SelectAll();

    /**
     * Set custom selection
     *
     * @note it overrides any range-based (rows and columns) selection
     */
    void SetCustomSelection(const RowEntityIdentifier & row_id, const ColumnIdentifier & column_id, bool selected);

    /**
     * Inverse current selection
     */
    void SetSelectionInverted();

    /**
     * Inverse current selection
     */
    void ResetSelectionInverted();

    operator const std::shared_ptr<tbricks::visualization::GridViewModel>() const;

    std::shared_ptr<AppViewModelImpl> get_model() const override;

    std::shared_ptr<visualization::GridViewModel> m_grid_view_model;
};

} // namespace models
} // namespace visualization
} // namespace tbricks

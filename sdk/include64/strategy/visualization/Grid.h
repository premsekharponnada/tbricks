#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Grid interface.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Strategy.h"
#include "strategy/visualization/GridViewModel.h"
#include "strategy/visualization/RowEntity.h"
#include "strategy/GridParameterDefinition.h"

namespace tbricks {
class VisualizationApp;
namespace visualization {

class ViewModelUpdate;
class AppViewModelManagerImpl;
class VisualizationAppRowEntity;
class OrderBookHandler;

/**
 * Grid class provides an interface for interacting with grid parameter.
 *
 */
class STRATEGY_EXPORT Grid
{
public:
    friend VisualizationApp;
    friend OrderBookHandler;

    Grid(const GridParameterDefinition & grid_parameter_definition, VisualizationApp & app_view_model_manager) :
        m_grid_parameter(grid_parameter_definition),
        m_manager(app_view_model_manager)
    {}

    Grid(const Grid & other) = default;

    Grid(Grid && other) = delete;
    Grid & operator=(const Grid & other) = delete;
    Grid & operator=(Grid && other) = delete;

    /**
     * Add row to view manager and all grids associated with grid parameter handler
     *
     * @param [in]  entity row entity from RowBasedDataSource
     *
     * @throws RowIsPresentInGridParameterException if row entity was already added
     *
     */
    void AddRow(const RowEntity & entity);

    /**
     * Add row to view manager and all grids associated with grid parameter
     *
     * @param [in]  parent_id identifier of parent row entity on grid
     * @param [in]  child_entity row entity from RowBasedDataSource
     *
     * @throws RowIsPresentInGridParameterException if row entity was already added
     *
     */
    void AddChildRow(const RowEntityIdentifier & parent_id, const RowEntity & child_entity);

    /**
     * Get row entity by identifier
     *
     * @param [in]  id row entity identifier
     *
     * @return optional object with row entity if row with corresponding id is present in grid, empty otherwise
     *
     */
    std::optional<RowEntity> GetRowEntity(const RowEntityIdentifier & id) const;

    /**
     * Get view models associated with grid parameter.
     *
     * @return vector of all grid view models associated with grid parameter.
     *
     */
    std::vector<models::GridViewModel> GetGridViewModels() const;

    /**
     * Set filter to view manager and all grids associated with grid parameter
     *
     * @param [in]  filter CalculatedPropertyFilter
     *
     *
     */
    void SetFilter(const CalculatedPropertyFilter & filter);

    /**
     * Set parameters associated with grid parameter definition.
     *
     * @param [in]  parameters grid parameters
     *
     *
     */
    void SetParameters(const StrategyParameters & parameters);

    /**
     * Remove row from all grids associated with parameter if exists
     *
     * @param [in]  row_id RowEntityIdentifier
     *
     */
    void RemoveRow(const RowEntityIdentifier & row_id);

    /**
     * Remove all rows from grid
     */
    void RemoveAllRows();

    /**
     * Suspend all grids associated with parameter so that updates won't be propagated until Resume() is called.
     * Set grid is in snapshot state.
     */
    void Suspend();

    /**
     * Resume all grids associated with parameter. Set grid snapshot done.
     */
    void Resume();

    class STRATEGY_EXPORT const_iterator
    {
    public:
        const_iterator();
        const_iterator(const const_iterator & iterator);
        ~const_iterator();

        const_iterator & operator=(const const_iterator & iterator);

        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        RowEntity operator*() const;

        RowEntity GetRowEntity() const;

    private:
        class IteratorImpl;
        std::unique_ptr<IteratorImpl> m_impl;

        friend Grid;
        explicit const_iterator(std::unique_ptr<IteratorImpl> &&);
    };

    const_iterator begin() const;
    const_iterator end() const;

private:
    GridParameterDefinition m_grid_parameter;
    VisualizationApp & m_manager;
};

} // \namespace visualization
} // \namespace tbricks

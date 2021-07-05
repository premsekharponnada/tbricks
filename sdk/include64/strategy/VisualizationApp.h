#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// AppViewModel Manager.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Strategy.h"
#include "strategy/visualization/StrategyRowEntity.h"
#include "strategy/visualization/AppViewModel.h"
#include "strategy/visualization/GridViewModel.h"
#include "strategy/visualization/RowEntity.h"

namespace tbricks {

namespace visualization {

class ViewModelUpdate;
class AppViewModelManagerImpl;
class VisualizationAppRowEntity;
class OrderBookHandler;
class Grid;
}

class STRATEGY_EXPORT VisualizationApp : public Strategy
{
public:
    VisualizationApp();

    virtual ~VisualizationApp();

    VisualizationApp(const VisualizationApp & src) = delete;
    VisualizationApp & operator=(const VisualizationApp & src) = delete;

    /**
     * Set value for property.
     *
     * @note this call is related to view models only, not strategy instance or it's parameters
     */
    void SetCustomValue(const CalculatedProperty & property, const AnyType & value);

    /**
     * Get value for property
     *
     * @returns true if property exists, false otherwise.
     *
     * @note this call is related to view models only, not strategy instance or it's parameters
     */
    bool GetCustomValue(const CalculatedProperty & property, AnyType & value) const;

    /**
     * Is value for property is present
     *
     * @returns true if property exists, false otherwise.
     */
    bool HasCustomValue(const CalculatedProperty & property) const;

    /**
     * Clears property value
     * @returns true if property exists, false otherwise
     */
    bool ClearCustomValue(const CalculatedProperty & property);

    /**
     * Check values container for emptiness.
     *
     * @return                          True if there are no values set the
     *                                  visualization app, false otherwise.
     */
    bool HasCustomValues() const;

    /**
     * Clear all properties data.
     *
     * After this call container is guaranteed to contain no data, and HasValues()
     * method will return False if called.
     */
    void ClearCustomValues();

    /**
     * Get StrategyRowEntity which represents the current application
     */
    visualization::StrategyRowEntity GetAppEntity();

    /**
     * Find already existing AppViewModel.
     *
     * @throws NotFoundException if view model does not exists
     */
    visualization::models::AppViewModel GetAppModel(const Uuid & view_id) const;

    /**
     * Find already existing GridViewModel.
     *
     * @throws NotFoundException if view model does not exists
     */
    visualization::models::GridViewModel GetGridModel(const Uuid & view_id) const;

    /**
     * Calculate a property value for current app if it exists and can be resolved
     *
     * @param [in] property  property to resolve
     * @param [in] on_ready  callback function for resolved value
     */
    void GetValue(const CalculatedProperty & property, std::function<void(const Value<Variant> &)> on_ready) const;

    /**
     * Set app model is in snapshot state
     *
     * @returns value of current snapshot counter
     */
    uint64_t BeginSnapshot();

    /**
     * Set app model snapshot done
     *
     * @returns value of current snapshot counter
     */
    uint64_t EndSnapshot();

    /**
     * Calculate a property value if it exists and can be resolved
     *
     * @param [in] entity    base entity for property resolve
     * @param [in] property  property to resolve
     * @param [in] on_ready  callback function for resolved value
     */
    void GetValue(const visualization::RowEntity & entity,
                  const CalculatedProperty & property,
                  std::function<void(const Value<Variant> &)> on_ready) const;

protected:
    /**
     * ViewModel app view create event.
     *
     * Called when a new app model is created.
     *
     * @param [in] view_model AppViewModel view model
     * @param [in] update ViewModelUpdate view model initial values
     */
    virtual void HandleStrategyViewCreate(visualization::models::AppViewModel & view_model, const tbricks::visualization::ViewModelUpdate & update);

    /**
     * ViewModel app view update event.
     *
     * Called when the app model data has been changed.
     *
     * @param [in] view_model AppViewModel view model
     * @param [in] update ViewModelUpdate view model updated values
     */
    virtual void HandleStrategyViewUpdate(visualization::models::AppViewModel & view_model, const tbricks::visualization::ViewModelUpdate & update);

    /**
     * ViewModel app view delete event.
     *
     * Called before the model is deleted.
     *
     * @param [in] view_model AppViewModel view model
     */
    virtual void HandleStrategyViewDelete(visualization::models::AppViewModel & view_model);

    /**
     * ViewModel grid view create event.
     *
     * Called when a new grid model is created.
     *
     * @param [in] view_model GridViewModel view model
     * @param [in] update updateViewModelUpdate view model initial values
     */
    virtual void HandleGridViewCreate(visualization::models::GridViewModel & view_model, const tbricks::visualization::ViewModelUpdate & update);

    /**
     * ViewModel grid view update event.
     *
     * Called when the app model data has been changed.
     *
     * @param [in] view_model GridViewModel view model
     * @param [in] update ViewModelUpdate view model updated values
     */
    virtual void HandleGridViewUpdate(visualization::models::GridViewModel & view_model, const tbricks::visualization::ViewModelUpdate & update);

    /**
     * ViewModel grid view delete event.
     *
     * Called before the model is deleted.
     *
     * @param [in] view_model GridViewModel view model
     */
    virtual void HandleGridViewDelete(visualization::models::GridViewModel & view_model);

    /**
     * Base implementation for old apps with ValidationProtocol support
     *
     * @note uou do not need to override this method if you have not used it
     * before the AppViewModel was added
     */
    void HandleValidateRequest(tbricks::ValidationContext & context) override;

    /**
     * ValidateViewModel if this parameters changed
     *
     * @param [in] definitions parameters definitions the change of which
     * leads to HandleValidateRequest call fallback
     *
     * @note uou do not need to use this method if you have not used it
     * before the AppViewModel was added
     */
    void SetValidationDefinitions(std::vector<ParameterDefinition> definitions);

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

        visualization::models::AppViewModel operator*() const;

        visualization::models::AppViewModel GetModel() const;

    private:
        class IteratorImpl;
        std::unique_ptr<IteratorImpl> m_impl;

        friend VisualizationApp;
        const_iterator(std::unique_ptr<IteratorImpl> &&);
    };

    const_iterator begin() const;
    const_iterator end() const;

private:
    friend visualization::AppViewModelManagerImpl;
    friend visualization::OrderBookHandler;
    friend visualization::Grid;

    std::shared_ptr<visualization::VisualizationAppRowEntity> m_entity;

    std::unique_ptr<visualization::AppViewModelManagerImpl> m_impl;
};

} // \namespace tbricks

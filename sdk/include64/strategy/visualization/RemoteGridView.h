#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Primary grid view model public interface
//****************************************************************************************

#include "strategy/type/StrategyIdentifier.h"
#include "strategy/visualization/ViewModelData.h"
#include "strategy/visualization/ViewModelUpdate.h"

namespace tbricks {

class ColumnIdentifier;
class RowEntityIdentifier;
class StrategyData;
class GridParameterDefinition;

namespace visualization {

class IExternalViewModelListener;
class RemoteAppView;
class RemoteViewModelImpl;

class STRATEGY_EXPORT RemoteGridView
{
public:
    class Options;

    /**
     * Default constructor and destructor
     * Default constructor is used to comply to container requirements only
     */
    RemoteGridView() = default;
    ~RemoteGridView() = default;

    /**
     * Copy/Move constructors. Copy/Move assignment operators
     */
    RemoteGridView(const RemoteGridView &) = default;
    RemoteGridView(RemoteGridView &&) noexcept = default;
    RemoteGridView & operator=(const RemoteGridView &) = default;
    RemoteGridView & operator=(RemoteGridView &&) noexcept = default;

    /**
     * Request subscription to the remote model with IExternalViewModelListener instance.
     * Any options applied to the view model previously will be send with this request as well
     *
     * @param [in] listener Object where to send the updates
     * @param [in] data     Optional table with data to be applied to the request
     *
     * @return true if subscription is requested, false if already subscribed
     * @throws EmptyValueException if Strategy identifier was not set
     */
    bool RequestSubscription(IExternalViewModelListener & listener, const ViewModelData & data = {}) const;

    /**
     * Send view model update to the subscribed view model.
     * Any options applied to the view model previously will be send with this request as well
     *
     * @param [in] data Optional table with data to be applied to the request
     *
     * @throws EmptyValueException if provided identifier is empty
     * @throws TypeInitializationException if view model was not subscribed
     */
    void SendUpdate(const ViewModelData & data = {}) const;

    /**
     * Set options for this view model
     *
     * @param [in]  options Contains topical options for this model
     */
    void SetOptions(const Options & options);

    /**
     * Revoke subscription to the remote model and clear all the persisted data
     *
     * @return true is subscription is revoked, false if view model was not subscribed
     */
    bool RevokeSubscription() const;

    /**
     * Get strategy identifier.
     *
     * @return Strategy identifier
     * @throws EmptyValueException if Strategy identifier was not set
     */
    StrategyIdentifier GetStrategyIdentifier() const;

    /**
     * Get view model identifier.
     *
     * @return View model identifier
     */
    Uuid GetViewModelIdentifier() const;

    /**
     * Checks is this model was subscribed
     *
     * @return true is subscribed, false otherwise
     */
    bool IsSubscribed() const;

    /**
     * Send view model selection update to the subscribed view model.
     *
     * @param [in] columns         Aliases of the selected columns
     * @param [in] rangeStart      Row identifier which marks the selection range start
     * @param [in] rangeEnd        Row identifier which marks the selection range end
     * @param [in] selectOperation Either select or extend operation. None is not supported
     * @param [in] isSelected      Current selection status. True if selected, false otherwise
     *
     * @throws EmptyValueException if provided identifier is empty
     * @throws TypeInitializationException if view model was not subscribed
     */
    void SendSelectionUpdate(const std::vector<ColumnIdentifier> & columns,
                             const RowEntityIdentifier & rangeStart,
                             const RowEntityIdentifier & rangeEnd,
                             const ViewModelUpdate::SelectionUpdate::SelectOperation selectOperation,
                             const bool isSelected);

    /**
     * Prepare remote grid view instance to attach to the existing app instance
     *
     * @param [in]  targetStrategy Data of the running app instance to attach
     * @param [in]  gridParameterIdentifier identifier of grid
     *
     * @throws TypeInitializationException if provided strategy data is empty or in deleted state
     */
    static RemoteGridView Attach(const StrategyData & targetStrategy, const GridParameterDefinition & gridParameterIdentifier);

protected:
    friend RemoteAppView;

    /**
     * Constructor with strategy identifier parameter
     *
     * @param [in]  strategyIdentifier identifier of strategy
     * @param [in]  gridParameterIdentifier identifier of grid parameter
     */
    RemoteGridView(const StrategyIdentifier & strategyIdentifier, const GridParameterDefinition & gridParameterIdentifier);

    std::shared_ptr<RemoteViewModelImpl> m_primaryViewModelImpl;
};

} // namespace visualization

} // namespace tbricks

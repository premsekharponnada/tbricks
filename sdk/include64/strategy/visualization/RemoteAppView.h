#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Primary app view model public interface
//****************************************************************************************

#include "strategy/type/StrategyIdentifier.h"
#include "strategy/visualization/ViewModelData.h"

namespace tbricks {

class StrategyData;
class GridParameterDefinition;

namespace visualization {

class IExternalViewModelListener;
class RemoteGridView;

class STRATEGY_EXPORT RemoteAppView
{
public:
    class Options;

    /**
     * Default constructor and destructor
     * Default constructor is used to comply to container requirements only
     */
    RemoteAppView() = default;
    ~RemoteAppView() = default;

    /**
     * Constructor with strategy definition parameter
     *
     * @param [in]  strategyDefinition plugin type of the strategy
     */
    explicit RemoteAppView(const StrategyIdentifier & strategyDefinition);

    /**
     * Copy/Move constructors. Copy/Move assignment operators
     */
    RemoteAppView(const RemoteAppView &) = default;
    RemoteAppView(RemoteAppView &&) noexcept = default;
    RemoteAppView & operator=(const RemoteAppView &) = default;
    RemoteAppView & operator=(RemoteAppView &&) noexcept = default;

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
     * Set stream limit for the app
     *
     * @param [in]  limit Maximum amount of streams that app can open.
     *                    Stream limitations will be discarded if this parameter is passed as empty Integer.
     *
     * @throws TypeInitializationException if provided integer is less than zero
     */
    void SetStreamLimit(const Integer & limit);

    /**
     * Make grid view model object from this running instance
     *
     * @param [in]  gridParameterIdentifier identifier of grid parameter
     *
     * @throws TypeInitializationException if view model was not subscribed
     */
    RemoteGridView MakeGridView(const GridParameterDefinition & gridParameterIdentifier) const;

    /**
     * Prepare remote app view instance to attach to the existing app instance
     *
     * @param [in]  targetStrategy Data of the running app instance to attach
     *
     * @throws TypeInitializationException if provided strategy data is empty or in deleted state
     */
    static RemoteAppView Attach(const StrategyData & targetStrategy);

private:
    std::shared_ptr<RemoteViewModelImpl> m_primaryViewModelImpl;
};

} // namespace visualization

} // namespace tbricks

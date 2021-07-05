#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Remote view model observer public interface
//****************************************************************************************

#include "strategy/type/StrategyIdentifier.h"
#include "strategy/Definitions.h"
#include "strategy/visualization/ViewModelData.h"

namespace tbricks { namespace visualization {
class ViewModel;
class IExternalViewModelListener;

class STRATEGY_EXPORT RemoteViewModelObserver
{
public:
    class Options;

    RemoteViewModelObserver();
    ~RemoteViewModelObserver() = default;
    RemoteViewModelObserver(const RemoteViewModelObserver & model) = default;
    RemoteViewModelObserver(RemoteViewModelObserver && model) noexcept = default;
    RemoteViewModelObserver & operator=(const RemoteViewModelObserver & model) = default;
    RemoteViewModelObserver & operator=(RemoteViewModelObserver && model) noexcept = default;

    /**
     * Request subscription to the remote model with IExternalViewModelListener instance.
     * Any options applied to the view model previously will be send with this request as well
     *
     * @param [in]  listener Object where to send the updates
     * @param [in]  dependentModel  dependentModel.GetSourceViewModelIdentifier() to be observed
     *
     * @return true if subscription requested, false if already subscribed
     * @throws EmptyValueException if dependentModel.GetSourceViewModelIdentifier() is empty
     * @throws EmptyValueException if dependentModel.GetSourceStrategyIdentifier() is empty
     */
    bool RequestSubscription(IExternalViewModelListener & listener, const ViewModel & dependentModel) const;

    /**
     * Set options for this view model
     *
     * @param [in]  options Contains topical options for this model
     */
    void SetOptions(const Options & options);

    /**
     * Get observed view model identifier.
     *
     * @return Observed view model identifier
     */
    Uuid GetObservedViewModelIdentifier() const;

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
     */
    StrategyIdentifier GetStrategyIdentifier() const;

    /**
     * Checks is this model was subscribed
     *
     * @return true is subscribed, false otherwise
     */
    bool IsSubscribed() const;

private:
    std::shared_ptr<RemoteViewModelImpl> m_primaryViewModelImpl;
};

} // namespace visualization
} // namespace tbricks

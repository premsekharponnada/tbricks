#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// App view model public interface.
//****************************************************************************************

#include <memory>

#include "strategy/visualization/ExternalViewModel.h"

namespace tbricks { namespace visualization {

class ViewModelUpdate;

class STRATEGY_EXPORT IExternalViewModelListener
{
public:
    /**
     * External ViewModel update event
     *
     * Called when remote view update received.
     *
     * @param [in] view_model view model handler
     * @param [in] update view model updated values
     *
     */
    virtual void HandleRemoteViewUpdate(const ExternalViewModel & view_model, const ViewModelUpdate & update) = 0;

    /**
     * External ViewModel snapshot begin event
     *
     * Called when remote view model snapshot begin received.
     *
     * @param [in] view_model view model handler
     *
     */
    virtual void HandleRemoteViewSnapshotBegin(const ExternalViewModel & view_model) {}

    /**
     * External ViewModel snapshot done event
     *
     * Called when remote view model snapshot done received.
     *
     * @param [in] view_model view model handler
     *
     */
    virtual void HandleRemoteViewSnapshotDone(const ExternalViewModel & view_model) {}

    virtual ~IExternalViewModelListener() = default;
};

} // namespace visualization
} // namespace tbricks

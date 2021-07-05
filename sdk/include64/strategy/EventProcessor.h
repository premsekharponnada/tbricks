#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// EventProcessor class provides an access to Strategy Engine services.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/StrategyData.h"

// \namespace tbricks
namespace tbricks {

class IStrategyEngine;

/**
 * Interface to the Strategy Engine, provides some operations from user thread
 */
class STRATEGY_EXPORT EventProcessor
{
private:
    // Prohibited.
    EventProcessor(const EventProcessor &);
    EventProcessor & operator=(const EventProcessor &);

public:
    /**
     * EventProcessor constructor.
     *
     * Must be created in plug-in callback. Then it could be used in user thread
     * to send asynchronous requests.
     */
    EventProcessor();

    ~EventProcessor();

    /**
     * Send user-defined event to a strategy.
     *
     * Only works for user-derived strategies and only if they run on the
     * same Strategy Engine instance the request originates from.
     *
     * Allocation/deallocation of data object is sole responsibility of
     * a user.
     *
     * @param strategy_id               Identifier of the request target
     * @param data                      User-defined data
     *
     * @code
     * UserData user_data(data, size);
     *
     * ScheduleStrategyEvent(id, user_data);
     * //or
     * ScheduleStrategyEvent(id, std::move(user_data));
     *
     * @endcode
     */
    void ScheduleStrategyEvent(const StrategyIdentifier & strategy_id, UserData data) const;

private:
    IStrategyEngine * m_se;
};

} // \namespace tbricks

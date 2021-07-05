#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TimerController is a interface for timer control.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Types.h"

namespace tbricks { namespace test {
class ITimerController;

class STRATEGY_EXPORT TimerController
{
public:
    /**
    * TimerController used for manual control of timer execution.
    * All timers can be detected by strategy instance identifier
    * and timer identifier.
    *
    * @param id          Strategy instance identifier .
    *
    * @param timer_id    Timer identifier. Compliant with order of
    *                    timers creation. First timer will have id=0.
    *                    If you want to be sure of right timer id,
    *                    check log and find notice entry like
    *                        "Timer created: [name=<timer_name>] [global_id=<timer_id>]
                              [sequence_number=<sequence_number>] [app_id=<app_id>] [path=<path>]"
    *
    * @param timer_name  Timer name. Using to identify timer. Path can be used to
    *                    Also path can be used for timer identification.
    */

    /**
     * Wait for a timer start.
     * Will wait for a timer creation if timer not exist.
     * Return when plugin calling Timer::Start();
     */
    void WaitStart(const StrategyIdentifier & id, int timer_id);
    void WaitStart(const StrategyIdentifier & id, const char * timer_name, uint64_t seq_num = 0);

    /**
     * Wait for a timer stop.
     * Will wait for a timer creation if timer not exist.
     * Return after non-repetitive timer calling ITimerEventHandler::HandleTimerEvent();
     */
    void WaitStop(const StrategyIdentifier & id, int timer_id);
    void WaitStop(const StrategyIdentifier & id, const char * timer_name, uint64_t seq_num = 0);

    /**
     * Handle timer timeout.
     * Will wait for a timer start if timer not started.
     */
    void HandleTimeout(const StrategyIdentifier & id, int timer_id);
    void HandleTimeout(const StrategyIdentifier & id, const char * timer_name, uint64_t seq_num = 0);

public:
    /**
     * TimerController constructor, can be called inside TestEngine only.
     */
    TimerController(ITimerController * impl);

private:
    TimerController() = delete;
    TimerController(const TimerController &) = delete;
    TimerController & operator=(const TimerController &) = delete;

    ITimerController * m_impl;
};

} // \namespace test
} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Timer API.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Strategy.h"

#include "strategy/type/DateTime.h"
#include "strategy/type/Duration.h"

namespace tbricks {

class StrategyTimerImpl;
class Timer;

class STRATEGY_EXPORT ITimerEventHandler
{
public:
    virtual void HandleTimerEvent(Timer & timer) = 0;

protected:
    virtual ~ITimerEventHandler();
};

class STRATEGY_EXPORT Timer : public Printable
{
public:
    Timer(ITimerEventHandler & handler, const char * name = nullptr);
    Timer(const Timer & timer);
    virtual ~Timer();

    Timer & operator=(const Timer & timer);

    bool operator==(const Timer & timer) const;
    bool operator!=(const Timer & timer) const;
    bool operator<(const Timer & timer) const;
    bool operator>(const Timer & timer) const { return timer < *this; }
    bool operator<=(const Timer & timer) const { return !(timer < *this); }
    bool operator>=(const Timer & timer) const { return !operator<(timer); }

    /**
     * Schedule timer to expire at specified time point and to repeatedly
     * expire after this on specified time fraction.
     *
     * Call has no effect if timer is already started.
     *
     * @param expire                    Absolute time stamp when timer will
     *                                  expire for the first time. If value
     *                                  points in the past, timer expires at
     *                                  expire+repeat*k
     *
     * @param repeat                    If set and is not empty, timer will
     *                                  continue to expire continuously after
     *                                  first expiration using the second
     *                                  argument as a time fraction
     *
     * @return                          false if expire < DateTime::Now(),
     *                                  true otherwise
     */
    bool Start(const DateTime & expire, const Duration & repeat = Duration());

    /**
     * Repeatedly expire on time interval.
     *
     * Call has no effect if timer is already started or 'repeat' has no value.
     *
     * @param repeat                    Time interval
     */
    void Start(const Duration & repeat);

    /**
     * Repeatedly expire on time interval starting at specific time
     *
     * Call has no effect if timer is already started or 'repeat' has no value.
     *
     * @param expire                    Time of current day when timer will
     *                                  expire for the first time. If value
     *                                  points in the past, timer expires at
     *                                  expire+repeat*k
     *
     * @param repeat                    Time interval
     */
    void Start(const Time & expire, const Duration & repeat = Duration::Days(1));

    /* Gets indentifier of created timer
     *
     * @return                          Timer number
     */
    Integer GetIdentifier() const;

    /**
     * Cancel timer.
     *
     * Strategy will receive no timer updates for this timer instance after
     * the call.
     *
     * Call has no effect if timer is already stopped.
     */
    void Stop();

    bool IsActive() const;
    bool IsRepetitive() const;

    /* Gets timer's expiration time.
     *
     * @return                          Time when the timer will fire
     */
    DateTime GetTime() const;

    Duration GetDuration() const;

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend class StrategyTimerImpl;

    Timer(StrategyTimerImpl * timer_impl);
    bool Start(const DateTime & expire, const Duration & repeat, const DateTime & now);

private:
    StrategyTimerImpl * m_timer;
};
}

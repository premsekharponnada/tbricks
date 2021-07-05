#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PluginEvent describes plugin event.
//****************************************************************************************

#include <memory>
#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/String.h"
#include "strategy/type/Identifier.h"
#include "strategy/Action.h"
#include "strategy/test/EventManager.h"

namespace tbricks {

namespace pe {
class PluginEvent;
}

namespace test {

class STRATEGY_EXPORT PluginAction : public Printable
{
public:
    PluginAction();
    PluginAction(Action action,
                 Identifier identifier = Identifier(),
                 uint64_t processing_time = 0,
                 uint64_t call_time = 0,
                 const std::shared_ptr<EventManager::Action> & action_object = {});
    PluginAction(const PluginAction & action) = default;

    PluginAction & operator=(Action value);
    PluginAction & operator=(const PluginAction & value);

    /**
     * Action type. NONE means that it's an internal
     * action call by plugin engine. Can be ignored.
     *
     * @return           Action.
     */
    Action Get() const;

    std::shared_ptr<EventManager::Action> & GetActionInstance();

    /**
     * Action identifier. Stream identifier
     * in case of stream opening, request
     * identifier in case of request sending.
     *
     * @return           Identifier.
     */
    const Identifier & GetIdentifier() const;

public:
    operator Action() const;

    operator const char *() const;

    bool operator==(Action value) const;
    bool operator!=(Action value) const;

    bool operator==(const PluginAction & value) const;
    bool operator!=(const PluginAction & value) const;

    bool operator==(const char * action) const;
    bool operator!=(const char * action) const;

public:
    /**
     * Time elapsed from app handler call by this event to action call.
     *
     * @return           Time in nanoseconds.
     */
    uint64_t GetCallTime() const;

    /**
     * Action processing time.
     *
     * @return           Time in nanoseconds.
     */
    uint64_t GetProcessingTime() const;

public:
    bool Empty() const;

    void Clear();

    /**
     * Print PluginAction:
     * ActionName | ProcessingTime (CallTime)
     */
    std::ostream & Print(std::ostream & strm) const override;

private:
    Action m_value;
    Identifier m_identifier;
    uint64_t m_call_time;
    uint64_t m_processing_time;
    std::shared_ptr<EventManager::Action> m_action;
};

class STRATEGY_EXPORT PluginEvent : public Printable
{
public:
    PluginEvent(const PluginEvent & event);
    PluginEvent & operator=(const PluginEvent & event);

public:
    /**
     * Get event name. Describes handled event.
     */
    const char * GetName() const;

    /**
     * Get list of plugin actions during event.
     *
     * @return           vector of PluginActions.
     */
    std::vector<PluginAction> GetActions() const;

    /**
     * Get plugin action during event.
     *
     * @param pos        Action ordinal position.
     *
     * @return           PluginAction.
     */
    PluginAction operator[](size_t pos) const;

    /**
     * Get number of plugin actions.
     *
     * @return           Number of actions.
     */
    size_t GetActionsSize() const;

    /**
     * Get event identifier.
     * Associated with the order of events.
     *
     * @return           Event number.
     */
    uint64_t GetId() const;

    /**
     * Event identifier. Stream identifier
     * in case of stream callback, request
     * identifier in case of incoming request
     * or request reply.
     *
     * @return           Identifier.
     */
    Identifier GetIdentifier() const;

    /**
     * Get event type
     *
     * @return           EventType.
     */
    EventManager::EventType GetType() const;

public:
    /**
     * Get time elapsed until event execution.
     *
     * @return           Time in nanoseconds.
     */
    uint64_t GetWaitingTime() const;

    /**
     * Get event execution time.
     *
     * @return           Time in nanoseconds.
     */
    uint64_t GetExecutionTime() const;

public:
    /**
     * PluginEvent constructor.
     * Can be created only inside TestEngine.
     */
    PluginEvent(pe::PluginEvent * const event_ptr);
    PluginEvent() = delete;

public:
    /**
     * Print PluginEvent:
     * EventName | ExecutionTime (WaitingTime)
     *  -> PluginAction list
     */
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    pe::PluginEvent * m_event_impl;
};

} // \namespace test

} // \namespace tbricks

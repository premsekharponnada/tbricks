#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// EventManager is a interface for plugin events control.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Types.h"
#include "strategy/Action.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/stream_throttle/Throttle.h"

namespace tbricks { namespace test {
class EventManagerImpl;
class EventImpl;
class ActionImpl;
class PluginEvent;

/**
 * EventManager class.
 *
 * EventManager allows to specify the sequence of plugin callbacks in which they must be executed.
 * Event sequences can be specified at the time of plugin creation.
 * Note that any changes in EventManager are not possible after plugin creation,
 * an exception is thrown otherwise.
 */
class STRATEGY_EXPORT EventManager : public Printable
{
public:
    /**
     * Event Type is an enumeration which specifies the possible
     * types of events.
     */
    enum EventType
    {
        PLUGIN_CREATE,
        PLUGIN_PAUSE,
        PLUGIN_RUN,
        PLUGIN_DELETE,
        PLUGIN_MODIFY,
        HANDLE_REQUEST_REPLY,
        HANDLE_ORDER_UPDATE,
        TCP_CONNECTION_ESTABLISHED,
        STREAM_OPENED,
        STREAM_STALED,
        STREAM_FAILED,
        STREAM_SNAPSHOT_DONE,
        STREAM_MODIFY_SNAPSHOT_DONE,
        STREAM_ITEM_INVALID,
        STREAM_UPDATE,
        UNDEFINED,
        HANDLE_SUBSCRIBE,
        HANDLE_UNSUBSCRIBE,
        HANDLE_USER_EVENT,
        HANDLE_TIMER_EVENT
    };

    class Event;
    class Action;

public:
    EventManager();

    explicit EventManager(const std::vector<test::PluginEvent> & history_events);

    /**
     * %Set EventManager mode.
     * EventManager is in Soft mode by default and can be changed to
     * force mode by calling this method.
     *
     * @param force         Bool value
     *                      true -> change to Force mode
     *                      false ->  change to Soft mode
     */
    void SetForce(bool force = true);

    /**
     * This method allows to add an expected event.
     *
     * @param EventType     Type of expected event.
     */
    Event ExpectEvent(EventType event_type);

public:
    /**
     * Event class.
     * Event object is used to specify the sequence of plugin events.
     * It can also be used to specify the relations
     * of the event with other events and actions.
     */
    class Event : public Printable
    {
    public:
        /**
         * This method allows to assign previously created action.
         *
         * @param action         Action.
         */
        void ExpectAction(Action action);

        /**
         * This method allows to create and assign the action.
         *
         * @param action_type    Type of expected action.
         *
         * @return               Created action.
         */
        Action ExpectAction(tbricks::Action action_type);

        /**
         * This method allows to relate an event with the action.
         * It can be used to differentiate between the events of the same type.
         *
         * For example, Stream event can be related to the 'stream open' action.
         *
         * @param action         Action object.
         */
        void RelateAction(const Action & action);

        /**
         * This method allows to relate one event with another event.
         * Stream events can be related with HandleConnectionEstablished event.
         * As in TCP stream openings are performed via HandleConnectionEstablished
         * event instead of StreamOpenRequest.
         *
         * @param event          Event object.
         */
        void RelateEvent(const Event & event);

        /**
         * This method makes to wait until the execution of the event is completed.
         */
        void Wait();

    public:
        std::ostream & Print(std::ostream & strm) const override;

    public:
        /**
         * Event constructor.
         * Event can be created only using EventManager.
         * Use EventManager::ExpectEvent(type).
         */
        explicit Event(const std::shared_ptr<EventImpl> & event_impl);

        const std::shared_ptr<EventImpl> & GetImpl() const;

    private:
        std::shared_ptr<EventImpl> m_impl;
    };

    /**
     * Action class.
     * Action object can be used only to specify relations between events.
     * Action should to be assigned with an initial event.
     * If no event is assigned, Action will be of NO use.
     */
    class Action : public Printable
    {
    public:
        /**
         * Action constructor.
         * After constructor call action doesn't assigned to event.
         *
         * @param action         Action type.
         */
        Action(tbricks::Action action_type);

    public:
        std::ostream & Print(std::ostream & strm) const override;

    public:
        /**
         * Internal action constructor.
         */
        explicit Action(const std::shared_ptr<ActionImpl> & action_impl);

        const std::shared_ptr<ActionImpl> & GetImpl() const;

    protected:
        std::shared_ptr<ActionImpl> m_impl;
    };

    /**
     * StreamAction class.
     * Specific action object can be used for more exact stream detection.
     * StreamAction should to be assigned with an initial event.
     * If no event is assigned, StreamAction will be of NO use.
     */
    class StreamAction : public Action
    {
    public:
        /**
         * StreamAction constructor.
         * It can be created only for 'stream open' action type.
         * After constructor call action doesn't assigned to event.
         *
         * @param action         Action type.
         */
        StreamAction(tbricks::Action action_type);

        using Action::Action;

    public:
        /**
         * Expected stream setters.
         * These methods can be called with empty value to match with stream without this value.
         * If value setter method is not called, value will be ignored during stream comparison.
         * NOTE: Changes is not allowed after EventManager is assigned.
         */

        void SetType(Stream::Type type);

        void SetFilter(const tbricks::Filter & filter);

        void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

        void SetThrottle(const Throttle & throttle);

        void SetContextIdentifier(const Identifier & id);

        void SetRequestedService(const ServiceIdentifier & id);

        void SetLiquidityPool(const LiquidityPoolIdentifier & id);

        void SetUserIdentifier(const UserIdentifier & id);

        void SetPortfolioIdentifier(const PortfolioIdentifier & id);

        void SetItems(const std::vector<Identifier> & items);

        void SetRankingIdentifier(const Identifier & id);

        void SetParameters(const std::vector<InstrumentParameterDefinition> & definitions);

    private:
        StreamAction() = delete;
    };

public:
    std::ostream & Print(std::ostream & strm) const override;

public:
    const std::shared_ptr<EventManagerImpl> & GetImpl() const;

private:
    std::shared_ptr<EventManagerImpl> m_impl;
};

} // \namespace test
} // \namespace tbricks

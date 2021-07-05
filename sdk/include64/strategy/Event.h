#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/AlertParameters.h"

namespace tbricks {

namespace protocol {
class Event;
}

class STRATEGY_EXPORT Event : public Printable
{
public:
    Event();
    Event(const Event & event);
    Event(std::shared_ptr<tbricks::protocol::Event>);
    Event & operator=(const Event & event);
    virtual ~Event();

public:
    /**
     * Get event identifier.
     *
     * Returns system event identifier the object is associated with.
     *
     * @return                          EventIdentifier
     */
    EventIdentifier GetIdentifier() const;

    /**
     * Get event type identifier.
     *
     * Returns tree node identifier which defines the event's type.
     *
     * @return                          TreeNodeIdentifier
     */
    TreeNodeIdentifier GetType() const;

    /**
     * Get event parameters
     *
     * Returns collection of parameters associated with the event.
     *
     * @return                          AlertParameters
     */
    AlertParameters GetParameters() const;

    /**
     * Get event host creation datetime.
     *
     * Returns the event host creation datetime.
     *
     * @return                          DateTime
     */
    DateTime GetHostCreatedDatetime() const;

    /**
     * Get event host modification datetime.
     *
     * Returns the event host modification datetime.
     *
     * @return                          DateTime
     */
    DateTime GetHostModifiedDatetime() const;

public:
    void Clear();
    bool Empty() const;

    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    std::shared_ptr<tbricks::protocol::Event> m_event;
};

} // namespace tbricks

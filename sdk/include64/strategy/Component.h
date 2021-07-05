#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Component
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/RequestReplyHandler.h"

#include "strategy_generated/ComponentBase.h"
#include "strategy_generated/ComponentModifierBase.h"

#include <vector>

namespace tbricks {

class Integer;
class String;

class STRATEGY_EXPORT Component : public ComponentBase
{
public:
    class Stream;
    class Modifier;

    /**
     * Default constructor.
     *
     * Initializes object to default value -- no fields present, all returned
     * values are empty.
     *
     * This is mostly for use in STL containers.
     */
    Component() = default;

    Component(const ComponentIdentifier & identifier);

    /**
     * Get current component.
     */
    static const Component GetCurrent();

    using ComponentBase::ComponentBase;

    /**
     * Get system process identifier
     *
     * @return system process identifier or empty if component is not running
     */
    Integer GetPID() const;

    /**
     * Get platform of currently running component
     *
     * @return platform of currently running component
     */
    String GetCurrentPlatform() const;

    /**
     * Get platform of component after restart, empty if there is no pending platform change
     *
     * @return platform of component after restart
     */
    String GetPendingPlatform() const;

    /**
     * Get connectivity packages of currently running component
     *
     * @return connectivity packages of currently running component
     */
    std::vector<String> GetCurrentConnectivityPackages() const;

    /**
     * Get connectivity packages of component after restart, empty if there is no
     * pending connectivity packages
     *
     * @return connectivity packages of component after restart
     */
    std::vector<String> GetPendingConnectivityPackages() const;

    /**
     * Send component modify request to AC.
     *
     * @param component_identifier      Component instance identifier
     * @param component_modifier        Component modify request
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Request identifier
     */
    static Identifier SendModifyRequest(const ComponentIdentifier & component_identifier,
                                        const Component::Modifier & component_modifier,
                                        IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send component start request to AC.
     *
     * @param component_identifier      Component instance identifier
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Request identifier
     */
    static Identifier SendStartRequest(const ComponentIdentifier & component_identifier,
                                       IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send component stop request to AC.
     *
     * @param component_identifier      Component instance identifier
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Request identifier
     */
    static Identifier SendStopRequest(const ComponentIdentifier & component_identifier,
                                      IRequestReplyHandler & handler = IRequestReplyHandler::Default());
};

class STRATEGY_EXPORT Component::Modifier : public ComponentModifierBase
{};
}

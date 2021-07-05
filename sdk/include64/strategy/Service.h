#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Service
//****************************************************************************************

#include "strategy/Component.h"
#include "strategy/Linkage.h"
#include "strategy/Node.h"
#include "strategy/Subsystem.h"
#include "strategy/Types.h"
#include "strategy/RequestReplyHandler.h"
#include "strategy/type/ComponentIdentifier.h"
#include "strategy/type/ServiceIdentifier.h"
#include "strategy/type/ServiceType.h"
#include "strategy/type/String.h"

#include "strategy_generated/ServiceBase.h"
#include "strategy_generated/ServiceModifierBase.h"

namespace tbricks {

namespace protocol {
class Service;
}

class VenueStatus;

/**
 * Service object informs about changes in a service state, such as when
 * service goes online or offline and so on.
 *
 * Every update is guaranteed to have service identifier, other fields are
 * optional and may return empty value.
 */
class STRATEGY_EXPORT Service : public ServiceBase
{
public:
    class Stream;
    class Modifier;

    /// @deprecated Deprecated in 2.14.3 use ServiceType
    enum [[deprecated(DEPRECATE_LINK)]] Type
    {
        GRID_BACKEND = static_cast<int>(ServiceType::GRID_BACKEND), INSTRUMENT = static_cast<int>(ServiceType::INSTRUMENT),
        MARKET_DATA = static_cast<int>(ServiceType::MARKET_DATA), METADATA = static_cast<int>(ServiceType::METADATA),
        ORDER_PERSISTENCE = static_cast<int>(ServiceType::ORDER_PERSISTENCE), XRAY_FRONTEND = static_cast<int>(ServiceType::XRAY_FRONTEND),
        INSTRUMENT_REFERENCE_DATA = static_cast<int>(ServiceType::INSTRUMENT_REFERENCE_DATA),
        STRATEGY_ENGINE = static_cast<int>(ServiceType::STRATEGY_ENGINE), TRADE_PERSISTENCE = static_cast<int>(ServiceType::TRADE_PERSISTENCE),
        TRADING = static_cast<int>(ServiceType::TRADING), XRAY_PERSISTENCE = static_cast<int>(ServiceType::XRAY_PERSISTENCE),
        MARKET_PLACE = static_cast<int>(ServiceType::MARKET_PLACE), INTEGRATION = static_cast<int>(ServiceType::INTEGRATION),
        SMS = static_cast<int>(ServiceType::SMS), TRADING_REFERENCE_DATA = static_cast<int>(ServiceType::TRADING_REFERENCE_DATA),
        TIME_SERIES = static_cast<int>(ServiceType::TIME_SERIES), REPLAY = static_cast<int>(ServiceType::REPLAY),
        PRICING_ENGINE = static_cast<int>(ServiceType::PRICING_ENGINE), LIMIT_ENGINE = static_cast<int>(ServiceType::LIMIT_ENGINE),
        ACCESSORY_ENGINE = static_cast<int>(ServiceType::ACCESSORY_ENGINE), QUOTING = static_cast<int>(ServiceType::QUOTING),
        REQUEST_FOR_QUOTE = static_cast<int>(ServiceType::REQUEST_FOR_QUOTE), QUOTE_REQUEST = static_cast<int>(ServiceType::QUOTE_REQUEST),
        EXPIT_TRADING = static_cast<int>(ServiceType::EXPIT_TRADING), INTEGRATION_ENGINE = static_cast<int>(ServiceType::INTEGRATION_ENGINE),
        FLOW_ENGINE = static_cast<int>(ServiceType::FLOW_ENGINE), MATCHING_ENGINE = static_cast<int>(ServiceType::MATCHING_ENGINE),
        MARKET_INFORMATION = static_cast<int>(ServiceType::MARKET_INFORMATION), CONTRIBUTION = static_cast<int>(ServiceType::CONTRIBUTION),
        OMD_RAW_DATA_SERVER = static_cast<int>(ServiceType::OMD_RAW_DATA_SERVER), DIRECTED_QUOTING = static_cast<int>(ServiceType::DIRECTED_QUOTING),
        VISUALIZATION_ENGINE = static_cast<int>(ServiceType::VISUALIZATION_ENGINE), MARKET_COMMAND = static_cast<int>(ServiceType::MARKET_COMMAND),
        DIRECTED_QUOTE_REQUEST = static_cast<int>(ServiceType::DIRECTED_QUOTE_REQUEST),
        DISTRIBUTION_ENGINE = static_cast<int>(ServiceType::DISTRIBUTION_ENGINE), OMD_TICK_SERVER = static_cast<int>(ServiceType::OMD_TICK_SERVER),
        OMD_NATIVE_MEMORY_LOADER = static_cast<int>(ServiceType::OMD_NATIVE_MEMORY_LOADER),
        OMD_NATIVE_DAILY_LOADER = static_cast<int>(ServiceType::OMD_NATIVE_DAILY_LOADER),
        OMD_RT_MEMORY_LOADER = static_cast<int>(ServiceType::OMD_RT_MEMORY_LOADER),
        OMD_RT_DAILY_LOADER = static_cast<int>(ServiceType::OMD_RT_DAILY_LOADER),
        OMD_ASCII_DAILY_LOADER = static_cast<int>(ServiceType::OMD_ASCII_DAILY_LOADER),
        OMD_OTQ_QUERY_DAILY_LOADER = static_cast<int>(ServiceType::OMD_OTQ_QUERY_DAILY_LOADER), DROP_COPY = static_cast<int>(ServiceType::DROP_COPY),
        UNKNOWN = static_cast<int>(ServiceType::UNKNOWN)
    };

public:
    /**
     * Default constructor.
     *
     * Initializes object to default value -- no fields present, all returned
     * values are empty.
     *
     * This is mostly for use in STL containers.
     */
    Service() = default;

    Service(const ServiceIdentifier & identifier);

    static const Service GetCurrent();

    /**
     * Get service name.
     */
    String GetName() const;

    /**
     * Get service host name.
     *
     * A user-assigned node name or DNS name of the host a service is
     * running on.
     *
     * @return                          Node name or DNS host name
     */
    String GetHostName() const;

    /**
     * Get service host address.
     *
     * Returns address of the host a service is running on. This field
     * could be empty if the service is offline.
     *
     * @return                          Host address
     */
    String GetHostAddress() const;

    /**
     * Get service type.
     *
     * @return                          Service type
     */
    /// @deprecated Deprecated in 2.14.3 use GetServiceType
    [[deprecated(DEPRECATE_LINK)]] Type GetType() const;

    /**
     * Get service type.
     *
     * @return                          Service type
     */
    ServiceType GetServiceType() const;

    /**
     * Get service venue identifier.
     *
     * If a service connects to a real market place, this field will contain
     * venue identifier. Otherwise, empty value is returned.
     *
     * Result value can be empty if service is offline even if the service
     * is configured to connect to a market.
     *
     * @return                          Venue identifier if service is online
     *                                  and is connected to a venue, empty
     *                                  identifier otherwise
     */
    Venue GetVenue() const;

    /**
     * Get venue status.
     *
     * If service venue identifier is empty, empty venue status is returned.
     *
     * @return                          Venue status is service is online
     *                                  and is connected to a venue, empty
     *                                  status otherwise
     */
    VenueStatus GetVenueStatus() const;

    /**
     * Check if service is online.
     *
     * @return                          "true" if service is online,
     *                                  "false" otherwise
     */
    Boolean IsOnline() const;

    /**
     * Get parent subsystem.
     */
    const Subsystem GetSubsystem() const;

    /**
     * Get parent component.
     */
    const Component GetComponent() const;

    /**
     * Get parent subsystem.
     */
    const Node GetNode() const;

    /**
     * Send service modify request to AC.
     *
     * @param service_identifier        Service instance identifier
     * @param service_modifier          Service modify request
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Request identifier
     */
    static Identifier SendModifyRequest(const ServiceIdentifier & service_identifier,
                                        const Service::Modifier & service_modifier,
                                        IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Check if service is connected to Strategy Engine.
     *
     * Unlike IsOnline() call, this method returns true only if Strategy
     * Engine has an active connection to the service.
     *
     * @deprecated Deprecated in 2.13.0 as obsolete, use IsConnected() instead.
     *
     * @return                          "true" if service is offline,
     *                                  "false" otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] Boolean IsConnectedToStrategyEngine() const { return IsConnected(); }

    Boolean IsConnected() const;

    Boolean IsDisabled() const;

    Boolean IsDowntime() const;

    using ServiceBase::ServiceBase;
};

class STRATEGY_EXPORT Service::Modifier : public ServiceModifierBase
{};

/// @deprecated Deprecated in 2.14.3 use tbricks::ServiceType
[[deprecated(DEPRECATE_LINK)]] std::ostream & operator<<(std::ostream & strm, const Service::Type & type);

namespace strategy {

/// @deprecated Deprecated in 2.14.3 use tbricks::Service
using Service[[deprecated(DEPRECATE_LINK)]] = tbricks::Service;

} // namespace strategy

} // namespace tbricks

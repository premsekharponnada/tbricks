#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ServiceBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class ComponentIdentifier;
class NodeIdentifier;
class ServiceIdentifier;
class String;
class StringDictionary;
class SubsystemIdentifier;
class SystemIdentifier;
enum class ServiceState;


namespace protocol { class Service; }

class STRATEGY_EXPORT ServiceBase : public Printable
{
protected:
    ServiceBase();
    ServiceBase(const ServiceBase & value);
    ServiceBase(ServiceBase && value) noexcept;
    ServiceBase & operator=(const ServiceBase & value);
    ServiceBase & operator=(ServiceBase && value) noexcept;
    virtual ~ServiceBase();

public:
    /**
     * Check if field is set.
     *
     * Returned value uniquely identifies a service in a Tbricks system
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get service identifier.
     *
     * Returned value uniquely identifies a service in a Tbricks system
     *
     *
     * @return                          service identifier
     */
    ServiceIdentifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get service subsystem identifier
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSubsystemIdentifier() const;

    /**
     * Get subsystem identifier.
     *
     * Get service subsystem identifier
     *
     *
     * @return                          subsystem identifier
     */
    SubsystemIdentifier GetSubsystemIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get service system identifier
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSystemIdentifier() const;

    /**
     * Get system identifier.
     *
     * Get service system identifier
     *
     *
     * @return                          system identifier
     */
    SystemIdentifier GetSystemIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get service subsystem name
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSubsystemName() const;

    /**
     * Get subsystem name.
     *
     * Get service subsystem name
     *
     *
     * @return                          subsystem name
     */
    String GetSubsystemName() const;

    /**
     * Check if field is set.
     *
     * Get service node identifier
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasNodeIdentifier() const;

    /**
     * Get node identifier.
     *
     * Get service node identifier
     *
     *
     * @return                          node identifier
     */
    NodeIdentifier GetNodeIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get service node name
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasNodeName() const;

    /**
     * Get node name.
     *
     * Get service node name
     *
     *
     * @return                          node name
     */
    String GetNodeName() const;

    /**
     * Check if field is set.
     *
     * Get component identifier.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComponentIdentifier() const;

    /**
     * Get component identifier.
     *
     * Get component identifier.
     *
     *
     * @return                          component identifier
     */
    ComponentIdentifier GetComponentIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get component name.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComponentName() const;

    /**
     * Get component name.
     *
     * Get component name.
     *
     *
     * @return                          component name
     */
    String GetComponentName() const;

    /**
     * Check if field is set.
     *
     * Get state of this service.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasState() const;

    /**
     * Get service state.
     *
     * Get state of this service.
     *
     *
     * @return                          service state
     */
    std::optional<ServiceState> GetState() const;

    /**
     * Check if field is set.
     *
     * Get service short name.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasShortName() const;

    /**
     * Get service name.
     *
     * Get service short name.
     *
     *
     * @return                          service name
     */
    String GetShortName() const;

    /**
     * Check if field is set.
     *
     * Same as GetType(), but in string form.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTypeName() const;

    /**
     * Get service type.
     *
     * Same as GetType(), but in string form.
     *
     *
     * @return                          service type
     */
    String GetTypeName() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProperties() const;

    /**
     * Get service properties.
     *
     *
     * @return                          service properties
     */
    StringDictionary GetProperties() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSetOnceProperties() const;

    /**
     * Get setonce service properties.
     *
     *
     * @return                          setonce service properties
     */
    StringDictionary GetSetOnceProperties() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    ServiceBase(const protocol::Service & value);
    ServiceBase(std::shared_ptr<protocol::Service> && value);

    std::shared_ptr<protocol::Service> & get_impl_wr() const;
    const std::shared_ptr<protocol::Service> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Service> m_impl;
};

}

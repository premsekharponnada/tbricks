#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ComponentBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class ComponentIdentifier;
class Identifier;
class NodeIdentifier;
class String;
class StringDictionary;
class SystemIdentifier;
enum class ComponentState;


namespace protocol { class Component; }

class STRATEGY_EXPORT ComponentBase : public Printable
{
protected:
    ComponentBase();
    ComponentBase(const ComponentBase & value);
    ComponentBase(ComponentBase && value) noexcept;
    ComponentBase & operator=(const ComponentBase & value);
    ComponentBase & operator=(ComponentBase && value) noexcept;
    virtual ~ComponentBase();

public:
    /**
     * Check if field is set.
     *
     * Returned value uniquely identifies a component in a Tbricks system.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get component identifier.
     *
     * Returned value uniquely identifies a component in a Tbricks system.
     *
     *
     * @return                          component identifier
     */
    ComponentIdentifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get component name.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasName() const;

    /**
     * Get component name.
     *
     * Get component name.
     *
     *
     * @return                          component name
     */
    String GetName() const;

    /**
     * Check if field is set.
     *
     * Get component type name
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTypeName() const;

    /**
     * Get component type.
     *
     * Get component type name
     *
     *
     * @return                          component type
     */
    String GetTypeName() const;

    /**
     * Check if field is set.
     *
     * Get component type identifier.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTypeIdentifier() const;

    /**
     * Get component type identifier.
     *
     * Get component type identifier.
     *
     *
     * @return                          component type identifier
     */
    Identifier GetTypeIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get system name.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSystemName() const;

    /**
     * Get system name.
     *
     * Get system name.
     *
     *
     * @return                          system name
     */
    String GetSystemName() const;

    /**
     * Check if field is set.
     *
     * System identifier which associated with this component.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSystemIdentifier() const;

    /**
     * Get system identifier.
     *
     * System identifier which associated with this component.
     *
     *
     * @return                          system identifier
     */
    SystemIdentifier GetSystemIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get component node identifier
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasNodeIdentifier() const;

    /**
     * Get node identifier.
     *
     * Get component node identifier
     *
     *
     * @return                          node identifier
     */
    NodeIdentifier GetNodeIdentifier() const;

    /**
     * Check if field is set.
     *
     * Returned value uniquely identifies a speedcore component, which
     * associated with current component in a Tbricks system.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSpeedCoreIdentifier() const;

    /**
     * Get speedcore identifier.
     *
     * Returned value uniquely identifies a speedcore component, which
     * associated with current component in a Tbricks system.
     *
     *
     * @return                          speedcore identifier
     */
    ComponentIdentifier GetSpeedCoreIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get state of this component.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasState() const;

    /**
     * Get component state.
     *
     * Get state of this component.
     *
     *
     * @return                          component state
     */
    std::optional<ComponentState> GetState() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProperties() const;

    /**
     * Get component properties.
     *
     *
     * @return                          component properties
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
     * Get setonce component properties.
     *
     *
     * @return                          setonce component properties
     */
    StringDictionary GetSetOnceProperties() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    ComponentBase(const protocol::Component & value);
    ComponentBase(std::shared_ptr<protocol::Component> && value);

    std::shared_ptr<protocol::Component> & get_impl_wr() const;
    const std::shared_ptr<protocol::Component> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Component> m_impl;
};

}

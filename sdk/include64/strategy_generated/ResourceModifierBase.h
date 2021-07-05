#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ResourceModifierBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class ComponentIdentifier;
class ServiceIdentifier;
class String;
class SystemIdentifier;


namespace protocol { class Resource; }

class STRATEGY_EXPORT ResourceModifierBase : public Printable
{
protected:
    ResourceModifierBase();
    ResourceModifierBase(const ResourceModifierBase & value);
    ResourceModifierBase(ResourceModifierBase && value) noexcept;
    ResourceModifierBase & operator=(const ResourceModifierBase & value);
    ResourceModifierBase & operator=(ResourceModifierBase && value) noexcept;
    virtual ~ResourceModifierBase();

public:
    /**
     * Get resource services.
     *
     * List of service identifiers which associated with this resource.
     *
     *
     * @return                          resource services
     */
    std::vector<ServiceIdentifier> GetServiceIdentifiers() const;

    /**
     * %Set resource services.
     * The field will be set into object even if the field is empty.
     *
     * List of service identifiers which associated with this resource.
     *
     *
     * @param value                     resource services
     */
    void SetServiceIdentifiers(const std::vector<ServiceIdentifier> & value);

    /**
     * Get resource components.
     *
     * List of component identifiers which associated with this resource.
     *
     *
     * @return                          resource components
     */
    std::vector<ComponentIdentifier> GetComponentIdentifiers() const;

    /**
     * %Set resource components.
     * The field will be set into object even if the field is empty.
     *
     * List of component identifiers which associated with this resource.
     *
     *
     * @param value                     resource components
     */
    void SetComponentIdentifiers(const std::vector<ComponentIdentifier> & value);

    /**
     * Get resource systems.
     *
     * List of system identifiers which associated with this resource.
     *
     *
     * @return                          resource systems
     */
    std::vector<SystemIdentifier> GetSystemIdentifiers() const;

    /**
     * %Set resource systems.
     * The field will be set into object even if the field is empty.
     *
     * List of system identifiers which associated with this resource.
     *
     *
     * @param value                     resource systems
     */
    void SetSystemIdentifiers(const std::vector<SystemIdentifier> & value);

    /**
     * Check if field is set.
     *
     * A longer description of the resource and its intended usage.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDescription() const;

    /**
     * Get resource description.
     *
     * A longer description of the resource and its intended usage.
     *
     *
     * @return                          resource description
     */
    String GetDescription() const;

    /**
     * %Set resource description.
     *
     * A longer description of the resource and its intended usage.
     *
     *    
     *  
     * @param value                     resource description
     */
    void SetDescription(const String & value);

    /**
     * Check if field is set.
     *
     * The type defines what kind of data that the resource represents.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMimeType() const;

    /**
     * Get resource mime type.
     *
     * The type defines what kind of data that the resource represents.
     *
     *
     * @return                          resource mime type
     */
    String GetMimeType() const;

    /**
     * %Set resource mime type.
     *
     * The type defines what kind of data that the resource represents.
     *
     *    
     *  
     * @param value                     resource mime type
     */
    void SetMimeType(const String & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    ResourceModifierBase(const protocol::Resource & value);
    ResourceModifierBase(std::unique_ptr<protocol::Resource> && value);

    std::unique_ptr<protocol::Resource> & get_impl_wr() const;
    const std::unique_ptr<protocol::Resource> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::Resource> m_impl;
};

}

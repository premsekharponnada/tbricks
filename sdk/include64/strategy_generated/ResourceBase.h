#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ResourceBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class ComponentIdentifier;
class DateTime;
class ServiceIdentifier;
class String;
class StringDictionary;
class SystemIdentifier;
class Uuid;


namespace protocol { class Resource; }

class STRATEGY_EXPORT ResourceBase : public Printable
{
protected:
    ResourceBase();
    ResourceBase(const ResourceBase & value);
    ResourceBase(ResourceBase && value) noexcept;
    ResourceBase & operator=(const ResourceBase & value);
    ResourceBase & operator=(ResourceBase && value) noexcept;
    virtual ~ResourceBase();

public:
    /**
     * Get resource identifier.
     *
     * The unique resource identifier.
     *
     *
     * @return                          resource identifier
     */
    Uuid GetIdentifier() const;

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
     * Get resource components.
     *
     * List of component identifiers which associated with this resource.
     *
     *
     * @return                          resource components
     */
    std::vector<ComponentIdentifier> GetComponentIdentifiers() const;

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
     * Check if field is set.
     *
     * Name used to identify the resource.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasShortName() const;

    /**
     * Get resource short name.
     *
     * Name used to identify the resource.
     *
     *
     * @return                          resource short name
     */
    String GetShortName() const;

    /**
     * Check if field is set.
     *
     * Display name of the resource.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDisplayName() const;

    /**
     * Get resource display name.
     *
     * Display name of the resource.
     *
     *
     * @return                          resource display name
     */
    String GetDisplayName() const;

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
     * Check if field is set.
     *
     * Path of extracted resource on the local machine.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPath() const;

    /**
     * Get resource path.
     *
     * Path of extracted resource on the local machine.
     *
     *
     * @return                          resource path
     */
    String GetPath() const;

    /**
     * Check if field is set.
     *
     * File name which associated with this resource.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasFileName() const;

    /**
     * Get resource file name.
     *
     * File name which associated with this resource.
     *
     *
     * @return                          resource file name
     */
    String GetFileName() const;

    /**
     * Check if field is set.
     *
     * Last time when resource was uploaded.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUploadTime() const;

    /**
     * Get resource upload time.
     *
     * Last time when resource was uploaded.
     *
     *
     * @return                          resource upload time
     */
    DateTime GetUploadTime() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProperties() const;

    /**
     * Get resource properties.
     *
     *
     * @return                          resource properties
     */
    StringDictionary GetProperties() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    ResourceBase(const protocol::Resource & value);
    ResourceBase(std::shared_ptr<protocol::Resource> && value);

    std::shared_ptr<protocol::Resource> & get_impl_wr() const;
    const std::shared_ptr<protocol::Resource> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Resource> m_impl;
};

}

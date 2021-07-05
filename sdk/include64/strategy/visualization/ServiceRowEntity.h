#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Service Row Entity public interface.
//****************************************************************************************

#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class Service;
class ServiceIdentifier;
class QualityOfService;

namespace visualization {

/**
 * RowEntity implementation containing Service object.
 *
 */
class STRATEGY_EXPORT ServiceRowEntity final : public RowEntity
{
public:
    /*
     * Create Service Row Entity with currently available information about
     * the Service with request identifier.
     */
    ServiceRowEntity(const ServiceIdentifier & id, RowEntity::Options options);

    ServiceRowEntity(const ServiceRowEntity & other) = default;
    ServiceRowEntity(ServiceRowEntity && other) noexcept = default;
    ServiceRowEntity & operator=(const ServiceRowEntity & other) = default;
    ServiceRowEntity & operator=(ServiceRowEntity && other) noexcept = default;

    const Service & GetService() const;

    /**
     * Set service object and update view models containing row entity.
     *
     * @param service        service
     */
    void SetService(const Service & service);

    /**
     * Get service object stored in row entity.
     *
     * @return service
     */
    const QualityOfService & GetQualityOfService() const;

    /**
     * Update information about the quality of service.
     *
     * @param qos        quality of service
     */
    void MergeQualityOfService(const QualityOfService & qos);

    virtual ~ServiceRowEntity() = default;
};

} // namespace visualization
} // namespace tbricks

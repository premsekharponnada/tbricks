#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Custom Properties Row Entity public interface.
//****************************************************************************************

#include "strategy/visualization/RowEntity.h"
#include "strategy/visualization/RowEntityType.h"

namespace tbricks {

class AnyType;
class Uuid;
class CalculatedProperty;

namespace visualization {

/**
 * CustomPropertiesRowEntity contains arbitrary property data set by user and/or some base row entities. 
 */
class STRATEGY_EXPORT CustomPropertiesRowEntity : public RowEntity
{
public:
    /**
     * Create empty CustomProperties row entity
     */
    CustomPropertiesRowEntity();

    CustomPropertiesRowEntity(const CustomPropertiesRowEntity & other) = default;
    CustomPropertiesRowEntity(CustomPropertiesRowEntity && other) noexcept = default;
    CustomPropertiesRowEntity & operator=(const CustomPropertiesRowEntity & other) = default;
    CustomPropertiesRowEntity & operator=(CustomPropertiesRowEntity && other) noexcept = default;

    virtual ~CustomPropertiesRowEntity() = default;

    /**
     * Sets base entities to get values in order of priority.
     *
     * @throws EntityCircularDependencyException if base entities dependencies are not acyclic
     *
     * @param entities           vector of entities
     * @param base_type          data type of base row entity
     */
    void SetBaseEntities(const std::vector<RowEntity> & entities, std::optional<RowEntityType> base_type = {});

    /**
     * Sets base entities to get values in order of priority.
     *
     * @throws EntityCircularDependencyException if base entities dependencies is not acyclic
     *
     * @param entities           vector of entities
     * @param base_type          data type of base row entity
     */
    void SetBaseEntities(std::vector<RowEntity> && entities, std::optional<RowEntityType> base_type = {});

    /**
     * Add passed row entity to this custom properties row entity.
     * Passed entity and the stored entity will be the same object.
     *
     * @throws EntityCircularDependencyException if base entities dependencies are not acyclic
     *
     * @param entity row entity
     */
    void AddEntity(RowEntity entity);

    /**
     * Set value for property.
     *
     * @param property column property
     * @param value absolute value of column
     *
     * @throws TypeMismatchException if value is not absolute
     */
    void SetValue(const CalculatedProperty & property, const AnyType & value);

    /**
     * Get value for property
     *
     * @return true if property exists, false otherwise.
     */
    bool GetValue(const CalculatedProperty & property, AnyType & value) const;

    /**
     * Is value for property is present
     *
     * @return true if property exists, false otherwise.
     */
    bool HasValue(const CalculatedProperty & property) const;

    /**
     * Clears property value
     * @return true if property exists, false otherwise
     */
    bool ClearValue(const CalculatedProperty & property);

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no values in the
     *                                  container, false otherwise.
     */
    bool Empty() const;

    /**
     * Clear all properties data.
     *
     * After this call container is guaranteed to contain no data, and Empty()
     * method will return True if called.
     */
    void Clear();
};

} // namespace visualization
} // namespace tbricks

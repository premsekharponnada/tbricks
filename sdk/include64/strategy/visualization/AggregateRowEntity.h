#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Aggregate Row Entity public interface.
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Hash.h"
#include "strategy/visualization/RowEntity.h"

namespace tbricks::visualization {

/**
 * AggregateRowEntity object contains other row entities and summarizes
 * their numeric properties marked with 'Sum' merge style.
 *
 */
class STRATEGY_EXPORT AggregateRowEntity : public RowEntity
{
public:
    AggregateRowEntity();

    AggregateRowEntity(const AggregateRowEntity & other) = default;
    AggregateRowEntity(AggregateRowEntity && other) noexcept = default;
    AggregateRowEntity & operator=(const AggregateRowEntity & other) = default;
    AggregateRowEntity & operator=(AggregateRowEntity && other) noexcept = default;

    /**
     * Add passed row entity to this aggregated row entity.
     * Passed entity and the stored entity will be the same object.
     *
     * @param entity        row entity
     */
    void AddEntity(const RowEntity & entity);

    /**
     * Remove row entity from this entity.
     *
     * @param entity        row entity
     */
    void RemoveEntity(const RowEntity & entity);

    class STRATEGY_EXPORT const_iterator
    {
    public:
        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        const_iterator & operator*();

        RowEntity Get() const;

    private:
        friend class AggregateRowEntity;
        explicit const_iterator(const tbricks::Hash<Uuid, std::shared_ptr<IRowEntityImpl>>::const_iterator & it);

        tbricks::Hash<Uuid, std::shared_ptr<IRowEntityImpl>>::const_iterator m_it;
    };

    const_iterator begin() const;
    const_iterator end() const;
};

} // namespace tbricks::visualization

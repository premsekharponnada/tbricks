#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Position Row Entity public interface.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class Uuid;
class Position;

namespace visualization {

/**
 * RowEntity implementation containing Position object.
 *
 */
class STRATEGY_EXPORT PositionRowEntity final : public RowEntity
{
public:
    PositionRowEntity();

    PositionRowEntity(const PositionRowEntity & other) = default;
    PositionRowEntity(PositionRowEntity && other) noexcept = default;
    PositionRowEntity & operator=(const PositionRowEntity & other) = default;
    PositionRowEntity & operator=(PositionRowEntity && other) noexcept = default;

    /**
     * Get position object stored in row entity.
     *
     * @return position
     */
    const Position & GetPosition() const;

    /**
     * Set position object and update view models containing row entity.
     *
     * @param position        position
     */
    void SetPosition(const Position & position);

    virtual ~PositionRowEntity() = default;
};

} // namespace visualization
} // namespace tbricks

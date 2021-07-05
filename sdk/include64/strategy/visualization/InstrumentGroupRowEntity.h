#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentGroup Row Entity public interface.
//****************************************************************************************

#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class Uuid;
class InstrumentGroup;

namespace visualization {

/**
 * RowEntity implementation containing InstrumentGroup object.
 *
 */
class STRATEGY_EXPORT InstrumentGroupRowEntity final : public RowEntity
{
public:
    InstrumentGroupRowEntity();

    InstrumentGroupRowEntity(const InstrumentGroupRowEntity & other) = default;
    InstrumentGroupRowEntity(InstrumentGroupRowEntity && other) noexcept = default;
    InstrumentGroupRowEntity & operator=(const InstrumentGroupRowEntity & other) = default;
    InstrumentGroupRowEntity & operator=(InstrumentGroupRowEntity && other) noexcept = default;

    /**
     * Get instrument group object stored in row entity.
     *
     * @return instrument group
     */
    const InstrumentGroup & GetInstrumentGroup() const;

    /**
     * Set instrument group object and update view models containing row entity.
     *
     * @param instrument_group        instrument group
     */
    void SetInstrumentGroup(const InstrumentGroup & instrument_group);

    virtual ~InstrumentGroupRowEntity() = default;
};

} // namespace visualization
} // namespace tbricks

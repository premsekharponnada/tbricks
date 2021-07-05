#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument Row Entity public interface.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class InstrumentIdentifier;
class Instrument;
class InstrumentComponent;

namespace visualization {

/**
 * RowEntity implementation containing Instrument object.
 *
 */
class STRATEGY_EXPORT InstrumentRowEntity final : public RowEntity
{
public:
    InstrumentRowEntity();

    InstrumentRowEntity(const InstrumentRowEntity & other) = default;
    InstrumentRowEntity(InstrumentRowEntity && other) noexcept = default;
    InstrumentRowEntity & operator=(const InstrumentRowEntity & other) = default;
    InstrumentRowEntity & operator=(InstrumentRowEntity && other) noexcept = default;

    /**
     * Get instrument object stored in row entity.
     *
     * @return instrument
     */
    const Instrument & GetInstrument() const;

    /**
     * Set instrument object and update view models containing row entity.
     *
     * @param instrument        instrument
     */
    void SetInstrument(const Instrument & instrument);

    /**
     * Set instrument component info and update view models containing row entity.
     *
     * @param composite        identifier of composite instrument
     * @param component        instrument component; id must me equal to instrument id passed to SetInstrument method
     */
    void SetInstrumentComponent(const InstrumentIdentifier & composite, const InstrumentComponent & component);

    ~InstrumentRowEntity() = default;
};

} // namespace visualization
} // namespace tbricks

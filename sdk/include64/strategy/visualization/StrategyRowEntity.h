#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy Row Entity public interface.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class StrategyData;

namespace visualization {

/**
 * RowEntity implementation containing StrategyData object.
 *
 */
class STRATEGY_EXPORT StrategyRowEntity final : public RowEntity
{
public:
    StrategyRowEntity();
    explicit StrategyRowEntity(Options options);

    StrategyRowEntity(const StrategyRowEntity & other) = default;
    StrategyRowEntity(StrategyRowEntity && other) noexcept = default;
    StrategyRowEntity & operator=(const StrategyRowEntity & other) = default;
    StrategyRowEntity & operator=(StrategyRowEntity && other) noexcept = default;

    /**
     * Get strategy data object stored in row entity.
     *
     * @return strategy data
     */
    const StrategyData & GetStrategy() const;

    /**
     * Set strategy data object and update view models containing row entity.
     *
     * @param strategy_data        strategy data
     */
    void SetStrategy(const StrategyData & strategy_data);

    ~StrategyRowEntity() = default;
};

} // namespace visualization
} // namespace tbricks

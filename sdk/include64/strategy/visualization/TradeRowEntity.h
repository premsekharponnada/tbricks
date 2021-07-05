#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Trade Row Entity public interface.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class Uuid;
class Trade;

namespace visualization {

/**
 * RowEntity implementation containing Trade object.
 *
 */
class STRATEGY_EXPORT TradeRowEntity final : public RowEntity
{
public:
    TradeRowEntity();

    TradeRowEntity(const TradeRowEntity & other) = default;
    TradeRowEntity(TradeRowEntity && other) noexcept = default;
    TradeRowEntity & operator=(const TradeRowEntity & other) = default;
    TradeRowEntity & operator=(TradeRowEntity && other) noexcept = default;

    /**
     * Get trade object stored in row entity.
     *
     * @return trade
     */
    const Trade & GetTrade() const;

    /**
     * Set trade object and update view models containing row entity.
     *
     * @param trade        trade
     */
    void SetTrade(const Trade & trade);

    virtual ~TradeRowEntity() = default;
};

} // namespace visualization
} // namespace tbricks

#pragma once
//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RowEntity cast functions.
//****************************************************************************************

#include "strategy/visualization/AggregateRowEntity.h"
#include "strategy/visualization/AuditDataRowEntity.h"
#include "strategy/visualization/CashRowEntity.h"
#include "strategy/visualization/CustomPropertiesRowEntity.h"
#include "strategy/visualization/InstrumentGroupRowEntity.h"
#include "strategy/visualization/InstrumentRowEntity.h"
#include "strategy/visualization/OrderRowEntity.h"
#include "strategy/visualization/PortfolioRowEntity.h"
#include "strategy/visualization/PositionRowEntity.h"
#include "strategy/visualization/RequestForQuoteRowEntity.h"
#include "strategy/visualization/ServiceRowEntity.h"
#include "strategy/visualization/StrategyRowEntity.h"
#include "strategy/visualization/TradeRowEntity.h"
#include "strategy/visualization/TreeRowEntity.h"
#include "strategy/visualization/UserRowEntity.h"
#include "strategy/visualization/ValueProviderRowEntity.h"

namespace tbricks::visualization {
/**
 * Cast RowEntity to one of its descendents
 *
 * Usage example:
 * for(const auto& it : aggregateRowEntity)
 * {
 *     auto instrument = EntityCast<InstrumentRowEntity>(it.Get());
 *     if(instrument.has_value())
 *     {
 *         ...
 *     }
 * }
 *
 * @param [in]  entity base row entity
 *
 * @return optional object containing TRowEntity type if entity may be cast to it, std::nullopt otherwise
 *
 */
template <typename TRowEntity>
std::optional<TRowEntity> EntityCast(RowEntity entity)
{
    auto variantEntity = entity.GetTypedRowEntity();
    if (!std::holds_alternative<TRowEntity>(variantEntity))
        return std::nullopt;
    return std::get<TRowEntity>(variantEntity);
}

/**
 * Cast RowEntity to one of its descendents
 *
 * Usage example:
 * auto& gridHandler = m_instrumentGrid;
 * auto instrument = EntityCast<InstrumentRowEntity>(gridHandler.GetRowEntity(rowId));
 * if(instrument.has_value())
 * {
 *     ...
 * }
 *
 * @param [in]  entity base row entity
 *
 * @return optional object containing TRowEntity type if entity may be cast to it, std::nullopt otherwise
 *
 */
template <typename TRowEntity>
std::optional<TRowEntity> EntityCast(std::optional<RowEntity> entity)
{
    if (!entity.has_value())
        return std::nullopt;
    return EntityCast<TRowEntity>(entity.value());
}
}

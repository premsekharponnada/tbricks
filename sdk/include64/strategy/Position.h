#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// positions
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy_generated/PositionBase.h"

#include "strategy/Types.h"
#include "strategy/InstrumentVenueIdentification.h"

#include <memory>

namespace tbricks {

namespace protocol {
class PortfolioPosition;
}
namespace filter {
class Filter;
}

/**
 * Portfolio positions.
 *
 * Supported aggregation styles are:
 *
 * * AGGREGATE_POSITIONS_BY_CURRENCY_SETTLEMENT_VENUE
 * Aggregation over available fields, portfolio identifier, instrument
 * identifier, currency, venue and settlement date. Most detailed style of
 * aggregation
 *
 * * AGGREGATE_POSITIONS
 * Aggregation over portfolio identifier and instrument identifier only. Used
 * for total volumes only, gross trade amount have no semantic meaning in this
 * context
 *
 * * AGGREGATE_POSITIONS_BY_CURRENCY
 * Aggregation over portfolio identifier, instrument identifier and currency.
 * Used to see your oncoming cashflow in different currencies on instrument level.
 *
 * * AGGREGATE_POSITIONS_BY_CURRENCY_SETTLEMENT
 * Aggregation over portfolio identifier, instrument identifier, currency and
 * settlement date. Used to see your oncoming cashflow in different currencies
 * on instrument level with settlement date granularity.
 *
 * * AGGREGATE_BALANCE_CASH_FLOWS
 * Aggregating over portfolio, currency and settlement date to see
 * the portfolios total oncoming cashflow. Volume bought and sold have no
 * semantic meaning in this context, only the gross trade amounts.
 *
 * * AGGREGATE_POSITIONS_BY_INSTRUMENT_AND_MARKET
 * Aggregating over portfolio, instrument and market
 *
 * * AGGREGATE_BALANCE_CASH_FLOWS_CURRENCY
 * Aggregating over portfolio and currency to see
 * the portfolios total oncoming cashflow. Volume bought and sold have no
 * semantic meaning in this context, only the gross trade amounts.
 *
 */
class STRATEGY_EXPORT Position : public PositionBase
{
    friend class TradeByPositionFilter;

public:
    enum AggregationType
    {
        AGGREGATE_POSITIONS_BY_CUSTOM_KEYS = 0,
        AGGREGATE_POSITIONS_BY_CURRENCY_SETTLEMENT_VENUE = 1,
        AGGREGATE_POSITIONS = 2,
        AGGREGATE_POSITIONS_BY_CURRENCY_SETTLEMENT = 3,
        AGGREGATE_BALANCE_CASH_FLOWS = 4,
        AGGREGATE_POSITIONS_BY_CURRENCY = 5,
        AGGREGATE_POSITIONS_BY_INSTRUMENT_AND_MARKET = 6,
        AGGREGATE_BALANCE_CASH_FLOWS_CURRENCY = 7
    };

public:
    Position() = default;
    Position(const Position & position) = default;
    Position(Position && position) = default;
    ~Position() override = default;

    Position & operator=(const Position & position) = default;
    Position & operator=(Position && position) = default;

    /**
     * Get type of aggregation used.
     *
     * @return                                             Aggregation type.
     */
    AggregationType GetAggregationType() const;

    /**
     * Check if instrument venue identification field is set.
     *
     * @return                                             True if field is set, false otherwise.
     */
    bool HasInstrumentVenueIdentification() const;

    /**
     * Get instrument venue identification.
     *
     * Present only when aggregating by venue.
     *
     * @return                                             Instrument venue identification.
     */
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;

    /**
     * Get instrument net position.
     *
     * @return                                             Net position.
     */
    Volume GetNetPosition() const;

    /**
     * Get gross amount of the position.
     *
     * @return                                             Gross amount of position.
     */
    Double GetInvested() const;

    /**
     * Merge position update on existing object.
     *
     * @param position                                     Position update.
     */
    void Merge(const Position & position);

public:
    using PositionBase::PositionBase;
};
}

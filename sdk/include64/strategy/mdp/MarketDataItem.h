#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// MarketDataItem
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/Linkage.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/stream/Stream.h"
#include "strategy/type/PublicTradeIdentifier.h"

#include <memory>

namespace tbricks {

class BestPrice;
class InstrumentStatus;
class Statistics;
class Depth;
class PublicTrade;
class IMarketDataItemInfo;

/**
 * Market Data Item object
 *
 * Interface for providing market data. Market data item is associated with
 * Instrument venue identifier and related parameters.
 *
 * Market data item is passed in HandleSubscribe and HandleUnsubscribe methods. After HandleUnsubscribe result of
 * MarketDataItem modification is unexpected.
 */
class STRATEGY_EXPORT MarketDataItem : public tbricks::Printable
{
public:
    MarketDataItem();
    MarketDataItem(std::shared_ptr<IMarketDataItemInfo> item);

    /**
     * Update BestPrice for MarketDataItem
     *
     * @param bp                BestPrice
     *
     * @deprecated  use "PartialUpdate" method instead. Deprecated in 2.14.4
     */
    [[deprecated(DEPRECATE_LINK)]] void Update(const BestPrice & bp);

    /**
     * Update Instrument status for MarketDataItem
     *
     * @param is                InstrumentStatus
     *
     * @deprecated  use "PartialUpdate" method instead. Deprecated in 2.14.4
     */
    [[deprecated(DEPRECATE_LINK)]] void Update(const InstrumentStatus & is);

    /**
     * Update Statistics for MarketDataItem
     *
     * @param st                Statistics
     *
     * @deprecated  use "PartialUpdate" method instead. Deprecated in 2.14.4
     */
    [[deprecated(DEPRECATE_LINK)]] void Update(const Statistics & st);

    /**
     * Partial update BestPrice for MarketDataItem
     * If update contains MarketDataParameters,
     * it will be merged with old parameters instead of replacing
     * If update does not contain ExchangeModifiedDatatime it will be set automatically on flush.
     *
     * @param bp                BestPrice
     */
    void PartialUpdate(const BestPrice & bp);

    /**
     * Update Statistics for MarketDataItem
     * If update contains MarketDataParameters,
     * it will be merged with old parameters instead of replacing
     *
     * @param st                Statistics
     */
    void PartialUpdate(const InstrumentStatus & is);

    /**
     * Update Statistics for MarketDataItem
     * If update contains MarketDataParameters,
     * it will be merged with old parameters instead of replacing
     * If update does not contain ExchangeModifiedDatatime it will be set automatically on flush.
     *
     * @param st                Statistics
     */
    void PartialUpdate(const Statistics & st);

    /**
     * Publish public trade
     *
     * @param trade             Public trade to publish
     *
     * @return                  Generated public trade identifier
     */
    PublicTradeIdentifier AddPublicTrade(PublicTrade & trade);

    /**
     * Send public trade cancellation
     *
     * @param id                Public trade identifier
     */
    void CancelPublicTrade(const PublicTradeIdentifier & id);

    /**
     * Restrict market data permissions to only those which are allowed by source_stream.
     * Only market data streams are allowed, exception is thrown otherwise.
     * When source stream is closed, its permissions are automatically removed from restrictions.
     */
    void RestrictPermissions(const Stream & source_stream);

    /**
     * Removes restrictions enforced by market data permissions from source_stream.
     * Only market data streams are allowed, exception is thrown otherwise.
     */
    void RemoveRestrictions(const Stream & source_stream);

    /**
     * Must be called after application filled snapshot for MarketDataItem.
     */
    void SendSnapshotDone();

    void Flush();

    const tbricks::InstrumentVenueIdentification & GetInstrumentVenueIdentification() const;

    LiquidityPoolIdentifier GetLiquidityPool() const;

    bool HasParameters() const;
    void GetParameters(StrategyParameters & parameters) const;

    /*
     * Unique identifier of Market data item used internally
     * Stream Item Identifier can be used as key for storing Items in Hash/Map containers
     */
    Identifier GetIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    std::shared_ptr<IMarketDataItemInfo> m_item;
    tbricks::InstrumentVenueIdentification m_ivid;
};
}

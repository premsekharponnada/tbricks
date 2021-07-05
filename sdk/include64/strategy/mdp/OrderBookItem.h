#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OrderBookItem
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/Linkage.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/OrderBook.h"
#include "strategy/stream/Stream.h"

#include <memory>

namespace tbricks {

class IMarketDataItemInfo;

/**
 * OrderBook Item object
 *
 * Interface for providing order book. OrderBook item is associated with
 * Instrument venue identifier and related parameters.
 *
 * OrderBook item is passed in HandleOrderBookSubscribe and HandleUnsubscribe methods. After HandleOrderBookUnsubscribe
 * result of MarketDataItem modification is unexpected. Application can provide order book by orders or by levels.
 * Changing the way of providing at runtime leads to exception.
 *
 * Application provide updates using AggregatedOrderBook or FullOrderBook.
 * Using FullOrderBook application can provide updates only using orders.
 * Using AggregatedOrderBook application can provide updates only using levels.
 */
class STRATEGY_EXPORT OrderBookItem : public tbricks::Printable
{
public:
    class AggregatedOrderBook;
    class FullOrderBook;
    class PriceBandedOrderBook;

    OrderBookItem();
    OrderBookItem(std::shared_ptr<IMarketDataItemInfo> item);

    virtual ~OrderBookItem() {}

    const tbricks::InstrumentVenueIdentification & GetInstrumentVenueIdentification() const;

    AggregatedOrderBook & GetAggregatedOrderBook();
    FullOrderBook & GetFullOrderBook();
    PriceBandedOrderBook & GetPriceBandedOrderBook();

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

    bool HasParameters();
    void GetParameters(StrategyParameters & parameters);

    /**
     * Unique identifier of Market data item used internally
     * Stream Item Identifier can be used as key for storing Items in Hash/Map containers
     */
    Identifier GetIdentifier() const;

    /**
     * %Set market data parameters
     *
     * @param                           Market data parameters
     *
     * @deprecated  use "PartialUpdate" method instead. Deprecated in 2.14.4
     */
    [[deprecated(DEPRECATE_LINK)]] void SetMarketDataParameters(const MarketDataParameters & param);

    /**
     * Update market data parameters
     * It will be merged with old parameters instead of replacing
     *
     * @param                           Market data parameters update
     */
    void PartialUpdate(const MarketDataParameters & param);

    virtual std::ostream & Print(std::ostream & strm) const;

    LiquidityPoolIdentifier GetLiquidityPool() const;

private:
    std::shared_ptr<IMarketDataItemInfo> m_item;
    tbricks::InstrumentVenueIdentification m_ivid;

private:
    enum OrderBookType
    {
        NONE,
        AGGREGATED,
        FULL,
        PRICE_BANDED
    };
    OrderBookType m_type = NONE;

    std::shared_ptr<AggregatedOrderBook> m_aggregatedOrderBook;
    std::shared_ptr<FullOrderBook> m_fullOrderBook;
    std::shared_ptr<PriceBandedOrderBook> m_priceBandedOrderBook;
};

class STRATEGY_EXPORT OrderBookItem::FullOrderBook : public tbricks::Printable
{
public:
    FullOrderBook(std::shared_ptr<IMarketDataItemInfo> & item);

    /**
     * @deprecated use SetOrder instead. Deprecated in 2.12.0
     */
    [[deprecated(DEPRECATE_LINK)]] void AddOrder(const Side & side,
                                                 const uint64_t id,
                                                 const Price & price,
                                                 const Volume & volume,
                                                 const Volume & volumeImplied = Volume(),
                                                 const String & participant = String());

    /**
     * @deprecated use SetOrder instead. Deprecated in 2.12.0
     */
    [[deprecated(DEPRECATE_LINK)]] void
    ModifyOrder(const Side & side, const uint64_t id, const Price & price, const Volume & volume, const Volume & volumeImplied = Volume());

    /**
     * %Set depth for order.
     * Depth must contain side, price, volume and depth identifier.
     *
     * @param depth  depth for order
     */
    void SetOrder(const Depth & depth);

    void DeleteOrder(const Side & side, const uint64_t id);

    void Clear();

    /**
     * %Set exchange modified date time
     * If update does not contain ExchangeModifiedDatatime it will be set automatically on flush.
     *
     * @param                           Exchange modified date time
     */
    void SetExchangeModifiedDatetime(const DateTime & param);

    void SendOrderBookSnapshot();

    void Flush();

    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << m_item << std::endl;
        return strm;
    }

private:
    std::shared_ptr<IMarketDataItemInfo> m_item;
};

class STRATEGY_EXPORT OrderBookItem::AggregatedOrderBook : public tbricks::Printable
{
public:
    AggregatedOrderBook(std::shared_ptr<IMarketDataItemInfo> & item);

    /**
     *  Add Level into OrderBook
     *  pos - position of level in OrderBook
     * @deprecated  use "SetLevel" method instead.
     *              Deprecated in 2.12.0
     *
     */
    [[deprecated(DEPRECATE_LINK)]] void AddLevel(const Side & side,
                                                 uint64_t pos,
                                                 const Price & price,
                                                 const Volume & volume,
                                                 const Volume & volumeImplied = Volume(),
                                                 uint32_t orderCount = 0);

    /**
     *  Add Level into OrderBook
     *
     * @deprecated  use "SetLevel" method instead.
     *              Deprecated in 2.12.0
     *
     */
    [[deprecated(DEPRECATE_LINK)]] void
    AddLevel(const Side & side, const Price & price, const Volume & volume, const Volume & volumeImplied = Volume(), uint32_t orderCount = 0);

    /**
     *  @deprecated  use "SetLevel" method instead. Deprecated in 2.12.0
     */
    [[deprecated(DEPRECATE_LINK)]] void ModifyLevel(const Side & side,
                                                    uint64_t pos,
                                                    const Price & price,
                                                    const Volume & volume,
                                                    const Volume & volumeImplied = Volume(),
                                                    uint32_t orderCount = 0);

    /**
     *  @deprecated  use "SetLevel" method instead. Deprecated in 2.12.0
     */
    [[deprecated(DEPRECATE_LINK)]] void
    ModifyLevel(const Side & side, const Price & price, const Volume & volume, const Volume & volumeImplied = Volume(), uint32_t orderCount = 0);

    void DeleteLevel(const Side & side, uint64_t pos);
    void DeleteLevel(const Side & side, const Price & price);

    /**
     * %Set depth for level.
     * Depth must contain side, price and volume. Depth identifier must be empty.
     *
     * @param pos    level
     * @param depth  depth for level
     */
    void SetLevel(uint64_t pos, const Depth & depth);

    /**
     * %Set depth for level.
     * Depth must contain side, price and volume. Depth identifier must be empty.
     *
     * @param depth  depth for level
     */
    void SetLevel(const Depth & depth);

    void Clear();

    /**
     * %Set exchange modified date time
     * If update does not contain ExchangeModifiedDatatime it will be set automatically on flush.
     *
     * @param                           Exchange modified date time
     */
    void SetExchangeModifiedDatetime(const DateTime & param);

    void SendOrderBookSnapshot();

    void Flush();

    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << m_item << std::endl;
        return strm;
    }

private:
    std::shared_ptr<IMarketDataItemInfo> m_item;
};

class STRATEGY_EXPORT OrderBookItem::PriceBandedOrderBook : public tbricks::Printable
{
public:
    PriceBandedOrderBook(std::shared_ptr<IMarketDataItemInfo> & item);

    void AddLevel(const Side & side, const Volume & volume, const Price & price, uint32_t orderCount = 0);
    void ModifyLevel(const Side & side, const Volume & volume, const Price & price, uint32_t orderCount = 0);
    void DeleteLevel(const Side & side, const Volume & volume);

    void Clear();

    /**
     * %Set exchange modified date time
     * If update does not contain ExchangeModifiedDatatime it will be set automatically on flush.
     *
     * @param                           Exchange modified date time
     */
    void SetExchangeModifiedDatetime(const DateTime & param);

    void SendOrderBookSnapshot();

    void Flush();

    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << m_item << std::endl;
        return strm;
    }

private:
    std::shared_ptr<IMarketDataItemInfo> m_item;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OrderBook
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Value.h"
#include "strategy/Depth.h"
#include "strategy/Hash.h"
#include "strategy/LatencyTimer.h"
#include "strategy/MarketDataParameters.h"

#include <unordered_map>

namespace tbricks {

namespace protocol {
class OrderBook;
}

//****************************************************************************
// OrderBook class
//****************************************************************************
class STRATEGY_EXPORT OrderBook : public Printable
{
public:
    enum class Type
    {
        LIMIT = 0,       ///< Regular limit orderbook pepresending individual orders or their aggregation per-price level.
        PRICE_BANDED = 1 ///< %Order book expressed in terms of prices for specific volumes, i.e. price to trade specific volume.
    };

public:
    class Update;
    class Stream;

public:
    /**
     * Default constructor.
     *
     * Initializes object to default value -- no fields present, all returned
     * values are empty.
     *
     * This is mostly for use in STL containers.
     */
    OrderBook() = default;

    /**
     * Copy constructor.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param order_book                Object to copy from
     */
    OrderBook(const OrderBook & order_book) = default;

    /**
     * Assignment operator.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param order_book                Object to copy from
     * @return                          Updated object
     */
    OrderBook & operator=(const OrderBook & order_book) = default;

    /**
     * Destructor.
     */
    ~OrderBook() override = default;

    void Clear();
    bool Empty() const;

public:
    /**
     * Getting depth.
     *
     * Getting the bid and ask Depth objects for the specified depth level.
     * If there is no such level, returns false
     *
     * @param depth                     The depth level for which to get the Depth information
     * @param bid                       The bid Depth for the level
     * @param ask                       The ask Depth for the level
     * @return                          true if at least one of bid or ask had such a depth level
     */
    bool GetDepth(size_t depth, Depth & bid, Depth & ask) const;

    size_t GetBidSideSize() const;

    /**
     * Getting bid depth.
     *
     * Getting the bid Depth object for the specified depth level.
     * If there is no such level, returns false
     *
     * @param depth                     The depth level for which to get the Depth information
     * @param bid                       The bid Depth for the level
     * @return                          true if there was such a level (i.e. if depth < GetBidSideSize() )
     */
    bool GetBidDepth(size_t depth, Depth & bid) const;

    size_t GetAskSideSize() const;

    /**
     * Getting ask depth.
     *
     * Getting the ask Depth object for the specified depth level.
     * If there is no such level, returns false
     *
     * @param depth                     The depth level for which to get the Depth information
     * @param ask                       The ask Depth for the level
     * @return                          true if there was such a level (i.e. if depth < GetAskSideSize() )
     */
    bool GetAskDepth(size_t depth, Depth & ask) const;

    /**
     * Getting the average bid price for the specified volume.
     *
     * Returns the volume-weighted average bid price for the specified volume.
     *
     * @param volume                    The volume for which to calculate the price
     * @return                          The volume-weighted average price.
     *                                  If the volume is not available, the Price will be empty.
     */
    Price GetWeightedBidPrice(const Volume & volume) const;

    /**
     * Getting the average ask price for the specified volume.
     *
     * Returns the volume-weighted average ask price for the specified volume.
     *
     * @param volume                    The volume for which to calculate the price
     * @return                          The volume-weighted average price.
     *                                  If the volume is not available, the Price will be empty.
     */
    Price GetWeightedAskPrice(const Volume & volume) const;

    Volume GetTotalBidVolume() const;
    Volume GetTotalAskVolume() const;

    /**
     * Getting the order book type.
     *
     * @return                          Order book type.
     */
    Type GetType() const;

    /**
     * Get exchange modifier date time.
     *
     * @return                          exchange modified date time
     */
    const DateTime & GetExchangeModifiedDatetime() const;

    /**
     * Get host modifier date time.
     *
     * @return                          host modified date time
     */
    const DateTime & GetHostModifiedDatetime() const;

    /**
     * Get market data parameters.
     *
     * @return                          Market data parameters.
     */
    const MarketDataParameters & GetMarketDataParameters() const;

private:
    friend STRATEGY_EXPORT class PriceBasedDepthComparator;
    friend STRATEGY_EXPORT class VolumeBasedDepthComparator;
    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, Type value);

public:
    void Merge(const OrderBook::Update & update);

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    void DeleteDepth(const Integer & id);
    friend class OrderBookStream;
    void init(const protocol::OrderBook & book);

private:
    std::vector<Integer> m_bid;
    std::vector<Integer> m_ask;
    std::unordered_map<Integer, size_t> m_indexes;
    std::unordered_map<Integer, Depth> m_depths;
    MarketDataParameters m_parameters;
    Type m_type;
    DateTime m_host_modified_datetime;
    DateTime m_exchange_modified_datetime;
};

class STRATEGY_EXPORT FullOrderBook : public OrderBook
{};

//****************************************************************************
// OrderBook::Update class
//****************************************************************************
class STRATEGY_EXPORT OrderBook::Update : public Printable
{
public:
    Update();
    ~Update() override = default;

    /**
     * Getting the order book type.
     *
     * @return                          Order book type.
     */
    OrderBook::Type GetType() const;

    /**
     * Get exchange modifier date time.
     *
     * @return                          exchange modified date time
     */
    const DateTime & GetExchangeModifiedDatetime() const;

    /**
     * Get host modifier date time.
     *
     * @return                          host modified date time
     */
    const DateTime & GetHostModifiedDatetime() const;

    /**
     * Get market data parameters.
     *
     * @return                          Market data parameters.
     */
    const MarketDataParameters & GetMarketDataParameters() const;

    bool Empty() const;

    const std::vector<Depth> & GetDepths() const;

    bool IsFullUpdate() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

public:
    Update(std::shared_ptr<protocol::OrderBook> && msg);
    Update(const protocol::OrderBook * msg);

    void Decode(const protocol::OrderBook & msg);

private:
    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, OrderBook::Type value);

private:
    bool m_full_update = false;
    std::vector<Depth> m_depths;
    MarketDataParameters m_parameters;
    Type m_type = Type::LIMIT;
    DateTime m_host_modified_datetime;
    DateTime m_exchange_modified_datetime;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OrderBook.
//****************************************************************************************

#include "strategy/Strategy.h"
#include "strategy/Linkage.h"
#include "strategy/OrderBook.h"
#include <map>

namespace tbricks {

namespace protocol {
class OrderBook;
class Depth;
}

namespace test {

/**
 * Order book wrapper.
 */
class STRATEGY_EXPORT OrderBook : public Printable
{
public:
    class Level;

public:
    /**
     * OrderBook constructor.
     *
     * @param viid                       VenueInstrumentIdentifier for which.
     *
     * @param type                       OrderBook Type.
     */
    OrderBook(const VenueInstrumentIdentifier & viid, tbricks::OrderBook::Type type = tbricks::OrderBook::Type::LIMIT);
    OrderBook(const OrderBook & order_book);
    virtual ~OrderBook();

    OrderBook & operator=(const OrderBook & order);

public:
    /**
     * Get order book level.
     *
     * Price(Volume) should be used as key to provide correct
     * PriceLevelOrderBook(PriceBanded OrderBook) on plugin side.
     *
     * First key access is initializing empty level.
     *
     * @param key                        Level key.
     */
    Level & GetBidLevel(double key);
    Level & GetAskLevel(double key);

    /**
     * Reset order book. Call Remove for all levels.
     */
    void Reset();

    const VenueInstrumentIdentifier & GetVenueInstrumentIdentifier() const;

public:
    /**
     * Order book level wrapper.
     */
    class STRATEGY_EXPORT Level
    {
    public:
        Level();

        /**
         * %Set order book level.
         *
         * Note, in case of change level price (volume)
         * at PriceLevelOrderBook (PriceBanded OrderBook),
         * old level should be removed and new inserted with different key.
         * Otherwise, there will be two current level with different prices (volumes).
         */
        void Set(const Price & price,
                 const Volume & volume,
                 const Integer & orderCount = Integer(),
                 const Volume & volumeImplied = Volume(),
                 const Volume & participantVolume = Volume());

        /**
         * Mark level removed.
         */
        void Remove();

    private:
        protocol::Depth * m_depth;
        friend class OrderBook;
    };

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void get_impl(protocol::OrderBook & order_book, VenueInstrumentIdentifier & viid) const;
    void flush();

private:
    std::map<double, Level> m_bids, m_asks;
    protocol::OrderBook * m_order_book;
    VenueInstrumentIdentifier m_viid;

    friend class VirtualServiceMarketData;
    friend class VirtualServiceMatchingEngine;
    friend class VirtualServiceOrderPersistence;
};
}
}

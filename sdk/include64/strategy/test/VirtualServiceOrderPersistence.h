#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceOrderPersistence is a
// system virtual OrderPersistence service.
//****************************************************************************************

#include "strategy/test/OrderBook.h"
#include "strategy/test/IVirtualService.h"
#include "strategy/stream/OrderStream.h"

namespace tbricks { namespace test {
class OPImpl;
class OrderOptions;

class STRATEGY_EXPORT VirtualServiceOrderPersistence : public IVirtualService
{
public:
    /**
     * Send order update to schedule HandleOrderUpdate() event on an app side.
     * Do not use volume delta from update.
     *
     * @param update     Order Update.
     */
    void UpdateOrder(const test::OrderOptions & update);

    /**
     * Send order book update to schedule HandleQuoteInformation() event on an app side.
     * Full order book will be sent.
     *
     * @param viid              Venue instrument identifier.
     *
     * @param update            Order book update.
     */
    void UpdateOrderBook(const VenueInstrumentIdentifier & viid, const test::OrderBook & update);

    /**
     * Send order book update to schedule HandleQuoteInformation() event on an app side.
     *
     * @param update            Order book update. Recent actions will be flushed.
     */
    void UpdateOrderBook(test::OrderBook & update);

public:
    /**
     * VirtualServiceOrderPersistence constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceOrderPersistence(OPImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceOrderPersistence();

private:
    VirtualServiceOrderPersistence() = delete;
    VirtualServiceOrderPersistence(const VirtualServiceOrderPersistence &) = delete;
    VirtualServiceOrderPersistence & operator=(const VirtualServiceOrderPersistence &) = delete;
    OPImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks

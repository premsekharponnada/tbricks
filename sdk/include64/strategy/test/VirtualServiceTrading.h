#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceTrading is a
// system virtual Trading service.
//****************************************************************************************

#include "strategy/test/IVirtualService.h"
#include "strategy/test/OrderOptions.h"
#include "strategy/test/BlockOrderOptions.h"
#include "strategy/BlockOrder.h"

namespace tbricks::test {
class TRImpl;

class STRATEGY_EXPORT VirtualServiceTrading : public IVirtualService
{
public:
    /**
     * @return  Venue identifier
     */
    VenueIdentifier GetVenueId() const;

    /**
     * Waits until an order is created
     *
     * @return  Options of the order that will be created
     */
    test::OrderOptions WaitOrderCreateRequest();

    /**
     * Waits until an order is modified
     *
     * @return  Options of the order that will be modified
     */
    test::OrderOptions WaitOrderModifyRequest();

    /**
     * Waits until an order is deleted
     *
     * @return  Options of the order that will be deleted
     */
    test::OrderDeleteOptions WaitOrderDeleteRequest();

    /**
     * Sends update of the order to schedule HandleOrderUpdate() event on an app side
     * Note: It ignores 'Volume delta' option from the update
     *
     * @param update     Order Update or options.
     */
    void UpdateOrder(const test::OrderOptions & update);

    [[deprecated(DEPRECATE_LINK)]] void SetRequestReply(const Status::StatusValue & status, const char * status_text);

    /**
     * Overrides default order request reply.
     * HandleRequestReply() event is scheduled automatically on an app side for each incoming request
     *
     * @param status       StatusOk or StatusFail otherwise if the engine couldn't process request
     * @param status_text  Failure reason if status == StatusFail, otherwise empty string
     */
    void SetRequestReply(const Status & status, const String & status_text);

    /**
     * Waits until an order is created
     *
     * @return           BlockOrder
     */
    BlockOrder WaitBlockOrderCreateRequest();

    /**
     * Waits until an order is deleted
     *
     * @return           BlockOrderDeleteOptions
     */
    BlockOrderIdentifier WaitBlockOrderDeleteRequest();

    /**
     * Overrides default block order request reply.
     * HandleRequestReply() event is scheduled automatically on an app side for each incoming request
     *
     * @param status       StatusOk or StatusFail otherwise if the engine couldn't process request
     * @param status_text  Failure reason if status == StatusFail, otherwise empty string
     */
    void SetBlockOrderRequestReply(const Status & status, const String & status_text);

    enum UpdateTypeValue
    {
        OrderCreateRequestType = 1,
        OrderModifyRequestType = 2,
        OrderDeleteRequestType = 3,
        BlockOrderCreateRequestType = 4,
        BlockOrderDeleteRequestType = 5,
    };

public:
    /**
     * VirtualServiceTrading constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceTrading(TRImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceTrading();

private:
    VirtualServiceTrading() = delete;
    VirtualServiceTrading(const VirtualServiceTrading & is) = delete;
    VirtualServiceTrading & operator=(const VirtualServiceTrading &) = delete;
    TRImpl * m_impl;
};

} // \namespace tbricks::test

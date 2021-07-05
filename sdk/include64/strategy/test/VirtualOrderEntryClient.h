#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OrderEntry client is used for flow app testing.
//****************************************************************************************

#include "strategy/test/OrderOptions.h"
#include "strategy/test/BlockOrderOptions.h"

namespace tbricks::test {
class OECImpl;

class STRATEGY_EXPORT VirtualOrderEntryClient
{
public:
    VirtualOrderEntryClient();
    ~VirtualOrderEntryClient();

public:
    /**
     * Sends the request to create an order to the trading service.
     *
     * @param  options  Options for the order that will be created
     */
    void SendOrderCreateRequest(const test::OrderOptions & options);

    /**
     * Sends the request to modify an order to the trading service.
     *
     * @param  options  New options for the order that will be modified
     */
    void SendOrderModifyRequest(const test::OrderOptions & options);

    /**
     * Sends the request to delete the order
     *
     * @param  options  Options for the order that will be deleted
     */
    void SendOrderDeleteRequest(const test::OrderDeleteOptions & options);

    /**
     * Waits until reply is received.
     *
     * @return  Reply status.
     */
    Status WaitOrderReplyReceived();

    [[deprecated(DEPRECATE_LINK)]] Status::StatusValue WaitOrderReply();

    /**
     * Sends the request to create a block order to the trading service.
     *
     * @param  options  Options for the block order that will be created
     */
    void SendBlockOrderCreateRequest(const BlockOrderOptions & options);

    /**
     * Sends the request to delete the block order
     *
     * @param  options  Options for the block order that will be deleted
     */
    void SendBlockOrderDeleteRequest(const BlockOrderIdentifier & identifier);

    /**
     * Waits until a reply is received
     *
     * @return  Reply status
     */
    Status WaitBlockOrderReplyReceived();

private:
    VirtualOrderEntryClient(const VirtualOrderEntryClient &) = delete;
    VirtualOrderEntryClient & operator=(const VirtualOrderEntryClient &) = delete;
    OECImpl * m_impl;
};

} // \namespace tbricks::test

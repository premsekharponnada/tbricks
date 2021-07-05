#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BlockOrder Manager.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/BlockOrder.h"

namespace tbricks {

class InitializationReason;

namespace pe {
class BlockOrderManagerImpl;
}

/**
 * The BlockOrderManager is used to add, modify, and delete block orders.
 *
 * Each app should only have one instance of the BlockOrderManager.
 *
 * The BlockOrderManager provides the following functionality:
 * - Send block order create requests
 * - Send block order delete requests
 * - Handle block order updates
 * - BlockOrder recovery in case of Strategy Engine restart
 *
 */
class STRATEGY_EXPORT BlockOrderManager
{
public:
    class CreateRequestResult;

public:
    BlockOrderManager();
    virtual ~BlockOrderManager();

    /**
     * Apps call this method when they need to start recovery process for their own orders.
     * For example, after restart of the app.
     *
     * @param reason                    Reason to start recovery.
     * @param get_deleted               Subscribe to deleted orders.
     *
     * @return true                     The reason parameter is RECOVERED and other StartRecovery()
     *                                  is not running. This means there are may be orders to recover.
     *                                  Recovery will be performed.
     * @return false                    The reason parameter is not RECOVERED or other StartRecovery()
     *                                  is running.
     */
    bool StartRecovery(const InitializationReason & reason, bool get_deleted = true);

    /**
     * This method detects if the %Order Manager is in recovery state.
     *
     * @return true                      %Order Manager is in recovery state.
     * @return false                     %Order Manager is NOT in recovery state.
     */
    bool InRecovery() const;

    /**
     * This method is used to create an order.
     *
     * @param options                   BlockOrder options
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          RequestResult
     */
    CreateRequestResult SendCreateRequest(BlockOrder::Options & options, IRequestReplyHandler & handler);

    /**
     * This method is used to delete an order by identifier.
     *
     * If order created by another app, the engine need subscribe to order to be able
     * to delete it, consider to use a static method version in this case.
     *
     * @param order_id                  BlockOrder identifier
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          RequestResult
     */
    Identifier SendDeleteRequest(const BlockOrderIdentifier & order_id, IRequestReplyHandler & handler);

    virtual void HandleRecoveryCompleted() = 0;
    virtual void HandleBlockOrderUpdate(const BlockOrder::Update & update) = 0;

private:
    friend pe::BlockOrderManagerImpl;

    BlockOrderManager(const BlockOrderManager & src);
    BlockOrderManager & operator=(const BlockOrderManager & src);
};

class STRATEGY_EXPORT BlockOrderManager::CreateRequestResult
{
public:
    CreateRequestResult() = default;
    CreateRequestResult(const Identifier & request_id, const BlockOrderIdentifier & order_id) : m_request_id(request_id), m_order_id(order_id) {}

    const Identifier & GetRequestIdentifier() const { return m_request_id; }

    const BlockOrderIdentifier & GetBlockOrderIdentifier() const { return m_order_id; }

    /** @deprecated Deprecated in 2.14.5 */
    [[deprecated(DEPRECATE_LINK)]] bool Empty() const { return m_request_id.Empty() && m_order_id.Empty(); }

        /** @deprecated Deprecated in 2.14.5 */
        [[deprecated(DEPRECATE_LINK)]] void Clear()
    {
        m_request_id.Clear();
        m_order_id.Clear();
    }

private:
    Identifier m_request_id;
    BlockOrderIdentifier m_order_id;
};
}

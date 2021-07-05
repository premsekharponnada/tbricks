#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Order Manager.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Strategy.h"
#include "strategy/Order.h"
#include "strategy/stream/OrderStream.h"
#include "strategy/stream_filter/OrderFilter.h"
#include "strategy_generated/OrderMassCancelConditionBase.h"

namespace tbricks {
namespace pe {
class OrderManagerImpl;
}

/**
 * The OrderManager is used to add, modify, and delete orders.
 *
 * Each app should only have one instance of the OrderManager.
 *
 * The OrderManager provides the following functionality:
 * - Send order create requests
 * - Send order modify requests
 * - Send order delete requests
 * - Handle order updates
 * - Order recovery in case of Strategy Engine restart
 *
 */
class STRATEGY_EXPORT OrderManager
{
public:
    class OrderRequestResult;
    class OrderCreateRequestResult;
    class TemplateCreateRequestResult;
    class MassCancelCondition;

public:
    /**
     * Create OrderManager with disables coalescing by default.
     */
    OrderManager();

    /**
     * Coalescing flag enable coalescing of updates still waiting for
     * processing in the queue. Sequences of requests from one or more
     * incoming sessions can be folded into fewer,
     * singular requests to the outside world.
     *
     * @param coalescing               coalescing flag
     */
    OrderManager(bool coalescing);

    virtual ~OrderManager();

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
     * @param options                   Order options
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          RequestResult
     */
    OrderCreateRequestResult SendCreateRequest(Order::Options & options, IRequestReplyHandler & handler);

    /**
     * This method is used to modify an order created by current app instance only.
     *
     * @param order_id                  Order identifier
     * @param modifier                  Order modifier
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          RequestResult
     */
    Identifier SendModifyRequest(const OrderIdentifier & order_id, const Order::Modifier & modifier, IRequestReplyHandler & handler);

    /**
     * This method is used to delete an order by identifier.
     *
     * If order created by another app, the engine need subscribe to order to be able
     * to delete it, consider to use a static method version in this case.
     *
     * @param order_id                  Order identifier
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          RequestResult
     */
    Identifier SendDeleteRequest(const OrderIdentifier & order_id, IRequestReplyHandler & handler);

    /**
     * This method is used to delete the order created by another app.
     *
     * This method is available only for Strategy, Accessory and Limit apps.
     *
     * @param order                     Order object
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          RequestResult
     */
    static Identifier SendDeleteRequest(const Order & order, IRequestReplyHandler & handler);

    /**
     * SendDeleteRequest is used to delete the orders which matches the filter.
     *
     * Request reply handler will be called for each request identifier
     * from order request results
     *
     * This method is available only for Strategy and Limit apps.
     *
     * @param filter                    Request filter
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          Vector of RequestResult which is a pair of
     *                                  requested identifier and service identifier
     *                                  of the order request.
     */
    static std::vector<OrderRequestResult> SendDeleteRequest(const Order::Stream::Filters::Filter & filter, IRequestReplyHandler & handler);

    /**
     * SendDeleteRequest is used to delete the orders which matches the condition.
     *
     * Request reply handler will be called for each request identifier
     * from order request results
     *
     * This method is available only for Strategy and Limit apps.
     *
     * @param condition                 Request condition
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          Vector of RequestResult which is a pair of
     *                                  requested identifier and service identifier
     *                                  of the order request.
     */
    static std::vector<OrderRequestResult> SendDeleteRequest(const MassCancelCondition & condition, IRequestReplyHandler & handler);

    /**
     * SendDeleteRequest is used to delete the orders which matches the filter.
     *
     * Request reply handler will be called for each request identifier
     * from order request results
     *
     * This method is available only for Strategy and Limit apps.
     *
     * @param filter                    Request filter
     * @param comment                   Request comment
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          Vector of RequestResult which is a pair of
     *                                  requested identifier and service identifier
     *                                  of the order request.
     */
    static std::vector<OrderRequestResult>
    SendDeleteRequest(const Order::Stream::Filters::Filter & filter, const String & comment, IRequestReplyHandler & handler);

    /**
     * SendDeleteRequest is used to delete the orders which matches the condition.
     *
     * Request reply handler will be called for each request identifier
     * from order request results
     *
     * This method is available only for Strategy and Limit apps.
     *
     * @param condition                 Request condition
     * @param comment                   Request comment
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          Vector of RequestResult which is a pair of
     *                                  requested identifier and service identifier
     *                                  of the order request.
     */
    static std::vector<OrderRequestResult>
    SendDeleteRequest(const MassCancelCondition & condition, const String & comment, IRequestReplyHandler & handler);

    /**
     * Creates order template, this can be done at any time. If there is no connection to trading service, SE caches template and sends it to TR when
     * connection is established OrderManager owns templates created by an app and deletes them when instance is destroyed
     */
    TemplateCreateRequestResult CreateOrderTemplate(const Order::Template & order_template,
                                                    IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Deletes previously created order template
     */
    void DeleteOrderTemplate(const OrderTemplateIdentifier & template_id);

    /**
     * Activates template to send an order
     * Order creation is NACKed via HandleRequestReply if specified template does not exists in Trading Service
     * Order creation is Failed (failed order update) if order/template doesn't fit limits
     */
    OrderCreateRequestResult CreateOrderFromTemplate(const OrderTemplateIdentifier & template_id,
                                                     const Order::ActivationOptions & options,
                                                     IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Resolves identifier of trading service which can be used to send order in a given
     * viid which will reach venue (provided it's allowed by pre-trade limits).
     * Returns empty identifier if trading service is not found or it's not properly
     * connected to the venue.
     * The method might involve request/reply from engine to trading services
     * if this ivid and user was not traded since engine start.
     *
     * @param ivid                      required ivid
     * @return                          service identifier what is used to send order
     *                                  in the current moment
     */
    ServiceIdentifier ResolveTradingService(const InstrumentVenueIdentification & ivid);

    virtual void HandleRecoveryCompleted() = 0;
    virtual void HandleOrderUpdate(const Order::Update & update) = 0;

private:
    OrderManager(const OrderManager & src);
    OrderManager & operator=(const OrderManager & src);
};

class STRATEGY_EXPORT OrderManager::OrderRequestResult : public Printable
{
public:
    OrderRequestResult() = default;
    OrderRequestResult(const Identifier & id, const ServiceIdentifier & sid) : m_request_id(id), m_service_id(sid) {}

public:
    const Identifier & GetRequestIdentifier() const { return m_request_id; }
    const ServiceIdentifier & GetServiceIdentifier() const { return m_service_id; }

    /** @deprecated Deprecated in 2.14.5 */
    [[deprecated(DEPRECATE_LINK)]] bool Empty() const { return m_request_id.Empty() && m_service_id.Empty(); }

        /** @deprecated Deprecated in 2.14.5 */
        [[deprecated(DEPRECATE_LINK)]] void Clear()
    {
        m_request_id.Clear();
        m_service_id.Clear();
    }

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_id;
    ServiceIdentifier m_service_id;
};

class STRATEGY_EXPORT OrderManager::OrderCreateRequestResult
{
public:
    OrderCreateRequestResult() = default;
    OrderCreateRequestResult(const Identifier & request_id, const OrderIdentifier & order_id) : m_request_id(request_id), m_order_id(order_id) {}
    OrderCreateRequestResult(const Identifier & request_id, const OrderIdentifier & order_id, const MIC & mic) :
        m_request_id(request_id),
        m_order_id(order_id),
        m_mic(mic)
    {}

    const Identifier & GetRequestIdentifier() const { return m_request_id; }
    const OrderIdentifier & GetOrderIdentifier() const { return m_order_id; }

    /**
     * @deprecated Deprecated in 2.14.5, use Order::Options::GetInstrumentVenueIdentification() and
     *                                       InstrumentVenueIdentification::GetMIC() instead
     */
    [[deprecated(DEPRECATE_LINK)]] const MIC & GetMIC() const { return m_mic; }

        /** @deprecated Deprecated in 2.14.5, use OrderCreateRequestResult::GetOrderIdentifier().Empty() instead */
        [[deprecated(DEPRECATE_LINK)]] bool Empty() const
    {
        return m_request_id.Empty() && m_order_id.Empty();
    }

    /** @deprecated Deprecated in 2.14.5 */
    [[deprecated(DEPRECATE_LINK)]] void Clear() {
        m_request_id.Clear();
        m_order_id.Clear();
        m_mic.Clear();
    }

    private : Identifier m_request_id;
    OrderIdentifier m_order_id;
    MIC m_mic;
};

class STRATEGY_EXPORT OrderManager::TemplateCreateRequestResult
{
public:
    TemplateCreateRequestResult() = default;
    TemplateCreateRequestResult(const Identifier & request_id, const OrderTemplateIdentifier & order_id) :
        m_request_id(request_id),
        m_order_id(order_id)
    {}

    const Identifier & GetRequestIdentifier() const { return m_request_id; }
    const OrderTemplateIdentifier & GetOrderTemplateIdentifier() const { return m_order_id; }

private:
    Identifier m_request_id;
    OrderTemplateIdentifier m_order_id;
};

class STRATEGY_EXPORT OrderManager::MassCancelCondition : public OrderMassCancelConditionBase
{
    using OrderMassCancelConditionBase::OrderMassCancelConditionBase;
};
}

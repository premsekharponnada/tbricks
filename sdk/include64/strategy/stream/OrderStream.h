#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OrderStream
//****************************************************************************************

#include "strategy/Order.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * Order::Stream class is an interface to receive snapshots
 * and/or live order updates.
 *
 */
class STRATEGY_EXPORT Order::Stream : public tbricks::Stream
{
public:
    class IHandler;
    class Options;

public:
    /**
     * Filters defined for Order streams.
     */
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByIdentifier;
        class ByPortfolio;
        class ByInstrument;
        class ByOwner;
        class ByCreator;
        class ByParentStrategy;
        class ByRootStrategy;
        class ByAncestorStrategy;
        class Active;
        class ByHostModifiedDateTime;
        class ByHostCreatedDateTime;
        class BySide;
        class ByTransactionState;
        class ByPrice;
        class ByTotalVolume;
        class ByFilledVolume;
        class ByMIC;
        class ByExtraData;
        class ByClient;
        class ByHandler;
        class ByVenue;
        class ByRootPortfolio;
        class ByAlgoLabel;
        class ByType;
        class Quote;
        class FromOrder;
        class FromQuote;
    };

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    Stream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    Stream(IHandler & handler);

    /**
     * %Set callback interface.
     *
     * Associates current stream object with a callback interface where
     * stream updates will be delivered to.
     *
     * If stream is already opened this method has no effect.
     *
     * @param handler                   Callback interface
     */
    void SetCallback(IHandler & handler);

    /**
     * Open a stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter
     * @param coalescing                Enable coalescing of stream data
     */
    void Open(Type type, const Filters::Filter & filter, bool coalescing = true);

    /**
     * Open a stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Stream options
     */
    void Open(Type type, const Options & options);

    /**
     * Open an audit stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param from                      Initial point of time
     * @param to                        Point of time to which the updates will
     *                                  be collected
     */
    void OpenAudit(Type type, const Filters::Filter & filter, const DateTime & from = DateTime(), const DateTime & to = DateTime());

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * Order::Stream::IHandler class is a callback interface to
 * handle instrument parameter stream events.
 *
 * @see Order::Stream
 */
class STRATEGY_EXPORT Order::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Order update stream handler.
     *
     * Method is called when a new order update becomes
     * available on the stream.
     *
     * @param stream                   Stream identifier
     * @param order_id                 Order identifier
     * @param update                   Update data
     */
    virtual void HandleOrderUpdate(const StreamIdentifier & stream_id, const Order::Update & update) = 0;

    /**
     * Order stream invalidation handler.
     *
     * Called when an item previously seen on the stream stops to match
     * stream filter, to signal that no strategy updates for this strategy
     * instance will be available on the stream from now on, unless the
     * instance changes.
     *
     * For instance, if stream was open with a filter for all *active*
     * orders and an order that previously matched the
     * filter becomes filled, HandleOrderInvalidate() will be called
     * for such instance.
     *
     * @param stream                   Stream where invalidation occured
     * @param id                       Identifier of invalidated order
     */
    virtual void HandleOrderInvalidate(const StreamIdentifier & stream, const OrderIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};
}

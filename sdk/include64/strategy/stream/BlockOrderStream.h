#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BlockOrderStream.
//****************************************************************************************

#include "strategy/BlockOrder.h"
#include "strategy/stream/Stream.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * BlockOrder::Stream class is an interface to receive snapshots
 * and/or live block order updates.
 *
 */
class STRATEGY_EXPORT BlockOrder::Stream : public tbricks::Stream
{
public:
    class IHandler;
    class Options;

public:
    /**
     * Filters defined for BlockOrder streams.
     */
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class Active;
        class ByHostModifiedDateTime;
        class ByHostCreatedDateTime;
        class ByParentStrategy;
    };

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    Stream() = default;

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
     * @param options                   Stream options
     */
    void Open(Type type, const Options & options);

    /**
     * Open a stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter
     */
    void Open(Type type, const Filters::Filter & filter);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * BlockOrder::Stream::IHandler class is a callback interface to
 * handle instrument parameter stream events.
 *
 * @see BlockOrder::Stream
 */
class STRATEGY_EXPORT BlockOrder::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Order update stream handler.
     *
     * Method is called when a new block order update becomes
     * available on the stream.
     *
     * @param stream                   Stream identifier
     * @param block_order_id           Block order identifier
     * @param update                   Block order update
     */
    virtual void HandleBlockOrderUpdate(const StreamIdentifier & stream_id, const BlockOrder::Update & update) = 0;

    /**
     * Order stream invalidation handler.
     *
     * Called when an item previously seen on the stream stops to match
     * stream filter, to signal that no strategy updates for this strategy
     * instance will be available on the stream from now on, unless the
     * instance changes.
     *
     * For instance, if stream was open with a filter for all *active*
     * block orders and an block order that previously matched the
     * filter becomes filled, HandleOrderInvalidate() will be called
     * for such instance.
     *
     * @param stream                   Stream where invalidation occured
     * @param id                       Identifier of invalidated order
     */
    virtual void HandleBlockOrderInvalidate(const StreamIdentifier & stream, const BlockOrderIdentifier & id) = 0;

protected:
    virtual ~IHandler() = default;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Strategy.h"
#include "strategy/StrategyUpdate.h"

#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/StrategyFilter.h"
#include "strategy/stream/StreamOptions.h"
#include "strategy/stream_throttle/StrategyParametersThrottle.h"

// \namespace tbricks
namespace tbricks {

/**
 * StrategyStream class is an interface to receive snapshots and/or live
 * strategy updates.
 *
 * StrategyStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last StrategyStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private StrategyStream::IHandler
 * {
 *     ...
 *
 * private:
 *     StrategyStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     StrategyByParentFilter filter(GetIdentifier());
 *
 *     // receive all historical and live data for all direct
 *     // children of this strategy
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyStrategy::HandleStrategyUpdate(const StreamIdentifier & stream, const StrategyUpdate & update)
 * {
 *     // can use such comparison if there are more than one strategy streams
 *     if (stream == m_stream.GetIdentifier()) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT StrategyStream : public Stream
{
public:
    enum StreamToEngineType
    {
        ToDefaultEngine = 0,
        ToStrategyEngine = 1,
        ToLimitEngine = 2,
        ToCalculationEngine = 3,
        ToAccessoryEngine = 4,
        ToIntegrationEngine = 7,
        ToFlowEngine = 8,
        ToMatchingEngine = 9,
        ToVisualizationEngine = 10,
        ToDistributionEngine = 11
    };

public:
    class IHandler;
    typedef StreamOptions<StrategyFilter, StrategyParametersThrottle> Options;

    class Fields
    {
    public:
        class StrategyState;
        class StatusText;
        class TransactionState;
        class TransactionOperation;
    };

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    StrategyStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    StrategyStream(IHandler & handler);

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
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param coalescing                Enable coalescing of stream data
     * @param stream_type               Type of engine where stream will open
     */
    void Open(Type type, const StrategyFilter & filter, bool coalescing = true, StreamToEngineType stream_type = ToDefaultEngine);

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
     * @param stream_type               Type of engine where stream will open
     */
    void OpenAudit(Type type,
                   const StrategyFilter & filter,
                   const DateTime & from = DateTime(),
                   const DateTime & to = DateTime(),
                   StreamToEngineType stream_type = ToDefaultEngine);

    /**
     * Open a stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Stream advanced options
     * @param stream_type               Type of engine where stream will open
     */
    void Open(Type type, const Options & options, StreamToEngineType stream_type = ToDefaultEngine);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * StrategyStream::IHandler class provides a callback interface to handle
 * strategy stream events.
 *
 * @see StrategyStream
 */
class STRATEGY_EXPORT StrategyStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Strategy stream update handler.
     *
     * Method is called when a new strategy update becomes available on the
     * stream.
     *
     * @param stream                   Stream where an update occured
     * @param update                   Strategy update object, represents a
     *                                 set of updated strategy fields
     */
    virtual void HandleStrategyUpdate(const StreamIdentifier & stream, const StrategyUpdate & update) = 0;

    /**
     * Strategy stream invalidation handler.
     *
     * Called when an item previously seen on the stream stops to match
     * stream filter, to signal that no strategy updates for this strategy
     * instance will be available on the stream from now on, unless the
     * instance changes.
     *
     * For instance, if stream was open with a filter for all *running*
     * strategies and a strategy instance that previously matched the
     * filter becomes paused, HandleStrategyInvalidate() will be called
     * for such instance. However, if the instance becomes running again,
     * it will appear on the stream without further notice.
     *
     * @param stream                   Stream where invalidation occured
     * @param id                       Identifier of invalidated strategy
     *                                 instance
     */
    virtual void HandleStrategyInvalidate(const StreamIdentifier & stream, const StrategyIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};

class STRATEGY_EXPORT StrategyStream::Fields::StrategyState : public Field
{
public:
    StrategyState();
};

class STRATEGY_EXPORT StrategyStream::Fields::StatusText : public Field
{
public:
    StatusText();
};

class STRATEGY_EXPORT StrategyStream::Fields::TransactionState : public Field
{
public:
    TransactionState();
};

class STRATEGY_EXPORT StrategyStream::Fields::TransactionOperation : public Field
{
public:
    TransactionOperation();
};
}

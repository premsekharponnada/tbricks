#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyType stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/Stream.h"
#include "strategy/StrategyType.h"

namespace tbricks {

class StrategyTypeUpdate;

/**
 * StrategyType::Stream class is an interface to receive snapshots and/or live
 * strategy type updates.
 *
 * StrategyType::Stream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last InstrumentStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private StrategyType::Stream::IHandler
 * {
 *     ...
 *
 * private:
 *     StrategyType::Stream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     StrategyType::Stream::Filters::DeletedFilter filter(false);
 *
 *     // receive all historical and live data for all strategy type originated
 *     // from this strategy and all its descendants
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyStrategy::HandleStrategyType(
 *          const Stream & stream, const StrategyTypeUpdate & update)
 * {
 *     // can use such comparison if there are more than one strategy type streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT StrategyType::Stream : public tbricks::Stream
{
public:
    class IHandler;
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByIdentifierFilter;
        class ByClassFilter;
        class DeletedFilter;
    };

public:
    Stream();
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
     */
    void Open(Type type);

    /**
     * Open a stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter;
     */
    void Open(Type type, const StrategyType::Stream::Filters::Filter & filter);

protected:
    std::ostream & Print(std::ostream & strm) const override;
};

/**
 * StrategyType::Stream::IHandler class provides a callback interface to handle
 * strategy type stream events.
 *
 * @see InstrumentStream
 */
class STRATEGY_EXPORT StrategyType::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Strategy type stream update handler.
     *
     * Method is called when a new strategy type update becomes available on the
     * stream; provided strategy type object is guaranteed to be in resolved
     * state.
     *
     * @param stream                   Stream update was generated for
     * @param update                   Update data
     */
    virtual void HandleStrategyType(const StreamIdentifier & stream_id, const StrategyType::Update & update) = 0;

    /**
     * Strategy type stream invalidation handler.
     *
     * Called when an item previously seen on the stream stops to match
     * stream filter, to signal that no strategy updates for this strategy
     * instance will be available on the stream from now on, unless the
     * instance changes.
     *
     *
     * @param stream                   Stream where invalidation occured
     * @param id                       Identifier of invalidated strategy type
     */
    virtual void HandleStrategyTypeInvalidate(const StreamIdentifier & stream_id, const StrategyIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};
}

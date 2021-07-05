#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Algo label component stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/Stream.h"
#include "strategy/AlgoLabel.h"

namespace tbricks {

/**
 * AlgoLabel::Stream class is an interface to receive snapshots and/or live
 * algo label components.
 *
 * AlgoLabel::Stream is a reference to the internal stream object managed by
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
 *                    private AlgoLabel::Stream::IHandler
 * {
 *     ...
 *
 * private:
 *     AlgoLabel::Stream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     AlgoLabel::Stream::Filters::DeletedFilter filter(false);
 *
 *     // receive snaphow and  live data for all non-deleted algo label component
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyStrategy::HandleAlgoLabel(
 *          const Stream & stream, const AlgoLabel & component)
 * {
 *     // can use such comparison if there are more than one algo label component streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT AlgoLabel::Stream : public tbricks::Stream
{
public:
    class IHandler;
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByIdentifierFilter;
        class ByStrategyDefinitionFilter;
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
     * @param filter                    Stream event filter;
     */
    void Open(Type type, const Filters::Filter & filter);

    /**
     * Open a stream to German HFT legacy algo labeling database
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     */
    void OpenGermanHFT();

    /**
     * Open an audit stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter
     * @param from                      Initial point of time
     * @param to                        Point of time to which the updates will
     *                                  be collected
     */
    void OpenAudit(Type type, const Filters::Filter & filter, const DateTime & from = DateTime(), const DateTime & to = DateTime());

protected:
    std::ostream & Print(std::ostream & strm) const override;
};

/**
 * AlgoLabel::Stream::IHandler class provides a callback interface to handle
 * algo label component stream events.
 *
 * @see InstrumentStream
 */
class STRATEGY_EXPORT AlgoLabel::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Algo label component stream update handler.
     *
     * Method is called when a new algo label component update  becomes available on the
     * stream; provided algo label component  object is guaranteed to be in resolved
     * state.
     *
     * @param stream                   Stream update was generated for
     * @param component                Algo label component
     */
    virtual void HandleAlgoLabel(const StreamIdentifier & stream_id, const AlgoLabel & component) = 0;

    /**
     * Algo label component stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits the filtering criteria.
     *
     * Fox example, a subscription is made for deleted AlgoLabel and all the
     * deleted AlgoLabels are received. If any such AlgoLabel is now set to un-deleted,
     * invalidate method will be called to indicate that this AlgoLabel no longer belongs
     * to subscription request.
     *
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated algo label component
     */
    virtual void HandleAlgoLabelInvalidate(const StreamIdentifier & stream_id, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};
}

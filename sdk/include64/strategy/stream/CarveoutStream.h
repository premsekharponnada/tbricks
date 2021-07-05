#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Carveout stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/Stream.h"
#include "strategy/Carveout.h"

namespace tbricks {

class CarveoutUpdate;

/**
 * Carveout::Stream class is an interface to receive snapshots and/or live
 * carveout updates.
 *
 * Carveout::Stream is a reference to the internal stream object managed by
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
 *                    private Carveout::Stream::IHandler
 * {
 *     ...
 *
 * private:
 *     Carveout::Stream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     Carveout::Stream::Filters::DeletedFilter filter(false);
 *
 *     // receive all historical and live data for all carveout originated
 *     // from this strategy and all its descendants
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyStrategy::HandleCarveout(
 *          const Stream & stream, const CarveoutUpdate & update)
 * {
 *     // can use such comparison if there are more than one carveout streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT Carveout::Stream : public tbricks::Stream
{
public:
    class IHandler;
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByCarveoutIdentifierFilter;
        class ByParentStrategyFilter;
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
    void Open(Type type, const Carveout::Stream::Filters::Filter & filter);

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
    void OpenAudit(Type type, const Carveout::Stream::Filters::Filter & filter, const DateTime & from = DateTime(), const DateTime & to = DateTime());

protected:
    std::ostream & Print(std::ostream & strm) const override;
};

/**
 * Carveout::Stream::IHandler class provides a callback interface to handle
 * carveout stream events.
 *
 * @see InstrumentStream
 */
class STRATEGY_EXPORT Carveout::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Carveout stream update handler.
     *
     * Method is called when a new carveout update becomes available on the
     * stream; provided carveout object is guaranteed to be in resolved
     * state.
     *
     * @param stream                   Stream update was generated for
     * @param update                   Update data
     */
    virtual void HandleCarveout(const StreamIdentifier & stream_id, const Carveout::Update & update) = 0;

    /**
     * Carveout stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits the filtering criteria.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated carveout
     */
    virtual void HandleCarveoutInvalidate(const StreamIdentifier & stream_id, const CarveoutIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};
}

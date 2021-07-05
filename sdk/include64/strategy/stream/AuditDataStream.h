#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// audit data stream.
//****************************************************************************************

#include "strategy/AuditData.h"
#include "strategy/Linkage.h"
#include "strategy/stream/StrategyStream.h"
#include "strategy/stream/Stream.h"

namespace tbricks {

/**
 * AuditData::Stream class is an interface to receive snapshots and/or live
 * audit data updates.
 *
 * AuditData::Stream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last AuditData::Stream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private AuditData::Stream::IHandler
 * {
 *     ...
 *
 * private:
 *     AuditData::Stream m_stream;
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
 * void MyStrategy::HandleStrategy(
 *          const Stream & stream, const Strategy & strategy)
 * {
 *     // can use such comparison if there are more than one audit data streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT AuditData::Stream : public tbricks::Stream
{
public:
    class IHandler;

    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByCreatedDateTime;
        class ByInstrument;
        class ByStrategyIdentifier;
    };

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
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param stream_type               Type of engine where stream will open
     */
    void Open(Type type, const Filters::Filter & filter, StrategyStream::StreamToEngineType stream_type = StrategyStream::ToDefaultEngine);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * AuditData::Stream::IHandler class provides a callback interface to handle
 * audit data stream events.
 *
 * @see AuditData::Stream
 */
class STRATEGY_EXPORT AuditData::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * audit data stream update handler.
     *
     * Method is called when a new audit data update becomes available on the
     * stream.
     *
     * @param stream                   Stream where an update occurred
     * @param update                   Update data
     */
    virtual void HandleAuditData(const StreamIdentifier & stream, const AuditData & data) = 0;

protected:
    virtual ~IHandler();
};
}

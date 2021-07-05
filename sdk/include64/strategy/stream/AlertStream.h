#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Alert stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Alert.h"

#include "strategy/stream/Stream.h"
#include "strategy/type/Field.h"
#include "strategy/stream/StrategyStream.h"

// \namespace tbricks
namespace tbricks {

/**
 * Alert::Stream class is an interface to receive snapshots and/or live
 * alert updates.
 *
 * Alert::Stream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last Alert::Stream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private Alert::Stream::IHandler
 * {
 *     ...
 *
 * private:
 *     Alert::Stream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, m_instrument);
 * }
 *
 * void MyStrategy::HandleAlert(
 *          const StreamIdentifier & stream, const Alert & alert)
 * {
 *     // can use such comparison if there are more than one alert streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT Alert::Stream : public tbricks::Stream
{
public:
    class IHandler;

    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class BySeverity;
        class ByChecked;
        class ByParameter;
        class ByCreatedDateTime;
        class ByModifiedDateTime;
        class ByStrategyType;
        class ByAlertType;
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
     * Opens a stream for a given filter and a engine type.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param engine_type               Type of engine where stream will open
     */
    void Open(Type type,
              const Filters::Filter & filter,
              StrategyStream::StreamToEngineType engine_type = StrategyStream::StreamToEngineType::ToDefaultEngine);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * Alert::Stream::IHandler class provides a callback interface to handle
 * alert stream events.
 *
 * @see Alert::Stream
 */
class STRATEGY_EXPORT Alert::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Alert stream update handler.
     *
     * Method is called when a new Alert becomes available on the stream.
     *
     * @param stream                   Stream where update has appeared
     * @param alert                    Update data
     */
    virtual void HandleAlert(const StreamIdentifier & stream, const Alert & alert) = 0;

    /**
     * Alert stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits the filtering criteria.
     *
     * Fox example, a subscription is made for non-checked alerts and all the
     * non-checked are received. If any such alert is now checked, invalidate
     * method will be called to indicate that this alert no longer belongs
     * to subscription request.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated alert
     */
    virtual void HandleAlertInvalidate(const StreamIdentifier & stream, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

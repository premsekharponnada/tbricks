#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Limit settings stream
//
//****************************************************************************

#include "strategy/stream/Stream.h"
#include "strategy/Linkage.h"
#include "strategy/LimitSettings.h"

namespace tbricks {

/**
 * LimitSettings::Stream class is an interface to receive snapshots and/or live
 * limit settings updates.
 *
 * LimitSettings::Stream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last LimitSettings::Stream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private LimitSettings::Stream::IHandler
 * {
 *     ...
 *
 * private:
 *     LimitSettings::Stream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     LimitSettings::Stream::Filters::DeletedFilter filter(false);
 *
 *     // receive all historical and live data for all algo identification originated
 *     // from this strategy and all its descendants
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyStrategy::HandleLimitSettings(
 *          const Stream & stream, const LimitSettings::Update & update)
 * {
 *     // can use such comparison if there are more than one algo identification streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT LimitSettings::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByIdentifier;
        class ByDefinition;
        class ByFilterCondition;
        class ByValue;
        class ByParameter;
        class DeletedFilter;
    };

public:
    Stream();
    Stream(IHandler & handler);

    /**
     * Set callback interface.
     *
     * Associates current stream object with a callback interface where
     * stream updates will be delivered to.
     *
     * If stream is already opened this method has no effect.
     *
     * @param handler                   Callback interface
     */
    void SetCallback(IHandler & callback);

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
    void Open(Type type, const Filters::Filter & filter);

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

public:
    std::ostream & Print(std::ostream & strm) const override;
};

/**
 * LimitSettings::Stream::IHandler class provides a callback interface to handle
 * algo identification stream events.
 *
 * @see LimitSettings
 */
class STRATEGY_EXPORT LimitSettings::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    /**
     * Limit settings stream update handler.
     *
     * Method is called when a LimitSettings update becomes available on the stream;
     * provided LimitSettings::Update object is guaranteed to be in resolved state.
     *
     * @param stream_id                Identifier of the stream the update was generated for
     * @param update                   Update data
     */
    virtual void HandleLimitSettings(const StreamIdentifier & stream_id, const LimitSettings::Update & update) = 0;

    /**
     * Limit settings invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * @param stream_id                Identifier of the stream where invalidation occurred
     * @param id                       Identifier of invalidated LimitSettings
     */
    virtual void HandleLimitSettingsInvalidate(const StreamIdentifier & stream_id, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};
}

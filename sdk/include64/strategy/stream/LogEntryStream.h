#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// LogEntry stream.
//****************************************************************************************

#include "strategy/stream/Stream.h"
#include "strategy/LogEntry.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * LogEntry::Stream class is an interface to receive snapshots
 * and/or live LogEntry updates.
 *
 */
class STRATEGY_EXPORT LogEntry::Stream : public tbricks::Stream
{
public:
    class IHandler;
    class Options;

    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByLevel;
        class ByStrategyIdentifier;
        class ByCreatedDateTime;
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
     * Parameter "definitions" allows to select what specific instrument
     * order updates the caller is interested in.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Stream Options
     */
    void Open(Type type, const Options & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * LogEntry::Stream::IHandler class is a callback interface to
 * handle LogEntry stream events.
 *
 * @see LogEntry::Stream
 */
class STRATEGY_EXPORT LogEntry::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & stream_id) {}

    /**
     * LogEntry update stream handler.
     *
     * Method is called when a new LogEntry update becomes
     * available on the stream.
     *
     * @param stream                   Stream identifier
     * @param update                   Update data
     */
    virtual void HandleLogEntry(const StreamIdentifier & stream, const LogEntry & update) = 0;

protected:
    virtual ~IHandler();
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Resource stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Resource.h"

#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/Filter.h"

// \namespace tbricks
namespace tbricks {

/**
 * ResourceStream class is an interface to receive snapshots and/or live
 * resource updates.
 *
 * ResourceStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last ResourceStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private ResourceStream::IHandler
 * {
 *     ...
 *
 * private:
 *     ResourceStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE);
 * }
 *
 * void MyStrategy::HandleResourceUpdate(
 *          const Stream & stream, const Resource & resource)
 * {
 *     // can use such comparison if there are more than one service status
 *     // streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT Resource::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    /**
     * Filters defined for Resource streams.
     */
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByMimeType;
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
     */
    void Open(Type type, const Filters::Filter & filter);

    /**
     * Requests stream data snapshot.
     *
     * Stream snapshot is available if one and only one resource matches the filter.
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    uint64_t GetSnapshot(Resource & snapshot) const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * ResourceStream::IHandler class provides a callback interface to handle
 * resource stream events.
 *
 * @see ResourceStream
 */
class STRATEGY_EXPORT Resource::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Resource stream update handler.
     *
     * Method is called when a new Resource update becomes available on the
     * stream.
     *
     * @param stream                        Stream where update has appeared
     * @param resource                      Update data
     */
    virtual void HandleResourceUpdate(const StreamIdentifier & stream, const Resource & resource) = 0;

    /**
     * Resource stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated Resource
     */
    virtual void HandleResourceInvalidate(const StreamIdentifier & stream, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};

/**
 * Base Resource filter class.
 */
class STRATEGY_EXPORT Resource::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Filter & filter);
    virtual ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const Filter & filter);
    Filter & operator&=(const Filter & filter);

    Filter operator||(const Filter & filter);
    Filter operator&&(const Filter & filter);

    Filter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

class STRATEGY_EXPORT Resource::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Resource::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    Resource::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    Resource::Stream::Filters::Filter operator||(const Filter & cond) const;
    Resource::Stream::Filters::Filter operator&&(const Filter & cond) const;
    Resource::Stream::Filters::Filter operator!() const;
    operator Resource::Stream::Filters::Filter() const;
};

/// By MIME type

class STRATEGY_EXPORT Resource::Stream::Filters::ByMimeType : public Resource::Stream::Filters::FilterCondition
{
public:
    ByMimeType(const String & mime_type);
    ByMimeType(const ByMimeType & filter);
    virtual ~ByMimeType();

    ByMimeType & operator=(const ByMimeType & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    String m_mime_type;
};

} // \namespace tbricks

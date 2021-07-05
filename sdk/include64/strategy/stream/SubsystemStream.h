#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Stream object
//
//****************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/Stream.h"

#include "strategy/Subsystem.h"

namespace tbricks {

class SubsystemIdentifier;


namespace subscription { class SmartStreamOpenRequest; }

class STRATEGY_EXPORT Subsystem::Stream : public tbricks::Stream
{
public:
    class IHandler;
    class Options;
    struct Filters
    {
        class Filter;
        class FilterCondition;
        
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
    Stream(IHandler& handler);

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
    void SetCallback(IHandler& handler);

    /**
     * Open a stream.
     *
     * Opens a stream for settings given in options.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Stream options
     */
    void Open(Type type, const Stream::Options & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * Subsystem::Stream::IHandler class provides a callback interface to handle stream events.
 * @see Subsystem::Stream
 */
class STRATEGY_EXPORT Subsystem::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

     /**
      * Stream update handler.
      *
      * Method is called when a new update becomes available on the stream.
      *
      * @param stream                   Stream where update has appeared
      * @param update                   Update data
      */
    virtual void HandleSubsystem(const StreamIdentifier & stream, const Subsystem & update) = 0;

    /**
      * Stream invalidation handler.
      *
      * Called when an item previously seen on the stream stops to match
      * stream filter, to signal that no strategy updates for this strategy
      * instance will be available on the stream from now on, unless the
      * instance changes.
      *
      * @param stream                   Stream where invalidation occured
      * @param id                       Identifier of invalidated item
      */
    virtual void HandleSubsystemInvalidate(const StreamIdentifier & stream, const SubsystemIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};

/**
 * Subsystem::Stream::Options
 * @see Subsystem::Stream
 */
class STRATEGY_EXPORT Subsystem::Stream::Options : public Printable
{
public:
    Options();
    ~Options();

        /**
     * Get filter.
     *
     * @return                          filter
     */
    Subsystem::Stream::Filters::Filter GetFilter() const;

    /**
     * %Set filter.
     *
     * @param value                     filter
     */
    void SetFilter(const Subsystem::Stream::Filters::Filter & value);
    /**
     * Get stream item ids.
     *
     * @return                          stream item ids
     */
    std::vector<SubsystemIdentifier> GetSubsystemIdentifiers() const;

    /**
     * %Set stream item ids.
     *
     * @param value                     stream item ids
     */
    void SetSubsystemIdentifiers(const std::vector<SubsystemIdentifier> & value);



    std::ostream & Print(std::ostream & strm) const override;

private:
    friend class Stream;
    const std::unique_ptr<subscription::SmartStreamOpenRequest> & get_impl_rd() const;
    std::unique_ptr<subscription::SmartStreamOpenRequest> & get_impl_wr() const;

    std::unique_ptr<subscription::SmartStreamOpenRequest> m_sor;
};

}

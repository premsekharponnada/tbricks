#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedRequestForQuote stream.
//****************************************************************************************

#include "strategy/stream/Stream.h"
#include "strategy/type/VenueIdentifier.h"
#include "strategy/directed_quoting/DirectedRequestForQuote.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * DirectedRequestForQuote::Stream class is an interface to receive snapshots
 * and/or live directed quote request updates.
 *
 */
class STRATEGY_EXPORT DirectedRequestForQuote::Stream : public tbricks::Stream
{
public:
    class IHandler;
    class Options;

    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByIdentifier;
        class Deleted;
        class ByVenueInstrumentIdentifier;
        class ByVenue;
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
     * @param venue                     Desired venue identifier, if it is empty,
     *                                  stream will be opened to all services
     */
    void Open(Type type, const Options & options, const VenueIdentifier & venue);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * DirectedRequestForQuote::Stream::IHandler class is a callback interface to
 * handle instrument parameter stream events.
 *
 * @see DirectedRequestForQuote::Stream
 */
class STRATEGY_EXPORT DirectedRequestForQuote::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & stream_id) {}

    /**
     * DirectedRequestForQuote update stream handler.
     *
     * Method is called when a new instrument order update becomes
     * available on the stream.
     *
     * @param stream                   Stream identifier
     * @param update                   Update data
     */
    virtual void HandleDirectedRequestForQuote(const StreamIdentifier & stream, const DirectedRequestForQuote & update) = 0;

    /**
     * DirectedRequestForQuote stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits the filtering criteria.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated quote
     */
    virtual void HandleDirectedRequestForQuoteInvalidate(const StreamIdentifier & stream, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};
}

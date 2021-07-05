#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Reference price stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/ReferencePrice.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/ReferencePriceFilter.h"

// \namespace tbricks
namespace tbricks {

/**
 * ReferencePriceStream class is an interface to receive snapshots and/or live
 * Reference Price updates.
 *
 * ReferencePriceStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last PortfolioStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private PortfolioStream::IHandler
 * {
 *     ...
 *
 * private:
 *     ReferencePriceStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     ReferencePriceStream filter(instrument_id);
 *
 *     // receive all historical and live data for all portfolios originated
 *     // from this strategy and all its descendants
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyStrategy::HandleReferencePrice(
 *          const Stream & stream, const ReferencePrice & price)
 * {
 *     // can use such comparison if there are more than one portfolio streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT ReferencePriceStream : public Stream
{
public:
    class IHandler;
    class Options;

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    ReferencePriceStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    ReferencePriceStream(IHandler & handler);

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
     * @param datetime                  Request recent reference price before specified datetime
     */
    void Open(Type type, const ReferencePriceFilter & filter = AnyReferencePriceFilter(), const DateTime & datetime = DateTime());

    /**
     * Open a stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Stream advanced options
     */
    void Open(Type type, const Options & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * ReferencePriceStream::IHandler class provides a callback interface to handle
 * Reference Price stream events.
 *
 * @see ReferencePriceStream
 */
class STRATEGY_EXPORT ReferencePriceStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * ReferencePrice stream update handler.
     *
     * Method is called when a new ReferencePrice update becomes available on the
     * stream.
     *
     * @param stream                   Stream update was generated for
     * @param price                    Update data
     */
    virtual void HandleReferencePrice(const StreamIdentifier & stream, const ReferencePrice::Update & price) = 0;

    /**
     * ReferencePrice stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidate ReferencePrice
     */
    virtual void HandleReferencePriceInvalidate(const StreamIdentifier & stream, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

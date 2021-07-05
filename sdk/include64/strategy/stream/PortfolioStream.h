#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Portfolio stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Portfolio.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/PortfolioFilter.h"

// \namespace tbricks
namespace tbricks {

/**
 * PortfolioStream class is an interface to receive snapshots and/or live
 * portfolio updates.
 *
 * PortfolioStream is a reference to the internal stream object managed by
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
 *     PortfolioStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     PortfolioIdentifierFilter filter(portfolio_id);
 *
 *     // receive all historical and live data for all portfolios originated
 *     // from this strategy and all its descendants
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyStrategy::HandlePortfolio(
 *          const Stream & stream, const Portfolio & portfolio)
 * {
 *     // can use such comparison if there are more than one portfolio streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT PortfolioStream : public Stream
{
public:
    class IHandler;

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    PortfolioStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    PortfolioStream(IHandler & handler);

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
     */
    void Open(Type type, const PortfolioFilter & filter = AnyPortfolioFilter());

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * PortfolioStream::IHandler class provides a callback interface to handle
 * portfolio stream events.
 *
 * @see PortfolioStream
 */
class STRATEGY_EXPORT PortfolioStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Portfolio stream update handler.
     *
     * Method is called when a new portfolio update becomes available on the
     * stream.
     *
     * @param stream                   Stream update was generated for
     * @param update                   Update data
     */
    virtual void HandlePortfolioUpdate(const StreamIdentifier & stream, const Portfolio::Update & update) = 0;

    /**
     * Position stream invalidate handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * Fox example, a subscription was made for deleted portfolio and all the
     * deleted portfolio are received. If any such portfolio is un-deleted,
     * invalidate method would be called to indicate that this portfolio no longer
     * belongs to subscription request.
     *
     * @param stream                   Stream update was generated for
     * @param id                       Position identifier
     */
    virtual void HandlePortfolioInvalidate(const StreamIdentifier & stream, const PortfolioIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

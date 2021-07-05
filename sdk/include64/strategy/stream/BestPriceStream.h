#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BestPrice stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/BestPrice.h"

#include "strategy/InstrumentVenueIdentification.h"

#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/BestPriceFilter.h"
#include "strategy/stream_throttle/BestPriceThrottle.h"
#include "strategy/stream/StreamOptions.h"

#include "strategy/type/Field.h"

namespace tbricks {

/**
 * BestPriceStream class is an interface to receive snapshots and/or live
 * best price updates.
 *
 * BestPriceStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last BestPriceStream object is destroyed.
 *
 * Note that if no callback set then Open will thrown a CallbackNotSetException.
 * If Open is not called then no update will be delivered.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private BestPriceStream::IHandler
 * {
 *     ...
 *
 * private:
 *     BestPriceStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, ivid, options);
 * }
 *
 * void MyStrategy::HandleBestPrice(const StreamIdentifier & stream, const BestPrice & price)
 * {
 *     // can use such comparison if there are more than one best price streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT BestPriceStream : public Stream
{
public:
    class IHandler;
    typedef StreamOptions<BestPriceFilter, BestPriceThrottle> Options;

    class Fields
    {
    public:
        class AskPrice;
        class BidPrice;
        class AskVolume;
        class BidVolume;
        class AskTrend;
        class BidTrend;
        class AskPriceImplied;
        class BidPriceImplied;
        class AskVolumeImplied;
        class BidVolumeImplied;
        class AskOrderCount;
        class BidOrderCount;
    };

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    BestPriceStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    BestPriceStream(IHandler & handler);

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
     * Opens a stream for a given system instrument identifier, a given
     * Instrument venue identifier and a filter, if provided.
     *
     * Note that if no callback set then Open will thrown a CallbackNotSetException.
     * If Open is not called then no update will be delivered.
     *
     * @param type                      Stream type
     * @param ivid                      Instrument venue identifier
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param coalescing                Enable coalescing of stream data
     */
    void Open(Type type, const InstrumentVenueIdentification & ivid, const BestPriceFilter & filter = AnyBestPriceFilter(), bool coalescing = true);

    /**
     * Open a stream.
     *
     * Opens a stream for a given system instrument identifier, a given
     * Instrument venue identifier and a filter, if provided.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param ivid                      Instrument venue identifier
     * @param options                   Stream advanced options
     */
    void Open(Type type, const InstrumentVenueIdentification & ivid, const Options & options);

    /**
     * Open a stream for historical data
     *
     * @param type                      Stream type
     * @param ivid                      Instrument venue identifier
     * @param granularity               Updates granularity
     * @param from                      Initial point of time
     * @param to                        Point of time to which the updates will
     *                                  be collected. If empty all live updates will come.
     */
    void OpenHistorical(Type type,
                        const InstrumentVenueIdentification & ivid,
                        const Duration & granularity,
                        const DateTime & from = DateTime(),
                        const DateTime & to = DateTime());

    /**
     * Requests stream data snapshot
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    uint64_t GetSnapshot(BestPrice & snapshot) const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * BestPriceStream::IHandler class provides a callback interface to handle
 * best price stream events.
 *
 * @see BestPriceStream
 */
class STRATEGY_EXPORT BestPriceStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Best price stream update handler.
     *
     * Method is called when a new best price update becomes available on the
     * stream.
     *
     * @param stream                   Stream where update has appeared
     * @param price                    Update data
     */
    virtual void HandleBestPrice(const StreamIdentifier & stream, const BestPrice & price) = 0;

protected:
    virtual ~IHandler();
};

class STRATEGY_EXPORT BestPriceStream::Fields::AskPrice : public Field
{
public:
    AskPrice();
};

class STRATEGY_EXPORT BestPriceStream::Fields::BidPrice : public Field
{
public:
    BidPrice();
};

class STRATEGY_EXPORT BestPriceStream::Fields::AskVolume : public Field
{
public:
    AskVolume();
};

class STRATEGY_EXPORT BestPriceStream::Fields::BidVolume : public Field
{
public:
    BidVolume();
};

class STRATEGY_EXPORT BestPriceStream::Fields::AskTrend : public Field
{
public:
    AskTrend();
};

class STRATEGY_EXPORT BestPriceStream::Fields::BidTrend : public Field
{
public:
    BidTrend();
};

class STRATEGY_EXPORT BestPriceStream::Fields::AskPriceImplied : public Field
{
public:
    AskPriceImplied();
};

class STRATEGY_EXPORT BestPriceStream::Fields::BidPriceImplied : public Field
{
public:
    BidPriceImplied();
};

class STRATEGY_EXPORT BestPriceStream::Fields::AskVolumeImplied : public Field
{
public:
    AskVolumeImplied();
};

class STRATEGY_EXPORT BestPriceStream::Fields::BidVolumeImplied : public Field
{
public:
    BidVolumeImplied();
};

class STRATEGY_EXPORT BestPriceStream::Fields::AskOrderCount : public Field
{
public:
    AskOrderCount();
};

class STRATEGY_EXPORT BestPriceStream::Fields::BidOrderCount : public Field
{
public:
    BidOrderCount();
};
}

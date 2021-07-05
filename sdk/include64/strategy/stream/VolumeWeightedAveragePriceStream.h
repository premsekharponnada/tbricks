#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Volume-Weighted Average Price stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/BestPrice.h"
#include "strategy/VWAPPrice.h"

#include "strategy/InstrumentVenueIdentification.h"

#include "strategy/stream/Stream.h"
#include "strategy/stream/BestPriceStream.h"
#include "strategy/stream_filter/BestPriceFilter.h"
#include "strategy/stream_throttle/BestPriceThrottle.h"
#include "strategy/stream/StreamOptions.h"

// \namespace tbricks
namespace tbricks {

/**
 * VolumeWeightedAveragePriceStream class is an interface to receive snapshots and/or live
 * volume weighted average price updates.
 *
 * VolumeWeightedAveragePriceStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last VolumeWeightedAveragePriceStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Also note that you need set volume by SetVolume() method before open stream.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private VolumeWeightedAveragePriceStream::IHandler
 * {
 *     ...
 *
 * private:
 *     VolumeWeightedAveragePriceStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     m_stream.SetAskVolume(100.0);
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, m_instrument);
 * }
 *
 * void MyStrategy::HandleVWAPPrice(
 *          const Stream & stream, const VWAPPrice & price)
 * {
 *     // can use such comparison if there are more than one VWAP price streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT VolumeWeightedAveragePriceStream : public Stream
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
        class WorstAskPrice;
        class WorstBidPrice;
    };

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    VolumeWeightedAveragePriceStream();

    /**
     * Constructor.
     *
     * Creates a instance associated with a stream callback interface.
     *
     * @param handler                   Stream callback interface
     */
    VolumeWeightedAveragePriceStream(VolumeWeightedAveragePriceStream::IHandler & handler);

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
    void SetCallback(VolumeWeightedAveragePriceStream::IHandler & handler);

    /**
     * %Set ask volume size.
     */
    void SetAskVolume(const Volume & volume);

    /**
     * %Set bid volume size.
     */
    void SetBidVolume(const Volume & volume);

    /**
     * Open a stream.
     *
     * Opens a stream for a given system instrument identifier, a given
     * venue instrument identifier and a filter, if provided.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param ivid                      Venue instrument identifier
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
     * venue instrument identifier and a filter, if provided.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param ivid                      Venue instrument identifier
     * @param options                   Stream advanced options
     */
    void Open(Type type, const InstrumentVenueIdentification & ivid, const Options & options);

    /**
     * Requests stream data snapshot
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    uint64_t GetSnapshot(VWAPPrice & snapshot) const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Volume m_ask_volume;
    Volume m_bid_volume;
};

class STRATEGY_EXPORT VolumeWeightedAveragePriceStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * VWAP price stream update handler.
     *
     * Method is called when a new VWAP price update becomes available on the
     * stream.
     *
     * @param stream                   Stream where update has appeared
     * @param price                    VWAP price
     */
    virtual void HandleVWAPPrice(const StreamIdentifier & stream, const VWAPPrice & price) = 0;

protected:
    virtual ~IHandler();
};

class STRATEGY_EXPORT VolumeWeightedAveragePriceStream::Fields::AskPrice : public Field
{
public:
    AskPrice();
};

class STRATEGY_EXPORT VolumeWeightedAveragePriceStream::Fields::BidPrice : public Field
{
public:
    BidPrice();
};

class STRATEGY_EXPORT VolumeWeightedAveragePriceStream::Fields::AskVolume : public Field
{
public:
    AskVolume();
};

class STRATEGY_EXPORT VolumeWeightedAveragePriceStream::Fields::BidVolume : public Field
{
public:
    BidVolume();
};

class STRATEGY_EXPORT VolumeWeightedAveragePriceStream::Fields::AskTrend : public Field
{
public:
    AskTrend();
};

class STRATEGY_EXPORT VolumeWeightedAveragePriceStream::Fields::BidTrend : public Field
{
public:
    BidTrend();
};

class STRATEGY_EXPORT VolumeWeightedAveragePriceStream::Fields::WorstAskPrice : public Field
{
public:
    WorstAskPrice();
};

class STRATEGY_EXPORT VolumeWeightedAveragePriceStream::Fields::WorstBidPrice : public Field
{
public:
    WorstBidPrice();
};

} // \namespace tbricks

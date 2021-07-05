#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Statistics stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Statistics.h"

#include "strategy/InstrumentVenueIdentification.h"

#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/StatisticsFilter.h"
#include "strategy/stream_throttle/StatisticsThrottle.h"
#include "strategy/stream/StreamOptions.h"
#include "strategy/type/Field.h"

namespace tbricks {

/**
 * StatisticsStream class is an interface to receive snapshots and/or live
 * statistics updates.
 *
 * StatisticsStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last StatisticsStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private StatisticsStream::IHandler
 * {
 *     ...
 *
 * private:
 *     StatisticsStream m_stream;
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
 * void MyStrategy::HandleStatistics(
 *          const Stream & stream, const Statistics & statistics)
 * {
 *     // can use such comparison if there are more than one statistics streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT StatisticsStream : public Stream
{
public:
    class IHandler;
    typedef StreamOptions<StatisticsFilter, StatisticsThrottle> Options;

    class Fields
    {
    public:
        class ClosingPrice;
        class DailySettlementPrice;
        class HighPrice;
        class IndicativeAuctionPrice;
        class IndicativeAuctionSurplusDirection;
        class IndicativeAuctionSurplusVolume;
        class IndicativeAuctionVolume;
        class LastAuctionPrice;
        class LastAuctionVolume;
        class LastPrice;
        class LastPriceOffMarket;
        class LastTrend;
        class LastVolume;
        class LastVolumeOffMarket;
        class LowPrice;
        class OpenInterest;
        class OpeningPrice;
        class PreviousClosingPrice;
        class PreviousSettlementPrice;
        class Turnover;
        class TurnoverOffMarket;
        class TurnoverVolume;
        class TurnoverVolumeOffMarket;
        class MinimumShortSellPrice;
    };

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    StatisticsStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    StatisticsStream(IHandler & handler);

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
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param instrument                System instrument identifier
     * @param ivid                      Instrument venue identifier
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param coalescing                Enable coalescing of stream data
     */
    void Open(Type type, const InstrumentVenueIdentification & ivid, const StatisticsFilter & filter = AnyStatisticsFilter(), bool coalescing = true);

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
     * Requests stream data snapshot
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    uint64_t GetSnapshot(Statistics & snapshot) const;

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

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * StatisticsStream::IHandler class provides a callback interface to handle
 * statistics stream events.
 *
 * @see StatisticsStream::IHandler
 */
class STRATEGY_EXPORT StatisticsStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Statistics stream update handler.
     *
     * Method is called when a new statistics update becomes available on the
     * stream.
     *
     * @param stream                   Stream where an update occured
     * @param statistics               Update data
     */
    virtual void HandleStatistics(const StreamIdentifier & stream, const Statistics & statistics) = 0;

protected:
    virtual ~IHandler();
};

class STRATEGY_EXPORT StatisticsStream::Fields::ClosingPrice : public Field
{
public:
    ClosingPrice();
};

class STRATEGY_EXPORT StatisticsStream::Fields::DailySettlementPrice : public Field
{
public:
    DailySettlementPrice();
};

class STRATEGY_EXPORT StatisticsStream::Fields::HighPrice : public Field
{
public:
    HighPrice();
};

class STRATEGY_EXPORT StatisticsStream::Fields::IndicativeAuctionPrice : public Field
{
public:
    IndicativeAuctionPrice();
};

class STRATEGY_EXPORT StatisticsStream::Fields::IndicativeAuctionSurplusDirection : public Field
{
public:
    IndicativeAuctionSurplusDirection();
};

class STRATEGY_EXPORT StatisticsStream::Fields::IndicativeAuctionSurplusVolume : public Field
{
public:
    IndicativeAuctionSurplusVolume();
};

class STRATEGY_EXPORT StatisticsStream::Fields::IndicativeAuctionVolume : public Field
{
public:
    IndicativeAuctionVolume();
};

class STRATEGY_EXPORT StatisticsStream::Fields::LastAuctionPrice : public Field
{
public:
    LastAuctionPrice();
};

class STRATEGY_EXPORT StatisticsStream::Fields::LastAuctionVolume : public Field
{
public:
    LastAuctionVolume();
};

class STRATEGY_EXPORT StatisticsStream::Fields::LastPrice : public Field
{
public:
    LastPrice();
};

class STRATEGY_EXPORT StatisticsStream::Fields::LastPriceOffMarket : public Field
{
public:
    LastPriceOffMarket();
};

class STRATEGY_EXPORT StatisticsStream::Fields::LastTrend : public Field
{
public:
    LastTrend();
};

class STRATEGY_EXPORT StatisticsStream::Fields::LastVolume : public Field
{
public:
    LastVolume();
};

class STRATEGY_EXPORT StatisticsStream::Fields::LastVolumeOffMarket : public Field
{
public:
    LastVolumeOffMarket();
};

class STRATEGY_EXPORT StatisticsStream::Fields::LowPrice : public Field
{
public:
    LowPrice();
};

class STRATEGY_EXPORT StatisticsStream::Fields::OpenInterest : public Field
{
public:
    OpenInterest();
};

class STRATEGY_EXPORT StatisticsStream::Fields::OpeningPrice : public Field
{
public:
    OpeningPrice();
};

class STRATEGY_EXPORT StatisticsStream::Fields::PreviousClosingPrice : public Field
{
public:
    PreviousClosingPrice();
};

class STRATEGY_EXPORT StatisticsStream::Fields::PreviousSettlementPrice : public Field
{
public:
    PreviousSettlementPrice();
};

class STRATEGY_EXPORT StatisticsStream::Fields::Turnover : public Field
{
public:
    Turnover();
};

class STRATEGY_EXPORT StatisticsStream::Fields::TurnoverOffMarket : public Field
{
public:
    TurnoverOffMarket();
};

class STRATEGY_EXPORT StatisticsStream::Fields::TurnoverVolume : public Field
{
public:
    TurnoverVolume();
};

class STRATEGY_EXPORT StatisticsStream::Fields::TurnoverVolumeOffMarket : public Field
{
public:
    TurnoverVolumeOffMarket();
};

class STRATEGY_EXPORT StatisticsStream::Fields::MinimumShortSellPrice : public Field
{
public:
    MinimumShortSellPrice();
};
}

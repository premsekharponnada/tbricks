#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Abstract stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Integer.h"
#include "strategy/type/StreamIdentifier.h"

#include <memory>

namespace tbricks {

namespace pe {
class StreamImpl;
}

class StrategyStreamImpl;
class StrategyBatchImpl;
class FieldFilter;

/**
 * Data Stream, provides snapshot on selected data types, live data updates or
 * both.
 *
 * SNAPSHOT streams provide historical data only. No live data is available in
 * this kind of streams. Callback order for such streams is: None, one or more
 * (depending on number of available data) data update callbacks is called.
 * When all data is received, HandleSnapshotEnd() is called followed by
 * HandleStreamFailed() callback. If stream is prematurely closed by the other
 * side, HandleStreamFailed() will be called, and if snapshot was not fully
 * received by this point a strategy will never receive HandleSnapshotEnd()
 * event.
 *
 * SNAPSHOT_AND_LIVE streams provide both historical and live data,
 * historical data comes first and live data follows. Call sequence is,
 * therefore, none, one or more data update callbacks for historical data
 * (possibly interposed with live data updates) followed by HandleSnapshotEnd()
 * and then followed by none, one or more data update callbacks for live
 * data. If live update becomes available in the middle of the snapshot, two
 * different cases are possible -- if an item had been already sent and live
 * update is available for the item, live update is sent to the stream;
 * however, if the item had not been sent yet, live update is silently merged
 * to the item, and an updated item will eventually appear on the stream.
 * If the other side closes the stream, HandleStreamFailed() is received,
 * and this event may appear even earlier than HandleSnapshotEnd() or any
 * historical data.
 *
 * If strategy closes the stream by means of Stream::Close() method, it is
 * guaranteed to receive no more updates for this stream, and
 * HandleStreamFailed() event is not delivered in this case.
 *
 * It is also guaranteed that no stream updates are sent after
 * HandleStreamFailed() event is delivered.
 */
class STRATEGY_EXPORT Stream : public Printable
{
public:
    class IHandler;

public:
    enum Type
    {
        SNAPSHOT = 1,         /**< Historical data stream                 */
        SNAPSHOT_AND_LIVE = 3 /**< Combined live + historical data stream */
    };

    enum class StaleReason
    {
        NONE = 0,
        SERVICE_DISCONNECTED = 1, /**< service is diconnected                        */
        NO_RBAC_PERMISSION = 2,   /**< absense of RBAC permission                    */
        NOT_ENTITLED = 3          /**< absense of entitlement for app owner          */
    };

public:
    virtual ~Stream();

    /**
     * Close data stream.
     *
     * Guaranteed that no updates are sent after this call, not even
     * HandleStreamFailed() event.
     *
     * If stream was not opened, the call does nothing.
     */
    virtual void Close();

    /**
     * Check if stream is open.
     *
     *
     * @return                          "true" if stream is open, "false"
     *                                  otherwise
     */
    virtual bool IsOpen() const;

    /**
     * Check if snapshot is already received.
     *
     *
     * @return                          "true" if snapshot is received, "false"
     *                                  if snapshot is still in progress
     */
    virtual bool IsSnapshotDone() const;

    /**
     * Check if stream is staled.
     *
     * @return                          "true" if stream is staled, "false" if
     *                                  stream is still valid
     */
    virtual bool IsStale() const;

    /**
     * Get unique stream identifier.
     *
     * Each open stream is tagged with an identifier that is guaranteed to be
     * unique among all open streams. If called for closed stream, an empty
     * identifier is returned.
     *
     *
     * @return                          stream unique identifier
     *
     */
    const StreamIdentifier & GetIdentifier() const;

    /**
     * Get stream type.
     *
     *
     * @return                          stream snapshot type, snapshot or snapshot_and_live
     */
    Type GetType() const;

    /**
     * Get number of stream updates.
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     */
    uint64_t GetUpdateCounter() const;

    /**
     * Clear callback inerface handler.
     *
     * App could call it if doesn't want to receive updates anymore.
     */
    void ClearCallback();

    /**
     * "snapshot done" flag will be reset if stream becomes staled.
     * It means HandleSnapshotEnd() will be called each time after successful reconnection
     * and snapshot receiving.
     */
    void ResetSnapshotDoneAfterReconnect();

    /**
     * %Set subscribed fields.
     *
     * Specifies the set of fields to watch for updates.
     * NOTE: method must be called for closed stream, otherwise it will have no effect.
     *
     * @param filter       Filter with the set of fields to watch for.
     *
     * @code
     * // Subscribe only price updates for BestPriceStream
     * BestPriceStream m_bp_stream();
     * m_bp_stream.SetSubscribedFields(BestPriceStream::Fields::AskPrice() ||
     *     BestPriceStream::Fields::BidPrice());
     * @endcode
     */
    void SetSubscribedFields(const FieldFilter & filter);

    /**
     * %Set stream priority.
     *
     * Stream priority introduces precedence over stream events. Events
     * from streams of higher priority are generally delivered before the
     * events with a lower priority.
     *
     * Stream priority can be changed at any time, and if stream is open
     * this setting takes immediate effect.
     *
     * Stream priority is an interger value in a range of [0..100] where
     * '0' is the lowest priority possible and '100' is the highest one.
     * Default priority value is 50.
     *
     * If argument does not fall into the range, it is automatically
     * converted to the closest valid value (-100 will become zero,
     * 3000 will be reduced to 100).
     *
     * @param priority                   Stream priority value
     */
    void SetPriority(const Integer & priority);

    /**
     * %Set maximum amount of updates in snapshot.
     *
     * @param limit                     Maximum amount of updates
     */
    void SetSnapshotLimit(const Integer & limit);

    /**
     * Get stream priority.
     *
     * @see SetPriority
     *
     * @return                          Current stream priority
     */
    Integer GetPriority() const;

    /**
     * %Set warmup option.
     *
     * Method allows to set warmup option to receive updates for warmup objects as well
     *
     * @param warmup                    Warmup option
     */
    void SetWarmup(bool warmup);

    /**
     * Get warmup option.
     *
     * Method provides read-only access to warmup option.
     *
     * @return                          Warmup option
     */
    bool GetWarmup() const;

    /**
     * Get stale reason.
     *
     * @return                          Stale reason
     */
    StaleReason GetStaleReason() const;

    /**
     * Get description of stale reason for e.g. alert/logs output.
     *
     * @return                          Description of stale reason
     */
    String GetStaleReasonDescription() const;

    /**
     * Set waiting duration for GetSnapshot() calls
     *
     * @param duration                  Timeout for GetSnapshot() calls,
     *                                  if specified, GetSnapshot() would wait for
     *                                  snapshot or timeout.
     *                                  Default duration is zero
     */
    void SetSnapshotWaitingDuration(const Duration & duration);

    /**
     * Comparison operator.
     *
     * Two closed streams are equal, open stream is not equal to closed one,
     * otherwise streams are equal if they refer to the same physical data stream.
     *
     * @return                          "true" if streams are equal, "false"
     *                                  otherwise
     */
    bool operator==(const Stream & stream) const;

    /**
     * Comparison operator.
     *
     * Two closed streams are equal, open stream is not equal to closed one,
     * otherwise streams are equal if they refer to the same physical data stream.
     *
     * @return                          "true" if streams are equal, "false"
     *                                  otherwise
     */
    bool operator==(const StreamIdentifier & stream_id) const;

    /**
     * Comparison operator.
     *
     *
     * Two closed streams are equal, open stream is not equal to closed one,
     * otherwise streams are equal if they refer to the same physical data stream.
     *
     * @return                          "true" if streams are not equal, "false"
     *                                  otherwise
     */
    bool operator!=(const Stream & stream) const;

    /**
     * Comparison operator.
     *
     *
     * Two closed streams are equal, open stream is not equal to closed one,
     * otherwise streams are equal if they refer to the same physical data stream.
     *
     * @return                          "true" if streams are not equal, "false"
     *                                  otherwise
     */
    bool operator!=(const StreamIdentifier & stream_id) const;

protected:
    friend class StreamBatch;

    Stream();
    Stream(pe::StreamImpl * stream_impl);
    Stream(const Stream & stream);
    Stream & operator=(const Stream & stream);

    friend class OrderBookItem;
    friend class MarketDataItem;
    pe::StreamImpl * get_impl() const;
    StrategyStreamImpl * get_strategy_impl() const;

private:
    StreamIdentifier m_id;
    pe::StreamImpl * m_stream_impl;
};

/**
 * Stream::IHandler is a callback interface for common stream event types, and
 * all concrete stream handlers are derived from this one.
 *
 * All stream data and all stream control events such as stream close or end
 * of snapshot are reported to the strategy through the set of methods defined
 * by appropriate callback interface. There is one concrete callback interface
 * per each stream type, and depending on the data type the stream provides
 * the interface adds an appropriate method to those defined in Stream::IHandler.
 *
 * @see Stream
 */
class STRATEGY_EXPORT Stream::IHandler
{
public:
    /**
     * Stream open event.
     *
     * Called when the other side successfully opens the stream.
     *
     * @param stream                    Reference to event originator stream
     */
    virtual void HandleStreamOpen(const StreamIdentifier & stream) = 0;

    /**
     * Stream stale event.
     *
     * Called when the stream becomes unconsistent by any reason
     * (other side was crashed, network connection was broken, etc.)
     * Stream will be valid after HandleStreamOpen event
     *
     * @param stream                    Reference to event originator stream
     */
    virtual void HandleStreamStale(const StreamIdentifier & stream) = 0;

    /**
     * Stream close event.
     *
     * Called when the other side forcefully closes the stream. No updates
     * will be delivered for the stream provided as a parameter after this
     * event.
     *
     * @code
     * void MyStrategy::HandleStreamFailed(const Stream & stream)
     * {
     *     std::vector<tbricks::BestPrice>::iterator i;
     *     for (i = m_best_price_streams.begin();
     *          i != m_best_price_streams.end(); ++i) {
     *          if (*i == stream) {
     *              // this stream is closed by the other side, either
     *              // erase it or re-open.
     *              break;
     *          }
     *     }
     *
     * }
     * @endcode
     *
     * @param stream                    Reference to event originator stream
     */
    virtual void HandleStreamFailed(const StreamIdentifier & stream) = 0;

    /**
     * Stream end of snapshot event.
     *
     * Appears only in streams of SNAPSHOT_AND_LIVE and SNAPSHOT types when
     * all historical data is received.
     *
     * @param stream                    Reference to event originator stream
     */
    virtual void HandleSnapshotEnd(const StreamIdentifier & stream) = 0;

protected:
    virtual ~IHandler();
};

/**
 * Batches callbacks from associated streams.
 * When a first event from batched stream arrives, a single callback event is posed into the app queue
 * for all subsequent events from streams in the same batch.
 * While app has not started processing this event, all coalescing is performed on that event.
 * When app is scheduled to handle that batch event, first HandleBatchStart() is called,
 * then all callbacks from batched events, then HandleBatchEnd().
 */
class STRATEGY_EXPORT StreamBatch
{
public:
    class IHandler;

    /**
     * Constructor.
     *
     * @param handler                   Batch callback interface
     */
    StreamBatch(IHandler & handler);

    /**
     * Adds stream to a batch. Updates from this stream will trigger batch start unless it's already started.
     */
    void AddStream(const Stream & stream);

    /**
     * Removes all streams associated with a batch.
     */
    /// @deprecated Deprecated in 2.14.5 use 'Close()' instead.
    [[deprecated(DEPRECATE_LINK)]] void Clear();

    /**
     * Close all streams and remove them from the batch
     */
    void Close();

    /**
     * Indicates whether app is currently processing this batch.
     */
    bool IsProcessing() const;

private:
    std::shared_ptr<StrategyBatchImpl> m_batch_impl;
};

class STRATEGY_EXPORT StreamBatch::IHandler
{
public:
    /**
     * Called right before performing calls on strategy instance for events in batch.
     * At this point all updates to the affected streams are not merged into the batch anymore.
     * After this call appropriate callback handlers on app are invoked for all events in the batch.
     */
    virtual void HandleBatchStart(StreamBatch & batch) = 0;

    /**
     * Called after last event from batch was delivered to an app.
     */
    virtual void HandleBatchEnd(StreamBatch & batch) = 0;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStatus stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/InstrumentStatus.h"

#include "strategy/type/Venue.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/InstrumentVenueIdentification.h"

#include "strategy/stream/Stream.h"
#include "strategy/stream/InstrumentStream.h"

#include "strategy/type/Field.h"

// \namespace tbricks
namespace tbricks {

/**
 * InstrumentStatusStream class is an interface to receive snapshots and/or live
 * instrument status updates.
 *
 * InstrumentStatusStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last InstrumentStatusStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private InstrumentStatusStream::IHandler
 * {
 *     ...
 *
 * private:
 *     InstrumentStatusStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     InstrumentFilter filter();
 *
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyStrategy::HandleInstrumentStatus(
 *          const Stream & stream, const InstrumentStatus & status)
 * {
 *     // can use such comparison if there are more than one instrument streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT InstrumentStatusStream : public Stream
{
public:
    class IHandler;

    class Fields
    {
    public:
        class InstrumentMarketDataStatus;
        class InstrumentTradingPhase;
        class InstrumentTradingStatus;
        class VenueInstrumentIdentifier;
        class VenueInstrumentMarketDataStatus;
        class VenueInstrumentTradingStatus;
    };

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    InstrumentStatusStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    InstrumentStatusStream(IHandler & handler);

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
     * Opens a stream for a given instrument venue identifier
     * and a filter, if provided.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param ivid                      Instrument venue identifier
     * @param coalescing                Should updates be coalesced
     */
    void Open(Type type, const InstrumentVenueIdentification & ivid, bool coalescing = false);

    /**
     * Requests stream data snapshot
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    uint64_t GetSnapshot(InstrumentStatus & snapshot) const;

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
 * InstrumentStatusStream::IHandler class provides a callback interface to handle
 * instrument status stream events.
 *
 * @see InstrumentStatusStream
 */
class STRATEGY_EXPORT InstrumentStatusStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * InstrumentStatus stream update handler.
     *
     * Method is called when a new instrument update becomes available on the
     * stream; provided instrument object is guaranteed to be in resolved
     * state.
     *
     * @param stream                   Stream update was generated for
     * @param status                   Update data
     */
    virtual void HandleInstrumentStatus(const StreamIdentifier & stream, const InstrumentStatus & status) = 0;

protected:
    virtual ~IHandler();
};

class STRATEGY_EXPORT InstrumentStatusStream::Fields::InstrumentMarketDataStatus : public Field
{
public:
    InstrumentMarketDataStatus();
};

class STRATEGY_EXPORT InstrumentStatusStream::Fields::InstrumentTradingPhase : public Field
{
public:
    InstrumentTradingPhase();
};

class STRATEGY_EXPORT InstrumentStatusStream::Fields::InstrumentTradingStatus : public Field
{
public:
    InstrumentTradingStatus();
};

class STRATEGY_EXPORT InstrumentStatusStream::Fields::VenueInstrumentIdentifier : public Field
{
public:
    VenueInstrumentIdentifier();
};

class STRATEGY_EXPORT InstrumentStatusStream::Fields::VenueInstrumentMarketDataStatus : public Field
{
public:
    VenueInstrumentMarketDataStatus();
};

class STRATEGY_EXPORT InstrumentStatusStream::Fields::VenueInstrumentTradingStatus : public Field
{
public:
    VenueInstrumentTradingStatus();
};

} // \namespace tbricks

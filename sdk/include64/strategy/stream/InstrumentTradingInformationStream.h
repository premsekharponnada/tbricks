#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentTradingInformation stream.
//
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/stream/Stream.h"
#include "strategy/InstrumentTradingInformation.h"
#include "strategy/type/LiquidityPoolIdentifier.h"

namespace tbricks {

/**
 * InstrumentTradingInformation::Stream class is an interface to receive snapshots and/or live
 * instrument trading inforamtion.
 *
 * InstrumentTradingInformation::Stream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last InstrumentTradingInformation::Stream object is destroyed.
 *
 * Note that if no callback set then Open will thrown a CallbackNotSetException.
 * If Open is not called then no update will be delivered.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private InstrumentTradingInformation::Stream::IHandler
 * {
 *     ...
 *
 * private:
 *     InstrumentTradingInformation::Stream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, options);
 * }
 *
 * void MyStrategy::HandleInstrumentTradingInformation(const StreamIdentifier & stream,
 *                                                     const InstrumentTradingInformation & information)
 * {
 *     // can use such comparison if there are more than one trd streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT InstrumentTradingInformation::Stream : public tbricks::Stream
{
public:
    class Options;
    class IHandler;

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    Stream() {}

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
     * Opens a stream for a given system instrument identifier, a given
     * Instrument venue identifier and a filter, if provided.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Stream advanced options
     */
    void Open(Type type, const Options & options);

    /**
     * Requests stream data snapshot
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    uint64_t GetSnapshot(InstrumentTradingInformation & snapshot) const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * InstrumentTradingInformation::Stream::Option class, used for setting options for
 * InstrumentTradingInformation::Stream
 */
class InstrumentTradingInformation::Stream::Options
{
public:
    /**
     * %Set liquidity pool identifier
     */
    void SetLiquidityPool(const LiquidityPoolIdentifier & id) { m_liquidity_pool = id; }

    /**
     * Get liquidity pool identifier
     */
    const LiquidityPoolIdentifier & GetLiquidityPool() const { return m_liquidity_pool; }

    /**
     * %Ser instrument venue identification
     */
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & id) { m_ivid = id; }

    /**
     * Get instrument venue identification
     */
    const InstrumentVenueIdentification & GetInstrumentVenueIdentification() const { return m_ivid; }

private:
    LiquidityPoolIdentifier m_liquidity_pool;
    InstrumentVenueIdentification m_ivid;
};

/**
 * InstrumentTradingInformation::Stream::IHandler class provides a callback interface to handle
 *  stream events.
 *
 * @see InstrumentTradingInformation::Stream
 */
class STRATEGY_EXPORT InstrumentTradingInformation::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * InstrumentTradingInformation stream update handler.
     *
     * Method is called when a new best price update becomes available on the
     * stream.
     *
     * @param stream                   Stream where update has appeared
     * @param price                    Update data
     */
    virtual void HandleInstrumentTradingInformation(const StreamIdentifier & stream, const InstrumentTradingInformation & information) = 0;

protected:
    virtual ~IHandler() {}
};
}

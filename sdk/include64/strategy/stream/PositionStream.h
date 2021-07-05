#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Position stream.
//****************************************************************************************

#include <set>

#include "strategy/Linkage.h"
#include "strategy/Position.h"
#include "strategy/Strategy.h"
#include "strategy/Trade.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/PositionFilter.h"

// \namespace tbricks
namespace tbricks {

/**
 * PositionStream class is an interface to receive snapshots and/or live
 * position updates.
 *
 * PositionStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last PositionStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyStrategy : public Strategy,
 *                    private PositionStream::IHandler
 * {
 *     ...
 *
 * private:
 *     PositionStream m_stream;
 * }
 *
 * MyStrategy::MyStrategy()
 *     : m_stream(*this)
 * { }
 *
 * void MyStrategy::OpenStream()
 * {
 *     // receive all historical and live data for all positions originated
 *     // from this strategy and all its descendants
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, portfolio_id, aggregation_type);
 * }
 *
 * void MyStrategy::HandlePosition(
 *          const Stream & stream, const Position & position)
 * {
 *     // can use such comparison if there are more than one position streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT PositionStream : public Stream
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
    PositionStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    PositionStream(IHandler & handler);

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
     * %Set list of instruments for filtering on engine level.
     *
     * @ param instruments              List of instruments
     */
    void SetInstrumentsList(const std::vector<InstrumentIdentifier> & instruments);

    /**
     * Open a stream for positions by portfolio
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param portfolio_id              Portfolio identifier
     * @param aggregation_type          Position aggregation type
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param summate_positions         Summate children portfolio positions
     */
    void Open(Type type,
              const PortfolioIdentifier & portfolio_id,
              Position::AggregationType aggregation_type,
              const PositionFilter & filter = AnyPositionFilter(),
              bool summate_positions = true);

    /**
     * The same method as above, but open a stream for positions
     * from all portfolios from the portfolio_ids list.
     */
    void Open(Type type,
              const std::vector<PortfolioIdentifier> & portfolio_ids,
              Position::AggregationType aggregation_type,
              const PositionFilter & filter = AnyPositionFilter(),
              bool summate_positions = true);

    /**
     * Open a stream for positions
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param root_strategy_id          Root strategy identifier
     * @param aggregation_type          Position aggregation type
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param summate_positions         Summate children portfolio positions
     */
    void Open(Type type,
              const StrategyIdentifier & root_strategy_id,
              Position::AggregationType aggregation_type,
              const PositionFilter & filter = AnyPositionFilter(),
              bool summate_positions = true);

    /**
     * Open a stream for positions
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param options                   Options
     */
    void Open(Type type, const Options & options);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * PositionStream::IHandler class provides a callback interface to handle
 * position stream events.
 *
 * @see PositionStream
 */
class STRATEGY_EXPORT PositionStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Position stream update handler.
     *
     * Method is called when a new position update becomes available on the
     * stream.
     *
     * HandlePosition executed twice a time when trade has registered fee
     * - first position update includes initial trade
     * - second position update with encountered trade fee
     *
     * @param stream                   Stream update was generated for
     * @param position                 Update data
     */
    virtual void HandlePosition(const StreamIdentifier & stream, const Position & position) = 0;

    /**
     * Position stream invalidate handler.
     *
     * Called when all related trades were deleted from position.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * For instance, if stream was open with a filter for all *active*
     * orders and an order that previously matched the
     * filter becomes filled, HandlePositionInvalidate() will be called
     * for such instance.
     *
     * @param stream                   Stream update generated for
     * @param id                       Identifier of invalidate Position
     */
    virtual void HandlePositionInvalidate(const StreamIdentifier & stream, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};

/**
 * PositionStream::Options class provides options for PositionStream
 *
 * @see PositionStream
 */
class STRATEGY_EXPORT PositionStream::Options : public Printable
{
public:
    /**
     * Set position stream filter.
     *
     * If filter is not set all position are requested..
     *
     * @param filter                   Position filter
     */
    void SetFilter(PositionFilter filter) { m_filter = std::move(filter); }

    /**
     * Get position stream filter.
     *
     * @return                         Position filter.
     */
    const PositionFilter & GetFilter() const { return m_filter; }

    /**
     * Set keys used to aggregate trades.
     *
     * It's mandatory to specify the aggregation set, otherwise
     * EmptyValueException is thrown from PositionStream::Open().
     *
     *
     * @param aggregation_keys         Trade aggregation keys set
     */
    void SetAggregationKeys(std::set<Trade::AggregationKey> aggregation_keys) { m_aggregation_keys = std::move(aggregation_keys); }

    /**
     * Get set of trade aggregation keys.
     *
     * @return                         Trade aggregation keys set
     */
    const std::set<Trade::AggregationKey> & GetAggregationKeys() const { return m_aggregation_keys; }

    /**
     * Specify whether position should summate trades in sub-portfolios.
     *
     * Summation is enabled by default.
     *
     * @param summate_portfolios       Summate portfolios flag
     */
    void SetSummatePortfolios(bool summate_portfolios) { m_summate_portfolios = summate_portfolios; }

    /**
     * Return true if trades in sub-portfolios should be summated.
     * False otherwise.
     *
     * @return                         Summate portfolios flag
     */
    bool GetSummatePortfolios() const { return m_summate_portfolios; }

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    PositionFilter m_filter;
    std::set<Trade::AggregationKey> m_aggregation_keys;
    bool m_summate_portfolios = true;
};

} // \namespace tbricks

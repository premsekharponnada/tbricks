#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/InstrumentGroup.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/InstrumentGroupFilter.h"
#include "strategy/stream/InstrumentStreamOptions.h"
#include "strategy/stream_throttle/InstrumentThrottle.h"

namespace tbricks {

/**
 * InstrumentGroupStream class is an interface to receive snapshots and/or live
 * instrument updates.
 *
 * InstrumentGroupStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last InstrumentGroupStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyApp : public Strategy,
 *               private InstrumentGroupStream::IHandler
 * {
 *     ...
 *
 * private:
 *     InstrumentGroupStream m_stream;
 * }
 *
 * MyApp::MyApp()
 *     : m_stream(*this)
 * { }
 *
 * void MyApp::OpenStream()
 * {
 *     InstrumentGroupByIdentifierFilter filter(GetIdentifier());
 *
 *     // receive all historical and live data for all instruments originated
 *     // from this strategy and all its descendants
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyApp::HandleInstrumentGroup(const StreamIdentifier & stream, const InstrumentGroup & group)
 * {
 *     // can use such comparison if there are more than one instrument streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT InstrumentGroupStream : public Stream
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
    InstrumentGroupStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    InstrumentGroupStream(IHandler & handler);

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
    void Open(Type type, const InstrumentGroupFilter & filter = AnyInstrumentGroupFilter());
    void Open(Type type, const Options & options);

    /**
     * Open an audit stream.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param filter                    Stream event filter; if not provided,
     *                                  all data is communicated to the
     *                                  associated callback interface
     * @param from                      Initial point of time
     * @param to                        Point of time to which the updates will
     *                                  be collected
     */
    void OpenAudit(Type type,
                   const InstrumentGroupFilter & filter = AnyInstrumentGroupFilter(),
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
    uint64_t GetSnapshot(InstrumentGroup & snapshot) const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * InstrumentGroupStream::IHandler class provides a callback interface to handle
 * instrument stream events.
 *
 * @see InstrumentGroupStream
 */
class STRATEGY_EXPORT InstrumentGroupStream::IHandler : public Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Instrument stream update handler.
     *
     * Method is called when a new instrument update becomes available on the
     * stream; provided instrument object is guaranteed to be in resolved
     * state.
     *
     * @param stream                   Stream update was generated for
     * @param group                    Update data
     */
    virtual void HandleInstrumentGroup(const StreamIdentifier & stream, const InstrumentGroup & group) = 0;

    /**
     * Instrument group stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * Fox example, a subscription was made for deleted instrument group and all the
     * deleted instrument groups are received. If any such instrument group is un-deleted,
     * invalidate method would be called to indicate that this instrument group no longer
     * belongs to subscription request.
     *
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated instrument group
     */
    virtual void HandleInstrumentGroupInvalidate(const StreamIdentifier & stream, const InstrumentGroupIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};

class STRATEGY_EXPORT InstrumentGroupStream::Options : public Printable
{
public:
    using filter_type = InstrumentGroupFilter;
    using throttle_type = InstrumentGroupThrottle;

    Options() = default;
    ~Options() = default;

    /**
     * %Set instrument group filter to subscribe to all instruments that match it
     * @param filter   instrument group filter
     */
    void SetFilter(const filter_type & filter) { m_filter = filter; }

    /**
     * Get instrument group filter
     * @return         instrument group filter
     */
    const filter_type & GetFilter() const { return m_filter; }

    /**
     * %Set instrument group to subscribe
     * If you set instrumnet groups before, the old value will be frayed
     * @param instrument   instrument group identifier
     */
    void SetInstrumentGroup(const InstrumentGroupIdentifier & group) { m_instrument_groups.assign(1, group); }

    /**
     * %Set instrument groups to subscribe
     * If you set instrumnet groups before, the old value will be frayed
     * @param instruments  instrument groups identifiers
     */
    void SetInstrumentGroups(const std::vector<InstrumentGroupIdentifier> & groups) { m_instrument_groups = groups; }

    /**
     * Add passed instrument group to the list of instrumnet groups to subscribe
     * If the number of instrument groups is not one, coalesing will not be enabled
     * @param instrument   instrument group identifier
     */
    void AddInstrumentGroup(const InstrumentGroupIdentifier & group)
    {
        if (!group.Empty()) {
            m_instrument_groups.push_back(group);
        }
    }

    /**
     * Get instrument groups to subscribe
     * @return             instrument groups identifiers
     */
    const std::vector<InstrumentGroupIdentifier> & GetInstrumentGroups() const { return m_instrument_groups; }

    // clang-format off
    /// @deprecated Deprecated in 2.14.6, use 'const std::vector<InstrumentGroupIdentifier> & GetInstrumentGroups() const' instead
    [[deprecated(DEPRECATE_LINK)]] std::vector<InstrumentGroupIdentifier> & GetInstrumentGroups() { return m_instrument_groups; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetRankingIdentifier(const Identifier & id) { m_ranking_id = id; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] const Identifier & GetRankingIdentifier() const { return m_ranking_id; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetContextIdentifier(const Identifier & id) { m_context_id = id; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] const Identifier & GetContextIdentifier() const { return m_context_id; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetUserIdentifier(const UserIdentifier & id) { m_user_id = id; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetUserIdentifier(const User & user) { m_user_id = user.GetIdentifier(); }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] const UserIdentifier & GetUserIdentifier() const { return m_user_id; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetPortfolioIdentifier(const PortfolioIdentifier & id) { m_portfolio_id = id; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] const PortfolioIdentifier & GetPortfolioIdentifier() const { return m_portfolio_id; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetSnapshotDateTime(const DateTime & date_time) { m_snapshot_datetime = date_time; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] const DateTime & GetSnapshotDateTime() const { return m_snapshot_datetime; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] filter_type & GetFilter() { return m_filter; }

    /// @deprecated Deprecated in 2.14.6, set automatically if it is possible
    [[deprecated(DEPRECATE_LINK)]] void SetCoalescing(bool coalescing) { m_coalescing = coalescing; }

    /// @deprecated Deprecated in 2.14.6, set automatically if it is possible
    /// true if the filter is empty and one instrument group is set
    [[deprecated(DEPRECATE_LINK)]] bool GetCoalescing() const { return m_coalescing; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetThrottle(const throttle_type & throttle) { m_throttle = throttle; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] const throttle_type & GetThrottle() const { return m_throttle; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] throttle_type & GetThrottle() { return m_throttle; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetInstrument(const InstrumentIdentifier & instrument) { m_instruments.assign(1, instrument); }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetInstruments(const std::vector<InstrumentIdentifier> & instruments) { m_instruments = instruments; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void AddInstrument(const InstrumentIdentifier & instrument) { if (!instrument.Empty()) { m_instruments.push_back(instrument); } }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] const std::vector<InstrumentIdentifier> & GetInstruments() const { return m_instruments; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] std::vector<InstrumentIdentifier> & GetInstruments() { return m_instruments; }
    // clang-format on

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    filter_type m_filter;
    throttle_type m_throttle;
    std::vector<InstrumentIdentifier> m_instruments;
    std::vector<InstrumentGroupIdentifier> m_instrument_groups;
    Identifier m_ranking_id;
    Identifier m_context_id;
    UserIdentifier m_user_id;
    PortfolioIdentifier m_portfolio_id;
    DateTime m_snapshot_datetime;
    bool m_coalescing;
};
}

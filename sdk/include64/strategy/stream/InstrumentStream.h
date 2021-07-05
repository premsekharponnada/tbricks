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
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream/InstrumentStreamOptions.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/stream_throttle/InstrumentThrottle.h"

namespace tbricks {

class Instrument;

/**
 * InstrumentStream class is an interface to receive snapshots and/or live
 * instrument updates.
 *
 * InstrumentStream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last InstrumentStream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 *
 * Possible use:
 * @code
 * class MyApp : public Strategy,
 *               private InstrumentStream::IHandler
 * {
 *     ...
 *
 * private:
 *     InstrumentStream m_stream;
 * }
 *
 * MyApp::MyApp()
 *     : m_stream(*this)
 * { }
 *
 * void MyApp::OpenStream()
 * {
 *     InstrumentByAncestorFilter filter(GetIdentifier());
 *
 *     // receive all historical and live data for all instruments originated
 *     // from this strategy and all its descendants
 *     m_stream.Open(Stream::SNAPSHOT_AND_LIVE, filter);
 * }
 *
 * void MyApp::HandleInstrument(const StreamIdentifier & stream, const Instrument & instrument)
 * {
 *     // can use such comparison if there are more than one instrument streams
 *     if (stream == m_stream) {
 *         // handle update
 *         ...
 *     }
 * }
 * @endcode
 */
class STRATEGY_EXPORT InstrumentStream : public Stream
{
public:
    class IHandler;
    class Options;

    class Filters
    {
    public:
        class Filter;
        class FilterCondition;

        class ByAttributesFilter;
        class ByCreatedDateTimeFilter;
        class ByCurrencyFilter;
        class ByVenueInstrumentIdentifierFilter;
        class ByFlatParameterFilter;
        class ByGroupFilter;
        class ByModifiedDateTimeFilter;
        class ByParameterFilter;
        class BySymbologyKeyFilter;
        class ByVenueFilter;
        class DeletedFilter;
        class HasFlatParameterFilter;
        class HasParameterFilter;
        class TemporaryFilter;
        class HasComponentsFilter;
        class ByInstrumentAttributeFilter;
        class ByInstrumentHasAttributeFilter;
        class ByPriceStructure;
        class ShortNameContainsFilter;
    };

public:
    /**
     * Default constructor.
     *
     * Creates an instance not associated with a callback interface, and as
     * result Open() method will not have any effect to the instance unless
     * SetCallback() is applied before.
     */
    InstrumentStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param handler                   Stream callback interface
     */
    InstrumentStream(IHandler & handler);

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
     * @param filter                    Stream event filter;
     */
    void Open(Type type, const InstrumentStream::Filters::Filter & filter);

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
    void OpenAudit(Type type, const InstrumentStream::Filters::Filter & filter, const DateTime & from = DateTime(), const DateTime & to = DateTime());
    void OpenAudit(Type type, const Options & options, const DateTime & from = DateTime(), const DateTime & to = DateTime());

    /**
     * This option enable force stream collapsing on engine level. If it
     * was enabled, all snapshot for stream will be kept in engine and used
     * for identical stream. It can lead to significantly decreasing of load
     * for Instrument Service for some cases.
     *
     * \note
     * ATTENTION! THIS OPTION ONLY FOR TBRICKS INTERNAL USAGE!
     *
     * \warning
     * This option also could lead to bad performance and high memory consumption
     * in your system! Please don't use this option or contact Tbricks support
     * for addition information before use it.
     */
    void CollapseAlways();

    /**
     * Requests stream data snapshot
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    uint64_t GetSnapshot(Instrument & snapshot) const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    bool m_multisnapshot;
};

/**
 * InstrumentStream::IHandler class provides a callback interface to handle
 * instrument stream events.
 *
 * @see InstrumentStream
 */
class STRATEGY_EXPORT InstrumentStream::IHandler : public Stream::IHandler
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
     * @param instrument               Update data
     */
    virtual void HandleInstrument(const StreamIdentifier & stream, const Instrument & instrument) = 0;

    /**
     * Instrument stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     * Fox example, a subscription was made for deleted instruments and all the
     * deleted instruments are received. If any such instrument is un-deleted,
     * invalidate method would be called to indicate that this instrument no longer
     * belongs to subscription request.
     *
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidate instrument
     */
    virtual void HandleInstrumentInvalidate(const StreamIdentifier & stream, const InstrumentIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};

/**
 * Default instrument filter, matches all data.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Filter & filter);
    virtual ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const Filter & filter);
    Filter & operator&=(const Filter & filter);

    Filter operator||(const Filter & filter);
    Filter operator&&(const Filter & filter);

    Filter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

/**
 * InstrumentStream::Filters::FilterCondition.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    InstrumentStream::Filters::Filter operator||(const InstrumentStream::Filters::FilterCondition & cond) const;
    InstrumentStream::Filters::Filter operator&&(const InstrumentStream::Filters::FilterCondition & cond) const;
    InstrumentStream::Filters::Filter operator||(const InstrumentStream::Filters::Filter & cond) const;
    InstrumentStream::Filters::Filter operator&&(const InstrumentStream::Filters::Filter & cond) const;
    InstrumentStream::Filters::Filter operator!() const;
    operator InstrumentStream::Filters::Filter() const;

public:
    virtual ~FilterCondition() {}
};

class STRATEGY_EXPORT InstrumentStream::Options : public Printable
{
public:
    using filter_type = InstrumentStream::Filters::Filter;
    using throttle_type = InstrumentThrottle;

    Options() = default;
    ~Options() = default;

    /**
     * %Set instrument filter to subscribe for all instrumnets match it
     * @param filter   instrument filter
     */
    void SetFilter(const InstrumentStream::Filters::Filter & filter) { m_filter = filter; }

    /**
     * Get instrument filter
     * @return         instrument filter
     */
    const InstrumentStream::Filters::Filter & GetFilter() const { return m_filter; }

    /**
     * %Set instrument to subscribe
     * If you set instrumnets before, the old value will be frayed
     *
     * @param instrument   instrument identifier
     */
    void SetInstrument(const InstrumentIdentifier & instrument) { m_instruments.assign(1, instrument); }

    /**
     * %Set instruments to subscribe
     * If you set instrumnets before, the old value will be frayed
     * @param instruments  instrument identifiers
     */
    void SetInstruments(const std::vector<InstrumentIdentifier> & instruments) { m_instruments = instruments; }

    /**
     * Add passed instrument to the list of instrumnets to subscribe
     * If the number of instruments is not one, coalesing will not be enabled
     * @param instrument   instrument identifier
     */
    void AddInstrument(const InstrumentIdentifier & instrument)
    {
        if (!instrument.Empty()) {
            m_instruments.push_back(instrument);
        }
    }

    /**
     * Get instrument to subscribe
     * @return             instrument identifiers
     */
    const std::vector<InstrumentIdentifier> & GetInstruments() const { return m_instruments; }

    /**
     * %Set ranking identifier
     * @param id           ranking identifier
     */
    void SetRankingIdentifier(const Identifier & id) { m_ranking_id = id; }

    /**
     * Get ranking identifier
     * @return             ranking identifier
     */
    const Identifier & GetRankingIdentifier() const { return m_ranking_id; }

    /**
     * %Set context identifier
     * @param id           context identifier
     */
    void SetContextIdentifier(const Identifier & id) { m_context_id = id; }

    /**
     * Get context identifier
     * @return             context identifier
     */
    const Identifier & GetContextIdentifier() const { return m_context_id; }

    /**
     * %Set user
     * @param id           user identifier
     */
    void SetUserIdentifier(const UserIdentifier & id) { m_user_id = id; }

    /**
     * %Set user
     * @param user         user
     */
    void SetUserIdentifier(const User & user) { m_user_id = user.GetIdentifier(); }

    /**
     * Get user
     * @return             user identifier
     */
    const UserIdentifier & GetUserIdentifier() const { return m_user_id; }

    /**
     * %Set portfolio
     * @param id           portfolio identifier
     */
    void SetPortfolioIdentifier(const PortfolioIdentifier & id) { m_portfolio_id = id; }

    /**
     * Get portfolio
     * @return             portfolio identifier
     */
    const PortfolioIdentifier & GetPortfolioIdentifier() const { return m_portfolio_id; }

    /**
     * %Set snapshot date time
     * @param date_time    snapshot date time
     */
    void SetSnapshotDateTime(const DateTime & date_time) { m_snapshot_datetime = date_time; }

    /**
     * Get snapshot date time
     * @return             snapshot datetime
     */
    const DateTime & GetSnapshotDateTime() const { return m_snapshot_datetime; }

    virtual std::ostream & Print(std::ostream & strm) const;

    // clang-format off
    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] filter_type & GetFilter() { return m_filter; }

    /// @deprecated Deprecated in 2.14.6, set automatically if it is possible
    [[deprecated(DEPRECATE_LINK)]] void SetCoalescing(bool coalescing) { m_coalescing = coalescing; }

    /// @deprecated Deprecated in 2.14.6, set automatically if it is possible
    /// true if the filter is empty and one instrument is set
    [[deprecated(DEPRECATE_LINK)]] bool GetCoalescing() const { return m_coalescing; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetThrottle(const throttle_type & throttle) { m_throttle = throttle; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] const throttle_type & GetThrottle() const { return m_throttle; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] throttle_type & GetThrottle() { return m_throttle; }

    /// @deprecated Deprecated in 2.14.6, use 'const std::vector<InstrumentIdentifier> & GetInstruments() const' instead
    [[deprecated(DEPRECATE_LINK)]] std::vector<InstrumentIdentifier> & GetInstruments() { return m_instruments; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetInstrumentGroup(const InstrumentGroupIdentifier & group) { m_instrument_groups.assign(1, group); }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetInstrumentGroups(const std::vector<InstrumentGroupIdentifier> & groups) { m_instrument_groups = groups; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void AddInstrumentGroup(const InstrumentGroupIdentifier & group) { if (!group.Empty()) { m_instrument_groups.push_back(group); } }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] const std::vector<InstrumentGroupIdentifier> & GetInstrumentGroups() const { return m_instrument_groups; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] std::vector<InstrumentGroupIdentifier> & GetInstrumentGroups() { return m_instrument_groups; }
    // clang-format on

private:
    InstrumentStream::Filters::Filter m_filter;
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

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument group parameters container.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Strategy.h"
#include "strategy/type/AnyType.h"
#include "strategy/type/InstrumentGroupIdentifier.h"

#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/InstrumentGroupFilter.h"
#include "strategy/stream_throttle/InstrumentParametersThrottle.h"

#include <memory>

namespace tbricks {

namespace types {
class Parameters;
class ParameterInformation;
}

namespace protocol {
class InstrumentGroupParametersAggregate;
}

class InstrumentGroupAggregateParametersStream;
class InstrumentParameterDefinition;
class ParameterSource;

/**
 * InstrumentGroupAggregateParameters is a merged view of group parameters and
 * group's ascendant parameters.  the instrument belongs to. That is, if group
 * A has parameter PA and its parent group B that has parameter PB, then
 * aggregate parameters for group A (unless they are excluded with manual
 * parameter definition selection, see methods below) will contain both PA and
 * PB.
 *
 * @see InstrumentParameters
 * @see InstrumentGroupParameters
 */
class STRATEGY_EXPORT InstrumentGroupAggregateParameters : public Printable
{
public:
    class Update;
    using Stream = InstrumentGroupAggregateParametersStream;

public:
    /**
     * Default constructor, creates an empty object.
     */
    InstrumentGroupAggregateParameters();

    /**
     * Creates immediately resolved object.
     *
     * If instrument identifier does not match any of the instruments known in
     * the system, constructor will create an empty object and a warning will
     * be logged.
     *
     * If second parameter is left empty, object receives all parameters
     * available for the instrument.
     *
     * @param instrument_id             Instrument identifier
     * @param definitions               Indentifiers of the parameters the
     *                                  caller is interested in
     */
    InstrumentGroupAggregateParameters(const InstrumentGroupIdentifier & instrument_id,
                                       const std::vector<InstrumentParameterDefinition> & definitions);

    /**
     * Copy constructor.
     */
    InstrumentGroupAggregateParameters(const InstrumentGroupAggregateParameters & parameters);

    /**
     * Destructor.
     */
    virtual ~InstrumentGroupAggregateParameters();

    InstrumentGroupAggregateParameters & operator=(const InstrumentGroupAggregateParameters & parameters);

public:
    /**
     * Fetch parameter value from the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     *
     * @return                          True if container has parameter value
     *                                  tagged with given name, false otherwise
     */
    bool GetParameter(const InstrumentParameterDefinition & definition, AnyType & value) const;

    /**
     * Store parameter value in the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     */
    void SetParameter(const InstrumentParameterDefinition & definition, const AnyType & value);

    /**
     * Check if container has a value for the key.
     *
     * Method returns 'true' if only if container has a value for the
     * provided parameter definition.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     *
     * @return                          True if value is found, false otherwise.
     */
    bool HasParameter(const InstrumentParameterDefinition & definition) const;

    bool GetSource(const InstrumentParameterDefinition & definition, ParameterSource & source) const;
    bool HasSource(const InstrumentParameterDefinition & definition) const;

    /**
     * Clear parameters.
     */
    void Clear();

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no records in the
     *                                  container, false otherwise.
     */
    bool Empty() const;

    /**
     * Merge parameters.
     *
     * Updates container data with values from the argument.
     *
     * @param parameters                Parameter container
     */
    void Merge(const InstrumentGroupAggregateParameters::Update & parameters);

    size_t GetHash() const;

    std::ostream & Print(std::ostream & strm) const override;

public:
    class STRATEGY_EXPORT const_iterator : public Printable
    {
    public:
        const_iterator();
        const_iterator(const const_iterator & it);
        ~const_iterator() override;
        const_iterator & operator=(const const_iterator & it);

        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        const_iterator & operator*();

        void Clear();
        bool Empty() const;

    public:
        Uuid GetIdentifier() const;
        // returns Empty definition if cannot resolve
        InstrumentParameterDefinition GetDefinition() const;

        bool Get(AnyType & value) const;
        bool Get(Variant & value) const;

        bool GetSource(ParameterSource & source) const;

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class InstrumentGroupAggregateParameters;
        void init(const types::ParameterInformation * sources, const void * data, size_t size, size_t pos = 0);

    private:
        const types::ParameterInformation * m_sources;
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

public:
    InstrumentGroupAggregateParameters(const protocol::InstrumentGroupParametersAggregate & parameters);
    InstrumentGroupAggregateParameters & operator=(const protocol::InstrumentGroupParametersAggregate & parameters);
    types::Parameters & get_parameters();
    const types::Parameters & get_parameters() const;

private:
    std::unique_ptr<types::Parameters> m_parameters;
    std::unique_ptr<types::ParameterInformation> m_sources;
};

inline size_t hash_value(const InstrumentGroupAggregateParameters & value)
{
    return value.GetHash();
}

/**
 * InstrumentGroupAggregateParameters::Update, collection of updated instrument
 * parameters.
 */
class STRATEGY_EXPORT InstrumentGroupAggregateParameters::Update : public Printable
{
public:
    /**
     * Fetch parameter value from the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Result
     *
     * @return                          True if container has parameter value
     *                                  for given identifier, false otherwise
     */
    bool GetParameter(const InstrumentParameterDefinition & definition, AnyType & value) const;

    bool GetSource(const InstrumentParameterDefinition & definition, ParameterSource & source) const;
    bool HasSource(const InstrumentParameterDefinition & definition) const;

    /**
     * Get all sources.
     *
     * @param sources                   Variable to store sources value
     *
     * @return                          True if sources exists, false otherwise
     */
    bool GetSources(SparseHash<Uuid, ParameterSource> & sources) const;

    /**
     * Check if container has a value for the key.
     *
     * Method returns 'true' if only if container has a value for the
     * provided parameter definition.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     *
     * @return                          True if value is found, false otherwise.
     */
    bool IsUpdated(const InstrumentParameterDefinition & definition) const;

    std::ostream & Print(std::ostream & strm) const override;

public:
    class STRATEGY_EXPORT const_iterator : public Printable
    {
    public:
        const_iterator();
        const_iterator(const const_iterator & it);
        ~const_iterator() override;
        const_iterator & operator=(const const_iterator & it);

        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        const_iterator & operator*();

        void Clear();
        bool Empty() const;

    public:
        Uuid GetIdentifier() const;
        // returns Empty definition if cannot resolve
        InstrumentParameterDefinition GetDefinition() const;

        bool Get(AnyType & value) const;
        bool Get(Variant & value) const;

        bool GetSource(ParameterSource & source) const;

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class InstrumentGroupAggregateParameters::Update;
        void init(const void * data, size_t size, size_t pos, const void * sources_data, size_t sources_size);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;

        const void * m_sources_data;
        size_t m_sources_size;
    };

    const_iterator begin() const;
    const_iterator end() const;

public:
    types::Parameters get_parameters() const;
    types::ParameterInformation get_sources() const;

public:
    Update(std::shared_ptr<protocol::InstrumentGroupParametersAggregate> && msg);
    virtual ~Update();

private:
    std::shared_ptr<protocol::InstrumentGroupParametersAggregate> m_msg;
};

/**
 * InstrumentGroupAggregateParameters::Stream class is an interface to receive snapshots
 * and/or live instrument group parameters updates.
 *
 * Stream is a reference to the internal stream object managed by
 * Strategy Engine, and all copies of the object always refer to the same
 * stream, always have the same state and operations made on one instance
 * becomes immediately effective to all others.
 *
 * Also, unless Close() method is called explicitly, opened stream is not
 * closed physically until last Stream object is destroyed.
 *
 * Note that if a callback is not set either in the constructor or at a
 * later time by SetCallback() method, stream delivers no updates.
 */
class STRATEGY_EXPORT InstrumentGroupAggregateParametersStream : public tbricks::Stream
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
    InstrumentGroupAggregateParametersStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param context                   Strategy context
     * @param handler                   Stream callback interface
     */
    InstrumentGroupAggregateParametersStream(IHandler & handler);

    /**
     * %Set callback interface.
     *
     * Associates current stream object with a callback interface where
     * stream updates will be delivered to.
     *
     * If stream is already opened this method has no effect.
     *
     * @param context                   Strategy context
     * @param handler                   Callback interface
     */
    void SetCallback(IHandler & handler);

    /**
     * Open a stream.
     *
     * Parameter "definitions" allows to select what specific instrument
     * parameters updates the caller is interested in.
     *
     * Parameter "snapshot_datetime" allows to get instument paramers as they were at
     * a particular time in past. By default, "snapshot_datetime" is empty what means
     * current parameters will be requested.
     *
     * If stream is already opened or no callback interface is associated,
     * the call has no effect.
     *
     * @param type                      Stream type
     * @param definitions               Parameter definitions
     * @param filter                    Stream event filter
     * @param snapshot_datetime         Snapshot datetime
     */
    void Open(Type type,
              const std::vector<InstrumentParameterDefinition> & definitions,
              const InstrumentGroupFilter & filter,
              const DateTime & snapshot_datetime = DateTime(),
              bool get_source = false);

    void Open(Type type, const Options & options);

    /**
     * Requests stream data snapshot
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    uint64_t GetSnapshot(InstrumentGroupAggregateParameters & snapshot) const;

    /**
     * This option enable force stream collapsing on engine level. If it
     * was enabled, all snapshot for stream will be kept in engine and used
     * for identical stream. It can lead to significantly decreasing of load
     * for Instrument Service for some cases.
     *
     * ATTENTION! THIS OPTION ONLY FOR TBRICKS INTERNAL USAGE!
     *
     * This option also could lead to bad performance and high memory consumption
     * in your system! Please don't use this option or contact Tbricks support
     * for addition information before use it.
     */
    void CollapseAlways();

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    bool m_multisnapshot;
};

/**
 * InstrumentGroupAggregateParameters::Stream::IHandler class is a callback interface to
 * handle instrument group parameters stream events.
 *
 * @see InstrumentGroupAggregateParameters::Stream
 */
class STRATEGY_EXPORT InstrumentGroupAggregateParameters::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    /**
     * Instrument group parameters stream update handler.
     *
     * Method is called when a new instrument parameters update becomes
     * available on the stream.
     *
     * @param stream                   Stream identifier
     * @param group                    Instrument group identifier
     * @param update                   Update data
     */
    virtual void HandleInstrumentGroupAggregateParameters(const StreamIdentifier & stream,
                                                          const InstrumentGroupIdentifier & group,
                                                          const InstrumentGroupAggregateParameters::Update & update) = 0;

protected:
    virtual ~IHandler();
};

class STRATEGY_EXPORT InstrumentGroupAggregateParametersStream::Options : public Printable
{
public:
    using filter_type = InstrumentGroupFilter;
    using throttle_type = InstrumentGroupAggregateParametersThrottle;

    Options() = default;

    ~Options() = default;

    void SetParameterDefinitions(const std::vector<InstrumentParameterDefinition> & params) { m_definitions = params; }

    const std::vector<InstrumentParameterDefinition> & GetParameterDefinitions() const { return m_definitions; }

    void SetRankingIdentifier(const Identifier & id) { m_ranking_id = id; }

    const Identifier & GetRankingIdentifier() const { return m_ranking_id; }

    void SetContextIdentifier(const Identifier & id) { m_context_id = id; }

    const Identifier & GetContextIdentifier() const { return m_context_id; }

    void SetUserIdentifier(const UserIdentifier & id) { m_user_id = id; }

    void SetUserIdentifier(const User & user) { m_user_id = user.GetIdentifier(); }

    const UserIdentifier & GetUserIdentifier() const { return m_user_id; }

    void SetPortfolioIdentifier(const PortfolioIdentifier & id) { m_portfolio_id = id; }

    const PortfolioIdentifier & GetPortfolioIdentifier() const { return m_portfolio_id; }

    void SetFilter(const filter_type & filter) { m_filter = filter; }

    const filter_type & GetFilter() const { return m_filter; }

    void SetThrottle(const throttle_type & throttle) { m_throttle = throttle; }

    const throttle_type & GetThrottle() const { return m_throttle; }

    void SetSnapshotDateTime(const DateTime & date_time) { m_snapshot_date_time = date_time; }

    const DateTime & GetSnapshotDateTime() const { return m_snapshot_date_time; }

    bool GetParameterSource() const { return m_get_parameter_source; }

    void SetParameterSource(bool get_parameter_source) { m_get_parameter_source = get_parameter_source; }

    const std::vector<InstrumentGroupIdentifier> & GetInstrumentGroups() const { return m_instrument_groups; }

    void SetInstrumentGroups(const std::vector<InstrumentGroupIdentifier> & groups) { m_instrument_groups = groups; }

    void SetInstrumentGroup(const InstrumentGroupIdentifier & group) { m_instrument_groups.assign(1, group); }

    void AddInstrumentGroup(const InstrumentGroupIdentifier & group) { m_instrument_groups.push_back(group); }

    // clang-format off
    /// @deprecated Deprecated in 2.14.6, use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] std::vector<InstrumentParameterDefinition> & GetParameterDefinitions() { return m_definitions; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] filter_type & GetFilter() { return m_filter; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] throttle_type & GetThrottle() { return m_throttle; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] DateTime & GetSnapshotDateTime() { return m_snapshot_date_time; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] const std::vector<InstrumentIdentifier> & GetInstruments() const { return m_instruments; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] std::vector<InstrumentIdentifier> & GetInstruments() { return m_instruments; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetInstruments(const std::vector<InstrumentIdentifier> & instruments) { m_instruments = instruments; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetInstrument(const InstrumentIdentifier & instrument) { m_instruments.assign(1, instrument); }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void AddInstrument(const InstrumentIdentifier & instrument) { m_instruments.push_back(instrument); }

    /// @deprecated Deprecated in 2.14.6, use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] std::vector<InstrumentGroupIdentifier> & GetInstrumentGroups() { return m_instrument_groups; }
    // clang-format on

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::vector<InstrumentParameterDefinition> m_definitions;
    std::vector<InstrumentIdentifier> m_instruments;
    std::vector<InstrumentGroupIdentifier> m_instrument_groups;
    Identifier m_ranking_id;
    Identifier m_context_id;
    UserIdentifier m_user_id;
    PortfolioIdentifier m_portfolio_id;
    filter_type m_filter;
    throttle_type m_throttle;
    DateTime m_snapshot_date_time;
    bool m_get_parameter_source = false;
};
}

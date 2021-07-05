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
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/InstrumentGroupFilter.h"
#include "strategy/stream_throttle/InstrumentParametersThrottle.h"
#include "strategy/type/AnyType.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/InstrumentGroupIdentifier.h"
#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/type/UserIdentifier.h"
#include "strategy_generated/InstrumentGroupParametersBase.h"
#include "strategy_generated/InstrumentGroupParametersUpdateBase.h"

#include <memory>

namespace tbricks {

namespace types {
class Parameters;
}
namespace protocol {
class InstrumentGroupParameters;
}

class InstrumentGroupParametersStream;
class InstrumentParameterDefinition;

/**
 * InstrumentGroupParameters object stores a collection of instrument
 * parameters and, through nested auxiliary classes, provides
 * for distant manipulations.
 */
class STRATEGY_EXPORT InstrumentGroupParameters : public InstrumentGroupParametersBase
{
public:
    class Modifier;
    class Update;
    using Stream = InstrumentGroupParametersStream;

public:
    InstrumentGroupParameters();
    InstrumentGroupParameters(const InstrumentGroupParameters & parameters);
    InstrumentGroupParameters(InstrumentGroupParameters && parameters) noexcept;
    InstrumentGroupParameters & operator=(const InstrumentGroupParameters & parameters);
    InstrumentGroupParameters & operator=(InstrumentGroupParameters && parameters) noexcept;
    ~InstrumentGroupParameters() override;

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
    InstrumentGroupParameters(const InstrumentGroupIdentifier & instrument_id, const std::vector<InstrumentParameterDefinition> & definitions);

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

    /**
     * Merge parameters.
     *
     * Updates container data with values from the argument.
     *
     * @param parameters                Parameter container
     */
    void Merge(const InstrumentGroupParameters::Update & parameters);

    /**
     * Get operator identifier
     *
     * @return                          Operator's identifier
     */
    UserIdentifier GetUserIdentifier() const { return GetOperator(); }

public:
    /**
     * Send instrument group parameters modify request.
     *
     * Instrument modify request is a remote operation and its status is
     * delievered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param group_id                  Group identifier
     * @param modifier                  Modification request
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Request identifier, for later use
     *                                  in HandleRequestReply() method
     */
    static Identifier SendModifyRequest(const InstrumentGroupIdentifier & group_id,
                                        const InstrumentGroupParameters::Modifier & modifier,
                                        IRequestReplyHandler & handler = IRequestReplyHandler::Default());

public:
    size_t GetHash() const;

    bool operator==(const InstrumentGroupParameters & parameters) const;
    bool operator!=(const InstrumentGroupParameters & parameters) const { return !operator==(parameters); }

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

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class InstrumentGroupParameters;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;
};

inline size_t hash_value(const InstrumentGroupParameters & value)
{
    return value.GetHash();
}

/**
 * InstrumentGroupParameters::Modifier, helper class for remote instrument
 * parameter modifications.
 *
 * @see InstrumentGroupParameters::SendModifyRequest
 */
class STRATEGY_EXPORT InstrumentGroupParameters::Modifier : public Printable
{
public:
    /**
     * Contructor.
     */
    Modifier();

    /**
     * Copy constructor
     */
    Modifier(const Modifier & modifier);

    /**
     * Operator =
     */
    Modifier & operator=(const Modifier & modifier);

    /**
     * Destructor.
     */
    virtual ~Modifier();

    /**
     * %Set new parameter value.
     *
     * Parameter value does not take effect until appropriate
     * InstrumentGroupParameters::SendModifyRequest() is called and it is acknowledged by remote
     * side with IRequestReplyHandler::HandleRequestReply().
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     New parameter value
     */
    void SetParameter(const InstrumentParameterDefinition & definition, const AnyType & value);

    void SetParameters(const InstrumentGroupParameters & parameters);

    void SetContextIdentifier(const Identifier & context_id);
    void SetPortfolioIdentifier(const PortfolioIdentifier & portfolio_id);
    void SetUserIdentifier(const UserIdentifier & user_id);
    void SetUserIdentifier(const User & user);

    const Identifier & GetContextIdentifier() const { return m_context_id; }
    const PortfolioIdentifier & GetPortfolioIdentifier() const { return m_portfolio_id; }
    const UserIdentifier & GetUserIdentifier() const { return m_user_id; }

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

    bool Empty() const;
    void Clear();

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

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class InstrumentGroupParameters::Modifier;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

public:
    types::Parameters & get_parameters();

private:
    std::unique_ptr<types::Parameters> m_parameters;
    Identifier m_context_id;
    PortfolioIdentifier m_portfolio_id;
    UserIdentifier m_user_id;
};

/**
 * InstrumentGroupParameters::Update, collection of updated instrument
 * parameters.
 */
class STRATEGY_EXPORT InstrumentGroupParameters::Update : public InstrumentGroupParametersUpdateBase
{
public:
    Update();
    Update(const Update & update);
    Update(Update && update) noexcept;
    Update & operator=(const Update & update);
    Update & operator=(Update && update) noexcept;
    ~Update() override;

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

    /**
     * Get operator identifier
     *
     * @return                          Operator's identifier
     */
    UserIdentifier GetUserIdentifier() const { return GetOperator(); }

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

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class InstrumentGroupParameters::Update;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

public:
    types::Parameters get_parameters() const;

public:
    Update(std::shared_ptr<protocol::InstrumentGroupParameters> && msg);
};

/**
 * InstrumentGroupParameters::Stream class is an interface to receive snapshots
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
class STRATEGY_EXPORT InstrumentGroupParametersStream : public tbricks::Stream
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
    InstrumentGroupParametersStream();

    /**
     * Constructor.
     *
     * Creates a full functional instance associated with a stream callback
     * interface.
     *
     * @param context                   Strategy context
     * @param handler                   Stream callback interface
     */
    InstrumentGroupParametersStream(IHandler & handler);

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
     * @param snapshot_datetime         Snapshot datetim
     */
    void Open(Type type,
              const std::vector<InstrumentParameterDefinition> & definitions,
              const InstrumentGroupFilter & filter,
              const DateTime & snapshot_datetime = DateTime());

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
    void OpenAudit(Type type, const InstrumentGroupFilter & filter, const DateTime & from = DateTime(), const DateTime & to = DateTime());

    void OpenAudit(Type type, const Options & options, const DateTime & from = DateTime(), const DateTime & to = DateTime());

    /**
     * Requests stream data snapshot
     *
     * @param snapshot                  Object target for snapshot extraction
     *
     * @return                          Number of stream updates, 0 means no updates since stream opening
     *                                  or snapshot is not provided by this type of stream
     */
    uint64_t GetSnapshot(InstrumentGroupParameters & snapshot) const;

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
 * InstrumentGroupParameters::Stream::IHandler class is a callback interface to
 * handle instrument group parameters stream events.
 *
 * @see InstrumentGroupParameters::Stream
 */
class STRATEGY_EXPORT InstrumentGroupParameters::Stream::IHandler : public tbricks::Stream::IHandler
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
    virtual void HandleInstrumentGroupParameters(const StreamIdentifier & stream,
                                                 const InstrumentGroupIdentifier & group,
                                                 const InstrumentGroupParameters::Update & update) = 0;

protected:
    virtual ~IHandler();
};

class STRATEGY_EXPORT InstrumentGroupParametersStream::Options : public Printable
{
public:
    using filter_type = InstrumentGroupFilter;
    using throttle_type = InstrumentGroupParametersThrottle;

    Options() = default;
    ~Options() = default;

    void SetParameterDefinitions(const std::vector<InstrumentParameterDefinition> & params) { m_definitions = params; }

    const std::vector<InstrumentParameterDefinition> & GetParameterDefinitions() const { return m_definitions; }

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

    const std::vector<InstrumentGroupIdentifier> & GetInstrumentGroups() const { return m_instrument_groups; }

    void SetInstrumentGroups(const std::vector<InstrumentGroupIdentifier> & groups) { m_instrument_groups = groups; }

    void SetInstrumentGroup(const InstrumentGroupIdentifier & group) { m_instrument_groups.assign(1, group); }

    void AddInstrumentGroup(const InstrumentGroupIdentifier & group) { m_instrument_groups.push_back(group); }

    // clang-format off
    /// @deprecated Deprecated in 2.14.6, use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] std::vector<InstrumentParameterDefinition> & GetParameterDefinitions() { return m_definitions; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetRankingIdentifier(const Identifier & id) { m_ranking_id = id; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] const Identifier & GetRankingIdentifier() const { return m_ranking_id; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] filter_type & GetFilter() { return m_filter; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] throttle_type & GetThrottle() { return m_throttle; }

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] DateTime & GetSnapshotDateTime() { return m_snapshot_date_time; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] bool GetParameterSource() const { return m_parameters_source; }

    /// @deprecated Deprecated in 2.14.6, it is not used
    [[deprecated(DEPRECATE_LINK)]] void SetParameterSource(bool get_parameter_source) { m_parameters_source = get_parameter_source; }

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
    bool m_parameters_source = false;
};
}

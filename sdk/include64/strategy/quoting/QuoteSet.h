#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteSet object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Pair.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/CircuitBreaker.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/RegulatoryParameters.h"
#include "strategy/Event.h"

#include "strategy/quoting/QuoteVolumesTable.h"
#include "strategy/quoting/QuoteIdentification.h"
#include "strategy/quoting/QuoteTable.h"
#include "strategy/stream/InstrumentStream.h"
#include "strategy_generated/QuoteSetMassCancelConditionBase.h"

namespace tbricks {

namespace protocol {
class QuoteSet;
}

namespace strategy {
class QuoteSetStreamImpl;
class EventStreamImpl;
class QuoteMessages;
}

class STRATEGY_EXPORT QuoteSet : public Printable
{
public:
    enum State
    {
        UNKNOWN = 0,
        PAUSED = 1,
        RUNNING = 2,
        DELETED = 3,
        FAILED = 4
    };

    enum QuotePressureConvention
    {
        CONVENTION_1 = 0,
        CONVENTION_2 = 1,
        CONVENTION_3 = 2
    };

    enum FailureReason
    {
        FAILURE_DEFAULT = 0,
        FAILURE_AT_START = 1,
        FAILURE_LIMIT_BREACHED = 2
    };

public:
    class RequestResult;

public:
    class IHandler;

public:
    class Options;
    class Update;
    class Modifier;
    class MassCancelCondition;

public:
    QuoteSet();
    virtual ~QuoteSet();

private:
    QuoteSet(const QuoteSet & quote_set) = delete;
    QuoteSet & operator=(const QuoteSet & quote_set) = delete;

public:
    const Identifier & GetIdentifier() const;
    const VenueIdentifier & GetVenueIdentifier() const;
    const MIC & GetMIC() const;
    const UserIdentifier & GetCreatorIdentifier() const;
    const ExtraData & GetExtraData() const;
    const DateTime & GetHostCreatedDateTime() const;
    const DateTime & GetHostModifiedDateTime() const;
    const UserIdentifier & GetOwnerIdentifier() const;
    const PortfolioIdentifier & GetPortfolioIdentifier() const;
    const Validity & GetMultilevelQuotesValidity() const;
    const ServiceIdentifier & GetQuotingServiceIdentifier() const;
    const State & GetState() const;
    const Boolean & GetSuspended() const;
    const bool & GetCorrupted() const;
    const bool & GetSuppressReplies() const;
    const QuoteVolumesTable & GetQuoteVolumes() const;
    const String & GetStatusText() const;
    const InstrumentIdentifier & GetFailedInstrumentIdentifier() const;
    const InstrumentGroupIdentifier & GetFailedInstrumentGroupIdentifier() const;
    const FailureReason & GetFailureReason() const;
    const StrategyIdentifier & GetStrategyIdentifier() const;
    const Double & GetQuotePressureThreshold() const;
    const Double & GetQuotePressureThresholdFactor() const;
    const Double & GetQuotePressureThrottleMultiplier() const;
    const Boolean & GetQuotePressureUpdatesBothSides() const;

    /**
     * Get quote volume change threshold. Volume change threshold is used in dynamic quote volume computation.
     *
     * @return                    Quote volume change threshold
     */
    const Double & GetQuoteVolumeChangeThreshold() const;

    const QuotePressureConvention & GetQuotePressureConvention() const;
    const VolumeIncreaseBehavior & GetVolumeIncreaseBehavior() const;
    const RegulatoryParameters & GetRegulatoryParameters() const;

    /**
     * Get liquidity pool.
     *
     * @return                    Liquidity pool identifier
     */
    const LiquidityPoolIdentifier & GetLiquidityPool() const;

    /**
     * Get strategy definition identifier path.
     *
     * @return                    strategy definition identifier path
     */
    const std::vector<StrategyIdentifier> & GetStrategyDefinitionPath() const;

public:
    bool Empty() const;
    void Clear();

public:
    void SuppressReplies(bool suppress = true);

private:
    friend STRATEGY_EXPORT class strategy::QuoteSetStreamImpl;
    friend STRATEGY_EXPORT class Converter;

public:
    void Merge(const QuoteSet::Update & update);

public:
    QuoteIdentification
    GetQuoteIdentification(const InstrumentVenueIdentification & ivid, const Integer & level = Integer(0), QuoteMode mode = QuoteModeQuoting);

    QuoteIdentification GetQuoteIdentification(const Identifier & quote_identifier);

    /**
     * If venue and mic are specified, it tries to use market data from passed venue for Hidden and Peg quotes.
     * Resolves market data from ivid otherwise.
     */
    QuoteIdentification GetQuoteIdentification(const InstrumentVenueIdentification & ivid,
                                               const VenueIdentifier & md_venue,
                                               const MIC & md_mic,
                                               const Integer & level = Integer(0),
                                               QuoteMode mode = QuoteModeQuoting);

    class STRATEGY_EXPORT Stream : public tbricks::Stream
    {
    public:
        class IHandler;

    public:
        class Filters
        {
        public:
            class Filter;
            class FilterCondition;
            class ByIdentifierFilter;
            class ByPortfolioFilter;
            class Active;
            class ByOwner;
            class ByCreator;
            class ByParentStrategy;
            class ByAncestorStrategy;
            class ByMIC;
            class ByVenue;
            class ByAlgoLabel;
        };

    public:
        Stream();
        Stream(IHandler & handler);

        void SetCallback(IHandler & handler);
        void SetQuotingService(const ServiceIdentifier & identifier);

        void Open(Type type, const Filters::Filter & filter);

    protected:
        virtual std::ostream & Print(std::ostream & strm) const;

    private:
        strategy::QuoteSetStreamImpl * m_stream;
    };

public:
    RequestResult
    SendCreateRequest(const QuoteSet::Options & options, tbricks::QuoteSet::Stream::IHandler & observer, IRequestReplyHandler & handler);

    RequestResult SendModifyRequest(const QuoteSet::Modifier & modifier, IRequestReplyHandler & handler);

    RequestResult
    SetActiveTable(const Integer & primary_table_identifier, const Integer & secondary_table_identifier, IRequestReplyHandler & handler);

    RequestResult SendStartRequest(IRequestReplyHandler & handler);

    RequestResult SendStopRequest(IRequestReplyHandler & handler);

    RequestResult SendDeleteRequest(IRequestReplyHandler & handler);

    RequestResult SendForceDeleteRequest(IRequestReplyHandler & handler);

    RequestResult SendSuspendRequest(IRequestReplyHandler & handler);

    RequestResult SendUnsuspendRequest(IRequestReplyHandler & handler);

    /**
     * SendDeleteRequest is used to delete the quote sets which matches the filter.
     *
     * Request reply handler will be called for each request identifier
     * from order request results.
     *
     * This method is availabele only for Strategy and Limit apps.
     *
     * @param filter                    Request filter
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          Vector of RequestResult which is a pair of
     *                                  requested identifier and service identifier
     *                                  of the order request.
     */
    static std::vector<RequestResult> SendDeleteRequest(const QuoteSet::Stream::Filters::Filter & filter, IRequestReplyHandler & handler);

    /**
     * SendDeleteRequest is used to delete the quote sets which matches the filter.
     *
     * Request reply handler will be called for each request identifier
     * from order request results.
     *
     * This method is availabele only for Strategy and Limit apps.
     *
     * @param filter                    Request filter
     * @param comment                   Request comment
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          Vector of RequestResult which is a pair of
     *                                  requested identifier and service identifier
     *                                  of the order request.
     */
    static std::vector<RequestResult>
    SendDeleteRequest(const QuoteSet::Stream::Filters::Filter & filter, const String & comment, IRequestReplyHandler & handler);

    /**
     * SendDeleteRequest is used to delete the quote sets which matches the condition.
     *
     * Request reply handler will be called for each request identifier
     * from order request results.
     *
     * This method is availabele only for Strategy and Limit apps.
     *
     * @param condition                 Request condition
     * @param comment                   Request comment
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until all replies are received
     *
     * @return                          Vector of RequestResult which is a pair of
     *                                  requested identifier and service identifier
     *                                  of the order request.
     */
    static std::vector<RequestResult>
    SendDeleteRequest(const MassCancelCondition & condition, const String & comment, IRequestReplyHandler & handler);

public:
    RequestResult AddQuoteTable(const QuoteTable::Options & options, IRequestReplyHandler & handler);

    RequestResult ModifyQuoteTable(const QuoteTable::Modifier & quote_table_modifier, IRequestReplyHandler & handler);

    RequestResult DeleteQuoteTable(const Integer & primary_quote_table_identifier,
                                   const Integer & secondary_quote_table_identifier,
                                   IRequestReplyHandler & handler);

public:
    CircuitBreaker::RequestResult SendCircuitBreakerCreateRequest(const CircuitBreaker::Options & options, IRequestReplyHandler & handler);

    CircuitBreaker::RequestResult
    SendCircuitBreakerModifyRequest(const Identifier & circuit_breaker_id, const CircuitBreaker::Modifier & modifier, IRequestReplyHandler & handler);

    CircuitBreaker::RequestResult SendCircuitBreakerDeleteRequest(const Identifier & circuit_breaker_id, IRequestReplyHandler & handler);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const State & state);
    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const QuotePressureConvention & convention);
    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const VolumeIncreaseBehavior & behavior);

private:
    bool ValidateQuoteTableModifier(const QuoteTable::Modifier & modifer, String & status);

    RequestResult DoDeleteQuoteSet(IRequestReplyHandler & handler, bool force);

    RequestResult DoSendSuspendRequest(bool suspend, IRequestReplyHandler & handler);

private:
    Identifier m_identifier;
    MIC m_mic;
    UserIdentifier m_creator_identifier;
    ExtraData m_extra_data;
    DateTime m_host_created_datetime;
    DateTime m_host_modified_datetime;
    UserIdentifier m_owner_identifier;
    PortfolioIdentifier m_portfolio_identifier;
    Validity m_multilevel_quotes_validity;
    ServiceIdentifier m_service_identifier;
    QuoteVolumesTable m_quote_volumes;
    String m_status_text;
    InstrumentIdentifier m_failed_instrument_identifier;
    InstrumentGroupIdentifier m_failed_group_identifier;
    FailureReason m_failure_reason;
    StrategyIdentifier m_strategy_identifier;
    VenueIdentifier m_venue_identifier;
    Double m_quote_pressure_threshold;
    Double m_quote_pressure_threshold_factor;
    Double m_quote_pressure_throttle_multiplier;
    QuotePressureConvention m_pressure_convention;
    Double m_quote_volume_change_threshold;
    VolumeIncreaseBehavior m_volume_increase_behavior;
    RegulatoryParameters m_regulatory_parameters;

    State m_state;
    bool m_suppress_reply;
    bool m_corrupted;
    uint64_t m_service_version = 0;

    Boolean m_quote_pressure_updates_both_sides;
    Boolean m_suspended;

    strategy::QuoteSetStreamImpl * m_quote_set_stream_impl;
    strategy::QuoteMessages * m_quote_messages;

    tbricks::QuoteSet::Stream::IHandler * m_observer;

    typedef Pair<InstrumentVenueIdentification, Pair<Integer, Integer>> Level;
    SparseHash<Level, Identifier> m_quote_level_mapping;
    SparseHash<Identifier, QuoteIdentification> m_quote_mapping;

    typedef Pair<Integer, Integer> QuoteTableIdentifier;
    SparseHash<QuoteTableIdentifier, QuoteTable> m_quote_tables;

    LiquidityPoolIdentifier m_liquidity_pool_identifier;

    std::vector<StrategyIdentifier> m_strategy_definition_path;
};

//****************************************************************************
// RequestResult class
//****************************************************************************
class STRATEGY_EXPORT QuoteSet::RequestResult : public Printable
{
public:
    RequestResult();
    virtual ~RequestResult() {}
    RequestResult(const Identifier & request_identifier, const Identifier & quote_set_identifier, const ServiceIdentifier & service_id);

    const Identifier & GetRequestIdentifier() const;
    const Identifier & GetQuoteSetIdentifier() const;
    const ServiceIdentifier & GetServiceIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    Identifier m_quote_set_identifier;
    ServiceIdentifier m_service_id;
};

//****************************************************************************
// Options class
//****************************************************************************
class STRATEGY_EXPORT QuoteSet::Options : public Printable
{
public:
    Options();

public:
    void SetExtraData(const ExtraData & extra_data);
    const ExtraData & GetExtraData() const;

    void SetPortfolioIdentifier(const PortfolioIdentifier & portfolio_identifier);
    const PortfolioIdentifier & GetPortfolioIdentifier() const;

    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);
    const InstrumentVenueIdentification & GetInstrumentVenueIdentification() const;

    void SetCarveoutIdentifier(const CarveoutIdentifier & carveout_id);
    const CarveoutIdentifier & GetCarveoutIdentifier() const;

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] CarveoutIdentifier & GetCarveoutIdentifier();

    void SetQuotePressureThreshold(const Double & threshold);
    const Double & GetQuotePressureThreshold() const;

    void SetQuotePressureThresholdFactor(const Double & factor);
    const Double & GetQuotePressureThresholdFactor() const;

    void SetQuotePressureThrottleMultiplier(const Double & threshold);
    const Double & GetQuotePressureThrottleMultiplier() const;

    void SetQuotePressureUpdatesBothSides(const Boolean & bothsides);
    const Boolean & GetQuotePressureUpdatesBothSides() const;

    void SetQuotePressureConvention(const QuotePressureConvention & pressure);
    const QuotePressureConvention & GetQuotePressureConvention() const;

    /**
     * Set quote volume change threshold. Volume change threshold is used in dynamic quote volume computation.
     *
     * @param threshold           Quote volume change threshold to set
     */
    void SetQuoteVolumeChangeThreshold(const Double & threshold);
    /**
     * Get quote volume change threshold. Volume change threshold is used in dynamic quote volume computation.
     *
     * @return                    Quote volume change threshold
     */
    const Double & GetQuoteVolumeChangeThreshold() const;

    void SetVolumeIncreaseBehavior(const VolumeIncreaseBehavior & behavior);
    const VolumeIncreaseBehavior & GetVolumeIncreaseBehavior() const;

    void SetMultilevelQuotesValidity(const Validity & validity);
    const Validity & GetMultilevelQuotesValidity() const;

    void SetRegulatoryParameters(const RegulatoryParameters & parameters);
    const RegulatoryParameters & GetRegulatoryParameters() const;

    void SetLimitRulesWarmupFilter(const InstrumentStream::Filters::Filter & filter);

    /**
     * Sets liquidity pool.
     *
     * @param                     Liquidity pool identifier
     */
    void SetLiquidityPool(const LiquidityPoolIdentifier & liquidity_pool);

    /**
     * Get liquidity pool.
     *
     * @return                    Liquidity pool identifier
     */
    const LiquidityPoolIdentifier & GetLiquidityPool() const;

public:
    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;
    friend STRATEGY_EXPORT class QuoteSet;

private:
    ExtraData m_extra_data;
    PortfolioIdentifier m_portfolio_identifier;
    Validity m_multilevel_quotes_validity;
    QuoteVolumesTable m_quote_volumes;
    InstrumentVenueIdentification m_ivid;
    CarveoutIdentifier m_carveout_id;
    Double m_quote_pressure_threshold;
    Double m_quote_pressure_threshold_factor;
    Double m_quote_pressure_throttle_multiplier;
    Boolean m_quote_pressure_updates_both_sides;
    QuotePressureConvention m_pressure_convention;
    Double m_quote_volume_change_threshold;
    VolumeIncreaseBehavior m_volume_increase_behavior;
    LiquidityPoolIdentifier m_liquidity_pool_identifier;
    RegulatoryParameters m_regulatory_parameters;
    InstrumentStream::Filters::Filter m_limit_rules_warmup_filter;
};

//****************************************************************************
// Update class
//****************************************************************************
class STRATEGY_EXPORT QuoteSet::Update : public Printable
{
public:
    Update();

public:
    const Identifier & GetIdentifier() const;
    const VenueIdentifier & GetVenueIdentifier() const;
    const MIC & GetMIC() const;
    const UserIdentifier & GetCreatorIdentifier() const;
    const ExtraData & GetExtraData() const;
    const DateTime & GetHostCreatedDateTime() const;
    const DateTime & GetHostModifiedDateTime() const;
    const UserIdentifier & GetOwnerIdentifier() const;
    const PortfolioIdentifier & GetPortfolioIdentifier() const;
    const Validity & GetMultilevelQuotesValidity() const;
    const State & GetState() const;
    const Boolean & GetSuspended() const;
    const QuoteVolumesTable & GetQuoteVolumes() const;
    const String & GetStatusText() const;
    const InstrumentIdentifier & GetFailedInstrumentIdentifier() const;
    const InstrumentGroupIdentifier & GetFailedInstrumentGroupIdentifier() const;
    const Value<FailureReason> & GetFailureReason() const;
    const StrategyIdentifier & GetStrategyIdentifier() const;
    const Double & GetQuotePressureThreshold() const;
    const Double & GetQuotePressureThresholdFactor() const;
    const Double & GetQuotePressureThrottleMultiplier() const;
    const Value<QuotePressureConvention> & GetQuotePressureConvention() const;
    const Double & GetQuoteVolumeChangeThreshold() const;
    const Value<VolumeIncreaseBehavior> & GetVolumeIncreaseBehavior() const;
    const RegulatoryParameters & GetRegulatoryParameters() const;
    const ServiceIdentifier & GetQuotingServiceIdentifier() const;

    /**
     * Get liquidity pool.
     *
     * @return                    Liquidity pool identifier
     */
    const LiquidityPoolIdentifier & GetLiquidityPool() const;

    /**
     * Get strategy definition identifier path.
     *
     * @return                    strategy definition identifier path
     */
    const std::vector<StrategyIdentifier> & GetStrategyDefinitionPath() const;

public:
    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;
    friend STRATEGY_EXPORT class QuoteSet;
    friend STRATEGY_EXPORT class strategy::QuoteSetStreamImpl;

public:
    Update(const protocol::QuoteSet & msg);

private:
    Identifier m_identifier;
    VenueIdentifier m_venue_identifier;
    MIC m_mic;
    UserIdentifier m_creator_identifier;
    ExtraData m_extra_data;
    DateTime m_host_created_datetime;
    DateTime m_host_modified_datetime;
    UserIdentifier m_owner_identifier;
    PortfolioIdentifier m_portfolio_identifier;
    Validity m_multilevel_quotes_validity;
    State m_state;
    Boolean m_suspended;
    QuoteVolumesTable m_quote_volumes;
    String m_status_text;
    InstrumentIdentifier m_failed_instrument_identifier;
    InstrumentGroupIdentifier m_failed_group_identifier;
    Value<FailureReason> m_failure_reason;
    StrategyIdentifier m_strategy_identifier;
    Double m_quote_pressure_threshold;
    Double m_quote_pressure_threshold_factor;
    Double m_quote_pressure_throttle_multiplier;
    LiquidityPoolIdentifier m_liquidity_pool_identifier;
    Value<QuotePressureConvention> m_pressure_convention;
    Double m_quote_volume_change_threshold;
    Value<VolumeIncreaseBehavior> m_volume_increase_behavior;
    RegulatoryParameters m_regulatory_parameters;
    ServiceIdentifier m_service_identifier;
    std::vector<StrategyIdentifier> m_strategy_definition_path;
};

//****************************************************************************
// Modifier class
//****************************************************************************
class STRATEGY_EXPORT QuoteSet::Modifier : public Printable
{
public:
    Modifier(const Identifier & identifier);

public:
    const Identifier & GetIdentifier() const;

    void SetExtraData(const ExtraData & extra_data);
    const ExtraData & GetExtraData() const;

    void SetPortfolioIdentifier(const PortfolioIdentifier & portfolio_identifier);
    const PortfolioIdentifier & GetPortfolioIdentifier() const;

    void SetQuoteVolumes(const QuoteVolumesTable & quote_volumes);
    const QuoteVolumesTable & GetQuoteVolumes() const;

    void SetQuotePressureThreshold(const Double & threshold);
    const Double & GetQuotePressureThreshold() const;

    void SetQuotePressureThresholdFactor(const Double & factor);
    const Double & GetQuotePressureThresholdFactor() const;

    void SetQuotePressureThrottleMultiplier(const Double & threshold);
    const Double & GetQuotePressureThrottleMultiplier() const;

    void SetQuotePressureUpdatesBothSides(const Boolean & bothsides);
    const Boolean & GetQuotePressureUpdatesBothSides() const;

    void SetQuotePressureConvention(const QuotePressureConvention & convention);
    const Value<QuotePressureConvention> & GetQuotePressureConvention() const;

    void SetVolumeIncreaseBehavior(const VolumeIncreaseBehavior & behavior);
    const Value<VolumeIncreaseBehavior> & GetVolumeIncreaseBehavior() const;

    void Clear();
    bool Empty() const;

public:
    std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_identifier;
    ExtraData m_extra_data;
    PortfolioIdentifier m_portfolio_identifier;
    QuoteVolumesTable m_quote_volumes;
    Double m_quote_pressure_threshold;
    Double m_quote_pressure_threshold_factor;
    Double m_quote_pressure_throttle_multiplier;
    Boolean m_quote_pressure_updates_both_sides;
    Value<QuotePressureConvention> m_pressure_convention;
    Value<VolumeIncreaseBehavior> m_volume_increase_behavior;
};

class STRATEGY_EXPORT QuoteSet::MassCancelCondition : public QuoteSetMassCancelConditionBase
{
    using QuoteSetMassCancelConditionBase::QuoteSetMassCancelConditionBase;
};

} // namespace tbricks

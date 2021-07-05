#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteSetOptions
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/quoting/QuoteSet.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/Table.h"
#include "strategy/Value.h"

namespace tbricks {

namespace protocol {
class QuoteSet;
class QuoteSetDeleteRequest;
}

namespace test {

class STRATEGY_EXPORT QuoteSetOptions : public Printable
{
public:
    typedef protocol::QuoteSet quote_set_t;

    QuoteSetOptions();
    QuoteSetOptions(const QuoteSetOptions & options);
    QuoteSetOptions(quote_set_t * quote_set);
    QuoteSetOptions & operator=(const QuoteSetOptions & options);
    virtual ~QuoteSetOptions();

public:
    bool HasAlgoLabelOperationIdentifier() const;
    const std::vector<uint32_t> & GetAlgoLabelOperationIdentifier() const;
    void SetAlgoLabelOperationIdentifier(std::vector<uint32_t> algo_labels);

    bool HasCreator() const;
    UserIdentifier GetCreator() const;
    void SetCreator(const UserIdentifier & creator);

    bool HasExtraData() const;
    ExtraData GetExtraData() const;
    void SetExtraData(const ExtraData & extra_data);

    bool HasFailedGroupIdentifier() const;
    Identifier GetFailedGroupIdentifier() const;
    void SetFailedGroupIdentifier(const Identifier & id);

    bool HasFailedInstrumentIdentifier() const;
    Identifier GetFailedInstrumentIdentifier() const;
    void SetFailedInstrumentIdentifier(const Identifier & id);

    bool HasHostCreatedDatetime() const;
    DateTime GetHostCreatedDatetime() const;
    void SetHostCreatedDatetime(const DateTime & host_created_datetime);

    bool HasHostModifiedDatetime() const;
    DateTime GetHostModifiedDatetime() const;
    void SetHostModifiedDatetime(const DateTime & host_modified_datetime);

    bool HasOperatingServiceInstanceIdentifier() const;
    Identifier GetOperatingServiceInstanceIdentifier() const;
    void SetOperatingServiceInstanceIdentifier(const Identifier & id);

    bool HasOperatingStrategyIdentifier() const;
    StrategyIdentifier GetOperatingStrategyIdentifier() const;
    void SetOperatingStrategyIdentifier(const StrategyIdentifier & id);

    bool HasOperator() const;
    UserIdentifier GetOperator() const;
    void SetOperator(const UserIdentifier & user);

    bool HasOwner() const;
    UserIdentifier GetOwner() const;
    void SetOwner(const UserIdentifier & owner);

    bool HasParentStrategyIdentifier() const;
    StrategyIdentifier GetParentStrategyIdentifier() const;
    void SetParentStrategyIdentifier(const StrategyIdentifier & parent_strategy_identifier);

    bool HasPortfolioIdentifier() const;
    PortfolioIdentifier GetPortfolioIdentifier() const;
    void SetPortfolioIdentifier(const PortfolioIdentifier & portfolio_identifier);

    bool HasPortfolioName() const;
    String GetPortfolioName() const;
    void SetPortfolioName(const String & name);

    bool HasQuoteSetPressureConvention() const;
    QuoteSet::QuotePressureConvention GetQuoteSetPressureConvention() const;
    void SetQuoteSetPressureConvention(QuoteSet::QuotePressureConvention convention);

    bool HasQuoteSetPressureThreshold() const;
    Value<Double> GetQuoteSetPressureThreshold() const;
    void SetQuoteSetPressureThreshold(const Value<Double> & threshold);

    bool HasQuoteSetPressureThresholdFactor() const;
    Value<Double> GetQuoteSetPressureThresholdFactor() const;
    void SetQuoteSetPressureThresholdFactor(const Value<Double> & factor);

    bool HasQuoteSetPressureThrottleMultiplier() const;
    Double GetQuoteSetPressureThrottleMultiplier() const;
    void SetQuoteSetPressureThrottleMultiplier(const Double & multiplier);

    bool HasQuoteSetPressureUpdatesBothSides() const;
    Boolean GetQuoteSetPressureUpdatesBothSides() const;
    void SetQuoteSetPressureUpdatesBothSides(const Boolean & both_sides);

    bool HasQuoteSetServiceInstanceIdentifier() const;
    Identifier GetQuoteSetServiceInstanceIdentifier() const;
    void SetQuoteSetServiceInstanceIdentifier(const Identifier & id);

    bool HasQuoteSetFailureReason() const;
    QuoteSet::FailureReason GetQuoteSetFailureReason() const;
    void SetQuoteSetFailureReason(const QuoteSet::FailureReason reason);

    bool HasQuoteSetIdentifier() const;
    Identifier GetQuoteSetIdentifier() const;
    void SetQuoteSetIdentifier(const Identifier & id);

    bool HasQuoteSetState() const;
    QuoteSet::State GetQuoteSetState() const;
    void SetQuoteSetState(const QuoteSet::State state);

    bool HasQuoteSetSuspended() const;
    Boolean GetQuoteSetSuspended() const;
    void SetQuoteSetSuspended(const Boolean & suspended);

    bool HasQuoteVolumes() const;
    QuoteVolumesTable GetQuoteVolumes() const;
    void SetQuoteVolumes(const QuoteVolumesTable & table);

    bool HasRequestIdentifier() const;
    Identifier GetRequestIdentifier() const;
    void SetRequestIdentifier(const Identifier & id);

    bool HasRootStrategyIdentifier() const;
    StrategyIdentifier GetRootStrategyIdentifier() const;
    void SetRootStrategyIdentifier(const StrategyIdentifier & id);

    bool HasStatusText() const;
    String GetStatusText() const;
    void SetStatusText(const String & status_text);

    bool HasStrategyDefinitionPath() const;
    std::vector<StrategyIdentifier> GetStrategyDefinitionPath() const;
    void SetStrategyDefinitionPath(const std::vector<StrategyIdentifier> & path);

    bool HasStrategyEngineServiceInstanceIdentifier() const;
    Identifier GetStrategyEngineServiceInstanceIdentifier() const;
    void SetStrategyEngineServiceInstanceIdentifier(const Identifier & id);

    bool HasStrategyIdentifier() const;
    StrategyIdentifier GetStrategyIdentifier() const;
    void SetStrategyIdentifier(const StrategyIdentifier & id);

    bool HasStrategyIdentifierPath() const;
    std::vector<StrategyIdentifier> GetStrategyIdentifierPath() const;
    void SetStrategyIdentifierPath(const std::vector<StrategyIdentifier> & path);

    bool HasValidity() const;
    Validity GetValidity() const;
    void SetValidity(const Validity & validity);

    bool HasVolumeIncreaseBehavior() const;
    VolumeIncreaseBehavior GetVolumeIncreaseBehavior() const;
    void SetVolumeIncreaseBehavior(VolumeIncreaseBehavior behavior);

public:
    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    const quote_set_t & get_quote_set() const;
    quote_set_t & get_quote_set();

private:
    quote_set_t * m_quote_set;
    std::vector<uint32_t> m_algo_labels;
    Value<QuoteVolumesTable> m_quote_volumes;
};

class STRATEGY_EXPORT QuoteSetOperation : public Printable
{
public:
    typedef protocol::QuoteSetDeleteRequest operation_t;

    QuoteSetOperation();
    QuoteSetOperation(const QuoteSetOperation & operation);
    QuoteSetOperation(operation_t * operation);
    QuoteSetOperation & operator=(const QuoteSetOperation & operation);
    virtual ~QuoteSetOperation();

public:
    bool HasAlgoLabelOperationIdentifier() const;
    std::vector<uint32_t> GetAlgoLabelOperationIdentifier() const;
    void SetAlgoLabelOperationIdentifier(const std::vector<uint32_t> & algo_mapping);

    bool HasForceDeletion() const;
    Boolean GetForceDeletion() const;
    void SetForceDeletion(const Boolean & force);

    bool HasQuoteSetIdentifier() const;
    Identifier GetQuoteSetIdentifier() const;
    void SetQuoteSetIdentifier(const Identifier & id);

    bool HasRequestIdentifier() const;
    Identifier GetRequestIdentifier() const;
    void SetRequestIdentifier(const Identifier & id);

public:
    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    const operation_t & get_operation() const;
    operation_t & get_operation();

private:
    operation_t * m_operation;
};

} // \namespace test
} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PluginOptions
//****************************************************************************

#include "strategy/Printable.h"
#include "strategy/StrategyData.h"
#include "strategy/StrategyAttributes.h"
#include "strategy/StrategyInstruments.h"
#include "strategy/limit/TradingLimitResult.h"
#include "strategy/limit/TradingLimitState.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/StrategyState.h"
#include "strategy/type/TransactionState.h"
#include "strategy/type/UserIdentifier.h"
#include "strategy/type/StrategyTransactionOperation.h"

namespace tbricks {

namespace protocol {
class StrategyInstance;
}

namespace test {

class STRATEGY_EXPORT PluginOptions : public Printable
{
public:
    typedef protocol::StrategyInstance options_t;

    PluginOptions();
    PluginOptions(options_t * options);
    PluginOptions(const PluginOptions & options);
    PluginOptions & operator=(const PluginOptions & options);
    virtual ~PluginOptions();

public:
    bool GetAttributes(StrategyAttributes & attributes) const;
    void SetAttributes(const StrategyAttributes & attributes);

    bool HasCreator() const;
    UserIdentifier GetCreator() const;
    void SetCreator(const UserIdentifier & id);

    bool HasExtraData() const;
    ExtraData GetExtraData() const;
    void SetExtraData(const ExtraData & data);

    bool HasCreationTime() const;
    DateTime GetCreationTime() const;
    void SetCreationTime(const DateTime & time);

    bool HasForwardParameters() const;
    StrategyParameters GetForwardParameters() const;
    void SetForwardParameters(const StrategyParameters & params);

    bool HasLastModificationTime() const;
    DateTime GetLastModificationTime() const;
    void SetLastModificationTime(const DateTime & time);

    /// @deprecated Deprecated in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] bool HasLimitBreach() const;

    /// @deprecated Deprecated in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] Boolean GetLimitBreach() const;

    /// @deprecated Deprecated in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void SetLimitBreach(const Boolean & breach);

    bool HasThroughputLimitBreached() const;
    Boolean GetThroughputLimitBreached() const;
    void SetThroughputLimitBreached(const Boolean & breach);

    bool HasInstruments() const;
    void GetInstruments(std::vector<InstrumentIdentifier> & instruments) const;
    const StrategyInstruments GetStrategyInstruments() const;
    void SetInstruments(StrategyInstruments & ids);
    void SetInstruments(const std::vector<InstrumentIdentifier> & ids);

    bool HasOwner() const;
    UserIdentifier GetOwner() const;
    void SetOwner(const UserIdentifier & id);

    bool HasOperator() const;
    UserIdentifier GetOperator() const;
    void SetOperator(const UserIdentifier & id);

    bool HasParentIdentifier() const;
    StrategyIdentifier GetParentIdentifier() const;
    void SetParentIdentifier(const StrategyIdentifier & id);

    bool HasPriority() const;
    Integer GetPriority() const;
    void SetPriority(const Integer & priority);

    bool HasRequestIdentifier() const;
    Identifier GetRequestIdentifier() const;
    void SetRequestIdentifier(const Identifier & id);

    bool HasRootIdentifier() const;
    StrategyIdentifier GetRootIdentifier() const;
    void SetRootIdentifier(const StrategyIdentifier & id);

    bool HasService() const;
    ServiceIdentifier GetService() const;
    void SetService(const ServiceIdentifier & id);

    bool HasStatusText() const;
    String GetStatusText() const;
    void SetStatusText(const String & status);

    bool HasStrategyDefinitionIdentifier() const;
    StrategyIdentifier GetStrategyDefinitionIdentifier() const;
    void SetStrategyDefinitionIdentifier(const StrategyIdentifier & id);

    bool HasStrategyDefinitionPath() const;
    void GetStrategyDefinitionPath(std::vector<StrategyIdentifier> & path) const;
    void SetStrategyDefinitionPath(const std::vector<StrategyIdentifier> & path);

    bool HasStrategyIdentifier() const;
    StrategyIdentifier GetStrategyIdentifier() const;
    void SetStrategyIdentifier(const StrategyIdentifier & id);

    bool HasStrategyPath() const;
    void GetStrategyPath(std::vector<StrategyIdentifier> & path) const;
    void SetStrategyPath(const std::vector<StrategyIdentifier> & path);

    bool HasStrategyName() const;
    String GetStrategyName() const;
    void SetStrategyName(const String & name);

    bool HasStrategyParameters() const;
    StrategyParameters GetStrategyParameters() const;
    void SetStrategyParameters(const StrategyParameters & params);

    bool HasStrategyState() const;
    StrategyState GetStrategyState() const;
    void SetStrategyState(const StrategyState & state);

    bool HasTransactionOperation() const;
    StrategyTransactionOperation GetTransactionOperation() const;
    void SetTransactionOperation(const StrategyTransactionOperation & operation);

    bool HasStrategyTransactionState() const;
    TransactionState GetStrategyTransactionState() const;
    void SetStrategyTransactionState(const TransactionState & state);

    bool HasTradingLimitResult() const;
    bool GetTradingLimitResult(TradingLimitResult & result) const;
    void SetTradingLimitResult(const TradingLimitResult & result);

    bool HasTradingLimitState() const;
    TradingLimitState GetTradingLimitState() const;
    void SetTradingLimitState(const TradingLimitState & state);

    bool HasValidity() const;
    Validity GetValidity() const;
    void SetValidity(const Validity & validity);

    StrategyData GetStrategyData() const;
    void SetStrategyData(const StrategyData & data);

public:
    void Clear();
    bool Empty() const;
    void Merge(const PluginOptions & options);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    const options_t & get_options() const;
    options_t & get_options();

private:
    options_t * m_options;
};

} // \namespace test
} // \namespace tbricks

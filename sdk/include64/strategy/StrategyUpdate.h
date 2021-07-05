#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyUpdate, represents a set of fields modified in a [remote] strategy
// instance.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/ExtraData.h"
#include "strategy/StrategyInstruments.h"
#include "strategy/parameter/StrategyParameters.h"
#include "strategy/limit/TradingLimitState.h"
#include "strategy/limit/TradingLimitResult.h"

#include "strategy/StrategyAttributes.h"

// \namespace tbricks
namespace tbricks {

namespace protocol {
class StrategyInstance;
}

/**
 * StrategyUpdate object represents a strategy stream item which is a set of
 * fields changed in a strategy.
 *
 * @see StrategyData
 */
class STRATEGY_EXPORT StrategyUpdate : public Printable
{
public:
    StrategyUpdate & operator=(const StrategyUpdate & update);
    ~StrategyUpdate();

    /**
     * Get strategy creator.
     *
     * If field is not available, returned value is empty.
     *
     * @return                          Field value
     */
    UserIdentifier GetCreator() const;
    bool GetCreator(User & user) const;

    bool HasCreator() const;

    /**
     * Get strategy owner.
     *
     * If field is not available, returned value is empty.
     *
     * @return                          Field value
     */
    UserIdentifier GetOwner() const;
    bool GetOwner(User & user) const;

    bool HasOwner() const;

    /**
     * Get strategy operator
     *
     * If field is not available, returned value is empty.
     *
     * @return                          Field value
     */
    UserIdentifier GetOperator() const;
    bool GetOperator(User & user) const;

    bool HasOperator() const;

    /**
     * Get strategy identifier.
     *
     * Returns unique identifier of the strategy in the system.
     * Strategy identifier is always present in StrategyUpdate instance.
     *
     * @code
     * if (m_currentOS == strategy.GetIdentifier()) {
     *     UpdateChildStrategyState(strategy);
     * }
     * @endcode
     *
     * @return                          System-wide unique strategy identifier
     */
    StrategyIdentifier GetIdentifier() const;

    bool HasIdentifier() const;

    /**
     * Get strategy root identifier.
     *
     * Strategies in the system are organized into inheritance trees, where
     * tree root can currently be instantiated only by external requests, e.g.
     * from the GUI client. For the root strategy, its root identifier is set
     * to strategy's identifier; otherwise, when strategy is created its root
     * identifier is set to inheritance tree root strategy's identifier.
     *
     * For instance, if strategy S1 is created from the outside, its root
     * identifier and root identifiers of all its direct and indirect
     * descendants will be set to S1 strategy identifier.
     *
     * If field is not available, returned value is empty.
     *
     * @return                          Strategy root identifier
     */
    StrategyIdentifier GetRootIdentifier() const;

    bool HasRootIdentifier() const;

    /**
     * Get strategy parent identifier.
     *
     * Strategies in the system are organized into inheritance trees, where
     * tree root can currently be instantiated only by external requests, e.g.
     * from the GUI client. For the root strategy, its parent identifier is set
     * to strategy's identifier; otherwise, when strategy is created its parent
     * identifier is set to the identifier of the strategy create request
     * originator.
     *
     * For instance, if strategy S1 is created from the outside and it created
     * S2 and S3, and S3 created S4, strategies S2 and S3 will have their
     * parent identifiers set to S1, and for S4 it will be S3.
     *
     * If field is not available, returned value is empty.
     *
     * @return                          Strategy parent identifier
     */
    StrategyIdentifier GetParentIdentifier() const;

    bool HasParentIdentifier() const;

    /**
     * Get strategy identifier path.
     *
     * Returns a vector of strategy identifiers that describe the path of
     * strategies used to create this entity starting from the root strategy
     * identifier.
     *
     * @param path                      vector of StrategyIdentifier
     */
    void GetStrategyPath(std::vector<StrategyIdentifier> & path) const;

    /**
     * Get strategy definition identifier path.
     *
     * Returns a vector of strategy definition identifiers that describe the path of
     * strategie types used to create this entity starting from the root strategy
     * definition identifier.
     *
     * @param path                      vector of StrategyIdentifier
     */
    void GetStrategyDefinitionPath(std::vector<StrategyIdentifier> & path) const;

    /**
     * Get strategy type identifier.
     *
     * Returned object uniquely identifies strategy class in a system
     * and can be used, for example, to start a strategy of this type
     * or to subscribe for updates for this strategy type.
     *
     * If field is not available, returned value is empty.
     *
     * @code
     * if (strategy.GetType() == plug_ins::Order()) {
     *     m_myOrderStrategies ++;
     * }
     * @endcode
     *
     * @return                          Strategy type identifier
     */
    StrategyIdentifier GetType() const;

    bool HasType() const;

    /**
     * Get strategy type name.
     *
     * Returns high-level informational type strategy name, e.g.
     * "Order".
     *
     * If field is not available, returned value is empty.
     *
     * @return                          High-level strategy type name
     */
    String GetTypeName() const;

    bool HasTypeName() const;

    /**
     * Get strategy service instance identifier.
     *
     * Returned object uniquely identifies service instance in a system
     * and can be used, for example, to subscribe for updates for this service.
     *
     * If field is not available, returned value is empty.
     *
     *
     * @return                          Service instance identifier
     */
    ServiceIdentifier GetService() const;

    bool HasService() const;

    /**
     * Get strategy name.
     *
     * Returns high-level informational strategy name, e.g.
     * "Tbricks Built-in Order Strategy".
     *
     * If field is not available, returned value is empty.
     *
     * @return                          High-level strategy name
     */
    String GetName() const;

    bool HasName() const;

    /**
     * Get strategy validity.
     *
     * @see Validity
     *
     * @return                          Validity
     */
    Validity GetValidity() const;

    /**
     * Get current strategy state.
     *
     * If field is not available, returned value is empty.
     *
     * @see StrategyState
     *
     * @return                          Current strategy state
     */
    StrategyState GetState() const;

    bool HasState() const;

    /**
     * Get strategy transaction state.
     *
     * If field is not available, returned value is empty.
     *
     * @see TransactionState
     *
     * @return                          Current strategy transaction state
     */
    TransactionState GetTransactionState() const;

    bool HasTransactionState() const;

    /**
     * Get operation the strategy is working on.
     *
     * If field is not available, returned value is empty.
     *
     * @see StrategyTransactionOperation
     *
     * @return                          Operation the strategy is working on
     */
    StrategyTransactionOperation GetTransactionOperation() const;

    bool HasTransactionOperation() const;

    /**
     * Get strategy status text.
     *
     * Method is only meningful for strategy updates with indication of
     * transaction failure, an empty string is returned otherwise.
     *
     * If field is not available, returned value is empty.
     *
     * @code
     * if (strategy.GetTransactionState() == TransactionState::FAIL) {
     *     TBERROR(strategy.GetStatusText());
     * }
     * @endcode
     *
     * @return                          Failure reason if there is a failure,
     *                                  an empty string otherwise
     */
    String GetStatusText() const;

    bool HasStatusText() const;

    /**
     * Get strategy parameters.
     *
     * @return                          Strategy parameter container.
     */
    const StrategyParameters & GetParameters() const;

    bool HasParameters() const;

    /**
     * Get strategy associated instruments.
     *
     * Returns a vector of instrument identifiers a strategy is known or reports
     * to support.
     *
     * If field value is not present, argument is cleared.
     *
     * @param instruments              Vector of associated instruments
     */
    void GetInstruments(std::vector<InstrumentIdentifier> & instruments) const;

    bool HasInstrument(const InstrumentIdentifier & instrument) const;

    /**
     * Get user data.
     *
     * @return                          User data container
     */
    const ExtraData & GetExtraData() const;

    bool HasExtraData() const;

    /**
     * Get forward parameters which should be passed to venue alongside with an order.
     * Used to represent additional parameters for algo orders available on
     * FIX venues or on Tbricks Matching Engine.
     *
     * @return                          Forward parameters
     */
    StrategyParameters GetForwardParameters() const;

    bool HasForwardParameters() const;

    RegulatoryParameters GetRegulatoryParameters() const;

    bool HasRegulatoryParameters() const;

    /**
     * Get time of last strategy modification.
     *
     * If field is not present, returned value is empty.
     *
     * @return                          Time of last strategy modification
     */
    DateTime GetCreationTime() const;

    bool HasCreationTime() const;

    /**
     * Get time of last strategy modification.
     *
     * If field is not present, returned value is empty.
     *
     * @return                          Time of last strategy modification
     */
    DateTime GetLastModificationTime() const;

    /**
     * Get datetime of last modification.
     *
     * Returns datetime of last modification.
     *
     * @return                          Modified datetime
     */
    DateTime GetHostModifiedDatetime() const;

    bool HasLastModificationTime() const;

    /**
     * Get strategy/instrument associations.
     *
     * If there are no associations (field is not present), and empty
     * container is returned.
     *
     * @return                          Association container
     */
    const StrategyInstruments & GetInstruments() const;

    bool HasInstruments() const;

    /**
     * Get strategy priority.
     *
     * If field is not present, result is empty.
     *
     * @see Strategy::SetPriority
     * @see Strategy::GetPriority
     *
     * @return                          Strategy priority
     */
    Integer GetPriority() const;
    bool HasPriority() const;

    /**
     * Get request identifier
     *
     * @return                          RequestIdentifier
     */
    Identifier GetRequestIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasRequestIdentifier() const;

    /**
     * Get warmup option.
     *
     * @return                          Warmup option
     */
    bool GetWarmup() const;

    /**
     * Get visible child attribute
     *
     * @return true if strategy has visible childs
     */
    Boolean GetStrategyHasVisibleChild() const;

    /**
     * Check if visible child field is set.
     *
     * @return "true" if field is set, "false"
     *         otherwise
     */
    bool HasStrategyHasVisibleChild() const;

    /**
     * Get active child attribute
     *
     * @return true if strategy has active childs
     */
    Boolean GetStrategyHasActiveChild() const;

    /**
     * Check if active child field is set.
     *
     * @return "true" if field is set, "false"
     *         otherwise
     */
    bool HasStrategyHasActiveChild() const;

    TradingLimitState GetTradingLimitState() const;
    bool HasTradingLimitState() const;
    bool HasTradingLimitResult() const;
    bool GetTradingLimitResult(TradingLimitResult & result) const;

    /// @deprecated Deprecated in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] Boolean GetLimitBreach() const;

    /// @deprecated Deprecated in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] bool HasLimitBreach() const;

    /// @deprecated Deprecated in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] bool GetLimitBreach(bool & limit_breach) const;

    Boolean GetThroughputLimitBreached() const;
    bool HasThroughputLimitBreached() const;
    bool GetThroughputLimitBreached(bool & limit_breach) const;

    bool GetAttributes(StrategyAttributes & attributes) const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

    tbricks::protocol::StrategyInstance & GetValue() const;
    bool HasValue() const;

    StrategyUpdate(tbricks::protocol::StrategyInstance * message);

protected:
    StrategyUpdate();
    void Reuse(tbricks::protocol::StrategyInstance * message);

private:
    // other create/assign operators are prohibited
    StrategyUpdate(const StrategyUpdate &);

    void parse_message();

private:
    tbricks::protocol::StrategyInstance * m_message;

    ExtraData m_extra_data;

    StrategyParameters m_parameters;
    StrategyInstruments m_instruments;
};
}

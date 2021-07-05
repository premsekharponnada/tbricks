#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyData, convenience container for caching of data received in
// StrategyData objects through strategy streams.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/ExtraData.h"
#include "strategy/StrategyUpdate.h"
#include "strategy/StrategyInstruments.h"
#include "strategy/parameter/StrategyParameters.h"
#include "strategy/StrategyAttributes.h"

// \namespace tbricks
namespace tbricks {

namespace protocol {
class StrategyInstance;
}

/**
 * StrategyData object is used to cache incoming strategy updates when
 * needed.
 *
 * @code
 * class MyStrategy
 * {
 * public:
 *     // ...
 * private:
 *     Hash<StrategyIdentifier, StrategyData> m_strategies;
 * };
 *
 * void MyStrategy::HandleStrategyUpdate(
 *                      const StreamIdentifier & stream_id,
 *                      const StrategyUpdate   & update)
 * {
 *     // merge in strategy update first
 *     m_strategies[update.GetIdentifier()].Merge(update);
 *
 *     // perform field analysis
 *     if (m_strategies[update.GetIdentifier()].GetState()
 *                  == StrategyState::RUNNING) {
 *         // strategy is runnning
 *     }
 *
 *     // ...
 * }
 * @endcode
 */
class STRATEGY_EXPORT StrategyData : public Printable
{
public:
    StrategyData();
    StrategyData(const StrategyIdentifier & strategy_id);
    StrategyData(const StrategyData & data);
    StrategyData(tbricks::protocol::StrategyInstance & si);
    StrategyData(const StrategyUpdate & update);
    StrategyData & operator=(const StrategyData & data);

    ~StrategyData();

    /**
     * Comparison operator.
     *
     * Two strategy objects are said to be equal if their strategy identifiers
     * are equal, or, in other words, they refer to the same strategy instance.
     *
     * Note that two instances may be different -- user code derived from
     * strategy and an update for this strategy received over a stream will be
     * equal (strategy identifiers are equal), but they may well have different
     * set of parameters, or have different state etc.
     *
     * @return                          "true" if objects refer to the same
     *                                  strategy instance, "false" otherwise
     */
    bool operator==(const StrategyData & data) const;
    bool operator==(const StrategyUpdate & update) const;

    /**
     * Comparison operator.
     *
     * Two strategy objects are said to be unequal if their strategy
     * identifiers are not equal, or, in other words, they do not refer to the
     * same strategy instance.
     *
     * @return                          "false" if objects refer to the same
     *                                  strategy instance, "true" otherwise
     */
    bool operator!=(const StrategyData & data) const;
    bool operator!=(const StrategyUpdate & update) const;

    /**
     * Comparison operator.
     *
     * This operator numerically compares object identifiers, and is available
     * to support STL std::set<> container.
     *
     * @return                          "true" if current object's identifier
     *                                  is numerically less than argument's one,
     *                                  false otherwise
     */
    bool operator<(const StrategyData & update) const;

    /**
     * Get strategy creator.
     *
     * If field is not available, returned value is empty.
     *
     * @return                          Field value
     */
    UserIdentifier GetCreator() const;

    /**
     * Get strategy owner.
     *
     * If field is not available, returned value is empty.
     *
     * @return                          Field value
     */
    UserIdentifier GetOwner() const;

    /**
     * Get strategy identifier.
     *
     * Returns unique identifier of the strategy in the system.
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

    /**
     * Get strategy state.
     *
     * If field is not available, returned value is empty.
     *
     * @see StrategyState
     *
     * @return                          Current strategy state
     */
    StrategyState GetState() const;

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

    /**
     * Get strategy status text.
     *
     * Method is only meningful for strategy updates with indication of
     * transaction failure, an empty string is returned otherwise.
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

    /**
     * Get strategy parameters.
     *
     * If field is not available, returned container is empty.
     *
     * @return                          Strategy parameter container.
     */
    const StrategyParameters & GetParameters() const;

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

    /**
     * Get strategy validity.
     *
     * @return                          Current strategy validity value,
     *                                  or an empty object if it is not set
     */
    Validity GetValidity() const;

    /**
     * Get user data.
     *
     * @return                          User data container
     */
    const ExtraData & GetExtraData() const;

    /**
     * Get strategy creation time.
     *
     * If field is not present, returned value is empty.
     *
     * @return                          Time when strategy was created
     */
    DateTime GetCreationTime() const;

    /**
     * Get time of last strategy modification.
     *
     * If field is not present, returned value is empty.
     *
     * @return                          Time of last strategy modification
     */
    DateTime GetLastModificationTime() const;

    /**
     * Get strategy/instrument associations.
     *
     * If there are no associations (field is not present), and empty
     * container is returned.
     *
     * @return                          Association container
     */
    const StrategyInstruments & GetInstruments() const;

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

    TradingLimitState GetTradingLimitState() const;
    bool HasTradingLimitResult() const;
    bool GetTradingLimitResult(TradingLimitResult & result) const;

    bool GetAttributes(StrategyAttributes & attributes) const;

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

    /**
     * Get visible child attribute
     *
     * @return true if strategy has visible childs
     */
    Boolean GetStrategyHasVisibleChild() const;

    /**
     * Get active child attribute
     *
     * @return true if strategy has active childs
     */
    Boolean GetStrategyHasActiveChild() const;

    /**
     * Merge data from extern source.
     *
     * Object fields are updated from the argument, old values (if any) are
     * replaced.
     *
     * Method only fails when both source and target objects have their
     * identifier set, and identifiers are not equal. If this is the case, the
     * method throws an exception.
     *
     * @param data                     Data source
     * @return                         "true" if merge succeeded, "false"
     *                                 otherwise
     */
    void Merge(const StrategyData & data);

    /**
     * Merge data from extern source.
     *
     * Object fields are updated from the argument, old values (if any) are
     * replaced.
     *
     * Method only fails when both source and target objects have their
     * identifier set, and identifiers are not equal. If this is the case, the
     * method throws an exception.
     *
     * @param update                   Data source
     * @return                         "true" if merge succeeded, "false"
     *                                 otherwise
     */
    void Merge(const StrategyUpdate & update);

    /**
     * Check object for emptiness.
     *
     * @return                          Returns true if no fields are set
     */
    bool Empty() const;

    /**
     * Clear object value.
     *
     * After this operation, all field values are cleared, and Empty()
     * method will return "true".
     */
    void Clear();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    tbricks::protocol::StrategyInstance & GetValue() const;

private:
    void parse_message();

private:
    bool m_alloc;
    tbricks::protocol::StrategyInstance * m_message;
    StrategyUpdate m_update;
};
}

#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExPitBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/ExPitUpdateBase.h"


#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class DateTime;
class DirectedQuoteRequestIdentifier;
class ExPitIdentifier;
class Integer;
class RequestForTradeIdentifier;
class StrategyIdentifier;
class String;
class TransactionState;
class TreeNodeIdentifier;
class UserIdentifier;


namespace protocol { class Expit; }

class STRATEGY_EXPORT ExPitBase : public Printable
{
protected:
    ExPitBase();
    ExPitBase(const ExPitBase & value);
    ExPitBase(ExPitBase && value) noexcept;
    ExPitBase & operator=(const ExPitBase & value);
    ExPitBase & operator=(ExPitBase && value) noexcept;
    virtual ~ExPitBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAlgoLabel() const;

    /**
     * Get algo label.
     *
     *
     * @return                          algo label
     */
    Integer GetAlgoLabel() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCreator() const;

    /**
     * Get creator.
     *
     *
     * @return                          creator
     */
    UserIdentifier GetCreator() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeleted() const;

    /**
     * Get deleted.
     *
     *
     * @return                          deleted
     */
    Boolean GetDeleted() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeClientIdentifier() const;

    /**
     * Get exchange client expit reference.
     *
     *
     * @return                          exchange client expit reference
     */
    String GetExchangeClientIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeReference() const;

    /**
     * Get exchange expit reference.
     *
     *
     * @return                          exchange expit reference
     */
    String GetExchangeReference() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get expit identifier.
     *
     *
     * @return                          expit identifier
     */
    ExPitIdentifier GetIdentifier() const;

    /**
     * Get expit identifier.
     *
     *
     * @return                          expit identifier
     */
    ExPitIdentifier GetExPitIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPackageIdentifier() const;

    /**
     * Get expit package identifier.
     *
     *
     * @return                          expit package identifier
     */
    String GetPackageIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTransactionState() const;

    /**
     * Get expit transaction state.
     *
     *
     * @return                          expit transaction state
     */
    TransactionState GetTransactionState() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandler() const;

    /**
     * Get handler.
     *
     *
     * @return                          handler
     */
    TreeNodeIdentifier GetHandler() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostCreatedDatetime() const;

    /**
     * Get host created datetime.
     *
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDatetime() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostModifiedDatetime() const;

    /**
     * Get host modified datetime.
     *
     *
     * @return                          host modified datetime
     */
    DateTime GetHostModifiedDatetime() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMatchingCode() const;

    /**
     * Get matching code.
     *
     *
     * @return                          matching code
     */
    String GetMatchingCode() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOwner() const;

    /**
     * Get owner.
     *
     *
     * @return                          owner
     */
    UserIdentifier GetOwner() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParentStrategyIdentifier() const;

    /**
     * Get parent strategy identifier.
     *
     *
     * @return                          parent strategy identifier
     */
    StrategyIdentifier GetParentStrategyIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRootStrategyIdentifier() const;

    /**
     * Get root strategy identifier.
     *
     *
     * @return                          root strategy identifier
     */
    StrategyIdentifier GetRootStrategyIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStatusText() const;

    /**
     * Get status text.
     *
     *
     * @return                          status text
     */
    String GetStatusText() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestForTradeIdentifier() const;

    /**
     * Get request for trade identifier.
     *
     *
     * @return                          request for trade identifier
     */
    RequestForTradeIdentifier GetRequestForTradeIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteRequestIdentifier() const;

    /**
     * Get quote request identifier.
     *
     *
     * @return                          quote request identifier
     */
    DirectedQuoteRequestIdentifier GetDirectedQuoteRequestIdentifier() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const ExPitUpdateBase & update);

/** @cond PRIVATE */
public:
    ExPitBase(const protocol::Expit & value);
    ExPitBase(std::shared_ptr<protocol::Expit> && value);

    std::shared_ptr<protocol::Expit> & get_impl_wr() const;
    const std::shared_ptr<protocol::Expit> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Expit> m_impl;
};

}

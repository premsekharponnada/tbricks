#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingBlockUpdateBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class DateTime;
class Identifier;
class StrategyIdentifier;
class String;
class TradingBlockCondition;
class UserIdentifier;


namespace protocol { class TradingBlock; }

class STRATEGY_EXPORT TradingBlockUpdateBase : public Printable
{
protected:
    TradingBlockUpdateBase();
    TradingBlockUpdateBase(const TradingBlockUpdateBase & value);
    TradingBlockUpdateBase(TradingBlockUpdateBase && value) noexcept;
    TradingBlockUpdateBase & operator=(const TradingBlockUpdateBase & value);
    TradingBlockUpdateBase & operator=(TradingBlockUpdateBase && value) noexcept;
    virtual ~TradingBlockUpdateBase();

public:
    /**
     * Get trading block identifier.
     *
     *
     * @return                          trading block identifier
     */
    Identifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCondition() const;

    /**
     * Get trading block condition.
     *
     *
     * @return                          trading block condition
     */
    TradingBlockCondition GetCondition() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSoft() const;

    /**
     * Get soft.
     *
     *
     * @return                          soft
     */
    Boolean GetSoft() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComment() const;

    /**
     * Get comment.
     *
     *
     * @return                          comment
     */
    String GetComment() const;

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
    bool HasOperator() const;

    /**
     * Get operator.
     *
     *
     * @return                          operator
     */
    UserIdentifier GetOperator() const;

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
    bool HasAppPath() const;

    /**
     * Get strategy identifier path.
     *
     *
     * @return                          strategy identifier path
     */
    std::vector<StrategyIdentifier> GetAppPath() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAppDefinitionPath() const;

    /**
     * Get strategy definition identifier path.
     *
     *
     * @return                          strategy definition identifier path
     */
    std::vector<StrategyIdentifier> GetAppDefinitionPath() const;

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    TradingBlockUpdateBase(const protocol::TradingBlock & value);
    TradingBlockUpdateBase(std::shared_ptr<protocol::TradingBlock> && value);

    std::shared_ptr<protocol::TradingBlock> & get_impl_wr() const;
    const std::shared_ptr<protocol::TradingBlock> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::TradingBlock> m_impl;
};

}

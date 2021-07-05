#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExpirationBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/ExpirationUpdateBase.h"


#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class DateTime;
class Identifier;
class Integer;
class StrategyIdentifier;
class String;
class UserIdentifier;


namespace protocol { class Expiration2; }

class STRATEGY_EXPORT ExpirationBase : public Printable
{
protected:
    ExpirationBase();
    ExpirationBase(const ExpirationBase & value);
    ExpirationBase(ExpirationBase && value) noexcept;
    ExpirationBase & operator=(const ExpirationBase & value);
    ExpirationBase & operator=(ExpirationBase && value) noexcept;
    virtual ~ExpirationBase();

public:
    /**
     * Get expiration identifier.
     *
     *
     * @return                          expiration identifier
     */
    Identifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestIdentifier() const;

    /**
     * Get request identifier.
     *
     *
     * @return                          request identifier
     */
    Identifier GetRequestIdentifier() const;

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
    bool HasExpirationSet() const;

    /**
     * Get expiration set.
     *
     *
     * @return                          expiration set
     */
    Integer GetExpirationSet() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExpirationDate() const;

    /**
     * Get expiration date.
     *
     *
     * @return                          expiration date
     */
    DateTime GetExpirationDate() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyIdentifier() const;

    /**
     * Get strategy identifier.
     *
     *
     * @return                          strategy identifier
     */
    StrategyIdentifier GetStrategyIdentifier() const;

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
    bool HasComment() const;

    /**
     * Get comment.
     *
     *
     * @return                          comment
     */
    String GetComment() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const ExpirationUpdateBase & update);

/** @cond PRIVATE */
public:
    ExpirationBase(const protocol::Expiration2 & value);
    ExpirationBase(std::shared_ptr<protocol::Expiration2> && value);

    std::shared_ptr<protocol::Expiration2> & get_impl_wr() const;
    const std::shared_ptr<protocol::Expiration2> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Expiration2> m_impl;
};

}

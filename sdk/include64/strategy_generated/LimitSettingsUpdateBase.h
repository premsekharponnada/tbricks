#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// LimitSettingsUpdateBase object
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
class LimitSettingsParameters;
class StrategyIdentifier;
class UserIdentifier;


namespace protocol { class LimitSettings; }

class STRATEGY_EXPORT LimitSettingsUpdateBase : public Printable
{
protected:
    LimitSettingsUpdateBase();
    LimitSettingsUpdateBase(const LimitSettingsUpdateBase & value);
    LimitSettingsUpdateBase(LimitSettingsUpdateBase && value) noexcept;
    LimitSettingsUpdateBase & operator=(const LimitSettingsUpdateBase & value);
    LimitSettingsUpdateBase & operator=(LimitSettingsUpdateBase && value) noexcept;
    virtual ~LimitSettingsUpdateBase();

public:
    /**
     * Get limit identifier.
     *
     *
     * @return                          limit identifier
     */
    Identifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParentIdentifier() const;

    /**
     * Get parent limit identifier.
     *
     *
     * @return                          parent limit identifier
     */
    Identifier GetParentIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParameters() const;

    /**
     * Get limit settings parameters.
     *
     *
     * @return                          limit settings parameters
     */
    LimitSettingsParameters GetParameters() const;

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
    bool HasOperatingServiceInstanceIdentifier() const;

    /**
     * Get operating service instance identifier.
     *
     *
     * @return                          operating service instance identifier
     */
    Identifier GetOperatingServiceInstanceIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOperatingStrategyIdentifier() const;

    /**
     * Get operating strategy identifier.
     *
     *
     * @return                          operating strategy identifier
     */
    StrategyIdentifier GetOperatingStrategyIdentifier() const;

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    LimitSettingsUpdateBase(const protocol::LimitSettings & value);
    LimitSettingsUpdateBase(std::shared_ptr<protocol::LimitSettings> && value);

    std::shared_ptr<protocol::LimitSettings> & get_impl_wr() const;
    const std::shared_ptr<protocol::LimitSettings> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::LimitSettings> m_impl;
};

}

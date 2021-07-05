#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentGroupParametersUpdateBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class DateTime;
class ServiceIdentifier;
class StrategyIdentifier;
class UserIdentifier;


namespace protocol { class InstrumentGroupParameters; }

class STRATEGY_EXPORT InstrumentGroupParametersUpdateBase : public Printable
{
protected:
    InstrumentGroupParametersUpdateBase();
    InstrumentGroupParametersUpdateBase(const InstrumentGroupParametersUpdateBase & value);
    InstrumentGroupParametersUpdateBase(InstrumentGroupParametersUpdateBase && value) noexcept;
    InstrumentGroupParametersUpdateBase & operator=(const InstrumentGroupParametersUpdateBase & value);
    InstrumentGroupParametersUpdateBase & operator=(InstrumentGroupParametersUpdateBase && value) noexcept;
    virtual ~InstrumentGroupParametersUpdateBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostCreatedDateTime() const;

    /**
     * Get host created datetime.
     *
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDateTime() const;

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
    bool HasOperatingServiceInstanceIdentifier() const;

    /**
     * Get operating service instance identifier.
     *
     *
     * @return                          operating service instance identifier
     */
    ServiceIdentifier GetOperatingServiceInstanceIdentifier() const;

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    InstrumentGroupParametersUpdateBase(const protocol::InstrumentGroupParameters & value);
    InstrumentGroupParametersUpdateBase(std::shared_ptr<protocol::InstrumentGroupParameters> && value);

    std::shared_ptr<protocol::InstrumentGroupParameters> & get_impl_wr() const;
    const std::shared_ptr<protocol::InstrumentGroupParameters> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::InstrumentGroupParameters> m_impl;
};

}

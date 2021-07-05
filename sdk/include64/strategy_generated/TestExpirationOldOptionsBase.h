#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestExpirationOldOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class DateTime;
class Identifier;
class StrategyIdentifier;
class UserIdentifier;


namespace protocol { class Expiration; }

class STRATEGY_EXPORT TestExpirationOldOptionsBase : public Printable
{
protected:
    TestExpirationOldOptionsBase();
    TestExpirationOldOptionsBase(const TestExpirationOldOptionsBase & value);
    TestExpirationOldOptionsBase(TestExpirationOldOptionsBase && value) noexcept;
    TestExpirationOldOptionsBase & operator=(const TestExpirationOldOptionsBase & value);
    TestExpirationOldOptionsBase & operator=(TestExpirationOldOptionsBase && value) noexcept;
    virtual ~TestExpirationOldOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get expiration identifier.
     *
     *
     * @return                          expiration identifier
     */
    Identifier GetIdentifier() const;

    /**
     * %Set expiration identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expiration identifier
     */
    void SetIdentifier(const Identifier & value);

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
     * %Set request identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     request identifier
     */
    void SetRequestIdentifier(const Identifier & value);

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
     * %Set creator.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     creator
     */
    void SetCreator(const UserIdentifier & value);

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
     * %Set strategy identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     strategy identifier
     */
    void SetStrategyIdentifier(const StrategyIdentifier & value);

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
     * %Set host created datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host created datetime
     */
    void SetHostCreatedDatetime(const DateTime & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const TestExpirationOldOptionsBase & update);

/** @cond PRIVATE */
public:
    TestExpirationOldOptionsBase(const protocol::Expiration & value);
    TestExpirationOldOptionsBase(std::shared_ptr<protocol::Expiration> && value);

    std::shared_ptr<protocol::Expiration> & get_impl_wr() const;
    const std::shared_ptr<protocol::Expiration> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Expiration> m_impl;
};

}

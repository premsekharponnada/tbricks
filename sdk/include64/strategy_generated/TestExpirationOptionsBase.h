#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestExpirationOptionsBase object
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
class Integer;
class StrategyIdentifier;
class String;
class UserIdentifier;


namespace protocol { class Expiration2; }

class STRATEGY_EXPORT TestExpirationOptionsBase : public Printable
{
protected:
    TestExpirationOptionsBase();
    TestExpirationOptionsBase(const TestExpirationOptionsBase & value);
    TestExpirationOptionsBase(TestExpirationOptionsBase && value) noexcept;
    TestExpirationOptionsBase & operator=(const TestExpirationOptionsBase & value);
    TestExpirationOptionsBase & operator=(TestExpirationOptionsBase && value) noexcept;
    virtual ~TestExpirationOptionsBase();

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
    bool HasDeleted() const;

    /**
     * Get deleted.
     *
     *
     * @return                          deleted
     */
    Boolean GetDeleted() const;

    /**
     * %Set deleted.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     deleted
     */
    void SetDeleted(const Boolean & value);

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
     * %Set expiration set.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expiration set
     */
    void SetExpirationSet(const Integer & value);

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
     * %Set expiration date.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expiration date
     */
    void SetExpirationDate(const DateTime & value);

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
     * %Set host modified datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host modified datetime
     */
    void SetHostModifiedDatetime(const DateTime & value);

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
     * %Set comment.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     comment
     */
    void SetComment(const String & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const TestExpirationOptionsBase & update);

/** @cond PRIVATE */
public:
    TestExpirationOptionsBase(const protocol::Expiration2 & value);
    TestExpirationOptionsBase(std::shared_ptr<protocol::Expiration2> && value);

    std::shared_ptr<protocol::Expiration2> & get_impl_wr() const;
    const std::shared_ptr<protocol::Expiration2> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Expiration2> m_impl;
};

}

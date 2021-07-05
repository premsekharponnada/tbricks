#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestExpirationOldOperationBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Identifier;


namespace protocol { class ExpirationResetRequest; }

class STRATEGY_EXPORT TestExpirationOldOperationBase : public Printable
{
protected:
    TestExpirationOldOperationBase();
    TestExpirationOldOperationBase(const TestExpirationOldOperationBase & value);
    TestExpirationOldOperationBase(TestExpirationOldOperationBase && value) noexcept;
    TestExpirationOldOperationBase & operator=(const TestExpirationOldOperationBase & value);
    TestExpirationOldOperationBase & operator=(TestExpirationOldOperationBase && value) noexcept;
    virtual ~TestExpirationOldOperationBase();

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    TestExpirationOldOperationBase(const protocol::ExpirationResetRequest & value);
    TestExpirationOldOperationBase(std::shared_ptr<protocol::ExpirationResetRequest> && value);

    std::shared_ptr<protocol::ExpirationResetRequest> & get_impl_wr() const;
    const std::shared_ptr<protocol::ExpirationResetRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::ExpirationResetRequest> m_impl;
};

}

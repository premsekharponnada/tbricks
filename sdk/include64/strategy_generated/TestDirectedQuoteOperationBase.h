#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestDirectedQuoteOperationBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class DirectedQuoteIdentifier;
class Identifier;


namespace protocol { class DirectedQuoteDeleteRequest; }

class STRATEGY_EXPORT TestDirectedQuoteOperationBase : public Printable
{
protected:
    TestDirectedQuoteOperationBase();
    TestDirectedQuoteOperationBase(const TestDirectedQuoteOperationBase & value);
    TestDirectedQuoteOperationBase(TestDirectedQuoteOperationBase && value) noexcept;
    TestDirectedQuoteOperationBase & operator=(const TestDirectedQuoteOperationBase & value);
    TestDirectedQuoteOperationBase & operator=(TestDirectedQuoteOperationBase && value) noexcept;
    virtual ~TestDirectedQuoteOperationBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteIdentifier() const;

    /**
     * Get directed quote identifier.
     *
     *
     * @return                          directed quote identifier
     */
    DirectedQuoteIdentifier GetDirectedQuoteIdentifier() const;

    /**
     * %Set directed quote identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     directed quote identifier
     */
    void SetDirectedQuoteIdentifier(const DirectedQuoteIdentifier & value);

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
    TestDirectedQuoteOperationBase(const protocol::DirectedQuoteDeleteRequest & value);
    TestDirectedQuoteOperationBase(std::shared_ptr<protocol::DirectedQuoteDeleteRequest> && value);

    std::shared_ptr<protocol::DirectedQuoteDeleteRequest> & get_impl_wr() const;
    const std::shared_ptr<protocol::DirectedQuoteDeleteRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::DirectedQuoteDeleteRequest> m_impl;
};

}

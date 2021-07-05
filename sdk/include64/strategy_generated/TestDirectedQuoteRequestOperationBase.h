#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestDirectedQuoteRequestOperationBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class DirectedQuoteRequestIdentifier;
class Identifier;


namespace protocol { class DirectedQuoteRequestDeleteRequest; }

class STRATEGY_EXPORT TestDirectedQuoteRequestOperationBase : public Printable
{
protected:
    TestDirectedQuoteRequestOperationBase();
    TestDirectedQuoteRequestOperationBase(const TestDirectedQuoteRequestOperationBase & value);
    TestDirectedQuoteRequestOperationBase(TestDirectedQuoteRequestOperationBase && value) noexcept;
    TestDirectedQuoteRequestOperationBase & operator=(const TestDirectedQuoteRequestOperationBase & value);
    TestDirectedQuoteRequestOperationBase & operator=(TestDirectedQuoteRequestOperationBase && value) noexcept;
    virtual ~TestDirectedQuoteRequestOperationBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get quote request identifier.
     *
     *
     * @return                          quote request identifier
     */
    DirectedQuoteRequestIdentifier GetIdentifier() const;

    /**
     * %Set quote request identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote request identifier
     */
    void SetIdentifier(const DirectedQuoteRequestIdentifier & value);

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
    TestDirectedQuoteRequestOperationBase(const protocol::DirectedQuoteRequestDeleteRequest & value);
    TestDirectedQuoteRequestOperationBase(std::shared_ptr<protocol::DirectedQuoteRequestDeleteRequest> && value);

    std::shared_ptr<protocol::DirectedQuoteRequestDeleteRequest> & get_impl_wr() const;
    const std::shared_ptr<protocol::DirectedQuoteRequestDeleteRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::DirectedQuoteRequestDeleteRequest> m_impl;
};

}

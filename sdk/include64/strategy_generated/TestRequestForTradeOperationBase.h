#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestRequestForTradeOperationBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class ExPitIdentifier;
class Identifier;
class RequestForTradeIdentifier;


namespace protocol { class RequestForTrade; }

class STRATEGY_EXPORT TestRequestForTradeOperationBase : public Printable
{
protected:
    TestRequestForTradeOperationBase();
    TestRequestForTradeOperationBase(const TestRequestForTradeOperationBase & value);
    TestRequestForTradeOperationBase(TestRequestForTradeOperationBase && value) noexcept;
    TestRequestForTradeOperationBase & operator=(const TestRequestForTradeOperationBase & value);
    TestRequestForTradeOperationBase & operator=(TestRequestForTradeOperationBase && value) noexcept;
    virtual ~TestRequestForTradeOperationBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExPitIdentifier() const;

    /**
     * Get expit identifier.
     *
     *
     * @return                          expit identifier
     */
    ExPitIdentifier GetExPitIdentifier() const;

    /**
     * %Set expit identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expit identifier
     */
    void SetExPitIdentifier(const ExPitIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get stream item identifier.
     *
     *
     * @return                          stream item identifier
     */
    Identifier GetIdentifier() const;

    /**
     * %Set stream item identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     stream item identifier
     */
    void SetIdentifier(const Identifier & value);

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
     * %Set request for trade identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     request for trade identifier
     */
    void SetRequestForTradeIdentifier(const RequestForTradeIdentifier & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    TestRequestForTradeOperationBase(const protocol::RequestForTrade & value);
    TestRequestForTradeOperationBase(std::shared_ptr<protocol::RequestForTrade> && value);

    std::shared_ptr<protocol::RequestForTrade> & get_impl_wr() const;
    const std::shared_ptr<protocol::RequestForTrade> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::RequestForTrade> m_impl;
};

}

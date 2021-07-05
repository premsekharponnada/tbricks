#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestRequestForQuoteOperationBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Identifier;


namespace protocol { class StreamItemInvalid; }

class STRATEGY_EXPORT TestRequestForQuoteOperationBase : public Printable
{
protected:
    TestRequestForQuoteOperationBase();
    TestRequestForQuoteOperationBase(const TestRequestForQuoteOperationBase & value);
    TestRequestForQuoteOperationBase(TestRequestForQuoteOperationBase && value) noexcept;
    TestRequestForQuoteOperationBase & operator=(const TestRequestForQuoteOperationBase & value);
    TestRequestForQuoteOperationBase & operator=(TestRequestForQuoteOperationBase && value) noexcept;
    virtual ~TestRequestForQuoteOperationBase();

public:
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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    TestRequestForQuoteOperationBase(const protocol::StreamItemInvalid & value);
    TestRequestForQuoteOperationBase(std::shared_ptr<protocol::StreamItemInvalid> && value);

    std::shared_ptr<protocol::StreamItemInvalid> & get_impl_wr() const;
    const std::shared_ptr<protocol::StreamItemInvalid> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::StreamItemInvalid> m_impl;
};

}

#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestQuoteBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Identifier;


namespace protocol { class Quote; }

class STRATEGY_EXPORT TestQuoteBase : public Printable
{
protected:
    TestQuoteBase();
    TestQuoteBase(const TestQuoteBase & value);
    TestQuoteBase(TestQuoteBase && value) noexcept;
    TestQuoteBase & operator=(const TestQuoteBase & value);
    TestQuoteBase & operator=(TestQuoteBase && value) noexcept;
    virtual ~TestQuoteBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasQuoteSetIdentifier() const;

    /**
     * Get quote set identifier.
     *
     *
     * @return                          quote set identifier
     */
    Identifier GetQuoteSetIdentifier() const;

    /**
     * %Set quote set identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote set identifier
     */
    void SetQuoteSetIdentifier(const Identifier & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const TestQuoteBase & update);

/** @cond PRIVATE */
public:
    TestQuoteBase(const protocol::Quote & value);
    TestQuoteBase(std::shared_ptr<protocol::Quote> && value);

    std::shared_ptr<protocol::Quote> & get_impl_wr() const;
    const std::shared_ptr<protocol::Quote> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Quote> m_impl;
};

}

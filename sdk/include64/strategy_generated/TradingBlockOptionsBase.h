#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingBlockOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class String;
class TradingBlockCondition;


namespace protocol { class TradingBlockAddRequest; }

class STRATEGY_EXPORT TradingBlockOptionsBase : public Printable
{
protected:
    TradingBlockOptionsBase();
    TradingBlockOptionsBase(const TradingBlockOptionsBase & value);
    TradingBlockOptionsBase(TradingBlockOptionsBase && value) noexcept;
    TradingBlockOptionsBase & operator=(const TradingBlockOptionsBase & value);
    TradingBlockOptionsBase & operator=(TradingBlockOptionsBase && value) noexcept;
    virtual ~TradingBlockOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCondition() const;

    /**
     * Get trading block condition.
     *
     *
     * @return                          trading block condition
     */
    TradingBlockCondition GetCondition() const;

    /**
     * %Set trading block condition.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     trading block condition
     */
    void SetCondition(const TradingBlockCondition & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSoft() const;

    /**
     * Get soft.
     *
     *
     * @return                          soft
     */
    Boolean GetSoft() const;

    /**
     * %Set soft.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     soft
     */
    void SetSoft(const Boolean & value);

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


/** @cond PRIVATE */
public:
    TradingBlockOptionsBase(const protocol::TradingBlockAddRequest & value);
    TradingBlockOptionsBase(std::unique_ptr<protocol::TradingBlockAddRequest> && value);

    std::unique_ptr<protocol::TradingBlockAddRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::TradingBlockAddRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::TradingBlockAddRequest> m_impl;
};

}

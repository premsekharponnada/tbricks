#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradingBlockModifierBase object
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


namespace protocol { class TradingBlockModifyRequest; }

class STRATEGY_EXPORT TradingBlockModifierBase : public Printable
{
protected:
    TradingBlockModifierBase();
    TradingBlockModifierBase(const TradingBlockModifierBase & value);
    TradingBlockModifierBase(TradingBlockModifierBase && value) noexcept;
    TradingBlockModifierBase & operator=(const TradingBlockModifierBase & value);
    TradingBlockModifierBase & operator=(TradingBlockModifierBase && value) noexcept;
    virtual ~TradingBlockModifierBase();

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
     * @throw Exception if passed value is empty
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
    TradingBlockModifierBase(const protocol::TradingBlockModifyRequest & value);
    TradingBlockModifierBase(std::unique_ptr<protocol::TradingBlockModifyRequest> && value);

    std::unique_ptr<protocol::TradingBlockModifyRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::TradingBlockModifyRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::TradingBlockModifyRequest> m_impl;
};

}

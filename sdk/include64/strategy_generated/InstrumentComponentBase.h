#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentComponentBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Double;
class InstrumentIdentifier;


namespace protocol { class InstrumentComponent; }

class STRATEGY_EXPORT InstrumentComponentBase : public Printable
{
protected:
    InstrumentComponentBase();
    InstrumentComponentBase(const InstrumentComponentBase & value);
    InstrumentComponentBase(InstrumentComponentBase && value) noexcept;
    InstrumentComponentBase & operator=(const InstrumentComponentBase & value);
    InstrumentComponentBase & operator=(InstrumentComponentBase && value) noexcept;
    virtual ~InstrumentComponentBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInstrumentIdentifier() const;

    /**
     * Get instrument identifier.
     *
     *
     * @return                          instrument identifier
     */
    InstrumentIdentifier GetInstrumentIdentifier() const;

    /**
     * %Set instrument identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     instrument identifier
     */
    void SetInstrumentIdentifier(const InstrumentIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRatio() const;

    /**
     * Get ratio.
     *
     *
     * @return                          ratio
     */
    Double GetRatio() const;

    /**
     * %Set ratio.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     ratio
     */
    void SetRatio(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasUnderlyingPriceLevel() const;

    /**
     * Get underlying price level.
     *
     *
     * @return                          underlying price level
     */
    Double GetUnderlyingPriceLevel() const;

    /**
     * %Set underlying price level.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     underlying price level
     */
    void SetUnderlyingPriceLevel(const Double & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    InstrumentComponentBase(const protocol::InstrumentComponent & value);
    InstrumentComponentBase(std::shared_ptr<protocol::InstrumentComponent> && value);

    std::shared_ptr<protocol::InstrumentComponent> & get_impl_wr() const;
    const std::shared_ptr<protocol::InstrumentComponent> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::InstrumentComponent> m_impl;
};

}

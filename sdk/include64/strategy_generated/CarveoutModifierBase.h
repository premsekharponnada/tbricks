#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CarveoutModifierBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Double;
class Volume;


namespace protocol { class CarveoutModifyRequest; }

class STRATEGY_EXPORT CarveoutModifierBase : public Printable
{
protected:
    CarveoutModifierBase();
    CarveoutModifierBase(const CarveoutModifierBase & value);
    CarveoutModifierBase(CarveoutModifierBase && value) noexcept;
    CarveoutModifierBase & operator=(const CarveoutModifierBase & value);
    CarveoutModifierBase & operator=(CarveoutModifierBase && value) noexcept;
    virtual ~CarveoutModifierBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidTotalVolume() const;

    /**
     * Get bid volume.
     *
     *
     * @return                          bid volume
     */
    Volume GetBidTotalVolume() const;

    /**
     * %Set bid volume.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     bid volume
     */
    void SetBidTotalVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidTotalValue() const;

    /**
     * Get bid value.
     *
     *
     * @return                          bid value
     */
    Double GetBidTotalValue() const;

    /**
     * %Set bid value.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     bid value
     */
    void SetBidTotalValue(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskTotalVolume() const;

    /**
     * Get ask volume.
     *
     *
     * @return                          ask volume
     */
    Volume GetAskTotalVolume() const;

    /**
     * %Set ask volume.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     ask volume
     */
    void SetAskTotalVolume(const Volume & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskTotalValue() const;

    /**
     * Get ask value.
     *
     *
     * @return                          ask value
     */
    Double GetAskTotalValue() const;

    /**
     * %Set ask value.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     ask value
     */
    void SetAskTotalValue(const Double & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    CarveoutModifierBase(const protocol::CarveoutModifyRequest & value);
    CarveoutModifierBase(std::unique_ptr<protocol::CarveoutModifyRequest> && value);

    std::unique_ptr<protocol::CarveoutModifyRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::CarveoutModifyRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::CarveoutModifyRequest> m_impl;
};

}

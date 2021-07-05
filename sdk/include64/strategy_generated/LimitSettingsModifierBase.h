#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// LimitSettingsModifierBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class LimitSettingsParameters;


namespace protocol { class LimitSettingsUpdateRequest; }

class STRATEGY_EXPORT LimitSettingsModifierBase : public Printable
{
protected:
    LimitSettingsModifierBase();
    LimitSettingsModifierBase(const LimitSettingsModifierBase & value);
    LimitSettingsModifierBase(LimitSettingsModifierBase && value) noexcept;
    LimitSettingsModifierBase & operator=(const LimitSettingsModifierBase & value);
    LimitSettingsModifierBase & operator=(LimitSettingsModifierBase && value) noexcept;
    virtual ~LimitSettingsModifierBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParameters() const;

    /**
     * Get limit settings parameters.
     *
     *
     * @return                          limit settings parameters
     */
    LimitSettingsParameters GetParameters() const;

    /**
     * %Set limit settings parameters.
     *
     *    
     *  
     * @param value                     limit settings parameters
     */
    void SetParameters(const LimitSettingsParameters & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeleted() const;

    /**
     * Get deleted.
     *
     *
     * @return                          deleted
     */
    Boolean GetDeleted() const;

    /**
     * %Set deleted.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     deleted
     */
    void SetDeleted(const Boolean & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    LimitSettingsModifierBase(const protocol::LimitSettingsUpdateRequest & value);
    LimitSettingsModifierBase(std::unique_ptr<protocol::LimitSettingsUpdateRequest> && value);

    std::unique_ptr<protocol::LimitSettingsUpdateRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::LimitSettingsUpdateRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::LimitSettingsUpdateRequest> m_impl;
};

}

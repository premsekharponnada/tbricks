#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// LimitSettingsOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Identifier;
class LimitSettingsParameters;


namespace protocol { class LimitSettingsAddRequest; }

class STRATEGY_EXPORT LimitSettingsOptionsBase : public Printable
{
protected:
    LimitSettingsOptionsBase();
    LimitSettingsOptionsBase(const LimitSettingsOptionsBase & value);
    LimitSettingsOptionsBase(LimitSettingsOptionsBase && value) noexcept;
    LimitSettingsOptionsBase & operator=(const LimitSettingsOptionsBase & value);
    LimitSettingsOptionsBase & operator=(LimitSettingsOptionsBase && value) noexcept;
    virtual ~LimitSettingsOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParentIdentifier() const;

    /**
     * Get parent limit identifier.
     *
     *
     * @return                          parent limit identifier
     */
    Identifier GetParentIdentifier() const;

    /**
     * %Set parent limit identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     parent limit identifier
     */
    void SetParentIdentifier(const Identifier & value);

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
     * Delete field from request if field is empty 
     *  
     * @param value                     limit settings parameters
     */
    void SetParameters(const LimitSettingsParameters & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    LimitSettingsOptionsBase(const protocol::LimitSettingsAddRequest & value);
    LimitSettingsOptionsBase(std::unique_ptr<protocol::LimitSettingsAddRequest> && value);

    std::unique_ptr<protocol::LimitSettingsAddRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::LimitSettingsAddRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::LimitSettingsAddRequest> m_impl;
};

}

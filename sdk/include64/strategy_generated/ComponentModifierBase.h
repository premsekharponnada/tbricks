#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ComponentModifierBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class StringDictionary;


namespace protocol { class ComponentUpdateRequest; }

class STRATEGY_EXPORT ComponentModifierBase : public Printable
{
protected:
    ComponentModifierBase();
    ComponentModifierBase(const ComponentModifierBase & value);
    ComponentModifierBase(ComponentModifierBase && value) noexcept;
    ComponentModifierBase & operator=(const ComponentModifierBase & value);
    ComponentModifierBase & operator=(ComponentModifierBase && value) noexcept;
    virtual ~ComponentModifierBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProperties() const;

    /**
     * Get component properties.
     *
     *
     * @return                          component properties
     */
    StringDictionary GetProperties() const;

    /**
     * %Set component properties.
     *
     *    
     *  
     * @param value                     component properties
     */
    void SetProperties(const StringDictionary & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSetOnceProperties() const;

    /**
     * Get setonce component properties.
     *
     *
     * @return                          setonce component properties
     */
    StringDictionary GetSetOnceProperties() const;

    /**
     * %Set setonce component properties.
     *
     *    
     *  
     * @param value                     setonce component properties
     */
    void SetSetOnceProperties(const StringDictionary & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    ComponentModifierBase(const protocol::ComponentUpdateRequest & value);
    ComponentModifierBase(std::unique_ptr<protocol::ComponentUpdateRequest> && value);

    std::unique_ptr<protocol::ComponentUpdateRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::ComponentUpdateRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::ComponentUpdateRequest> m_impl;
};

}

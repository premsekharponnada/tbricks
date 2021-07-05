#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ServiceModifierBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class StringDictionary;


namespace protocol { class ServiceUpdateRequest; }

class STRATEGY_EXPORT ServiceModifierBase : public Printable
{
protected:
    ServiceModifierBase();
    ServiceModifierBase(const ServiceModifierBase & value);
    ServiceModifierBase(ServiceModifierBase && value) noexcept;
    ServiceModifierBase & operator=(const ServiceModifierBase & value);
    ServiceModifierBase & operator=(ServiceModifierBase && value) noexcept;
    virtual ~ServiceModifierBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProperties() const;

    /**
     * Get service properties.
     *
     *
     * @return                          service properties
     */
    StringDictionary GetProperties() const;

    /**
     * %Set service properties.
     *
     *    
     *  
     * @param value                     service properties
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
     * Get setonce service properties.
     *
     *
     * @return                          setonce service properties
     */
    StringDictionary GetSetOnceProperties() const;

    /**
     * %Set setonce service properties.
     *
     *    
     *  
     * @param value                     setonce service properties
     */
    void SetSetOnceProperties(const StringDictionary & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    ServiceModifierBase(const protocol::ServiceUpdateRequest & value);
    ServiceModifierBase(std::unique_ptr<protocol::ServiceUpdateRequest> && value);

    std::unique_ptr<protocol::ServiceUpdateRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::ServiceUpdateRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::ServiceUpdateRequest> m_impl;
};

}

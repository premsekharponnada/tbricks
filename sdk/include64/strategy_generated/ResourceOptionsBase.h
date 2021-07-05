#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ResourceOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class String;


namespace protocol { class ResourceCreateRequest; }

class STRATEGY_EXPORT ResourceOptionsBase : public Printable
{
protected:
    ResourceOptionsBase();
    ResourceOptionsBase(const ResourceOptionsBase & value);
    ResourceOptionsBase(ResourceOptionsBase && value) noexcept;
    ResourceOptionsBase & operator=(const ResourceOptionsBase & value);
    ResourceOptionsBase & operator=(ResourceOptionsBase && value) noexcept;
    virtual ~ResourceOptionsBase();

public:
    /**
     * Check if field is set.
     *
     * Name used to identify the resource.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasShortName() const;

    /**
     * Get resource short name.
     *
     * Name used to identify the resource.
     *
     *
     * @return                          resource short name
     */
    String GetShortName() const;

    /**
     * %Set resource short name.
     *
     * Name used to identify the resource.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     resource short name
     */
    void SetShortName(const String & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    ResourceOptionsBase(const protocol::ResourceCreateRequest & value);
    ResourceOptionsBase(std::unique_ptr<protocol::ResourceCreateRequest> && value);

    std::unique_ptr<protocol::ResourceCreateRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::ResourceCreateRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::ResourceCreateRequest> m_impl;
};

}

#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VenueStatusBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class ServiceIdentifier;
class Status;
class String;
class Venue;


namespace protocol { class VenueStatus; }

class STRATEGY_EXPORT VenueStatusBase : public Printable
{
protected:
    VenueStatusBase();
    VenueStatusBase(const VenueStatusBase & value);
    VenueStatusBase(VenueStatusBase && value) noexcept;
    VenueStatusBase & operator=(const VenueStatusBase & value);
    VenueStatusBase & operator=(VenueStatusBase && value) noexcept;
    virtual ~VenueStatusBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVenue() const;

    /**
     * Get venue identifier.
     *
     *
     * @return                          venue identifier
     */
    Venue GetVenue() const;

    /**
     * %Set venue identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     venue identifier
     */
    void SetVenue(const Venue & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasServiceIdentifier() const;

    /**
     * Get service instance identifier.
     *
     *
     * @return                          service instance identifier
     */
    ServiceIdentifier GetServiceIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStatus() const;

    /**
     * Get status.
     *
     *
     * @return                          status
     */
    Status GetStatus() const;

    /**
     * %Set status.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     status
     */
    void SetStatus(const Status & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStatusText() const;

    /**
     * Get status text.
     *
     *
     * @return                          status text
     */
    String GetStatusText() const;

    /**
     * %Set status text.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     status text
     */
    void SetStatusText(const String & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const VenueStatusBase & update);

/** @cond PRIVATE */
public:
    VenueStatusBase(const protocol::VenueStatus & value);
    VenueStatusBase(std::shared_ptr<protocol::VenueStatus> && value);

    std::shared_ptr<protocol::VenueStatus> & get_impl_wr() const;
    const std::shared_ptr<protocol::VenueStatus> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::VenueStatus> m_impl;
};

}

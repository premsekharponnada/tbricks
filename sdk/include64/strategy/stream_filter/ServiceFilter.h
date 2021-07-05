#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in service status streams.
//****************************************************************************************

#include "strategy/Service.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/stream/ServiceStream.h"

namespace tbricks {

/**
 * Default service status filter, matches all data.
 */
class STRATEGY_EXPORT Service::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Filter & filter);
    ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const Filter & filter);
    Filter & operator&=(const Filter & filter);

    Filter operator||(const Filter & filter);
    Filter operator&&(const Filter & filter);

    Filter operator!();

    void Clear() override;
    bool Empty() const override;

public:
    tbricks::filter::FieldFilter GetValue() const override;
    Filter(const tbricks::filter::Filter & filter) : tbricks::Filter(filter) {}

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

/**
 * Convenience alias.
 */
using AnyServiceFilter = Service::Stream::Filters::Filter;

class STRATEGY_EXPORT Service::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Service::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    Service::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    Service::Stream::Filters::Filter operator||(const Service::Stream::Filters::Filter & cond) const;
    Service::Stream::Filters::Filter operator&&(const Service::Stream::Filters::Filter & cond) const;
    Service::Stream::Filters::Filter operator!() const;
    operator Service::Stream::Filters::Filter() const;
};

/**
 * Service status filter by type.
 */
class STRATEGY_EXPORT Service::Stream::Filters::ByTypeFilter : public Service::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all updates with the specified service type.
     *
     * @param venue                 Instance of Venue
     */
    /// @deprecated Deprecated in 2.14.3 use tbricks::ServiceType
    [[deprecated(DEPRECATE_LINK)]] ByTypeFilter(Service::Type type) : ByTypeFilter(static_cast<ServiceType>(type)) {}

    ByTypeFilter(ServiceType type);

    virtual ~ByTypeFilter();

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    ServiceType m_type;
    bool m_empty;
};

/**
 * Service status filter by venue.
 */
class STRATEGY_EXPORT Service::Stream::Filters::ByVenueFilter : public Service::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all updates with the specified venue.
     *
     * @param venue                 Instance of Venue
     */
    ByVenueFilter(const Venue & venue);

    /**
     * Constructor.
     *
     * Makes a filter to match all updates with the specified venue.
     *
     * @param venue                 Instance of Venue
     */
    ByVenueFilter(const VenueIdentifier & venue_id);

    virtual ~ByVenueFilter();

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    VenueIdentifier m_venue_id;
};
}

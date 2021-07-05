#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ServiceOptions
//****************************************************************************************

#include "strategy/stream/ServiceStream.h"
#include "strategy/stream_filter/ServiceFilter.h"

namespace tbricks {

class STRATEGY_EXPORT Service::Stream::Options : public Printable
{
public:
    void SetFilter(const Service::Stream::Filters::Filter & filter) { m_filter = filter; }

    const Service::Stream::Filters::Filter & GetFilter() const { return m_filter; }

    void SetServiceIdentifiers(const std::vector<ServiceIdentifier> & service_ids) { m_service_ids = service_ids; }

    const std::vector<ServiceIdentifier> & GetServiceIdentifiers() const { return m_service_ids; }

    void SetShowDisabled(bool show_disabled) { m_show_disabled = show_disabled; }

    bool IsShowDisabled() const { return m_show_disabled; }

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Service::Stream::Filters::Filter m_filter;
    std::vector<ServiceIdentifier> m_service_ids;
    bool m_show_disabled = false;
};
}

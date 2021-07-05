#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// LogEntryStreamOptions
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/LogEntry.h"
#include "strategy/stream_filter/LogEntryFilter.h"

namespace tbricks {

class STRATEGY_EXPORT LogEntry::Stream::Options : public Printable
{
public:
    Options() = default;
    Options(const Options & o) = default;
    Options(Options && o) = default;

    Options & operator=(const Options & o) = default;
    Options & operator=(Options && o) = default;

public:
    void SetFilter(const LogEntry::Stream::Filters::Filter & filter) { m_filter = filter; }
    const LogEntry::Stream::Filters::Filter & GetFilter() const { return m_filter; }

    void SetServiceIdentifier(const ServiceIdentifier & service_id) { m_service_id = service_id; }
    const ServiceIdentifier & GetServiceIdentifier() const { return m_service_id; }

    std::ostream & Print(std::ostream & strm) const override;

private:
    LogEntry::Stream::Filters::Filter m_filter;
    ServiceIdentifier m_service_id;
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Auditable stream.
//****************************************************************************************

#include "strategy/Auditable.h"
#include "strategy/Linkage.h"
#include "strategy/stream_filter/AuditableFilter.h"
#include "strategy/stream_filter/ExPitFilters.h"

namespace tbricks {

class STRATEGY_EXPORT RegulatoryAuditStreamOptions : public Printable
{
public:
    /**
     * Set types of auditable objects.
     *
     * @param types                  Types of auditable objects. All if emply.
     */
    void SetTypes(const std::vector<Auditable::Type> & types) { m_types = types; }

    /**
     * Get types of auditable objects.
     */
    const std::vector<Auditable::Type> & GetTypes() const { return m_types; }

    void SetFilter(const AuditableFilter & filter) { m_filter = filter; }

    const AuditableFilter & GetFilter() const { return m_filter; }

    void SetExPitFilter(const ExPit::Stream::Filters::Filter & filter) { m_expit_filter = filter; }

    const ExPit::Stream::Filters::Filter & GetExPitFilter() const { return m_expit_filter; }

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    AuditableFilter m_filter;
    ExPit::Stream::Filters::Filter m_expit_filter;
    std::vector<Auditable::Type> m_types;
};

} // namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ReferencePrice stream options.
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/stream/ReferencePriceStream.h"

namespace tbricks {

/** Stream advanced options */
class ReferencePriceStream::Options : public Printable
{
public:
    /**
     * %Set reference price stream filter.
     *
     * @param filter         reference price stream filter
     */
    void SetFilter(const ReferencePriceFilter & filter) { m_filter = filter; }

    /**
     * Get reference price stream filter.
     *
     * @return               reference price stream filter
     */
    const ReferencePriceFilter & GetFilter() const { return m_filter; }

    /**
     * %Set parameter context identifier.
     *
     * @param id             parameter context identifier
     */
    void SetContextIdentifier(const Identifier & id) { m_context_id = id; }

    /**
     * Get parameter context identifier.
     *
     * @return               parameter context identifier
     */
    const Identifier & GetContextIdentifier() const { return m_context_id; }

    /**
     * %Set snapshot datetime.
     *
     * @param date_time      snapshot datetime
     */
    void SetSnapshotDateTime(const DateTime & date_time) { m_snapshot_datetime = date_time; }

    /**
     * Get snapshot datetime.
     *
     * @return               snapshot datetime
     */
    const DateTime & GetSnapshotDateTime() const { return m_snapshot_datetime; }

    std::ostream & Print(std::ostream & strm) const override
    {
        long nindent = strm.iword(0);
        std::string indent(nindent, ' ');

        strm << indent << "<ReferencePriceStream::Options> {" << std::endl;

        if (!m_filter.Empty()) {
            strm << indent << "  stream filter " << m_filter << std::endl;
        }
        if (!m_context_id.Empty()) {
            strm << indent << "  parameter context identifier " << m_context_id << std::endl;
        }
        if (!m_snapshot_datetime.Empty()) {
            strm << indent << "  snapshot datetime = " << m_snapshot_datetime << std::endl;
        }

        strm << indent << "}" << std::endl;
        return strm;
    }

private:
    ReferencePriceFilter m_filter;
    Identifier m_context_id;
    DateTime m_snapshot_datetime;
};
}

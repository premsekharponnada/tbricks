#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OrderStreamOptions
//****************************************************************************************

#include "strategy/stream/OrderStream.h"
#include "strategy/stream_filter/OrderFilter.h"

namespace tbricks {

class STRATEGY_EXPORT Order::Stream::Options : public Printable
{
public:
    void SetFilter(const Order::Stream::Filters::Filter & filter) { m_filter = filter; }

    const Order::Stream::Filters::Filter & GetFilter() const { return m_filter; }

    /**
     * %Set trading service identifier
     * If trading id is not set, stream will open to order persistence services
     * otherwise to specified trading service
     *
     * @param service_id           trading identifier
     */
    void SetService(const ServiceIdentifier & service_id) { m_service_id = service_id; }

    /**
     * Get trading service identifier
     * If return value is empty the stream will open to order percsistence services
     * otherwise to specified trading service
     *
     * @return                     trading idenifier
     */
    const ServiceIdentifier & GetService() const { return m_service_id; }

    void SetCoalescing(const Boolean & coalescing) { m_coalescing = coalescing; }

    const Boolean & GetCoalescing() const { return m_coalescing; }

    void SetSnapshotDateTime(const DateTime & snapshot_datetime) { m_snapshot_datetime = snapshot_datetime; }

    const DateTime & GetSnapshotDateTime() const { return m_snapshot_datetime; }

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Order::Stream::Filters::Filter m_filter;
    ServiceIdentifier m_service_id;
    DateTime m_snapshot_datetime;
    Boolean m_coalescing;
};
}

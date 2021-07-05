#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// BlockOrderStreamOptions.
//****************************************************************************************

#include "strategy/stream/BlockOrderStream.h"
#include "strategy/stream_filter/BlockOrderFilter.h"

namespace tbricks {

class STRATEGY_EXPORT BlockOrder::Stream::Options : public Printable
{
public:
    Options() = default;
    Options(const Options & o) = default;
    Options(Options && o) = default;

    Options & operator=(const Options & o) = default;
    Options & operator=(Options && o) = default;

public:
    void SetFilter(const BlockOrder::Stream::Filters::Filter & filter) { m_filter = filter; }
    const BlockOrder::Stream::Filters::Filter & GetFilter() const { return m_filter; }

    void SetCoalescing(const Boolean & coalescing) { m_coalescing = coalescing; }
    const Boolean & GetCoalescing() const { return m_coalescing; }

    void SetSnapshotDateTime(const DateTime & snapshot_datetime) { m_snapshot_datetime = snapshot_datetime; }
    const DateTime & GetSnapshotDateTime() const { return m_snapshot_datetime; }

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    BlockOrder::Stream::Filters::Filter m_filter;
    DateTime m_snapshot_datetime;
    Boolean m_coalescing;
};
}

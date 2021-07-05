#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeStreamOptions
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Trade.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/TradeFilter.h"

namespace tbricks {

class STRATEGY_EXPORT TradeStreamOptions : public Printable
{
public:
    TradeStreamOptions() = default;
    TradeStreamOptions(const TradeStreamOptions & o) = default;
    TradeStreamOptions(TradeStreamOptions && o) = default;

    TradeStreamOptions & operator=(const TradeStreamOptions & o) = default;
    TradeStreamOptions & operator=(TradeStreamOptions && o) = default;

public:
    void SetFilter(const TradeFilter & filter) { m_filter = filter; }
    const TradeFilter & GetFilter() const { return m_filter; }

    void SetSnapshotDateTime(const DateTime & snapshot_datetime) { m_snapshot_datetime = snapshot_datetime; }
    const DateTime & GetSnapshotDateTime() const { return m_snapshot_datetime; }

    void SetUseFullUpdatesOnly(const Boolean & value) { m_use_full_updates_only = value; }
    const Boolean & GetUseFullUpdatesOnly() const { return m_use_full_updates_only; }

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    TradeFilter m_filter;
    DateTime m_snapshot_datetime;
    Boolean m_use_full_updates_only;
};
}

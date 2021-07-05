#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Percentiles calculator.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/StdInt.h"
#include "strategy/Printable.h"
#include "strategy/type/Integer.h"

namespace tbricks {

/**
 * Percentiles calculator
 */
class STRATEGY_EXPORT Percentiles : public Printable
{
    enum SupportedPercents
    {
        PERCENT_50 = 0,
        PERCENT_80,
        PERCENT_95,
        PERCENT_99,
        PERCENT_99_9,
        PERCENT_LAST,
    };

public:
    Percentiles();

    // returns true, if statistical data is available
    bool Empty() const { return m_observationsCount == 0; }

    void Clear() { m_observationsCount = 0; }

    /*
     * Get percentiles for specified data set.
     *
     * @return                          empty Integer if percentile is not available,
     *                                  percentile's value otherwise
     */
    Integer GetPercentile50() const { return GetPercentile(PERCENT_50); }
    Integer GetPercentile80() const { return GetPercentile(PERCENT_80); }
    Integer GetPercentile95() const { return GetPercentile(PERCENT_95); }
    Integer GetPercentile99() const { return GetPercentile(PERCENT_99); }
    Integer GetPercentile99_9() const { return GetPercentile(PERCENT_99_9); }

    Integer GetObservationsCount() const { return Empty() ? Integer() : Integer((int64_t)m_observationsCount); }

    std::ostream & Print(std::ostream & strm) const override;

    void Set(uint64_t observationsCount, uint64_t percentile[]);

private:
    // percentile values
    uint64_t m_percentile[PERCENT_LAST];
    // size of data set for which percentiles has been calculated
    uint64_t m_observationsCount;

    inline Integer GetPercentile(SupportedPercents percent) const { return Empty() ? Integer() : Integer((int64_t)m_percentile[percent]); }
};
}

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TimeZone type
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/String.h"
#include "strategy/type/TimeZoneIdentifiers.h"

namespace tbricks {

class DateTime;

/**
 * Time zone object. Use "tbtimezone ls" to see
 * all possible time zones
 */
class STRATEGY_EXPORT TimeZone : public Printable
{
public:
    /**
     * Creates time zone of server
     */
    TimeZone();

    TimeZone(const TimeZone & timezone);

    TimeZone(TimeZoneID id);

    /**
     * Creates time zone with passed name
     *
     * @param name       name of time zone
     */
    TimeZone(const String & name);

    /**
     * @return time zone of server
     */
    static TimeZone GetLocal();

    /**
     * @return utc time zone
     */
    static TimeZone GetUTC();

    /**
     * @return empty time zone
     */
    static TimeZone GetEmpty();

    /**
     * @return time zone identifier
     */
    TimeZoneID GetID() const;

    /**
     * @return long name of time zone
     */
    String GetName() const;

    /**
     * Queries if this time zone uses daylight savings time (dst).
     *
     * @return False if offsets of last dst and non-dst months are the same,
     * true otherwise.
     */
    bool IsDaylightUsed() const;

    bool InDaylightTime(const DateTime & dt);

    size_t GetHash() const;

public:
    TimeZone & operator=(const TimeZone & timezone);

    /**
     * compares two time zone identifiers
     */
    bool operator==(const TimeZone & timezone) const;

    /**
     * compares two time zone identifiers
     */
    bool operator!=(const TimeZone & timezone) const;

    std::ostream & Print(std::ostream & strm) const override;

private:
    TimeZoneID m_id;
};
}

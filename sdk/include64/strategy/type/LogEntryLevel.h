#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// LogEntryLevel enumeration.
//****************************************************************************************

#include "strategy/Linkage.h"

#include <ostream>

namespace tbricks {

enum class STRATEGY_EXPORT LogEntryLevel
{
    CRITICAL = 0, /**< An unrecoverable critical error has occurred. The service will try to emit additional debug information for the cause before aborting. This is only being done due to a lack for critical system resources or internal inconsistencies in the service that can risk data corruption or erroneous behavior. */
    ERROR = 1, /**< An unexpected recoverable error condition has occurred that should be reported to the software vendor, this usually requires corrective action by administrative staff. */
    WARNING = 2, /**< An recoverable but potentially expected exceptional condition has occurred that may require corrective action by administrative staff to be resolved. For example, it can be that the system is running low on disk space, or that a latency measurement counter is slower than an acceptable threshold. */
    NOTICE = 3, /**< An expected system state change has occurred. E.g., the service has successfully connected to another service, the service may have connected to an external data source (for trading services), the service has fully recovered it's state during startup. */
    STATUS = 4, /**< Periodic events containing status information. Typically non-exceptional health information like memory utilization, cpu utilization, cache statistics, number of instruments, number of bytes sent/received, number of strategies, number of running strategies, number of clients connected, etc, etc. */
    DEBUG = 5, /**< A moderate amount of debug information is provided with the intention to aid operational administrative and/or engineering staff with troubleshooting.
                This may have a noticeable performance impact on the service. */
    DUMP = 6, /**< This provides extensive debug dumps, up to and including verbose dumps of all messages and data buffers sent/received etc.
                This will have a severe performance impact on the service if used by a tblog client. */
    FULL_DUMP = 7 /**< This provides maximum full raw debug dumps, up to and including hex dumps of all messages and data buffers sent/received etc.
                This will have a severe performance impact on the service if used by a tblog client. */
};

STRATEGY_EXPORT std::ostream & operator << (std::ostream & strm, LogEntryLevel value);

}

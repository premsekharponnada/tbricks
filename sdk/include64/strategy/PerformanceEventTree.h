#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PerformanceEventTree
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/type/StdInt.h"

#include <utility>

/**
 * PerformanceEventTree object.
 *
 * Represents context for TRACEPOINT macro.
 *
 * In first parameter TRACEPOINT macro you should set name
 * of trace point.
 * In second parameter you should provide PerformanceEventTree
 * object for bind different tracepoints.
 *
 * @code
 * PerformanceEventTree context;
 * TRACEPOINT(received_bbo, context);
 * ...
 * TRACEPOINT(bbo_processed, context);
 *
 * @endcode
 */

namespace tbricks {

class STRATEGY_EXPORT PerformanceEventTree : public Printable
{
public:
    PerformanceEventTree();

    PerformanceEventTree(const PerformanceEventTree & pet);
    PerformanceEventTree & operator=(const PerformanceEventTree & pet);

protected:
    void Generate();
    std::pair<uint64_t, uint64_t> & GetPET();
    static std::pair<uint64_t, uint64_t> GetEnginePET();
    static void SetEnginePET(const std::pair<uint64_t, uint64_t> & pet);

private:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::pair<uint64_t, uint64_t> m_pet;
};
}

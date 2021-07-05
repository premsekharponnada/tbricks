#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Latency timer API.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/Integer.h"
#include "strategy/type/String.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT LatencyTimer : public Printable
{
public:
    LatencyTimer() : m_start(0), m_ticks(0) {}
    ~LatencyTimer() override {}

    void Start();
    void Start(const String & name);
    void Finish();

    uint64_t GetTicks() const { return m_ticks; }

    uint64_t GetMicroseconds() const;

    void SetName(const String & name) { m_name = name; }

    const String & GetName() const { return m_name; }

    bool Empty() const { return m_start == 0; }
    void Clear()
    {
        m_start = 0;
        m_ticks = 0;
    }

    static void MakeCheckpoint(const char * name);

    std::ostream & Print(std::ostream & strm) const override;

public:
    static uint64_t ConvertTicksToNanoseconds(uint64_t ticks);
    static uint64_t ConvertTicksToMicroseconds(uint64_t ticks);
    static uint64_t ConvertTicksToMilliseconds(uint64_t ticks);
    static uint64_t ConvertTicksToSeconds(uint64_t ticks);

private:
    String m_name;
    uint64_t m_start;
    uint64_t m_ticks;
};

} // \namespace tbricks

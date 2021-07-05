#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instruments associated with the strategy.
//****************************************************************************************

#include <vector>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/InstrumentIdentifier.h"

// \namespace tbricks
namespace tbricks {

namespace types {
class UUID;
}
namespace strategy {
class IStrategyInstruments;
}
namespace protocol {
class StrategyInstance;
}

class STRATEGY_EXPORT StrategyInstruments : public Printable
{
public:
    typedef std::vector<tbricks::types::UUID> instruments_t;

public:
    StrategyInstruments();
    StrategyInstruments(const StrategyInstruments & instruments);
    virtual ~StrategyInstruments();

    StrategyInstruments & operator=(const StrategyInstruments & instruments);

    /**
     * Overwrite associated instruments.
     *
     * Old vector of associated instruments is fully replaced with the
     * argument.
     *
     * @param instruments               New instruments vector
     */
    void SetValue(const std::vector<InstrumentIdentifier> & instruments);

    /**
     * %Set associated instrument.
     *
     * Replace instrument vector with a single value.
     *
     * @param instrument                Instrument identifier
     */
    void SetValue(const InstrumentIdentifier & instrument);

    /**
     * Add associated instrument.
     *
     * Expand instrument vector with a new value.
     *
     * @param instrument                Instrument identifier
     */
    void AddValue(const InstrumentIdentifier & instrument);

    /**
     * Remove associated instrument.
     *
     * If instrument identifier is not in the current vector,
     * the method has no effect.
     *
     * @param instrument                Instrument identifier
     */
    void DeleteValue(const InstrumentIdentifier & instrument);

    /**
     * Check associated instrument presence.
     *
     * Returns true if instrument is already associated.
     * the method has no effect.
     *
     * @param instrument                Instrument identifier
     * @return                          "true" if instrument is already
     *                                  associated, "false" otherwise
     */
    bool HasValue(const InstrumentIdentifier & instrument) const;

    /**
     * Get associated instruments.
     *
     * If there are no associated instruments, parameter is cleared.
     *
     * @param instruments               Instruments vector
     */
    void GetValue(std::vector<InstrumentIdentifier> & instruments) const;

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no parameters in the
     *                                  container, false otherwise.
     */
    bool Empty() const;

    /**
     * Clear container data.
     *
     * After this call container is guaranteed to contain no data, and Empty()
     * method will return True if called.
     */
    void Clear();

    /**
     * return number of instruments
     */
    size_t GetSize() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

    bool updated() const { return m_update; }
    void update(tbricks::protocol::StrategyInstance & partial_si);
    void decode(const void * data, size_t size);

private:
    size_t m_count;
    enum
    {
        CacheSize = 4
    };
    InstrumentIdentifier m_cache[CacheSize];
    instruments_t * m_instruments;
    bool m_update;
};

} // \namespace tbricks

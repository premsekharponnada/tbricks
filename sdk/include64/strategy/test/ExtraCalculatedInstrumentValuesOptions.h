#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Extra Calculated Instrument Values Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Strategy.h"

#include "strategy/type/UserIdentifier.h"

// \namespace tbricks
namespace tbricks {

namespace protocol {
class StreamOpenRequest;
}

namespace test {

/**
 */
class STRATEGY_EXPORT ExtraCalculatedInstrumentValuesOptions : public Printable
{
public:
    typedef protocol::StreamOpenRequest stream_open_request_t;

public:
    ExtraCalculatedInstrumentValuesOptions();
    ExtraCalculatedInstrumentValuesOptions(stream_open_request_t * order);
    ExtraCalculatedInstrumentValuesOptions(const ExtraCalculatedInstrumentValuesOptions & order);
    virtual ~ExtraCalculatedInstrumentValuesOptions();

    ExtraCalculatedInstrumentValuesOptions & operator=(const ExtraCalculatedInstrumentValuesOptions & order);

public:
    bool HasUserIdentifier() const;
    UserIdentifier GetUserIdentifier() const;
    void SetUserIdentifier(const UserIdentifier & user);

    /**
     * Check extra calculated instrument values options for emptiness.
     *
     * @return                          True if extra calculated instrument values options are empty, false otherwise.
     */
    bool Empty() const;

    virtual std::ostream & Print(std::ostream & strm) const;

    void Merge(const ExtraCalculatedInstrumentValuesOptions & options);

public:
    const stream_open_request_t & get_stream_open_request() const;
    stream_open_request_t & get_stream_open_request();

private:
    stream_open_request_t * m_sor;
};

} // \namespace test

} // \namespace tbricks

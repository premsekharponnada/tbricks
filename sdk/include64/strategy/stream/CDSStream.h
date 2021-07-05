#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CDSStream
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/Stream.h"

namespace tbricks {

namespace strategy {
class CDSStreamImpl;
}

class STRATEGY_EXPORT CDSStream : public Stream
{
public:
    class IHandler;

public:
    CDSStream();
    CDSStream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open(const String & host, const String & process, const String & user, bool broadcast = false);

    void SendCDSMessage(char message_type, void * data, size_t size);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    strategy::CDSStreamImpl * m_stream;
};

class STRATEGY_EXPORT CDSStream::IHandler
{
public:
    virtual void HandleCDSStreamOpen(const StreamIdentifier & stream) = 0;
    virtual void HandleCDSStreamClosed(const StreamIdentifier & stream) = 0;
    virtual void HandleCDSStreamFailed(const StreamIdentifier & stream) = 0;
    virtual void HandleCDSMessage(const StreamIdentifier & stream, char message_type, const Binary & msg) = 0;

    virtual ~IHandler();
};
}

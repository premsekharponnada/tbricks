#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Circuit breaker stream
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/CircuitBreaker.h"
#include "strategy/stream/Stream.h"

namespace tbricks {

class STRATEGY_EXPORT CircuitBreaker::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

public:
    /**
     * Open a stream.
     *
     * If stream is already opened the call has no effect.
     * If no callback interface is associated exception will be thrown.
     * If service idetifier is not specified exception will be thrown.
     *
     * @param type                      Stream type
     * @param service_id                Quoting service identifier
     * @param circuit_breaker_id        Circuit breaker identifier, if identifier is empty
     *                                  stream for all circuit breaks will be opened.
     */
    void Open(Stream::Type type, const ServiceIdentifier & service_id, const Identifier & circuit_breaker_id);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * CircuitBreaker::Stream::IHandler
 */
class STRATEGY_EXPORT CircuitBreaker::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleCircuitBreaker(const StreamIdentifier & stream_id, const CircuitBreaker & cb) = 0;

protected:
    virtual ~IHandler();
};

} // namespace tbricks

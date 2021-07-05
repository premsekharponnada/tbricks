#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExpirationOld stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/ExpirationOld.h"
#include "strategy/Expiration.h"
#include "strategy/stream/ExpirationStream.h"
#include "strategy/Strategy.h"
#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/Stream.h"

namespace tbricks {

class STRATEGY_EXPORT ExpirationOld::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open(Type type, const Expiration::Stream::Filters::Filter & filter);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

class STRATEGY_EXPORT ExpirationOld::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleExpiration(const StreamIdentifier & stream_id, const ExpirationOld::Update & update) = 0;

    /**
     * Expiration stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits the filtering criteria.
     *
     * Fox example, a subscription is made for deleted Expiration and all the
     * deleted Expiration are received. If any such Expiration is un-deleted,
     * invalidate method would be called to indicate that this Expiration no longer
     * belongs to subscription request.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated Expiration
     */
    virtual void HandleExpirationInvalidate(const StreamIdentifier & stream, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

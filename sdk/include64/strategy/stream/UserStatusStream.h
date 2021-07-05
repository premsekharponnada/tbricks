#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// User preferences stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/Stream.h"

#include "strategy/UserStatus.h"

namespace tbricks {

/**
 * User::Status::Stream class
 */
class STRATEGY_EXPORT User::Status::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByUserIdentifier;
    };

public:
    Stream();
    Stream(IHandler & handler);

public:
    void SetCallback(IHandler & handler);

    void Open(Type type, const Filters::Filter & filter);

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * User::Status::Stream::IHandler interface
 */
class STRATEGY_EXPORT User::Status::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleUserStatus(const StreamIdentifier & stream_id, const User::Status & update) = 0;

protected:
    virtual ~IHandler();
};

} // namespace tbricks

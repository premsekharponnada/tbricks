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

#include "strategy/UserPreferences.h"

namespace tbricks {

/**
 * User::Preferences::Stream class
 */
class STRATEGY_EXPORT User::Preferences::Stream : public tbricks::Stream
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
 * User::Preferences::Stream::IHandler interface
 */
class STRATEGY_EXPORT User::Preferences::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleUserPreferences(const StreamIdentifier & stream_id, const User::Preferences::Update & update) = 0;

protected:
    virtual ~IHandler();
};

} // namespace tbricks

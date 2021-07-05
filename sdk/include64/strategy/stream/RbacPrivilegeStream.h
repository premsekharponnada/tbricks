#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RbacPrivilege stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/rbac/RbacPrivilege.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"

namespace tbricks {

class STRATEGY_EXPORT RbacPrivilege::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;
        class ByOperationFilter;
    };

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open(Type type, const Filters::Filter & filter);
    void OpenAudit(Type type, const Filters::Filter & filter, const DateTime & from = DateTime(), const DateTime & to = DateTime());

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

class STRATEGY_EXPORT RbacPrivilege::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & /* stream */) {}

    virtual void HandleRbacPrivilege(const StreamIdentifier & stream_id, const RbacPrivilege & update) = 0;

    /**
     * RbacPrivilege stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       identifier of invalidated RbacPrivilege
     */
    virtual void HandleRbacPrivilegeInvalidate(const StreamIdentifier & stream_id, const Identifier & id) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Resource object
//
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Strategy.h"
#include "strategy/Types.h"

#include "strategy_generated/ResourceBase.h"

#include <cstddef>

namespace tbricks {

/**
 * Resource object describes binary resource from Distribution Center
 */
class STRATEGY_EXPORT Resource : public ResourceBase
{
public:
    class RequestResult;
    class Stream;
    class Modifier;
    class Options;

public:
    Resource() = default;
    Resource(std::shared_ptr<protocol::Resource> && value) : ResourceBase(std::move(value)) {}

public:
    /**
     * Get resource size.
     *
     * Returns resource file size, in bytes.
     *
     * @return                          Resource size
     */
    size_t GetSize() const;

    void Merge(const Resource & src);

public:
    static RequestResult SendCreateRequest(const Resource::Options & options, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    static RequestResult
    SendUploadRequest(const String & short_name, const String & data, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    static RequestResult SendModifyRequest(const Resource::Modifier & modifier, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    static RequestResult SendDeleteRequest(const String & short_name, IRequestReplyHandler & handler = IRequestReplyHandler::Default());
};

/**
 * Resource::RequestResult object.
 */
class STRATEGY_EXPORT Resource::RequestResult : public Printable
{
public:
    RequestResult() = default;
    RequestResult(const Identifier & request_identifier, const String & resource_short_name)
    {
        m_request_identifier = request_identifier;
        m_resource_short_name = resource_short_name;
    }

    const Identifier & GetRequestIdentifier() const { return m_request_identifier; }

    const String & GetResourceShortName() const { return m_resource_short_name; }

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    String m_resource_short_name;
};
}

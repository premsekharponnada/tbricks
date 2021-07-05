#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Pre-trade risk checking API.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include <memory>
#include <vector>

namespace tbricks {

class StrategyParameters;
class Identifier;
class StrategyIdentifier;
class UserIdentifier;
class StrategyState;

namespace protocol {
class IMessage;
}

/**
 * This class is the primary pre-trade risk check point.
 * When IFlowEventHandler::HandleAppRequest() is called, AppRequestContext object
 * contains parameter values extracted from the request, type of the request being handled,
 * request identifier, strategy identifier, etc. Callee shall check and decide whether
 * request is accepted/rejected for further processing.
 *
 * @see IFlowEventHandler::HandleAppRequest()
 */
class STRATEGY_EXPORT AppRequestContext : public Printable
{
public:
    AppRequestContext();
    AppRequestContext(const AppRequestContext & ctx);
    AppRequestContext(AppRequestContext && ctx) noexcept;

    AppRequestContext & operator=(const AppRequestContext & ctx);
    AppRequestContext & operator=(AppRequestContext && ctx) noexcept;

    ~AppRequestContext();

public:
    /**
     * Returns request identifier of the request being processed.
     */
    bool GetRequestIdentifier(Identifier & id) const;

    /**
     * Type of the request
     */
    enum RequestType
    {
        CREATE_REQUEST = 0,
        RUN_REQUEST = 1,
        PAUSE_REQUEST = 2,
        MODIFY_REQUEST = 3,
        DELETE_REQUEST = 4,
    };

    /**
     * Returns type of the request being processed.
     */
    bool GetRequestType(RequestType & request_type) const;

    /**
     * Returns app state extracted from the request being handled
     */
    bool HasAppState() const;
    bool GetAppState(StrategyState & state) const;

    /**
     * Returns app's definition identifier
     */
    bool GetAppDefinitionIdentifier(StrategyIdentifier & id) const;

    /**
     * Returns app's identifier
     */
    bool GetAppIdentifier(StrategyIdentifier & id) const;

    /**
     * Returns 'operator' field from the request being handled
     */
    bool HasCreatorIdentifier() const;
    bool GetCreatorIdentifier(UserIdentifier & id) const;

    /**
     * Returns 'creator' field from the request being handled
     */
    bool HasOperatorIdentifier() const;
    bool GetOperatorIdentifier(UserIdentifier & id) const;

    /**
     * Returns parameters extracted from the request being handled
     */
    bool HasParameters() const;
    bool GetParameters(StrategyParameters & params) const;

    bool HasParentAppIdentifier() const;
    bool GetParentAppIdentifier(StrategyIdentifier & id) const;

    bool HasRootAppIdentifier() const;
    bool GetRootAppIdentifier(StrategyIdentifier & id) const;

    bool HasAppDefinitionIdentifierPath() const;
    bool GetAppDefinitionIdentifierPath(std::vector<StrategyIdentifier> & path) const;

    bool HasAppIdentifierPath() const;
    bool GetAppIdentifierPath(std::vector<StrategyIdentifier> & path) const;

    /**
     * Causes request to be accepted and forwarded for further processing.
     * Either this method or SendRejectReply must be called, exactly once per request, but not both.
     */
    void SendAcceptReply() const;

    /**
     * Causes request to be rejected.
     * Either this method or SendAcceptReply must be called, exactly once per request, but not both.
     */
    void SendRejectReply(const String & reason) const;

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    class Impl;
    AppRequestContext(std::shared_ptr<Impl> msg);
    Impl * get_impl() const;

private:
    std::shared_ptr<Impl> m_impl;
};

std::ostream & operator<<(std::ostream & strm, const AppRequestContext::RequestType & type);
}

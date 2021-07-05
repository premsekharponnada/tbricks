#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestReplyHandler
//****************************************************************************************

#include "strategy/type/Status.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/String.h"

#include <utility>

namespace tbricks {

class STRATEGY_EXPORT IReplyHandler
{
protected:
    IReplyHandler();
    virtual ~IReplyHandler();

private:
    friend class AppEventHandler;

    void * m_ptr;
    std::pair<uint64_t, uint64_t> m_id;
};

/**
 * Request strategy reply handler interface delivers result of remote operation
 * back to the originator.
 */
class STRATEGY_EXPORT IStrategyRequestReplyHandler : public IReplyHandler
{
public:
    /**
     * Process strategy request reply.
     *
     * Method returns result of Create request issued with
     * SendAsyncCreateRequest().
     *
     * Note: Even positive result means only that appropriate Strategy Engine
     * instance had accepted the request for further processing. To make sure
     * the request had succeeded, please track strategy instance updates with
     * strategy stream (@see StrategyStream).
     *
     * @param strategy_id               Strategy identifier
     * @param id                        Identifier returned by either of
     *                                  Strategy::SendAsyncCreateRequest()
     * @param status                    StatusOk if request was accepted by a
     *                                  target service, StatusFail otherwise
     * @param status_text               Failure reason if status == StatusFail,
     *                                  empty string otherwise
     */
    virtual void
    HandleStrategyRequestReply(const StrategyIdentifier & strategy_id, const Identifier & id, Status status, const String & status_text) = 0;

    /**
     * Get default handler instance.
     *
     * Default handler instance simply skips request replies.
     */
    static IStrategyRequestReplyHandler & Default();

protected:
    virtual ~IStrategyRequestReplyHandler();
};

/**
 * Request reply handler interface delivers result of remote operation
 * back to the originator.
 */
class STRATEGY_EXPORT IRequestReplyHandler : public IStrategyRequestReplyHandler
{
public:
    /**
     * Process request reply.
     *
     * Method returns result of Run/Pause/Delete/Modify requests issued
     * (possibly from a remote Strategy Engine instance) with SendRunRequest(),
     * SendPauseRequest(), SendDeleteRequest() and SendModifyRequest(),
     * respectively.
     *
     * Note: Even positive result means only that appropriate Strategy Engine
     * instance had accepted the request for further processing. To make sure
     * the request had succeeded, please track strategy instance updates with
     * strategy stream (@see StrategyStream).
     *
     * @param id                        Identifier returned by either of
     *                                  Strategy::SendRunRequest(),
     *                                  Strategy::SendPauseRequest(),
     *                                  Strategy::SendDeleteRequest() or
     *                                  Strategy::SendModifyRequest()
     * @param status                    StatusOk if request was accepted by a
     *                                  target service, StatusFail otherwise
     * @param status_text               Failure reason if status == StatusFail,
     *                                  empty string otherwise
     */
    virtual void HandleRequestReply(const Identifier & id, Status status, const String & status_text) = 0;

    virtual void HandleStrategyRequestReply(const StrategyIdentifier & /* strategy_id */,
                                            const Identifier & id,
                                            Status status,
                                            const String & status_text) override
    {
        HandleRequestReply(id, status, status_text);
    }

    /**
     * Get default handler instance.
     *
     * Default handler instance simply skips request replies.
     */
    static IRequestReplyHandler & Default();

protected:
    virtual ~IRequestReplyHandler();
};
}

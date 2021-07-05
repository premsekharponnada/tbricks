#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExPit Manager.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/ExPit.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT ExPitManager
{
public:
    class STRATEGY_EXPORT ExPitCreateRequestResult
    {
    public:
        ExPitCreateRequestResult() = default;
        ExPitCreateRequestResult(const Identifier & request_id, const ExPitIdentifier & expit_id) : m_request_id(request_id), m_expit_id(expit_id) {}

        const Identifier & GetRequestIdentifier() const { return m_request_id; }
        const ExPitIdentifier & GetExPitIdentifier() const { return m_expit_id; }

        /** @deprecated Deprecated in 2.14.5 */
        [[deprecated(DEPRECATE_LINK)]] bool Empty() const { return m_request_id.Empty() && m_expit_id.Empty(); }

            /** @deprecated Deprecated in 2.14.5 */
            [[deprecated(DEPRECATE_LINK)]] void Clear()
        {
            m_request_id.Clear();
            m_expit_id.Clear();
        }

    private:
        Identifier m_request_id;
        ExPitIdentifier m_expit_id;
    };

public:
    ExPitManager();
    virtual ~ExPitManager();

    /**
     * Apps call this method when they need to start recovery process for their own orders.
     * For example, after restart of the app.
     *
     * @param reason                    Reason to start recovery.
     *
     * @return true                     The reason parameter is RECOVERED and other StartRecovery()
     *                                  is not running. This means there are may be orders to recover.
     *                                  Recovery will be performed.
     * @return false                    The reason parameter is not RECOVERED or other StartRecovery()
     *                                  is running.
     */
    bool StartRecovery(const InitializationReason & reason);

    /**
     * This method detects if the %Order Manager is in recovery state.
     *
     * @return true                      %Order Manager is in recovery state.
     * @return false                     %Order Manager is NOT in recovery state.
     */
    bool InRecovery() const;

    ExPitCreateRequestResult SendCreateRequest(const ExPit::Options & options, IRequestReplyHandler & handler);

    Identifier SendDeleteRequest(const ExPitIdentifier & expit_id, IRequestReplyHandler & handler);

public:
    /// This sends ex-pit request which is used to accept
    ExPitCreateRequestResult SendAcceptRequest(const ExPit::AcceptOptions & options, IRequestReplyHandler & handler);

    /// This sends decline request
    Identifier SendDeclineRequest(const ExPit::DeclineOptions & options, IRequestReplyHandler & handler);

    /**
     * This sends decline request
     *
     * @deprecated Deprecated in 2.13.1, use SendDeclineRequest(const ExPit::DeclineOptions & expit_id,
     * IRequestReplyHandler & handler) instead
     */
    [[deprecated(DEPRECATE_LINK)]] Identifier SendDeclineRequest(const ExPitIdentifier & expit_id, IRequestReplyHandler & handler);

public:
    virtual void HandleRecoveryCompleted() = 0;
    virtual void HandleExPitUpdate(const ExPit::Update & update) = 0;

private:
    ExPitManager(const ExPitManager & src);
    ExPitManager & operator=(const ExPitManager & src);

public:
    void complete_recovery();

private:
    bool m_recovery;
};

} // \namespace tbricks

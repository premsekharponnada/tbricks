#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteSetProxy object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Strategy.h"

#include "strategy/quoting/QuoteIdentification.h"
#include "strategy/quoting/QuoteTable.h"

namespace tbricks {

namespace protocol {
class QuoteSetActiveTable;
class QuoteSetDeleteRequest;
class QuoteSetRunRequest;
class QuoteSetPauseRequest;
class QuoteSetModifyRequest;
}

//****************************************************************************
// QuoteSetProxy class
//****************************************************************************
class STRATEGY_EXPORT QuoteSetProxy : public Printable
{
public:
    class RequestResult;

public:
    QuoteSetProxy(const Identifier & quote_set_identifier);
    /**
     * Constructor for explicit set quoting service identifier.
     */
    QuoteSetProxy(const Identifier & quote_set_identifier, const ServiceIdentifier & quoting_service_identifier);
    QuoteSetProxy(const QuoteSetProxy & qs_proxy);
    QuoteSetProxy & operator=(const QuoteSetProxy & qs_proxy);
    ~QuoteSetProxy();

public:
    const Identifier & GetQuoteSetIdentifier() const;
    const ServiceIdentifier & GetServiceIdentifier() const;

    RequestResult
    SetActiveTable(const Integer & primary_table_identifier, const Integer & secondary_table_identifier, IRequestReplyHandler & handler);

    RequestResult SendDeleteRequest(IRequestReplyHandler & handler);

    RequestResult SendForceDeleteRequest(IRequestReplyHandler & handler);

    RequestResult SendStartRequest(IRequestReplyHandler & handler);

    RequestResult SendStopRequest(IRequestReplyHandler & handler);

    RequestResult SendSuspendRequest(IRequestReplyHandler & handler);

    RequestResult SendUnsuspendRequest(IRequestReplyHandler & handler);

public:
    bool Empty() const;
    void Clear();

public:
    std::ostream & Print(std::ostream & strm) const;

private:
    RequestResult DoDeleteQuoteSet(IRequestReplyHandler & handler, bool force);

private:
    Identifier m_quote_set_identifier;
    ServiceIdentifier m_service_identifier;
    protocol::QuoteSetActiveTable * m_active_table_message;
    protocol::QuoteSetDeleteRequest * m_delete_request_message;
    protocol::QuoteSetRunRequest * m_run_request_message;
    protocol::QuoteSetPauseRequest * m_pause_request_message;
    protocol::QuoteSetModifyRequest * m_modify_request_message;
};

//****************************************************************************
// RequestResult class
//****************************************************************************
class STRATEGY_EXPORT QuoteSetProxy::RequestResult : public Printable
{
public:
    RequestResult();
    virtual ~RequestResult() {}
    RequestResult(const Identifier & request_identifier);

    const Identifier & GetRequestIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
};

} // namespace tbricks

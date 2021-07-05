#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// FIX session.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/stream/Stream.h"
#include "strategy/SafePointer.h"
#include "strategy/Printable.h"
#include "strategy/fix/Enums.h"
#include "strategy/fix/MessagesSnapshot.h"

namespace tbricks {

namespace fix {
class ISession;
}

namespace FIX {

class Message;
class MessageBuilder;

/**
 * WARNING!
 *
 * This class is under development, class interface is subject to change.
 *
 */
class STRATEGY_EXPORT Session : public Printable
{
public:
    static const char * GetFIXatdlResourceMimeType() { return "application/x-fixatdl+xml"; }

public:
    Session();
    Session(tbricks::fix::ISession * session);
    ~Session();

    Session(const Session & session);
    Session & operator=(const Session & session);

    friend class Message;

    String GetName() const;

    String GetIdentifier() const;

    String GetSenderCompID() const;
    String GetTargetCompID() const;
    String GetSenderSubID() const;
    String GetTargetSubID() const;

    String GetHost() const;
    uint16_t GetPort() const;

    TimeZone GetTimeZone() const;

    bool Send(MessageBuilder & message);

    void Close();

    /**
     * This class is under development, GetLastIncomingMessage method is subject to change.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetLastIncomingMessage(MessageType::Type type, Message & message);

    /**
     * This class is under development, GetLastOutgoingMessage method is subject to change.
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetLastOutgoingMessage(MessageType::Type type, Message & message);

    /**
     * Returns iterator provider over all outgoing messages for the session.
     * Please refer to Tbricks FIX API documentation for more information.
     *
     * @code
     *  FIX::Session session{ ... };
     *  for (const FIX::Message & message : session.GetOutgoingMessages()) {
     *      ...
     *  }
     * @endcode
     *
     * @return                          Iterable range of outgoing messages.
     */
    MessagesSnapshot GetOutgoingMessages() const;

    MessageBuilder CreateMessage(const char * msg_type);
    MessageBuilder CreateMessage(const String & msg_type);
    MessageBuilder CreateMessage(MessageType::Type type);
    MessageBuilder CreateFromData(const char *, size_t, std::string & status);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    SafePointer<tbricks::fix::ISession> m_session;
};

class STRATEGY_EXPORT ISessionHandler
{
public:
    virtual void HandleLogon(Session & session) = 0;

    virtual void HandleLogout(Session & session) = 0;

    virtual void HandleMessage(Session & session, const Message & message) = 0;

protected:
    virtual ~ISessionHandler() {}
};

class STRATEGY_EXPORT Connector : public Printable
{
public:
    Connector();
    ~Connector();

    bool Accept(const String & group_name, ISessionHandler & handler);
    void Close();

    static bool Connect(const String & session_name, ISessionHandler & handler);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    String m_name;
};
}
} // namespace FIX, namespace tbricks

#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// FIX Message
// UNDER DEVELOPMENT. PLEASE, DON'T USE
//****************************************************************************************

#include "strategy/fix/Group.h"

namespace tbricks { namespace fix {
class Message;
}}
namespace tbricks { namespace FIX {

class Session;
class MessageBuilder;
class MessagesSnapshot;

/**
 * WARNING!
 *
 * This class is under development, class interface is subject to change.
 *
 */
class STRATEGY_EXPORT Message : public Group
{
    friend Session;
    friend MessageBuilder;
    friend MessagesSnapshot;

public:
    ~Message();
    Message() = default;
    Message(const Message &);
    Message & operator=(const Message &);

    Message(Message &&);
    Message & operator=(Message &&);

public:
    MessageType::Type GetType() const;
    String GetCustomType() const;

    static MessageType::Type GetMessageType(const String & msg_type);
    static MessageType::Type GetMessageType(const char * msg_type);

public:
    void Clear();
    bool Empty() const;

    void set_external_data(fix::Message *);

private:
    Message & copy(const Message &);
    Message & move(Message &&);

private:
    bool m_is_external{false};

    fix::Message * get_data();
    const fix::Message * get_data() const;

    void set_data(const fix::Message &);
};

}} // namespace FIX, namespace tbricks

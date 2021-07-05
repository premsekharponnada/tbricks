#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// FIX::[IncomingMessagesSnapshot, OutgoingMessagesSnapshot]
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/SafePointer.h"
#include "strategy/fix/Message.h"

namespace tbricks {

namespace fix {
class ISession;
}

namespace FIX {

/**
 * WARNING!
 *
 * This class is under development, class interface is subject to change.
 *
 */
class STRATEGY_EXPORT MessagesSnapshot
{
public:
    /**
     * Iterator like accessor to fix storage of messages.
     */
    class STRATEGY_EXPORT Cursor
    {
    public:
        class EndTag
        {};

    public:
        /** @cond PRIVATE */
        Cursor(fix::ISession * session, uint32_t from_sequence_number, uint32_t last_sequence_number, bool is_outgoing) :
            m_session(session),
            m_next_seq_num(from_sequence_number),
            m_end_seq_num(last_sequence_number + 1),
            m_is_outgoing(is_outgoing)
        {
            next();
        }

        Cursor(const Cursor &) noexcept = delete;
        Cursor & operator=(const Cursor &) noexcept = delete;

        Cursor(Cursor &&) noexcept = delete;
        Cursor & operator=(Cursor &&) noexcept = delete;

        ~Cursor() noexcept = default;
        /** @endcond */

    public:
        /**
         * Get current message ref.
         * Reference will invalidate after operator++.
         */
        const FIX::Message & operator*() const noexcept { return m_msg; }

        bool operator!=(const EndTag &) const noexcept { return m_next_seq_num <= m_end_seq_num; }

        Cursor & operator++() noexcept
        {
            next();
            return *this;
        }

    private:
        void next();

    private:
        tbricks::fix::ISession * m_session;
        uint32_t m_next_seq_num;
        uint32_t m_end_seq_num;
        bool m_is_outgoing;
        FIX::Message m_msg;
    };

public:
    /**
     * Construct iterator for snapshot reading.
     */
    Cursor begin() const { return Cursor{m_session.Get(), m_first_sequence_number, m_last_sequence_number, m_is_outgoing}; }

    /**
     * Construct end iterator.
     */
    Cursor::EndTag end() const { return {}; }

public:
    /** @cond PRIVATE */
    MessagesSnapshot(tbricks::fix::ISession * m_session, bool is_outgoing, uint32_t first_sequence_number);

    MessagesSnapshot(const MessagesSnapshot &);
    MessagesSnapshot & operator=(const MessagesSnapshot &);

    MessagesSnapshot(MessagesSnapshot &&);
    MessagesSnapshot & operator=(MessagesSnapshot &&);

    ~MessagesSnapshot();
    /** @endcond */

private:
    SafePointer<tbricks::fix::ISession> m_session;
    uint32_t m_first_sequence_number;
    uint32_t m_last_sequence_number;
    bool m_is_outgoing;
};

} // namespace FIX
} // namespace tbricks

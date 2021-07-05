#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// FIX Group
// UNDER DEVELOPMENT. PLEASE, DON'T USE
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/fix/Enums.h"

namespace tbricks {

namespace fix {
class GroupRef;
}
namespace strategy {
class FIXStreamImpl;
}

class Boolean;
class Currency;
class Date;
class DateTime;
class Double;
class Identifier;
class Integer;
class MIC;
class MessageBuilder;
class Price;
class Side;
class StrategyIdentifier;
class String;
class Time;
class Uuid;
class Volume;

namespace FIX {

/**
 * WARNING!
 *
 * This class is under development, class interface is subject to change.
 *
 */
class STRATEGY_EXPORT Group : public Printable
{
public:
    class STRATEGY_EXPORT const_iterator
    {
        struct Impl;

    public:
        const_iterator(const const_iterator &) = delete;
        const_iterator & operator=(const const_iterator &) = delete;

        const_iterator() = default;
        ~const_iterator();

        size_t GetRepeatingCount() const;
        bool Next();
        bool IsLast() const;

        bool GetCurrent(Group & group) const;

        const_iterator & operator*();

    private:
        void Reset(Impl *);

    private:
        friend class Group;

        Impl * m_impl{nullptr};
    };

    /// @deprecated Deprecated in 2.11.2, will be removed in 2.12.0
    [[deprecated(DEPRECATE_LINK)]] typedef const_iterator ConstIterator;

public:
    Group() = default;

    bool FindGroups(unsigned int id, const_iterator & groups) const;

    bool Empty() const;

public:
    bool GetField(unsigned int id, Boolean & v) const;
    bool GetField(unsigned int id, Currency & v) const;
    bool GetField(unsigned int id, Date & v) const;
    bool GetField(unsigned int id, DateTime & v) const;
    bool GetField(unsigned int id, Double & v) const;
    bool GetField(unsigned int id, Price & v) const;
    bool GetField(unsigned int id, Volume & v) const;
    bool GetField(unsigned int id, Integer & v) const;
    bool GetField(unsigned int id, String & v) const;
    bool GetField(unsigned int id, Time & v) const;
    bool GetField(unsigned int id, Uuid & v) const;
    bool GetField(unsigned int id, Identifier & v) const;
    bool GetField(unsigned int id, StrategyIdentifier & v) const;
    bool GetField(unsigned int id, Side & v) const;
    bool GetField(unsigned int id, MIC & v) const;

    bool GetField(unsigned int id, char & v) const;
    bool GetField(unsigned int id, bool & v) const;
    bool GetField(unsigned int id, int & v) const;
    bool GetField(unsigned int id, size_t & v) const;
    bool GetField(unsigned int id, double & v) const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

protected:
    void set_data(fix::GroupRef *);
    fix::GroupRef * get_data();
    const fix::GroupRef * get_data() const;

private:
    friend class Session;
    friend class const_iterator;
    friend class MessageBuilder;

private:
    fix::GroupRef * m_data = nullptr;
};
}
} // namespace FIX, namespace tbricks

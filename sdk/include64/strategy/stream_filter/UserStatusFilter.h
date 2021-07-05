#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for user preferences stream.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/stream/UserStatusStream.h"

#include "strategy/stream_filter/Filter.h"

namespace tbricks {

/**
 * User::Status::Stream::Filters::Filter class
 */
class STRATEGY_EXPORT User::Status::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Filter & filter);
    ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const Filter & filter);
    Filter & operator&=(const Filter & filter);

    Filter operator||(const Filter & filter);
    Filter operator&&(const Filter & filter);

    Filter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

public:
    std::ostream & Print(std::ostream & strm) const override;

protected:
    uint64_t get_stream_message_id() const override;
};

typedef User::Status::Stream::Filters::Filter AnyUserStatusFilter;

/**
 * User::Status::Stream::Filters::FilterCondition class
 */
class STRATEGY_EXPORT User::Status::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    User::Status::Stream::Filters::Filter operator||(const User::Status::Stream::Filters::FilterCondition & cond) const;
    User::Status::Stream::Filters::Filter operator&&(const User::Status::Stream::Filters::FilterCondition & cond) const;
    User::Status::Stream::Filters::Filter operator||(const User::Status::Stream::Filters::Filter & cond) const;
    User::Status::Stream::Filters::Filter operator&&(const User::Status::Stream::Filters::Filter & cond) const;
    User::Status::Stream::Filters::Filter operator!() const;
    operator User::Status::Stream::Filters::Filter() const;
};

/**
 * User::Status::Stream::Filters::ByUserIdentifier class
 *
 * ByUserFilter matches concrete user instance updates,
 * selected by user identifier.
 */
class STRATEGY_EXPORT User::Status::Stream::Filters::ByUserIdentifier : public User::Status::Stream::Filters::FilterCondition
{
public:
    /**
     * Makes a filter to match  the user with the
     * specified user identifier.
     *
     * @param identifier                  	user identifier
     */
    ByUserIdentifier(const UserIdentifier & identifier);

    /**
     * Makes a filter to match the user with the specified user.
     *
     * @param user				user instance.
     */
    ByUserIdentifier(const User & user);
    ByUserIdentifier(const ByUserIdentifier & filter);

    ByUserIdentifier & operator=(const ByUserIdentifier & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    UserIdentifier m_identifier;
};
}

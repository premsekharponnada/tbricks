#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in rbac privilege streams.
//****************************************************************************************

#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/RbacPrivilegeStream.h"

namespace tbricks {

class STRATEGY_EXPORT RbacPrivilege::Stream::Filters::Filter : public tbricks::Filter
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

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

typedef RbacPrivilege::Stream::Filters::Filter AnyRbacPrivilegeFilter;

class STRATEGY_EXPORT RbacPrivilege::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    RbacPrivilege::Stream::Filters::Filter operator||(const RbacPrivilege::Stream::Filters::FilterCondition & cond) const;
    RbacPrivilege::Stream::Filters::Filter operator&&(const RbacPrivilege::Stream::Filters::FilterCondition & cond) const;
    RbacPrivilege::Stream::Filters::Filter operator||(const RbacPrivilege::Stream::Filters::Filter & cond) const;
    RbacPrivilege::Stream::Filters::Filter operator&&(const RbacPrivilege::Stream::Filters::Filter & cond) const;
    RbacPrivilege::Stream::Filters::Filter operator!() const;
    operator RbacPrivilege::Stream::Filters::Filter() const;
};

/**
 * RbacPrivilege::Stream::Filters::ByOperationFilter matches Rbac
 * privileges with specified operation.
 */
class STRATEGY_EXPORT RbacPrivilege::Stream::Filters::ByOperationFilter : public RbacPrivilege::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all Rbac privileges for
     * operation as specified in the input parameter.
     *
     * @param operation                     Instance of RbacOperation
     */
    ByOperationFilter(const RbacOperation & operation);
    ByOperationFilter(const ByOperationFilter & filter);

    ByOperationFilter & operator=(const ByOperationFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    RbacOperation m_operation;
};
}

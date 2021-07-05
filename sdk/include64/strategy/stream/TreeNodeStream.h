#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Tree stream.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/TreeNode.h"
#include "strategy/Strategy.h"
#include "strategy/stream/Stream.h"
#include "strategy/stream_filter/AnyFilter.h"

namespace tbricks {

class STRATEGY_EXPORT TreeNode::Stream : public tbricks::Stream
{
public:
    class IHandler;

public:
    class Filters
    {
    public:
        class Filter;
        class FilterCondition;

        class DeletedFilter;
        class IsRootFilter;
        class ByTypeFilter;
        class ByIdentifierFilter;
        class ByAncestorFilter;
        class ByParentFilter;
        class ByModifiedDateTimeFilter;
        class ByParameterFilter;
        class ShortNameContainsFilter;
    };

public:
    Stream();
    Stream(IHandler & handler);

    void SetCallback(IHandler & handler);

    void Open(Type type, const Filters::Filter & filter);
    void OpenAudit(Type type, const Filters::Filter & filter, const DateTime & from = DateTime(), const DateTime & to = DateTime());

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

class STRATEGY_EXPORT TreeNode::Stream::Filters::Filter : public tbricks::Filter
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

class STRATEGY_EXPORT TreeNode::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Filter operator||(const FilterCondition & cond) const;
    Filter operator&&(const FilterCondition & cond) const;
    Filter operator||(const Filter & cond) const;
    Filter operator&&(const Filter & cond) const;
    Filter operator!() const;
    operator Filter() const;
};

typedef TreeNode::Stream::Filters::Filter AnyTreeNodeFilter;

class STRATEGY_EXPORT TreeNode::Stream::IHandler : public tbricks::Stream::IHandler
{
public:
    virtual void HandleStreamOpen(const StreamIdentifier & stream_id);

    virtual void HandleTreeNode(const StreamIdentifier & stream_id, const TreeNode & update) = 0;

    /**
     * TreeNode stream invalidation handler.
     *
     * This method is called when an object previously present as a part of
     * subscription in the handle stream update for the matched stream filter,
     * now no longer fits filtering criteria.
     *
     * Fox example, a subscription was made for deleted TreeNode and all the
     * deleted TreeNode were received. If any such TreeNode is un-deleted, invalidate
     * method would be called to indicate that this TreeNode no longer belongs
     * to subscription request.
     *
     * @param stream                   Stream where invalidation occurred
     * @param id                       Identifier of invalidated TreeNode
     */
    virtual void HandleTreeNodeInvalidate(const StreamIdentifier & stream_id, const TreeNodeIdentifier & id) = 0;

protected:
    virtual ~IHandler();
};

} // \namespace tbricks

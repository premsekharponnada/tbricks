#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNode::Stream::Filters::ByAncestorFilter, matches nodes that are descendants
// of the specified node.
//****************************************************************************************

#include "strategy/stream/TreeNodeStream.h"

namespace tbricks {

/**
 * ByAncestorFilter allows to get nodes that belong to subtree with a specified root.
 */
class STRATEGY_EXPORT TreeNode::Stream::Filters::ByAncestorFilter : public TreeNode::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the TreeNodes having the specified
     * TreeNode identifier as an ancestor.
     *
     * @param id			identifier of the TreeNode.
     */
    ByAncestorFilter(const TreeNodeIdentifier & id);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    TreeNodeIdentifier m_nodeId;
};
}

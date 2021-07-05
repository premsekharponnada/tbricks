#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNode::Stream::Filters::ByParentFilter, matches tree nodes with specified
// parent node.
//****************************************************************************************

#include "strategy/stream/TreeNodeStream.h"

namespace tbricks {

/**
 * ByParentFilter allows to get nodes with specified parent node.
 */
class STRATEGY_EXPORT TreeNode::Stream::Filters::ByParentFilter : public TreeNode::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     * Makes a filter to match all the tree nodes having specified
     * tree node identifier as their parent node.
     *
     * @param id		Instance of TreeNodeIdentifier
     */
    ByParentFilter(const TreeNodeIdentifier & id);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    TreeNodeIdentifier m_parentId;
};
}

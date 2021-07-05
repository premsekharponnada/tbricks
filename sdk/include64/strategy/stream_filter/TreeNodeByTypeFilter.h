#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNode::Stream::Filters::ByTypeFilter, matches tree node updates
// of specified tree type.
//****************************************************************************************

#include "strategy/type/TreeTypeIdentifier.h"
#include "strategy/stream/TreeNodeStream.h"

namespace tbricks {

/**
 * TreeNodeByTypeFilter allows to filter tree nodes based on tree type.
 */
class STRATEGY_EXPORT TreeNode::Stream::Filters::ByTypeFilter : public TreeNode::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the tree nodes belongs to specified
     * tree node type.
     *
     * @param type                          TreeTypeIdentifier instance.
     *                                      Type of the tree node user wants to filter.
     */
    ByTypeFilter(const TreeTypeIdentifier & type);
    ByTypeFilter(const ByTypeFilter & filter);

    ByTypeFilter & operator=(const ByTypeFilter & filter);

    /**
     * %Set type of the tree node.
     *
     * @param tree_type                        TreeTypeIdentifier instance.
     *                                         Type of the tree node user wants to filter.
     */
    void SetType(const TreeTypeIdentifier & tree_type);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    TreeTypeIdentifier m_type;
};
}

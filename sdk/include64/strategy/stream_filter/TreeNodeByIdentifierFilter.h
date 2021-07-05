#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNode::Stream::ByIdentifierFilter, matches updates of concrete tree node instance.
//****************************************************************************************

#include "strategy/stream/TreeNodeStream.h"

namespace tbricks {

/**
 * TreeNode::Stream::Filters::ByIdentifierFilter matches concrete tree node instance updates,
 * selected by tree node identifier.
 */
class STRATEGY_EXPORT TreeNode::Stream::Filters::ByIdentifierFilter : public TreeNode::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match the specified TreeNode instance.
     *
     * @param instance                              instance of TreeNode
     */
    ByIdentifierFilter(const TreeNode & instance);

    /**
     * Constructor.
     *
     * Makes a filter to match the TreeNode specified by the tree node identifier.
     *
     * @param instance				instance of TreeNodeIdentifier
     */
    ByIdentifierFilter(const TreeNodeIdentifier & instance);
    ByIdentifierFilter(const ByIdentifierFilter & filter);

    ByIdentifierFilter & operator=(const ByIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    TreeNodeIdentifier m_instance;
};
}

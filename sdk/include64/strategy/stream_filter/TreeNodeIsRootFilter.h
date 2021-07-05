#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNode::Stream::Filters::IsRootFilter, matches root tree nodes.
//****************************************************************************************

#include "strategy/type/Boolean.h"
#include "strategy/stream/TreeNodeStream.h"

namespace tbricks {

/**
 * TreeNodeIsRootFilter allows to get only root tree nodes.
 */
class STRATEGY_EXPORT TreeNode::Stream::Filters::IsRootFilter : public TreeNode::Stream::Filters::FilterCondition
{
public:
    /// Default constructor.
    IsRootFilter();
    IsRootFilter(const IsRootFilter & filter);

    IsRootFilter & operator=(const IsRootFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
};
}

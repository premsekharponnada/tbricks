#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNodeStream::Filters::ShortNameContainsFilter, matches treenode
// updates by specified short name.
//****************************************************************************************

#include "strategy/type/String.h"
#include "strategy/stream/TreeNodeStream.h"

namespace tbricks {

/**
 * TreeNodeStream::Filters::ShortNameContainsFilter matches concrete treenode instance updates
 * containing specific treenode short name.
 */
class STRATEGY_EXPORT TreeNode::Stream::Filters::ShortNameContainsFilter : public TreeNode::Stream::Filters::FilterCondition
{
public:
    /**
     * Makes a filter to match the treenode instance having
     * short name as specified in the input parameter.
     *
     * @param short_name            String instance, short name of the
     *                              treenode to be filtered.
     */
    ShortNameContainsFilter(String short_name, bool case_sensitive = true);

    tbricks::filter::FieldFilter GetValue() const override;

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;
    void Clear() override;
    bool Empty() const override;

private:
    String m_short_name;
    bool m_case_sensitive;
};
}

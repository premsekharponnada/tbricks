#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNode::Stream::Filters::DeletedFilter, matches deleted tree nodes.
//****************************************************************************************

#include "strategy/type/Boolean.h"
#include "strategy/stream/TreeNodeStream.h"

namespace tbricks {

/**
 * TreeNodeDeletedFilter allows to skip deleted tree nodes.
 */
class STRATEGY_EXPORT TreeNode::Stream::Filters::DeletedFilter : public TreeNode::Stream::Filters::FilterCondition
{
public:
    /// Default constructor.
    DeletedFilter();
    /**
     * Constructor.
     *
     * Makes a filter to match all instruments based on the specified
     * Boolean value.
     *
     * @param deleted                                 Boolean value.
                                                      Set true to get deleted instrument.
                                                      Set false to get non deleted instrument.
     */
    DeletedFilter(bool deleted);
    DeletedFilter(const DeletedFilter & filter);

    DeletedFilter & operator=(const DeletedFilter & filter);

    /**
     * %Set instrument deleted status for the filter.
     *
     * @param deleted                                 Boolean value.
                                                      Set true to get deleted instrument.
                                                      Set false to get non deleted instrument.
     */
    void SetDeleted(bool deleted);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Value<bool> m_deleted;
};
}

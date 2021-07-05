#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNode::Stream::ByParameterFilter, matches updates of concrete tree node instance
// of specified parameter selection.
//****************************************************************************************

#include "strategy/stream/TreeNodeStream.h"

namespace tbricks {

/**
 * TreeNodeByParameterFilter matches TreeNode instances having the specified
 * parameter.
 */

namespace filter {
class ICondition;
}

class STRATEGY_EXPORT TreeNode::Stream::Filters::ByParameterFilter : public TreeNode::Stream::Filters::FilterCondition
{
public:
    /// Default constructor.
    ByParameterFilter();
    ByParameterFilter(const ByParameterFilter & filter);

    /**
     * Constructor.
     *
     * Makes a filter to match the tree node having specified
     * TreeNode parameter definition and value.
     *
     * @param definition                       Parameter "definitions" allows to select what
                                               specific TreeNode parameters updates the
                                               caller is interested in.
     *
     * @param value                            TreeNode parameter's value
     */

    ByParameterFilter(const TreeNodeParameterDefinition & definition, const AnyType & value);

    /**
     * Constructor.
     *
     * Makes a filter to match the tree node having specified parameter and value.
     *
     * @param parameter_id                     Uuid of TreeNode parameter
     * @param value                            TreeNode parameter's value
     */
    ByParameterFilter(const Uuid & parameter_id, const AnyType & value);
    ~ByParameterFilter();

    ByParameterFilter & operator=(const ByParameterFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void init(const Uuid & parameter_id, const AnyType & value);

private:
    filter::ICondition * m_condition;
};
}

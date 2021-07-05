#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PositionByExecutionPolicyFilter matches concrete
// position instance updates, selected by execution policy.
//****************************************************************************************

#include "strategy/stream_filter/PositionFilter.h"
#include "strategy/type/ExecutionPolicy.h"

namespace tbricks {

/**
 * PositionByExecutionPolicyFilter matches concrete
 * position instance updates, selected by execution policy.
 */
class STRATEGY_EXPORT PositionByExecutionPolicyFilter : public PositionFilterCondition
{
public:
    /**
     * Makes a filter to match all the positions with the specified execution policy
     *
     * @param execution_policy                execution policy
     */
    PositionByExecutionPolicyFilter(const ExecutionPolicy & execution_policy);

    PositionByExecutionPolicyFilter(const PositionByExecutionPolicyFilter & filter) = default;
    PositionByExecutionPolicyFilter & operator=(const PositionByExecutionPolicyFilter & filter) = default;

    void Clear() override { m_execution_policy.Clear(); }
    bool Empty() const override { return m_execution_policy.Empty(); }

protected:
    std::ostream & Print(std::ostream & strm) const override;
    filter::FieldFilter GetValue() const override;

private:
    ExecutionPolicy m_execution_policy;
};
}
